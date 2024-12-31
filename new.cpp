#include<iostream>
using namespace std;
class queue
{  public:
    int *data;
    int size;
    int first;
    int last;
    queue(int s)
    {
      size=s;
      data=new int[s];
      first=-1;
      last=-1;
    }
    void Enqueue(int a)
    {
        if(last==-1)
        {   last++;
            first++;
            data[last]=a;
            return ;
        }
        last++;
        data[last]=a;
        return;

    }
};

int main()
{
   queue q(5);
   q.Enqueue(10);
   q.Enqueue(10);
   q.Enqueue(10);
   q.Enqueue(10);
}