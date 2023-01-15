/*

ALL LIST ARE SORTED.

Test case 1:

2 4 5
5 6 7

The given list are [2, 4, 5],
                   [5, 6, 7].
The range [5, 5] will include 5 which is present in both the list 
and hence the length of this range is 1. 
This is the only possible range having the minimum length.


Test case 2 :

1 1
9 12
4 9

The given list are [1, 1],
                   [9, 12], 
                   [4, 9]. 
The range [1, 9] will include 1 which is present in the first list, and 9 which include in both the second and third list 
The length of the range is 9 (9 - 1 + 1 = 9).

*/

/*

   APPROACH-1:
   
	Time Complexity: O(N^3 * K^3)
	Space complexity: O(N*K)

	Where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.

*/

#include <limits.h>

#include <algorithm>

// This function will return true if given start end include at least element from each list
bool validRange(vector<vector<int>> &a, int start, int end, int k, int n) {
    for (int i = 0; i < k; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            // Check if any element lie in our current range
            if (start <= a[i][j] && a[i][j] <= end) {
                found = true;
                break;
            }
        }
        // If we can not find any elements which lie in our range then we return false
        if (!found) {
            return false;
        }
    }
    // If for each element in the list we always find some element which lie in our range then we return true
    return true;
}

int kSorted(vector<vector<int>> &a, int k, int n) {
    vector<int> list;
    // Storing all the elements in 1D list
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            list.push_back(a[i][j]);
        }
    }
    sort(list.begin(), list.end());
    int ans = INT_MAX;
    // Check for all possible range
    for (int i = 0; i < list.size(); ++i) {
        for (int j = i; j < list.size(); ++j) {
            int start = list[i];
            int end = list[j];
            // If current range is valid then compare its len with minimum length
            if (validRange(a, start, end, k, n)) {
                int len = end - start + 1;
                ans = min(ans, len);
            }
        }
    }

    return ans;
}


