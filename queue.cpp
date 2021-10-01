// Akhil S S
#include<iostream>
using namespace std;

template<class T>
class QueueType{
 protected:
  int maxSize;
  int count;
  int Qfront;
  int Qrear;
  T *list;
 
 public:
  bool empty();
  bool full();
  void print();
  T front();
  T rear();
  bool insert(T);
  bool remove();
  QueueType(int);
  ~QueueType();
};

//----------Constructor
template<class T>
QueueType<T>::QueueType(int size){
 if(size<0){
  cout<<"invalid Entry!!\nInitializing the queue size to 10\n";
  maxSize=10;
 }
 else
  maxSize=size;
 Qfront=0;
 Qrear=maxSize-1;
 count=0;
 list= new T[maxSize];
}

//-------Distructor
template<class T>
QueueType<T>::~QueueType(){
 delete []list;
}

//---------Is Empty
template<class T>
bool QueueType<T>::empty(){
 if(count==0)
  return true;
 else
  return false;
}

//---------Is Full
template<class T>
bool QueueType<T>::full(){
 if(count==maxSize)
  return true;
 else
  return false;
}

//---Print
template<class T>
void QueueType<T>::print(){
 if(count==0){
  cout<<"Queue is empty...\n";
  return;
 }
 for(int i=Qfront; i<=Qrear; i=(i+1)%maxSize){
  cout<<"\t"<<list[i];
 }
}

//------Front
template<class T>
T QueueType<T>::front(){
 if(count==0)
  cout<<"Queue is Empty..\n";
 else
  return list[Qfront];
}

//-----Back
template<class T>
T QueueType<T>::rear(){
 if(count==0)
  cout<<"Queue is Empty..\n";
 else
  return list[Qrear];
}

//--- Insert
template<class T>
bool QueueType<T>::insert(T ele){
 if(count==maxSize)
  return false;
 else{
  Qrear=(Qrear+1)%maxSize;
  count++;
  list[Qrear]=ele;
  return true;
 }  
}

//-------Delete
template<class T>
bool QueueType<T>::remove(){
 if(count==0)
  return false;
 else{
  count--;
  Qfront=(Qfront+1)%maxSize;
  return true;
 }
}

int main(){
 QueueType<int> Q(10);
 int ch, n=1;
 while(n){
  cout<<endl<<"Enter Operation: \n";
  cout<<"\t 1. Insert\n";
  cout<<"\t 2. Delete\n";
  cout<<"\t 3. Front\n";
  cout<<"\t 4. Rear\n";
  cout<<"\t 5. Is Full\n";
  cout<<"\t 6. Is Empty\n";
  cout<<"\t 7. Print\n";
  cout<<"Enter your Choise: ";
  cin>>ch;
  
  switch(ch){
   case 1:
    int ele;
    cout<<"Enter Element to Insert: ";
    cin>>ele;
    if(Q.insert(ele))
     cout<<"Element Added Successfully...\n";
    else
     cout<<"Queue is full\n";
    break;
   
   case 2:
    if(Q.remove())
     cout<<"Element Removed Sucessfully...\n";
    else
     cout<<"Queue is Empty...\n";
    break;
    
   case 3:
    cout<<"The Front Element is : "<<Q.front();
    break;
   
   case 4:
    cout<<"The Rear Element is : "<<Q.rear();
    break;
    
   case 5:
    if(Q.full())
     cout<<"Queue is full\n";
    else
     cout<<"Queue is not full\n";
    break;
    
   case 6:
    if(Q.empty())
     cout<<"Queue is Empty..\n";
    else
     cout<<"Queue is not Empty..\n";
    break;
   
   case 7:
    cout<<"Queue Elements are : ";
    Q.print();
    break;
   
   default:
    n=0;
    break;
  }
 }
 return 0;
}
