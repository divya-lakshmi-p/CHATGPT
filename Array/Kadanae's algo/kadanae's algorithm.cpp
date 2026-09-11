#include<bits/stdc++.h>
using namespace std;
void kadanaesquestion(int arr[] , int n)
{
    int currentsum = arr[0] , maxsum = arr[0];


    for(int i=1; i<n; i++)
    {
        currentsum = max(currentsum+arr[i] , arr[i]);

        maxsum = max(maxsum , currentsum);
    }

    cout<<maxsum<<endl;
    
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

    kadanaesquestion(arr , n);
}
