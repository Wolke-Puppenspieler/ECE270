#pragma once

#include "ofMain.h"

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

class Move{
    private:
        Effect effect;
        int power;
        string name;
    public:
        Move(Effect effect_in, int pow_in, string name_in);
        Move();
        setMove(Effect effect_in, int pow_in, string name_in);
        setMove()
};

class Pokemon{
    private:
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

        Pokemon(int baseHP_in, int baseAtk_in, int baseDef_in, int baseSpd_in, int baseSpec_in, int type1_in, int type2_in, int evoLvl_in, int expClass_in);
        Pokemon();
        void setPoke(int baseHP_in, int baseAtk_in, int baseDef_in, int baseSpd_in, int baseSpec_in, int type1_in, int type2_in, int evoLvl_in, int expClass_in);
};

class PartyPokemon{
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
        int faint; //1 or 0
        PartyPokemon(Pokemon, int level)
        void learnMove(Move newMove)
};

