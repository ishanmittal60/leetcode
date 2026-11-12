class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(2*k+1>n) return ans;
        long long x=0;
        for(int i=0;i<2*k+1;i++){
            x+=nums[i];
        }
        ans[k]=x/ (2*k+1);
        int j=k+1;
        while(j+k<n){
            x-=nums[j-k-1];
            x+=nums[j+k];
            ans[j]=x/ (2*k+1);
            j++;
        }
        return ans;
    }
};