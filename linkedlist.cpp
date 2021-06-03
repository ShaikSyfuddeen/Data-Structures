#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* insert_begining(Node* head, int x){

    Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;

}

Node* insert_end(Node* head, int x){

    Node* end = new Node;
    end->data = x;
    end->next = NULL;

    if(head == NULL){
        head = end;
        return head;
    }

    Node* temp = new Node;
    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = end;
    return head;
}

Node* insert_middle(Node* head, int x, int position){
    Node* middle = new Node;
    middle->data = x;
    middle->next = NULL;

    if(head == NULL){
        head = middle;
        return head;
    }

    if(position == 0){
        middle->next = head;
        head = middle;
        return head;
    }

    Node* temp = new Node;
    temp = head;
    int count = 1;
    while(temp->next && count < position){
        temp = temp->next;
        count++;
    }

    middle->next = temp->next;
    temp->next = middle;

    return head;
}

Node* delete_begining(Node* head){
    if(head == NULL){
        cout<<"Empty\n";
        free(head);
        return head;
    }
    Node* temp = new Node;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* delete_end(Node* head){
    if(head == NULL){
        cout<<"Empty";
        free(head);
        return head;
    }
    Node* temp = new Node;
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

Node* delete_middle(Node* head, int position){
    Node* temp = new Node;
    temp = head;

    if(head == NULL){
        cout<<"Empty";
        return head;
    }

    if(position == 0){
        head = head->next;
        free(temp);
        return head;
    }

    int count = 1;
    while(temp->next && count < position){
        temp = temp->next;
        count++;
    }

    Node* middle = new Node;
    middle = temp;
    middle = middle->next->next;
    temp->next = middle;
    return head;

}

void printlist(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node;
    head = NULL;
    head = insert_begining(head, 10);
    head = insert_begining(head, 40);
    head = insert_begining(head, 10);
    head = insert_begining(head, 10);
    head = insert_begining(head, 10);
    head = insert_end(head, 20);
    head = insert_middle(head, 30, 2);
    head = delete_begining(head);
    head = delete_end(head);
    head = delete_middle(head,2);
    printlist(head);
}