class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //int m = tasks.size();
        int ans=0;
        vector<int>freq(26, 0);
        for(char i :tasks)freq[i-'A']++;

        priority_queue<int>pq;
        for(int i =0;i<26;i++){
            if(freq[i]>0)pq.push(freq[i]);
        }

        while(!pq.empty()){

            vector<int>curr;
            for(int i =0;i<(n+1);i++){
                if(!pq.empty()){
int t = pq.top();
                pq.pop();
                t--;
                curr.push_back(t);
                }
                
            }
            for(int i =0;i<curr.size();i++){
                if(curr[i]>0)pq.push(curr[i]);
            }

            if(!pq.empty()) ans = ans+n+1;
            else ans = ans+ curr.size();
        }
        return ans;
    }
};
