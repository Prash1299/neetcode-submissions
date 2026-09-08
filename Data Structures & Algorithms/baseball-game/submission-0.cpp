class Solution {
public:
    int calPoints(vector<string>& operations) {


        stack<int> ans;

        for(int i=0; i<operations.size(); i++){
            
                if(operations[i] == "+"){
                    int first = ans.top();
                    ans.pop();

                    int second = ans.top();

                    ans.push(first);
                    ans.push(first + second);

                }

                else if(operations[i] == "D"){
                  
                    ans.push(2*ans.top());
                }

                else if(operations[i] == "C"){
                    
                        ans.pop();
                   
                }
                else {

                    ans.push(stoi(operations[i]));

                }
            
        }

        int total = 0;

        while(!ans.empty()) {
            total += ans.top();
            ans.pop();
        }

        return total;

    }
};