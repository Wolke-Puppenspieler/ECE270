#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //george.loadImage("barrel.png");
    ralph.loadImage("006.PNG");
    larry.loadImage("pallet.bmp");
    j=0;
    k=0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int i;//,j=0,k=0;

    /*for(i=0;i<300;i++)
    {
        ofPushMatrix();//change coordinate matrix, works in conjunction with ofTranslate()
        k++;
        if((i*16)%160==0)
        {
            j++;
            k=0;
        }
        ofTranslate(k*16,(j-1)*16);//shifts image
        george.draw(0,0);//draws image
     ofPopMatrix();//change coordinate matrix, works in conjunction with ofTranslate()
     }*/
     larry.draw(j,k);
     ralph.draw(80,64);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a')
    {
        j=j+16;
    }
    else if(key=='d')
    {
        j=j-16;
    }
    else if(key=='w')
    {
        k=k+16;
    }
    else if(key=='s')
    {
        k=k-16;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

Pokemon::Pokemon(int baseHP_in, int baseAtk_in, int baseDef_in, int baseSpd_in, int baseSpec_in, int type1_in, int type2_in, int evoLvl_in, int expClass_in)
{
    baseHP=baseHP_in;
    baseAtk=baseAtk_in;
    baseDef=baseDef_in
}
