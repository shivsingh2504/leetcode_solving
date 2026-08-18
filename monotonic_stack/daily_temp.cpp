#include <vector>
#include <stack>

using namespace std;

/*
 * LeetCode 739: Daily Temperatures
 * Approach: Monotonic Decreasing Stack
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * 
 * Stack Behavior:
 * - Stores indices of days waiting for a warmer temperature.
 * - Elements inside the stack maintain a strict top-to-bottom descending order.
 * - An incoming warmer temperature triggers a loop that pops colder days and calculates distances.
 */

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0); // Initializes all wait times to 0 by default
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the current day's temperature 
        // is strictly warmer than the temperature at the index on top of the stack.
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int p = st.top();
            answer[p] = i - p; // Calculate the distance (waiting days)
            st.pop();          // Safely remove the resolved day from the stack
        }
        
        // Push the current day's index onto the stack
        st.push(i);
    }
    
    return answer;
}
