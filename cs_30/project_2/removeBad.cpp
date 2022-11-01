#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
// // doesn't work for linked list 
// template<typename T>
// void removeOdds(T& li){
//     for (auto current = li.begin(); current != li.end();){
//         if (*current % 2){
//             li.erase(current);
//         }
//         else{
//             current++;
//         }
//     }
// }

void removeOdds(list<int>& li){
    for (auto current = li.begin(); current != li.end(); current++){
        if (*current % 2){
            li.erase(current++);
        }
    }
}

void removeOdds(vector<int>& v){
    for (auto current = v.begin(); current != v.end();){
        if (*current % 2){
            v.erase(current);
        }
        else{
            current++;
        }
    }
}

// void test(){
//     int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
//     list<int> x(a, a+8); // construct x from the array
//     assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
//     removeOdds(x);
//     assert(x.size() == 4);
//     vector<int> v(x.begin(), x.end()); // construct v from x
//     sort(v.begin(), v.end());
//     int expect[4] = { 2, 4, 6, 8 };
//     for (int k = 0; k < 4; k++){
//     assert(v[k] == expect[k]);}
// }

// int main(){
//     test();
//     cout << "Passed" << endl;
//     return 0;
// }

// void test(){
//     int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
//     vector<int> x(a, a+8); // construct x from the array
//     assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
//     removeOdds(x);
//     assert(x.size() == 4);
//     sort(x.begin(), x.end());
//     int expect[4] = { 2, 4, 6, 8 };
//     for (int k = 0; k < 4; k++)
//     assert(x[k] == expect[k]);
// }

// int main(){
//     test();
//     cout << "Passed" << endl;
// }

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
    for (auto current = li.begin(); current != li.end(); current++){
            if ((*current)->rating() < 50){
                li.erase(current++);
            }
    }
}

void test()
{
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
int main()
{
 test();
 cout << "Passed" << endl;
}