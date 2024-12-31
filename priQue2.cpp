//************ Q7 *****************/


#include<iostream>
using namespace std;

class Queue
{   int sizeh,sizem,sizel;
    //int size;
    int fronth,frontm,frontl;
    int rearh,rearm,rearl;
    int *high;
    int *mid;
    int *low;
    public:
    Queue(int a,int b,int c)
    {   high=new int[a];
        mid=new int[b];
        low=new int[c];
        sizeh=a,sizem=b,sizel=c;
        fronth=-1,frontm=-1,frontl=-1;
        rearh=-1,rearm=-1,rearl=-1;
    }
    void Enqueue(int p,int q);
    int dequeue();
    bool isEmpty(int q);
    bool isFull(int q);
    
};
void Queue:: Enqueue(int p,int q)
{ if(q==2)
   { if(isFull(q))
    {
       cout<<"high Queue is Full"<<endl;
    }
    else if(fronth==-1 && rearh==-1)
 {
   fronth++;
   rearh++;
   high[fronth]=p;
   rearh++;
   cout<<p<<" pushed in high Queue."<<endl;
   cout<<endl;
 }
  else{
    high[rearh]=p;
    rearh++;
    cout<<p<<" pushed in high Queue."<<endl;
    cout<<endl;
  }
  return;
   }
   else if(q==1)
   { if(isFull(q))
    {
       cout<<" mid Queue is Full"<<endl;
    }
    else if(frontm==-1 && rearm==-1)
 {
   frontm++;
   rearm++;
   mid[frontm]=p;
   rearm++;
   cout<<p<<" pushed in midium Queue."<<endl;
   cout<<endl;
 }
  else{
    mid[rearm]=p;
    rearm++;
    cout<<p<<" pushed in midium Queue."<<endl;
    cout<<endl;
  }
  return;
   }
  else if(q==0)
   { if(isFull(q))
    {
       cout<<"low Queue is Full"<<endl;
    }
    else if(frontl==-1 && rearl==-1)
 {
   frontl++;
   rearl++;
   low[frontl]=p;
   rearl++;
   cout<<p<<" pushed in low Queue."<<endl;
   cout<<endl;
 }
  else{
    //rearl++;
    low[rearl]=p;
    rearl++;
    cout<<p<<" pushed in low Queue."<<endl;
    cout<<endl;
  }
  return;
   }
 }
int Queue:: dequeue()
{   int k;
    if(fronth!=rearh)
    {
        k=high[fronth];
        fronth++;
        return k;
    }
    else if(frontm!=rearm)
    {
        k=mid[frontm];
        frontm++;
        return k;
    }
    else if(frontl!=rearl)
    {
      k=low[frontl];
        frontl++;
        return k;
    }
    else
    {
       cout<<"Queue is Empty."<<endl;
       return -1;
    }
    
}
bool Queue:: isEmpty(int q)
{   if(q==2)
    {if(rearh==-1) 
    {
        //cout<<"high Queue is Empty."<<endl;
        return 1;
    }
    else{
        return 0;
    }
    }
    else if(q==1)
    {if(rearm==-1) 
    {
        //cout<<"mid Queue is Empty."<<endl;
        return 1;
    }
    else{
        return 0;
    }
    }
   else if(q==0)
    {if(rearl==-1) 
    {
        //cout<<"low Queue is Empty."<<endl;
        return 1;
    }
    else{
        return 0;
    }
    } 
    return 0;      
}
bool Queue:: isFull(int q)
{  if(q==2)
   {if(rearh==sizeh-1) 
    {
       //cout<<"high Queue is Full"<<endl;
       return 1;
    }
    else
    return 0;
   }
   else if(q==1)
   {if(rearm==sizem-1) 
    {
       //cout<<"mid Queue is Full"<<endl;
       return 1;
    }
    else
    return 0;
   }
   else if(q==0)
   {if(rearl==sizel-1) 
    {
       //cout<<"low Queue is Full"<<endl
       return 1;
    }
    else
    return 0;
   }
   return 0;
}
int main()
{
   Queue q(5,5,5);
   q.dequeue();
   // 0-low priority  1-medium priority  2-high priority
   q.Enqueue(10,0);
   q.Enqueue(20,2);
   q.Enqueue(30,0);
   q.Enqueue(40,1);
   q.Enqueue(50,2);
   q.Enqueue(60,0);
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;
   q.Enqueue(70,1);
   q.Enqueue(80,2);
   cout<<"Pooped "<<q.dequeue()<<endl;
   cout<<"Pooped "<<q.dequeue()<<endl;

}
