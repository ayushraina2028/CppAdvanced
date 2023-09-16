#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector <int> stockSpanProblem(vector <int> arr) {
    int n = arr.size();
    vector <int> answer(n,1);

    
    // we will start traversing from end
    stack<int> st;
    st.push(arr[0]);


    // -> inside this for loop while loop is running at most n times total
    // -> one element is added and popped atmost one time only

    stack <int> helper;
    for(int i = 1;i < n;i++) {

        while(st.size() > 0 && st.top() < arr[i]) {
            answer[i]++;
            helper.push(st.top());
            st.pop();
        }

        while(!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }

        st.push(arr[i]);

    }

    return answer;
}

int main() {
    vector <int> arr = {100,80,60,70,60,75,85};
    vector <int> ans = stockSpanProblem(arr);
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

// -> {2,1,5,6,2,3} 
// -> prevS = -1 -1 1 5 1 2
// -> nextS = 1 -1 2 2 -1 -1 
