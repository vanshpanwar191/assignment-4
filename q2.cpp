#include<iostream>
using namespace std;
class cq{
    int *arr;
    int front;
    int rear;
    int size;
    public:
      cq(int a){
          size=a;
          front=-1;
          rear=-1;
          arr=new int[size];
      }
      bool isfull(){
          return((rear+1)%size==front);
      }
      bool isempty(){
          return (front==-1);
      }
      void enqueue(int a){
          if(isfull()){
              cout<<"queue is full";
          }
          if(isempty()){
              front=rear=0;
          }
          else{
              rear=(rear+1)%size;
          }
          arr[rear]=a;
          cout<<"element enqueued";
      }
      void dequeue(){
          if(isempty()){
              cout<<"queue is empty";
          }
          int removed=arr[front];
          if(front==rear){
              front=rear=-1;
          }
          else{
              front=(front+1)%size;
          }
          cout<<removed<<"element removed";
      }
      void display(){
          if(isempty()){
              cout<<"queue is empty";
          }
          int i=front;
          while(true){
              
             cout<<arr[i];
             if(i==rear){
                 break;
             }
             i=(i+1)%size;
              
          }
          cout<<endl;
      }
      
};
int main(){
    int size;
    cout<<"enter the size of array:\n";
    cin>>size;
    cq c1(size);
    int choice;
    while(true){
        cout<<"----menu----"<<endl;
        cout<<"1.enqueue"<<endl;
        cout<<"2.dequeue"<<endl;
        cout<<"3.isfull"<<endl;
        cout<<"4.dequeue"<<endl;
        cout<<"5.display"<<endl;
        cout<<"enter the choice:\n";
        cin>>choice;
        switch(choice){
            case 1:{
                int a;
                cout<<"enter the element to enqueue:\n";
                cin>>a;
                c1.enqueue(a);
                break;
            }
            case 2:{
                c1.dequeue();
                break;
            }
            case 3:{
                if(c1.isfull()){
                    cout<<"queue is full";
                }
                else{
                    cout<<"queue is not full";
                }
                break;
            }
            case 4:{
                if(c1.isempty()){
                    cout<<"queue is empty";
                }
                else{
                    cout<<"queue is not empty";
                }
                break;
            }
            case 5:{
                c1.display();
                break;
            }
            case 6:{
                cout<<"exiting";
                break;
            }
            
        }
    }
    
}
