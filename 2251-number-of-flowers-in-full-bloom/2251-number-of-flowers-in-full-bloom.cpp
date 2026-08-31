class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int>st;
        vector<int>en;
        for(int i=0;i<m;i++){
            st.push_back(flowers[i][0]);
             en.push_back(flowers[i][1]);
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++){
              int day = people[i];

            int started = upper_bound(st.begin(), st.end(), day) - st.begin();
            int ended = lower_bound(en.begin(), en.end(), day) - en.begin();

            ans[i] = started - ended;
        }
        return ans;
    }
};