#include <iostream>
using namespace std;

struct LinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    };
    Node *head, *tail;
    int countNode = 0;
    LinkedList(){
        head = tail = NULL;
    }
    void pushBack(int data){
        if(!head){
            Node* temp = new Node(data);
            head = tail = temp;
        }
        else{
            Node* temp = new Node(data);
            tail->next = temp;
            tail = temp;
        }
        countNode++;
    }
    void pushFront(int data){
        if(!head){
            Node* temp = new Node(data);
            head = tail = temp;
        }
        else{
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
        }
        countNode++;
    }
    void pushAt(int pos, int data){
        Node* temp = head;
        int place = 0;
        while(place < pos-1)
            temp = temp->next;
        Node* t = new Node(data);
        t->next = temp->next;
        temp->next = t;
        countNode++;
    }
    void print(){
        Node* temp = head;
        while(temp){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void sortedInsert(int data){
        if(!head || head->data > data){
            pushFront(data);
            return;
        }
        Node* temp = head;
        while(temp->next && temp->next->data < data)
            temp = temp->next;
        Node* t = new Node(data);
        t->next = temp->next;
        temp->next = t;
        countNode++;
    }
    void reverse(){
        Node *p,*c,*n;
        c = tail = head;
        p = NULL;
        while(c){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
    }
};
int main(){
    LinkedList List;
    List.pushBack(1);
    List.pushBack(2);
    List.pushBack(3);
    List.pushBack(5);
    List.pushBack(6);
    List.sortedInsert(4);
    List.sortedInsert(7);
    List.sortedInsert(0);
    List.reverse();
    List.print();
}
