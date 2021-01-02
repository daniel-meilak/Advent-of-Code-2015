#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

int main(){

    int N = 3600000;
    int N2 = 1000000;

    std::vector<int> house(N,0);

    for (int i=1; i<=N2; i++){
        for (int j=i; j<=N2; j+=i){
            house[j] += i*10;
        }
    }

    for ( unsigned int i=0; i<house.size(); i++ ){
        if (house[i] >= N*10){
            std::cout << "Answer: " << i << std::endl;
            break;
        }
    }

    return 0;
}