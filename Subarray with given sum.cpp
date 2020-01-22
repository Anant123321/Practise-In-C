#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void func(int arr[],int s,int num)
{
    int i=0,j=0;
    int sum=0,flag=0;
    for(i=0;i<s && j<s;)
    {
        if(sum+arr[i]<num)
        {
            sum+=arr[i];
            i++;
        }
        else
        {
            if(sum+arr[i]>num)
            {
                sum=sum-arr[j];
                j++;
            }
            else
            {
                cout<<j+1<<" "<<i+1<<endl;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        cout<<-1<<endl;
    }
    
    
}
int main() {
    int t;
    cin>> t;
    for(int l=0; l<t; l++)
    {
        int s,n;
        cin>>s>>n;
        int arr[s];
        for(int i=0;i<s;i++)
        {
            cin>>arr[i];
        }
        func(arr,s,n);
    }
	return 0;
}
