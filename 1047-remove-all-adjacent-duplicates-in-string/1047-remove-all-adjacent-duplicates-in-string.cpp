class Solution {
public:
    string removeDuplicates(string s) {
          int n=  s.size();
        if(n==1) return s;
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()==s[i]) {st.pop();
            continue;
            }
            
                st.push(s[i]);
            
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};