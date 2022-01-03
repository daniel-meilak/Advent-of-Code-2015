#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

int main(){

    // read input into vector of strings.
    std::vector<std::string> input_full = read_input("input_01");

    // exctract single line into string
    std::string input = input_full[0];
    size_t size = input.size();

    // current floor
    int floor = 0;
    bool got_to_basement = false;
    int part2{0};

    // work through instructions
    for (size_t i=0; i<size; i++){

        // Part 1 
        if ( input[i] == '(' ){ floor++; }
        else { floor--; }

        // Part 2
        if ( (floor < 0) && !got_to_basement ){
            part2 = i+1;
            got_to_basement = true;
        }
    }

    // output final floor
    std::cout << "Answer (part 1): " << floor << std::endl;
    std::cout << "Answer (part 2): " << part2 << std::endl;

    return 0;
}
