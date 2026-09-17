Problem 15 — Maximum Subarray Sum Using Kadane ⭐⭐⭐

Find the maximum sum of a non-empty contiguous subarray.

Input

9
-2 1 -3 4 -1 2 1 -5 4

Output

6

The best subarray is:

[4,-1,2,1]

sum = 6.

Focus:

currentSum
bestSum

and the decision:

continue
OR
start fresh



Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n  ;
    cin >> n ;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int maxsum = INT_MIN, sum =0;
    for(int i=0; i<n; i++)
    {       sum =0;
        for(int j=i; j<n; j++)
        {       sum =0;
            for(int k=i; k<=j; k++)
            {
                    sum += arr[k];
            }
                //cout<<sum <<endl;
        maxsum = max(maxsum , sum);
        }
        
    }

    cout<< maxsum <<endl;
} 


Kadane's algorithm

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

    int maxsum =0, currentsum =0;

    for(int i=0; i<n; i++)
    {
        currentsum = max(currentsum+arr[i] , arr[i]);
        maxsum = max(maxsum , currentsum);
    }

    cout<<maxsum << endl;
}
