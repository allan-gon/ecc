#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

void removeOdds(list<int>& li){
    // remove odd ints from li
    for (auto it = li.begin(); it != li.end(); it++){
        if (*it % 2){
            li.erase(it++);
        }
    }
}

void test_li(){
    int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
    list<int> x(a, a+8); // construct x from the array
    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
    removeOdds(x);
    assert(x.size() == 4);
    vector<int> v(x.begin(), x.end()); // construct v from x
    sort(v.begin(), v.end());
    int expect[4] = { 2, 4, 6, 8 };
    for (int k = 0; k < 4; k++)
    assert(v[k] == expect[k]);
}

void removeOdds(vector<int>& v){
    for (auto it = v.begin(); it != v.end();){
        if (*it % 2){
            it = v.erase(it);
        }
        // only increment if not deleting since if you delete
        // the next element to check is the same index
        else{it++;}
    }
}

void test_vec(){
    int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
    vector<int> x(a, a+8); // construct x from the array
    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
    removeOdds(x);
    assert(x.size() == 4);
    sort(x.begin(), x.end());
    int expect[4] = { 2, 4, 6, 8 };
    for (int k = 0; k < 4; k++)
    assert(x[k] == expect[k]);
}

vector<int> destroyedOnes;
class Movie{
    public:
    Movie(int r) : m_rating(r) {}
    ~Movie() { destroyedOnes.push_back(m_rating); }
    int rating() const { return m_rating; }
    private:
    int m_rating;
};

void removeBad(list<Movie*>& li){
    // if rating is < 50 remove and destroy
    for(auto it = li.begin(); it != li.end(); it++){
        if ((*it)->rating() < 50){
            delete *it;
            li.erase(it++);
        }
    }
}

void test_rb_li(){
    int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 };
    list<Movie*> x;
    for (int k = 0; k < 8; k++)
    x.push_back(new Movie(a[k]));
    assert(x.size() == 8 && x.front()->rating() == 85 &&
    x.back()->rating() == 10);
    removeBad(x);
    assert(x.size() == 4 && destroyedOnes.size() == 4);
    vector<int> v;
    for (list<Movie*>::iterator p = x.begin(); p != x.end(); p++)
    {
    Movie* mp = *p;
    v.push_back(mp->rating());
    }
    sort(v.begin(), v.end());
    int expect[4] = { 70, 80, 85, 90 };
    for (int k = 0; k < 4; k++)
    assert(v[k] == expect[k]);
    sort(destroyedOnes.begin(), destroyedOnes.end());
    int expectGone[4] = { 10, 15, 20, 30 };
    for (int k = 0; k < 4; k++)
    assert(destroyedOnes[k] == expectGone[k]);
}

void removeBad(vector<Movie*>& v){
    for (auto it = v.begin(); it != v.end();){
        if ((*it)->rating() < 50){
            delete *it;
            it = v.erase(it);
        }
        // only increment if not deleting since if you delete
        // the next element to check is the same index
        else{it++;}
    }
}

void test_rb_vec() {
    int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 };
    vector<Movie*> x;
    for (int k = 0; k < 8; k++)
    x.push_back(new Movie(a[k]));
    assert(x.size() == 8 && x.front()->rating() == 85 &&
    x.back()->rating() == 10);
    removeBad(x);
    assert(x.size() == 4 && destroyedOnes.size() == 4);
    vector<int> v;
    for (int k = 0; k < 4; k++)
    v.push_back(x[k]->rating());
    sort(v.begin(), v.end());
    int expect[4] = { 70, 80, 85, 90 };
    for (int k = 0; k < 4; k++)
    assert(v[k] == expect[k]);
    sort(destroyedOnes.begin(), destroyedOnes.end());
    int expectGone[4] = { 10, 15, 20, 30 };
    for (int k = 0; k < 4; k++)
    assert(destroyedOnes[k] == expectGone[k]);
}

int main(){
    // remove odds for list type
    test_li();
    // remove odds for a vector
    test_vec();
    // remove bad list
    test_rb_li();
    destroyedOnes.clear();
    // remove bad vector
    test_rb_vec();
    destroyedOnes.clear();


    cout << "Passed" << endl;
    return 0;
}
