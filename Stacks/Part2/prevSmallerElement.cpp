#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector <int> findPreviousSmallerElement(vector <int> arr) {
    int n = arr.size();
    vector <int> answer(n,-2);

    // -> last index cant have next greater element
    answer[0] = -1;

    // we will start traversing from end
    stack<int> st;
    st.push(0);


    // -> inside this for loop while loop is running at most n times total
    // -> one element is added and popped atmost one time only
    for(int i = 1;i < n;i++) {

        while(st.size() > 0 && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if(st.size() == 0) {
            answer[i] = -1;
            st.push(i);
            continue;
        }
        
        answer[i] = st.top();
        st.push(i);

    }

    return answer;
}

int main() {
    vector <int> arr = {2,1,5,6,2,3};
    vector <int> ans = findPreviousSmallerElement(arr);
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}