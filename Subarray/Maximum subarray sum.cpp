Problem 4 — Maximum Subarray Sum (Brute Force)

Find the maximum sum among all contiguous subarrays.

Input

5
-2 1 -3 4 2

Output

6

Because:

[4,2] → 6

Focus: First solve this with brute force. Don't use Kadane yet.






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
    int currentsum =0, maxsum =0;
    for(int i=0; i<n; i++)
    {      
        currentsum = max(arr[i] , currentsum+arr[i]);

        maxsum = max(maxsum , currentsum);
    }

    cout<<maxsum<<endl;
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

    int maxsum =0, sum=0;

    for(int i=0; i<n; i++)
    {
        sum =0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];

            maxsum = max(maxsum , sum);
        }
    }

    cout<<maxsum<<endl;
}


