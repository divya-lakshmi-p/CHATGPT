4Sum

Pattern: Sorting + multiple pointers

Example:

[1,0,-1,0,-2,2]
target = 0

Focus on how 4Sum builds on 3Sum.






4SUM

Goal:
Find all unique quadruplets whose sum = target.

Pattern:
Sorting + 2 fixed indices + Two Pointers

1. Sort array
2. Fix i
3. Fix j
4. left = j + 1
5. right = n - 1

sum = arr[i] + arr[j] + arr[left] + arr[right]

sum < target → left++
sum > target → right--
sum == target → store + move both

Duplicates:
skip duplicate i
skip duplicate j
skip duplicate left/right

Think:

4Sum
= Fix 2 numbers
+ 2Sum using Two Pointers

TC: O(n³)




  




#include<bits/stdc++.h>
using namespace std;
void foursum(int arr[],int n)
{ 
  vector<vector<int>>sum;
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      for(int k=j+1; k<n; k++)
      {
        for(int l= k+1; l<n; l++)
        {
          if(arr[i]+arr[j]+arr[k]+arr[l]==0)
          {
            sum.push_back({arr[i] , arr[j], arr[k], arr[l]});
          }
        }
      }
    }
  }

  cout<<"[ ";
  for(auto x:sum)
  {
    cout<<"[ ";
    for(int d :x)
    {
      cout<<d <<" ,";
    }
    cout<<"] ";

  }

  cout<<" ] "<<endl;
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

  sort(arr , arr+n);

  foursum(arr ,n);


}

#include<bits/stdc++.h>
using namespace std;
void foursum(int arr[] ,int n)
{ vector<vector<int>>res;
  sort(arr , arr+n);
  for(int i=0; i<n-3;  i++)
  {
    if(i>0 && arr[i] == arr[i-1])
      continue;
    for(int j=i+1; j<n-2; j++)
    {
        if(j>i+1&& arr[j]==arr[j-1])
        continue;

      int left = j+1 , right = n-1;

      while(left < right)
      {
        int sum = arr[i]+arr[j]+arr[left]+arr[right];

        if(sum > 0)
          right--;
        else if(sum <0)
          left++;
        else{
            res.push_back({arr[i] , arr[j] , arr[left] , arr[right]});

            left++;
            right--;

             while(left < right && arr[left] == arr[left-1])   // it is second one to avaoif the dupliacet pairs 
                left++;
        while(left<right && arr[right] == arr[right+1])
        right--;
        }
      }


    }
  }

  cout<<"[ ";

  for(auto x: res)
  {
    cout<<"[ ";

    for(int l : x)
    {
      cout<< l <<" ,";
    }
    cout<<"] ";
  }
  cout<<"] "<<endl;
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

  foursum(arr , n);
}



// if we are having target as something instead of zero we have to check the target 
