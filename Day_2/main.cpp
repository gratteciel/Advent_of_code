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
    string filenamePath(R"(C:\Users\mitue\OneDrive\Documents\ECE\advent_of_code\Day_2\data.txt)");
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
        switch (match[x+i+2]) {
            // X = lose => 1 ; Y= draw => 1 + 3; Z = win => 3+6
            case 'A': //rock
                user += 1;
                /*switch (match[x+i]) {
                    case 'A':
                        user += 3;
                        break;
                    case 'B':
                        user += 0;
                        break;
                    case 'C':
                        user += 6;
                        break;
                    default:
                        return 1;
                }*/
                break;
            case 'B': //paper
                user += 2+3;
                /*switch (match[x+i]) {
                    case 'A':
                        user += 6;
                        break;
                    case 'B':
                        user += 3;
                        break;
                    case 'C':
                        user += 0;
                        break;
                    default:
                        return 1;
                }*/
                break;
            case 'C': //scissors
                user += 3+6;
                /*switch (match[x+i]) {
                    case 'A':
                        user += 0;
                        break;
                    case 'B':
                        user += 6;
                        break;
                    case 'C':
                        user += 3;
                        break;
                    default:
                        return 1;
                }*/
                break;

        }
        i +=2;

    }
    cout << "Final score for you: ";
    cout << user << endl;

    return 0;
}

