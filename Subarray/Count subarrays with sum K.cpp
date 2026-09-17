Problem 13 — Count Subarrays With Sum K ⭐⭐⭐

Given an array, count how many contiguous subarrays have sum exactly K.

Input

5
1 2 1 2 1
3

Output

4

Valid subarrays:

[1,2]
[2,1]
[1,2]
[2,1]

Focus: Prefix Sum + HashMap. [unable to think in hashmap ] could you please guide me  




#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,k ;
    cin >> n >>k;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int left =0, sum =0 ,  count =0;

    for(int right=0; right<n;right++)
    {
        sum += arr[right];

        while(sum >k)
        {
            sum -= arr[left];
            left ++;
        }

          if(sum == k)
        {    count ++;
        }

    }

    cout<<count<<endl;

}






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

    int left =0, sum =0 ,  count =0;
    for(int left =0; left<n; left++)
    {       sum =0;
        for(int right=left; right<n;right++)
    {
        sum += arr[right];
        if(sum %2 ==0)
        {    count++;
        }

    }
    
    }

   cout<<count<<endl;

}
