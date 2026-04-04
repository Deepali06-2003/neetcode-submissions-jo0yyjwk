class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st( wordList.begin(), wordList.end());
        queue<pair<string , int>>q;

        q.push({beginWord , 1});
        st.erase(beginWord);

        while(!q.empty()){

            string w = q.front().first;
            int s = q.front().second;
            q.pop();

            if(w == endWord)return s;

            for(int i =0;i<w.size();i++){
                char t = w[i];

                for(char j ='a' ; j<='z' ; j++){

                    if(j == t) continue;
                    w[i] = j;

                    if(st.find(w) != st.end()){
                        st.erase(w);
                        q.push({w , s+1});
                    }
                }

                w[i] = t;
            } 
        }
        return 0;
    }
};
