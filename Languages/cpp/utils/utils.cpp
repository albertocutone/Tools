//hashTables
Set is a container that stores sorted and unique elements.
Unordered_set does not sort and stores unique elements.
Multi_set can have duplicate elements but is sorted.
Unordered_multiset, which can have duplicates but is not sorted.

bool findDuplicates(vector<Type>& keys) {
    // Replace Type with actual type of your key
    unordered_set<Type> hashset;
    for (Type key : keys) {
        if (hashset.count(key) > 0) {
            return true;
        }
        hashset.insert(key);
    }
    return false;
}
/*
 * Template for using hash map to find duplicates.
 * Replace ReturnType with the actual type of your return value.
 */
ReturnType aggregateByKey_hashmap(vector<Type>& keys) {
    // Replace Type and InfoType with actual type of your key and value
    unordered_map<Type, InfoType> hashtable;
    for (Type key : keys) {
        if (hashmap.count(key) > 0) {
            if (hashmap[key] satisfies the requirement) {
                return needed_information;
            }
        }
        // Value can be any information you needed (e.g. index)
        hashmap[key] = value;
    }
    return needed_information;
}
//picking digits off one-by-one.
//In this particular case, sum the square of digits and return sum
//Finding the next value for a given number has a cost of O(logn)
int getNext(int n){
    int sum = 0;
    while(n>0){
        int digit = n%10;
        n=n/10;
        sum+=digit*digit;
    }
    return sum;
}

//Working with ASCII chars
// c - 'a' -> return the ASCII value of char c, with offset a
// num - '0' -> return the in value num -> ASCII(num) - offset 0 = int(num)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<vector<int>,vector<string>> umap;
    for(string &s:strs){
        vector<int> vec(26,0);
        for(char &c:s){
            vec[c-'a']++;
        }
        umap[vec].push_back(s);
    }
    for(auto &x:umap){
        ans.push_back(x.second);
    }
    return ans;
}


char shiftLetterTo_a_char(char letter, int shift) {
    return (letter - shift + 26) % 26 + 'a';
}
