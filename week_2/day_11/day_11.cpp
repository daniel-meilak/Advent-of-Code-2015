#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declarations
void increment_password(std::string &password, size_t n);
bool straight(std::string password);
bool dont_contain(std::string password, std::string invalid_letters);
bool two_matching(std::string password);
void part_1(std::string &input);
void part_2(std::string &input);

int main(){

    // read input into string.
    std::string input = "hepxcrrq";

    part_1(input);
    part_2(input);

    return 0;
}

// find next valid password from input
void part_1(std::string &input){

    while ( !(straight(input) && dont_contain(input,"iol") && two_matching(input)) ){
        increment_password(input, input.size());
    }

    std::cout << "Answer: " << input << std::endl;
}

// find next valid password from part 1
void part_2(std::string &input){

    // increment password as password from part 1 is valid
    increment_password(input, input.size());

    part_1(input);
}

// increment string at pos n by 1
// eg fun(aaa,3) -> aab
void increment_password(std::string &password, size_t n){

    if ( password[n-1] == 'z' ){
        password[n-1] = 'a';
        increment_password(password,n-1);
    }
    else {
        ++password[n-1];
    }
}

// checks if string contains straight of 3 letters
// eg abc, xyz
bool straight(std::string password){

    for (unsigned int i=0; i<password.size()-2; i++){
        // to compare reduce next numbers
        char a = password[i];
        char b = password[i+1]-1;
        char c = password[i+2]-2;

        // if number are now equal, password is valid
        if ( (a==b) && (a==c) ){
            return true;
        }
    }

    // if no straight exist, password is invalid
    return false;
}

// checks that password doesnt contain any invalid letters
bool dont_contain(std::string password, std::string invalid_letters){

    // loop through all invalid letters
    for ( char letter : invalid_letters){

        // if an invalid letter is found
        if ( password.find(letter) != std::string::npos ){

            // password is invalid
            return false;
        }
    }

    // no invalid letters found
    return true;
}

// checks for two pairs of matching letters
bool two_matching(std::string password){

    // number of matches
    int num_matches=0;

    // start with aa
    char letter = 'a';

    // check every letter pair for match
    for (int i=0; i<26; i++){
        
        std::string match = {letter, letter};

        if (password.find(match) != std::string::npos){
            num_matches++;
        }

        // If two pairs are found, password is valid
        if (num_matches == 2){
            return true;
        }

        // increment letter (a -> b)
        letter++;
    }

    // if less than two pairs are found, password is invalid
    return false;
}