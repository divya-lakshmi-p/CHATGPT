Squares of a Sorted Array

Pattern: Opposite-direction

Example:

[-4,-1,0,3,10]

Output:

[0,1,9,16,100]

This is a beautiful Two Pointer problem because the array is sorted but negative values make the larger square come from either end.
bbrute force

#include<bits/stdc++.h>
using namespace std;
void  squarearray(int brr[] ,int n)
{
  int left = 0;
  while(left < n-1)
  {
    for(int right = left+1; right<n;  right++)
    {
      if(brr[left] > brr[right])
      {
        swap(brr[left], brr[right]);
      }
    }
    left++;
  }
}
int main()
{
  int n,sum;
  cin >> n;

  int arr[n],brr[n];
  for(int i=0; i<n; i++)
  { sum =1;
    cin >> arr[i];
    brr[i] =arr[i] * arr[i];
  }
  
  squarearray(brr, n);

  for(int i=0; i<n; i++)
  {
    cout<<brr[i]<<" ";
  }
  cout<<endl;
}


Brute force

#include<bits/stdc++.h>
using namespace std;
void  squarearray(int brr[] ,int n)
{
  int left = 0;
  while(left < n-1)
  {
    for(int right = left+1; right<n;  right++)
    {
      if(brr[left] > brr[right])
      {
        swap(brr[left], brr[right]);
      }
    }
    left++;
  }
}
int main()
{
  int n,sum;
  cin >> n;

  int  brr[n];
  for(int i=0; i<n; i++)
  { 
    int x;
    cin >> x;
    brr[i] = x*x;
  }
  
  squarearray(brr, n);

  for(int i=0; i<n; i++)
  {
    cout<<brr[i]<<" ";
  }
  cout<<endl;
}

//direct square 

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;

    arr[i] = x*x;
  }
  sort(arr , arr+n);

  for(int i=0; i<n; i++)
  {
    cout << arr[i] <<" ";
  }

  cout<<endl;
}

//Two pointer approach

#include<bits/stdc++.h>
using namespace std;
void squarerootarray(int arr[] , int n)
{
  int left =0,right =n-1;
  vector<int>ans(n);

  for(int pos = n-1; pos>=0; pos--)
  {
    if(abs(arr[left]) > abs(arr[right]))
    {
      ans[pos]= arr[left] * arr[left];
      left++;
    }
    else
    {
      ans[pos] = arr[right] * arr[right];
      right --;
    }
  }

    for(int i=0; i<n; i++)
  {
    cout << ans[i] << " ";
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
  squarerootarray(arr , n);
}
