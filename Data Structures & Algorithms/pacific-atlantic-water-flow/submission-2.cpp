class Solution {
public:

    bool atlantic1(vector<vector<int>>& heights, vector<vector<int>> &visited2, int i, int j){

        int row = heights.size();
        int col = heights[0].size();

        if(i == row-1 || j == col-1 ){
            return true;
        }

        if(visited2[i][j] == 1){
            return false;
        }

        visited2[i][j] = 1;

        bool down = false;
        if(i+1 < row && heights[i+1][j] <= heights[i][j]){
            down = atlantic1(heights, visited2, i+1, j);
        }

        bool up = false;
        if(i-1 >= 0 && heights[i-1][j] <= heights[i][j]){
            up = atlantic1(heights, visited2, i-1, j);
        }

        bool right = false;
        if(j+1 < col && heights[i][j+1] <= heights[i][j]){
            right = atlantic1(heights, visited2, i, j+1);
        }

        bool left = false;
        if(j-1 >= 0 && heights[i][j-1] <= heights[i][j]){
            left = atlantic1(heights, visited2, i, j-1);
        }

        return (right || down || left || up);

    }

    bool pasafic1(vector<vector<int>>& heights, vector<vector<int>> &visited1, int i, int j){

        int row = heights.size();
        int col = heights[0].size();

        if(i == 0 || j == 0){
            return true;
        }

        if(visited1[i][j] == 1){
            return false;
        }

        visited1[i][j] = 1;

        bool down = false;
        if(i+1 < row && heights[i+1][j] <= heights[i][j]){
            down = pasafic1(heights, visited1, i+1, j);
        }

        bool up = false;
        if(i-1 >= 0 && heights[i-1][j] <= heights[i][j]){
            up = pasafic1(heights, visited1, i-1, j);
        }

        bool right = false;
        if(j+1 < col && heights[i][j+1] <= heights[i][j]){
            right = pasafic1(heights, visited1, i, j+1);
        }

        bool left = false;
        if(j-1 >= 0 && heights[i][j-1] <= heights[i][j]){
            left = pasafic1(heights, visited1, i, j-1);
        }

        return (right || down || left || up);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> ans;

        for(int i = 0; i<row; i++){

            for(int j = 0; j<col; j++){

                vector<vector<int>> visited1(row, vector<int>(col, 0));
                vector<vector<int>> visited2(row, vector<int>(col, 0));

                bool pacific = pasafic1(heights, visited1, i, j);
                bool atlantic = atlantic1(heights, visited2, i, j);

                if(pacific && atlantic){
                    ans.push_back({i, j});
                }

            }
        }

        return ans;
    }
};
