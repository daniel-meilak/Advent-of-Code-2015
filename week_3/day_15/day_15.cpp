#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"utils.h"

int main(){

    // read input into vector of strings.
    std::vector<std::string> delimiters = {":", " ", ",",  "capacity", "durability" ,"flavor", "texture", "calories", "Sugar", "Sprinkles", "Candy", "Chocolate"};
    std::vector<std::vector<int>> input = input_to_int_2D(read_input_2D("input_15", delimiters));

    // keep score
    int high_score = 0;
    int low_cal_score = 0;
    int tot_score = 0;
    std::vector<int> score = {0,0,0,0,0};

    // Brute force every combination
    for (int i=0; i<100; i++){
        for (int j=0; j<100-i; j++){
            for (int k=0; k<100-i-j; k++){
                int l = 100-i-j-k;

                score[0] = i*input[0][0] + j*input[1][0] + k*input[2][0] + l*input[3][0];
                score[1] = i*input[0][1] + j*input[1][1] + k*input[2][1] + l*input[3][1];
                score[2] = i*input[0][2] + j*input[1][2] + k*input[2][2] + l*input[3][2];
                score[3] = i*input[0][3] + j*input[1][3] + k*input[2][3] + l*input[3][3];
                score[4] = i*input[0][4] + j*input[1][4] + k*input[2][4] + l*input[3][4];

                // turn all negative scores to zero
                for ( int &s : score ){ if (s < 0){ s = 0; } }

                // find total score and check if highest score
                tot_score = score[0] * score[1] * score[2] * score[3];
                if (tot_score > high_score){ high_score = tot_score; }

                // find total score with 500cal and check if highest
                if ( (score[4] == 500) && (tot_score > low_cal_score)){ low_cal_score = tot_score; }
            }
        }
    }

    std::cout << "Answer (part 1): " << high_score    << std::endl;
    std::cout << "Answer (part 2): " << low_cal_score << std::endl;

    return 0;
}

