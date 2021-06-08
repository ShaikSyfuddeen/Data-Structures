#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class LinkedList
{
    private:
     Node *head;
     Node *tail;
    public:
        LinkedList();
        insert(int data);
        Node* insert_begining(int data);
        Node* insert_middle(int data, int position);
        Node* delete_begining();
        Node* delete_end();
        Node* delete_middle(int position);
        printList();
};

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::insert(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        Node* tail = new Node();
        tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = temp;
    }
}

Node* LinkedList::insert_begining(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}

Node* LinkedList::insert_middle(int data, int position){
    if(position == 0 || head == NULL){
        insert_begining(data);
        return head;
    }

    Node* middle = new Node();
    middle->data = data;
    middle->next = NULL;
    int count = 1;

    Node* temp = new Node();
    temp = head;
    while(count < position && temp->next!=NULL){
        temp = temp->next;
        count++;
    }
    
    middle->next = temp->next;
    temp->next = middle;
    return head;

}

Node* LinkedList::delete_end(){
    Node* temp = new Node();
    temp = head;
    if(head == NULL){
        return head;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    cout<<temp->next->data<<endl;
    temp->next = NULL;
    return head;
}

Node* LinkedList::delete_begining(){
    if(head == NULL){
        return head;
    }
    cout<<head->data<<endl;
    head = head->next;
    return head;
}

Node* LinkedList::delete_middle(int position){

    if(head == NULL){
        return head;
    }

    if(position == 0){
        delete_begining();
        return head;
    }

    Node* temp = new Node();
    temp = head;
    int count = 1;

    while(count < position && temp->next->next!=NULL){
        temp = temp->next;
        count++;
    }

    cout<<temp->next->data<<endl;
    temp->next = temp->next->next;
    return head;


}

LinkedList::printList(){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



int main(){
    LinkedList LL;
    LL.delete_end();
    LL.printList();
    LL.insert_middle(88,1);
    LL.insert(6);
    LL.insert(6);
    LL.insert(9);
    LL.delete_middle(0);
    LL.delete_middle(3);
    LL.printList();
    LL.insert_middle(80,2);
    //LinkedList ll;
    // ll.insert(7);
    // ll.insert(8);
    // ll.insert(6);
    LL.printList();
    // ll.printList();
    LL.insert_begining(56);
    LL.printList();
    LL.insert_middle(90,0);
    LL.insert_middle(88,8);
    LL.printList();
    LL.delete_end();
    LL.printList();
    LL.delete_begining();
    LL.printList();
    LL.delete_middle(10);
    LL.printList();
}