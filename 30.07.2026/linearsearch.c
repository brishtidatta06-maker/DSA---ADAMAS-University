/*
in a linrary the books are sorteds using their acc no.Acc is the whole number
that consist 3 digit maximum.consider an array where the books are stored in an unorganised way.
The librarian want to search for a specific access number in the array.which searching methodology 
the librarian must be used.write the programe to implement this subject technique

*/
#include<stdio.h>
int main(){
    int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int acc[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
      scanf("%d",&acc[i]);
     }
     int target;
     scanf("%d",&target);
     linearsearch(acc,n,target);
    return 0;
}
void linearsearch(int arr[],int n,int target){
   int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
         count++;
        }
    }
    if(count==1){
        printf("The book is avilable in this library");
    }
    else{
            printf("The book is not avilable in this library");
    }
}