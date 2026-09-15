Problem 8 — Minimum Sum of Size K

Input

7
4 2 7 1 8 3 5
3

Output

10

Because:

[4,2,7] → 13
[2,7,1] → 10 ← minimum
[7,1,8] → 16
[1,8,3] → 12
[8,3,5] → 16




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
    int start ,end , k , minisum = INT_MAX;
    cin >> k;
    for(int i=0; i<=n-k; i++)
    {
        start = pref[i-1];
        end = pref[k+i-1];
        int sum = end - start;
        minisum = min(minisum , sum);

    }

    cout<<minisum;
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

    int windowsum =0  , maxsum =INT_MAX;
    int k ;
    cin >> k;

    for(int i=0; i<k; i++)
    {
        windowsum += arr[i];
    }

    for(int i=k; i<n; i++)
    {
        windowsum = windowsum - arr[i-k]+arr[i];

        maxsum = min(maxsum , windowsum);
    }

    cout<<maxsum<<" "<<endl;
}
