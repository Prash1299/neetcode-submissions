class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> mp(wordList.begin(), wordList.end());
        mp.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord){
                return step;
            }

            for(int i = 0; i<word.length(); i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    // check is word is present in map
                    if(mp.find(word) != mp.end()){
                        mp.erase(word);
                        q.push({word, step+1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};
