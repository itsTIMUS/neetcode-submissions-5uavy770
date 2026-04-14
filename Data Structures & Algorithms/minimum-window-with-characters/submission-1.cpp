class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        vector<int> freq1(128, 0); 
        for (char c : t) freq1[c]++;

        vector<int> freq2(128, 0);
        int l = 0, r = 0, minL = INT_MAX, startI = -1;
        int count = 0;

        while (r < s.size()) {
            char rightChar = s[r];
            freq2[rightChar]++;
            
            if (freq1[rightChar] > 0 && freq2[rightChar] <= freq1[rightChar]) {
                count++;
            }

            while (count == t.size()) {
                if (r - l + 1 < minL) {
                    minL = r - l + 1;
                    startI = l;
                }

                char leftChar = s[l];
                freq2[leftChar]--;
                if (freq1[leftChar] > 0 && freq2[leftChar] < freq1[leftChar]) {
                    count--;
                }
                l++;
            }
            r++;
        }

        return (startI == -1) ? "" : s.substr(startI, minL);
    }
};
