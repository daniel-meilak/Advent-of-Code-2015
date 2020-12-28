#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"md5.h"

int main(){

    std::string input = "bgvyzdsv";

    std::string output, hash;

    for (int i=0; i<100000000; i++){

        hash = input + std::to_string(i);

        output = MD5(hash).hexdigest();

        if ( output.substr(0,6) == "000000" ){
            break;
        }
    }

    std::cout << "Answer (part 2): " << hash << std::endl;

    return 0;
}
