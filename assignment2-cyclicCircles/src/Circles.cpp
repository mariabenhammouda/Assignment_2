//
//  Circles.cpp
//  assignment2-cyclicCircles
//
//  Created by Maria  on 16/04/2022.
//

#include "Circles.hpp"
circles::circles() {
  radius = ofGetHeight()/4;
  pos.set(0, 0, 0);
  rotate.set(0, 0, 0);
  
  speed = 0.001;
  speed_noise = ofRandom(10);
  speed_amp = ofRandom(10)/10000;
  pos_noise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  pos_amp.set(0, 0, 0);
  rot_noise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  rot_amp.set(0, 0, 0);
}

void circles::update() {
  speed = ofNoise(speed_noise)*speed_amp;
  
  pos.set((ofNoise(pos_noise.x)*2-1)*pos_amp.x,
          (ofNoise(pos_noise.y)*2-1)*pos_amp.y,
          (ofNoise(pos_noise.z)*2-1)*pos_amp.z);
  
  rotate.set((ofNoise(rot_noise.x)*2-1)*rot_amp.x,
             (ofNoise(rot_noise.y)*2-1)*rot_amp.y,
             (ofNoise(rot_noise.z)*2-1)*rot_amp.z);
  
  speed_noise += 0.01;
  
  pos_noise.x += speed;
  pos_noise.y += speed;
  pos_noise.z += speed;
  
  rot_noise.x += speed;
  rot_noise.y += speed;
  rot_noise.z += speed;

}

void circles::draw() {
  ofNoFill();
  ofPushMatrix();
  ofTranslate(pos);
  ofRotateX(rotate.x);
  ofRotateY(rotate.y);
  ofRotateZ(rotate.z);

    ofSetLineWidth(2);
  ofDrawCircle(0, 0, 0, radius);
  
  ofPopMatrix();
}

void circles::setRadius(float _radius) {
  radius = _radius;
}

void circles::setPosAmp(ofVec3f _pos_amp) {
  pos_amp = _pos_amp;
}

void circles::setRotAmp(ofVec3f _rot_amp) {
  rot_amp = _rot_amp;
}

void circles::setSpeedAmp(float _speed_amp) {
  speed_amp = _speed_amp;
}


