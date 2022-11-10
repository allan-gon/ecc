// #include "WeddingGuest.h"
// #include <string>
// #include <cassert>
// #include <iostream>
// using namespace std;

// int main(){
//     WeddingGuest list;
//     // list.print(); // should print nothing
//     GuestType fname, lname, data;
//     // cout << "--------" << endl;
//     assert(list.verifyGuestOnTheList(10, fname, lname, data) == false); // checks that verifying on an empty list returns false
//     assert(list.matchInvitedGuest("a", "b", data) == false); // checks that match return false on an empty list
//     assert(list.invitedToTheWedding("A", "B") == false); // check that checking for people in an empty list returns false
//     assert(list.crossGuestOff("A", "B") == false); // checks that crossing off a guest from an empty list does nothing
//     assert(list.alterGuest("A", "B", "C") == false); // checks that you can't alter an empty list
//     assert(list.noGuests() == true); // checks that noGuest correctly knows the list is empty
//     assert(list.guestCount() == 0); // checks both that count works for an empty list and that the default constructor sets head to nullptr
//     list.inviteGuest("Allan", "Gongora", "20");
//     assert(list.alterGuest("Allan", "Gongora", "21")); // checks that you can alter a a guest when it exists in the list
//     assert(list.alterGuest("X", "Y", "29") == false); // checks that you cant alter a guest that doesn't exist in a populated list
//     assert(list.noGuests() == false); // checks that noGuest correctly knows the list is NOT empty
//     assert(list.guestCount() == 1); // checks that I properly insert to an empty list
//     list.inviteGuest("A", "Z", "19");
//     list.inviteGuest("Aa", "Gongora", "25");
//     // list.print();
//     // cout << "--------" << endl;
//     assert(list.inviteOrAlter("Person", "Last", "30") == true); // checks that returns true (redundant)
//     assert(list.guestCount() == 4); // checks that count increased when inv/alter an guest that's not on the list
//     assert(list.crossGuestOff("Aa", "Gongora") == true);// checks that crossing off an existing person can happen
//     // list.print();
//     // cout << "--------\n";
//     assert(list.invitedToTheWedding("Allan", "Gongora") == true); // check that a known person is in the list
//     assert(list.matchInvitedGuest("Allan", "Gongora", data) == true); // checks that matching a known guest in the list return true
//     assert(data == "21"); // checks that matching correctly save value in data
//     assert(list.matchInvitedGuest("A", "B", data) == false); // checks that matching a person not in the list return false
//     assert(list.verifyGuestOnTheList(0, fname, lname, data) == true); // checks that verifying a person on the list return true
//     assert((fname == "Allan") && (lname == "Gongora") && (data == "21")); // checks that values are correct stored after verifying a guest
//     assert(list.verifyGuestOnTheList(10, fname, lname, data) == false); // checks that verifying an index out of range return false
//     assert(list.verifyGuestOnTheList(-1, fname, lname, data) == false); // checks that using negative index returns false
//     WeddingGuest copy = list;
//     assert(copy.guestCount() == list.guestCount()); // checks that assigning WeddingGuest to Wedding Guest results in a list of equal length
//     // checks that all their values are the same // too lazy to do this
//     copy = list;
//     assert(copy.guestCount() == list.guestCount());// check that assignment operator works (only called when already initialized item is re assigned)
//     WeddingGuest l1, l2;
//     l1.inviteGuest("A", "B", "C");
//     l1.inviteGuest("H", "I", "J");
//     l2.inviteGuest("X", "Y", "Z");

//     l1.swapWeddingGuests(l2);
//     assert((l1.guestCount() == 1) && (l2.guestCount() == 2)); // checks that lens swapped
//     // l1.print(); // this is to checks that contents actualy swapped. too lazy to write a unit test
//     // l2.print();
//     WeddingGuest temp1, temp2, joined;
//     // "LeBron" "James" 23 "Russell" "Westbrook" 0
//     temp1.inviteGuest("Anthony", "Davis", "3");
//     temp1.inviteGuest("Lebron", "James", "23");
//     temp1.inviteGuest("Malik", "Monk", "11");

