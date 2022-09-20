#include "WeddingGuest.h"
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main(){
    WeddingGuest list;
    // list.print(); // should print nothing
    GuestType fname, lname, data;
    // cout << "--------" << endl;
    assert(list.verifyGuestOnTheList(10, fname, lname, data) == false); // checks that verifying on an empty list returns false
    assert(list.matchInvitedGuest("a", "b", data) == false); // checks that match return false on an empty list
    assert(list.invitedToTheWedding("A", "B") == false); // check that checking for people in an empty list returns false
    assert(list.crossGuestOff("A", "B") == false); // checks that crossing off a guest from an empty list does nothing
    assert(list.alterGuest("A", "B", "C") == false); // checks that you can't alter an empty list
    assert(list.noGuests() == true); // checks that noGuest correctly knows the list is empty
    assert(list.guestCount() == 0); // checks both that count works for an empty list and that the default constructor sets head to nullptr
    list.inviteGuest("Allan", "Gongora", "20");
    assert(list.alterGuest("Allan", "Gongora", "21")); // checks that you can alter a a guest when it exists in the list
    assert(list.alterGuest("X", "Y", "29") == false); // checks that you cant alter a guest that doesn't exist in a populated list
    assert(list.noGuests() == false); // checks that noGuest correctly knows the list is NOT empty
    assert(list.guestCount() == 1); // checks that I properly insert to an empty list
    list.inviteGuest("A", "Z", "19");
    list.inviteGuest("Aa", "Gongora", "25");
    // list.print();
    // cout << "--------" << endl;
    assert(list.inviteOrAlter("Person", "Last", "30") == true); // checks that returns true (redundant)
    assert(list.guestCount() == 4); // checks that count increased when inv/alter an guest that's not on the list
    assert(list.crossGuestOff("Aa", "Gongora") == true);// checks that crossing off an existing person can happen
    // list.print();
    // cout << "--------\n";
    assert(list.invitedToTheWedding("Allan", "Gongora") == true); // check that a known person is in the list
    assert(list.matchInvitedGuest("Allan", "Gongora", data) == true); // checks that matching a known guest in the list return true
    assert(data == "21"); // checks that matching correctly save value in data
    assert(list.matchInvitedGuest("A", "B", data) == false); // checks that matching a person not in the list return false
    assert(list.verifyGuestOnTheList(0, fname, lname, data) == true); // checks that verifying a person on the list return true
    assert((fname == "Allan") && (lname == "Gongora") && (data == "21")); // checks that values are correct stored after verifying a guest
    assert(list.verifyGuestOnTheList(10, fname, lname, data) == false); // checks that verifying an index out of range return false
    assert(list.verifyGuestOnTheList(-1, fname, lname, data) == false); // checks that using negative index returns false
    WeddingGuest copy = list;
    assert(copy.guestCount() == list.guestCount()); // checks that assigning WeddingGuest to Wedding Guest results in a list of equal length
    // checks that all their values are the same // too lazy to do this
    copy = list;
    assert(copy.guestCount() == list.guestCount());// check that assignment operator works (only called when already initialized item is re assigned)
    WeddingGuest l1, l2;
    l1.inviteGuest("A", "B", "C");
    l1.inviteGuest("H", "I", "J");
    l2.inviteGuest("X", "Y", "Z");
    l1.swapWeddingGuests(l2);
    assert((l1.guestCount() == 1) && (l2.guestCount() == 2)); // checks that lens swapped
    // l1.print(); // this is to checks that contents actualy swapped. too lazy to write a unit test
    // l2.print();
    WeddingGuest temp1, temp2, joined;
    // "LeBron" "James" 23 "Russell" "Westbrook" 0 
    temp1.inviteGuest("Anthony", "Davis", "3");
    temp1.inviteGuest("Lebron", "James", "23");
    temp1.inviteGuest("Malik", "Monk", "11");
    
    temp2.inviteGuest("Lebron", "James", "23");
    temp2.inviteGuest("Russell", "Westbrook", "0");

    assert(joinGuests(temp1, temp2, joined)); // join return true
    // joined.print();
    // "Pete" "Best" 6 "George" "Harrison" 4 "Ringo" "Starr" 5
    temp1 = WeddingGuest();
    temp2 = WeddingGuest();
    temp1.inviteGuest("Pete", "Best", "3");
    temp1.inviteGuest("John", "Lennon", "1");
    temp1.inviteGuest("Paul", "McCartney", "2");

    temp2.inviteGuest("Pete", "Best", "6");
    temp2.inviteGuest("George", "Harrison", "4");
    temp2.inviteGuest("Ringo", "Starr", "5");

    assert(!joinGuests(temp1, temp2, joined)); // join returns false
    joined.print();

    cout << "All tests passesd\n";
    return 0;
}