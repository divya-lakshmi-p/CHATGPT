Problem 11 — Longest Subarray With Sum K ⭐⭐

Given an array of positive integers, find the length of the longest contiguous subarray whose sum is exactly K.

Input

7
1 2 1 1 1 2 3
3

Output

3

Because:

[1,1,1] = 3

has length 3.

Focus: Understand the difference between:

find a subarray
vs
find the longest subarray


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int k , sum =0;
    cin >> k;

    int start =0 ,end=0;

    int maxlength = INT_MIN;

    for(int i=0; i<n; i++)
    {    sum =0;
        

        for(int j=i; j<n; j++)
        {
            sum += arr[j];

            if(sum ==k)
            {  start = i;
                end = j;

                break;
            }
            
            else if(sum >k)
            {
                break;
            }
        }
        maxlength = max(maxlength , end-start+1);
    }
    cout<<maxlength<<" "<<endl;
}


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

    int left =0, sum =0;

    for(int right=0; right<n;right++)
    {
        sum += arr[right];

        while(sum >k)
        {
            sum -= arr[left];
            left ++;
        }

        if(sum == k)
        {
            maxlength = max(maxlength ,  (right-left+1));
        }

    }
    cout<<maxlength<<endl;
}


