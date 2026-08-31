Move Zeroes

Pattern: Same-direction Read/Write

Example:

[0,1,0,3,12]

Output:

[1,3,12,0,0]

This will reinforce the slow/fast pattern you just practiced.


#include<bits/stdc++.h>tc:o(n)
using namespace std;
void movezeros(int arr[] ,  int n,int count)
{
  sort(arr , arr+n);//it wont work if we need the array in ordered way because sorting will change the order 

  for(int i=n-count; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  for(int i=0; i<n-count; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int n,count=0;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin  >> arr[i];
    if(arr[i] !=0)
    {
      count++;
    }
  }

  movezeros(arr , n,count);
}

using Two pointer


#include<bits/stdc++.h>
using namespace std;

void movezeros(int arr[] , int n)
{
  int zeroscount =0;
  
  for(int i=0; i<n; i++)
  {
    if(arr[i] != 0)
    {
      arr[zeroscount] = arr[i];
      zeroscount++;
    }
  }

  for(int i=zeroscount; i<n; i++)
  {
    arr[i] =0;
  }
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
  movezeros(arr , n);

  for(int i=0; i<n; i++)
  {
    cout<< arr[i] << " ";
  }
}*/

Best way 
#include<bits/stdc++.h>
using namespace std;

void movezeros(int arr[] , int n)
{
  int slow =0;

  for(int fast =0; fast<n; fast++)
  {
    if(arr[fast] !=0)
    {
        swap(arr[slow] ,arr[fast]);
        slow++;
    }
  }
}

int main()
{
  int n;
  cin >>n ;

  int arr[n];

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  movezeros(arr , n);

  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
}
