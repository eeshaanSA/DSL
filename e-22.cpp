/*
E-22
minheap and maxheap
find the max and min marks of student obtained in a particular exam 
*/
#include<iostream>
using namespace std;

//minheap
void minInsert(int arr[], int i)
{
    int parent = (i-1)/2;
    int curr = i;
    while(parent >= 0 && arr[parent] > arr[curr])
    {
        swap(arr[parent],arr[curr]);
        curr = parent;
        parent = (curr-1)/2;
    }
}
//maxheap
void maxInsert(int arr[], int i)
{
    int parent = (i-1)/2;
    int curr = i;
    while(parent >= 0 && arr[parent] < arr[curr])
    {
        swap(arr[parent],arr[curr]);
        curr = parent;
        parent = (curr-1)/2;
    }
};

int main()
{
    int arr[] = {20, 30, 15, 2, 5, 10};
    for( int i = 0; i<6 ; i++)
    {
        minInsert(arr, i);
    }
        cout<<"Minimum score is:"<<arr[0]<<endl;
    
    for( int i = 0; i<6 ; i++)
    {
        maxInsert(arr, i);
    }    
        cout<<"Maximum score is:"<<arr[0]<<endl;
    
}    