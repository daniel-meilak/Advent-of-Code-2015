#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<map>
#include"../../Utils/utils.h"

int main(){

    // read input into vector of vector of strings.
    std::vector<std::vector<std::string>> input = read_input_2D("input", {" ", ".", "would", "happiness units by sitting next to"});

    // map relating person pair and happiness gained/lost
    std::map<std::string, int> relation;

    // vector of persons
    std::vector<std::string> persons;

    // build map
    for (std::vector<std::string> line : input){

        // add unique people to persons vector
        if ( std::find(persons.begin(), persons.end(), line[0]) == persons.end() ){
            persons.push_back(line[0]);
        }

        if (line[1] == "gain"){
            relation[line[0]+line[3]] = std::stoi(line[2]);
        }
        else {
            relation[line[0]+line[3]] = -std::stoi(line[2]);
        }
    }

    // total happiness from configuration
    int happiness = 0;
    int current_config;

    int n = persons.size();

    // brute force each permutation using std::next_permutation
    do{
        current_config = 0;

        for (int i=0; i<n; i++){
            current_config += relation[persons[i]+persons[mod(i-1,n)]];
            current_config += relation[persons[i]+persons[mod(i+1,n)]];
        }

        // if current config has higher happiness, reassign
        if ( current_config > happiness ){ happiness = current_config; }

    } while( std::next_permutation(persons.begin(), persons.end()) );

    std::cout << "Answer (part 1): " << happiness << std::endl;

    // create releations for "Me"
    for ( std::string person : persons ){
        relation["Me"+person] = 0;
        relation[person+"Me"] = 0;
    }

    // add "me" to person vector
    persons.push_back("Me");

    // brute force each permutation with "me" included
    happiness = 0;
    n = persons.size();
    do{
        current_config = 0;

        for (int i=0; i<n; i++){
            int tmp = i-1;
            current_config += relation[persons[i]+persons[mod(tmp,n)]];
            current_config += relation[persons[i]+persons[mod(i+1,n)]];
        }

        // if current config has higher happiness, reassign
        if ( current_config > happiness ){
            happiness = current_config;
        }

    } while( std::next_permutation(persons.begin(), persons.end()) );

    std::cout << "Answer (part 2): " << happiness << std::endl;

    return 0;
}

