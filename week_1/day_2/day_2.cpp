#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../utils/utils.h"

int main(){

    // read input into vec of vec of ints.
    std::vector<std::vector<int>> input = input_to_int_2D(read_input_2D("input", "x"));

    std::vector<int> area(3);
    int total_area = 0;
    int ribbon_area = 0;

    for ( std::vector<int> & dim : input){

        std::sort(dim.begin(), dim.end());

        // work out areas for wrapping paper
        area[0] = 2 * dim[0] * dim[1];
        area[1] = 2 * dim[0] * dim[2];
        area[2] = 2 * dim[1] * dim[2];

        total_area += area[0] + area[1] + area[2] + area[0]/2;

        ribbon_area += 2*dim[0] + 2*dim[1] + dim[0]*dim[1]*dim[2];
    }

    std::cout << "Answer (part 1): " << total_area  << std::endl;
    std::cout << "Answer (part 2): " << ribbon_area << std::endl;

    return 0;
}
