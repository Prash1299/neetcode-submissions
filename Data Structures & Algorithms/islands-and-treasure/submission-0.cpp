class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int land = INT_MAX;

        queue<pair<int,int>> q;

        // Put all treasures into queue
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            // UP
            if(r - 1 >= 0 && grid[r-1][c] == land) {
                grid[r-1][c] = grid[r][c] + 1;
                q.push({r-1, c});
            }

            // DOWN
            if(r + 1 < row && grid[r+1][c] == land) {
                grid[r+1][c] = grid[r][c] + 1;
                q.push({r+1, c});
            }

            // LEFT
            if(c - 1 >= 0 && grid[r][c-1] == land) {
                grid[r][c-1] = grid[r][c] + 1;
                q.push({r, c-1});
            }

            // RIGHT
            if(c + 1 < col && grid[r][c+1] == land) {
                grid[r][c+1] = grid[r][c] + 1;
                q.push({r, c+1});
            }
        }
    }
};