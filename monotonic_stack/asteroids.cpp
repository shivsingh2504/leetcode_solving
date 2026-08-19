#include <vector>
#include<stack>
#include<cmath>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st; 
        for(int i = 0 ;i<asteroids.size();i++){
            bool alive = true;
            while(!st.empty()&&asteroids[i]<0&&st.top()>0){
                if(abs(asteroids[i])>st.top()){
                    st.pop();
                }
                else if(abs(asteroids[i])==st.top()){
                    st.pop();
                    alive = false;
                    break;
                }
                else{
                    alive = false;
                    break;
                }
            }
            if(alive){
                    st.push(asteroids[i]);
            }
        }
        int s = st.size();
        vector <int> answer(s);
        for(int i =s-1; i>=0; i--){
            answer[i] = st.top();
            st.pop();
        }
        return answer;
        
    }
};