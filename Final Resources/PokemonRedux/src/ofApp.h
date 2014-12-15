#pragma once
#include <iostream>
#include <string>
#include "ofMain.h"

struct Pokemon{
	int idNum;
	string name;
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


class Effect{
    private:
        int index;
        int damage;
        int heal;
        int atk;
        int def;
        int spd;
        int spec;
};

/*struct Move{};
        int power;
        char name[11];
    public:
        Move(Effect effect_in, int pow_in, string name_in);
        Move();
        void setMove(Effect effect_in, int pow_in, string name_in);
        void setMove();
};

class Attack{
    private:
        int damageType;  // Grass, water, fire,etc
        int attackType;  // Physical/special
        int attackGroup; // Damage, drain, lower stat, etc
    public:
       Attack()



};
class Damage{

};

class Drain{

};

class LowerStat{

};

class Heal{

};
*/
class BattlePoke{
    private:
        int maxHP;
        int atkStat;
        int defStat;
        int spdStat;
        int specStat;
        int move1;
        int move2;
        int move3;
        int move4;
        int exp;
        int level;
    public:
        int hp;
        int atk;
        int def;
        int spd;
        int spec;
        int faint;//1 or 0
        int isWild;
        BattlePoke(struct Pokemon pokemon, int level);
		void evolve();
        //void learnMove(Move newMove);
        void battle(BattlePoke opponent);
};




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage george;
		ofImage ralph;
		ofImage larry;
		int i,j,k;

};
