#include <iostream>
using namespace std;
void func(int arr[], int size)
{
    int max=arr[size-1];
    int res[size],j=0;
    res[j++]=max;
    for(int i=size-2;i>=0;i--)
    {
        if(arr[i]>=max)
        {
            max=arr[i];
            res[j++]=max;
        }
    }
    for(int i=j-1;i>=0;i--)
    {
        cout<<res[i]<<" ";
    }
}
int main() {
	int testCases;
    cin >> testCases;
    for(int t=0;t<testCases;t++)
    {
        int size;
        cin >> size;
        int arr[size];
        for(int i=0; i<size ;i++)
        {
            cin>>arr[i];
        }
        func(arr,size);
        cout<<endl;
    }
	return 0;
}
