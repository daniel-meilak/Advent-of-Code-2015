#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<climits>
#include<cstdlib>
#include<utility>
#include"../../Utils/utils.h"

int find_comb(std::vector<int> input, int target, int start_pos, std::vector<std::vector<int>> &history);
long quantum_entaglement(std::vector<int> input, int target);

int main(){

    // read input into vector of int.
    std::vector<int> input = input_to_int(read_input("input_24", ""));

    // reverse vector so it is sorted high to low
    std::reverse(input.begin(), input.end());

    // sum of weights
    int sum = std::accumulate(input.begin(), input.end(), 0);

    std::cout << "Answer (part 1): " << quantum_entaglement(input, sum/3) << std::endl;
    std::cout << "Answer (part 2): " << quantum_entaglement(input, sum/4) << std::endl;

    return 0;
}

long quantum_entaglement(std::vector<int> input, int target){
    
    // history to track combinations
    std::vector<std::vector<int>> history(1);

    // find all combinations
    find_comb(input, target, 0, history);
    history.pop_back();

    // find combinations with lowest number of boxes
    size_t min_size = 1000;
    for (std::vector<int> comb : history){
        size_t size = comb.size();
        if (size < min_size){ min_size = size; }
    }

    // vector of pairs of smallest combinations and their quantum entanglement (product of elements)
    std::vector<std::pair<std::vector<int>, long>> best_comb;

    // find and calculate quantum entaglements
    for (std::vector<int> comb : history){
        if (comb.size() == min_size){
            long product = std::accumulate(comb.begin(), comb.end(), 1L, std::multiplies<long>());
            best_comb.push_back({comb, product});
        }
    }

    // loop for smallest quantum entaglement
    long min_entangle = LONG_MAX;
    for (auto pair : best_comb){
        if (pair.second < min_entangle){ min_entangle = pair.second; }
    }

    return min_entangle;
}

// Takes sorted vector of int and finds how many combinations of 
// values equals target
int find_comb(std::vector<int> input, int target, int start_pos, std::vector<std::vector<int>> &history){

    // output
    int count = 0;

    static int idx = 0;
    if (history.size() == 1){ idx = 0; }
    size_t size = input.size();

    for (size_t i=start_pos; i<size; i++){

        // current element in input
        int current_size = input[i];

        // if sum of remaining numbers can't equal target, return count
        int sum = 0;
        for (size_t j=i; j<size; j++){ sum += input[j]; }
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