#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    //code can be better just did the average the first time

    //variables
    std::ifstream fileData(R"(C:\Users\mitue\OneDrive\Documents\Perso\adventofCode\advent_of_code_project\Day_1\data.txt)");
    std::vector<string> values;
    string res;
    std::vector <int> total;
    int value = 0;
    string output;
    //test if the file is open
    if(!fileData){
        std::cout << "issue for opening the file" << std::endl;
    }
    else{
        while (std::getline(fileData, output)){ //while there is some data in the file
            if(!output.empty()){ //if line is blank
                value = stoi(output) + value;
            }
            else{
                int temp = value;
                total.push_back(temp);
                //assigned to 0 once again :
                value = 0;
            }
        }
    }

    //sorting for the highest value
    std::sort(total.begin(), total.end());
    int maxValue=0;
    //just want the add of the last 3 maxCalories
    for (int i = 3; i >0 ; i--) {
        maxValue += total[total.size()-i];
    }

    cout << "The max value is :";
    cout  << maxValue;
    //result part 2 : 205805
    fileData.close();
    return 0;
}
