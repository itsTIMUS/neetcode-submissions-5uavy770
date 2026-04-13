class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> freq1(26,0);
        for(int i=0; i<s1.size(); i++){
            freq1[s1[i]-'a']++;
        }
        vector <int> freq2(26,0);
        int l=0,r=0;
        while(r<s2.size()){
            freq2[s2[r]-'a']++;

            if(r-l+1>s1.size()){
                freq2[s2[l]-'a']--;
                l++;
            }

            if(freq1==freq2){
                return true;
            }
            r++;
        }
        return false;
    }
};
