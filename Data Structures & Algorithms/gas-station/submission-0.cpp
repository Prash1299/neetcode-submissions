class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        int currGas = 0;
        int start = 0;
        int n = gas.size();

        for(int i = 0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];

            currGas = currGas + gas[i] - cost[i];

            if(currGas < 0){
                currGas = 0;;
                start = i+1;
            }
        }

        if(totalCost > totalGas){
            return -1;
        }

        return start;
    }
};
