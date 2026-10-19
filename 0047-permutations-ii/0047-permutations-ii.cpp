class Solution {
public:
map<vector<int>,int>mp;
vector<vector<int>> ans;
void help(vector<int>& nums, int i){
if(i==nums.size()){
    if(mp.find(nums)==mp.end()){
        ans.push_back(nums);
        mp[nums]=1;
    }
     return;}
for(int j=i;j<nums.size();j++){
    swap(nums[i],nums[j]);
    help(nums,i+1);
    swap(nums[i],nums[j]);
}
return;
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        mp.clear();
ans.clear();
        help(nums,0);
        return ans;
    }
};