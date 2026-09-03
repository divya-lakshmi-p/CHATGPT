3Sum Closest

Pattern: Sorting + Two Pointers

Example:

[-1,2,1,-4]
target = 1

Output:

2

Focus on:

sum < target
sum > target

while keeping the closest value.









#include<bits/stdc++.h>
using namespace std;
int  threesumcloset(int arr[] , int  n )
{
  
  int target;
  cin >> target;

  int closet = arr[0]+arr[1]+arr[2];

  for(int i=0; i<n-2; i++)
  {
    int left = i+1 , right = n-1;

    while(left < right)
    {
      int sum = arr[i]+arr[left]+arr[right];

      if(abs(sum - target) < abs(closet - target))
      {
          closet=sum;
      }
      
      if(sum == target)
      {
          return sum;
      }
      else if(sum <target)
      {
        left++;

      }
      else
      { 
        right--;
      }
      
    }

  }

  return closet;

}

int main()
{
  int n ;
  cin >> n ;

  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  sort(arr , arr+n);

  cout << threesumcloset(arr , n);
}  
