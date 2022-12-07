/* For Resume
 * For opponent :
 * A : Rock
 * B: Paper
 * C : Scissors
 *
 * For the user:
 * X : Rock
 * Y : Paper
 * Z : Scissors
 *
 * Points :
 * X/R : 1
 * B/Y : 2
 * C/Z : 3*/


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int resMatch(const std::vector<char>& input, int *user, int *opponent);
int main() {
    //score for opponent
    int* opponent = nullptr;
    //score for the user
    int* user = nullptr;

    //for each match
    std::vector<char> match;

    //opening the file
    string filenamePath(R"(C:\Users\mitue\OneDrive\Documents\Perso\adventofCode\advent_of_code_project\Day_2\data.txt)");
    FILE *fileData = ::fopen(filenamePath.c_str(),"r");
    char output;

    if(!fileData){
        std::cout << "issue for opening the file" << std::endl;
    }
    while(!::feof(fileData)){
        for (int i = 0; i < 2; ++i) { // 2 characters per line
            output = getc(fileData);
            match.push_back(output);
            if(output == '\n'){ //We calculate who wins
                resMatch(match,user,opponent);

            }
        }
    }
    return 0;
}

int resMatch(const std::vector<char>& input, int *user, int *opponent){
//Create a map with each value
//pair for each type ?


    int result = 0;

    return result;
}