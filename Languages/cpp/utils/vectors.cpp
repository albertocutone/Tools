//Initialization: no need to allocate it with new, beacuse vecotr elements are already on the heap

//2-D vector
vector<vector<int>> test(NUM_ROWS,vector<int>(NUM_COLS,DEFAULT_VALUE));
//3-d vector
vector<vector<vector<int>>> test(DIM1,vector<vector<int>>(DIM2,vector<int>(DIM3,DEFAULT)));