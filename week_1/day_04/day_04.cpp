#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"
#include"md5.h"

int main(){

    std::string input = read_line("input_04");

    std::string output, hash, part1, part2;
    std::string seq1 = "00000", seq2 = "000000";


    for (int i=0; i<INT_MAX; i++){

        hash = input + std::to_string(i);

        output = MD5(hash).hexdigest();

        if (part1.empty() && output.substr(0,5) == seq1){ part1 = hash; }
        if (output.substr(0,6) == seq2 ){ part2 = hash; }

        if (!part1.empty() && !part2.empty()){ break; }
    }

    std::cout << "Answer (part 1): " << part1 << std::endl;
    std::cout << "Answer (part 2): " << part2 << std::endl;

    return 0;
}
