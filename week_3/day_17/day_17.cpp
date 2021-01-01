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

    int num = find_comb(input, 150);

    std::cout << num << std::endl;

    return 0;
}

int find_comb(std::vector<int> input, int target){

    // if input is empty return
    if (input.size() == 0){ return 0; }

    std::vector<int> input_copy;
    int count = 0;

    for (unsigned int i=0; i<input.size(); i++){

        // if remaining numbers in input cant equal target return
        int sum = 0;
        for (int num : input){ sum+= num; }
        if (sum < target){ return count; }
        
        input_copy = input;

        int current_size = input[i];
        if ( target == current_size){
            ++count;
            input.erase(input.begin()+i);
            --i;
        }
        else if ( target > current_size ){
            input_copy.erase(input_copy.begin()+i);
            count += find_comb(input_copy, target-current_size);
            input.erase(input.begin()+i);
            --i;
            input_copy = input;
        }
        else if (target < current_size){
            input.erase(input.begin()+i);
            --i;
        }
         
    }

    return count;
}