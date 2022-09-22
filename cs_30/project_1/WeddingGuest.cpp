#include "WeddingGuest.h"
#include <string>
#include <iostream>
using namespace std;

// TODO: refactor invite so it ompares to previous.
// If i do this i think i only need to compare to head not
// head.next
// actually i think i lied, id still need to check after
// the while if i have it look and previous

WeddingGuest::WeddingGuest(){
    this->head = nullptr;
}

void WeddingGuest::print() const{
    if (this->head != nullptr){
        Node* temp = this->head;
        while (temp != nullptr){
            cout << temp->last_name << ' ' << temp->first_name << ' ' << temp->val << endl;
            temp = temp->next;
        }
    }
}

WeddingGuest::WeddingGuest(const WeddingGuest& other){
    this->head = nullptr;
    int i = 0;
    string fname, lname;
    GuestType data;
    while (other.verifyGuestOnTheList(i, fname, lname, data)){
        this->inviteGuest(fname, lname, data);
        i++;
    }
}

const WeddingGuest& WeddingGuest::operator=(const WeddingGuest& other){
    this->~WeddingGuest();
    int i = 0;
    string fname, lname;
    GuestType data;
    while (other.verifyGuestOnTheList(i, fname, lname, data)){
        this->inviteGuest(fname, lname, data);
        i++;
    }
    return *this;
}

bool WeddingGuest::noGuests() const{
    return this->head == nullptr;
}

int WeddingGuest::guestCount() const{
    int count = 0;
    Node* temp = this->head;

    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

bool WeddingGuest::inviteGuest(const std::string& firstName, const std::string& lastName, const GuestType& value){
    // if the list is empty
    if (this->head == nullptr){
        // add the guest
        this->head = new Node(firstName, lastName, value);
        return true;
    } else if (lastName == this->head->last_name && firstName == this->head->first_name){ // if name is already in the list
        return false;
    } 
    else if ((lastName < this->head->last_name) | ((lastName == this->head->last_name) && (firstName < this->head->first_name))){ // if because of the last name this guest goes first
            Node* new_head = new Node(firstName, lastName, value); // create the guest
            new_head->next = this->head; // link the list
            this->head->prev = new_head;
            this->head = new_head; // save changes
            return true;
    }
    else { // othwerwise loop through and check
        Node* previous = this->head;
        Node* current = this->head->next;
        while (current != nullptr){
            if ((lastName == current->last_name) && (firstName == current->first_name)){
                return false;
            }
            else if ((lastName < current->last_name) || ((lastName == current->last_name) && (firstName < current->first_name))){ // infront of current
                Node* temp = new Node(firstName, lastName, value);
                temp->next = current;
                current->prev = temp;
                previous->next = temp;
                temp->prev = previous;
                return true;
            }
            previous = current;
            current = current->next;
        }
        if ((previous->last_name < lastName) | ((previous->last_name == lastName) && (previous->first_name < firstName))){ // otherwise, given it's not the tail, it belongs at the end
            Node* temp = new Node(firstName, lastName, value);
            temp->prev = previous;
            previous->next = temp;
            return true;
            //  i think i dont need this if i compare against previous insted of current
        }
    }
    return false;
}

WeddingGuest::~WeddingGuest(){
    if (this->head != nullptr){
        Node* prev = this->head;
        this->head->next;
        Node* curr = this->head->next;
        while(curr != nullptr){
            delete prev;
            prev = curr;
            curr = curr->next;
        }
        delete prev;
        this->head = nullptr;
    }
}

bool WeddingGuest::alterGuest(const std::string& firstName, const std::string& 
lastName, const GuestType& value){
    Node* temp = this->head;
    while (temp != nullptr){
        if ((temp->first_name == firstName) && (temp->last_name == lastName)){
            temp->val = value;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool WeddingGuest::inviteOrAlter(const std::string& firstName,
    const std::string& lastName, const GuestType& value){
    if (!this->alterGuest(firstName, lastName, value)){
        this->inviteGuest(firstName, lastName, value);
    }
    return true;
}

bool WeddingGuest::crossGuestOff(const std::string& firstName, const 
    std::string& lastName){
    if (this->head == nullptr){
        return false;
    }
    else if ((this->head->first_name == firstName) && (this->head->last_name == lastName)){
        Node* temp = this->head->next;
        temp->prev = nullptr;
        delete this->head;
        this->head = temp;
        return true;
    }
    else{
        Node* prev = this->head;
        Node* curr = this->head->next;
        while(curr != nullptr){
            if ((curr->first_name == firstName) && (curr->last_name == lastName)){
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;

        }
        return false;
    }
}

bool WeddingGuest::invitedToTheWedding(const std::string& firstName, const 
    std::string& lastName) const{
    if (this->head == nullptr){
        return false;
    }
    Node* temp = this->head;
    while (temp != nullptr){
        if ((temp->first_name == firstName) && (temp->last_name == lastName)){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool WeddingGuest::matchInvitedGuest(const std::string& firstName, const 
    std::string& lastName, GuestType& value) const{
    Node* temp = this->head;
    while (temp != nullptr){
        if ((temp->first_name == firstName) && (temp->last_name == lastName)){
            value = temp->val;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool WeddingGuest::verifyGuestOnTheList(int i, std::string& firstName, 
    std::string& lastName, GuestType & value) const{
    if (i >= 0){
        Node* temp = this->head;
        while (temp != nullptr){
            if (i == 0){
                firstName = temp->first_name;
                lastName = temp->last_name;
                value = temp->val;
                return true;
            }
            i--;
            temp = temp->next;
        }
    }
    return false;
}

void WeddingGuest::swapWeddingGuests(WeddingGuest& other){
    WeddingGuest temp = other;
    other = *this;
    int i = 0;
    string fname, lname;
    GuestType val;
    this->~WeddingGuest();
    while (temp.verifyGuestOnTheList(i, fname, lname, val)){
        this->inviteGuest(fname, lname, val);
        i++;
    }
    temp.~WeddingGuest();

}

bool joinGuests(const WeddingGuest& odOne, const WeddingGuest& odTwo,
 WeddingGuest & odJoined){
    // if a fullname is unique to a or b add to c
    // if node exists in both add to c
    // at the end, return false if name matches but value doesn't
    // otherwise return true
    odJoined.~WeddingGuest();
    string fname, lname;
    GuestType val_one, val_two;
    int i = 0;
    bool to_return = true;
    while(odOne.verifyGuestOnTheList(i, fname, lname, val_one)){ // for every name
        if (!odTwo.matchInvitedGuest(fname, lname, val_two)){ // if name is unique to odOne add it to odJoined
            odJoined.inviteGuest(fname, lname, val_one);
        } else if (val_one == val_two){
            odJoined.inviteGuest(fname, lname, val_one);
        } else{
            to_return = false;
        }
        i++;
    }
    i = 0;
    while(odTwo.verifyGuestOnTheList(i, fname, lname, val_two)){ // for every name
        if (!odOne.matchInvitedGuest(fname, lname, val_one)){ // if name is unique to odOne add it to odJoined
            odJoined.inviteGuest(fname, lname, val_two);
        } else if (val_two == val_one){
        odJoined.inviteGuest(fname, lname, val_two);
        } else{
            to_return = false;
        }
        i++;
    }
    return to_return;
} 

// TODO: cmissing func. doen't forget to make print private
