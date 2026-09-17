Problem 16 — Maximum Subarray With All Negative Values

This one is important because it catches incorrect Kadane implementations.

Input

5
-8 -3 -6 -2 -5

Output

-2

Focus: Non-empty subarray and correct initialization.








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

    int maxsum =arr[0], currentsum =arr[0];

    for(int i=1; i<n; i++)
    {
        currentsum = max(currentsum+arr[i] , arr[i]);
        maxsum = max(maxsum , currentsum);
    }

    cout<<maxsum << endl;
}

