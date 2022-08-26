#include "TreeNode.h"
#include <vector>

using namespace std;

//Recursion: 
// time O(N)
// space O(N) - use stack
class RecursiveSolution {
private:
    void helper(TreeNode* root, vector<int>& res){
        if(!root) return;
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
public:
    vector<int> inorderTraversel(TreeNode* root){
        vector<int> res;
        helper(root,res);
        return res;
    }
}