class Solution {
public:
int re(vector<int>& nums, int target,int i){
     if(i == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == nums[0] || target == -nums[0]) return 1;
            return 0;
        }
    int neg = re(nums,target-nums[i],i-1);
    int pos = re(nums,target+nums[i],i-1);
    return neg+pos;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return re(nums,target,n-1);
    }
};