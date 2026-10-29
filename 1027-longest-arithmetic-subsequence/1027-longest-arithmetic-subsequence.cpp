class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int r=0;
        vector<vector<int>>t(n,vector<int>(1001,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff= nums[i]-nums[j]+500;
                if(t[j][diff]>0){
                    t[i][diff]=t[j][diff]+1;
                }
                else t[i][diff]=2;
                r=max(r,t[i][diff]);
            }
        }
        return r;
    }
};