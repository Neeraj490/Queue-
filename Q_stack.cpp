//************ Q8 *****************/


#include<iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
struct stack
{  private:
   struct node *top;
   public:
   stack()
   {
    top=NULL;
   }
   void push(int p);
   int pop();
   int peek();
   bool isEmpty();
};
bool stack::isEmpty()
{
    if(top==NULL)
    {
        //cout<<"stack is Empty\n";
        return 1;
    }
    //cout<<"stack is not empty\n";
    return 0;
}
int stack::peek()
{
    return top->data;
}
int stack::pop()
{
    if(top==NULL)
    {
        cout<<"stack is empty\n";
        return -1;
    }
    int d=top->data;
    node *temp=top;
    top=top->next;
    delete temp;
    return d;
}
void stack::push(int p)
{
    node *temp=new node();
    temp->data=p;
    temp->next=top;
    top=temp;
    //cout<<"element "<<p <<" pushed.\n";
}
void Enqueue(int a, stack *s)
{ 
     s->push(a);
     cout<<a<<" pushed in Queue."<<endl;
     return;
}
int dequeue(stack *s2,stack *s3)
{    int k,t;
     while(!s2->isEmpty())
     {
        k=s2->peek();
        s2->pop();
        s3->push(k);
     }
     t=s3->pop();
     while(!s3->isEmpty())
     {
        k=s3->peek();
        s3->pop();
        s2->push(k);
     }
     return t;
     
}

int main()
{
    struct stack s,s1;
    Enqueue(4,&s);
    Enqueue(5,&s);
    Enqueue(6,&s);
    Enqueue(7,&s);
    Enqueue(8,&s);
    Enqueue(9,&s);
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    Enqueue(7,&s);
    Enqueue(8,&s);
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    cout<<"Pooped "<<dequeue(&s,&s1)<<endl;
    
    
}