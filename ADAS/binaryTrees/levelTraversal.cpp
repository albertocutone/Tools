#include "TreeNode.h"
#include <vector>

//Recursion
class RecursiveSolution1 {
public:
    vector<vector<int>> solve(vector<TreeNode*> k, vector<vector<int>> res){
        if (k.size()==0) return res;
        
        vector<TreeNode*> newk;
        vector<int> lvl;
        
        for (int i=0; i < k.size(); i++){
            lvl.push_back( k[i] -> val );
            if ( k[i] -> left ) newk.push_back( k[i] -> left);
            if ( k[i] -> right ) newk.push_back( k[i] -> right);
        }
        
        res.push_back(lvl);
        return solve(newk, res);

    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> k{root};
        vector<vector<int>> res;
        
        if (root==NULL) return res;
        
        return solve(k,res);
    }
};
 
class RecursiveSolution2 {
    vector<vector<int>> sol;
	void helper(TreeNode* node, int level)
	{
		if(node == NULL) return ;
		if(level ==  (int)sol.size()){
			vector<int> temp;
			sol.push_back(temp);
		}
		sol[level].push_back(node->val);
		if(node->left)  helper(node->left, level+1);
		if(node->right) helper(node->right, level+1);
		
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		if(root == NULL) return sol;
		helper(root, 0);
		return sol;
		
	}
};
//Iterative - use queue
class IterativeSolution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        TreeNode* cur;
        while (!q.empty()) {
            int size = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < size; ++i) {		// traverse nodes in the same level
                cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);		// visit the root
                if (cur->left) {
                    q.push(cur->left);				// push left child to queue if it is not null
                }
                if (cur->right) {
                    q.push(cur->right);				// push right child to queue if it is not null
                }
            }
        }
        return ans;
    }
};