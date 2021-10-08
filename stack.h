using namespace std;

template<class T>
class StackType{
protected:
    int maxSize;
    T *list;
    int stackTop;
public:
    bool push(T item);
    bool pop();
    T* top();
    bool isStackEmpty();
    bool isStackFull();
    void print();
    StackType(int size);
    ~StackType();
    
    
};


template<class T>
StackType<T>::StackType(int size){
    if(size < 0){
        cout << "stack is intializing with the size 10"<< endl;
        maxSize = 10;
        }
    else{
        cout << "stack is intializing with the size " << size << endl;
        maxSize = size;
        }
    list = new T[maxSize];
    stackTop = 0;
    cout << endl;
    
}

template<class T>
StackType<T>::~StackType(){
    delete[] list;
    cout << "deleting stack" << endl;
}

template<class T>
bool StackType<T>::push(T item){
    if(stackTop == maxSize)
       return false;
    else{
        list[stackTop] = item;
        stackTop++;
        return true;
        }
}

template<class T>
bool StackType<T>::pop(){
    if(stackTop == 0)
        return false;
    else{
        stackTop--;
        return true;
    }
}

template<class T>
void StackType<T>::print(){
    if(stackTop == 0)
        cout << "Empty stack" << endl;
    else{
        for(int i=0;i<stackTop;i++)
            cout << list[i] << " ";
        cout << endl;
    }
   

}


template<class T>
bool StackType<T>::isStackEmpty(){
   return stackTop == 0 ? true : false;
}

template<class T>
bool StackType<T>::isStackFull(){
   return stackTop == maxSize ? true : false;
}

template<class T>
T* StackType<T>::top(){
    if(stackTop == 0){
        //cout << "stack is empty" << endl;
        return NULL;
     }
    else
        return &list[stackTop - 1];
}
