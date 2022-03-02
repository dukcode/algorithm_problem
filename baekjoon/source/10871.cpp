#include <bits/stdc++.h>

using namespace std;

int n;
int upperNum;
int num;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> upperNum;

    while (n--) {
        cin >> num;
        if (num < upperNum) cout << num << ' ';
    }
}
