class Solution {
public:
bool is(vector<int>& nums, int ma,int m){
long long tot=0;
for(int &n:nums){
    int op=n/m;
    if(n%m==0) op-=1;
    tot+=op;
}
return tot<=ma;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r=*max_element(nums.begin(),nums.end());
        int ans=r;
        int l=1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(is(nums,maxOperations,m)==true){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};