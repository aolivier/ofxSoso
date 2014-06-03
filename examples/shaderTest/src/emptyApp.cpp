#include "emptyApp.h"


//--------------------------------------------------------------
void emptyApp::setup(){
  
  //Replace the default ofGLRenderer with ofxSosoRenderer which has overriden setupScreen() and setupScreenPerspective().
	//This lets us set up the scene graph how we want to.
	//Warning: Up is up and down is down in this world.
  //ofSetCurrentRenderer(ofPtr<ofBaseRenderer>(new ofxSosoRenderer(false)));
  
  //Create a scene.
	//The scene is a scene graph that renders objects added to its root and their children and their children's children and so on.
	//When the render mode of the scene is set to RENDER_ALPHA_DEPTH_SORTED, it handles sorting of both transparent and opaque objects in the z-axis.
  //scene = new ofxScene(ofGetWidth(), ofGetHeight());
	//scene->setBackgroundColor(10, 10, 10);
  
  
  ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
  
  image.loadImage("plasticman.jpg");
  
  //we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
#ifdef TARGET_OPENGLES
	shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
#else
	if(ofGetGLProgrammableRenderer()){
		shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
	}else{
		shader.load("shaders/alex.vert", "shaders/alex.frag");
	}
#endif
  
	doShader = true;
  
}

//--------------------------------------------------------------
void emptyApp::update(){
  
	//Update the scene with the current time. This call propagates the idle() call to all objects as well.
	//Note: If you are capturing frames to create a movie, simply replace ofGetElapsedTimef() with a float variable that you increment by a fixed time interval each frame.
  //scene->update(ofGetElapsedTimef());
}

//--------------------------------------------------------------
void emptyApp::draw(){
  
	//Call draw on scene, which initiates the drawing of the root object.
  //scene->draw();
  
  ofSetColor(225);
	ofDrawBitmapString("'s' toggles shader", 10, 20);
  
	//ofSetColor(245, 58, 135);
	ofFill();
	
	if( doShader ){
		shader.begin();
    //we want to pass in some varrying values to animate our type / color
    shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
    shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
    
    //we also pass in the mouse position
    //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
    shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
    
	}
	
  //finally draw our text
  //font.drawStringAsShapes("openFrameworks", 90, 260);
  
  //draw an image!
  image.draw(300,100);
	
	if( doShader ){
		shader.end();
	}
}

//--------------------------------------------------------------
void emptyApp::keyPressed  (int key){
  if( key == 's' ){
		doShader = !doShader;
	}
}

//--------------------------------------------------------------
void emptyApp::keyReleased(int key){
  
}

//--------------------------------------------------------------
void emptyApp::mouseMoved(int x, int y ){
  
}

//--------------------------------------------------------------
void emptyApp::mouseDragged(int x, int y, int button){
  
  
}

//--------------------------------------------------------------
void emptyApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void emptyApp::mouseReleased(int x, int y, int button){
  
  
}


//--------------------------------------------------------------
void emptyApp::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void emptyApp::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void emptyApp::dragEvent(ofDragInfo dragInfo){ 
  
}


