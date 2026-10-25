class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;   // store index

        for(int i=0; i<n; i++){
            while(!st.empty() && temp[i]>temp[st.top()]){
                int previndex = st.top();
                st.pop();
                ans[previndex] = i - previndex;
            }
            st.push(i);
        }
        return ans;
    }
};
