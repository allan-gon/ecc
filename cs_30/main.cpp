#include <algorithm>
using namespace std;

struct obj{
    int a;
    int b;
};

int main(){
    obj ls[2] = {{1, 3}, {7, 9}};
    std::sort(ls[0], ls[2], [](obj one, obj two) -> bool {return one.a < two.b;});
    return 0;
}