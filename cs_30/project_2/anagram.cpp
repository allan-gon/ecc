#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

int loadDictionary(istream &dictfile, vector<string>& dict){
    // Places each string in dictfile into the vector dict
    // return num words
    string word;
    while (!dictfile.eof()){
        getline(dictfile, word);
        dict.push_back(word);
    }
    return dict.size();
}

void gen_perms(string &a, int l, int r, set<string>& x){
    // helper saves all permutations of words in set
    if (l == r){
        x.insert(a);
    } else{
        for (int i = l; i <= r; i++){
            swap(a[l], a[i]);
            gen_perms(a, l+1, r, x);
            swap(a[l], a[i]);
        }
    }
}

int permute(string word, vector<string>& dict, vector<string>& results){
    // saves all perms of a word (in the dict) into results
    set<string> perms;
    gen_perms(word, 0, word.size() - 1, perms);
    for (auto dict_it = dict.begin(); dict_it != dict.end(); dict_it++){
        for (auto set_it = perms.begin(); set_it != perms.end(); set_it++){
            if (*dict_it == *set_it){
                results.push_back(*dict_it);
            }
        }
    }
    return results.size();
}

void display(vector<string>& results){
    if (results.size() == 0){
        cout << "No matches found\n";
    }
    else{
        for (auto wrd: results){
            cout << "Matching word " << wrd << endl;
        }
    }

}

int main(){
    ifstream dictfile("./words.txt");
    vector<string> words;
    vector<string> results;
    string word;

    int num_words = loadDictionary(dictfile, words);
    // tests load dict
    // assert((num_words == 25144) && (words.size() == num_words));
    
    cout << "Please enter a string for an anagram: ";
    cin >> word;
    // tests permute
    permute(word, words, results);
    display(results);

    // cout << "All tests Passed!\n";
    return 0;
}
