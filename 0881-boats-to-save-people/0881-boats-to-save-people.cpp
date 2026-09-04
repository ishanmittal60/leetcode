class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int n = people.size();
        int j=n-1;
        int cnt=0;
        while(i<=j){
            int a = limit;
            if(a-people[j]>=people[i]) i++;
            cnt++;
            j--;
        }
        return cnt;
    }
};