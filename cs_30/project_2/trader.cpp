#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int MAXAMOUNT = 500000;

bool compare(const string &a, const string &b){
    string day_a, day_b, name_a, name_b;
    istringstream first(a), second(b);
    getline(first, day_a, '|');
    getline(first, name_a);
    getline(second, day_b, '|');
    getline(second, name_b);
    if (day_a == day_b){
        return name_a < name_b;
    } else {return day_a < day_b;}
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

    for (auto pair: suspicious){
        result.push_back(to_string(pair.second) + "|" + pair.first);
    }

    sort(result.begin(), result.end(), compare);
    return result;
}
