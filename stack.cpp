#include<iostream>
using namespace std;
template<class Type>
class stackType
{
protected:
Type *list;
int stackTop;
int maxSize;
public:
bool stackEmpty();
bool stackFull();
bool push(Type newItem);
bool pop();
Type top();
void print();
stackType (int size=10);
};
//-------------stackEmpty-----------------//
template<class Type>
bool stackType<Type> :: stackEmpty()
{
if(stackTop==0)
return true;
else
return false;
}
//-------------stackFull----------------//
template<class Type>
bool stackType<Type> :: stackFull()
{
if(stackTop==maxSize)
return true;
else
return false;
}
//-----------------push---------------//
template<class Type>
bool stackType<Type> :: push(Type newItem)
{
if(stackTop==maxSize)//Check stack is full
return false;
else
{
list[stackTop]=newItem;
stackTop++;
return true;
}
}
//----------------pop-----------------//
template<class Type>
bool stackType<Type> :: pop()
{
if(stackTop==0)//Check stack is Empty
return false;
else
{
stackTop--;
return true;
}
}
//----------------top-----------------//
template<class Type>
Type stackType<Type> :: top()
{
if(stackTop==0)//Check stack is Empty
cout<<"Stack is Empty"<<endl;
else
{
return list[stackTop-1];
}
}
//---------------print---------------//
template<class Type>
void stackType<Type> :: print()
{
for(int i=0;i<stackTop;i++)
cout<<list[i]<<endl;
}
//--------------constructor----------------//
template<class Type>
stackType<Type> :: stackType(int size)
{
if(size<0)
{
cout<<"The stack size must be positive";
cout<<"Creating an array of size 10"<<endl;
maxSize=10;
}
else
{
maxSize=size;
stackTop=0;
}
list=new Type[maxSize];
}
int main()
{
stackType<int>l;
int ch;
while(1)
{
cout<<" List Elements "<<endl;
cout<<"1.stackEmpty"<<endl;
cout<<"2.stackFull"<<endl;
cout<<"3.Push"<<endl;
cout<<"4.Pop"<<endl;
cout<<"5.Top"<<endl;
cout<<"6.Print"<<endl;
cout<<"7.Quit"<<endl;
cout<<"Enter Choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
if(l.stackEmpty())
cout<<"Stack is Empty"<<endl;
else
cout<<"Stack is not Empty"<<endl;
break;
case 2:
if(l.stackFull())
cout<<"Stack is Full"<<endl;
else
cout<<"Stack is not Full";
break;
case 3:
int newItem;
cout<<"Element to push:";
cin>>newItem;
l.push( newItem);
break;
case 4:
l.pop();
break;
case 5:
cout<<"Top element is "<<l.top()<<endl;
break;
case 6:
cout<<"The Stack elements:"<<endl;
l.print();
break;
case 7:
cout<<"Exiting....."<<endl;
exit(0);
break;
default:
cout<<"Invalid choice!!!"<<endl;
}
}
return(0);
}
