#ifndef GAME_H
#define GAME_H

#include<vector>
#include<string>

const std::vector<std::string> delimiters = {"Hit Points: ","Damage: "};
const std::vector<int> input = input_to_int(read_input("input_22",delimiters));

// forward struct declaration
struct hero;

struct enemy{

    // curremt stats
    int hp = input[0];
    int damage = input[1];
    bool alive = true;

    // (de)buffs timers and effects
    int poison_timer = 0;

    // status effects
    bool poisoned = false;

    // attacks
    void bonk(hero &player);
};

struct hero{

    // current stats
    int hp = 50;
    int mana = 500;
    int mana_spent = 0;
    int armor = 0;
    bool alive = true;

    // (de)buff timers and effects
    int armor_timer = 0;
    int recovery_timer = 0;

    // status effects
    bool shielded = false;
    bool recovering = false;

    // spells
    void magic_missile(enemy &boss);
    void drain(enemy &boss);
    void shield();
    void poison(enemy &boss);
    void recharge();

    // check effects
    void effects(enemy &boss);
};

void hero::magic_missile(enemy &boss){
    mana -= 53;
    // if mana reaches zero player dies
    if (mana <= 0){
        alive=false;
        return;
    }
    mana_spent += 53;

    boss.hp -= 4;
    // check if boss is dead from hit
    if (boss.hp <= 0){boss.alive = false;}
}

void hero::drain(enemy &boss){
    mana -= 73;
    // if mana reaches zero player dies
    if (mana <= 0){
        alive=false;
        return;
    }
    mana_spent += 73;

    hp += 2;

    boss.hp -= 2;
    // check if boss is dead from hit
    if (boss.hp <= 0){boss.alive = false;}
}

void hero::shield(){

    // if already shielded, player dies
    if (shielded){
        alive = false;
        return;
    }

    mana -= 113;
    // if mana reaches zero player dies
    if (mana <= 0){
        alive=false;
        return;
    }
    mana_spent += 113;

    armor_timer = 6;
    shielded = true;
}

void hero::poison(enemy &boss){

    // if already poisoned, player dies
    if (boss.poisoned){
        alive = false;
        return;
    }

    mana -= 173;
    // if mana reaches zero player dies
    if (mana <= 0){
        alive=false;
        return;
    }
    mana_spent += 173;

    boss.poisoned = true;
    boss.poison_timer = 6;
}

void hero::recharge(){

    // if already recovering, player dies
    if (recovering){
        alive = false;
        return;
    }

    mana -= 229;
    // if mana reaches zero player dies
    if (mana <= 0){
        alive=false;
        return;
    }
    mana_spent += 229;

    recovering = true;
    recovery_timer = 5;
}

void hero::effects(enemy &boss){

    // mana recovery
    if (recovering){
        mana += 101;
        recovery_timer--;

        if (recovery_timer == 0){
            recovering = false;
        }
    }

    // bonus armor
    if (shielded){
        armor = 7;
        armor_timer--;

        if (armor_timer == 0){
            shielded = false;
        }
    }
    else {
        armor = 0;
    }

    // poison
    if (boss.poisoned){
        // apply hit
        boss.hp -= 3;
        // check if hit kills boss
        if (boss.hp <= 0){
            boss.alive = false;
            return;
        }
        
        boss.poison_timer--;
        // check if poison is over
        if (boss.poison_timer == 0){
            boss.poisoned = false;
        }
    }    
}

void enemy::bonk(hero &player){
    player.hp -= damage - player.armor;
    if (player.hp <= 0){player.alive = false;}
}

#endif /* GAME_H */