class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k=k-1;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty())
        return "0";
        string res="";
        while(!st.empty()){
             res.push_back(st.top()); 
            st.pop();
        }
        reverse(res.begin(),res.end());
        int pos = res.find_first_not_of('0'); 
        if (pos == string::npos) 
        return "0";
        res = res.substr(pos); 
        return res;
    }
};