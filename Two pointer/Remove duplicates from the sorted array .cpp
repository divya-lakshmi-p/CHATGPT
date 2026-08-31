Remove Duplicates from Sorted Array


Pattern: Same-direction Read/Write

Example:

[1,1,2,2,3]

Output logically:

[1,2,3]

Focus on:

slow → write
fast → read


using two pointers


#include<bits/stdc++.h>
using namespace std;
int removeduplicates(int arr[], int n)
{
  int left =0 ;
  for(int i=1; i<n; i++)
  {
    if(arr[i] !=arr[left])
    {
      left++;
      arr[left] = arr[i];
    }
  }
  return left+1;
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

  int count = removeduplicates(arr ,n);

  for(int i=0; i<count; i++)
  {
    cout<<arr[i]<<"  ";
  }
  cout<<endl;
}



using set


#include<bits/stdc++.h>
using namespace std;

set<int> removeduplicates(int arr[] , int n)
{
  set<int>s;

  for(int i=0; i<n; i++)
  {
    s.insert(arr[i]);
  }

  return s;
}

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i=0;  i<n; i++)
  {
    cin >> arr[i];
  }
  set<int> outPut = removeduplicates(arr ,n);

  for(int x:outPut)
  {
    cout<<x<<"  ";
  }

  cout<<endl;
}

if array is unsorted


#include<bits/stdc++.h>
using namespace std;

int removeduplicates(int arr[] , int n)
{
  sort(arr ,  arr+n);
  int left =0 ;
  for(int i=0; i<n; i++)
  {
    if(arr[i] !=arr[left])
    {
      left++;
      arr[left] = arr[i];
    }
  }
  return left+1;

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

  int count = removeduplicates(arr , n);

  for(int i=0; i<count; i++)
  {
    cout<<arr[i]<<"  ";
  }

  cout<<endl;

}*/


if order is matter then 



#include<bits/stdc++.h>
using namespace std;

vector<int> removeduplicates(int arr[], int n)
{
  set<int>s;
  vector<int>v;

  for(int i=0; i<n; i++)
  {
    if(s.find(arr[i]) == s.end())
    {
        s.insert(arr[i]);
        v.push_back(arr[i]);
    }
  }

  return v;
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

  vector<int> g = removeduplicates(arr , n);

  for(int i=0; i<g.size(); i++)
  {
    cout<< g[i] <<"  ";
  }
  cout<<endl;
}
