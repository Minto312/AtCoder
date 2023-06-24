#include <bits/stdc++.h>
using namespace std;
#define vvv vector<vector<vector

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> A(H);
    vvv<int>>> A_map;
    for (int i=0;i<H;i++){
        cin >> A[i];
    }
    int map_idx = 0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (A[i][j] == '#'){
                A_map.emplace_back();
                int idx = 0;
                for (int k=0;k<H;k++){
                    for (int h=0;h<W;h++){
                        if (A[k][h] == '#'){
                            A_map[map_idx].emplace_back();
                            A_map[map_idx][idx].emplace_back(i-k);
                            A_map[map_idx][idx].emplace_back(j-h);
                            idx++;
                        }
                    }
                }
                map_idx++;
            }
        }
    }

    cin >> H >> W;
    vector<string> B(H);
    for (int i=0;i<H;i++){
        cin >> B[i];
    }
    vvv<int>>> B_map;
    map_idx = 0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (B[i][j] == '#'){
                B_map.emplace_back();
                int idx = 0;
                for (int k=0;k<H;k++){
                    for (int h=0;h<W;h++){
                        if (B[k][h] == '#'){
                            B_map[map_idx].emplace_back();
                            B_map[map_idx][idx].emplace_back(i-k);
                            B_map[map_idx][idx].emplace_back(j-h);
                            idx++;
                        }
                    }
                }
                map_idx++;
            }
        }
    }


    cin >> H >> W;
    vector<string> X(H);
    vector<vector<char>> C(H,vector<char>(W,0));
    for (int i=0;i<H;i++){
        cin >> X[i];
    }
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (X[i][j] == '#'){
                for (auto& xx : A_map){
                    for (auto& x : xx){
                        if (i-x[0] < 0 || i-x[0] >= H ||
                            j-x[1] < 0 || j-x[1] >= W ||
                            X[i-x[0]][j-x[1]] == '.'){
                                vector<vector<char>> C(H,vector<char>(W,'.'));
                                continue;
                        }else{
                            C[i-x[0]][j-x[1]] = '#';
                        }
                    }
                }
                for (auto& xx : B_map){
                    for (auto& x : xx){
                        if (i-x[0] < 0 || i-x[0] >= H ||
                            j-x[1] < 0 || j-x[1] >= W ||
                            X[i-x[0]][j-x[1]] == '.'){
                                vector<vector<char>> C(H,vector<char>(W,'.'));
                                continue;
                        }else{
                            C[i-x[0]][j-x[1]] = '#';
                        }
                    }
                }
                for (int i=0;i<H;i++){
                    for (int j=0;j<W;j++){
                        cout << C[i][j] << " "; //debug
                        if (!(X[i][j] == C[i][j])){
                            continue;
                        }
                    }
                    cout << endl; //debug
                }
                cout << "Yes";
                // return 0;
                break;
            }
        }
    }
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cout << C[i][j] << " "; //debug
            if (!(X[i][j] == C[i][j])){
                // cout << "No";
                // return 0;
            }
        }
        cout << endl; //debug
    }
    cout << "Yes";
    return 0;
}