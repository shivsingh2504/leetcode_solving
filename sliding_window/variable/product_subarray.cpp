class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0){
            return 0;
        }
        int n = nums.size();
        int mul_count = 0;
        int muli = 1;
        int r = 0;
        int l = 0;
        for(r=0;r<n;r++){
            muli = muli * nums[r];
            while(muli>k){
                muli = muli / nums[l];
                l++;
            }
            mul_count += (r-l+1);
        }
        return mul_count;

    }
};