#include <vector>
#include <list>
using namespace std;

void removeOdds(list<int> &li)
{
    // remove odd ints from li
    for (auto it = li.begin(); it != li.end(); it++)
    {
        if (*it % 2)
        {
            li.erase(it++);
        }
    }
}

void removeOdds(vector<int> &v)
{
    for (auto it = v.begin(); it != v.end();)
    {
        if (*it % 2)
        {
            it = v.erase(it);
        }
        // only increment if not deleting since if you delete
        // the next element to check is the same index
        else
        {
            it++;
        }
    }
}

vector<int> destroyedOnes;
class Movie
{
public:
    Movie(int r) : m_rating(r) {}
    ~Movie() { destroyedOnes.push_back(m_rating); }
    int rating() const { return m_rating; }

private:
    int m_rating;
};

void removeBad(list<Movie *> &li)
{
    // if rating is < 50 remove and destroy
    for (auto it = li.begin(); it != li.end(); it++)
    {
        if ((*it)->rating() < 50)
        {
            delete *it;
            li.erase(it++);
        }
    }
}

void removeBad(vector<Movie *> &v)
{
    for (auto it = v.begin(); it != v.end();)
    {
        if ((*it)->rating() < 50)
        {
            delete *it;
            it = v.erase(it);
        }
        // only increment if not deleting since if you delete
        // the next element to check is the same index
        else
        {
            it++;
        }
    }
}
