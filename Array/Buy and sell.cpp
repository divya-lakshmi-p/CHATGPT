#include<bits/stdc++.h>
using namespace std;
void buyandsell(int arr[] , int n)
{
    int minprice = INT_MAX , maxprofit = INT_MIN;

    for(int i=0; i<n; i++)
    {
        minprice = min(minprice , arr[i]);

        maxprofit = max(maxprofit , (arr[i]-minprice));
    }

    cout<< maxprofit << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n; i++)
    {
        cin >> arr[i];
    }

    buyandsell(arr , n);
}
