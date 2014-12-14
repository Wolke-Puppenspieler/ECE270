#include <iostream>
#include <string>
#include "ofApp.h"

struct Pokemon pokedex[152];

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
    int idNum, stat1, stat2, stat3, stat4, stat5, type1, type2, evoLvl, expClass, baseExp;
	cout << "\ntest";


    for(i=0;i<152;i++)
    {
        //printf("error\n %d",i); - testing

		fgets(temp,sizeof(temp),fp);

        cout << "\ntest";
		token=strtok(NULL,comma);
        idNum=atoi(strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        strcpy(name,strdup(token));
        cout << "\ntest";
        token=strtok(NULL,comma);
        stat1=atoi(strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat2=atoi(strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat3=atoi(strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat4=atoi(strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        stat5=atoi(strdup(token));
        cout << "\ntest";
		token=strtok(NULL,comma);
        type1=atoi(strdup(token));

		token=strtok(NULL,comma);
        type2=atoi(strdup(token));

		token=strtok(NULL,comma);
        evoLvl=atoi(strdup(token));

		token=strtok(NULL,comma);
        expClass=atoi(strdup(token));
		
		token=strtok(NULL,comma);
        baseExp=atoi(strdup(token));

		pokedex[i].idNum=idNum;
        pokedex[i].name=name;
        pokedex[i].stat1=stat1;
        pokedex[i].stat2=stat2;
        pokedex[i].stat3=stat3;
        pokedex[i].stat4=stat4;
        pokedex[i].stat5=stat5;
        pokedex[i].type1=type1;
        pokedex[i].type2=type2;
        pokedex[i].evoLvl=evoLvl;
        pokedex[i].expClass=expClass;
		pokedex[i].baseExp=baseExp;

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
