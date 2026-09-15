#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freqmap;
        for (char c : s){
            freqmap[c]++;
        }
        vector<pair<char,int>> word;
        for(const auto w : freqmap){
            word.push_back(w);
        }
        sort(word.begin(),word.end(),[](const pair<char,int>&a,const pair<char,int>&b){return a.second>b.second;});
        string result = "";
        for(auto pair:word){
            result += string(pair.second,pair.first);
        }
        return result;
    }
};