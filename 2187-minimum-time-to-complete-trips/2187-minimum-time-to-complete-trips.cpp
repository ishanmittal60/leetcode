class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long h = *min_element(time.begin(),time.end())*1LL *totalTrips;
        
        while(l<h){
            long long mid = l+(h-l)/2;
            long long trip=0;
            for(int i=0;i<time.size();i++){
                trip+=mid/time[i];
               // if(trip>=totalTrips) break;
            }
            if(trip>=totalTrips) h=mid;
            else l=mid+1;
        }
        return l;
    }
};