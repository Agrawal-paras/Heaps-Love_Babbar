/* APPROACH 1-

    Time Complexity: O((N * K) * log(N * K))
    Space Complexity: O(N * K)
    
    Where K is the number of arrays and N is the average number of elements in every array.
*/

#include<algorithm>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Output array.
    vector<int> result;
    
    // Traverse all the k vectors.
    for(int i = 0;i < k; i++)
    {
        for(int j = 0; j < kArrays[i].size(); j++)
        {
            // Add the element to the output array.
            result.push_back(kArrays[i][j]);
        }
    }
    
    // Sort the output array.
    sort(result.begin(), result.end());
    
    return result;
}





/*
    APPROACH - 2

    Time Complexity: O((N * K) * log(K))
    Space Complexity: O((N * K )* log(K))
    
    Where K is the number of arrays and N is the average number of elements in every array. 
*/

vector<int> merge(vector<int>&a, vector<int>&b)
{
    vector<int>ans; 
    
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    
    // Traverse the both arrays.
    while(i < n and j < m)
    {
        if(a[i] < b[j])
        {
            ans.push_back(a[i]);
            i += 1;
        }
        else
        {
            ans.push_back(b[j]);
            j += 1;
        }
    }
    
    // Add remaining elements of the first array.
    while(i < n)
    {
        ans.push_back(a[i]);
        i += 1;
    }
    
    // Add remaining elements of the second array.
    while(j < m)
    {
        ans.push_back(b[j]);
        j += 1;
    }
    
    return ans; 
}

vector<int>  mergeKSortedArraysHelper(vector<vector<int>>&kArrays, int start, int end)
{
    // If there is only one array.
    if(start == end)
    {
        return kArrays[start];
    }
    
    // If there are only two arrays, merge them.
    if(start + 1 == end)
    {
        return merge(kArrays[start], kArrays[end]);
    }
    
    int mid = start + (end - start)/2;
    
    // Divide the arrays into two halves.
    vector<int> first = mergeKSortedArraysHelper(kArrays, start, mid);
    vector<int> second = mergeKSortedArraysHelper(kArrays, mid + 1, end);
    
    // Return the final merged array.
    return merge(first, second);
    
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> result = mergeKSortedArraysHelper(kArrays, 0, k - 1);
    return result;
}




/*
    APPROACH - 3
    Time Complexity: O((N * K) * log(K)) 
    Space Complexity: O(N * K)
    
    Where N is the total number of elements in all the arrays, and K is the number of arrays.
*/

#include<queue>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> result; 
  
    // Create a min heap to store atmost k heap nodes at a time.
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > minHeap; 
  
    for (int i = 0; i < kArrays.size(); i++)
    {
        minHeap.push({ kArrays[i][0], { i, 0 } });                  // Time Complexity-O(K*log(K))
    }
  
    while (minHeap.empty() == false) 
    { 
    
        // Remove the minimum element from the heap.
        pair<int, pair<int, int> > curr = minHeap.top(); 
        minHeap.pop(); 
  
        // i is the array number and j is the index of the removed element in the ith array.
        int i = curr.second.first; 
        int j = curr.second.second;                                            // Time Complexity-O(N*K*log(K))    
    
        // Add the removed element to the output array.
        result.push_back(curr.first);                   // Space Complexity-O(N*K)
  
        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size())
        {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    } 
  
    // Return the output array.
    return result; 
}
