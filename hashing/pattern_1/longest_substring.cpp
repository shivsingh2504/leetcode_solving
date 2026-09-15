#include<vector>
#include<unordered_map>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_len = 0;
        unordered_map<char,int> freqmap;
        for (int right = 0; right<s.size();right++){
            freqmap[s[right]]++;
            while(freqmap[s[right]]>1){
                freqmap[s[left]]--;
                left++;
            }
            max_len = max(max_len,right-left+1);
        }
        return max_len;
    }
};