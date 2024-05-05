#include <bits/stdc++.h>
using namespace std;

int N, M;
int cnt5 = 0, cnt4 = 0, cnt3 = 0, cnt2 = 0, cnt1 = 0;
vector<vector<int>> arr(10, vector<int>(10, 0));

int left(vector<vector<int>> &arr, int i, int j, int n){
    int left = j - 1; 
    int count = 0;
        while (left >= 0 && arr[i][left] != 6) {
            if (arr[i][left] == 0){
                count++;
            }
            left--;
        }
    return count;
}

int right(vector<vector<int>> &arr, int i, int j, int n){
    int right = j + 1;
    int count = 0;
        while (right < M && arr[i][right] != 6) {
            arr[i][right] = 9;
            if (arr[i][right] == 0){
                count++;
            }
            right++;
        }
    return count;
}

int up(vector<vector<int>> &arr, int i, int j, int n){
    int up = i - 1;
    int count = 0;
        while (up >= 0 && arr[up][j] != 6) {
            arr[up][j] = 9;
            if (arr[up][j] == 0){
                count++;
            }
            up--;
        }
    return count;
}

int down(vector<vector<int>> &arr, int i, int j, int n){
    int down = i + 1;
    int count = 0;
        while (down < N && arr[down][j] != 6) {
            arr[down][j] = 9;
            if (arr[down][j] == 0){
                count++;
            }
            down++;
        }
    return count;
}
int check(vector<vector<int>>& arr, int i, int j, int n) {
    int result = 0;  
    switch (n) {
        case 5: {
            int count1 = left(arr, i, j, 5) + right(arr, i, j, 5) + up(arr, i, j, 5) + down(arr, i, j, 5);
            result = count1;
            break;
        }
        case 4: {
            int count1_4 = left(arr, i, j, 4) + right(arr, i, j, 4) + up(arr, i, j, 4);
            int count2 = right(arr, i, j, 4) + up(arr, i, j, 4) + down(arr, i, j, 4);
            int count3 = left(arr, i, j, 4) + right(arr, i, j, 4) + down(arr, i, j, 4);
            int count4 = left(arr, i, j, 4) + up(arr, i, j, 4) + down(arr, i, j, 4);
            result = max({count1_4, count2, count3, count4});
            break;
        }
        case 3: {
            int count1_3 = right(arr, i, j, 3) + up(arr, i, j, 3);
            int count2_3 = right(arr, i, j, 3) + down(arr, i, j, 3);
            int count3_3 = left(arr, i, j, 3) + down(arr, i, j, 3);
            int count4_3 = left(arr, i, j, 3) + up(arr, i, j, 3);
            result = max({count1_3, count2_3, count3_3, count4_3});
            break;
        }
        case 2: {
            int count1_2 = left(arr, i, j, 2) + right(arr, i, j, 2);
            int count2_2 = up(arr, i, j, 2) + down(arr, i, j, 2);
            result = max(count1_2, count2_2);
            break;
        }
        case 1: {
            int count1_1 = left(arr, i, j, 1);
            int count2_1 = up(arr, i, j, 1);
            int count3_1 = right(arr, i, j, 1);
            int count4_1 = down(arr, i, j, 1);
            cout << count1_1 << " " << count2_1 << " " << count3_1 << " " << count4_1 << '\n';
            result = max({count1_1, count2_1, count3_1, count4_1});
            break;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    int non_zero = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] !=0 ) non_zero++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k = arr[i][j];
            if (k == 5) {
                cnt5 += check(arr, i, j, 5);
                cout << "k = 5, i = " << i << ", j = " << j << ", cnt5 = " << cnt5 << '\n';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k = arr[i][j];
            if (k == 4) {
                cnt4 += check(arr, i, j, 4);
                cout << "k = 4, i = " << i << ", j = " << j << ", cnt4 = " << cnt4 << '\n';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k = arr[i][j];
            if (k == 3) {
                cnt3 += check(arr, i, j, 3);
                cout << "k = 3, i = " << i << ", j = " << j << ", cnt3 = " << cnt3 << '\n';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k = arr[i][j];
            if (k == 2) {
                cnt2 += check(arr, i, j, 2);
                cout << "k = 2, i = " << i << ", j = " << j << ", cnt2 = " << cnt2 << '\n';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k = arr[i][j];
            if (k == 1) {
                cnt1 += check(arr, i, j, 1);
                cout << "k = 1, i = " << i << ", j = " << j << ", cnt1 = " << cnt1 << '\n';
            }
        }
    }
    cout << cnt1 << ' ' <<  cnt2 << ' ' <<  cnt3 << ' ' <<  cnt4 << ' ' << cnt5 << '\n';
    cout << N*M-non_zero-(cnt1+cnt2+cnt3+cnt4+cnt5);
    return 0;
}