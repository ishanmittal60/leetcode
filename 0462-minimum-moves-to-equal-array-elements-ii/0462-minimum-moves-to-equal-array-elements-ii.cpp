class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int x=(n)/2;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[x]){
                ans+=abs(nums[i]-nums[x]);
            }
        }
        return ans;
    }
};