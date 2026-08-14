/*
A class teacher list of marks in random order all the marks are whole number before publishing the result the class teacher 
wants to arrange the marks in an order so that the rank of the student can easily be dected.use a method to order the marks
 in assending order,which methodology you used here implement the method using c program

 sample input:[99,85,58,71,46,80,78,65,49,55]
 case 1:
*/
#include<stdio.h>
int main(){

     int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
     }
     bubble_sort(arr,n);
    return 0;
    
}
void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)
        if(arr[j]>arr[j+1]){
            swap(j,j+1,arr);
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int i,int j,int arr[]){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}