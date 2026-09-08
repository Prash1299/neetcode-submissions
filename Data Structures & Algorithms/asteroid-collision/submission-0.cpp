class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
    stack<int> st;
    
    int n = ast.size();
    for(int i=0; i<n; i++){
        bool destroy = false;
        while(!st.empty() && st.top()>0 && ast[i]<0){
            if(st.top() == abs(ast[i])){
                st.pop();
                destroy = true;
                break;
            }
            else if(st.top() < abs(ast[i])){
                st.pop();
                // st.push(ast[i]);
                
            }
            else{
                destroy = true;
                break;
            }
        }
        if(!destroy){
            st.push(ast[i]);
        }
    }

    vector<int> ans;



    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();

    }
    
    reverse(ans.begin(), ans.end());

    return ans;

    }
};