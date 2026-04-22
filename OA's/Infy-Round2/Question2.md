# Maximum Value Problem (Kadane + Modulo + long long)

## Problem Statement

You are given an integer array `A` of size `N`.

### Constraints

* `1 ≤ N ≤ 10^5`
* `-10^9 ≤ A[i] ≤ 10^9`

### Task

* You are allowed to choose **at most one contiguous subarray**.
* You can perform an operation equivalent to **adding the sum of that subarray once more to the total array sum**.

### Objective

* Compute the **maximum possible value** of the array sum after performing the operation.

### Output

* Return the result modulo:

```
MOD = 10^9 + 7
```

### Final Expression

The optimal result can be expressed as:

```
(total_sum + maximum_subarray_sum) % MOD
```

Where:

* `total_sum` = sum of all elements of the array
* `maximum_subarray_sum` = maximum sum of any contiguous subarray (using Kadane’s Algorithm)

---

## Step 1: Understanding Kadane’s Algorithm

Kadane finds the maximum subarray sum in **O(N)**.

Core idea:

```
curr_sum += A[i]
if (curr_sum < 0) curr_sum = 0
max_sub = max(max_sub, curr_sum)
```

### Why this works

* Negative sum → useless → reset
* Positive sum → keep extending

---

## Step 2: Why NOT use modulo inside Kadane

### Wrong approach

```
curr_sum = (curr_sum + A[i]) % MOD
```

### Why this breaks

Kadane depends on:

* Sign (`< 0` check)
* Magnitude (comparison)

Modulo destroys both.

### Example

```
MOD = 10
A = [8, 5]
```

Real sum:

```
8 + 5 = 13
```

With modulo:

```
(8 + 5) % 10 = 3
```

Now algorithm thinks sum is `3` instead of `13` → WRONG

---

## Step 3: Why we use `long long`

### Constraint

```
A[i] ∈ [-1e9, 1e9]
N up to 1e5
```

### Worst case sum

```
1e5 × 1e9 = 1e14
```

### Compare with data types

| Type      | Max Value  |
| --------- | ---------- |
| int       | ~2 × 10^9  |
| long long | ~9 × 10^18 |

👉 `int` **cannot store 1e14** → overflow
👉 `long long` **can**

---

## Step 4: What overflow actually does

Overflow does NOT give error.

```
int x = 1000000000;
x = x + x + x;  // overflow
```

Result becomes garbage (often negative).

This breaks:

* Kadane comparisons
* Maximum calculation

---

## Step 5: Where MOD should be used

### Safe place

While computing total sum:

```
total_sum = (total_sum + A[i]) % MOD
```

Why?

* Pure arithmetic
* No comparisons

---

### NOT safe

Inside Kadane:

```
curr_sum = (curr_sum + A[i]) % MOD   ❌
```

---

### Final step

```
result = (total_sum + max_sub) % MOD
if (result < 0) result += MOD
```

---

## Step 6: Final Correct C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

long long getMaximumValue(int N, vector<long long>& A) {
    const int MOD = 1e9 + 7;

    long long total_sum = 0;
    long long curr_sum = 0;
    long long mx_sub = 0;

    for (auto x : A) {
        // safe modulo here
        total_sum = (total_sum + x) % MOD;

        // Kadane (NO modulo here)
        curr_sum += x;
        mx_sub = max(mx_sub, curr_sum);
        if (curr_sum < 0) curr_sum = 0;
    }

    long long result = (total_sum + mx_sub) % MOD;
    if (result < 0) result += MOD;

    return result;
}
```

---

## Step 7: Final Takeaways

* Kadane needs **real values**, not modulo values
* Modulo breaks comparison-based logic
* `long long` is required because sums reach **1e14**
* MOD is only for:

  * preventing large output
  * formatting final result

---

## One-line Summary

> Use `long long` for correctness, use `% MOD` only where mathematically valid — not inside Kadane.
