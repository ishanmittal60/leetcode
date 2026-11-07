class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> free;
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> busy;
        for (int i = 0; i < n; i++) {
           free.push({servers[i], i});
           }
           int m = tasks.size();
           vector<int>ans;
           for(int i=0;i<m;i++){
            while (!busy.empty() && get<0>(busy.top()) <= i) {
             auto [time, weight, idx] = busy.top();
              busy.pop();
              free.push({weight, idx});}
              if(!free.empty()){
                auto [weight, idx] = free.top();
                free.pop();
                busy.push({i + tasks[i], weight, idx});
                ans.push_back(idx);
              }
              else{
                auto [time, weight, idx] = busy.top();
                busy.pop();
                busy.push({time + tasks[i], weight, idx});
                ans.push_back(idx);
              }
           }
           return ans;
    }
};