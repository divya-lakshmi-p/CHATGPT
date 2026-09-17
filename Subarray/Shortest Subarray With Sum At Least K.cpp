Problem 12 — Shortest Subarray With Sum At Least K ⭐⭐⭐

Given an array of positive integers, find the minimum length of a contiguous subarray whose sum is at least K.

Input

6
2 3 1 2 4 3
7

Output

2

Because:

[4,3] = 7

length = 2.

Focus: Variable-size Sliding Window.



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,k ;
    int  maxlength =0;
    cin >> n >>k;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int left =0, sum =0 , minsum = INT_MAX;

    for(int right=0; right<n;right++)
    {
        sum += arr[right];

        while(sum >k)
        {
            sum -= arr[left];
            left ++;
        }

          if(sum == k)
        {    // cout<< right <<"   "<<left << endl;
            minsum = min(minsum , (right-left+1));
        }

    }

    cout<<minsum<<endl;

}

