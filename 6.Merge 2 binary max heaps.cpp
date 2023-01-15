//Expected Time Complexity: O(n.Logn)
//Expected Auxiliary Space: O(n + m)

// 0-based indexing
class Solution{
    public:
    
    void heapify(vector<int> &ans, int size, int i)
    {
        int index=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && ans[left] > ans[index])
        index=left;
        if(right<size && ans[right] > ans[index])
        index=right;
        
        if(index!=i)
        {
            swap(ans[index],ans[i]);
            heapify(ans, size, index);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
       for(auto i:a)
           ans.push_back(i);

        for(auto i:b)
           ans.push_back(i);
      
      int size=ans.size();
      
      for(int i=size/2-1; i>=0; i--)
      {
          heapify(ans, size, i);
      }
      return ans;
    }
};