class Solution {
private: 

    vector<int> nextSmallerelement(vector<int> heights, int n){
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i = n-1; i>=0; i--){
            while(!st.empty()  && heights[st.top()] >= heights[i]){
                st.pop();
            }

            // ans is satck ka top
            if(!st.empty()){
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerelement(vector<int> heights, int n){
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            // ans is stack ka top
            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerelement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerelement(heights, n);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;

            area = max(area, newArea);
        }
        return area;

    }
};
