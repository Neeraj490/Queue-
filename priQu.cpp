//************ Q6 *****************/

#include<iostream>
using namespace std;
class node
{   public:
    int data, pri;
    node *next;
    
    node(int d,int p)
    {
       data=d;
       pri=p;
       next=NULL;
    }
};
class Queue
{   
    node *front;
    node *rear;
    
    public:
    Queue()
    {   
        front=NULL;
        rear=NULL;
    }
    void Enqueue(int p,int q);
    int dequeue();
    bool isEmpty();
    
    
};
void Queue:: Enqueue(int p,int q)
{ 
    
 if(isEmpty())
 {
   front=new node(p,q);
   rear=front;
   cout<<p<<" pushed in Queue."<<endl;
 }
  else{
    
      node *tail=new node(p,q);
       node *temp=front;
      while(temp->next!=NULL)
      {  node *temp1=temp->next;
        if(temp->pri<q)
        {
         tail->next=temp;
         front=tail;
         cout<<p<<" pushed in Queue."<<endl;
         return;
        }
        else if(temp->pri>q && temp1->pri<q)
        {
            temp->next=tail;
            tail->next=temp1;
            cout<<p<<" pushed in Queue."<<endl;
            return;
        }
        temp=temp->next;
      }
      if(temp->pri<q)
        {
         tail->next=temp;
         front=tail;
         cout<<p<<" pushed in Queue."<<endl;
        }

      else{temp->next=tail;
      rear=tail;
      cout<<p<<" pushed in Queue."<<endl;
      }
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
   q.Enqueue(5,1);
   q.Enqueue(40,8);
   q.Enqueue(15,3);
   q.Enqueue(30,6);
   q.Enqueue(25,5);
   q.Enqueue(20,4);
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   q.Enqueue(35,7);
   q.Enqueue(50,9);
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;

}
