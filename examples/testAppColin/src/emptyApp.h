#pragma once

#include "ofMain.h"
#include "ofxScene.h"
#include "ofxObject.h"
#include "ofxTextObject.h"
#include "ofxCircleObject.h"
#include "ofxAnimation.h"
#include "ofxSosoRenderer.h"

class emptyApp : public ofBaseApp{
  
public:
  
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
  
public:
  ofxScene						*scene;
    ofxObject                   *container;
    ofxCircleObject             *circle;
    ofxTextObject               *readOut;
    ofxSosoTrueTypeFont			*font16;
    int                         countMe;
 
};

