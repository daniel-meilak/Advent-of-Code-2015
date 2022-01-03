#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include"../../Utils/utils.h"

struct reindeer{
    std::string name;
    int speed;
    int fly_max;
    int rest_max;
    int fly_time = 0;
    int rest_time = 0;
    int pos = 0;
    int points = 0;
    bool flying = true;
};

// forward function declarations
void give_points(std::vector<reindeer> &reindeers);
int furthest_reindeer(const std::vector<reindeer> &reindeers);
int most_points(const std::vector<reindeer> &reindeers);

int main(){

    // read input into vector of vector of strings.
    std::vector<std::string> delimiters = {"can fly", " ", "km/s", "for", ", but then must rest for", ".", "seconds"};
    std::vector<std::vector<std::string>> input = read_input_2D("input_14", delimiters);

    // vector of reindeers
    std::vector<reindeer> reindeers;

    // build vector of reindeers
    for (std::vector<std::string> line : input){

        reindeer temp;
    
        temp.name      = line[0];
        temp.speed     = std::stoi(line[1]);
        temp.fly_max  = std::stoi(line[2]);
        temp.rest_max = std::stoi(line[3]);

        // add temp to reindeers
        reindeers.push_back(temp);
    }

    int race_time = 2503;

    // start the race
    for (int s=1; s<=race_time; s++){

        // move each reindeer
        for (reindeer &r : reindeers){

            // if reindeer is currently flying
            if (r.flying){
                // if reindeer reaches max flying time, rest
                if (r.fly_time == r.fly_max){
                    r.fly_time = 0;
                    r.flying = false;
                    r.rest_time++;
                }
                else {
                    r.pos += r.speed;
                    r.fly_time++;
                }
            }
            // else if reindeer is currently resting
            else {
                // if reindeer reaches max rest time, fly
                if (r.rest_time == r.rest_max){
                    r.rest_time = 0;
                    r.flying = true;
                    r.pos += r.speed;
                    r.fly_time++;
                }
                else {
                    r.rest_time++;
                }
            }
        }

        // give points according to which reindeers are furthest
        give_points(reindeers);
    }

    // furthest distance and most points
    int furthest = furthest_reindeer(reindeers);
    int points   = most_points(reindeers);

    std::cout << "Answer (part 1): " << furthest << std::endl;
    std::cout << "Answer (part 2): " << points   << std::endl;
    

    return 0;
}

// give points according to which reindeers are furthest
void give_points(std::vector<reindeer> &reindeers){

    int furthest = furthest_reindeer(reindeers);

    // give furthest reindeers points
    for (reindeer &r : reindeers){
        if (r.pos == furthest){ r.points++; }
    }
}

// finds furthest reindeer
int furthest_reindeer(const std::vector<reindeer> &reindeers){

    int furthest = 0;

    for (reindeer r : reindeers){
        if (r.pos > furthest){ furthest = r.pos; }
    }

    return furthest;
}

// finds the reindeer with the most points
int most_points(const std::vector<reindeer> &reindeers){

    int points = 0;

    for (reindeer r : reindeers){
        if (r.points > points){points = r.points; }
    }

    return points;
}
