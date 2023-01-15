//Expected Time Complexity: O(N)
//Expected Space Complexity: O(N)

class Solution {
  public:
  
    bool isCBT(struct Node* tree, int i, int count)
     {
         if(tree==NULL)
         return true;
         
         if(i>=count)
         return false;
         
         else
         {
             bool left=isCBT(tree->left, 2*i+1, count);
             bool right=isCBT(tree->right, 2*i+2, count);
             return left && right;
         }
     }
     
    bool isMaxOrder(struct Node* tree)
     {
        
         
         if(tree->left==NULL && tree->right==NULL)
         return true;
         
         if(tree->right==NULL)
         return (tree->data > tree->left->data);
         
         else
         {
         
         bool left=isMaxOrder(tree->left);
         bool right=isMaxOrder(tree->right);
         
         return (left && right && (tree->data > tree->left->data && tree->data > tree->right->data));
         
         }  
         
     }
     
     int countNodes(struct Node* tree)
     {
         if(tree==NULL)
         return 0;
         
         int ans=1 + countNodes(tree->left) + countNodes(tree->right);
         return ans;
     }
    bool isHeap(struct Node* tree) {
       
       // find the total no. of nodes
       int count=countNodes(tree);
      
       if( (isCBT(tree,0,count)) && (isMaxOrder(tree)))
       {
           return true;
       }
       else
       return false;
    }
};