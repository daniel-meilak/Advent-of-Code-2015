#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declarations
bool three_vowels(std::string word);
bool double_letter(std::string word);
bool no_excluded(std::string word);
bool pair_twice(std::string word);
bool repeat_inbetween(std::string word);

int main(){

    // read input into vector of strings.
    std::vector<std::string> input = read_input("input", "");

    // number of valid strings
    int nice_strings_part1 = 0;
    int nice_strings_part2 = 0;

    // cheack each word
    for (std::string word : input){

        // if all three rules are satisfied, increment count
        if (three_vowels(word) && double_letter(word) && no_excluded(word)){
            nice_strings_part1++;
        }

        if (pair_twice(word) && repeat_inbetween(word)){
            nice_strings_part2++;
        }
    }

    std::cout << "Answer (part 1): " << nice_strings_part1 << std::endl;
    std::cout << "Answer (part 2): " << nice_strings_part2 << std::endl;

    return 0;
}

// check if string contains at least 3 vowels
bool three_vowels(std::string word){

    // required vowels
    std::string vowels = "aeiou";

    // count
    int num_vowels = 0;

    for ( const char & vowel : vowels){

        // find number of each vowel in word
        num_vowels += std::count(word.begin(), word.end(), vowel);

        // if tally >= 3, word is valid. 
        if (num_vowels >= 3){
            return true;
        }
    }

    // if tally doesn't reach 3, word is invalid
    return false;
}

// check if string contains double letters next to each other
bool double_letter(std::string word){

    // loop through each letter checking for doubles
    for (unsigned int i=0; i<word.size()-1; i++){
        
        // if a double is found word is valid
        if (word[i] == word[i+1]){
            return true;
        }
    }

    // no doubles, word is invalid
    return false;
}

// check that string doesn't contain "ab", "cd", "pq", "xy"
bool no_excluded(std::string word){

    bool ab, cd, pq, xy;

    // search for each excluded string in word
    ab = word.find("ab") == std::string::npos;
    cd = word.find("cd") == std::string::npos;
    pq = word.find("pq") == std::string::npos;
    xy = word.find("xy") == std::string::npos;

    // if all excluded word is valid
    if ( ab && cd && pq && xy ){
        return true;
    }
    // else word is invalid
    else {
        return false;
    }
}

// check if pair of letters appears twice in string
bool pair_twice(std::string word){

    // contiain split up word
    std::string part1, part2;

    // loop through pairs of letters
    for (unsigned int i=0; i<word.size()-1; i++){

        // pair to match
        std::string match = word.substr(i,2);

        // remove match from word and split into two 
        part1 = word.substr(0,i);
        if ( i != word.size()-2 ){
            part2 = word.substr(i+2);
        }
        else {
            part2 = "";
        }

        // if another copy of match is found in part1 or part2, word is valid
        if ( (part1.find(match) != std::string::npos) || (part2.find(match) != std::string::npos) ){
            return true;
        }
    }

    // no matches found, word is invalid
    return false;
}

// checks if word contains letters which repeat with an extra letter inbetween
bool repeat_inbetween(std::string word){

    // loop through letters
    for (unsigned int i=0; i<word.size()-2; i++){

        // if repeating letters found, word is valid
        if (word[i] == word[i+2]){
            return true;
        }
    }

    // no repeating letters found, word is invalid
    return false;
}