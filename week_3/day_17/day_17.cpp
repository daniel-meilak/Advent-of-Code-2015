#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

int find_comb(std::vector<int> input, int target);

int main(){

    // read input into vector of strings.
    std::vector<int> input = input_to_int(read_input("input", ""));

    std::sort(input.rbegin(), input.rend());

    // target amount
    const int target = 150;

    int part_1 = find_comb(input, target);

    std::cout << "Answer (part 1): " << part_1 << std::endl;
    //std::cout << "Answer (part 2): " << count  << std::endl;

    return 0;
}

// Takes sorted vector of int and finds how many compinations of 
// values equals target
int find_comb(std::vector<int> input, int target){

    // output
    int count = 0;

    std::vector<int> input_copy;
    unsigned int size = input.size();

    for (unsigned int i=0; i<size; i++){

        // current element in input
        int current_size = input[i];

        // if sum of remaining numbers can't equal target, return count
        int sum = 0;
        for (unsigned int j=i; j<size; j++){ sum += input[j]; }
        if (sum < target){ return count; }

        // if target is reached, incr count 
        if ( target == current_size){
            ++count;
        }
        // else use find_comb on next values
        else if ( target > current_size ){
            input_copy.assign(input.begin()+i+1, input.end());
            count += find_comb(input_copy, target-current_size);
        }
    }

    return count;
}