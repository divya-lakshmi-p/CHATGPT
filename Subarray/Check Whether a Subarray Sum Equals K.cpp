Problem 9 — Check Whether a Subarray Sum Equals K

Given an array and K, determine whether any contiguous subarray has sum exactly K.

Input

5
1 2 3 4 5
9

Output

YES

Because:

[2,3,4] = 9

Focus: First brute force. Think about how you could later optimize it.



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

    int k , sum ;
    cin >> k;

    for(int i=0; i<n; i++)
    {       sum =0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];

            if(sum == k)
            {
                cout<<"yes";
                return 0;
            }
            else if(sum >k)
            {
                continue;
            }
        }
    }

    cout<<"NO"<<endl;
}


Sliding Window 

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

    int left =0, sum =0 , k;
    cin >> k;

    for(int right =0; right<n; right++)
    {
        sum += arr[right];

        while(sum >k)
        {
            sum -= arr[left];
            left++;
        }

        if(sum == k)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout << "No"<<endl;
}
