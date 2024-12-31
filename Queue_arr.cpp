//************ Q2 *****************/

#include<iostream>
using namespace std;

class Queue
{   int size;
    int front;
    int rear;
    int *arr;
    public:
    Queue(int d)
    {   arr=new int[d];
        size=d;
        front=-1;
        rear=-1;
    }
    void Enqueue(int p);
    int dequeue();
    bool isEmpty();
    bool isFull();
    
};
void Queue:: Enqueue(int p)
{ 
    if(isFull())
    {
       cout<<"Queue is Full"<<endl;
    }
    else if(front==-1 && rear==-1)
 {
   front++;
   rear++;
   arr[front]=p;
   cout<<p<<" pushed in Queue."<<endl;
 }
  else{
    rear++;
    arr[rear]=p;
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
        int k=arr[front];
        front++;
        return k;
    }
}
bool Queue:: isEmpty()
{
    if(rear==-1)
    {
        //cout<<"Queue is Empty."<<endl;
        return 1;
    }
    else{
        return 0;
    }
            
}
bool Queue:: isFull()
{
   if(rear==size-1)
    {
       //cout<<"Queue is Full"<<endl;
       return 1;
    }
    else
    return 0;
}


int main()
{
   Queue q(5);
   q.dequeue();
   q.Enqueue(10);
   q.Enqueue(20);
   q.Enqueue(30);
   q.Enqueue(40);
   q.Enqueue(50);
   q.Enqueue(60);
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   q.Enqueue(70);
   q.Enqueue(80);


}
