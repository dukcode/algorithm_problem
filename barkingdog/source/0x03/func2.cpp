#include <bits/stdc++.h>

using namespace std;

int numArr[101];

int func2(int arr[], int N) {
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; ++i) {
        if (numArr[100 - arr[i]] != 0) return 1;
        numArr[arr[i]] += 1;
    }

    return 0;
}
