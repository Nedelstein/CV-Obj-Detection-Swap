#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    cam.setup(ofGetWidth(), ofGetHeight());
    ofSetWindowShape(cam.getWidth(), cam.getHeight());
    
    detector.setNetworkImageSize(416, 416);
    detector.setup(ofToDataPath("dnn/yolov2-tiny.cfg"),
                   ofToDataPath("dnn/yolov2-tiny.weights"),
                   ofToDataPath("dnn/coco.txt"));
    
    detector.setConfidenceThreshold(0.4);


}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();

    if(cam.isFrameNew()){
        detector.update(cam.getPixels());
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    cam.draw(0,0);
    detector.draw(0,0,cam.getWidth(), cam.getHeight());
//    ofDrawBitmapString(ofToString(ofGetFrameRate(), 0), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
