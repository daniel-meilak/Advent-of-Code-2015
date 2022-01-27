#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<cstdlib>
#include"utils.h"

int calc_dist(std::unordered_map<std::string, int> &dist ,std::string a, std::string b);

int main(){

    // read input into vector of strings.
    std::vector<std::vector<std::string>> input = read_input_2D("input_09", {" ", "=", "to"});

    // vector containing place names
    std::vector<std::string> places;

    // map containing distances
    // map entries are placeAplaceB = dist
    // placeA and B are ordered alphabetically so same entries occur once
    std::unordered_map<std::string, int> dist;

    // loop through input and generate all distances
    for (std::vector<std::string> line : input){

        // check if cities are in places, if not add
        if (std::find(places.begin(), places.end(), line[0]) == places.end()){ places.push_back(line[0]); }
        if (std::find(places.begin(), places.end(), line[1]) == places.end()){ places.push_back(line[1]); }

        // add distance to map
        if ( line[0] < line[1] ){ dist[line[0]+line[1]] = std::stoi(line[2]); }
        else { dist[line[1]+line[0]] = std::stoi(line[2]); }
    }

    // keep track of min and max journey lengths
    int min = 1000000;
    int max = 0;
    int new_total;

    // use std::next_permutation to brute force all possible journeys
    do {
        new_total  = calc_dist(dist,places[0],places[1])+calc_dist(dist,places[1],places[2]);
        new_total += calc_dist(dist,places[2],places[3])+calc_dist(dist,places[3],places[4]);
        new_total += calc_dist(dist,places[4],places[5])+calc_dist(dist,places[5],places[6]);
        new_total += calc_dist(dist,places[6],places[7]);

        if (new_total < min){ min = new_total; }
        if (new_total > max){ max = new_total; }

    } while (std::next_permutation(places.begin(), places.end()));

    std::cout << "Answer (part 1): " << min << std::endl;
    std::cout << "Answer (part 2): " << max << std::endl;

    return 0;
}

int calc_dist(std::unordered_map<std::string, int> &dist ,std::string a, std::string b){

    if ( a < b ){ return dist[a+b]; }
    else { return dist[b+a]; }
}