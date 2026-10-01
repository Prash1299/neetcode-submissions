class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;

        while(!q.empty() && fresh > 0){ 
            // valids when there is always 1 member in queue not more then that but when ther eis more then 1 then we will increase the time when queue becomes empty

            int size = q.size();

            while(size--){

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                //down
                if(i+1 < row && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    fresh--;
                }

                //right
                if(j+1 < col && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    fresh--;
                }

                //up
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    fresh--;
                }

                //left
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    fresh--;
                }
            }
        
            time++;
        }

        if(fresh > 0){
            return -1;
        }

        return time;
    }
};
