class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> judge;

        for(auto edge : trust){
            int u = edge[0];
            int v = edge[1];

            judge[u]--;   // u trust someone
            judge[v]++;   // someone trust v
        }

        for(int i = 1; i<=n; i++){
            if(judge[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};