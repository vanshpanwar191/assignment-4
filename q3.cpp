#include<iostream>
using namespace std;
class interleave{
    int *arr;
    int size;
    int front;
    int rear;
    public:
      interleave(int a){
          size=a;
          arr=new int[size];
          rear=-1;
          front=-1;
      }
      bool isfull(){
          return (rear==size-1);
      }
      bool isempty(){
          return (rear==-1);
      }
      void enqueue(int a){
          if(isfull()){
              cout<<"queue is full;";
          }
          if(isempty()){
              front=rear=0;
          }
          else{
              rear++;
          }
          arr[rear]=a;
          
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
              front++;
          }
          cout<<"element removed is "<<removed;
      }
      void peek(){
          if(isempty()){
              cout<<"queue is empty";
          }
          else{
              cout<<arr[front];
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
void  get(int *arr,int size){
    
     int*arr1;
     int *arr2;
     interleave q1(size);
     int t=size/2;
     arr1=new int[t];
     arr2=new int[t];
     for(int i=0;i<t;i++){
         arr1[i]=arr[i];
     }
     for(int i=0;i<t;i++){
             arr2[i]=arr[i+t];
         }
     
     int i=0;
     while(i<t){
         q1.enqueue(arr1[i]);
         q1.enqueue(arr2[i]);
     }
     q1.display();
}
int main(){
    int size;
    cout<<"enter the size:\n";
    cin>>size;
    int*arr=new int[size];
    cout<<"enter the even numbere array:\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    get(arr,size);
    
    
} 
