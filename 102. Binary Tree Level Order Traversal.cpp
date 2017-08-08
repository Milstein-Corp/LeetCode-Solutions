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
    vector<vector<int>> levelOrder(TreeNode* root) {
    
       vector<vector<int> > v;
        if(root==NULL)
            return v;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int i=0;
        while(!q.empty())
        {
              TreeNode* temp=q.front();
              q.pop();
            
              if(temp!=NULL)
              {   level.push_back(temp->val); 
               
                  if(temp->left!=NULL)
                  {
                      q.push(temp->left);
                  }
                  if(temp->right!=NULL)
                  {
                      q.push(temp->right);
                  }
              }
            else {
                   v.push_back(level);
                   if(!q.empty())
                   {
                    q.push(NULL);
                   }
                i++;
                level.clear();
            }
                  
        }
        return v;
    }
};