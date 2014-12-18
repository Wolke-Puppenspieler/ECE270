#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ofApp.h"

using namespace std;


struct Pokemon pokedex[152];
//ofImage pokeSprites[152]; //causing crashes
//ofImage pokeBacks[151]; // """"""""""""
void loadPokedex();
//the next 2 functions come courtesy of the infinite wisdom of stackoverflow.com
//converts string to int
int get_int(string s) {
    stringstream ss(s);
    int ret;
    ss >> ret;
    return ret;
}
//converts string to float
float get_float(string s) {
    stringstream ss(s);
    float ret;
    ss >> ret;
    return ret;
}

//--------------------------------------------------------------
void ofApp::setup()
{

    ofBackground(0,0,0);
    player.loadImage("lordHelix.png"); //only the worthy will get it...
    gameText.loadFont("pojemans.ttf",8,false,true,false); //here's a callout to my lovely wife Nadia, who's ability to always make me laugh makes all of this a bit easier to handle
    fp=fopen("output.txt","w");
    currentMap.loadImage(maps[m]); //load first map
    j=currentMap.getWidth()/2-16; //set initial player x position
    k=currentMap.getHeight()/2; //set initial player y position
    bgMusic.loadSound("1.mp3");
    bgMusic.setLoop(true);
    bgMusic.play();

    loadPokedex();

    Pokemon demoTeam[6]={pokedex[151],pokedex[3],pokedex[6],pokedex[9],pokedex[130],pokedex[144]}; //initialize party for presentation demo
    int demoTeamLevels[6]={5,5,5,5,5,5}; //initialize party levels for demo
    Trainer player1(demoTeam,demoTeamLevels); //create player1 in-game

}

//--------------------------------------------------------------
void ofApp::update(){


    //switch(m)

}

