#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

void turn_on(std::vector<std::vector<bool>> &grid, int x1, int y1, int x2, int y2);
void turn_off(std::vector<std::vector<bool>> &grid, int x1, int y1, int x2, int y2);
void toggle(std::vector<std::vector<bool>> &grid, int x1, int y1, int x2, int y2);
void turn_on_2(std::vector<std::vector<int>> &grid, int x1, int y1, int x2, int y2);
void turn_off_2(std::vector<std::vector<int>> &grid, int x1, int y1, int x2, int y2);
void toggle_2(std::vector<std::vector<int>> &grid, int x1, int y1, int x2, int y2);
void part_1(std::vector<std::vector<std::string>> &input);
void part_2(std::vector<std::vector<std::string>> &input);

int main(){

    // read input into vector of strings.
    std::vector<std::vector<std::string>> input = read_input_2D("input_06", {" ", ",", "turn", "through"});

    part_1(input);
    part_2(input);  

    return 0;
}

void part_1(std::vector<std::vector<std::string>> &input){

    // create grid of lights (boolean)
    std::vector<std::vector<bool>> grid(1000, std::vector<bool>(1000, false));

    // work through input
    for (unsigned int i=0; i<input.size(); i++){

        std::string operation = input[i][0];
        int x1 = std::stoi(input[i][1]);
        int y1 = std::stoi(input[i][2]);
        int x2 = std::stoi(input[i][3]);
        int y2 = std::stoi(input[i][4]);

        if      (operation == "on"    ){ turn_on(grid,x1,y1,x2,y2);  }
        else if (operation == "off"   ){ turn_off(grid,x1,y1,x2,y2); }
        else if (operation == "toggle"){ toggle(grid,x1,y1,x2,y2);   }
    }

    // count lit lights
    int count = 0;

    for (size_t i=0; i<grid.size(); i++){
        for (size_t j=0; j<grid[i].size(); j++){
            if (grid[i][j]){ count++; }
        }
    }

    std::cout << "Answer (part 1): " << count << std::endl;
}

void part_2(std::vector<std::vector<std::string>> &input){

    // create grid of lights (boolean)
    std::vector<std::vector<int>> grid(1000, std::vector<int>(1000, 0));

    // work through input
    for (unsigned int i=0; i<input.size(); i++){

        std::string operation = input[i][0];
        int x1 = std::stoi(input[i][1]);
        int y1 = std::stoi(input[i][2]);
        int x2 = std::stoi(input[i][3]);
        int y2 = std::stoi(input[i][4]);

        if      (operation == "on"    ){ turn_on_2(grid,x1,y1,x2,y2);  }
        else if (operation == "off"   ){ turn_off_2(grid,x1,y1,x2,y2); }
        else if (operation == "toggle"){ toggle_2(grid,x1,y1,x2,y2);   }
    }

    // count lit lights
    int count = 0;

    for (size_t i=0; i<grid.size(); i++){
        for (size_t j=0; j<grid[i].size(); j++){
            count += grid[i][j];
        }
    }

    std::cout << "Answer (part 2): " << count << std::endl;
}

// set bool grid region to true
void turn_on(std::vector<std::vector<bool>> &grid, int x1, int y1, int x2, int y2){

    for (int x=x1; x<=x2; x++){
        for (int y=y1; y<=y2; y++){
            grid[x][y] = true;
        }
    }
}

// set bool grid region to false
void turn_off(std::vector<std::vector<bool>> &grid, int x1, int y1, int x2, int y2){

    for (int x=x1; x<=x2; x++){
        for (int y=y1; y<=y2; y++){
            grid[x][y] = false;
        }
    }
}

// toggle bool grid region
void toggle(std::vector<std::vector<bool>> &grid, int x1, int y1, int x2, int y2){

    for (int x=x1; x<=x2; x++){
        for (int y=y1; y<=y2; y++){
            grid[x][y] = !grid[x][y];
        }
    }
}

void turn_on_2(std::vector<std::vector<int>> &grid, int x1, int y1, int x2, int y2){

    for (int x=x1; x<=x2; x++){
        for (int y=y1; y<=y2; y++){
            grid[x][y]++;
        }
    }
}

void turn_off_2(std::vector<std::vector<int>> &grid, int x1, int y1, int x2, int y2){

    for (int x=x1; x<=x2; x++){
        for (int y=y1; y<=y2; y++){
            if (grid[x][y] != 0){ grid[x][y]--; }
        }
    }
}

void toggle_2(std::vector<std::vector<int>> &grid, int x1, int y1, int x2, int y2){

    for (int x=x1; x<=x2; x++){
        for (int y=y1; y<=y2; y++){
            grid[x][y] += 2;
        }
    }
}