#include <iostream>
#include <string>
#include "ofApp.h"

Pokemon pokedex[152];

//--------------------------------------------------------------
void ofApp::setup(){
	FILE *fp;
	fp=fopen("pkmnData.txt","r");

	cout << "test";

    //george.loadImage("barrel.png");
    ralph.loadImage("006.PNG");
    larry.loadImage("pallet.bmp");
    j=0;
    k=0;

    cout << "\ntest";

    int i=0;
	char *token, comma[2]=",";
	char  nameChar[11], temp[100];
    int idNum, stat1, stat2, stat3, stat4, stat5, type1, type2, evoLvl, expClass;
	cout << "\ntest";

	fgets(temp,sizeof(temp),fp);

        cout << "\ntest";
		token=strtok(NULL,comma);
        idNum=stoi(token);
        cout << "\ntest";
		token=strtok(NULL,comma);
        string name(token);
        cout << "\ntest";
        token=strtok(NULL,comma);
        stat1=stoi(token);
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat2=stoi(token);
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat3=stoi(token);
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(stat4,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(stat5,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(type1,strdup(token));

		token=strtok(NULL,comma);
        strcpy(type2,strdup(token));

		token=strtok(NULL,comma);
        strcpy(evoLvl,strdup(token));

		token=strtok(NULL,comma);
        strcpy(expClass,strdup(token));

        cout << "test";

        string nameStr(name);

		pokedex[0].setPoke(idNum, name, stat1, stat2, stat3, stat4, stat5, type1, type2, evoLvl, expClass);

    for(i=1;i<152;i++)
    {
        //printf("error\n %d",i); - testing

		fgets(temp,sizeof(temp),fp);

        cout << "\ntest";
		token=strtok(NULL,comma);
        idNum=stoi(token);
        cout << "\ntest";
		token=strtok(NULL,comma);
        name(token);
        cout << "\ntest";
        token=strtok(NULL,comma);
        stat1(token);
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat2=*token;
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat3=*token;
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(stat4,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(stat5,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(type1,strdup(token));

		token=strtok(NULL,comma);
        strcpy(type2,strdup(token));

		token=strtok(NULL,comma);
        strcpy(evoLvl,strdup(token));

		token=strtok(NULL,comma);
        strcpy(expClass,strdup(token));

        cout << "test";

		pokedex[i].setPoke(idNum, name, stat1, stat2, stat3, stat4, stat5, type1, type2, evoLvl, expClass);

		cout << "test";

    }


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

Pokemon::Pokemon(int idNum_in, string name_in, int baseHP_in, int baseAtk_in, int baseDef_in, int baseSpd_in, int baseSpec_in, int type1_in, int type2_in, int evoLvl_in, int expClass_in)
{
    idNum=idNum_in;
    name=name_in;
    baseHP=baseHP_in;
    baseAtk=baseAtk_in;
    baseDef=baseDef_in;
    baseSpd=baseSpd_in;
    baseSpec=baseSpec_in;
    type1=type1_in;
    type2=type2_in;
    evoLvl=evoLvl_in;
    expClass=expClass_in;

}

Pokemon::Pokemon()
{

}

void Pokemon::setPoke(int idNum_in, string name_in, int baseHP_in, int baseAtk_in, int baseDef_in, int baseSpd_in, int baseSpec_in, int type1_in, int type2_in, int evoLvl_in, int expClass_in)
{
    idNum=idNum_in;
    name=name_in;
    baseHP=baseHP_in;
    baseAtk=baseAtk_in;
    baseDef=baseDef_in;
    baseSpd=baseSpd_in;
    baseSpec=baseSpec_in;
    type1=type1_in;
    type2=type2_in;
    evoLvl=evoLvl_in;
    expClass=expClass_in;
}
