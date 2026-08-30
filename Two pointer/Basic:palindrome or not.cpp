Time and space complexity is o(n);
#include<bits/stdc++.h>
using namespace std;
string isPalindrome(string n)
{
  int left =0, right = n.length()-1;

  while(left <right)
  {
    char temp = n[left];
    n[left]=n[right];
    n[right]=temp;

    left++;
    right--;
  }

  return n;
}

int main()
{
  string n;
  cin >> n;
 string str =  isPalindrome(n);

 if(n == str)
  cout<<"palindrome"<<endl;
  else
  cout<<"NOt palindrome"<<endl;


}

Timeo(n) and space complexity o(1) ;

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
  int left =0 , right = str.length()-1;
  while(left < right)
  {
    if(str[left]!=str[right])
    {
     return false;
      
    }

    left++;
    right--;
  }
  return true;
}


int main()
{
  string str;
  cin >> str;

  bool out = isPalindrome(str);

  (out)?cout<<"Palindrome"<<" "<<endl:cout<<"Not palindrom"<<" "<<endl;

}
