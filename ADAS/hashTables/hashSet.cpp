class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x): val(x) {}
};

class BSTree {
private:
    
public:
    TreeNode* root = nullptr;
    TreeNode* searchBST(TreeNode* root, int val){
        if(!root || val == root->val) return root;
        return val < root->val ? searchBST(root->left,val) : 
                                 searchBST(root->right,val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        if(val>root->val){
            root->right = insertIntoBST(root->right,val);
        } else if (val==root->val){
            return root;
        } else {
            root->left = insertIntoBST(root->left,val);
        }
        return root;
    }
    int successor(TreeNode* root){
        root = root->right;
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    int predecessor(TreeNode* root){
        root = root->left;
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return nullptr;
        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(!root->left && !root->right){
                root = nullptr;
            }
            else if(root->right){
                root->val = successor(root);
                root->right = deleteNode(root->right,root->val);
            }
            else{
                root->val = predecessor(root);
                root->left = deleteNode(root->left,root->val);
            }
        }
        return root;
    }
};
class Bucket {
private:
    BSTree* tree;
public:
    Bucket(){
        tree = new BSTree();
    }
    
    void insert(int key){
        tree->root = tree->insertIntoBST(tree->root, key);
    }
    
    void remove(int key){
        tree->root = tree->deleteNode(tree->root,key);
    }
    
    bool exist(int key){
        TreeNode* node = tree->searchBST(tree->root,key);
        return (node!=nullptr);
    }
};


class MyHashSet {
private:
    int keyRange;
    vector<Bucket> vBucket; 
protected:
    int _hash(int key){
        return (key % keyRange);
    }
public:
    MyHashSet() {
        keyRange = 769; //shuld be a prime number
        vector<Bucket>* temp(new vector<Bucket>(keyRange));
        vBucket = *temp;

    }
    
    void add(int key) {
        int bucketIndex = _hash(key);
        vBucket[bucketIndex].insert(key);
    }
    
    void remove(int key) {
        int bucketIndex = _hash(key);
        vBucket[bucketIndex].remove(key);
    }
    
    bool contains(int key) {
        int bucketIndex = _hash(key);
        return vBucket[bucketIndex].exist(key);
    }
};



/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */