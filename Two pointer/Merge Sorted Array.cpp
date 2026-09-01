Merge Sorted Array

Pattern: Two pointers from the end

Example:

A = [1,2,3,0,0,0]
B = [2,5,6]

Output:

[1,2,2,3,5,6]

Focus on why we often start:

i = last valid element of A
j = last element of B
k = last empty position


1.Merge in the same place 

#include<bits/stdc++.h>
using namespace std;
void mergetwo(int arr[] , int brr[] , int n, int m )
{
  int k = m+n-1;
  int i = m-1, j=n-1;  

  while(i>=0 && j>=0)
  {
    if(arr[i]>brr[j])
    {
      arr[k] = arr[i];
      i--;
    }
    else
    {
      arr[k] = brr[j];
      j--;
    }

    k--;
  }

  while(j >= 0)
  {
    arr[k] = brr[j];
    j--;
    k--;
  }


 for(int i=0; i<m+n;  i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int n ,m;
  cin >> n >> m;

  int arr[n+m], brr[m];
  for(int i=0; i<n+m; i++)
  {
    cin >> arr[i];
  }

  for(int j=0; j<m; j++)
  {
    cin >> brr[j];
  }


  mergetwo(arr , brr ,n , m );
}






using extra array 
#include<bits/stdc++.h>
using namespace std;

void mergetwo(vector<int> &arr , vector<int>& brr , int n, int m ) 
{ 
  int k = n+m-1;
  int i = m-1, j=n-1;
  vector<int>crr(n+m);
  while(i>=0 && j>=0) 
  {  
    if(arr[i]>brr[j])
    { 
      crr[k] = arr[i];
      i--;
    } 
    else
    { 
      crr[k] = brr[j];
      j--;
    } 
    
    k--; 
  } 
  
  while(j >= 0) 
  { 
    crr[k] = brr[j];
    j--;
    k--;
  }

  while(i>=0)
  {
    crr[k] = arr[i];
    i--;
    k--;
  }
  for(int i=0; i<crr.size(); i++)
  { 
    cout<<crr[i]<<" ";
  } 
  cout<<endl;
} 

int main()
{ 
  int n ,m;
  cin >> n >> m;
  vector<int>arr(n+m), brr(m);
  for(int i=0; i<n+m; i++)
  { 
    cin >> arr[i];
  } 
  for(int j=0; j<m; j++)
  { 
    cin >> brr[j];
  } 
  mergetwo(arr , brr ,n , m );

}if the array dont have any zero element s
