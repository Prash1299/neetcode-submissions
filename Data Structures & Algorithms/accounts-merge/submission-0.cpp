class DisjointSet{
    vector<int> size, parent;

    public:

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionbySize(int u, int v){

        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v){
            return ;
        }

        if(ulp_u > ulp_v){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];

        }
        else if(ulp_v > ulp_u){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map <string, int> mailnode;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailnode.find(mail) == mailnode.end()){
                    mailnode[mail] = i;
                }
                else{
                    ds.unionbySize(i, mailnode[mail]);
                }
            }
        }

        vector<string> mergemail[n];

        for(auto it : mailnode){
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergemail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i<n; i++){
            if(mergemail[i].size() == 0){
                continue;
            }

            sort(mergemail[i].begin(), mergemail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);
            for(auto it : mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};