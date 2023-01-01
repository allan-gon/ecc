// #include <iostream>
// #include <list>
// #include <map>
// #include <string>
// #include <utility>
// using namespace std;

// void printRoster(map<string, map<string, list<string>>> &roster) {
//   map<string, map<string, list<string>>>::iterator map_it;
//   for (map_it = roster.begin(); map_it != roster.end(); map_it++) {
//     map<string, list<string>>::iterator other_it;
//     cout << map_it->first << endl;
//     for (other_it = map_it->second.begin(); other_it != map_it->second.end();
//          other_it++) {
//       cout << "\t" << other_it->first << ":\n";

//       std::list<string>::iterator it;
//       for (it = other_it->second.begin(); it != other_it->second.end(); ++it)
//       {
//         cout << "\t\t" << *it << endl;
//       }
//     }
//   }
// }

// int main() {
//   map<string, map<string, list<string>>> a;

//   a["ElCo"]["CS-30"].emplace_back("LeBron James");
//   a["ElCo"]["CS-30"].emplace_back("Anthonny Davis");
//   a["ElCo"]["BUS-101"].emplace_back("Russel WestBrook");
//   a["SMC"]["CHEM-101"].emplace_back("Lonnie Walker");

//   printRoster(a);
//   return 0;
// }

#include <future>
#include <iostream>
#include <regex>
using namespace std;

// int main() {
//   // match
//   //   string str1 = "7/4/1776";
//   //   string str1 = "1-1-2018";
//   // not match
//   //   string str1 = "3/29-2018";

//     // if match 1,3,5,7,8,10,12 the day must be 1-31
//     // otherwise 0-30 except 2:28

//   string str1 = "9-31-1955";
//   ""
//   regex pattern("^[0-9][0-9]?([-/])[0-9][0-9]?\\1[0-9][0-9][0-9][0-9]$");

//   bool match = regex_search(str1, pattern);
//   cout << (match ? "Matched" : "Not matched") << endl;
//   return 0;
// }

double funcA(double a) {
  if (a < 1) {
    throw "less than 1";
    return a * a;
  }
}

int main() {
  double dValue;
  cin >> dValue;

  try {
    future<double> dValue = async(funcA, dValue);
  } catch (const char *s) {
    cout << s << endl;
  }
  return 0;
}