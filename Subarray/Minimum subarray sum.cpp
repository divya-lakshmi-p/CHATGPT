Problem 5 — Minimum Subarray Sum

Find the minimum sum among all contiguous subarrays.

Input

6
3 -4 2 -3 -1 5

Output

-6

Because:

[3,-4,2,-3,-1] = -3
[-4,2,-3,-1] = -6

Focus: Brute force first.



Kadanae algorithm

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
    int currentsum =0, minsum =INT_MAX;
    for(int i=0; i<n; i++)
    {      
        currentsum = min(arr[i] , currentsum+arr[i]);

        minsum = min(minsum , currentsum);
    }

    cout<<minsum<<endl;
}  
Brute Force Approach 

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

    int MINSUM =INT_MAX, sum=0;

    for(int i=0; i<n; i++)
    {
        sum =0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];

            MINSUM = min(MINSUM , sum);
        }
    }

    cout<<MINSUM<<endl;
}
