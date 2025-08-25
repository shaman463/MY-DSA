#include<iostream>
using namespace std;


class MyLinkedList {
private:
    struct node{
        int val;
        node* next;
        node(int val){
            this->val = val;
            next = NULL;
        }
    };
    node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index>=size){
            return -1;
        }
        node* temp = head;
        for(int i = 0; i<index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
       node* n = new node(val);
       n->next = head;
       head = n;
       size++;
    }
    
    void addAtTail(int val) {
        node* n = new node(val);
        if (head == nullptr) {
            head = n;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
        addAtHead(val);
        return;
    }

        node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        node* n = new node(val);
        n->next = temp->next;
        temp->next = n;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index>=size){
            return;
        }
        if(index == 0){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            node* temp = head;
            for(int i = 0; i<index-1;i++){
                temp = temp->next;
            }
            node* curr = temp->next;
            temp->next = curr->next;
            delete curr;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */