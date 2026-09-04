# Trapping Rain Water

## ⭐ Pattern

**Advanced Two Pointers**

---

## 🎯 Problem

Given an array where each value represents the height of a vertical bar, find the **total amount of rainwater trapped** between the bars.

### Example

```text
Input:
[0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6
```

---

# 🧠 Core Idea

For every index `i`, the amount of water trapped is:

```text
water[i] = min(leftMax, rightMax) - height[i]
```

### Why?

The water level is limited by the **shorter boundary**.

```text
water level = min(leftMax, rightMax)
```

But the bar itself already occupies some height:

```text
actual water = water level - height[i]
```

Therefore:

```text
water = min(leftMax, rightMax) - height[i]
```

---

# 1️⃣ Prefix + Suffix Approach

Create two arrays:

```text
leftMax[i]  = maximum height from LEFT up to i
rightMax[i] = maximum height from RIGHT up to i
```

Then:

```text
water += min(leftMax[i], rightMax[i]) - height[i]
```

### Complexity

```text
Time  : O(n)
Space : O(n)
```

This approach is easier to understand first.

---

# 2️⃣ Two Pointer Approach ⭐

Instead of storing:

```text
leftMax[]
rightMax[]
```

maintain only:

```cpp
leftMax
rightMax
```

and two pointers:

```cpp
left = 0
right = n - 1
```

### Important Rule

```cpp
if(leftMax < rightMax)
```

means:

> `leftMax` is the smaller boundary, so the LEFT side is the limiting side.

Therefore:

```cpp
process left
left++;
```

Otherwise:

```cpp
process right
right--;
```

### Mental Model

```text
             leftMax        rightMax
                ↓              ↓
                |              |
                |    WATER     |
                |~~~~~~~~~~~~~~|
                |      |       |
                |      |       |
              LEFT           RIGHT

       Smaller boundary controls water
```

---

# ⭐ Two Pointer Algorithm

```text
1. left = 0
2. right = n - 1
3. leftMax = 0
4. rightMax = 0
5. water = 0

6. While left <= right:

   If leftMax < rightMax:

       If height[left] >= leftMax:
           update leftMax

       Else:
           water += leftMax - height[left]

       left++

   Else:

       If height[right] >= rightMax:
           update rightMax

       Else:
           water += rightMax - height[right]

       right--

7. Return water
```

---

# 💻 C++ — Two Pointer

```cpp
int trappingWater(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left <= right)
    {
        if(leftMax < rightMax)
        {
            if(arr[left] >= leftMax)
            {
                leftMax = arr[left];
            }
            else
            {
                water += leftMax - arr[left];
            }

            left++;
        }
        else
        {
            if(arr[right] >= rightMax)
            {
                rightMax = arr[right];
            }
            else
            {
                water += rightMax - arr[right];
            }

            right--;
        }
    }

    return water;
}
```

---

# ☕ Java — Two Pointer

```java
public int trappingWater(int[] height)
{
    int left = 0;
    int right = height.length - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left <= right)
    {
        if(leftMax < rightMax)
        {
            if(height[left] >= leftMax)
            {
                leftMax = height[left];
            }
            else
            {
                water += leftMax - height[left];
            }

            left++;
        }
        else
        {
            if(height[right] >= rightMax)
            {
                rightMax = height[right];
            }
            else
            {
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}
```

---

# 🔥 Most Important Understanding

### What is `leftMax`?

Highest bar seen from the **left side**.

### What is `rightMax`?

Highest bar seen from the **right side**.

### What does `min(leftMax, rightMax)` mean?

The **maximum possible water level**.

### Why subtract `height[i]`?

Because the bar itself occupies that height.

```text
water = waterLevel - barHeight
```

---

# ⭐ Why Compare `leftMax` and `rightMax`?

```cpp
if(leftMax < rightMax)
```

Suppose:

```text
leftMax  = 2
rightMax = 5
```

Then:

```text
min(2,5) = 2
```

So the left side determines the water level.

We can safely process:

```cpp
height[left]
```

because no matter how tall the right side becomes:

```text
min(2, anything) = 2
```

Therefore:

```cpp
water += leftMax - height[left];
left++;
```

Similarly, if:

```text
rightMax < leftMax
```

we process the right side.

---

# 🧪 Example

```text
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```

Water trapped at each position:

```text
[0,0,1,0,1,2,1,0,0,1,0,0]
```

Total:

```text
1 + 1 + 2 + 1 + 1 = 6
```

---

# ⚠️ Common Mistakes

### ❌ Mistake 1

Moving both pointers:

```cpp
left++;
right--;
```

They should move **one at a time**.

```text
Process LEFT  → left++

Process RIGHT → right--
```

---

### ❌ Mistake 2

Using current height instead of maximum:

```cpp
water += height[left] - ...
```

Water depends on the **highest boundary**, not just the current bar.

---

### ❌ Mistake 3

Forgetting to update the maximum:

```cpp
if(height[left] >= leftMax)
    leftMax = height[left];
```

A new taller bar becomes the new boundary and traps no water itself.

---

# 🧠 One-Line Revision

> **For every position, water is limited by the smaller of the highest bars on the left and right. Two pointers avoid storing the entire prefix/suffix arrays by processing the side with the smaller maximum boundary.**

```text
Formula:
water = min(leftMax, rightMax) - height[i]

Decision:
leftMax < rightMax → process LEFT
otherwise          → process RIGHT

Complexity:
Time  = O(n)
Space = O(1)
```

## 🔑 Pattern Recognition

When you see:

* Heights of bars
* Water trapped between bars
* Need total trapped water
* Need better than O(n²)

Think:

```text
Trapping Rain Water
        ↓
Prefix/Suffix Max
        ↓
Optimize
        ↓
Two Pointers
        ↓
leftMax + rightMax
```
