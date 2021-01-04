#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declaration
long next_code( long previous );

int main(){

    const int col = 3083;
    const int row = 2978;

    // grid width and total size of triangle
    const int n  = col+row;
    int total = 0;
    for (int i=0; i<n; i++){
        total += n-i;
    }


    // create square grid width=col+row to contain values
    std::vector<std::vector<long>> grid(n, std::vector<long>(n,0L));

    // initial value
    long current = 20151125L;
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
        current = next_code(current);
        grid[y][x] = current;
    }

    std::cout << "Answer (part 1): " << grid[row-1][col-1] << std::endl;

    return 0;
}

// generate next code
long next_code( long previous ){
    return (previous*252533L) % 33554393L;
}