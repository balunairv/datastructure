#include<iostream>
#include "stack.h"

using namespace std;


int main(){
    StackType<char>* stack;
    int length;
    string s;
    cout << "enter the string" << endl;
    cin >> s;
    stack = new StackType<char>(s.length());
    cout << s.length() << endl;
    for(int i=s.length()-1; i>=0;i--){
        cout << s[i] << endl;
        stack->push(s[i]);
    }
   stack->print();
   delete stack;
   return 0;
}
