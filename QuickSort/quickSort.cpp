#include <iostream>
using namespace std;

int partition(int arr[], int startIdx, int endIdx) {
    int pivot = arr[startIdx];

    // -> find no of elements less than our selected pivot.
    int count = 0;
    for(int i = startIdx+1;i <= endIdx;i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    // -> finding pivot index
    int pivotIdx = count+startIdx;

    // -> placing pivot at correct position
    swap(arr[startIdx], arr[pivotIdx]);

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

void QuickSort(int arr[], int startIdx, int endIdx) {
    if(startIdx >= endIdx) return;

    int pivotIdx = partition(arr,startIdx,endIdx);

    QuickSort(arr,startIdx,pivotIdx-1);
    QuickSort(arr,pivotIdx+1,endIdx);
}

int main() {
    int arr[] = {5,1,8,2,7,6,3,4,78,14,-8,51};
    int n = 12;
    for(int i = 0; i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr,0,n-1);

    for(int i = 0; i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}