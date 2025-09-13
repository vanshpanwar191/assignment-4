#include<iostream>
using namespace std;
class queue{
    int *arr;
    int size;
    int rear;
    int front;
    public:
      queue(int a){
          size=a;
          arr=new int[size];
          rear=-1;
          front=0;
      }
      bool isfull(){
          if(rear==size-1&&front==0)
            return true;
          else
            return false;
      }
      bool isempty(){
          if(rear==-1&&front==0){
              return true;}
          else{
              return false;
          }
      }
      void enqueue(int a){
          if(isfull()){
              cout<<"queue is full";
          }
          else{
              arr[++rear]=a;
          }
      }
      void dequeue(){
          if(isempty()){
              cout<<"queue is empty";
          }
          else{
              cout<<"element dequeued is:\n"<<arr[front];
              front++;
          }
      }
      void peek(){
          if(isempty()){
              cout<<"queue is empty";
          }
          else{
              cout<<"elemnt at top is: "<<arr[front];
          }
      }
      void display(){
          if(isempty()){
              cout<<"queue is empty";
          }
          else{
              for(int i=front;i<=rear;i++){
                  cout<<arr[i]<<" ";
              }
          }
      }
};
int main(){
    int size;
    cout<<"enter the size of the queue:\n";
    cin>>size;
    queue q(size);
    int choice;
    while (true){
        cout<<"------MENU------"<<"\n";
        cout<<"1.enqueue"<<"\n";
        cout<<"2.dequeue"<<"\n";
        cout<<"3.peek"<<"\n";
        cout<<"4.isfull"<<"\n";
        cout<<"5.isempty"<<"\n";
        cout<<"6.display"<<"\n";
        cout<<"7.exit"<<"\n";
        cout<<"enter your choice:\n";
        cin>>choice;
        switch(choice){
            case 1:{
                int a;
                cout<<"enter the number:\n";
                cin>>a;
                q.enqueue(a);
                break;
            }
            case 2:{
                q.dequeue();
                break;
            }
            case 3:{
                q.peek();
                break;
            }
            case 4:{
                if(q.isfull()){
                    cout<<"queue is full";
                }
                else{
                    cout<<"queue is not full";
                }
                break;
            }
            case 5:{
                if(q.isempty()){
                    cout<<"queue is empty";
                }
                else{
                    cout<<"queue is not empty";
                }
                break;
            }
            case 6:{
                q.display();
                break;
            }
            case 7:{
                cout<<"exiting..";
                break;
            }
            default:
             cout<<"enter valid choice";
             break;
            
        }
        
    }
    
}
