class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum =0;
        int n = customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        int res=sum;
        int i=0;
        int j=0;
        while(j<n){
            if(grumpy[j]==1) {
                sum+=customers[j];
            }
            while(j-i+1>minutes){
                if(grumpy[i]==1) sum-=customers[i];
                i++;
            }
            res=max(res,sum);
            j++;
        }
        return res;
    }
};