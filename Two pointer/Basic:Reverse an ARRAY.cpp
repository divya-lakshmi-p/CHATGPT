BAsic

1. Reverse an Array

Pattern: Opposite-direction

Example:

[1,2,3,4,5]

Output:

[5,4,3,2,1]

Focus on:

left++
right--

#include<bits/stdc++.h>
using namespace std;
void rotatearray(int arr[] , int n)
{
  int left =0, right = n-1;

  while(left <right)
  {
    int temp = arr[left];
    arr[left]=arr[right];
    arr[right]=temp;

    left++;
    right--;
  }

  for(int j=0; j<n; j++)
  {
    cout<< arr[j]<<" ";
  }

  cout<<endl;
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

  rotatearray(arr , n);
}
