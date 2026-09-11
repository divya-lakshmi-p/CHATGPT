Problem 2 — Count Number of Subarrays

Given an array, find the total number of contiguous subarrays.

Input

5
10 20 30 40 50

Output

15

Focus: Understand why the answer is n(n+1)/2.



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
    int count =0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n;j++)
        {
            count++;
        }
    }
    cout<<count<<endl;
}  
