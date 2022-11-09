#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <csignal>
using namespace std;

const int MAXRESULTS = 20;   // Max matches that can be found
const int MAXDICTWORDS = 10; // Max words that can be read in

int loadDictionary(istream &dictfile, vector<string> &dict)
{
    // Places each string in dictfile into the vector dict
    // return num words
    dict.clear(); // this line is not needed if vecs not filled
    string word;
    while (getline(dictfile, word))
    {
        if (dict.size() <= MAXDICTWORDS){
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
    results.clear(); // this line is not needed if vecs not filled
    set<string> perms;
    gen_perms(word, 0, word.size() - 1, perms);
    for (auto dict_it = dict.begin(); dict_it != dict.end(); dict_it++)
    {
        for (auto set_it = perms.begin(); set_it != perms.end(); set_it++)
        {
            if (*dict_it == *set_it)
            {
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

void testtwo(int n)
{
    vector<string> dictionary(MAXDICTWORDS);
    vector<string> results(MAXRESULTS);

    switch (n)
    {
    default:
    {
        cout << "Bad argument" << endl;
    }
    break;
    case 1:
    {
        istringstream
            iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\n");
        int numResults = loadDictionary(iss, dictionary);
        sort(dictionary.begin(), dictionary.end());
        assert(numResults == 9 && dictionary[0] == "act" &&
               dictionary[1] == "art" && dictionary[numResults - 1] == "tar");
    }
    break;
    case 2:
    {
        // File is empty, Checks that file is empty and loadDictionary returns 0.
        istringstream iss("");
        int numResults = loadDictionary(iss, dictionary);
        assert(numResults == 0);
    }
    break;
    case 3:
    {
        // Input file is larger than the dictionary size
        istringstream
            iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\ntoo\nmany\nwords\n");
        int numResults = loadDictionary(iss, dictionary);
        sort(dictionary.begin(), dictionary.end());
        assert(numResults == 10 && dictionary[MAXDICTWORDS - 1] == "too");
    }
    break;
    case 4:
    {
        // If a certain word with repeated letter is shown in results more than once - still accept.
        vector<string> dictionary{"one", "oone", "ne",
                                  "e", "too"};
        int numResults = permute("oto", dictionary,
                                 results);
        assert(numResults == 1 && results[0] == "too");
    }
    break;
    case 5:
    {
        // No fraction of a permutation is being searched in dictionary
        vector<string>
            dictionary{"one", "oone", "ne",
                       "e", "neoo", "oneo"};
        int numResults = permute("neo", dictionary,
                                 results);
        assert(numResults == 1 && results[0] == "one");
    }
    break;
    case 6:
    {
        // Checking that no error occurs if more than MAXRESULTS are found.
        vector<string> dictionary{"true", "treu", "teru",
                                  "teur", "ture", "tuer", "rtue", "rteu", "retu", "reut", "ruet",
                                  "rute", "utre", "uter", "uetr", "uert", "urte", "uret", "etru",
                                  "etur", "ertu", "erut", "eurt", "eutr"};
        // All 24 permutations
        int numResults = permute("true", dictionary,
                                 results);
        assert(numResults == MAXRESULTS);
    }
    break;
    case 7:
    {
        // Checking one word was found, no duplicates.
        vector<string> dictionary{"ppp"};
        int numResults = permute("ppp", dictionary,
                                 results);
        assert(numResults == 1 && results[0] == "ppp");
    }
    break;
    case 8:
    {
        streambuf *oldCoutStreamBuf = cout.rdbuf();
        ostringstream strCout;
        cout.rdbuf(strCout.rdbuf());
        vector<string> results{"cat", "act"};
        display(results);
        cout.rdbuf(oldCoutStreamBuf);
        string temp = strCout.str();
        bool match1 = temp.find("act") != string::npos;
        bool match2 = temp.find("cat") != string::npos;
        assert(match1 && match2);
    }
    break;
    case 9:
    {
        istringstream iss("tier\nrite\nbate\ntire\nttir");
        int numWords = loadDictionary(iss, dictionary);
        sort(dictionary.begin(), dictionary.end());
        assert(numWords == 5 && dictionary[0] == "bate");
        int numResults = permute("tier", dictionary,
                                 results);
        assert(numResults == 3 && (results[2] == "tire" ||
                                   results[2] == "tier" || results[2] == "rite"));
    }
    break;
    case 10:
    {
        vector<string> example{"kool", "moe", "dee"};
        int numResults = permute("look", example, results);
        assert(numResults == 1 && results[0] == "kool");
    }
    break;
    }
}

int main()
    {
    // expect to fail: 1,2,3,6,9 because I'm not checking for limit
    // i think vecs should be empty but there is maxsize
    // code to check maxsize: // this should replace push_back code on lines 24, 60
    // if (vec.size() < MAXSIZE){
    //     vec.push_back(item);
    // }
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testtwo(n);
    cout << "Passed" << endl;
    return 0;
}