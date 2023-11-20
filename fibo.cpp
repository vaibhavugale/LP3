#include<iostream>
using namespace std;


int fiboR(int number){
    if(number==1) return 1;
    if(number==0) return 0;

    return fiboR(number-1) + fiboR(number-2);

}
int fibo(int number){
   int a = 0;
   int b = 1;
   int result;
   for(int i=2;i<=number;i++){
       int temp = b;
        result =  a+b;
        b = result;
        a = temp;
   };

   return result;
}

int main(){

//    cout<<fiboR(5);
   cout<<fibo(12)<<" ";

    return 0;
}