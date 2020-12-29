#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<../../Utils/utils.h>

int main(){

    // read input into vector of strings.
    std::vector<std::string> input_full = read_input("input", "");

    // exctract single line into string
    std::string input = input_full[0];

    // current floor
    int floor = 0;
    bool got_to_basement = false;

    // work through instructions
    for (unsigned int i=0; i<input.size(); i++){

        // Part 1 
        if ( input[i] == '(' ){
            floor++;
        }
        else {
            floor--;
        }

        // Part 2
        if ( (floor < 0) && !got_to_basement ){
            std::cout << "Got to basement after " << i+1 << " steps." << std::endl;
            got_to_basement = true;
        }


    }

    // output final floor
    std::cout << "Final floor: " << floor << std::endl;


    return 0;
}
