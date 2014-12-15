#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "ofApp.h"

using namespace std;


struct Pokemon pokedex[152];

//the next 2 functions come courtesy of the infinite wisdom of stackoverflow.com
int get_int(string s) {
    stringstream ss(s);
    int ret;
    ss >> ret;
    return ret;
}

float get_float(string s) {
    stringstream ss(s);
    float ret;
    ss >> ret;
    return ret;
}

//--------------------------------------------------------------
void ofApp::setup(){
	ifstream pkmnData;
	pkmnData.open("pkmnData.csv");

	//cout << "test";

    //george.loadImage("barrel.png");
    ralph.loadImage("lordHelix.png");
    larry.loadImage("pallet.bmp");

    //cout << "\ntest";

    int i;
    string idNum, stat1, stat2, stat3, stat4, stat5, type1, type2, evoLvl, expClass, baseExp;
	string line;


	//cout << "\ntest";

    for(i=0;i<152;i++)
    {
        stringstream ss(line);
        vector<string> v;
        string field;

        cout << "\ntest" << field;

        getline(ss,field,',');
        idNum=field;
        v.push_back(field);

        cout << "\ntest" << field;

        getline(ss,field,',');
        pokedex[i].name=field;
        v.push_back(field);

        cout << "\ntest" << field;

        getline(ss,field,',');
        stat1=field;
        v.push_back(field);

        getline(ss,field,',');
        stat2=field;
        v.push_back(field);

        getline(ss,field,',');
        stat3=field;
        v.push_back(field);

		getline(ss,field,',');
        stat4=field;
        v.push_back(field);

        getline(ss,field,',');
        stat5=field;
        v.push_back(field);

        getline(ss,field,',');
        type1=field;
        v.push_back(field);

        getline(ss,field,',');
        type2=field;
        v.push_back(field);

        getline(ss,field,',');
        evoLvl=field;
        v.push_back(field);

		getline(ss,field,',');
        expClass=field;
        v.push_back(field);

        getline(ss,field,',');
        baseExp=field;
        v.push_back(field);

		pokedex[i].idNum=get_int(idNum);
        pokedex[i].baseHP=get_int(stat1);
        pokedex[i].baseAtk=get_int(stat2);
        pokedex[i].baseDef=get_int(stat3);
        pokedex[i].baseSpd=get_int(stat4);
        pokedex[i].baseSpec=get_int(stat5);
        pokedex[i].type1=get_int(type1);
        pokedex[i].type2=get_int(type2);
        pokedex[i].evoLvl=get_int(evoLvl);
        pokedex[i].expClass=get_int(expClass);
		pokedex[i].baseExp=get_int(baseExp);

        cout << "\n" << pokedex[i].name;
		cout << "\n" << pokedex[i].idNum;
        cout << "\n" << pokedex[i].baseHP;
        cout << "\n" << pokedex[i].baseAtk;
        cout << "\n" << pokedex[i].baseDef;
        cout << "\n" << pokedex[i].baseSpd;
        cout << "\n" << pokedex[i].baseSpec;
        cout << "\n" << pokedex[i].type1;
        cout << "\n" << pokedex[i].type2;
        cout << "\n" << pokedex[i].evoLvl;
        cout << "\n" << pokedex[i].expClass;
		cout << "\n" << pokedex[i].baseExp;
		//cout << "test";

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

BattlePoke::BattlePoke(struct Pokemon pokemon, int level_in)
{

	level=level_in;
	maxHP=(((rand()%32)+pokemon.baseHP+50)*level)/50+10;
    atkStat=(((rand()%32)+pokemon.baseAtk+50)*level)/50+5;
    defStat=(((rand()%32)+pokemon.baseDef+50)*level)/50+5;
    spdStat=(((rand()%32)+pokemon.baseSpd+50)*level)/50+5;
    specStat=(((rand()%32)+pokemon.baseSpec+50)*level)/50+5;

	switch(pokemon.expClass)
	{
		case 01:
			exp=1.25*pow(level,3);
		break;
		case 02:
			exp=pow(level,3);
		break;
		case 03:
			exp=.95*pow(level,3);
		break;
		case 04:
			exp=0.8*pow(level,3);
		break;
	}

}

void BattlePoke::evolve()
{

}

void BattlePoke::battle(BattlePoke opponent)
{

}
/*Pokemon::Pokemon(int idNum_in, string name_in, int baseHP_in, int baseAtk_in, int baseDef_in, int baseSpd_in, int baseSpec_in, int type1_in, int type2_in, int evoLvl_in, int expClass_in)
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
*/
