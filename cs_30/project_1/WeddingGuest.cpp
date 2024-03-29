#include "WeddingGuest.h"
#include <string>
#include <iostream>
using namespace std;

WeddingGuest::WeddingGuest(){
    this->head = nullptr;
}

// void WeddingGuest::print() const{
//     if (this->head != nullptr){
//         Node* temp = this->head;
//         while (temp != nullptr){
//             cout << temp->last_name << ' ' << temp->first_name << ' ' << temp->val << endl;
//             temp = temp->next;
//         }
//     }
// }

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
    if (this == &other){
        return *this;
    }
    // delete this;
    if (this->head != nullptr){
        Node* curr = this->head;
        while(curr != nullptr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        this->head = nullptr;
    }
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
        }
    }
    return false;
}

WeddingGuest::~WeddingGuest(){
    if (this->head != nullptr){
        Node* curr = this->head;
        while(curr != nullptr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
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
    if (this->head == nullptr){ // if list is empty do nothing
        return false;
    }
    else if ((this->head->first_name == firstName) && (this->head->last_name == lastName)){
        if (this->head->next == nullptr){
            delete this->head;
            this->head = nullptr;
        } else{
            Node* temp = this->head->next;
            temp->prev = nullptr;
            delete this->head;
            this->head = temp;
        }
        // i think it's because count is not dec?
        return true;
    }
    else{
        Node* prev = this->head;
        Node* curr = this->head->next;
        while(curr != nullptr){
            if ((curr->first_name == firstName) && (curr->last_name == lastName)){
                if (curr->next != nullptr){
                    curr->next->prev = prev;
                }
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
    if (this != &other){
        WeddingGuest temp = other;
        other = *this;
        int i = 0;
        string fname, lname;
        GuestType val;
        delete this;
        while (temp.verifyGuestOnTheList(i, fname, lname, val)){
            this->inviteGuest(fname, lname, val);
            i++;
        }
    }
}

bool joinGuests(const WeddingGuest& odOne, const WeddingGuest& odTwo,
 WeddingGuest & odJoined){
    WeddingGuest temp;
    string fname, lname;
    GuestType val_one, val_two;
    int i = 0;
    bool to_return = true;
    while(odOne.verifyGuestOnTheList(i, fname, lname, val_one)){ // for every name
        if (!odTwo.matchInvitedGuest(fname, lname, val_two)){ // if name is unique to odOne add it to odJoined
            temp.inviteGuest(fname, lname, val_one);
        } else if (val_one == val_two){
            temp.inviteGuest(fname, lname, val_one);
        } else{
            to_return = false;
        }
        i++;
    }
    i = 0;
    while(odTwo.verifyGuestOnTheList(i, fname, lname, val_two)){ // for every name
        if (!odOne.matchInvitedGuest(fname, lname, val_one)){ // if name is unique to odOne add it to odJoined
            temp.inviteGuest(fname, lname, val_two);
        } else if (val_two == val_one){
            temp.inviteGuest(fname, lname, val_two);
        } else{
            to_return = false;
        }
        i++;
    }
    odJoined = temp;
    return to_return;
} 

void attestGuests (const std::string& fsearch, const std::string& lsearch, const WeddingGuest& odOne, WeddingGuest& odResult){
    string fname, lname;
    GuestType data;
    WeddingGuest temp;
    int index = 0;
    if ((fsearch == "*") && (lsearch == "*")){ // if i should copy everything
        temp = odOne;
    }
    else if ((fsearch != "*") && (lsearch != "*")){ // if i should copy one
        if (odOne.matchInvitedGuest(fsearch, lsearch, data)){
            temp.inviteGuest(fsearch, lsearch, data);
        }
    }
    else if (fsearch != "*"){ // if only matching first name
        while (odOne.verifyGuestOnTheList(index, fname, lname, data)){
            if (fname == fsearch){
                temp.inviteGuest(fname, lname, data);
            }
            index++;
        }
    }
    else{ // if only matching last name
        while (odOne.verifyGuestOnTheList(index, fname, lname, data)){
            if (lname == lsearch){
                temp.inviteGuest(fname, lname, data);
            }
            index++;
        }
    }
    odResult = temp;
}
