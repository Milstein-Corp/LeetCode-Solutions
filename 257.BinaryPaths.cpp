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
    
    string stringFormation(int *arr,int level)
    {
        string str="";
        for(int i=0;i<=level;i++)
        {
             str.append(to_string(arr[i]));
            if(i!=level)
            str.append("->");
        }
        return str;
    }
    
    void binaryTreePathsUtil(TreeNode* root,int *arr,vector<string> &vtr,int level=0)
    {
         if(root==NULL)
            return;
        arr[level]=root->val;
       
        if(root->left==NULL && root->right==NULL)
        {
          vtr.push_back(stringFormation(arr,level));
            return;
        }
        binaryTreePathsUtil(root->left,arr,vtr,level+1);
       binaryTreePathsUtil(root->right,arr,vtr,level+1);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vtr;
        int arr[1000];
        binaryTreePathsUtil(root,arr,vtr);
        return vtr;
    }
};