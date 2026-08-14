/*
an online shop keep its product catalog sorted by product id(whole number) in assending order.
when a customer search for a specific product id the system return true if the product id present in the catalog
else it returns false,which searchin techinque to find the product id quickly from the catalog
implement the searching method uding a function,the function takes parameter product id list,size of the list and 
product id to be search
     

sample input:[2,8,9,16,18,26,38,48,51,90]
case1:product id to be reached:49
case 2:product id to be searche:26

*/
#include <stdio.h>
#include<stdbool.h>

bool binarySearch(int arr[],int size, int target)
{
    int low = 0;
    int high = size- 1;
   // int count=0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
         if(arr[mid]==target){
           return true;  
         }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
if(true){
    return true;
}
else{
    return false;
}
}

int main()
{
     int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
     }
     int target;
     scanf("%d",&target);
     if(binarySearch(arr,n,target)){
        printf("true");
     }else{
        printf("false");
     }

    return 0;
}