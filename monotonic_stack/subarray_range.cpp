class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        stack<int> min_st;
        for(int i=0;i<=n;i++){
            while(!min_st.empty()&&(i==n || nums[i]<=nums[min_st.top()])){
                int mid = min_st.top();
                min_st.pop();
                long long left = min_st.empty() ? -1 : min_st.top();
                long long right = i;
                long long subarray = (mid-left)*(right-mid);
                total -= subarray * nums[mid];
            }
            min_st.push(i);
        }
        stack<int> max_st;
        for(int i=0;i<=n;i++){
            while(!max_st.empty()&&(i==n || nums[i]>=nums[max_st.top()])){
                int mid = max_st.top();
                max_st.pop();
                long long left = max_st.empty() ? -1 : max_st.top();
                long long right = i;
                long long subarray = (mid-left)*(right-mid);
                total += subarray * nums[mid];
            }
            max_st.push(i);
        }
        return total;
    }
};