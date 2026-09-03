Two sum 
Two Sum II — Input Array Is Sorted

Pattern: Opposite-direction + sorted array

Example:

arr = [2,7,11,15]
target = 9

Output:

[1,2]

This is the most important beginner Two Pointer problem.

Understand deeply:

sum < target → left++
sum > target → right--



Core logic:
Small sum → need a bigger value → left++
Large sum → need a smaller value → right--





  Goal:
Find 2 numbers whose sum = target.

Pattern:
Sorting + Two Pointers

1. Sort array
2. left = 0
3. right = n - 1

sum = arr[left] + arr[right]

sum < target → left++
sum > target → right--
sum == target → answer found

Think:

2Sum
= Direct Two Pointers

TC:
O(n log n) including sorting
O(n) if array is already sorted








1.Brute force approach 
#include<bits/stdc++.h>
using namespace std;
void twosum(int arr[] , int n , int target)
{
  for(int i=0; i<n; i++)  // is this loop runn o(n)
  {
    for(int j=i+1; j<n; j++) //this loop run n-1 times so its n(n-1)/2 = n^2-n/2 so its n^2
    {
      if(arr[i]+arr[j]==target)
      {
        cout<<i <<" "<<j<<endl;
        return;
      }
    }
  }
  cout<<"-1";
}

int main()
{
  int n , target;
  cin >> n >> target;

  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  twosum(arr,n, target);
}


2.two pointer technique

#include<bits/stdc++.h>
using namespace std;

pair<int , int>twosum(int arr[] , int n,int target)
{
  int left =0,right = n-1;
  while(left < right)
  { int sum =0;
    sum = arr[left]+arr[right];
    if(sum ==target)
      return {left ,right};
    else if(sum < target)
      left++;
    else
      right--;
  }
  return {-1, -1};
}



int main()
{
  int n , target;
  cin >> n  >> target;

  int arr[n];

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  pair<int , int >ans = twosum(arr,n, target);

  cout<<ans.first <<" "<<ans.second<<endl;
}

3.using unordered_map

#include<bits/stdc++.h>
using namespace std;

void twosum(int arr[] ,int n, int target , unordered_map<int , int>mp)
{

  for(int i=0; i<n; i++)
  { int sum =0;
     sum  = target - arr[i];

    if(mp.find(sum) != mp.end())
    {
      cout<<i <<"  "<< "IT means the index value not the value itself   "<<mp[sum]<<endl;
      break;
    }
    else
      mp[arr[i]]=i;
  }

  
}

int main()
{
  int n , target;
  cin >> n  >> target;

  int arr[n];

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  unordered_map<int ,int>mp;

  twosum(arr, n, target ,mp);
}
