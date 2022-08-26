#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

//Recursion: 
// time O(N)
// space O(N) - use call-stack
class RecursiveSolution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res){
        if(root!=nullptr)
        {      
            res.push_back(root->val);
            helper(root->left,res);
            helper(root->right,res);
        }
    }
};

//Iterative: 
// time O(N)
// space O(N) - use stack (LIFO) -> push right first then left. 
//                                  Left will be processed first
class IterativeSolution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        if(root){
            todo.push(root);
        }
        TreeNode* cur;
        while (!todo.empty()) {
            cur = todo.top();
            todo.pop();
            res.push_back(root->val);
            if(cur->right){
                todo.push(cur->right);
            }
            if(cur->left){
                todo.push(cur->left);
            }
        }
        return res;
    }
};