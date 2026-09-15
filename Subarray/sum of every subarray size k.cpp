Problem 6 — Sum of Every Subarray of Size K

Given K, print the sum of every contiguous subarray of size K.

Input

6
2 1 5 1 3 2
3

Output

8 7 9 6

Windows:

[2,1,5] → 8
[1,5,1] → 7
[5,1,3] → 9
[1,3,2] → 6

Focus: Fixed-size window.

Brute force approach 
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

    for(int i=0; i<=n-k; i++)
    {       sum =0;
        for(int j=i; j<=k+i-1; j++)
        {
            sum += arr[j];
        }
        cout<< sum <<" ";
    }
    cout<<endl;
}

prefis sum approach 

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
    int start ,end , k;
    cin >> k;
    for(int i=0; i<=n-k; i++)
    {
        start = pref[i-1];
        end = pref[k+i-1];
       cout << end- start<<" ";
    }

    cout<<endl;
}

