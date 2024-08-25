#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<int> search(const T arr[], int arrSize, T target) {
    vector<int> temp;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == target) {
            temp.push_back(i);
        }
    }
    return temp;
}

int main() {
    int arr[100], arrSize, target;
    cout << "Nhap vao so phan tu mang: ";
    cin >> arrSize;
    for (int i = 0; i < arrSize; i++) {
        cout << "Nhap phan tu thu " << i << " : ";
        cin >> arr[i];
    }
    cout << "Nhap so can tim: ";
    cin >> target;
    vector<int> result = search<int>(arr, arrSize, target);
    if (!result.empty()) {
        cout << "Vi tri cua phan tu: ";
        for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
            cout << *it << " ";
        }
    } else {
        cout << "-1";
    }
    return 0;
}

