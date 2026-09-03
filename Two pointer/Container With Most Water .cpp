 Container With Most Water ⭐

Pattern: Opposite-direction

Example:

[1,8,6,2,5,4,8,3,7]

Output:

49

This is very frequently asked.

The important question is:

Why do we move the shorter-height pointer?

Don't memorize that rule; understand the proof.










Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

void containerwithwater(int arr[] , int n)
{
  
int maxi = INT_MIN;

  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {  
      int sum =0;
        
      sum = (j-i) * min(arr[i] , arr[j]);
      maxi = max( maxi , sum);
    }
  }

  cout << maxi << endl;

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

  containerwithwater(arr , n);

}



#include<bits/stdc++.h>
using namespace std;


void containerwithwater(int arr[] ,int n)
{
  int left  = 0 , right = n-1 , maxarea =0;

  while(left < right)
  {
    int width = right -left;
    int height = min(arr[left] , arr[right]);

    maxarea = max(maxarea , (width * height));

    if(arr[left] <=  arr[ right]) //why equal means if both pointer reaches the same value means we can move either left or right enything is good
    {
      left++;
    }
    else
    {
      right--;
    }
  }

  cout<<maxarea <<" "<<endl;
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

  containerwithwater(arr , n);

}
