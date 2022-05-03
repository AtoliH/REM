//
//  App.swift
//  REM
//
//  Created by Fire937 on 12/8/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

import Foundation
import AppKit

let app = NSApplication.shared

class AppDelegate: NSObject, NSApplicationDelegate {
    var window: NSWindow!

    func applicationDidFinishLaunching(_ notification: Notification) {
        let contentView = NSView()
        
        // Create the window and set the content view.
        window = NSWindow(
            contentRect: NSRect(x: 0, y: 0, width: 480, height: 300),
            styleMask: [.titled, .closable, .miniaturizable, .resizable, .fullSizeContentView],
            backing: .buffered, defer: false)
        window.center()
        window.setFrameAutosaveName("Main Window")
        window.contentView = contentView
        window.makeKeyAndOrderFront(nil)
        print("window created")
        
        app.stop(self) // Stopping default event loop so we can take control
    }
    
    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }
}

@_cdecl("openGUI")
func openGUI() {
    let delegate = AppDelegate()
    app.delegate = delegate
    
    app.run()
}
