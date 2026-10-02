class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int land = INT_MAX;

        queue<pair<int, int>> q;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
            
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            //down
            if(i+1 < row && grid[i+1][j] == land){
                grid[i+1][j] = 1 + grid[i][j];
                q.push({i+1, j});
            }

            if(j+1 < col && grid[i][j+1] == land){
                grid[i][j+1] = 1 + grid[i][j];
                q.push({i, j+1});
            }

            if(i-1 >= 0 && grid[i-1][j] == land){
                grid[i-1][j] = 1 + grid[i][j];
                q.push({i-1, j});
            }

            if(j-1 >= 0 && grid[i][j-1] == land){
                grid[i][j-1] = 1 + grid[i][j];
                q.push({i, j-1});
            }
            
        }
    }
};
