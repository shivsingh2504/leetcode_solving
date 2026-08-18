#include <stack>
#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        stack<int> st;
        unordered_map<int,int> next;
        for(int i = 0;i < nums2.size();i++){
            while(!st.empty()&& nums2[i]>st.top()){
                next[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int num:nums1){
            if (next.count(num)){
                answer.push_back(next[num]);
            }
            else{
                answer.push_back(-1);
            }
        }
        return answer;

    }
};