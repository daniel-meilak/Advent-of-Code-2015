#ifndef GAME_H
#define GAME_H

#include<vector>
#include<string>

struct equipment{
    std::string m_name;
    int m_cost;
    int m_damage;
    int m_defence;
    equipment(std::string name, int cost, int damage, int defence):m_name(name), m_cost(cost), m_damage(damage), m_defence(defence){};
};

equipment empty("empty",0,0,0);

equipment leather("leather",13,0,1);
equipment chainmail("chainmail",31,0,2);
equipment splintmail("splintmail",53,0,3);
equipment bandedmail("bandedmail",75,0,4);
equipment platemail("platemail",102,0,5);
std::vector<equipment> armor_shop = {empty, leather, chainmail, splintmail, bandedmail, platemail};

equipment dagger("dagger",8,4,0);
equipment shortsword("shortsword",10,5,0);
equipment warhammer("warhammer",25,6,0);
equipment longsword("longsword",40,7,0);
equipment greataxe("greataxe",74,8,0);
std::vector<equipment> weapon_shop = {dagger, shortsword, warhammer, longsword, greataxe};

equipment damage1("damage +1",25,1,0);
equipment damage2("damage +2",50,2,0);
equipment damage3("damage +3",100,3,0);
equipment defence1("defence +1",20,0,1);
equipment defence2("defence +2",40,0,2);
equipment defence3("defence +3",80,0,3);
std::vector<equipment> ring_shop = {empty, damage1, damage2, damage3, defence1, defence2, defence3};

struct hero{

    int hp = 100;
    equipment armor  = empty;
    equipment weapon = empty;
    equipment ring_l  = empty;
    equipment ring_r  = empty;
    int tot_defence();
    int tot_damage();
    int tot_cost();   
};

int hero::tot_defence(){ return armor.m_defence + weapon.m_defence + ring_l.m_defence + ring_r.m_defence; }
int hero::tot_damage(){ return armor.m_damage + weapon.m_damage + ring_l.m_damage + ring_r.m_damage; }
int hero::tot_cost(){ return armor.m_cost + weapon.m_cost + ring_l.m_cost + ring_r.m_cost; }

struct enemy{

    int hp = 109;
    int damage = 8;
    int defence = 2;
};





#endif /* GAME_H */