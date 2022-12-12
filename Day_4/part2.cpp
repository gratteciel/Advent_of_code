//
// Created by mitue on 09/12/2022.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool isContained(string v1,string v2);

int main (){
    std::ifstream fileData(
            R"(C:\Users\mitue\OneDrive\Documents\ECE\advent_of_code\Day_4\data.txt)");
    string output;
    int score = 0;



    if (!fileData) {
        std::cout << "issue for opening the file" << std::endl;
    }
    while (std::getline(fileData, output)) {
        size_t pos = output.find(',');

        string v1 = output.substr(0,pos);
        string v2 = output.substr(pos+1);
        if(isContained(v1,v2)){
            //incrementing score
            score += 1;

        }
        cout << score << endl;

    }
    cout << "Final result = " << score << endl;

    return  0;
}

//returns true if a pair is contained in the other one
bool isContained(string v1,string v2){
    try{
        size_t pos = v1.find('-');
        size_t pos1 = v2.find('-');
        int n1 = stoi(v1.substr(0,pos));
        int n2 = stoi(v1.substr(pos+1));
        int n3 = stoi(v2.substr(0,pos1));
        int n4 = stoi(v2.substr(pos1+1));
        cout << n1 << "/" << n2 << "/" << n3 << "/" << n4 << endl;
        if ((n1 >=n3 && n1<= n4) || (n2 >= n3 && n2 <= n4) || (n3 >= n1 && n3 <= n2) || (n4 >= n1 && n4 <= n2) ){
            return true;
        }
        else return false;
    }
    catch (const exception & e){
        cout << e.what() <<endl;
    }




}