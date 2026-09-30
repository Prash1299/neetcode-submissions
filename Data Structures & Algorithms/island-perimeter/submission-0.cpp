class Solution {
public:

    int perimeter(vector<vector<int>>& grid, int i, int j){

        int row = grid.size();
        int col = grid[0].size();

        int count = 0;

        //down
        if(i+1 < row && grid[i+1][j] == 0){
            count++;
        }

        if(i+1 >= row){
            count++;
        }

        //Right
        if(j+1 < col && grid[i][j+1] == 0){
            count++;
        }

        if(j+1 >= col){
            count++;
        }

        //Left
        if(j-1 >= 0 && grid[i][j-1] == 0){
            count++;
        }

        if(j-1 < 0){
            count++;
        }

        //UP
        if(i-1 >= 0 && grid[i-1][j] == 0){
            count++;
        }

        if(i-1 < 0){
            count++;
        }

        return count;


    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int i = 0;
        int j = 0;

        int peri = 0;

        while(i < row){

            j = 0; 
            
            while(j < col){

                if(grid[i][j] == 1){
                    peri = peri + perimeter(grid, i, j);
                }

                j++;
            }

            i++;

        }

        return peri;
    }
};