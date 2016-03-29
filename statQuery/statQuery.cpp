#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Pokemon{
	int idNum;		//the pokemon's index number referring to its species
	string name;	//the pokemon's species name
	int baseHP;     //base Health Point stat
	int baseAtk;    //base Attack stat
	int baseDef;    //base Defense stat
	int baseSpd;    //base Speed stat
	int baseSpec;   //base Special stat
	int type1;      //first elemental type
	int type2;      //second elemental type
	int evoLvl;     //level at which pokemon evolves (00 if pokemon does not evolve)
	int expClass;   //which level/experience ratio to use to determine pokemon level
	int baseExp;	//base exp yield upon defeat
};

class BattlePoke{
    private:
        int maxHP; //maximum health at current level
        int atkStat; //attack stat at current level
        int defStat; //defense stat at current level
        int spdStat; //speed stat at current level
        int specStat; //special stat at current level
        int move1; //attack 1
        int move2; //attack 2
        int move3; //attack 3
        int move4; //attack 4
        int exp; //total exp earned by this pokemon
        int level; //pokemon's current level
    public:
        int idNum;
        int hp; //current hp
        int atk; //current attack
        int def; //current defense
        int spd; //current speed
        int spec; //current special
        int faint;//1 if pokemon is knocked out | 0 if pokemon is currently able to battle
        int isWild; //1 if pokemon is wild | 0 trainer owned
        BattlePoke(struct Pokemon pokemon, int level_in); //generate a battleable pokemon
        BattlePoke(); //lazy constructor
        void genWild(struct Pokemon pokemon, int level_in); //generate a pokemon to battle
		void evolve(); //evolve pokemon if it reaches the appropriate level
        //void learnMove(Move newMove);
        void battle(BattlePoke opponent); //battle event vs other pokemon
};

struct Pokemon pokedex[152];

void loadPokedex();
void calcStat(int ,char );

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

int main()
{

    srand (time(NULL));
	char selection;
	int value;
	loadPokedex();

	do{
		cout << "This program will output a list of Pokemon with a desired stat VALUE\n";


		cout << "\nPlease make a selection from the following menu:";
		cout << "\nH:	Search by HP stat";
		cout << "\nA:	Search by Attack stat";
		cout << "\nD:	Search by Defense stat";
		cout << "\nP:	Search by Speed stat";
		cout << "\nS:	Search by Special stat";
		cout << "\nQ:	Quit\n";
		cin >> selection;

        cout << "Please enter the value of the stat you'd like to search for\n";
		cin >> value;

        calcStat(value,selection);

	}while((selection!='q')||(selection!='Q'));


	return 0;
}

BattlePoke::BattlePoke(struct Pokemon pokemon, int level_in)
{

	level=level_in;
	maxHP=((+pokemon.baseHP+50)*level)/50+10;
    atkStat=((+pokemon.baseAtk+50)*level)/50+5;
    defStat=((+pokemon.baseDef+50)*level)/50+5;
    spdStat=((+pokemon.baseSpd+50)*level)/50+5;
    specStat=((+pokemon.baseSpec+50)*level)/50+5;
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
	maxHP=((+pokemon.baseHP+50)*level)/50+10;
    atkStat=((+pokemon.baseAtk+50)*level)/50+5;
    defStat=((+pokemon.baseDef+50)*level)/50+5;
    spdStat=((+pokemon.baseSpd+50)*level)/50+5;
    specStat=((+pokemon.baseSpec+50)*level)/50+5;
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

void calcStat(int desiredValue, char stat)
{
	int i,lvl,dvs=0;

	switch(stat)
	{
		case 'h':case 'H':
			for(i=0;i<152;i++)
			{
				for(lvl=0;lvl<100;lvl++)
				{
					if((((((pokedex[i].baseHP+dvs)*2+63)*lvl)/100)+10)==desiredValue)
					{
						cout << "The pokemon you want is PROBABLY a level " << lvl << "\t" << pokedex[i].name << "\n";
					}
				}
			}
		break;
		case 'a':case 'A':
		for(i=0;i<152;i++)
			{
				for(lvl=0;lvl<100;lvl++)
				{
					if(((((pokedex[i].baseAtk+dvs)*lvl)/50)+5)==desiredValue)
					{
						cout << "The pokemon you want is PROBABLY a level " << lvl << "\t" << pokedex[i].name << "\n";
					}
				}
			}
		break;
		case 'd':case 'D':
		for(i=0;i<152;i++)
			{
				for(lvl=0;lvl<100;lvl++)
				{
					if(((((pokedex[i].baseDef+dvs)*lvl)/50)+5)==desiredValue)
					{
						cout << "The pokemon you want is PROBABLY a level " << lvl << "\t" << pokedex[i].name << "\n";
					}
				}
			}
		break;
		case 'p':case 'P':
		for(i=0;i<152;i++)
			{
				for(lvl=0;lvl<100;lvl++)
				{
					if(((((pokedex[i].baseSpd+dvs)*lvl)/50)+5)==desiredValue)
					{
						cout << "The pokemon you want is PROBABLY a level " << lvl << "\t" << pokedex[i].name << "\n";
					}
				}
			}
		case 's':case 'S':
		for(i=0;i<152;i++)
			{
				for(lvl=0;lvl<100;lvl++)
				{
					if(((((pokedex[i].baseSpec+dvs)*lvl)/50)+5)==desiredValue)
					{
						cout << "The pokemon you want is PROBABLY a level " << lvl << "\t" << pokedex[i].name << "\n";
					}
				}
			}
		break;
	}

}
