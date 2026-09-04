Trapping Rain Water ⭐⭐⭐

Pattern: Advanced Two Pointers

Example:

[0,1,0,2,1,0,1,3,2,1,2,1]

Output:

6

This is a very good interview problem because it tests whether you understand why pointer movement is safe.

You'll maintain:

leftMax
rightMax
left
right

Using prefix sum it is easy 

#include<bits/stdc++.h>
using namespace std;

void maxarray(int arr[] , int n)
{
  vector<int>leftmax(n) , rightmax(n);

  leftmax[0] = arr[0] ;

  for(int i= 1; i<n; i++)
  {
    leftmax[i] = max(leftmax[i-1] , arr[i]);
  }

  rightmax[n-1] = arr[n-1];
  for(int j =  n-2; j>=0; j--)
  {
    rightmax[j] = max(rightmax[j+1] , arr[j]);
  }

  int water = 0 ;

  for(int i=0; i<n; i++)
  { 
    int mini = min(leftmax[i] , rightmax[i]);

    water += mini -arr[i];
  }

  cout<<water<<endl;
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

  maxarray(arr , n);
}


Two pointer 

// core thing is in container with most water we just find the maximum heights of both left and right end from there we find mini value because water will flow to that level then we multiply it with index but in this case , we have to find the the ,max value of both left and right from that value we have to fint the minimum value and we have to subtract it from that inndex because waer will be blocked in that index for example left is 5 and  right is 7 but in between we are having 3 minimum value is 5 then we have to subtract this 3 fro 5 tht value only water will be trapped 
#include<bits/stdc++.h>
using namespace std;

void trappingwater(int arr[] , int n)
{
  int left =0 , right = n-1 , water =0;
  int leftmax=0, rightmax=0;

  while(left <= right)
  {
    if(leftmax < rightmax)
    {
      if(arr[left] >= leftmax)
      {
        leftmax = arr[left];
      }
      else{
        water +=   leftmax - arr[left];
      }

       left++;
    }
   

    else{
      if(arr[right] >= rightmax)
      {
        rightmax = arr[right];
      }
      else{
        water += rightmax - arr[right];
      }

      right--;
    }
    
  }

  cout<< water << endl;

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

  trappingwater(arr ,n);

}
