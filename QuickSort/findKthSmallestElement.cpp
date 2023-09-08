#include <iostream>
using namespace std;

int partition(int arr[], int startIdx, int endIdx) {

    // Just we select middle element in randomised QuickSort, we can select other also
    int pivot = arr[(startIdx+endIdx)/2];

    // -> find no of elements less than our selected pivot.
    int count = 0;

    // => this time run loop from start only instead of start + 1
    for(int i = startIdx;i <= endIdx;i++) {

        if(i==(startIdx+endIdx)/2) continue;

        if(arr[i] <= pivot) {
            count++;
        }
    }

    // -> finding pivot index
    int pivotIdx = count+startIdx;

    // -> placing pivot at correct position
    swap(arr[(startIdx+endIdx)/2], arr[pivotIdx]);

    // -> placing small elements in left and larger in right
    int i = startIdx;
    int j = endIdx;
    while(i < pivotIdx && j > pivotIdx) {
        if(arr[i] > arr[pivotIdx] && arr[j] <= arr[pivotIdx]) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } 

        else if(arr[i] > arr[pivotIdx]) {
            swap(arr[i], arr[j]);
            j--;
        }

        else if(arr[j] < arr[pivotIdx]) {
            swap(arr[i], arr[j]);
            i++;
        }

        else if(arr[i] < arr[pivotIdx]) {
            i++;
        }

        else if(arr[j] > arr[pivotIdx]) {
            j--;
        }
    }


    return pivotIdx;
}

int findKthSmallestElement(int arr[], int startIdx, int endIdx, int k) {

    int pivotIdx = partition(arr,startIdx,endIdx);

    // -> return when found
    if(pivotIdx+1==k) return arr[pivotIdx];

    // -> we are making only one call at a time, hence before whole array gets sorted element is found.
    else if(pivotIdx+1 < k) {
        return findKthSmallestElement(arr,startIdx+1,endIdx,k);
    }
    else {
        return findKthSmallestElement(arr,startIdx,pivotIdx-1,k);
    }

}

int main() {
    int arr[] = {5,1,8,2,7,6,3,4,78,14,-8,51};
    int n = 12;
    for(int i = 0; i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k = 11;
    cout << findKthSmallestElement(arr,0,n-1,k) << endl;

    for(int i = 0; i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}