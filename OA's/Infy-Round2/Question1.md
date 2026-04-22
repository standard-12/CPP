# Problem: Maximum Length Subsequence with At Most One Sign Change

## Problem Statement

You are given an array of **non-zero integers**.

You need to select a **subsequence (not necessarily contiguous)** such that:

* The subsequence has **maximum possible length**
* The **sign (positive/negative)** can change **at most once**

### Valid patterns:

* All positive
* All negative
* Positive → Negative
* Negative → Positive

---

# Solution 1: Prefix-Suffix (Optimal)

## Key Idea

Since subsequence allows skipping elements, we can:

* Choose all elements of one sign before a split
* Choose all elements of the opposite sign after the split

---

## Approach

Define:

* `prefPos[i]` = number of positives in `[0..i]`
* `prefNeg[i]` = number of negatives in `[0..i]`
* `sufPos[i]` = number of positives in `[i..n-1]`
* `sufNeg[i]` = number of negatives in `[i..n-1]`

---

## Try all cases

1. No sign change:

   * All positives
   * All negatives

2. One sign change:

   * Positive → Negative: `prefPos[i] + sufNeg[i+1]`
   * Negative → Positive: `prefNeg[i] + sufPos[i+1]`

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubseq(vector<int>& a) {
    int n = a.size();

    vector<int> prefPos(n), prefNeg(n);
    vector<int> sufPos(n), sufNeg(n);

    prefPos[0] = (a[0] > 0);
    prefNeg[0] = (a[0] < 0);

    for (int i = 1; i < n; i++) {
        prefPos[i] = prefPos[i-1] + (a[i] > 0);
        prefNeg[i] = prefNeg[i-1] + (a[i] < 0);
    }

    sufPos[n-1] = (a[n-1] > 0);
    sufNeg[n-1] = (a[n-1] < 0);

    for (int i = n-2; i >= 0; i--) {
        sufPos[i] = sufPos[i+1] + (a[i] > 0);
        sufNeg[i] = sufNeg[i+1] + (a[i] < 0);
    }

    int ans = max(prefPos[n-1], prefNeg[n-1]);

    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, prefPos[i] + sufNeg[i+1]);
        ans = max(ans, prefNeg[i] + sufPos[i+1]);
    }

    return ans;
}
```

---

## Complexity

* Time: O(N)
* Space: O(N)

---

# Solution 2: DP Tabulation (3D)

## State Definition

```
dp[i][s][f]
```

* `i` → index
* `s` → sign (0 = negative, 1 = positive)
* `f` → flip used (0 = no, 1 = yes)

Value = max subsequence length

---

## Transitions

* Skip current element
* Take element if valid:

  * Same sign → extend
  * Different sign → allowed only if flip not used

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    int n = a.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, 0)));

    if (a[0] > 0) dp[0][1][0] = 1;
    else dp[0][0][0] = 1;

    for (int i = 1; i < n; i++) {
        int curr = (a[i] > 0 ? 1 : 0);

        for (int s = 0; s < 2; s++)
            for (int f = 0; f < 2; f++)
                dp[i][s][f] = dp[i-1][s][f];

        dp[i][curr][0] = max(dp[i][curr][0], 1);

        for (int s = 0; s < 2; s++) {
            for (int f = 0; f < 2; f++) {
                if (dp[i-1][s][f] == 0) continue;

                if (curr == s)
                    dp[i][s][f] = max(dp[i][s][f], dp[i-1][s][f] + 1);
                else if (f == 0)
                    dp[i][curr][1] = max(dp[i][curr][1], dp[i-1][s][0] + 1);
            }
        }
    }

    int ans = 0;
    for (int s = 0; s < 2; s++)
        for (int f = 0; f < 2; f++)
            ans = max(ans, dp[n-1][s][f]);

    return ans;
}
```

---

## Complexity

* Time: O(N)
* Space: O(N)

---

# Solution 3: Memoization (Top-Down DP)

## State

```
(i, lastSign, usedFlip)
```

* `lastSign = -1, 0, 1`
* `usedFlip = 0/1`

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int dp[1001][3][2];

int solve(int i, int lastSign, int usedFlip) {
    if (i == n) return 0;

    int &res = dp[i][lastSign + 1][usedFlip];
    if (res != -1) return res;

    int curr = (a[i] > 0 ? 1 : 0);

    res = solve(i + 1, lastSign, usedFlip);

    if (lastSign == -1)
        res = max(res, 1 + solve(i + 1, curr, 0));
    else if (curr == lastSign)
        res = max(res, 1 + solve(i + 1, curr, usedFlip));
    else if (usedFlip == 0)
        res = max(res, 1 + solve(i + 1, curr, 1));

    return res;
}

int maxSubseq(vector<int>& arr) {
    a = arr;
    n = a.size();

    memset(dp, -1, sizeof(dp));

    return solve(0, -1, 0);
}
```

---

## Complexity

* Time: O(N)
* Space: O(N)

---

# Final Comparison

| Approach      | Complexity | Difficulty | Notes                   |
| ------------- | ---------- | ---------- | ----------------------- |
| Prefix-Suffix | O(N)       | Easy       | Best solution           |
| DP Tabulation | O(N)       | Medium     | Explicit state tracking |
| Memoization   | O(N)       | Medium     | Easier to derive        |

---

# Key Insight

The problem looks like DP, but actually reduces to:

> Counting positives and negatives around a split point

That’s why prefix-suffix is the cleanest solution.
