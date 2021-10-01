#include<iostream>
#include<stdlib.h>
using namespace std;
template<class type>
struct nodetype
{
type info;
nodetype<type> *link;
};
template<class type>
class linkedlist
{
protected:
nodetype<type>*head;
public:
linkedlist();
void initilize();
void insertfirst(const type &newitem);
void insertat(int loc,const type &newitem);
void insertend(const type& newitem);
void deletefirst();
void deleteat(int loc);
void deleteend();
bool search(const type &searchitem);
void print()const;
};
template<class type>
void linkedlist<type>::initilize()
{
nodetype<type>*temp;
while(head!=NULL)
{
temp=head;
head=head->link;
delete temp;
}
}
template<class type>
linkedlist<type>::linkedlist()
{
head=NULL;
}
template<class type>
void linkedlist<type>::insertfirst(const type &newitem)
{
nodetype<type>*newnode;
newnode=new nodetype<type>;
newnode->info=newitem;
newnode->link=head;
head=newnode;
}
template<class type>
void linkedlist<type>::insertat(int loc,const type& newitem)
{
nodetype<type>*current;
nodetype<type>*newnode;
newnode=new nodetype<type>;
newnode->info=newitem;
current=head;
if(loc==1)
{
newnode->link=head;
head=newnode;
return;
}
for(int i=1;i=loc-1;i++)
{
if(current->link==NULL)
{
cout<<"less element in the list"<<endl;
return;
}
current=current->link;
}
newnode->link=current->link;
current->link=newnode;
}
template<class type>
void linkedlist<type>::insertend(const type&newitem)
{
nodetype<type>*current;
nodetype<type>*newnode;
newnode=new nodetype<type>;
newnode->info=newitem;
if(head=NULL)
{
newnode->link=NULL;
head=newnode;
}
else
{
current=head;
while(current->link!=NULL)
{
current=current->link;
}
newnode->link=NULL;
current->link=newnode;
}
}
template<class type>
void linkedlist<type>::deletefirst()
{
nodetype<type>*newnode;
newnode=head;
head=head->link;
delete newnode;
}
template<class type>
void linkedlist<type>::deleteat(int loc)
{
nodetype<type>*current;
nodetype<type>*trailcurrent;
current=head;
trailcurrent=head;
if(head==NULL)
{
cout<<"empty list!!!! cannot delete"<<endl;
return;
}
if(loc==1)
{
head=head->link;
delete current;
return;
}
for(int i=1;i<loc;i++)
{
if(current==NULL)
{
cout<<"less elements in the list"<<endl;
return;
}
trailcurrent=current;
current=current->link;
}
trailcurrent->link=current->link;
delete current;
}
template<class type>
void linkedlist<type>::deleteend()
{
nodetype<type>*current;
nodetype<type>*trailcurrent;
current=head;
trailcurrent=head;
if(head=NULL)
{
cout<<"empty list!!! cannot delete"<<endl;
return;
}
while(current->link!=NULL)
{
trailcurrent=current;
current=current->link;
}
trailcurrent->link=current->link;
delete current;
}
template<class type>
bool linkedlist<type>::search(const type &searchitem)
{
nodetype<type>*current;
bool found=false;
current=head;
while(current!=NULL&&! found)
{
if(current->info=searchitem)
{
found=true;
}
else
current=current->link;
}
return found;
}
template<class type>
void linkedlist<type>::print()const
{
nodetype<type>*current;
if(head==NULL)
{
cout<<"list is empty"<<endl;
return;
}
current=head;
while(current!=NULL)
{
cout<<current->info<<" ";
current=current->link;
}
}



int main()
{
linkedlist<int>l;
int ch;
while(1){
cout<<"\n 1.insert first"<<endl;
cout<<"\n 2.insert at"<<endl;
cout<<"\n 3.insert end"<<endl;
cout<<"\n 4.delete first"<<endl;
cout<<"\n 5.delete at"<<endl;
cout<<"\n 6.delete end"<<endl;
cout<<"\n 7.search"<<endl;
cout<<"\n 8.print"<<endl;

cout<<"enter the choise"<<endl;
cin>>ch;
switch(ch)
{
int item,loc;
case 1:
cout<<"enter the element to insert:"<<endl;
cin>>item;
l.insertfirst(item);
break;
case 2:
cout<<"enter the element to insert:"<<endl;
cin>>item;
cout<<"enter the location to insert:"<<endl;
cin>>loc;
l.insertat(loc,item);
break;
case 3:
cout<<"enter the element to insert:"<<endl;
cin>>item;
l.insertend(item);
break;
case 4:
l.deletefirst();
break;
case 5:
cout<<"enter the location to delete:"<<endl;
cin>>loc;
l.deleteat(loc);
break;
case 6:
l.deleteend();
break;
case 7:
cout<<"enter the search element:"<<endl;
cin>>item;
if(l.search(item))
cout<<"element is found"<<endl;
else
cout<<"element is not found"<<endl;
break;
case 8:
l.print();
break;

default:
cout<<"invalid entery!!!!"<<endl;
exit(0);
}
}
return 0;
}
