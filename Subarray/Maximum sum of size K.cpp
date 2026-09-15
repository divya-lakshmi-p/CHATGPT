Problem 7 — Maximum Sum of Size K ⭐

Input

6
2 1 5 1 3 2
3

Output

9

Focus: Sliding Window.



prefix sum approach 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    vector<int>pref(n);
    for(int i=0;i<n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1]+arr[i];
    }
    int start ,end , k , maxsum = INT_MIN;
    cin >> k;
    for(int i=0; i<=n-k; i++)
    {
        start = pref[i-1];
        end = pref[k+i-1];
        int sum = end - start;
        maxsum = min(maxsum , sum);

    }

    cout<<maxsum;
}

Sliding window

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

    int windowsum =0  , maxsum =0;
    int k ;
    cin >> k;

    for(int i=0; i<k; i++)
    {
        windowsum += arr[i];
    }

    for(int i=k; i<n; i++)
    {
        windowsum = windowsum - arr[i-k]+arr[i];

        maxsum = max(maxsum , windowsum);
    }

    cout<<maxsum<<" "<<endl;
}
