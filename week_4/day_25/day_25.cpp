#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"utils.h"

int main(){

    std::vector<std::string> delimiters = {"To continue, please consult the code grid in the manual.  Enter the code at row ",", column "};
    std::vector<int> input = input_to_int(read_input("input_25",delimiters));

    const int row = input[0];
    const int col = input[1];

    // grid width and total size of triangle
    const int n  = col+row;
    int total = 0;
    for (int i=0; i<n; i++){
        total += n-i;
    }


    // create square grid width=col+row to contain values
    std::vector<std::vector<long long>> grid(n, std::vector<long long>(n,0LL));

    // initial value
    long long current = 20151125LL;
    grid[0][0] = current;

    // variables for the pattern
    int max_count = 0;
    int count = 0;

    // grid coordinates
    int x = 0;
    int y = 0;

    // successive values follow a pattern of swapping grid coords
    // and inc/red the x,y values
    for (int i=1; i<total; i++){

        // reached end of diag, incr x and swap x,y
        if (count == 0){
            x++;
            std::swap(x,y);

            // next diag is 1 value longer
            max_count++;
            count = max_count;
        }
        // while going through diag, inc x and dec y
        else {
            x++;
            y--;
            count--;
        }

        // calculate the next value
        current = (current*252533LL)%33554393LL;
        grid[y][x] = current;
    }

    std::cout << "Answer (part 1): " << grid[row-1][col-1] << std::endl;

    return 0;
}