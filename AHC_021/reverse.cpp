#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector


void swapping(int& a,int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    const int N = 30;
    vv<int>> balls(N,vector<int>(N,999));

    for (int i=0;i<N;i++){
        for (int j=0;j<=i;j++){
            cin >> balls[i][j];
        }
    }

    vector<vector<int>> swap_list;
    bool is_changed = true;
    while (is_changed){
        is_changed = false;
        for (int i=N-1;i>=0;i--){
            for (int j=0;j<=i;j++){
                int diff_j = -1;
                if (i-1 < 0) continue;
                if (j-1 < 0) diff_j = 0;

                is_changed = false;
                if (balls[i][j] > balls[i-1][j] || balls[i][j] > balls[i-1][j+diff_j]){
                    if (balls[i-1][j] < balls[i-1][j+diff_j]){
                        swapping(balls[i][j],balls[i-1][j]);
                        swap_list.emplace_back(vector<int>{i,j,i-1,j});
                    }else{
                        swapping(balls[i][j],balls[i-1][j+diff_j]);
                        swap_list.emplace_back(vector<int>{i,j,i-1,j+diff_j});
                    }
                    is_changed = true;
                }
            }
        }
    }
    cout << swap_list.size() << endl;
    for (auto& xx : swap_list){
        for (auto& x : xx){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}