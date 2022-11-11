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

int MAXAMOUNT = 500000;

bool compare(pair<string, int> &a, pair<string, int> &b){
    // if (a.second == b.second){
    //     return a.first < b.first;
    // } else{return a.second < b.second;}
    return a.second < b.second;
}

int get_price_day_of_trade(int day, map<int, int> ledger){
    int price;
    for (auto key: ledger){
        if (key.first > day){
            break;
        } price = key.second;
    }
    return price;
}

struct Trade{
    int day, amount;
    string name;
    bool bought;
    Trade(int m_day, string m_name, bool m_buy, int m_amount): 
        day{m_day}, name{m_name}, bought{m_buy}, amount{m_amount}{}
    

    bool is_sus(map<int, int> ledger){
        int self_price = get_price_day_of_trade(this->day, ledger);
        int latest_price = get_price_day_of_trade(this->day + 3, ledger);

        if (this->bought){
            if (((latest_price - self_price) * this->amount) >= MAXAMOUNT){return true;}
        } else if (((self_price - latest_price) * this->amount) >= MAXAMOUNT){return true;}
        return false;
    }
};

vector<string> findPotentialBadTraders(vector<string> v){
    string temp1, temp2, temp3, temp4;
    map<string, int> suspicious;
    vector<string> result;
    vector<Trade> trades;
    map<int, int> ledger;
    // parse data
    for (auto row: v){
        istringstream stream(row);
        if (count(row.begin(), row.end(), '|') == 1){
            getline(stream, temp1, '|');
            getline(stream, temp2);
            ledger.insert({stoi(temp1), stoi(temp2)});
        } else{
            getline(stream, temp1, '|');
            getline(stream, temp2, '|');
            getline(stream, temp3, '|');
            getline(stream, temp4);
            trades.push_back(Trade(stoi(temp1), temp2, temp3 == "BUY", stoi(temp4)));
        }
    }

    for (auto trade: trades){
        if (trade.is_sus(ledger)){
            if (suspicious.find(trade.name) == suspicious.end()){ // if not in map
                suspicious.insert({trade.name, trade.day});
            }
        }
    }
    // bro sort just doesn't work
    sort(suspicious.begin(), suspicious.end(), compare);

    for (auto pair: suspicious){
        result.push_back(to_string(pair.second) + "|" + pair.first);
    }
    return result;
}

// int main(){
//     ifstream in("input.txt");
//     string str;
//     if (!in){
//         cerr << "No input file" << endl;
//         exit(0);
//     }
//     vector<string> inputVec;
        
//     while (getline(in, str)) {
//     inputVec.push_back(str);
//     }
//     vector<string> resV = findPotentialBadTraders(inputVec);
//     for (const string& r : resV) {
//     cout << r << endl;;
//     }
//     return 0;
// }

void testthree()
{
    istringstream in("0|20\n0|Kristi|SELL|300\n0|Will|BUY|500\n0|Tom|BUY|5000\n0|Shilpa|BUY|150\n1|Tom|BUY|150000\n3|25\n5|Shilpa|SELL|150\n8|Kristi|SELL|60000\n9|Shilpa|BUY|50\n10|15\n11|5\n14|Will|BUY|10000\n15|Will|BUY|10000\n16|Will|BUY|10000\n17|25"); 
    string str; 
    vector<string> inputVec; 
    while (getline(in, str)) {
        inputVec.push_back(str); 
    }
    vector<string> resV = findPotentialBadTraders(inputVec); 
    assert(resV.size() == 2 && resV[0] == "1|Tom" && resV[1] == "8|Kristi");
}

int main()
{
    // cout << "Enter test number: ";
    // int n;
    // cin >> n;
    testthree(); // this passed in n shits fucked i think
    cout << "Passed" << endl;
}
