#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

// forward function declarations
void computer(unsigned int &a, unsigned int &b , std::vector<std::vector<std::string>> &input);

int main(){

    // read input into vector of vector of strings.
    std::vector<std::string> delimiter = {" ", ",", "+"};
    std::vector<std::vector<std::string>> input = read_input_2D("input_23", delimiter);

    unsigned int a1 = 0, a2 = 1;
    unsigned int b1 = 0, b2 = 0;

    computer(a1,b1,input);
    computer(a2,b2,input);

    std::cout << "Answer (part 1): " << b1 << std::endl;
    std::cout << "Answer (part 2): " << b2 << std::endl;

    return 0;
}

void computer(unsigned int &a, unsigned int &b , std::vector<std::vector<std::string>> &input){

    size_t size = input.size();
    for (size_t i=0; i<size; i++){

        std::string &instr = input[i][0];
        std::string &reg   = input[i][1];

        if (instr == "hlf"){
            if (reg == "a"){ a /= 2; }
            else {b /= 2; }
        }
        else if ( instr == "tpl"){
            if (reg == "a"){ a *= 3; }
            else {b *= 3; }
        }
        else if ( instr == "inc"){
            if (reg == "a"){ a++; }
            else { b++; }
        }
        else if ( instr == "jmp"){ i += std::stoi(reg) - 1; }
        else if ( instr == "jie"){
            if ((reg=="a" && a%2==0) || (reg!= "a" && b%2==0)){ i += std::stoi(input[i][2]) - 1; }
        }
        else if ( instr == "jio"){
            if ((reg=="a" && a==1) || (reg!="a" && b==1)){ i += std::stoi(input[i][2]) - 1; }
        }
    }
}
