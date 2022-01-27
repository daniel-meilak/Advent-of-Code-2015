#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"utils.h"
#include"game.h"

// forward function declaration
int fight(hero player, enemy boss, int &spell, bool hard_mode);
void player_turn(hero &player, enemy &boss, int spell, bool hard_mode);
void boss_turn(hero &player, enemy &boss);

int main(){

    hero player;
    enemy boss;

    int min_mana1 = 1000000;
    int min_mana2 = 1000000;
    int mana;
    
    for ( int i=0; i<5; i++ ){
        mana = fight(player, boss, i, false);
        if (mana < min_mana1){ min_mana1 = mana; }
    }

    for ( int i=0; i<5; i++ ){
        mana = fight(player, boss, i, true);
        if (mana < min_mana2){ min_mana2 = mana; }
    }


    std::cout << "Answer: " << min_mana1 << std::endl;
    std::cout << "Answer: " << min_mana2 << std::endl;

    return 0;
}

int fight(hero player, enemy boss, int &spell, bool hard_mode){

    int min_mana = 1000000;

    // player turn
    player_turn(player, boss, spell, hard_mode);
    if (!player.alive){ return 1000000;}
    if (!boss.alive){return player.mana_spent;}

    // boss turn
    boss_turn(player, boss);
    if (!boss.alive){return player.mana_spent;}
    if (!player.alive){ return 1000000;}

    int mana_spent;
    for ( int i=0; i<5; i++ ){
        mana_spent = fight(player, boss, i, hard_mode);
        if (mana_spent < min_mana){ min_mana = mana_spent; }
    }

    return min_mana;
}

void player_turn(hero &player, enemy &boss, int spell, bool hard_mode){

    // if hard mode, take 1 hp off per player round
    if (hard_mode){
        player.hp -= 1;
        if (player.hp <= 0){
            player.alive = false;
            return;
        }
    }

    // check effects
    player.effects(boss);

    // if not dead cast spell
    if (player.alive){
        switch (spell){
            case 0:
                player.magic_missile(boss);
                break;
            case 1:
                player.drain(boss);
                break;
            case 2:
                player.shield();
                break;
            case 3:
                player.poison(boss);
                break;
            case 4:
                player.recharge();
                break;
        }
    }
}

void boss_turn(hero &player, enemy &boss){

    // check effects
    player.effects(boss);

    // if not dead attack human
    if (boss.alive){ boss.bonk(player); }
}   
