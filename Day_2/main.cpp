/* For Resume
 * For opponent :
 * A : Rock
 * B: Paper
 * C : Scissors
 *
 * For the user:
 * X: Rock
 * Y : Paper
 * Z : Scissors
 * wins = +6
 *
 * Points :
 * X/R : 1
 * B/Y : 2
 * C/Z : 3*/


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    //score for opponent
    int opponent = 0;
    //score for the user
    int user = 0;

    //for each match
    std::vector<char> match;

    //opening the file
    string filenamePath(R"(C:\Users\mitue\OneDrive\Documents\Perso\adventofCode\advent_of_code_project\Day_2\data.txt)");
    FILE *fileData = ::fopen(filenamePath.c_str(),"r");
    char output;

    if(!fileData){
        std::cout << "issue for opening the file" << std::endl;
    }
    //insert data into a vector from the file
    while(!::feof(fileData)){// 2 characters per line
            output = getc(fileData);
            if(output !='\n')
            {
                match.push_back(output);
            }

    }
    int i = 0;

    //can do it in a different function
    //calculate the score
    for (int x = 0; x+i+1 < match.size() ; ++x) {
        switch (match[x+i]) {
            case 'A': //rock
                switch (match[x+i+2]) {
                    case 'X':
                        user += 3;
                        break;
                    case 'Y':
                        user += 1+3;
                        break;
                    case 'Z':
                        user += 2+6;
                        break;

                }
                break;
            case 'B': //paper
                switch (match[x+i+2]) {
                    case 'X':
                        user += 1;
                        break;
                    case 'Y':
                        user += 2+3;
                        break;
                    case 'Z':
                        user += 3+6;
                        break;

                }
                break;
            case 'C': //scissors
                switch (match[x+i+2]) {
                    case 'X':
                        user += 2;
                        break;
                    case 'Y':
                        user += 3+3;
                        break;
                    case 'Z':
                        user += 1+6;
                        break;

                }
                break;
        }

        i +=2;

        cout << "Score for you: ";
        cout << user << endl;
    }
    cout << "Final score for you: ";
    cout << user << endl;

    return 0;
}

