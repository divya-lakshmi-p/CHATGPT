Minimum Size Subarray Sum ⭐

Pattern: Sliding Window

Example:

target = 7
arr = [2,3,1,2,4,3]

Output:

2

This is the problem we discussed when asking:

Why do we move left++?

You should be able to explain:

right → expand
left → shrink

and why positivity matters.




MINIMUM SIZE SUBARRAY SUM

Pattern:
Sliding Window

Goal:
Smallest contiguous subarray
whose sum >= target.

right → EXPAND
left  → SHRINK

If sum < target:
    expand right

If sum >= target:
    record length
    shrink from left

Why positive numbers matter:
right++ adds positive → sum increases
left++ removes positive → sum decreases

Core:
for right:
    sum += nums[right]

    while sum >= target:
        answer = min(answer, right-left+1)
        sum -= nums[left]
        left++

Time:  O(n)
Space: O(1)




#include<bits/stdc++.h>
using namespace std;

int minisubarray(int arr[] , int n)
{
  int left =0 , sum =0 , mini = INT_MAX;

  int target;
  cin >> target;

  for(int right =0; right<n; right++)
  {
    sum += arr[right];

    while( sum >= target)
    {
      mini = min(mini, right-left+1);

      sum -= arr[left];
      left++;
    }

  }

  return mini;
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

  cout << minisubarray(arr ,n);
}
