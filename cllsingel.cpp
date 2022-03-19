#include <iostream>
using namespace std;
// circular singel linked list

struct cll{ // struct
    int Number; 
    cll* next;
};

cll *first,*cur ,*del,*addBf,*after;

//Deklarasi Node awal
void Nodeawal(int Num){
    cll* p = new cll;
    p->Number = Num;
    first = p;
    p->next = first;
}
//insert first
void insertFirst(int Num){
    cll* add = new cll;
    add->Number = Num;
    cll* q = first;
    while (q->next != first ){
        q = q->next;
    }
    add->next = first;
    q->next = add;
    first = add;
}
//insert after
void insertafter(int Num , int pos){
    addBf = new cll;
    addBf->Number = Num;
    cur = first;
    Num = 1 ;
    while (Num < pos -1 ){
        cur = cur->next;
        Num++;       
    }
    addBf->next = cur->next;
    cur->next = addBf;   
}
//insert last
void insertLast(int Num){
    cll* add = new cll;
    add->Number = Num;
    cll* q = first;
    while (q->next != first ){
        q = q->next;
    } 
    add->next = first;
    q->next = add;
}
//delete first
void delFirst(){
    cll* del;
    cll* q = first;
    while (q->next != first){
        q = q->next;
    } 
    del = first;
    first = del->next;
    del->next = NULL;
    q->next = first;
    delete del;
}
//delete after
void delAfter(int pos){
 int nomor = 1;
    cur = first;
    while( nomor <= pos ){
      if( nomor == pos-1 ){
        after = cur;
      }
      if( nomor == pos ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    after->next = cur;
    delete del;
}
//delete last
void delLast(){
    cll* del;
    cll* q = first;
    while (q->next->next != first){
        q = q->next;
    } 
    del = q->next;
    q->next = first;
    del->next = NULL;
    delete del;
}
// search
int search(int key){
    cll* p = first;
    int i = 1;
    while (p->Number != key){
        p = p->next;
        i++;
    }
    return i;  
}
//print
void print(){
    cur = first;
    while (cur->next != first)
    {
        cout << cur->Number << " ";
        cur = cur->next;
    }
    cout << cur->Number << " ";
    cout << endl;
}
int main(){
    Nodeawal(9);//node awal
    print(); //print

    insertFirst(5);//insert first
    print(); //print

    insertFirst(7);//insert first
    print(); //print

    insertafter(6,2);//insertafter
    print(); //print

    insertLast(4);//insertLast
    print(); //print

    delFirst();//delFirst
    print(); //print

    delAfter(2);//delAfter
    print(); //print

    delLast();//delLast
    print(); //print

    int key;//key
    cout<<"masukkan data yang ingin dicari : ";//menginput key yang di cari
    cin>>key;
    cout<<"data "<<key<<" berada di posisi ke - "<<search(key);
}

