
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {


    //for each match
    std::vector<string> match;
    std::map<string, string> mapRes;// map for both part we"ll split the vector

    ///Map for alphabet
    map<string, int> alphabet;


    // Insert the lowercase letters into the map
    alphabet.insert({"a", 1});
    alphabet.insert({"b", 2});
    alphabet.insert({"c", 3});
    alphabet.insert({"d", 4});
    alphabet.insert({"e", 5});
    alphabet.insert({"f", 6});
    alphabet.insert({"g", 7});
    alphabet.insert({"h", 8});
    alphabet.insert({"i", 9});
    alphabet.insert({"j", 10});
    alphabet.insert({"k", 11});
    alphabet.insert({"l", 12});
    alphabet.insert({"m", 13});
    alphabet.insert({"n", 14});
    alphabet.insert({"o", 15});
    alphabet.insert({"p", 16});
    alphabet.insert({"q", 17});
    alphabet.insert({"r", 18});
    alphabet.insert({"s", 19});
    alphabet.insert({"t", 20});
    alphabet.insert({"u", 21});
    alphabet.insert({"v", 22});
    alphabet.insert({"w", 23});
    alphabet.insert({"x", 24});
    alphabet.insert({"y", 25});
    alphabet.insert({"z", 26});
    // Insert the uppercase letters into the map
    alphabet.insert({"A", 27});
    alphabet.insert({"B", 28});
    alphabet.insert({"C", 29});
    alphabet.insert({"D", 30});
    alphabet.insert({"E", 31});
    alphabet.insert({"F", 32});
    alphabet.insert({"G", 33});
    alphabet.insert({"H", 34});
    alphabet.insert({"I", 35});
    alphabet.insert({"J", 36});
    alphabet.insert({"K", 37});
    alphabet.insert({"L", 38});
    alphabet.insert({"M", 39});
    alphabet.insert({"N", 40});
    alphabet.insert({"O", 41});
    alphabet.insert({"P", 42});
    alphabet.insert({"Q", 43});
    alphabet.insert({"R", 44});
    alphabet.insert({"S", 45});
    alphabet.insert({"T", 46});
    alphabet.insert({"U", 47});
    alphabet.insert({"V", 48});
    alphabet.insert({"W", 49});
    alphabet.insert({"X", 50});
    alphabet.insert({"Y", 51});
    alphabet.insert({"Z", 52});

    //opening the file
    std::ifstream fileData(
            R"(C:\Users\mitue\OneDrive\Documents\ECE\advent_of_code\Day_3\data.txt)");
    string output;

    if (!fileData) {
        std::cout << "issue for opening the file" << std::endl;
    }
    int line = 0;
    std::vector<std::vector<string>> output3Line;
    //insert data into a vector from the file
    while (std::getline(fileData, output)) {

        match.push_back(output);
    }
    std::map<string, int> letterValue;
    int result = 0;
    int j =0;

    for (std::vector<string>::iterator it = match.begin(); it < match.end();) {
        //cout  << "hello";

            string value ="";
            set<char> set1(it->begin(), it->end());
            set<char> set2((it+1)->begin(), (it+1)->end());
            set<char> set3((it+2)->begin(), (it+2)->end());

            string commonChar ="";
            std::set_intersection(set1.begin(), set1.end(),
                                  set2.begin(), set2.end(),
                                  back_inserter(commonChar));

            std::set_intersection(commonChar.begin(), commonChar.end(),
                                  set3.begin(), set3.end(),
                                  back_inserter(value));

            commonChar ="";

            it = std::next(it,3);


            letterValue[value] = alphabet.at(value);
            result += alphabet.at(value);



    }
    //compare to find the character in common between 2 string at we put in a map


    //find the character
    /*for (auto it = mapRes.begin(); it != mapRes.end(); it++) {

        set<char> set1(it->first.begin(), it->first.end());
        set<char> set2(it->second.begin(), it->second.end());
        string common_chars;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(common_chars));


        cout << it->first << "/" << it->second << " :";
        cout << common_chars << " result atm : " << result << endl;
    }*/

    cout << "Result:" << result << endl;

    return 0;
}