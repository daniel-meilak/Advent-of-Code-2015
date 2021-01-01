#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

int main(){

    // read input into vector of strings.
    std::vector<int> input = input_to_int(read_input("input", ""));

    const int target = 150;

    std::sort(input.rbegin(), input.rend());
    std::vector<int> best(target+1), ways(target+1);
    std::fill(best.begin(), best.end(), std::numeric_limits <int>::max() - 1);

    ways[0] = 1;
    best[0] = 0;

    for (auto && c : input){
        for (int rem=target; rem >= c; --rem){
            if (best[rem - c] + 1 < best[rem]){
                best[rem] = best[rem-c] + 1, ways[rem] = 0;
            }
            if (best[rem - c] + 1 == best[rem]){
                ways[rem] += ways [rem - c];
            }
        }
    }

    std::cout << "Answer (part 1): " << ways[target] << std::endl;

    return 0;
}
