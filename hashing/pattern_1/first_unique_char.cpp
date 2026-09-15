#include <vector>
#include <unordered_map>
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>freqmap;
        for(char c : s){
            freqmap[c]++;
        }
        for (int i = 0; i<s.size();i++){
            if(freqmap[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};