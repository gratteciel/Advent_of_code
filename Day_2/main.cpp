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
 *
 * Points :
 * X/R : 1
 * B/Y : 2
 * C/Z : 3*/


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

void resMatch(const std::vector<char>& match, int *opponent, int *user);
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
    while(!::feof(fileData)){// 2 characters per line
            output = getc(fileData);
            if(output !='\n')
            {
                match.push_back(output);
            }

    }
    int i = 0;

    for (int x = 0; x < match.size()/2 ; ++x) {
        cout << match[i+x+2] << endl;

        if ('X' == match[x+i+2] && match[x+i] == 'A' ) {
            user += 1+3;
            opponent += 1+3;
        }
        if ('Y' == match[x+i+2] && match[x+i] == 'B' ) {
            user += 2+3;
            opponent += 2+3;
        }
        if ('Z' == match[x+i+2] && match[x+i] == 'C' ) {
            user += 3+3;
            opponent += 3+3;
        }
        if (match[x+i] == 'A' && match[x+i+2] == 'Y') {
            user += 2 +6;
        }
        if (match[x+i] == 'C' && match[x+i+ 2] == 'Y') {
            opponent += 3+6;
        }
        if (match[x+i] == 'A' && match[x+i + 2] == 'Z') {
            opponent += 1+6;
        }
        if (match[x+i] == 'B' && match[x+i+ 2] == 'Z') {
            user += 3+6;
        }
        if (match[x+i] == 'B' && match[x+i + 2] == 'X') {
            opponent += 2+6;
        }
        if (match[x+i] == 'C' && match[x+i + 2] == 'X') {
            opponent += 3+6;
        }
        i +=2;

    }
    cout << user << endl;
    cout << opponent << endl << endl;
    return 0;
}



void resMatch(const std::vector<char>& match, int *opponent, int *user){
//Create a map with each value
//pair for each type ?
//value of map second : 1: opponent wins , -1 : user wins, 0 :draw
   //create a map with result in fonction of the letter
/*   std::map<std::pair<char,char>,int> map = {
           {make_pair('x+i','R'),1},
           {make_pair('B','Y'),2},
           {make_pair('C','Z'),3}
   };
    std::map<std::pair<char,char>,int>::iterator it;
    int x+i = 0;
    int y = 0;
    std::vector<std::pair<char,char>> temp;

    it = map.find(map[pair)*/





}