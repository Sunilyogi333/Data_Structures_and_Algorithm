#include<iostream>
using namespace std;
class stack{
    private:
    int top;
    int item[10];
    public:
    stack(){
        top = -1;
    }
    void push(int d){
        if(top==9){
            cout<<"Stack is full"<<endl;
        }
        else
        {
            top++;
            item[top]=d;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Deleted item is:"<<item[top--]<<endl;
        }
    }
    void display(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"The elements in stack are:"<<endl;
            for(int i =0; i<=top; i++){
                cout<<item[i]<<endl;
            }
        }
    }
};
int main(){
    stack S;
    S.display();
    S.push(2);
    S.push(4);
    S.push(6);
    S.display();
    S.pop();
    S.pop();
    S.pop();
    S.display();
    return 0;
}

