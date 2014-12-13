#include <iostream>
#include <string>
#include "ofMain.h"
#include "ofApp.h"
#include <time.h>

srand(time(NULL));
//========================================================================
int main( ){
	ofSetupOpenGL(160,144,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());


}
