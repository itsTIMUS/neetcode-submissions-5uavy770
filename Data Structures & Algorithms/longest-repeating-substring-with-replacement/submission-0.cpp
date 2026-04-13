class Solution {
public:
    int characterReplacement(string s, int k) {
        vector <int> freq(26,0);
        int l=0, r=0;
        int maxL=0, maxF=0;
        while(r<s.size()){
            freq[s[r]-'A']++;
            maxF = max(maxF,freq[s[r]-'A']);
            while((r-l+1)-maxF>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxL=max(maxL,(r-l+1));
            r++;
        }
        return maxL;
    }
};
