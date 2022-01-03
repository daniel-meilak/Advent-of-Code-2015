#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<unordered_map>
#include"../../Utils/utils.h"

// forward function declarations
size_t houses(const std::vector<std::string> &input, const bool part2);

int main(){

    // read input into vector of strings.
    std::vector<std::string> input = read_input("input_03");

    std::cout << "Answer (part 1): " << houses(input,false) << std::endl;
    std::cout << "Answer (part 2): " << houses(input,true ) << std::endl;

    return 0;
}

size_t houses(const std::vector<std::string> &input, const bool part2){
    
    // create map of visited houses
    std::unordered_map<std::string, int> grid;

    // grid coordinaates
    std::vector<int> x={0,0}, y={0,0};

    // present for origin
    std::string pos = "0";
    grid[pos] += 2;

    bool santa = true;

    // move along grid 
    for (const char & dir : input[0]){

        int &x_i = x[santa];
        int &y_i = y[santa];

        switch (dir){
            case '^':
                y_i++;
                pos = std::to_string(x_i*1000 + y_i);
                grid[pos]++;
                break;
            case 'v':
                y_i--;
                pos = std::to_string(x_i*1000 + y_i);
                grid[pos]++;
                break;
            case '>':
                x_i++;
                pos = std::to_string(x_i*1000 + y_i);
                grid[pos]++;
                break;
            case '<':
                x_i--;
                pos = std::to_string(x_i*1000 + y_i);
                grid[pos]++;
                break;
        }

        if (part2){ santa = !santa; }
    }

    return grid.size();
}