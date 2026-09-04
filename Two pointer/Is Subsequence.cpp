Is Subsequence

Pattern: Same-direction

Example:

s = "abc"
t = "ahbgdc"

Output:

true

Focus on one pointer moving through each string.


order is matter here 


#include<bits/stdc++.h>
using namespace std;

bool subSequence(string s , string t)
{
  int i=0, j=0;

  while(i < s.length() && j < t.length())
  {
    if(s[i] == t[j])
    {
      i++;
      j++;
    }
    else
    {
      j++;
    }
  }

  return i== s.length();
}

int main()
{
  string s , t;
  cin >> s  >> t;

  cout << boolalpha <<subSequence( s, t) << endl;
}
