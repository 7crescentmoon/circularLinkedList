#include <iostream>
using namespace std;
// double linked list to circular
struct CLL{ // struct

    int Number;
    CLL *next;
    CLL *prev;
};

CLL *first, *last, *cur, *add, *addLast, *afterNode, *after, *del;
//Deklarasi node awal 
void nodeawal(int Num){
    first = new CLL;
    first->Number = Num;
    first->prev = first;
    first->next = first;
    last = first;
}
//insert First
void insertFirst(int Num){
    add = new CLL;
    add->Number = Num;
    add->prev = last;
    add->next = first;
    first->prev = add;
    last->next = add;
    first = add;
}
//insert after
void insertAfter(int Num,int pos){
    after = new CLL;
    after->Number = Num;
    // transversing
    cur = first;
    int nomor = 1;
    while (nomor < pos - 1){
        cur = cur->next;
        nomor++;
    }
    afterNode = cur->next;
    after->prev = cur;
    after->next = afterNode;
    cur->next = after;
    afterNode->prev = after;
}
//insert last
void insertLast(int Num){
    addLast = new CLL;
    addLast->Number = Num;
    addLast->prev = last;
    addLast->next = first;
    last->next = addLast;
    first->prev = addLast;
    last = addLast;
}
//delete first
void delFirst(){
    CLL* p = first;
    first = p->next;
    p->next = NULL;
    p->prev = NULL;
    first->prev = last;
    last->next = first;
    delete del;
}
//delete after
void deleteAfter(int pos){
    int nomor = 1;
    cur = first;
    while (nomor < pos -1 ){
        cur = cur->next;
        nomor++;
    }
    del = cur->next;
    afterNode = del->next;
    cur->next = afterNode;
    afterNode->prev = cur;
    delete del;
}
//delete last
void delLast(){
    CLL* p = last;
    last = last->prev;
    p->prev = NULL;
    p->next = NULL;
    first->prev = last;
    last->next = first;
    delete del;
}
//search
int search(int key){
    CLL* p = first;
    int i = 1;
    while (p->Number != key){
        p = p->next;
        i++;
    }
    return i;
}
//print 
void print()
{
    cur = first;
    while (cur->next != first)
    {
        cout << cur->Number << " ";
        cur = cur->next;
    }
    cout << cur->Number << " ";
    cout << endl;
}

int main()
{
    nodeawal(7); //node awal
    print(); //print
    
    insertFirst(4); //insert first
    print(); //print
    
    insertFirst(5); //insert first
    print(); //print
    
    insertLast(10); //insert last
    print(); //print
    
    insertLast(8); //insert last
    print(); //print
    
    insertAfter(9,3); //insert after 
    print(); //print
    
    delFirst(); //delete first
    print(); //print
   
    deleteAfter(4); //delete after
    print(); //print
    
    delLast(); //delete last
    print(); //print

    int key; //key
    cout<<"masukkan data yang ingin dicari :"; //menginput key yg di cari
    cin>>key;
    cout<<"data "<< key << " diurutan ke - "<<search(key);  
}