//
//  StateManager.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef ChangeController_hpp
#define ChangeController_hpp

#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <any>
#include <functional>
#include "Observable.h"
#include "VarType.h"

class Subject;
class Observer;

class StateManager {    
    struct UpdateInfo {
        Subject *subject;
        Observable observable;
        ObservableType value;
    };
    
    std::map<Subject*, std::vector<Observer*> > connections; // All the observables the observers are listening to
    std::queue<UpdateInfo> updates;
    
    struct change_hash : public std::unary_function<VarID, std::size_t>
    {
       std::size_t operator()(const VarID& k) const
       {
          return std::get<0>(k) ^ std::hash<int>()(std::get<1>(k));
       }
    };
    std::map<std::weak_ptr<Subject>, std::unordered_map<VarID, std::list<std::function<void(std::any)>>, change_hash>, std::owner_less<>> newConnections;
    std::queue<std::tuple<std::weak_ptr<Subject>, VarID, std::any>> newUpdates;

public:
    StateManager();
    ~StateManager();
    static StateManager &instance() {
        static StateManager s;
        return s;
    }
    
    void connect(Observer &observer, Subject &subject); // Register an observer to a subject so that it can listen to the subject's changes
    void disconnect(Observer &observer, Subject &subject); // Deregister...
    
    void update(Subject &subject, Observable observable, ObservableType value);
    
    void distributeUpdates();
    
    template <typename S, typename T>
    void connect(std::weak_ptr<Subject> subject, VarType<S, T> varType, std::function<bool(T)> notifyCallback) {
        auto &callbackList = newConnections[subject][varType];
        callbackList.emplace_back();
        callbackList.back() = [selfIterator = std::prev(callbackList.end()), &notifyCallback, &callbackList](std::any newValue) {
            if(!notifyCallback(std::any_cast<T>(newValue)))
                callbackList.erase(selfIterator);
        };
    }
    
    template <typename S, typename T>
    void update(std::weak_ptr<Subject> subject, VarType<S, T> varType, T newValue) {
        newUpdates.push(std::make_pair(subject, varType, newValue));
    }
};

#endif /* ChangeController_hpp */
