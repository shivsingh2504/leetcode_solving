class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int count = 0;
        int avrg = 0;
        for(int i = 0 ;i<k; i++){
            sum += arr[i];
        }
        avrg = sum/k;
        if(avrg>=threshold){
            count+=1;
        }
        for(int i=k;i<n;i++){
            sum+=arr[i];
            sum-= arr[i-k];
            int avrg_s = sum/k;
            if(avrg_s >= threshold){
                count+=1;
            }
        }
        return count;

    }
};