//     temp2.inviteGuest("Lebron", "James", "23");
//     temp2.inviteGuest("Russell", "Westbrook", "0");

//     assert(joinGuests(temp1, temp2, joined)); // join return true
//     // joined.print();
//     // "Pete" "Best" 6 "George" "Harrison" 4 "Ringo" "Starr" 5
//     temp1 = WeddingGuest();
//     temp2 = WeddingGuest();
//     temp1.inviteGuest("Pete", "Best", "3");
//     temp1.inviteGuest("John", "Lennon", "1");
//     temp1.inviteGuest("Paul", "McCartney", "2");

//     temp2.inviteGuest("Pete", "Best", "6");
//     temp2.inviteGuest("George", "Harrison", "4");
//     temp2.inviteGuest("Ringo", "Starr", "5");

//     assert(!joinGuests(temp1, temp2, joined)); // join returns false
//     // joined.print();

//     WeddingGuest goBruins, result;
//     goBruins.inviteGuest("Dion", "V", "45");
//     goBruins.inviteGuest("Dan", "H", "38");
//     goBruins.inviteGuest("Dan", "V", "44");
//     goBruins.inviteGuest("Cobey", "C", "35");

//     attestGuests("Dan", "*", goBruins, result);
//     // result.print();

//     cout << "All tests passesd\n";
//     return 0;
// }

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
#include <type_traits>
#include "WeddingGuest.h"
using namespace std;
bool matchInvitedGuest3type(bool (WeddingGuest::*)(const std::string &, const std::string &, GuestType &) const) { return true; }
bool matchInvitedGuest3type(bool (WeddingGuest::*)(const std::string &, const std::string &, GuestType &)) { return false; }
bool matchInvitedGuest3type(...) { return false; }
bool verifyGuestOnTheList4type(bool (WeddingGuest::*)(int, std::string &,
                                                      std::string &, GuestType &) const) { return true; }
bool verifyGuestOnTheList4type(bool (WeddingGuest::*)(int, std::string &,
                                                      std::string &, GuestType &)) { return false; }
bool verifyGuestOnTheList4type(...) { return false; }
std::string SOMEFNAME = std::string("123");
std::string DEFAULTFNAME = std::string();
std::string ARRAYFNAME[6] = {
    std::string("10"), std::string("20"), std::string("30"),
    std::string("40"), std::string("50"), std::string("60")};
std::string SOMELNAME = std::string("321");
std::string DEFAULTLNAME = std::string();
std::string ARRAYLNAME[6] = {
    std::string("11"), std::string("21"), std::string("31"),
    std::string("41"), std::string("51"), std::string("61")};
GuestType SOMEVALUE = "junk";
GuestType DEFAULTV = GuestType();
GuestType ARRAYV[6] = {
    "able", "baker", "charlie", "delta", "echo", "foxtrot"};
