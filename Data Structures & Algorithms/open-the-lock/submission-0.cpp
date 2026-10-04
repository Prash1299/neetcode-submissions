class Solution {
public:

    vector<string> getNeighbours(string current) {

        vector<string> neighbours;

        for(int i = 0; i < 4; i++) {

            // Increase current digit
            string temp = current;

            if(temp[i] == '9')
                temp[i] = '0';

            else
                temp[i]++;

            neighbours.push_back(temp);


            // Decrease current digit
            temp = current;

            if(temp[i] == '0')
                temp[i] = '9';
            else
                temp[i]--;

            neighbours.push_back(temp);
        }

        return neighbours;
    }


    int openLock(vector<string>& deadends, string target) {

        // visited[i] tells whether state i has been visited
        vector<bool> visited(10000, false);

        // dead[i] tells whether state i is a deadend
        vector<bool> dead(10000, false);

        // Convert deadend strings into numbers
        for(string s : deadends) {

            int num = stoi(s);

            dead[num] = true;
        }

        // 0000 itself is blocked
        if(dead[0])
            return -1;

        queue<string> q;

        q.push("0000");
        visited[0] = true;

        int distance = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string current = q.front();
                q.pop();

                // Target reached
                if(current == target)
                    return distance;

                vector<string> neighbours = getNeighbours(current);

                for(string neighbour : neighbours) {

                    int num = stoi(neighbour);

                    // Skip deadend
                    if(dead[num])
                        continue;

                    // Skip already visited
                    if(visited[num])
                        continue;

                    visited[num] = true;

                    q.push(neighbour);
                }
            }

            distance++;
        }

        return -1;
    }
};