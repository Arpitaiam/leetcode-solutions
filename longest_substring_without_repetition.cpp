class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1); // store last index of each char
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (index[c] >= left) {
                // duplicate found, move left pointer
                left = index[c] + 1;
            }
            index[c] = right; // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
