// Depth First Search
// Find node in a graph using dfs

//If using stack, the max space allocated for the stack is h(height of the graph)

bool dfs(Node* cur, Node* target, set<Node*> visited){
    if( cur == nullptr ) return nullptr;
    if( cur == target ) return true;
    for(next : neighbors of cur ){
        if(next is not visited){
            add next to visited;
            return true if dfs(next,target,visited) == true;
        }
    }
    return false;
}

//if the depth of recursion is too high, you will suffer from stack overflow. 
//In that case, you might want to use BFS instead or implement DFS using an explicit stack.

/*
 * Return true if there is a path from cur to target.
 */
bool DFS(Node* root, int target) {
    set<Node*> visited;
    stack<Node*> stack;
    st.push(root);
    while (!st.empty()) {
        Node* cur = st.top();
        st.pop();
        if(cur->val==target){
            return true;
        }
        for (Node* next : cur->neighbors) {
            if (visited.find(next)==visited.end()) {
                visited.insert(next);
                st.push(next);
            }
        }
    }
    return false;
}