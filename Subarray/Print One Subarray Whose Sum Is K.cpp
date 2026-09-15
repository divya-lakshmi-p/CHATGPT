Problem 10 — Print One Subarray Whose Sum Is K

Input

6
2 3 1 2 4 3
7

Output

2 3 1 2

There are multiple valid subarrays depending on the problem interpretation; here we're asking you to print one valid subarray.

Focus: Track left and right.



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

    int start =0 ,end=0;

    bool found = false;

for(int i = 0; i < n; i++)
{
    int sum = 0;

    for(int j = i; j < n; j++)
    {
        sum += arr[j];

        if(sum == k)
        {
            start = i;
            end = j;
            found = true;
            break;       // stops j loop
        }

        if(sum > k)
        {
            break;
        }
    }

    if(found)
    {
        break;           // stops i loop
    }
}

    for(int i= start; i<=end; i++)
    {
        cout<< arr[i]<<" ";
    }

    cout<<endl;

}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,k ;
    int  maxlength =0;
    cin >> n >>k;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int left =0, sum =0;

    for(int right=0; right<n;right++)
    {
        sum += arr[right];

        while(sum >k)
        {
            sum -= arr[left];
            left ++;
        }

          if(sum == k)
        {
            for(int i = left; i <= right; i++)
            {
                cout << arr[i] << " ";
            }

            return 0;
        }

    }
cout << "No subarray found";

    return 0;
}

