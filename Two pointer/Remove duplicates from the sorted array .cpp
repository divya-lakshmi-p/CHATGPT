Remove duplicates from the sorted array 


#include<bits/stdc++.h>
using namespace std;

int removeduplicate(int arr[] , int n)
{
  int left =0, right ,i;

  for(int right =1; right <n; right++)
  {
    if(arr[right] != arr[left])
    {
      left++;
      arr[left]= arr[right];
    }
  }
return left+1;
  
}

int main()
{
  int n;
  cin >> n;

  int arr[n];

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  int newl = removeduplicate(arr ,n);
  for(int i=0; i<newl; i++)
  {
    cout<<arr[i]<<" ";
  }
}


Input:
10
1 1 2 3 4 5 5 6 7 7
Output:
1 2 3 4 5 6 7
