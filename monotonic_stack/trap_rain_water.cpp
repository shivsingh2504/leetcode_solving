#include<cmath>
#include <algorithm> 
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size()-1;
        int Leftmax = height[l];
        int Rightmax = height[r];
        while(l<r){
            if(Leftmax<Rightmax){
                l = l + 1;
                Leftmax = max(Leftmax,height[l]);
                res += Leftmax - height[l];
            }
            else{
                r = r - 1;
                Rightmax = max(Rightmax,height[r]);
                res += Rightmax - height[r];
            }
        }
        return res;
    }
};