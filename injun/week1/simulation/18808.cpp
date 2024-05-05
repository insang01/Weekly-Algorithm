#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int r,c;
vector<vector<int>> notebook(50, vector<int>(50, 0));
vector<vector<int>> sticker(12, vector<int>(12, 0));

bool pastable(int x, int y){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (sticker[i][j] == 1 && notebook[x+i][y+j] == 1){
                return false;
            }
        }
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (sticker[i][j] == 1){
                sticker[x+i][y+j] = 1;
            }
        }
    }
    return true;
}

void rotate(){
    int tmp[12][12];
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            tmp[i][j] = sticker[i][j];
        }
    }

    for (int i=0; i<c; i++){
        for (int j=0; j<r; j++){
            sticker[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r, c);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int cnt=0; cnt<k; cnt++){
        cin >> r >> c;
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                cin >> sticker[i][j];
            }
        }

        for (int rot = 0; rot < 4; rot ++){
            bool is_pasted = false;
            for (int i=0; i<=n-r; i++){
                if (is_pasted) break;
                for (int j=0; j<=m-r; j++){
                    if (pastable(i, j)){
                        is_pasted = true;
                        break;
                    } 
                }
            }
            if (is_pasted) break;
            rotate();
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cnt += notebook[i][j];
        }
    }
    cout << cnt << '\n';
}