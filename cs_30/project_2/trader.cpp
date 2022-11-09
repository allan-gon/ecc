#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <csignal>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

// struct Trade{
//     int day, amount;
//     bool bought;
//     Trade(int m_day, int m_amount, bool m_buy): 
//         day{m_day}, amount{m_amount}, bought{m_buy}{}
// };

// vector<string> findPotentialBadTraders(vector<string> v){
//     // get day price combo
//     // get person trade combo
//     // name: [Trades]
//     string name, bought;
//     int day, price;
//     map<string, vector<Trade>> dict;
//     vector<pair<int, int>> days;
//     for (string row: v){
//         if (count(row.begin(), row.end(), '|') == 1){ // found a date trade
//             // int delim = row.find('|');
//             // int day = stoi(row.substr(0, delim));
//             // int price = stoi(row.substr(delim + 1, row.size() - delim));
//             getline(row, day, '|');
//         }
//             days.push_back(pair(day, price));
//         // } else{
//         //     getline(row, day, "|");
//         //     // int delim = row.find("|");


//         // }
//     }
//     return v; // This compiles, but is not correct
// }

int main(){
    ifstream in("input.txt");
    string str;
    if (!in){
        cerr << "No input file" << endl;
        exit(0);
    }
    vector<string> inputVec;
    
    
    
    // while (getline(in, str)) {
    // inputVec.push_back(str);
    // }
    // vector<string> resV = findPotentialBadTraders(inputVec);
    // for (const string& r : resV) {
    // cout << r << endl;;
    // }
    return 0;
}

// void testthree()
// {
//     istringstream in("0|20\n0|Kristi|SELL|300\n0|Will|BUY|500\n0|Tom|BUY|5000\n0|Shilpa|BUY|150\n1|Tom|BUY|150000\n3|25\n5|Shilpa|SELL|150\n8|Kristi|SELL|60000\n9|Shilpa|BUY|50\n10|15\n11|5\n14|Will|BUY|10000\n15|Will|BUY|10000\n16|Will|BUY|10000\n17|25"); 
//     string str; 
//     vector<string> inputVec; 
//     while (getline(in, str)) {
//         inputVec.push_back(str); 
//     }
//     vector<string> resV = findPotentialBadTraders(inputVec); 
//     assert(resV.size() == 2 && resV[0] == "1|Tom" && resV[1] == "8|Kristi");
// }

// int main()
// {
//     // cout << "Enter test number: ";
//     // int n;
//     // cin >> n;
//     testthree(); // this passed in n shits fucked i think
//     cout << "Passed" << endl;
// }

// TODO: I want to get from stream to see if shits bussin
// if bussin use stream delim to correctly parse