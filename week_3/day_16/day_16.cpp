#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// data from the MFCSAM
struct Sue {
    int id;
    int children    = 3;
    int cats        = 7;
    int samoyeds    = 2;
    int pomeranians = 3;
    int akitas      = 0;
    int vizslas     = 0;
    int goldfish    = 5;
    int trees       = 3;
    int cars        = 2;
    int perfumes    = 1;
};

// forward function declarations
bool check_property_1(const std::vector<std::string> &aunt, const unsigned int &property);
bool check_property_2(const std::vector<std::string> &aunt, const unsigned int &property);

int main(){

    // read input into vector of strings.
    std::vector<std::string> delimiters = {":", " ", ","};
    std::vector<std::vector<std::string>> input = read_input_2D("input_16", delimiters);

    // The Sue that got the gift for part 1 and 2
    int part_1 = 0;
    int part_2 = 0;

    // loop through Sue's
    for ( std::vector<std::string> aunt : input ){

        // bool to check if all properties are correct
        bool valid_1 = true;
        bool valid_2 = true;

        // loop through Sue properties
        for (unsigned int i=2; i<aunt.size()-1; i+=2){
            valid_1 = check_property_1(aunt, i) && valid_1;
            valid_2 = check_property_2(aunt, i) && valid_2;
        }

        if (valid_1){ part_1 = std::stoi(aunt[1]); }
        if (valid_2){ part_2 = std::stoi(aunt[1]); }
    }    

    std::cout << "Answer (part 1): " << part_1 << std::endl;
    std::cout << "Answer (part 2): " << part_2 << std::endl;

    return 0;
}

// checks if sue properties matches the reference (part 1)
bool check_property_1(const std::vector<std::string> &aunt, const unsigned int &property){

    Sue sue;

    if      (aunt[property] == "children"    ){ if ( std::stoi(aunt[property+1]) == sue.children    ){ return true; } }
    else if (aunt[property] == "cats"        ){ if ( std::stoi(aunt[property+1]) == sue.cats        ){ return true; } }
    else if (aunt[property] == "samoyeds"    ){ if ( std::stoi(aunt[property+1]) == sue.samoyeds    ){ return true; } }
    else if (aunt[property] == "pomeranians" ){ if ( std::stoi(aunt[property+1]) == sue.pomeranians ){ return true; } }
    else if (aunt[property] == "akitas"      ){ if ( std::stoi(aunt[property+1]) == sue.akitas      ){ return true; } }
    else if (aunt[property] == "vizslas"     ){ if ( std::stoi(aunt[property+1]) == sue.vizslas     ){ return true; } }
    else if (aunt[property] == "goldfish"    ){ if ( std::stoi(aunt[property+1]) == sue.goldfish    ){ return true; } }
    else if (aunt[property] == "trees"       ){ if ( std::stoi(aunt[property+1]) == sue.trees       ){ return true; } }
    else if (aunt[property] == "cars"        ){ if ( std::stoi(aunt[property+1]) == sue.cars        ){ return true; } }
    else if (aunt[property] == "perfumes"    ){ if ( std::stoi(aunt[property+1]) == sue.perfumes    ){ return true; } }

    return false;
}

// checks if sue properties matches the reference (part 2)
bool check_property_2(const std::vector<std::string> &aunt, const unsigned int &property){

    Sue sue;

    if      (aunt[property] == "children"    ){ if ( std::stoi(aunt[property+1]) == sue.children    ){ return true; } }
    else if (aunt[property] == "cats"        ){ if ( std::stoi(aunt[property+1]) >  sue.cats        ){ return true; } }
    else if (aunt[property] == "samoyeds"    ){ if ( std::stoi(aunt[property+1]) == sue.samoyeds    ){ return true; } }
    else if (aunt[property] == "pomeranians" ){ if ( std::stoi(aunt[property+1]) <  sue.pomeranians ){ return true; } }
    else if (aunt[property] == "akitas"      ){ if ( std::stoi(aunt[property+1]) == sue.akitas      ){ return true; } }
    else if (aunt[property] == "vizslas"     ){ if ( std::stoi(aunt[property+1]) == sue.vizslas     ){ return true; } }
    else if (aunt[property] == "goldfish"    ){ if ( std::stoi(aunt[property+1]) <  sue.goldfish    ){ return true; } }
    else if (aunt[property] == "trees"       ){ if ( std::stoi(aunt[property+1]) >  sue.trees       ){ return true; } }
    else if (aunt[property] == "cars"        ){ if ( std::stoi(aunt[property+1]) == sue.cars        ){ return true; } }
    else if (aunt[property] == "perfumes"    ){ if ( std::stoi(aunt[property+1]) == sue.perfumes    ){ return true; } }

    return false;
}