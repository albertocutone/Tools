
//Evaluate distance from TARGET points in a matrix grid.
class Solution {
private:
    const int EMPTY = INT_MAX;
    const int TARGET = 0;
    const int HOLES = -1; //can't pass here
    const vector<vector<int>> DIRECTIONS = {{-1,0},{0,1},{0,-1},{1,0}}; //left,right,up,down
    int rows,cols;
public:
    void distanceFromTarget(vector<vector<int>>& matrix) {
        //check matrix sizes
        rows = matrix.size();
        if(rows==0) return;
        cols = matrix[0].size();

        queue<vector<int>> q;
        //insert targets in queue O(MxN)
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(rooms[row][col] == TARGET){
                    q.push({row,col});
                }
            }
        }

        //Computes distance for each TARGET
        while(!q.empty()){
            //Retireve TARGET coordinates
            vector<int> point = q.front();
            q.pop();
            int row = point[0];
            int col = point[1];

            //Check the four directions left,right,up,down
            for(vector<int> dir : DIRECTIONS){
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];
                //check matrix boundaries
                if(nextRow<0 || nextRow>=rows) continue;
                if(nextCol<0 || nextCol>=cols) continue;
                //do not pass on visited points, neither HOLES
                if(rooms[nextRow][nextCol]!=EMPTY) continue;
                
                //Increase distance counter from target
                rooms[nextRow][nextCol] = rooms[row][col] + 1;

                //Insert in queue the adjacent cells
                q.push({nextRow,nextCol});
            }
        }
        return;
    }
};