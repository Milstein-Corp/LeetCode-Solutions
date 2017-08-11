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
    void constVector(TreeNode* root,vector<int> &v)
    {
       if(root==NULL)
           return;
        constVector(root->left,v);
        v.push_back(root->val);
        constVector(root->right,v);
    }
    
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    
    void correctVector(vector<int> &v)
    {
        int firstdrop1;
        int seconddrop;
        int dropcount=0;
        for(int i=0;i<v.size()-1;i++)
        {
             if(v[i] > v[i+1])
             {  // cout<<"dropcounde"<<endl;
                 if(dropcount==0)
                 {
                     firstdrop1=i;
                     dropcount++;
                 }else
                 if(dropcount==1)
                 {
                     seconddrop=i+1;
                     dropcount++;
                 }
             }
        }
        
       // cout<<dropcount<<" "<<firstdrop1<<" "<<seconddrop<<endl;
        
        
        
        if(dropcount==1)
        {
            swap(v[firstdrop1],v[firstdrop1+1]);
        }else if(dropcount==2){
            swap(v[firstdrop1],v[seconddrop]);
        }
    } 
    
    void constBst(TreeNode* root,vector<int> v,int &index)
    {
        if(root==NULL)
            return;
        constBst(root->left,v,index);
       // cout<<"for a specific root:"<<root->val<<" ";
        root->val=v[index];
           index++;
        constBst(root->right,v,index);
    }
    
    void print(vector<int> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    void recoverTree(TreeNode* root) {
            vector<int> v;
        int index=0;
        constVector(root,v);
        //print(v);
        correctVector(v);
       // print(v);
        constBst(root,v,index);
    }
};