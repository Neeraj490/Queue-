//************ Q4 *****************/

#include<iostream>
using namespace std;
class node
{   public:
    int data;
    node *next;
    
    node(int d)
    {
       data=d;
       next=NULL;
    }
};
class Queue
{   //int size;
    node *front;
    node *rear;
    //node *arr;
    public:
    Queue()
    {   //arr=new node();
        //size=d;
        front=NULL;
        rear=NULL;
    }
    void Enqueue(int p);
    int dequeue();
    bool isEmpty();
    //bool isFull();
    
};
void Queue:: Enqueue(int p)
{ 
    
 if(isEmpty())
 {
   front=new node(p);
   rear=front;
   //arr[front]=p;
   cout<<p<<" pushed in Queue."<<endl;
 }
  else{
    rear->next=new node(p);
    rear=rear->next;
    cout<<p<<" pushed in Queue."<<endl;
  }
  return;
}
int Queue:: dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty."<<endl;
        return -1;
    }
    else{
        int k=front->data;
        node *temp=front;
        front=front->next;
        delete temp;
        return k;
    }
}
bool Queue:: isEmpty()
{
    if(rear==NULL)
    {
        //cout<<"Queue is Empty."<<endl;
        return 1;
    }
    else{
        return 0;
    }
            
}
int main()
{
   Queue q;
   q.dequeue();
   q.Enqueue(5);
   q.Enqueue(10);
   q.Enqueue(15);
   q.Enqueue(20);
   q.Enqueue(25);
   q.Enqueue(30);
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   q.Enqueue(35);
   q.Enqueue(40);


}
