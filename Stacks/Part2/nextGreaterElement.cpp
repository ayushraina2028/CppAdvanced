#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector <int> findNextGreaterElement(vector <int> arr) {
    int n = arr.size();
    vector <int> answer(n,-2);

    // -> last index cant have next greater element
    answer[n-1] = -1;

    // we will start traversing from end
    stack<int> st;
    st.push(arr[n-1]);


    // -> inside this for loop while loop is running at most n times total
    // -> one element is added and popped atmost one time only
    for(int i = n-2;i >= 0;i--) {

        while(st.size() > 0 && st.top() < arr[i]) {
            st.pop();
        }

        if(st.size() == 0) {
            answer[i] = -1;
            st.push(arr[i]);
            continue;
        }
        
        answer[i] = st.top();
        st.push(arr[i]);

    }

    return answer;
}

int main() {
    vector <int> arr = {2,1,5,6,2,3};
    vector <int> ans = findNextGreaterElement(arr);
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}