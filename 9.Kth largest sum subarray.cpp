/* 3 -2 5

Sum of [0, 0] = 3
Sum of [0, 1] = 1
Sum of [0, 2] = 6
Sum of [1, 1] = -2
Sum of [1, 2] = 3
Sum of [2, 2] = 5

All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.
*/

/*
   APPROACH -1

    Time Complexity: O(N ^ 2 * log(N)
    Space Complexity: O(N ^ 2)

    where ‘N’ is the length of the given array/list.
*/


#include <algorithm>

int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();

	//	To store the subarray sum of every possible subarray.
	vector<int> bin;

	for (int i = 0; i < n; i++)
	{
		//	Stores the subarray sum.
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum + arr[j];
			bin.push_back(sum);
		}
	}

	//	Sort in non-increasing order.
	sort(bin.begin(), bin.end(), greater<int>());

	return bin[k - 1];
}




/*
APPROACH -2

    Time Complexity: O(N ^ 2 * log(K)
    Space Complexity: O(K)

    where ‘N’ is the length of the given array/list.
	And 'K' is the given number.
*/

#include <queue>

int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();

	//	To store the subarray sums.
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++)
	{
		//	To store the current subarray sum.
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum + arr[j];

			if (minHeap.size() < k)
			{
				minHeap.push(sum);
			}
			else
			{
				if (minHeap.top() < sum)
				{
					//	Pop the minimum element.
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}

	//	Top-most element is the k-th largest subarray sum.
	return minHeap.top();
}