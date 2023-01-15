/*    N = 6
      arr[] = 7 10 4 3 20 15
      K = 3
      Expected Time Complexity: O(n)
      Expected Auxiliary Space: O(K)

   // arr : given array
   // l : starting index of the array i.e 0
   // r : ending index of the array i.e size-1
   // k : find kth smallest element and return using this function*/
    
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> q;  //max heap 
        
        for(int i=0; i<k; i++)
        {
            q.push(arr[i]);
            
        }
        for(int i=k; i<=r; i++)
        {
            if(arr[i] < q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        return q.top();
    }
