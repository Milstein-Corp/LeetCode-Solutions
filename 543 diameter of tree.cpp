/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int heightTree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh=heightTree(root->left)+1;
        int rh=heightTree(root->right)+1;
      return max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lh=heightTree(root->left);
        int rh=heightTree(root->right);
        
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        
        return max(ld,max(rd,lh+rh));
    }
};