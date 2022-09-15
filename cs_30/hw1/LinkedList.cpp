#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

LinkedList::LinkedList(){
    this->head = nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs){
    this->head = nullptr;
    // loop through rhs and make a deep copy
    ItemType val;
    int idx = 0;
    if (rhs.get(idx, val)){
        this->insertToFront(val);
        Node* temp = this->head;
        idx++;
        while (rhs.get(idx, val)){
            temp->next = new Node(val);
            temp = temp->next;
            idx++;
        }
    }
}

LinkedList::~LinkedList(){
    Node* curr = this->head;
    Node* next;
    while (curr != nullptr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = nullptr; // dixes dangling pointer
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs){
    // destroy dynamic alloc mem if any
    this->~LinkedList();
    // loop through rhs and make a deep copy
    ItemType val;
    int idx = 0;
    if (rhs.get(idx, val)){
        this->insertToFront(val);
        Node* temp = this->head;
        idx++;
        while (rhs.get(idx, val)){
            temp->next = new Node(val);
            temp = temp->next;
            idx++;
        }
    }
    return *this;
}

bool LinkedList::operator==(const LinkedList& rhs){
    // easy check that will save time if not passed
    if (this->size() != rhs.size()){
        return false;
    }
    // loop through both concurrently and compare values
    Node* temp = this->head;
    ItemType val;
    int idx = 0;
    while (rhs.get(idx, val)){
        if (temp->value != val){
            return false;
        }
        temp = temp->next;
        idx++;
    }
    return true;
}

void LinkedList::insertToFront(const ItemType &val){
    Node* new_head = new Node(val);
    if (this->head == nullptr){
        this->head = new_head;
    }
    else{
        new_head->next = this->head;
        this->head = new_head;
    }
}

void LinkedList::printList() const{ // cant unit test this because a side effect
    Node* temp = this->head;

    while (temp != nullptr){
        cout << temp->value << ' ';
        temp = temp->next;
    }
    cout << endl;
}

bool LinkedList::get(int i, ItemType& item) const{
    Node* temp = this->head;
    int idx = 0;

    while ((temp != nullptr) && (idx <= i)){
        if (i == idx){
            item = temp->value;
            return true;
        }
        temp = temp->next;
        idx++;
    }
    return false;
}

void LinkedList::reverseList(){
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void LinkedList::printReverse() const{ // cant unit test because a side effect
    // O(1) space complexity
    int idx = this->size() - 1;
    ItemType val;
    for (idx; idx>=0; idx--){
        this->get(idx, val);
        cout << val << ' ';
    }
    cout << endl;
}

void LinkedList::append(const LinkedList &other){
    // THIS IS UGLY
    // i wanted to keep from writing the loop twice but when this is null, i have to write the first iteration
    Node* temp = this->head;
    ItemType val;
    int idx = 0;
    // get to the end
    if (temp != nullptr){
        while (temp->next != nullptr){
            temp = temp->next;
        }
    }
    else{
        if (other.get(idx, val)){
            this->head = new Node(val);
            temp = this->head;
            idx++;
        }
    }
    // loop through other and append a deep copy
    while (other.get(idx, val)){
        temp->next = new Node(val);
        temp = temp->next;
        idx++;
    }
}

void LinkedList::swap(LinkedList& other){
    Node* temp = other.head;
    other.head = this->head;
    this->head = temp;
}

int LinkedList::size() const{
    Node* temp = this->head;
    int len = 0;

    while (temp != nullptr){
        temp = temp->next;
        len++;
    }

    return len;
}