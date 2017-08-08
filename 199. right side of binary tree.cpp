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


More Better approach. without extra map space.

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
    
    void rightSideViewUtil(TreeNode* root,int level,int &maxlevel,vector<int> &v)
    {
        if(root==NULL)
            return ;
        
        if(level>maxlevel)
        {
            v.push_back(root->val);
            maxlevel=level;
        }
        rightSideViewUtil(root->right,level+1,maxlevel,v);
        rightSideViewUtil(root->left,level+1,maxlevel,v);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        int maxlevel=0;
        rightSideViewUtil(root,1,maxlevel,v);
        return v;
    }
};