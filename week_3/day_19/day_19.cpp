#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include"../../Utils/utils.h"

int main(){

    // read input into vector of strings.
    std::vector<std::string> delimiter = {" ", "=>"};
    std::vector<std::vector<std::string>> input = read_input_2D("input", delimiter);

    // create vector of pairs of replacements
    std::vector<std::pair<std::string, std::string>> replace;

    int i=0;
    // populate map
    while (!input[i].empty()){
        replace.push_back({input[i][0], input[i][1]});
        i++;
    }

    // get molecule string 
    std::string mol = input.back()[0];

    // vector of unique substituted molecules
    std::vector<std::string> distinct;

    // loop through map keys
    for (const auto & [key, value] : replace){
            
        size_t pos = mol.find(key);
        while (pos != std::string::npos){
            std::string mol_copy = mol;
            mol_copy.replace(pos,key.size(),value);

            // if replacement is unique, add to distinct_mol
            if (std::find(distinct.begin(), distinct.end(), mol_copy) == distinct.end()){ distinct.push_back(mol_copy); }

            pos = mol.find(key, pos+1);
        }
    }

    std::cout << "Answer (part 1): " << distinct.size() << std::endl;

    std::string target = mol;
    int min_steps = 0;

    // going from end to start
    // while we havent reached start
    while (target != "e"){

        // create a copy of target for comparison
        std::string tmp = target;

        // go through each poss substitution and make replacements
        // where possible
        for ( const auto & [key, value] : replace){
            size_t pos = target.find(value);
            if ( pos == std::string::npos ){ continue; }

            target = target.replace(pos, value.size(), key );
            min_steps++;
        }

        // if no substitutions are made, the current order of subs is wrong
        // shuffle and try again
        if (tmp == target){
            target = mol;
            min_steps = 0;
            std::random_shuffle(replace.begin(), replace.end());
        }
    }


    std::cout << "Answer (part 2): " << min_steps << std::endl;

    return 0;
}
