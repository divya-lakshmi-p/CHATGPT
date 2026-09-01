Intersection of Two Arrays II

Pattern: Two pointers after sorting

Example:

[1,2,2,1]
[2,2]

Output:

[2,2]

Focus on comparing two sorted sequences.




Two pointer 

#include<bits/stdc++.h>
using namespace std;

void intersection(vector<int>&arr , vector<int>&brr , int n , int m)
{
  sort(arr.begin() , arr.end());
  sort(brr.begin() , brr.end());

  vector<int>ans;
  int i=0 , j=0;
  while(i < arr.size() && j < brr.size())
  {
    if(arr[i] == brr[j])
    {
      ans.push_back(arr[i]);
      i++;
      j++;
    }
    else if(arr[i]<brr[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  for(int i=0; i<ans.size(); i++)
  {
    cout << ans[i]<<"  ";
  }

  cout<<endl;
}

int main()
{ 
  int n ,m;
  cin >> n >> m;
  vector<int>arr(n), brr(m);
  for(int i=0; i<n; i++)
  { 
    cin >> arr[i];
  } 
  for(int j=0; j<m; j++)
  { 
    cin >> brr[j];
  } 
  intersection(arr , brr ,n , m );

}

 using multiset
#include<bits/stdc++.h>
using namespace std;

void intersection(int arr[], int brr[], int n,int m , multiset<int>ms)
{
  vector<int>vec;
  for(int i=0; i<m; i++)
  {
    auto it = ms.find(brr[i]);
    if(it != ms.end())
    {
      vec.push_back(brr[i]);
      ms.erase(it);
    }

  }

  for(int x: vec)
  {
    cout << x << " ";
  }

  cout<<endl;
}

int main()
{
  int n , m;
  cin >> n >> m;

  int arr[n] , brr[m];
  multiset<int>ms;
  for(int i=0; i<n; i++){ cin >> arr[i];  ms.insert(arr[i]);}
  for(int j=0; j<m; j++){ cin >> brr[j];}

  intersection(arr, brr,n,m ,ms);

}


using unordered_map 
#include<bits/stdc++.h>
using namespace std;
void intersection(int brr[] , int n , int m , unordered_map<int ,  int>&mp)
{   vector<int>ans;
    for(int i=0; i<m; i++)
    {
      if(mp[brr[i]] >0)
      {
          ans.push_back(brr[i]);
          mp[brr[i]]--;
      }
    }

    for(int x: ans)
    {
      cout << x << " ";
    }
    cout<<endl;
}

int main()
{
  int n , m;
  cin >> n >> m;

  int arr[n] , brr[m];
  unordered_map<int , int >mp;
  for(int i=0; i<n; i++){ cin >> arr[i];  mp[arr[i]]++;}
  for(int j=0; j<m; j++){ cin >> brr[j];}

  intersection( brr,n,m ,mp);
}
