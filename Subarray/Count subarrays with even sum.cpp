Problem 14 — Count Subarrays With Even Sum

Input

5
1 2 3 4 5

Output

6

Focus: Think about how many subarrays have even total sum.








#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n  ;
    cin >> n ;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int left =0, sum =0 ,  count =0;
    for(int left =0; left<n; left++)
    {       sum =0;
        for(int right=left; right<n;right++)
    {
        sum += arr[right];
        if(sum %2 ==0)
        {    count++;
        }

    }
    
    }

   cout<<count<<endl;

}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int even =1, odd=0, count =0 , pref=0;

    for(int i=0; i<n; i++)
    {
        pref += arr[i];


        if(pref %2==0)
        {
            count += even;
            even++;
        }
        else
        {
            count += odd;
            odd++;
        }
    }

    cout<<count<<endl;
Notes given by chatgpt for to remembber the question 

## Count Subarrays With Even Sum

### Question
Given an array, count how many **contiguous subarrays** have an even sum.

### First thought

`Subarray → Prefix Sum`

But we don't need the exact prefix value.

We only need:

`Even or Odd`

### Core observation

A subarray sum is:

`currentPrefix - previousPrefix`

For the result to be EVEN:

- Even - Even = Even
- Odd - Odd = Even

Therefore:

**Same parity prefix sums → even-sum subarray**

### What to maintain

```cpp
int prefix = 0;
int even = 1;
int odd = 0;
int count = 0;
```

`even = 1` because prefix `0` exists before the array starts, and `0` is even.

### Code skeleton

```cpp
for(int i = 0; i < n; i++)
{
    prefix += arr[i];

    if(prefix % 2 == 0)
    {
        // Current prefix is EVEN.
        // Pair it with every previous EVEN prefix.
        count += even;

        // Now current prefix becomes a previous prefix.
        even++;
    }
    else
    {
        // Current prefix is ODD.
        // Pair it with every previous ODD prefix.
        count += odd;

        // Now current prefix becomes a previous prefix.
        odd++;
    }
}
```

### Remember the order

```text
1. Calculate current prefix
2. Check EVEN/ODD
3. Use OLD count
4. Add to answer
5. Increment the current parity count
```

### Tiny example

Array:

```text
[1, 2, 3]
```

Prefix:

```text
0 → 1 → 3 → 6
E   O   O   E
```

Same-parity pairs:

```text
O-O → 3 - 1 = 2 → [2]
E-E → 6 - 0 = 6 → [1,2,3]
```

Answer:

```text
2
```

### One-line memory

**"Same parity prefixes make an even subarray; count the old same-parity prefixes before storing the current one."**
