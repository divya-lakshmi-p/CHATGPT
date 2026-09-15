Problem 3 — Print Sum of Every Subarray

Given an array, print the sum of every contiguous subarray.

Input

4
1 2 3 4

Output

1
3
6
10
2
5
9
3
7
4




#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int sum ;
    for(int i=0; i<n; i++)
    {       sum=0;
        for(int j=i; j<n;j++)
        {
           sum += arr[j];
            cout<<sum <<" ";
        }
        cout<<endl;
    }
}  
