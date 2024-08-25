class Solution {
public:
    int solve(int n, int idx, vector<bool>arr){
        if(idx > n){
            return 1;
        }

        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!arr[i] && (i%idx == 0 || idx%i == 0)){
                arr[i] = true;
                cnt += solve(n,idx+1,arr);
                arr[i] = false;
            }
        }
        return cnt;
    }
    int countArrangement(int n) {
        vector<bool>arr(n+1,false);
        return solve(n,1,arr);
    }
};
