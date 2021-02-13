#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#include<bitset>
#include<unordered_map>
#include"../../Utils/utils.h"

// conveniet flags for switch case 
enum oper {
    op_and, op_and_v, op_or, op_not, op_lshift, op_rshift, op_assign, op_assign_v 
};

// structure of identity. Holds operation, values and sub-identities to
// calculate the value of identity
struct ident{
    std::bitset<16> value, signal;
    std::vector<std::string> link;
    oper op;
    bool calculated = false;
};

// forward function declarations
void create_link(std::unordered_map<std::string, ident> &links, std::vector<std::string> line);
std::bitset<16> eval(std::unordered_map<std::string, ident> &links, std::string wire);
int part_1(std::vector<std::vector<std::string>> &input);
void part_2(std::vector<std::vector<std::string>> &input, int b_input);

int main(){

    // read input into vector of strings.
    std::vector<std::string> delimiters = {" ", "->"};
    std::vector<std::vector<std::string>> input = read_input_2D("input", delimiters );

    int b_input;

    // part_1 returns value for part two
    b_input = part_1(input);
    part_2(input, b_input);
    
    return 0;
}

int part_1(std::vector<std::vector<std::string>> &input){

    std::unordered_map<std::string, ident> links;

    for ( std::vector<std::string> line : input ){
        create_link(links, line);
    }

    int answer = eval(links, "a").to_ulong();
    std::cout << "Answer (part 1): " << answer << std::endl;

    return answer;
}

void part_2(std::vector<std::vector<std::string>> &input, int b_input){

    std::unordered_map<std::string, ident> links;

    for ( std::vector<std::string> line : input ){
        create_link(links, line);
    }

    links["b"].value = b_input;

    int answer = eval(links, "a").to_ulong();
    std::cout << "Answer (part 2): " << answer << std::endl;
}

// creates map of idents, building their requirements to calculate value
void create_link(std::unordered_map<std::string, ident> &links, std::vector<std::string> line){

    // temporary ident to store properties of link
    ident temp;

    // work through logic gates
    if ( line[1] == "AND" ){
        // AND with value
        if ( std::isdigit(line[0][0]) ){
            temp.value = std::stoi(line[0]);
            temp.link.push_back(line[2]);
            temp.op = op_and_v;
            links[line[3]] = temp;
        } 
        // AND with two identifiers
        else {
            temp.link.push_back(line[0]);
            temp.link.push_back(line[2]);
            temp.op = op_and;
            links[line[3]] = temp;
        }
    }
    // or, two input links 
    else if ( line[1] == "OR" ){
        temp.link.push_back(line[0]);
        temp.link.push_back(line[2]);
        temp.op = op_or;
        links[line[3]] = temp;
    }
    // lshift, one input link and one value
    else if ( line[1] == "LSHIFT" ){
        temp.link.push_back(line[0]);
        temp.value = std::stoi(line[2]);
        temp.op = op_lshift;
        links[line[3]] = temp;
    }
    // rshift, one input link and one value
    else if ( line[1] == "RSHIFT" ){
        temp.link.push_back(line[0]);
        temp.value = std::stoi(line[2]);
        temp.op = op_rshift;
        links[line[3]] = temp;
    }
    // not, one input link
    else if ( line[0] == "NOT" ){
        temp.link.push_back(line[1]);
        temp.op = op_not;
        links[line[2]] = temp;
    }
    else {
        // assign value
        if ( std::isdigit(line[0][0]) ){
            temp.value = std::stoi(line[0]);
            temp.op = op_assign_v;
            links[line[1]] = temp;
        }
        // assign value from link
        else {
            temp.link.push_back(line[0]);
            temp.op = op_assign;
            links[line[1]] = temp;
        }
    }
}

// work through tree recursively and find value
std::bitset<16> eval(std::unordered_map<std::string, ident> &links, std::string wire){

    ident &temp = links[wire];

    // if the signal has already been calculated, use it
    if (temp.calculated){
        return temp.signal;
    }
    // otherwise calculate using tree
    else {
        std::bitset<16> r;

        // select correct operation using the ident.op flag
        switch (temp.op){
            case op_and:
                r = eval(links, temp.link[0]) & eval(links, temp.link[1]);
                break;
            case op_and_v:
                r = temp.value & eval(links, temp.link[0]);
                break;
            case op_or:
                r = eval(links, temp.link[0]) | eval(links, temp.link[1]);
                break;
            case op_lshift:
                r = eval(links, temp.link[0]) << temp.value.to_ulong();
                break;
            case op_rshift:
                r = eval(links, temp.link[0]) >> temp.value.to_ulong();
                break;
            case op_not:
                r = ~eval(links, temp.link[0]);
                break;
            case op_assign:
                r = eval(links, temp.link[0]);
                break;
            case op_assign_v:
                r = temp.value;
                break;
        }
        // when value is calculated, save it and return
        temp.calculated = true;
        temp.signal = r;
        return r;
    }
}