bool has(const WeddingGuest &m, const std::string &firstName, const std::string &lastName, const GuestType &v)
{
    GuestType v2 = DEFAULTV;
    m.matchInvitedGuest(firstName, lastName, v2);
    GuestType v3 = SOMEVALUE;
    m.matchInvitedGuest(firstName, lastName, v3);
    return v2 == v && v3 == v;
}
void testone(int n)
{
    WeddingGuest m;
    // try{
    switch (n)
    {
    default:
    {
        cout << "Bad argument" << endl;
    }
    break;
    case 1:
    {
        assert((is_same<decltype(&WeddingGuest::noGuests), bool (WeddingGuest::*)() const>::value));
    }
    break;
    case 2:
    {
        assert((is_same<decltype(&WeddingGuest::guestCount), int (WeddingGuest::*)() const>::value));
    }
    break;
    case 3:
    {
        assert((is_same<decltype(&WeddingGuest::invitedToTheWedding), bool (WeddingGuest::*)(const std::string, const std::string) const>::value) ||
               (is_same<decltype(&WeddingGuest::invitedToTheWedding), bool (WeddingGuest::*)(const std::string &, const std::string &) const>::value));
    }
    break;
    case 4:
    {
        assert(matchInvitedGuest3type(&WeddingGuest::matchInvitedGuest));
    }
    break;
    case 5:
    {
        assert(verifyGuestOnTheList4type(&WeddingGuest::verifyGuestOnTheList));
    }
    break;
    case 6:
    {
        assert(m.noGuests());
    }
    break;
    case 7:
    {
        assert(m.guestCount() == 0);
    }
    break;
    case 8:
    {
        assert(!m.alterGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE) &&
               m.guestCount() == 0);
    }
    break;
    case 9:
    {
        assert(!m.crossGuestOff(DEFAULTFNAME, DEFAULTLNAME) && m.guestCount() == 0);
    }
    break;
    case 10:
    {
        assert(!m.invitedToTheWedding(DEFAULTFNAME, DEFAULTLNAME));
    }
    break;
    case 11:
    {
        GuestType v = SOMEVALUE;
        assert(!m.matchInvitedGuest(DEFAULTFNAME, DEFAULTLNAME, v) && v ==
                                                                          SOMEVALUE);
    }
    break;
    case 12:
    {
        GuestType v = SOMEVALUE;
        assert(!m.verifyGuestOnTheList(0, DEFAULTFNAME, DEFAULTLNAME, v) && v == SOMEVALUE);
    }
    break;
    case 13:
    {
        assert(m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE));
    }
    break;
    case 14:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(!m.noGuests());
    }
    break;
    case 15:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(m.guestCount() == 1);
    }
    break;
    case 16:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(m.invitedToTheWedding(SOMEFNAME, SOMELNAME));
    }
    break;
    case 17:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        GuestType v = DEFAULTV;
        assert(m.matchInvitedGuest(SOMEFNAME, SOMELNAME, v));
    }
    break;
    case 18:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        GuestType v = DEFAULTV;
        m.matchInvitedGuest(SOMEFNAME, SOMELNAME, v);
        assert(v == SOMEVALUE);
    }
    break;
    case 19:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE);
        GuestType v = DEFAULTV;
        assert(!m.matchInvitedGuest(ARRAYFNAME[1], ARRAYLNAME[1], v));
    }
    break;
    case 20:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        GuestType v = SOMEVALUE;
        m.matchInvitedGuest(ARRAYFNAME[1], ARRAYLNAME[1], v);
        assert(v == SOMEVALUE);
    }
    break;
    case 21:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        std::string f = DEFAULTFNAME;
        std::string l = DEFAULTLNAME;
        GuestType v = DEFAULTV;
        assert(m.verifyGuestOnTheList(0, f, l, v));
    }
    break;
    case 22:
    {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        std::string f = DEFAULTFNAME;
        std::string l = DEFAULTLNAME;
        GuestType v = DEFAULTV;
        m.verifyGuestOnTheList(0, f, l, v);
        assert(f == SOMEFNAME && l == SOMELNAME && v == SOMEVALUE);
    }
    break;
    case 23:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.noGuests() && m.guestCount() == 2);
    }
    break;
    case 24:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    }
    break;
    case 25:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m,
                                                                      ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    }
    break;
    case 26:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE) && has(m,
                                                                      ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    }
    break;
    case 27:
    {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    }
    break;
    case 28:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]);
        assert(m.guestCount() == 2);
    }
    break;
    case 29:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m,
                                                                      ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    }
    break;
    case 30:
    {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        assert(!m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]));
    }
    break;
    case 31:
    {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        assert(!m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
    }
    break;
    case 32:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(m.guestCount() == 3 && m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 33:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE) &&
               has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
    }
    break;
    case 34:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        assert(m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    }
    break;
    case 35:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.alterGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]);
        assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
               has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) && !m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 36:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.alterGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) && !m.alterGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[0]));
    }
    break;
    case 37:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.noGuests() && m.guestCount() == 2);
    }
    break;
    case 38:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m,
                                                                      ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    }
    break;
    case 39:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE) && has(m,
                                                                      ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    }
    break;
    case 40:
    {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    }
    break;
    case 41:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteOrAlter(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]);
        assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]) &&
               has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    }
    break;
    case 42:
    {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        assert(m.inviteOrAlter(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]));
    }
    break;
    case 43:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(m.guestCount() == 3 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
               has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
    }
    break;
    case 44:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        assert(m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    }
    break;
    case 45:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteOrAlter(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]);
        assert(m.guestCount() == 3 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
               has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]));
    }
    break;
    case 46:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(m.inviteOrAlter(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
    }
    break;
    case 47:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]));
    }
    break;
    case 48:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
        assert(!m.noGuests() && m.guestCount() == 1 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
               !m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    }
    break;
    case 49:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
        assert(!m.noGuests() && m.guestCount() == 1 && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) &&
               !m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]));
    }
    break;
    case 50:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
        m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
        assert(m.guestCount() == 0);
    }
    break;
    case 51:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
        m.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
               has(m, ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]) && !m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               !m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 52:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]) && m.guestCount() == 2);
    }
    break;
    case 53:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f;
        std::string l;
        GuestType v;
        assert(!m.verifyGuestOnTheList(-1, f, l, v));
    }
    break;
    case 54:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f = SOMEFNAME;
        std::string l = SOMELNAME;
        GuestType v = SOMEVALUE;
        m.verifyGuestOnTheList(-1, f, l, v);
        assert(f == SOMEFNAME && l == SOMELNAME && v == SOMEVALUE);
    }
    break;
    case 55:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f, l;
        GuestType v;
        assert(!m.verifyGuestOnTheList(2, f, l, v));
    }
    break;
    case 56:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f = SOMEFNAME;
        std::string l = SOMELNAME;
        GuestType v = SOMEVALUE;
        m.verifyGuestOnTheList(2, f, l, v);
        assert(f == SOMEFNAME && l == SOMELNAME && v == SOMEVALUE);
    }
    break;
    case 57:
    {
        m.inviteGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        assert(m.guestCount() == 1 && has(m, DEFAULTFNAME, DEFAULTLNAME,
                                          SOMEVALUE));
    }
    break;
    case 58:
    {
        m.alterGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        assert(m.guestCount() == 0 && !m.invitedToTheWedding(DEFAULTFNAME,
                                                             DEFAULTLNAME));
    }
    break;
    case 59:
    {
        m.inviteOrAlter(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        assert(m.guestCount() == 1 && has(m, DEFAULTFNAME, DEFAULTLNAME,
                                          SOMEVALUE));
    }
    break;
    case 60:
    {
        m.inviteGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        m.crossGuestOff(DEFAULTFNAME, DEFAULTLNAME);
        assert(m.guestCount() == 0 && !m.invitedToTheWedding(DEFAULTFNAME,
                                                             DEFAULTLNAME));
    }
    break;
    case 61:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(m.guestCount() == 3);
        }
    }
    break;
    case 62:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) &&
                   has(m, ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]) && !m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]));
        }
    }
    break;
    case 63:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(m2.guestCount() == 2);
        }
    }
    break;
    case 64:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(has(m2, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
                   has(m2, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) &&
                   !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) && !m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    }
    break;
    case 65:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m.swapWeddingGuests(m2);
            assert(m.guestCount() == 3 && m2.guestCount() == 5);
        }
    }
    break;
    case 66:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            assert(m2.guestCount() == 2 &&
                   m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) && !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[3]));
        }
    }
    break;
    case 67:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
            m2.crossGuestOff(ARRAYFNAME[3], ARRAYLNAME[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        }
        assert(true); // no corruption so bad that destruction failed
    }
    break;
    case 68:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            WeddingGuest m3(m2);
            m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m3.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
            m3.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m3.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
            m3.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m3.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
            m3.crossGuestOff(ARRAYFNAME[3], ARRAYLNAME[3]);
            m3.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        }
        assert(true); // no corruption so bad that destruction failed
    }
    break;
    case 69:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            WeddingGuest m3(m2);
            assert(m3.guestCount() == 3);
        }
    }
    break;
    case 70:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        {
            WeddingGuest m2(m);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.guestCount() == m.guestCount() + 1);
        }
    }
    break;
    case 71:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        {
            WeddingGuest m2(m);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.guestCount() == 4 &&
                   m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    }
    break;
    case 72:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        {
            WeddingGuest m2(m);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.guestCount() == 4 &&
                   m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) && !m2.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
        }
    }
    break;
    case 73:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            WeddingGuest m3;
            m3.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m3.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            m3 = m2;
            assert(m3.guestCount() == 3 && m2.guestCount() == 3);
        }
    }
    break;
    case 74:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2 = m;
            m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            assert(m2.guestCount() == m.guestCount() + 1);
        }
    }
    break;
    case 75:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            m2 = m;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
                   !m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    }
    break;
    case 76:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            m2 = m;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            assert(m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                   m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                   !m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
        }
    }
    break;
    case 77:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2 = m2;
            assert(m2.guestCount() == 3);
            assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
        }
        assert(true); // no corruption so bad that destruction failed
    }
    break;
    case 78:
    {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2 = m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
                   m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    }
    break;
    case 79:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 80:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        WeddingGuest m3;
        joinGuests(m2, m, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 81:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
               m3.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
               m3.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
    }
    break;
    case 82:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        assert(joinGuests(m, m2, m3));
    }
    break;
    case 83:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[5]);
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
               m3.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
               m3.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]) &&
               has(m3, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) &&
               !has(m3, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[5]));
    }
    break;
    case 84:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[5]);
        assert(joinGuests(m, m2, m3));
    }
    break;
    case 85:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
               m3.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
    }
    break;
    case 86:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m3;
        assert(joinGuests(m, m2, m3));
    }
    break;
    case 87:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[4]);
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 88:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[4]);
        WeddingGuest m3;
        assert(!joinGuests(m, m2, m3));
    }
    break;
    case 89:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        joinGuests(m, m2, m);
        assert(m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
               m.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
               m.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
    }
    break;
    case 90:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        joinGuests(m, m2, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
               m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
               m2.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
    }
    break;
    case 91:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m2);
        assert(!m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    }
    break;
    case 92:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m2);
        assert(!m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    }
    break;
    case 93:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m);
        assert(!m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    }
    break;
    case 94:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[1], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[1]) &&
               !m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 95:
    {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[0], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[2], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests(ARRAYFNAME[1], "*", m, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[0]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[2]) &&
               !m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 96:
    {
        string all = "*";
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[1], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests("*", "*", m, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[1]) &&
               m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
               m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    }
    break;
    case 97:
    {
        WeddingGuest m2 = m;
        WeddingGuest m3;
        attestGuests("*", "*", m2, m3);
        assert(m3.guestCount() == m.guestCount());
    }
    break;
    case 98:
    {
        WeddingGuest m2;
        WeddingGuest m3(m);
        attestGuests("*", "*", m2, m3);
        assert(m3.noGuests());
    }
    break;
    case 99:
    {
        WeddingGuest m2;
        attestGuests("*", "*", m2, m2);
        assert(m2.guestCount() == 0);
    }
    break;
    case 100:
    {
        const int NITEMS = 2000;
        for (int k = 0; k < NITEMS; k++)
            assert(m.inviteGuest(std::to_string(k), std::to_string(k),
                                 SOMEVALUE));
        assert(m.guestCount() == NITEMS);
    }
    }
    // } catch (...){
    //     ofstream outfile;
    //     outfile.open("failed.txt", std::ios_base::app); // append instead of overwrite
    //     outfile << n << ',';
    //     // throw;
    // }
    // ofstream file("passed.txt", std::ios_base::app);
    // file << n << ',';
}
int main()
{
    for (int n = 1; n <= 100; n++)
    {   
        testone(n);
        cout << n << " passed" << endl;
    }
    return 0;
}