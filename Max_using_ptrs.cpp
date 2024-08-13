//Finding the biggest element in the Arrays using pointers as well as sorting it 
//sorting in the decending order
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,54,3,4,72,62,85};
    int* ptr;
    ptr = arr;
    int size = sizeof(arr)/sizeof(arr[0]);

    int max =ptr[0];
    int temp =0;
    for(int i =0;i<size-1;i++){
        if(ptr[i]>ptr[i+1]){
            max = ptr[i];
            temp = ptr[i];
            ptr[i] = ptr[i+1];
            ptr[i+1] = temp;
        }
    }
    
    for(int i =0;i< size;i++){
        cout<<ptr[i]<<" ";
    }
    int fin =0;
    if(ptr[size-1]>ptr[size]){
        fin = ptr[size-1];
    }
    else{
        fin = ptr[size];
    }

    cout <<"\n";
    cout<<"the max nuym in the array is "<<fin;
   
//     cout<<ptr[sizeof(arr)/sizeof(arr[0])]<<" ";
//      temp = 0;


//     cout<<"printing the arr in reverse using ptrs  ";
//    int i =0,j = sizeof(arr)/sizeof(arr[0]);

//    while(i< sizeof(arr)/sizeof(arr[0])){
//         if(ptr[i]<ptr[j]){
//             temp = ptr[i];
//             ptr[i] = ptr[i+1];
//             ptr[i+1] = temp;
//             i++;
//             j--;
//         }
//         else{
//             i++;
//         }
//    }
//     cout<<ptr[0];

}


