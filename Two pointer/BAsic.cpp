return the index which  should be equal  to the sum




#include<bits/stdc++.h>
using namespace std;

void newconcept(int arr[] , int n)
{
  int left =0 , right = n-1;
  int target;
  cin >> target;

  while(left <= right)
  {   
    int sum =0;
    sum = arr[left] + arr[right];
    if(sum  == target)
    {
      cout<< "left index :" << left <<" "<< "left index value :" <<arr[left]<<endl;
      cout<<"Right index :"<<right <<" "<< "Right index value :"<<arr[right]<<endl;
      return;
    }
    else if(sum <target)
    {
      left++;
    }
    else{
      right --;
    }
    
  }
   
  cout<<"-1";
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

  newconcept(arr , n);
}
