# ofxLiveApp

Live coding for openFrameworks! Magic!

* For OSX used [jet-live](https://github.com/ddovod/jet-live)
* For Windows used [blink](https://github.com/crosire/blink)

## SETUP

1.	* **OSX**:
		- Install xcpretty: 
          ```
          gem install xcpretty  
          ```
	* **WIN**:
		- Add props file from addon to your project (via the "Property Manager" window in Visual Studio)

2. Inherit your main app from `ofxLiveApp` (instead of `ofBaseApp` class)
3. `ofxLiveApp` add new function `void reinit();` to your app. 
This function is called after changes are loaded, so you can reinit your objects (if necessary)
