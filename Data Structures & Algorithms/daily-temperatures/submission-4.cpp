class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> ans(n, -1);
        vector<int> days(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temp[i] >= st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(temp[i]);
        }

        // return ans;

        // now I have 2 arrays first is original & second is their first greater element

        for(int i=0; i<n; i++){
            int current = temp[i];
            int warmer = ans[i];
            if(warmer == -1){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(temp[j] == warmer){
                    days[i] = j-i;
                    break;
                }
            }
        }

        return days;
    }
};
