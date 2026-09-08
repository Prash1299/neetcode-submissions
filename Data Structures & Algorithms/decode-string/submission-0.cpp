class Solution {
public:
    string decodeString(string s) {
        stack<int> numst;
        stack<string> st;

        string current = "";
        int num = 0;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '['){
                numst.push(num);
                st.push(current);

                num = 0;
                current = "";
            }

            else if (ch == ']') {
                int repeat = numst.top();
                numst.pop();

                string previous = st.top();
                st.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            else {
                current += ch;
            }
        }

        return current;

        
    }
};