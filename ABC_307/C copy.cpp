#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> A(H);
    vv<int>> A_map;
    for (int i=0;i<H;i++){
        cin >> A[i];
    }
    int idx = 0;
    int diff_i,diff_j;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (A[i][j] == '#'){
                A_map.emplace_back();
                if (idx == 0){
                    diff_i = i;
                    diff_j = j;
                }
                A_map[idx][0] = i - diff_i;
                A_map[idx][1] = j - diff_j;

                idx++;
            }
        }
    }

    cin >> H >> W;
    vector<string> B(H);
    for (int i=0;i<H;i++){
        cin >> B[i];
    }
    vv<int>> B_map;
    for (int i=0;i<H;i++){
        cin >> B[i];
    }
    int idx = 0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (B[i][j] == '#'){
                B_map.emplace_back();
                if (idx == 0){
                    diff_i = i;
                    diff_j = j;
                }
                B_map[idx][0] = i - diff_i;
                B_map[idx][1] = j - diff_j;

                idx++;
            }
        }
    }


    cin >> H >> W;
    vector<string> X(H);
    vector<vector<char>> C(H,vector<char>(W,0));
    for (int i=0;i<H;i++){
        cin >> X[i];
    }


    return 0;
}