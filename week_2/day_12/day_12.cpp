#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<regex>
#include"utils.h"

void part_1(std::string word);
void part_2(std::string word);

int main(){

    // read input into vector of strings.
    std::vector<std::string> input = read_input("input_12");
    std::string json = input[0];

    part_1(json);
    part_2(json);

    return 0;
}


// sums up all numbers in string
void part_1(std::string word){

    // regex that matches any -/+ int
    std::regex numbers(R"(-?\d+)");

    // store summation of ints
    int sum = 0;

    std::sregex_iterator rbegin(word.begin(), word.end(), numbers);
    std::sregex_iterator rend;

    // iterate through json and add upp numbers
    while (rbegin != rend){
        sum += std::stoi(rbegin->str());
        ++rbegin;
    }

    std::cout << "Answer: " << sum << std::endl;
}

// takes summed numbers and removes contributions
// from objects containing red
void part_2(std::string word){

    // work through word find red in objects
    std::string red_object = R"(:"red")";

    size_t pos = word.find(red_object);

    // find the full object containing red_object
    while ( pos != std::string::npos ){

        int count = 1;
        size_t begin = pos;
        // find corresponding "{"
        while ( count != 0 ){
            begin--;
            char c = word[begin];
            if (c == '}'){
                count++;
            }
            else if (c == '{'){
                count--;
            }
        }

        count = 1;
        size_t end = pos;
        // find corresponding "}"
        while ( count != 0 ){
            end++;
            char c = word[end];
            if (c == '{'){
                count++;
            }
            else if (c == '}'){
                count--;
            }
        }
        end++;

        // remove red object from word
        word.erase(begin, end-begin);

        // move pos to begin (end of deleted region) to find next red_object
        pos = begin;
        pos = word.find(red_object, pos);
    }

    // json no longer contains objects with red
    // Use part 1 to calculate new answer from json 
    part_1(word);
}

