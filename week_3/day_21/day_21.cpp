#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"
#include"game.h"

bool fight( hero me, enemy boss);

int main(){

    hero me;
    enemy boss;

    int best_cost = 1000;
    int worst_cost = 0;

    // check each item combination
    for ( auto armor : armor_shop ){
        me.armor = armor;

        for ( auto weapon : weapon_shop){
            me.weapon = weapon;

            for ( auto ring_l : ring_shop ){
                me.ring_l = ring_l;

                for ( auto ring_r : ring_shop){
                    // one of each item
                    if (ring_r.m_name == ring_l.m_name){ continue; }
                    me.ring_r = ring_r;

                    int item_cost = me.tot_cost();

                    bool win = fight(me,boss);
                
                    // if fight ends in win, check if cheapest
                    if ( win && item_cost<best_cost){ best_cost = item_cost; }
                    // if fight ends in loss, check if most expensive
                    else if ( !win && item_cost>worst_cost ){ worst_cost = item_cost; }
                }
            }
        }
    }

    std::cout << "Answer (part 1): " << best_cost << std::endl;
    std::cout << "Answer (part 2): " << worst_cost << std::endl;

    return 0;
}

bool fight( hero me, enemy boss){

    bool hero_wins;

    while (true){
        int damage = boss.damage - me.tot_defence();
        if (damage < 1){ damage = 1; }

        me.hp -= damage;
        if (me.hp <= 0){
            hero_wins = false;
            break;
        }

        damage = me.tot_damage() - boss.defence;
        if (damage < 1){ damage = 1; }

        boss.hp -= damage;
        if (boss.hp <= 0){
            hero_wins = true;
            break;
        }
    }

    return hero_wins;
}
