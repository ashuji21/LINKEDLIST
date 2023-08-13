
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
       this->data=data;
       this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free from node with data"<<value<<endl;;
    }
};
void insertAtTail(Node* &tail, int d ){
    Node* temp =new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtHead(Node* &head, int d ){
    Node* temp =new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtPosi(Node* &head,Node* &tail,int position,int d){
     Node* nodetoinsert=new Node(d);
     if(position==1){
        insertAtHead(head,d);
     }
     Node* temp=head;
     int cnt=1;
     while(cnt<position-1){
        temp=temp->next;
        cnt++;
     }
     if(temp->next==NULL){
        insertAtTail(tail,d);
     }
     nodetoinsert->next=temp->next;
     temp->next=nodetoinsert;

}
void deleteNode(int position, Node* & head){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* cur=head;
        int cnt=1;
        Node* prev=NULL;
        while (cnt<position)
        {
            prev=cur;
            cur=cur->next;
            cnt++;
        }
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
        
    }
}

void Print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
 }
int main(){
     
   Node* node1=new Node(10);
   Node* head=node1;
   Node* tail=node1;
   Print(head);
   insertAtTail(tail,12);
   Print(head);
   insertAtHead(head,11);
   Print(head);
   insertAtPosi(head,tail,3,8);
   cout<<endl;
   Print(head);
   cout<<endl;
   deleteNode(2,head);
   Print(head);
}