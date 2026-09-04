Boats to Save People

Pattern: Sorting + Opposite-direction

Example:

people = [3,2,2,1]
limit = 3

Output:

3

This is a very clean greedy + Two Pointer problem.



          left <= right
                  ↓
       ┌──────────┴──────────┐
       ↓                     ↓
    TRUE                    FALSE
       ↓                     ↓
At least 1 person       Nobody remains
    remains                  ↓
       ↓                    STOP
  Use one boat



Boats to Save People

Pattern:
Sorting + Opposite-direction Two Pointers + Greedy

Sort the array

left = lightest
right = heaviest

if (people[left] + people[right] <= limit)
{
    // Both share a boat
    left++;
    right--;
}
else
{
    // Heaviest must go alone
    right--;
}

boats++;




#include<bits/stdc++.h>
using namespace std;

int saveboatpeople(int arr[] , int  n)
{
  int left =0 , right = n-1 , boats =0 , limit;
  cin >> limit;

  while(left <= right )
  {
    if(arr[left]+arr[right] <=  limit)  // if both side people are less than the limit they both can opcur in one boat so thats why we increkent left and right 
    {
      left ++;
      right--;
    }
    else{
      right --; // if both side people are greater than the limit then right side people can alone go into one single boat so we decre,ent right 
    }

    boats++;   // why we are incrementing boats outside of the loop is either one of the condiotn should satisfy and someone shoudl use boat so thats why 
  } 

  return boats;
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

  cout << saveboatpeople(arr , n) << endl;
}
