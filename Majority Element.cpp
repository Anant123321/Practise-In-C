#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
int main() {
    int testCases;
    cin >> testCases;
    for(int t=0;t<testCases;t++)
    {
        int size;
        cin >> size;
        int arr[size],flag=0;
        for(int i=0; i<size ;i++)
        {
            cin>>arr[i];
        }
        if(size==1)cout<<arr[0]<<endl;
        else
        {
            sort(arr,arr+size);
            for(int i=0 ; i<=size/2 ; i++)
            {
                if(arr[i]==arr[i+(size/2)])
                {
                    cout<<arr[i]<<endl;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            cout<<"-1"<<endl;
        }
    }
	//code
	return 0;
}
