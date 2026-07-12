Given an array a of length n and an integer k. 

You
must perform the following operation exactly k times:
choose two indices i, j and swap**(ai, aj).**

Find the maximum possible MSS

(maximum
subarray sum) after performing the above operation
exactly k times.

Case 1
Input:
3
1
1
-5
Output:
3



solution:

#include <bits/stdc++.h>
using namespace std;

long long helper(int n, vector<int>& v, int k) {
    long long maxy = LLONG_MIN;

    for (int L = 0; L < n; L++) {
        long long sum = 0;

        for (int R = L; R < n; R++) {
            sum += v[R];

            vector<int> inner;
            vector<int> outer;

            for (int i = 0; i < n; i++) {
                if (i >= L && i <= R) {
                    inner.push_back(v[i]);
                } else {
                    outer.push_back(v[i]);
                }
            }

            sort(inner.begin(), inner.end());
            sort(outer.rbegin(), outer.rend());

            long long improved = sum;

            int limit = min({
                k,
                (int)inner.size(),
                (int)outer.size()
            });

            for (int i = 0; i < limit; i++) {
                if (outer[i] > inner[i]) {
                    improved += outer[i] - inner[i];
                } else {
                    break;
                }
            }

            maxy = max(maxy, improved);
        }
    }

    return maxy;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << helper(n, v, k);

    return 0;
}

tips .. find every possible sub array sum with n^2;
        1. store the sum of a subarray ;
        2. make two vectors outer and inner 
        3. sort both ,, outer in reverse
        4. find min btw size of outer,inner,k 
        5. in limit exchange value and improved new sum;
        6. compare and return maxy(maxsum)