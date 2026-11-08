class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited){

        int row = grid.size();
        int col = grid[0].size();
        
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0){
            return 1;
        }

        if(visited[i][j] == 1){
            return 0;
        }

        visited[i][j] = 1;

        int sum = 0;

        if(i+1 < row && !visited[i+1][j]){
            sum = sum + solve(grid, i+1, j, visited);
        }
        else if(i+1 >= row){
            sum++;
        }

        if(j+1 < col && !visited[i][j+1]){
            sum = sum + solve(grid, i, j+1, visited);
        }
        else if(j+1 >= col){
            sum++;
        }

        if(i-1 >=0 && !visited[i-1][j]){
            sum = sum + solve(grid, i-1, j, visited);
        }
        else if(i-1 < 0){
            sum++;
        }

        if(j-1 >= 0 && !visited[i][j-1]){
            sum = sum + solve(grid, i, j-1, visited);
        }
        else if(j-1 < 0){
            sum++;
        }

        return sum;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    return solve(grid, i, j, visited);
                }
            }
        }

        return -1;
    }
};