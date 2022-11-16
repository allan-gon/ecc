#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

const int MAXRESULTS = 20;   // Max matches that can be found
const int MAXDICTWORDS = 10; // Max words that can be read in

int loadDictionary(istream &dictfile, vector<string> &dict)
{
    // Places each string in dictfile into the vector dict
    // return num words
    string word;
    while (getline(dictfile, word))
    {
        if (dict.size() < MAXDICTWORDS){
            dict.push_back(word);
        } else {break;} // not necessary but more efficient?
    }
    return dict.size();
}

void gen_perms(string &a, int l, int r, set<string> &x)
{
    // helper saves all permutations of words in set
    if (l == r)
    {
        x.insert(a);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            gen_perms(a, l + 1, r, x);
            swap(a[l], a[i]);
        }
    }
}

int permute(string word, vector<string> &dict, vector<string> &results)
{
    // saves all perms of a word (in the dict) into results
    set<string> perms;
    gen_perms(word, 0, word.size() - 1, perms);
    for (auto dict_it = dict.begin(); dict_it != dict.end(); dict_it++)
    { // every word in dict
        for (auto set_it = perms.begin(); set_it != perms.end(); set_it++)
        { // every perm of word in question
            if ((results.size() < MAXRESULTS) && (*dict_it == *set_it))
            { // have space and this perm is a match
                results.push_back(*dict_it);
            }
        }
    }
    return results.size();
}

void display(vector<string> &results)
{
    for (auto wrd : results)
    {
        cout << "Matching word " << wrd << endl;
    }
}
