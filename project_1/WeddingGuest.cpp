#include "WeddingGuest.h"
#include <string>
using namespace std;

WeddingGuest::WeddingGuest(){
    this->head = nullptr;
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
            if ((lastName < current->last_name) | ((lastName == current->last_name) && (firstName < current->first_name))){
                Node* temp = new Node(firstName, lastName, value);
                temp->next = current;
                current->prev = temp;
                previous->next = temp;
                return true;
        }
        // something with previous here
    }
}