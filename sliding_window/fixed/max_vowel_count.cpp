#include <algorithm>
#include <set>
#include<string>
class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> s1= {'a','e','i','o','u'};
        int n = s.length();
        int v_count = 0;
        for(int i = 0;i<k;i++){
            if (s1.find(s[i])!= s1.end()){
                v_count+=1;
            }
        }
        int max_count = v_count;
        for(int i =k;i<n;i++){
            if(s1.find(s[i])!= s1.end()){
                v_count+=1;
            }
            if(s1.find(s[i-k])!= s1.end()){
                v_count -= 1;
            }
            max_count = max(max_count,v_count);
        }
        return max_count;

    }
};