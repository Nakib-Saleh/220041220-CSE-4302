#include <bits/stdc++.h>
using namespace std;


class CharacterActions{
public:
    virtual int attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats()  = 0;

    virtual ~CharacterActions(){};
};

class BaseCharacter: public CharacterActions{
protected:
    string name;
    int health;
    int mana;

    int attackPower;
    string specialAbility;
    int specialAbilityPower;
public:
    BaseCharacter(string n, int h,int ap,string sa,int saPower )
    : name(n), health(h), mana(0), attackPower(ap), specialAbility(sa), specialAbilityPower(saPower){}

    int attack(){
        cout<<name<<" attacks with power "<<attackPower<<" !"<<endl;

        mana+=50;
        if(mana >= 100 ) {
            useSpecialAbility(); 
            mana = 0;

            return attackPower+specialAbilityPower;
        }
        return attackPower;
    }
    
    void defend(){
        cout<<name<<" defends the attack !"<<endl;
    }
    void useSpecialAbility(){
        cout<<name<<" uses "<<specialAbility<<" with power "<<specialAbilityPower<<" !"<<endl;

    }
    void displayStats() {
        cout << name << " - Health: " << health << " Mana: " << mana << endl;
    }
    
    string getName() {
        return name;
    }
    int getHealth() const {
        return health;
    }
    int getAttackPower(){
        return attackPower;
    }

    int getSpecialAbilityPower(){
        return specialAbilityPower;
    }


    void takeDamage(int damage) {
        health -= damage;
    }
    bool alive(){
        return health;
    }

};

class Warrior : public BaseCharacter {
public:
    Warrior() : BaseCharacter("Warrior", 100, 25, "Berserk Rage", 35) {}
};

class Mage : public BaseCharacter {
public:
    Mage() : BaseCharacter("Mage", 120, 20, "Arcane Blast", 30) {}
};

class Archer : public BaseCharacter {
public:
    Archer() : BaseCharacter("Archer", 90, 20, "Fire Arrow", 35) {}
};

class BossEnemy {
protected:
    int health;
    int attackPower;

public:
    BossEnemy(int h=150, int ap=30) : health(h), attackPower(ap) {}

    int getHealth() const {
        return health;
    }

    void takeDamage(int damage) {
        health -= damage;
    }
    bool alive(){
        if(health<=0) return false;
        return true;
    }
    int getAttackPower(){
        return attackPower;
    }
};

class GameEngine {
    bool playerAlive(BaseCharacter* players[], int count) {
        for (int i = 0; i < count; i++) {
            if (!players[i]->alive()) return false;
        }
        return true;
    }
   

public:
    void gameStart(BaseCharacter* players[], int plNo, BossEnemy& boss) {
        cout << "Game begins! Players vs. Boss" << endl;

        while (boss.alive() && playerAlive(players, plNo)) {
            
            for (int i = 0; i < plNo; i++) {
                int damage= players[i]->attack();
                boss.takeDamage(damage);
                cout << "Boss takes " << damage << " damage! Health now: " << boss.getHealth() << endl;
                if(!boss.alive()) break;
            }
            
            if(boss.alive()){
                for (int i = 0; i < plNo; i++) {
                    cout << "Boss attacks " << players[i]->getName() << " with power " << boss.getAttackPower() << "!" << endl;
                    players[i]->takeDamage(boss.getAttackPower());
                    cout << players[i]->getName() << " takes damage! Health now: " << players[i]->getHealth() << endl;
                }
            }
            else break;  
        }

        if (boss.alive()) {
            cout << "Boss wins! Players lose!" << endl;
        } else {
            cout << "Boss defeated! Players win!" << endl;
        }
    }

    
};

int main() {
    
    BaseCharacter* players[3];
    players[0] = new Warrior();
    players[1] = new Mage();
    players[2] = new Archer();

    BossEnemy boss;

    GameEngine engine;
    engine.gameStart(players, 3, boss);

   
    for (int i = 0; i < 3; i++) {
        delete players[i];
    }

    return 0;
}


