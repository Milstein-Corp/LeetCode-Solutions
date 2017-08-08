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
    
    void rightSideViewUtil(TreeNode* root,map<int,int> &m,int level=0)
    {
        if(root==NULL)
            return ;
        
        if(m[level]==0)
        {
            m[level]=root->val;
        }
        rightSideViewUtil(root->right,m,level+1);
        rightSideViewUtil(root->left,m,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> m;
        rightSideViewUtil(root,m);
        vector<int> v;
        map<int,int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            v.push_back(itr->second);
        }
        return v;
    }
};