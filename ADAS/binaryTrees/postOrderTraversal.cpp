#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

//Recursion: 
// time O(N)
// space O(N) - use stack
class RecursiveSolution {
private:
    void helper(TreeNode* root,vector<int>& res){
        if(!root) return;
        helper(root->left,res);
        helper(root->right,res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        helper(root,res);
        return res;
    }
};


//postOrder: left,right,root == - (root,right,left)
class IterativeSolution {
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        if(root){
            st.push(root);
        }
        TreeNode* cur;
        while(!st.empty()){
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
        }

        reverse(res.begin(),res.end());

        return res;
    }

};
