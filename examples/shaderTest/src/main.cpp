//#include "ofMain.h"
//#include "emptyApp.h"
//#include "ofAppGlutWindow.h"

#include "ofMain.h"
#include "emptyApp.h"
#ifdef TARGET_OPENGLES
#include "ofGLProgrammableRenderer.h"
#endif

//========================================================================
int main( ){
  
  
  
  /*ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);			// <-------- setup the GL context
  
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new emptyApp());*/
  
  ofSetLogLevel(OF_LOG_VERBOSE);
#ifdef TARGET_OPENGLES
  ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
#endif
	ofSetupOpenGL(1024,500, OF_WINDOW);			// <-------- setup the GL context
  
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new emptyApp());
  
}
