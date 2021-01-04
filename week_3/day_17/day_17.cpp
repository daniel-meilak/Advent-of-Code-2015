#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

int find_comb(std::vector<int> input, int target, int start_pos, std::vector<std::vector<int>> &history);

int main(){

    // read input into vector of strings.
    std::vector<int> input = input_to_int(read_input("input", ""));

    std::sort(input.rbegin(), input.rend());

    // target amount
    const int target = 150;

    // part 2
    std::vector<std::vector<int>> history(1);

    int part_1 = find_comb(input, target, 0, history);
    history.pop_back();

    // find min number of containers used in history
    unsigned int min = 100;
    unsigned int num_min = 0;
    for ( auto line : history ){
        if (line.size() < min){
            min = line.size();
            num_min = 1;
        }
        else if (line.size() == min){
            num_min++;
        }
    }

    std::cout << "Answer (part 1): " << part_1   << std::endl;
    std::cout << "Answer (part 2): " << num_min  << std::endl;

    return 0;
}

// Takes sorted vector of int and finds how many combinations of 
// values equals target
int find_comb(std::vector<int> input, int target, int start_pos, std::vector<std::vector<int>> &history){

    // output
    int count = 0;

    static int idx = 0;
    if (history.size() == 1){idx = 0;}
    unsigned int size = input.size();

    for (unsigned int i=start_pos; i<size; i++){

        // current element in input
        int current_size = input[i];

        // if sum of remaining numbers can't equal target, return count
        int sum = 0;
        for (unsigned int j=i; j<size; j++){ sum += input[j]; }
        if (sum < target){ 
            history[idx].pop_back();
            return count;
        }

        // if target is reached, incr count 
        if ( target == current_size){
            ++count;

            history.push_back(history[idx]);
            history[idx].push_back(current_size);
            idx++;
        }
        // else use find_comb on next values
        else if ( target > current_size ){
            history[idx].push_back(current_size);
            count += find_comb(input, target-current_size, i+1, history);
        }
    }

    history[idx].pop_back();
    return count;
}