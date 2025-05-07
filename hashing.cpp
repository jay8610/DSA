#include <iostream>
using namespace std;

class HashTable{

public:
int key;
int index;

};

class Hashing
{
 private:
 HashTable H[10];
 public:

 Hashing(){

 for(int i=0;i<10;i++)
 {
 H[i].key=-1;
 H[i].index=i;
 }
 }

  void display();
  void insert(int p_ch);
  int LinearP(int position);
  int QuadraticP(int position);
};

void Hashing::display()
{
  cout<<"Hash Table is"<<endl;
  for(int i=0;i<10;i++)
  {
     cout<<H[i].key<<"\t\t\t\t\t"<<H[i].index<<endl;

  }

}

void Hashing::insert(int p_ch)
{
 int pos;
 int key1;

 cout<<"Enter the Telephone number\n";
 cin>>key1;
 pos=key1%10;

 if(H[pos].key==-1)
 {
  H[pos].key=key1;
 }
 else if(p_ch==1){
 int temp=LinearP(pos);
 H[temp].key=key1;
 }
 else if(p_ch==2){
 int temp=QuadraticP(pos);
 H[temp].key=key1;
 }
}

int Hashing::LinearP(int position) {
     for (int i = 0; i < 10; i++) {
          int newPos = (position + i) % 10;
          if (H[newPos].key == -1) {
              return newPos;
          }
     }
     return -1;
}


int Hashing::QuadraticP(int position) {
     for (int i = 0; i < 10; i++) {
          int newPos = (position + (i * i)) % 10;
          if (H[newPos].key == -1) {
              return newPos;
          }
     }	
     return -1;
}


int main(){

Hashing obj;
int ch;
int p_choice;

do{
  cout<<"----MENU----\n";
  cout<<"1. Insert\n";
  cout<<"2. Display\n";
  cout<<"3. Exit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  if(ch==1){
  cout<<"Enter the probing choice\n1. Linear Probing\n2. Quadratic Probing\n";
  cin>>p_choice;
  }
  else{
  p_choice=0;
  }
  switch(ch){
  case 1:
  {
    obj.insert(p_choice);
    break;
  }
  case 2:
  {
  obj.display();
  break;
  }
  case 3:
  {
       cout<<"End of program";
       break;
  }
  default:
  {
  cout<<"Enter valid choice :\n";
  }
  }

}while(ch!=3);

}