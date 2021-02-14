#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

int sum_factors1(int x);
int sum_factors2(int x);

int main(){

    // read input into vector of strings.
    int input = 36000000;

    int x1 = 700000;
    int x2 = 1;
    int sum1 = sum_factors1(x1);
    int sum2 = sum_factors2(x2);
    
    while ( sum1 < input ){
        x1++;
        sum1 = sum_factors1(x1);
    }

    while ( sum2 < input ){
        x2++;
        sum2 = sum_factors2(x2);
    }
    
    std::cout << "Answer (part 1): " << x1 << std::endl;
    std::cout << "Answer (part 2): " << x2 << std::endl;

    return 0;
}

int sum_factors1(int x){

    // store sum of factors
    int sum = 0;

    int i = 1;

    // loop from i to int(sqrt(x))
    while (i*i <= x){
        
        // check if i divides x
        if (x % i == 0){
            sum += i*10;

            // handle special cases
            if (x/i != i){ sum+= (x/i)*10; }
        }

        i++;
    }

    return sum;
}

int sum_factors2(int x){

    // store sum of factors
    int sum = 0;

    int i = 1;

    // loop from i to int(sqrt(x))
    while (i*i <= x){
        
        // check if i divides x
        if (x % i == 0){

            // check that it divides less than 50 times
            int x_i = x/i;
            if (x_i <= 50){
                sum += i*11;
            }

            // check that it divides less than 50 times
            if (x_i!=i && x/x_i<=50){ sum+= (x/i)*11; }
        }

        i++;
    }

    return sum;
}