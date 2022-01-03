#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declarations
void find_replace_esc(std::string &word, std::string match, std::string replace);
void find_replace_hex(std::string &word, std::string match, std::string replace);
void part_1(std::vector<std::string> &input);
void part_2(std::vector<std::string> &input);

int main(){

    // read input into vector of strings.
    std::vector<std::string> input = read_input("input_08", "");
    
    part_1(input);
    part_2(input);

    return 0;
}

void part_1(std::vector<std::string> &input){

    // copy of input for processing
    std::vector<std::string> input_copy = input;

    // count raw and processed string lengths
    int raw_count = 0;
    int processed_count = 0;

    for (size_t i=0; i<input.size(); i++){

        std::string &line = input_copy[i];

        // first remove " at beginning and end
        line = line.substr(1);
        line = line.substr(0,line.size()-1);

        // find and replace escaped characters
        find_replace_esc(line, R"(\\)", "1");
        find_replace_esc(line, R"(\")", "1");
        find_replace_hex(line, R"(\x)", "1");

        raw_count += input[i].size();
        processed_count += line.size();
    }

    std::cout << "Answer (part 1): " << raw_count-processed_count << std::endl;
}

void part_2(std::vector<std::string> &input){

    // copy of input for processing
    std::vector<std::string> input_copy = input;

    // count raw and processed string lengths
    int raw_count = 0;
    int processed_count = 0;

    for (size_t i=0; i<input.size(); i++){

        std::string &line = input_copy[i];

        // add 4 for '"' at begginning and end
        processed_count += 4;

        // find and replace escaped characters
        // to match extra chracters
        find_replace_esc(line, R"(\\)", "1111");
        find_replace_esc(line, R"(\")", "1111");
        find_replace_hex(line, R"(\x)", "11111");

        raw_count += input[i].size();
        processed_count += line.size();
    }

    std::cout << "Answer (part 2): " << processed_count-raw_count << std::endl;
}

// to replace '\\' and '\"' 
void find_replace_esc(std::string &word, std::string match, std::string replace){

    size_t pos = word.find(match);
    
    while ( pos != std::string::npos){
        word.erase(pos, 2);
        word.insert(pos, replace);

        pos = word.find(match);
    }
}

// to replace '\xnn' 
void find_replace_hex(std::string &word, std::string match, std::string replace){

    size_t pos = word.find(match);
    
    while ( pos != std::string::npos){
        word.erase(pos, 4);
        word.insert(pos, replace);

        pos = word.find(match);
    }
}