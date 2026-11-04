class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0];
         int f=nums[0];
           do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);
         int c=nums[0];
         while(c!=f){
            c=nums[c];
            f=nums[f];
         }
         return c;
    }
};