//--------------------------------------------------------------
void ofApp::draw(){

    /*while(player1.isBattling==1)
    {
            pokeSprites[wild.idNum].draw(104,0);
            pokeBacks[player1.party[0].idNum].draw(0,96);
    }*/
    currentMap.draw(0,0);
    player.draw(j-8,k);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int wildPossible;
    switch(m)
    {
    case 2:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map1[(k/16)][((j-16)/16)]==0||map1[(k/16)][((j-16)/16)]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if((map1[(k/16)][((j-16)/16)]>1)) //check to see if we need to load another map
                {m=map1[(k/16)][((j-16)/16)];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map1[k/16][(j+16)/16]==0||map1[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j+16;} //move player
            if(map1[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map1[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map1[(k-16)/16][j/16]==0||map1[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map1[(k-16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map1[(k-16)/16][j/16];
                currentMap.loadImage(maps[m]);
                bgMusic.loadSound("6.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=currentMap.getHeight()-16;
                j=j-48;
            } //trigger load of next map and set new position
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map1[(k+16)/16][j/16]==0||map1[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map1[(k+16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map1[((k+16)/16)][(j/16)];
                currentMap.loadImage(maps[m]);
                bgMusic.loadSound(m+".mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=0;
            } //trigger load of next map and set new position
        break;
        }
    break;
    case 3:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map1a1[k/16][(j-16)/16]==0||map1a1[k/16][(j-16)/16]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if((map1a1[k/16][(j-16)/16]>1)) //check to see if we need to load another map
                {m=map1a1[k/16][(j-16)/16];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map1a1[k/16][(j+16)/16]==0||map1a1[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if(map1a1[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map1a1[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map1a1[(k-16)/16][j/16]==0||map1a1[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map1a1[(k-16)/16][j/16]>1) //check to see if we need to load another map
                {m=map1a1[(k-16)/16][j/16];} //trigger load of next map
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map1a1[(k+16)/1][j/16]==1||map1a1[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map1a1[(k+16)/1][j/16]>1) //check to see if we need to load another map
            {m=map1a1[(k+16)/1][j/16];} //trigger load of next map
        break;
        }
    break;
    case 4:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map1a2[k/16][(j-16)/16]==0||map1a2[k/16][(j-16)/16]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if(map1a2[k/16][(j-16)/16]>1) //check to see if we need to load another map
                {m=map1a2[k/16][(j-16)/16];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map1a2[k/16][(j+16)/16]==0||map1a2[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if(map1a2[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map1a2[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map1a2[(k-16)/16][j/16]==0||map1a2[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map1a2[(k-16)/16][j/16]>1) //check to see if we need to load another map
                {m=map1a2[(k-16)/16][j/16];} //trigger load of next map
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map1a2[(k+16)/16][j/16]==1||map1a2[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map1a2[(k+16)/16][j/16]>1) //check to see if we need to load another map
            {m=map1a2[(k+16)/16][j/16];} //trigger load of next map
        break;
        }
    break;
    case 5:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map1a2[k/16][(j-16)/16]==0||map1a2[k/16][(j-16)/16]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if((map1a2[k/16][(j-16)/16]>1)) //check to see if we need to load another map
                {m=map1a2[k/16][(j-16)/16];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map1a2[k/16][(j+16)/16]==0||map1a2[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if(map1a2[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map1a2[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map1a2[(k-16)/16][j/16]==0||map1a2[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map1a2[(k-16)/16][j/16]>1) //check to see if we need to load another map
                {m=map1a2[(k-16)/16][j/16];} //trigger load of next map
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map1a2[(k+16)/16][j/16]==1||map1a2[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map1a2[(k+16)/16][j/16]>1) //check to see if we need to load another map
                {m=map1a2[(k+16)/16][j/16];} //trigger load of next map
        break;
        }
    break;
    case 6:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map2[(k/16)][((j-16)/16)]==0||map2[(k/16)][((j-16)/16)]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if((map2[(k/16)][((j-16)/16)]>1)) //check to see if we need to load another map
                {m=map2[(k/16)][((j-16)/16)];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map2[k/16][(j+16)/16]==0||map2[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j+16;} //move player
            if(map2[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map2[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map2[(k-16)/16][j/16]==0||map2[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map2[(k-16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map2[(k-16)/16][j/16]; //change map
                currentMap.loadImage(maps[m]); //load next map
                bgMusic.loadSound("7.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=currentMap.getHeight()-16; //position player
                j=j+112; //position player
            }
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map2[(k+16)/16][j/16]==0||map2[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map2[(k+16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map2[((k+16)/16)][(j/16)]; //change map
                currentMap.loadImage(maps[m]); //load next map
                bgMusic.loadSound("1.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=0; //position player
                j=j+48; //position player
            }
        break;
        }

        if(map2[k/16][j/16]==-1){
        wildPossible=1;
        }else{wildPossible=0;}

    break;
    case 7:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map3[(k/16)][((j-16)/16)]==0||map3[(k/16)][((j-16)/16)]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if((map3[(k/16)][((j-16)/16)]>1)) //check to see if we need to load another map
                {m=map3[(k/16)][((j-16)/16)];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map3[k/16][(j+16)/16]==0||map3[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j+16;} //move player
            if(map3[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map3[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map3[(k-16)/16][j/16]==0||map3[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map3[(k-16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map3[(k-16)/16][j/16];
                currentMap.loadImage(maps[m]);
                bgMusic.loadSound("8.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=currentMap.getHeight()-16;
                j=j+32;

            } //trigger load of next map and set new position
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map3[(k+16)/16][j/16]==0||map3[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map3[(k+16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map3[((k+16)/16)][(j/16)];
                currentMap.loadImage(maps[m]);
                bgMusic.loadSound("6.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=0;
                j=j-112;
            } //trigger load of next map and set new position
        break;
        }
    break;
    case 8:
        switch(key)
        {
        case 'a':
            if(lastKey!=key){
            player.loadImage("leftSprite.png");}
            if(map4[(k/16)][((j-16)/16)]==0||map4[(k/16)][((j-16)/16)]==-1) //check if next cell is walkable
                {j=j-16;} //move player
            if((map4[(k/16)][((j-16)/16)]>1)) //check to see if we need to load another map
                {m=map4[(k/16)][((j-16)/16)];} //trigger load of next map
        break;
        case 'd':
            if(lastKey!=key){
            player.loadImage("rightSprite.png");}
            if(map4[k/16][(j+16)/16]==0||map4[k/16][(j+16)/16]==-1) //check if next cell is walkable
                {j=j+16;} //move player
            if(map4[k/16][(j+16)/16]>1) //check to see if we need to load another map
               {m=map4[k/16][(j+16)/16];} //trigger load of next map
        break;
        case 'w':
            if(lastKey!=key){
            player.loadImage("upSprite.png");}
            if(map4[(k-16)/16][j/16]==0||map4[(k-16)/16][j/16]==-1) //check if next cell is walkable
                {k=k-16;} //move player
            if(map4[(k-16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map4[(k-16)/16][j/16]; //change map
                currentMap.loadImage(maps[m]); //load new map
                bgMusic.loadSound("9.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=currentMap.getHeight()-16; //position player
                j=j+64;  //position player

            }
        break;
        case 's':
            if(lastKey!=key){
            player.loadImage("downSprite.png");}
            if(map4[(k+16)/16][j/16]==0||map4[(k+16)/16][j/16]==-1)//check if next cell is walkable
                {k=k+16;} //move player
            if(map4[(k+16)/16][j/16]>1) //check to see if we need to load another map
            {
                m=map4[((k+16)/16)][(j/16)];  //change map
                currentMap.loadImage(maps[m]); //load new map
                bgMusic.loadSound("7.mp3"); //load new music
                bgMusic.setLoop(true);
                bgMusic.play();
                k=0; //position player
                j=j-32; //position player
            }
        break;
        }

        if(map4[k/16][j/16]==-1){
        wildPossible=1;
        }else{wildPossible=0;}

    break;

    }
    lastKey=key;

    if(wildPossible==1&&rand()%5==1)
    {
        switch(m)
        {
        case 2:
            cout << "\nwild " << pokedex[pallet[rand()%4]].name << " of level " << rand()%4+2 << " found";
            fprintf(fp,"\nwild %s of level %d found",pokedex[pallet[rand()%4]].name.c_str(), rand()%4+2);
            //wildEncounter(pallet[rand()%4],rand()%4+2); //wild pokemon encounter event
        break;
        case 6:
            cout << "\nwild " << pokedex[route1[rand()%2]].name << " of level " << rand()%4+3 << " found";
            fprintf(fp,"\nwild %s of level %d found",pokedex[route1[rand()%4]].name.c_str(), rand()%4+2);
            //wildEncounter(route1[rand()%2],rand()%4+3); //wild pokemon encounter event
        break;
        case 8:
            cout << "\nwild " << pokedex[viridian[rand()%6]].name << " of level " << rand()%5+3 << " found";
            fprintf(fp,"\nwild %s of level %d found",pokedex[viridian[rand()%4]].name.c_str(), rand()%4+2);
            //wildEncounter(viridian[rand()%6],rand()%5+3); //wild pokemon encounter event
        break;
        }

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

void ofApp::wildEncounter(int idNum,int level)
{

    wild.genWild(pokedex[idNum],level); //generate battlable pokemon
    player1.battle(wild); //battle generated pokemon
}

BattlePoke::BattlePoke(struct Pokemon pokemon, int level_in)
{

	level=level_in;
	maxHP=(((rand()%32)+pokemon.baseHP+50)*level)/50+10;
    atkStat=(((rand()%32)+pokemon.baseAtk+50)*level)/50+5;
    defStat=(((rand()%32)+pokemon.baseDef+50)*level)/50+5;
    spdStat=(((rand()%32)+pokemon.baseSpd+50)*level)/50+5;
    specStat=(((rand()%32)+pokemon.baseSpec+50)*level)/50+5;
    idNum=pokemon.idNum;

	switch(pokemon.expClass)
	{
		case 1:
			exp=1.25*pow(level,3);
		break;
		case 2:
			exp=pow(level,3);
		break;
		case 3:
			exp=.95*pow(level,3);
		break;
		case 4:
			exp=0.8*pow(level,3);
		break;
	}

}

BattlePoke::BattlePoke(){} //lazy constructor

void BattlePoke::genWild(struct Pokemon pokemon, int level_in)
{
    level=level_in;
	maxHP=(((rand()%32)+pokemon.baseHP+50)*level)/50+10;
    atkStat=(((rand()%32)+pokemon.baseAtk+50)*level)/50+5;
    defStat=(((rand()%32)+pokemon.baseDef+50)*level)/50+5;
    spdStat=(((rand()%32)+pokemon.baseSpd+50)*level)/50+5;
    specStat=(((rand()%32)+pokemon.baseSpec+50)*level)/50+5;
    idNum=pokemon.idNum;

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

Trainer::Trainer(){}

Trainer::Trainer(struct Pokemon starter)
{
    party[0].genWild(starter,5);
}

Trainer::Trainer(Pokemon team[6],int levels[6])
{
    int i;
    for(i=0;i<6;i++)
    {
        party[i].genWild(team[i],levels[i]);
    }
}

void Trainer::battle(BattlePoke opponent)
{
    int mapHolder, xHolder, yHolder;
     //these 3 vars save the player's pre-battle location
    isBattling=1;
    while(isBattling=1)
    {


    }
    isBattling=0;
}

//just to get this out of setup...
void loadPokedex()
{
    //-------------------------------------initialize pokedex from pokemon database file----------------------------------------------//
    ifstream pkmnData;
	pkmnData.open("pkmnData.txt"); //open database of pokemon vital stats
    int i=0;
    string idNum, stat1, stat2, stat3, stat4, stat5, type1, type2, evoLvl, expClass, baseExp;
	string line;

    if(pkmnData.is_open())
    {
        for(i=0;i<152;i++)
        {
            getline(pkmnData,line);
            stringstream ss(line);
            string field;

            getline(ss,field,',');
            idNum=field;

            getline(ss,field,',');
            pokedex[i].name=field;

            getline(ss,field,',');
            stat1=field;

            getline(ss,field,',');
            stat2=field;

            getline(ss,field,',');
            stat3=field;

            getline(ss,field,',');
            stat4=field;

            getline(ss,field,',');
            stat5=field;

            getline(ss,field,',');
            type1=field;

            getline(ss,field,',');
            type2=field;

            getline(ss,field,',');
            evoLvl=field;

            getline(ss,field,',');
            expClass=field;

            getline(ss,field,',');
            baseExp=field;

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

            //pokeSprites[i].loadImage(("pkmnSprites/"+idNum+".PNG"));
            //pokeBacks[i].loadImage(("pkmnBacks/"+idNum+".png"));


        }

        pkmnData.close();
    }

}
