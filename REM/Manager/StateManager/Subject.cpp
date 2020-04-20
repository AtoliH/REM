//
//  Subject.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "Subject.hpp"

Subject::Subject(): observed(true) {

}

void Subject::setObserved(bool observed) {
    this->observed = observed;
}
