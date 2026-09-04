class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>s;
        for(int i=0;i<k;i++) s.insert(i);
        vector<int>fre(k,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<load.size();i++){
            while(!pq.empty() && pq.top().first<=arrival[i]){
                auto [t,ser] = pq.top();
                pq.pop();
                s.insert(ser);
            }
            if(s.empty()) continue;
             auto it = s.lower_bound(i % k);
                if (it == s.end()) it = s.begin();
                int b = *it;
                s.erase(it);
                fre[b]++;
                pq.push({arrival[i]+load[i],b});
        }
        int mx = *max_element(fre.begin(),fre.end());
        vector<int>res;
        for(int i=0;i<fre.size();i++){
            if(fre[i]==mx) res.push_back(i);
        }
        return res;
    }
};