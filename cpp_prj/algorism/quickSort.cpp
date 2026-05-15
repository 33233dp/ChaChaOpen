// 选择排序

#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> arr) {
    //基线条件(不再递归，直接返回)
    if(arr.size() <= 1) {
        return arr;
    }

    //缩小规模

    //选择最后一个元素作为基准指
    int pivot = arr.back();
    vector<int> left;
    vector<int> right;

    int n;
    n = arr.size();

    //比基准值大的放基准值的右边，比基准值小的放基准值左边
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > pivot) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }
    
    // 递归排序左边
    left = quickSort(left);
    // 递归排序右边
    right = quickSort(right);

    //拼接结果
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

int main() {

    vector<int> arr;
    int n;

    cout << "intput n: ";
    cin >> n;

    cout << "input arr:";
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    arr = quickSort(arr);

    n = arr.size();
    cout << "sort: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

