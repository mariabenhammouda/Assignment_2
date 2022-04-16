#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
  ofBackground(0);
  ofSetFrameRate(40);
  ofSetBackgroundAuto(false);
  ofSetCircleResolution(60);
  //  planet.load("planet.png"); //load the image into xcode
   // planet.getTexture().setTextureWrap(GL_REPEAT,GL_REPEAT);
  
  gui.setup();
  gui.add(circles_num.set("number of circles", 1, 1,10));
  gui.add(radius.set("radius", ofGetHeight()/4, 1, ofGetHeight()/2));
  gui.add(pos.set("pos",
                  ofVec3f(0),
                  ofVec3f(0),
                  ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 1000)));
  gui.add(rot.set("rot",
                  ofVec3f(0),
                  ofVec3f(0),
                  ofVec3f(720, 720, 720)));
  gui.add(speed.set("speed", 0.01, 0.01, 0.1));
  gui.add(after_img.set("after image", 0, 0, 255));
    gui.add(bluePlanet.set("Neptune",true));
    gui.add(greyPlanet.set("Mercury",false));
    gui.add(yellowPlanet.set("Venus",false));
  
  imgcount = 0;
  guidraw = true;
}

//--------------------------------------------------------------
void ofApp::update(){
  while (circle.size() != circles_num){
    if (circle.size() < circles_num) {
      circles s;
        circle.push_back(s);
    } else if (circle.size() > circles_num) {
        circle.erase(circle.begin());
    }
  }

  for (int i = 0; i < circle.size(); i++) {
      
      circle[i].update();
    
      circle[i].setRadius(radius);
      circle[i].setPosAmp(pos);
      circle[i].setRotAmp(rot);
      circle[i].setSpeedAmp(speed);
      
      ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
      
  }
    if(greyPlanet){
        planet.load("mercury.jpeg"); //load the image into xcode
          planet.getTexture().setTextureWrap(GL_REPEAT,GL_REPEAT);
        
    }
    else if(bluePlanet){
        planet.load("neptune.jpeg"); //load the image into xcode
        planet.getTexture().setTextureWrap(GL_REPEAT,GL_REPEAT);
        
    }
   
    else if(yellowPlanet){
        planet.load("venus.jpeg"); //load the image into xcode
          planet.getTexture().setTextureWrap(GL_REPEAT,GL_REPEAT);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    ofPushMatrix();
  
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSpherePrimitive sphere;
    sphere.mapTexCoordsFromTexture(planet.getTexture());
    ofPushStyle();
    ofSetColor(255);
    planet.getTexture().bind();
    sphere.setRadius(ofGetWidth()/10);
   // sphere.rotate(1,0,0.5,0);
    sphere.draw();// assign the texture then draw spheres

    planet.getTexture().unbind();
  
    ofPopStyle();
   
    ofEnableBlendMode(OF_BLENDMODE_ADD);
  
  for (int i = 0; i < circle.size(); i++) {
      circle[i].draw();
  }
  
  ofPopMatrix();
  
  ofEnableBlendMode(OF_BLENDMODE_ALPHA);

  ofFill();
  ofSetColor(0, after_img);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
  if(guidraw) {
    gui.draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  
  if (key == 'g') {
    guidraw = false;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
