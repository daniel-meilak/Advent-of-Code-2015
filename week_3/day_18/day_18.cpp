#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declarations
int check_neighbours(const std::vector<std::vector<bool>> &grid, unsigned int x, unsigned int y);
int count_lights(const std::vector<std::vector<bool>> &grid);
void corners_on(std::vector<std::vector<bool>> &grid);

int main(){

    // read input into vector of strings.
    std::vector<std::string> input = read_input("input", "");

    // gird of lights (booleans)
    std::vector<std::vector<bool>> grid(input.size()+2,std::vector<bool>(input.size()+2,false));


    // build initial grid
    int input_size = input.size();
    for (int i=0; i<input_size; i++){
        
        int line_size = input[i].size();
        for (int j=0; j<line_size; j++){

            // if input[i][j] is on (#), set grid to true
            grid[i+1][j+1] = (input[i][j] == '#');
        }
    }

    // for part two, turn on the corners
    corners_on(grid);

    // copy of grid
    std::vector<std::vector<bool>> grid_copy = grid;

    // perform steps
    int steps = 100;
    int grid_size = grid.size()-1;
    for (int i=0; i<steps; i++){

        for (int y=1; y<grid_size; y++){

            int line_size = grid[y].size()-1;
            for (int x=1; x<line_size; x++){

                // check neighbours
                int num_neighbours = check_neighbours(grid_copy,x,y);

                if ( grid_copy[y][x] ){
                    if (num_neighbours < 2 || num_neighbours > 3){ grid[y][x] = false; }
                }
                else {
                    if (num_neighbours == 3){ grid[y][x] = true; }
                }
            }
        }
        
        // keep corners on
        corners_on(grid);
        grid_copy = grid;
    }

    // count number of on lights
    int on = count_lights(grid);

    std::cout << "Answer: " << on << std::endl;

    return 0;
}

int check_neighbours(const std::vector<std::vector<bool>> &grid, unsigned int x, unsigned int y){

    int count = 0;

    if (grid[y  ][x+1]){ count++; }
    if (grid[y  ][x-1]){ count++; }
    if (grid[y+1][x  ]){ count++; }
    if (grid[y-1][x  ]){ count++; }
    if (grid[y+1][x+1]){ count++; }
    if (grid[y-1][x+1]){ count++; }
    if (grid[y+1][x-1]){ count++; }
    if (grid[y-1][x-1]){ count++; }

    return count;
}

int count_lights(const std::vector<std::vector<bool>> &grid){

    int count = 0;

    int grid_size = grid.size()-1;
    for (int y=1; y<grid_size; y++){

        int line_size = grid[y].size()-1;
        for (int x=1; x<line_size; x++){
            if (grid[y][x]){ count++; }
        }
    }

    return count;
}

void corners_on(std::vector<std::vector<bool>> &grid){

    int n = grid.size()-2;

    grid[1][1] = true;
    grid[n][1] = true;
    grid[1][n] = true;
    grid[n][n] = true;
}
