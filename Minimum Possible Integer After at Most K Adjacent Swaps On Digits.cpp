class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();

        for(int i = 0; i < n && k > 0; i++) {
            int pos = i;
            for(int j = i + 1; j < n && j - i <= k; ++j) {
                if(num[j] < num[pos]){
                    pos = j;
                }
            }

            for(int j = pos; j > i; j--) {
                swap(num[j], num[j-1]);
            }

            k -= pos - i;
        }
        return num;
    }
};
