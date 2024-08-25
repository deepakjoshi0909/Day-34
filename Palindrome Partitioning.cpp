class Solution {
public:
    bool isPalindrome(string s,int st,int end){
        while(st < end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void solve(string s, int idx, vector<vector<string>>& ans, vector<string>& arr){
        if(idx == s.length()){
            ans.push_back(arr);
            return ;
        }

        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
                arr.push_back(s.substr(idx, i-idx+1));
                solve(s,i+1,ans,arr);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>arr;
        solve(s,0,ans,arr);
        return ans;
    }
};
