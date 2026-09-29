class Solution {
public:

    void prepareList(unordered_map<int, vector<int>> &adjList, vector<vector<int>>& trust, unordered_map<int, int> &mayor){

        for(int i = 0; i<trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];

            //directed graph
            adjList[u].push_back(v);

            mayor[v]++;
        }
    }

    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_map<int, vector<int>> adjList;

        unordered_map<int, int> mayor;

        prepareList(adjList, trust, mayor);

        int ans = 0;

        for(int i = 1; i<=n; i++){

            if(adjList[i].size() == 0){
                if(mayor[i] == n-1){
                    return i;
                }
            }
            
        }

        return -1;

    }
};