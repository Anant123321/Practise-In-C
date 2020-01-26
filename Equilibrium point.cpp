#include <iostream>
using namespace std;

int func(int arr[],int sum_arr[],int size)
{
    if(size==1)return 1;
    if(size==2)return -1;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum_arr[i] = sum+arr[i];
        sum=sum+arr[i];
    }
    for(int i=1;i<size-1;i++)
    {
        int left_sum=sum_arr[i-1];
        int right_sum=sum-sum_arr[i];
        if(left_sum==right_sum)return i+1;
    }
    return -1;
}
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int size;
	    cin>>size;
	    int arr[size];
	    int sum_arr[size];
	    for(int i=0;i<size;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<func(arr,sum_arr,size)<<endl;
	}
	return 0;
}
