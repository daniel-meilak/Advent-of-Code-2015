#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declarations
std::string look_and_say(std::string term);

int main(){

    // read input into strings.
    std::string input = "1321131112";

    // find the next Conway term x50
    for (int i=0; i<50; i++){
        input = look_and_say(input);
    }

    std::cout << "Answer (part 1): " << input.size() << std::endl;

    return 0;
}

// finds the next Conway term
std::string look_and_say(std::string term){

    // pad term with extra letter at end
    term.push_back('a');
    char num = term[0];
    int count = 1;
    std::string next_term;
    
    // work through term n and build term n+1
    for ( unsigned int i=1; i<term.size(); i++ ){

        // if next number repeats, its count increases
        if ( num == term[i] ){
            count++;
        }
        // if next numbner is new, add count and old number
        // to term n+1
        else {
            next_term += std::to_string(count);
            next_term += num;
            num = term[i];
            count = 1;
        }
    }

    return next_term;
}
