#include <iostream>
using namespace std;
const int capacity = 100;
void merge(int *arr1, int *arr2, int low, int mid, int high)
{
    int h=low, i=low, j=mid+1, k;
    while((h <= mid) && (j <= high))
    {
        if(arr1[h]<=arr1[j])
        {
            arr2[i]=arr1[h];
            h++;
        }
        else
        {
            arr2[i]=arr1[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            arr2[i]=arr1[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            arr2[i]=arr1[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) 
	{
		arr1[k]=arr2[k];
	}
}
 
void mergeSort(int *arr1, int *arr2, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        mergeSort(arr1, arr2, low, mid);
        mergeSort(arr1, arr2, mid+1, high);
        merge(arr1,arr2,low,mid,high);
    }
}

int main()
{
    int arr1[capacity];
    int arr2[capacity];
	int size;
	cout<<"*****************MERGE SORT***************"<<endl;
	cout<<"Enter the size of array: ";
	cin>>size;
	for(int i=0; i<size ;i++)
	{
		cin>>arr1[i];
	}
    mergeSort(arr1,arr2,0,size-1);
    for(int i=0; i<size; i++)
	{
        cout<<arr1[i]<<" ";
	}
    cout<<endl;
	system("pause");
	return 0;
}
//T(n)=O(nlogn)