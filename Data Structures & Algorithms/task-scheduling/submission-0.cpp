class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26, 0);
        for(char c: tasks) freq[c-'A']++;

        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }

        int ans=0;
        while(!pq.empty()){
            vector<int>curr;

            for(int i=0;i<(n+1);i++){
                if(!pq.empty()){
                    int temp = pq.top();
                    pq.pop();
                    temp--;

                    curr.push_back(temp);
                }
                
            }

            for(int i=0;i<curr.size();i++){
                if(curr[i]>0) pq.push(curr[i]);
            }

            if(!pq.empty()) ans = ans+n+1;
            else ans = ans+curr.size();

        }
        return ans;
    }
};
