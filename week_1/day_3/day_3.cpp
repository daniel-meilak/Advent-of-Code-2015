#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<unordered_map>
#include"../../Utils/utils.h"

int main(){

    // read input into vector of strings.
    std::vector<std::string> input = read_input("input", "");

    // create map of visited houses
    std::unordered_map<std::string, int> grid;

    // gride coordinaates
    std::vector<int> x={0,0}, y={0,0};

    // present for origin
    std::string pos = "0";
    grid[pos] += 2;

    bool santa = true;
    int i;

    // move along grid 
    for ( const char & dir : input[0]){

        // santa and the robot take turns 
        if (santa){
            i=0;
            santa = false;
        }
        else {
            i=1;
            santa = true;
        }


        switch (dir){
            case '^':
                y[i]++;
                pos = std::to_string(x[i]*1000 + y[i]);
                grid[pos]++;
                break;
            case 'v':
                y[i]--;
                pos = std::to_string(x[i]*1000 + y[i]);
                grid[pos]++;
                break;
            case '>':
                x[i]++;
                pos = std::to_string(x[i]*1000 + y[i]);
                grid[pos]++;
                break;
            case '<':
                x[i]--;
                pos = std::to_string(x[i]*1000 + y[i]);
                grid[pos]++;
                break;
        }
    }

    // number of houses with at least 1 present
    std::cout  << "Answer (part 2): " << grid.size() << std::endl;

    return 0;
}