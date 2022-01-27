#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<iomanip>
#include"utils.h"
#include<openssl/md5.h>

std::string get_md5(const std::string& input){
    
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), result);

    std::ostringstream sout;
    sout << std::hex << std::setfill('0');
    for(long long c: result){ sout << std::setw(2) << (long long)c; }

    return sout.str();
}


int main(){

    std::string input = read_line("input_04");

    std::string output, hash, part1, part2;
    std::string seq1 = "00000", seq2 = "000000";


    for (int i=0; i<INT_MAX; i++){

        hash = input + std::to_string(i);

        output = get_md5(hash);

        if (part1.empty() && output.substr(0,5) == seq1){ part1 = hash; }
        if (output.substr(0,6) == seq2 ){ part2 = hash; }

        if (!part1.empty() && !part2.empty()){ break; }
    }

    std::cout << "Answer (part 1): " << part1 << std::endl;
    std::cout << "Answer (part 2): " << part2 << std::endl;

    return 0;
}
