#include <iostream>
#include <string>
#include "ofApp.h"

struct Pokemon pokedex[152];

//--------------------------------------------------------------
void ofApp::setup(){
	ifstream pkmnData;
	myfile.open("pkmnData.txt");

	cout << "test";

    //george.loadImage("barrel.png");
    ralph.loadImage("006.PNG");
    larry.loadImage("pallet.bmp");

    cout << "\ntest";

    int i=0;
	char *token;
	char nameChar[11], temp[100];
    char idNum[4], stat1[3], stat2[3], stat3[3], stat4[3], stat5[3], type1[3], type2[3], evoLvl[3], expClass[3], baseExp[4];
	string line;
	cout << "\ntest";

    for(i=0;i<152;i++)
    {
        //printf("error\n %d",i); - testing

		fgets(temp,sizeof(temp),fp);

        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(idNum,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(pokedex[i].name,strdup(token));
        cout << "\ntest";
        token=strtok(NULL,",");
        strcpy(stat1,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(stat2,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(stat3,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(stat4,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(stat5,strdup(token));
        cout << "\ntest";
		token=strtok(NULL,",");
        strcpy(type1,strdup(token));

		token=strtok(NULL,",");
        strcpy(type2,strdup(token));

		token=strtok(NULL,",");
        strcpy(evoLvl,strdup(token));

		token=strtok(NULL,",");
        strcpy(expClass,strdup(token));

		token=strtok(NULL,",");
        strcpy(baseExp,strdup(token));

		pokedex[i].idNum=atoi(idNum);
        pokedex[i].baseHP=atoi(stat1);
        pokedex[i].baseAtk=atoi(stat2);
        pokedex[i].baseDef=atoi(stat3);
        pokedex[i].baseSpd=atoi(stat4);
        pokedex[i].baseSpec=atoi(stat5);
        pokedex[i].type1=atoi(type1);
        pokedex[i].type2=atoi(type2);
        pokedex[i].evoLvl=atoi(evoLvl);
        pokedex[i].expClass=atoi(expClass);
		pokedex[i].baseExp=atoi(baseExp);

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
