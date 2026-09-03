3Sum ⭐

Pattern: Sorting + Two Pointers

Example:

[-1,0,1,2,-1,-4]

Output:

[[-1,-1,2],[-1,0,1]]

This is one of the most important Two Pointer interview problems.

It combines:

sorting
+
outer loop
+
two pointers
+
duplicate handling




Brute Force
    ↓
3 nested loops
    ↓
O(n³)

Then ask:
"Can I avoid checking every j and k?"

    ↓

Sort
    ↓
Fix i
    ↓
Two Pointers for remaining two values
    ↓
O(n²)



#include<bits/stdc++.h>
using  namespace std;

void threesum(int arr[] ,int n)
{
  vector<vector<int>>res;
  for(int i=0; i<n;  i++)
  {
    for(int j=i+1; j<n; j++)
    {
      for(int k=j+1; k<n; k++)
      {
        if(arr[i]+arr[j]+arr[k]==0)
        {
            res.push_back({arr[i] , arr[j] , arr[k]});
        }
      }
    }
  }
   cout<<"  [";
  for(auto x : res)
  {
    cout<<"[";

    for(int triplets:x)
    {
      cout << triplets <<" ";
    }
    cout<<"]  ";
  }

  cout<<"]"<<endl;
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
  threesum(arr ,n);
}



#include<bits/stdc++.h>
using namespace std;

//this concept is like freeze i value and take left and right to find the three sum for all the index 
vector<vector<int>> threesum(int arr[] , int n)
{
  vector<vector<int>>vec;
for(int i=0;  i<n-2; i++)//why means we need threee value if we access it till n then we will get the arrayoutof index error
  {
    if(i>0 && arr[i] == arr[i-1]) // it is used to skip the initial duplicate value  for example if we freeze -1 as initial then in the next iteration if again -1 come means we will skip it to avpid the dupliacte values again and again
    continue;

    int left = i+1 , right = n-1;

    while(left < right)
    {
      int sum = arr[i]+arr[left]+arr[right];

      if(sum > 0)
      right--;
      else if(sum < 0)
      left++;
      else
      {
        vec.push_back({arr[i] , arr[left] , arr[right]});

        left++;
        right--;


        while(left < right && arr[left] == arr[left-1])   // it is second one to avaoif the dupliacet pairs 
        left++;
        while(left<right && arr[right] == arr[right+1])
        right--;


      } 
    }
  }
return vec;
 
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
  vector<vector<int>>ans = threesum(arr ,n);

   for(auto x:ans)
  {
    cout<<"[ ";
    for(int res:x)
    {
      cout<< res <<" ";
    }
    cout<<"] ";
  }

  cout<<endl;
}
