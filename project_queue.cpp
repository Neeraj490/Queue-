//************ Q9 *****************/

#include<iostream>
using namespace std;

class patient
{   public:
    string name;
    int age;
    int condition;
    patient *next;

    patient(string a,int b,int c)
    {
        name=a;
        age=b;
        condition=c;
        next=NULL;
    }
};
class Queue
{   
    patient *frontN,*frontE;
    patient *rearN,*rearE;
   
    public:
    Queue()
    { 
        frontN=NULL,frontE=NULL;
        rearN=NULL,rearE=NULL;
    }
    void Enqueue(patient p);
    string dequeue();
    string peek();
    void wait();
    
};
void Queue::wait() {
    patient *temp=frontE;
    cout<< "Waiting patients in Emergency Queue: ";
    while(temp!=NULL) {
        cout<<temp->name<<" ";
        temp=temp->next; 
    }
    cout<<endl; 

    patient *temp1=frontN;
    cout <<"Waiting patients in Normal Queue: ";
    while(temp1 != NULL) {
        cout<<temp1->name<<" ";
        temp1=temp1->next; 
    }
    cout<<endl; 
}
string Queue:: peek()
{
    if(frontE!=NULL)
    {
        return frontE->name;
    }
    else{
        return frontN->name;
    }
}
void Queue:: Enqueue(patient p)
{ 
    if(p.condition==0)
    {
       if(frontN==NULL && rearN==NULL)
       {
         frontN=new patient(p);
         cout<<p.name<<" add in Normal patient Queue."<<endl;
         cout<<endl;
         rearN=frontN;
       }
       else{
        rearN->next=new patient(p);
        cout<<p.name<<" add in Normal patient Queue."<<endl;
        cout<<endl;
        rearN=rearN->next;
        }
    }
    else if(p.condition==1)
    {
       if(frontE==NULL && rearE==NULL)
       {
         frontE=new patient(p);
         cout<<p.name<<" add in Emergency patient Queue."<<endl;
         cout<<endl;
         rearE=frontE;
       }
       else{
        rearE->next=new patient(p);
        cout<<p.name<<" add in Emergency patient Queue."<<endl;
        cout<<endl;
        rearE=rearE->next;
       }
    }
    return;

}
string Queue:: dequeue()
{   string name;
    if(frontE==NULL && frontN==NULL)
    {
       return "no patient";
    }
    else if(frontE==NULL)
    {
        patient *k=frontN;
           name=k->name;
        frontN=frontN->next;
        delete k;
        return name+" from Normal Queue ";
    }
    else
    {
        patient *k=frontE;
        name=k->name;
        frontE=frontE->next;
        delete k;
        return name+" from Emergency Queue ";
    }
    
}
int main()
{  
    
   Queue q;
    //Normal-0    Emergency-1
   patient p1("pradeep",19,0);
   q.Enqueue(p1);
   patient p2("aditya",20,1);
   q.Enqueue(p2);
   patient p3("adarsh",18,1);
   q.Enqueue(p3);
   patient p4("prashant",23,0);
   q.Enqueue(p4);
   patient p5("ajay",22,1);
   q.Enqueue(p5);
   patient p6("mohit",15,0);
   q.Enqueue(p6);
   patient p7("aman",10,1);
   q.Enqueue(p7);
   cout<<"treated "<<q.dequeue()<<endl;
   cout<<"treated "<<q.dequeue()<<endl;
   cout<<endl;
   
   q.wait();
   
   cout<<"treated "<<q.dequeue()<<endl;
   cout<<"treated "<<q.dequeue()<<endl;
   cout<<endl;
   
   cout<<"Next patient is "<<q.peek()<<endl;
   cout<<endl;
   
   cout<<"treated "<<q.dequeue()<<endl;
   cout<<"treated "<<q.dequeue()<<endl;
   cout<<"treated "<<q.dequeue()<<endl;
}  
