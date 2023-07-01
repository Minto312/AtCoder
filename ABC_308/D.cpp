#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(obj) obj.begin(), obj.end()
#define vv vector<vector<


int main(){
    int H,W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i=0;i<H;i++){
        cin >> S[i];
    }

    const string snuke = "snuke";
    if (S[0][0] != 's'){
        cout << "No" << endl;
        return 0;
    }
    vector<vector<bool>> visited(H,vector<bool>(W,false));

    stack<vector<int>> s;
    s.push({0,0,1});
    visited[0][0] = true;
    int x = 0, y = 0;
    while (true){
        if (s.empty()){
            cout << "No" << endl;
            return 0;
        }

        int x = s.top()[0];
        int y = s.top()[1];
        int idx = s.top()[2];
        visited[y][x] = true;
        s.pop();
        if (x == W-1 && y == H-1){
            cout << "Yes" << endl;
            return 0;
        }

        // cout << x << " " << y << " " << idx << endl; //debug
        if (x - 1 >= 0 && S[y][x-1] == snuke[idx] && visited[y][x-1] == false){
            s.push({x-1,y,(idx+1) % 5});
        }
        if (x + 1 < W && S[y][x+1] == snuke[idx] && visited[y][x+1] == false){
            s.push({x+1,y,(idx+1) % 5});
        }
        if (y - 1 >= 0 && S[y-1][x] == snuke[idx] && visited[y-1][x] == false){
            s.push({x,y-1,(idx+1) % 5});
        }
        if (y + 1 < H && S[y+1][x] == snuke[idx] && visited[y+1][x] == false){
            s.push({x,y+1,(idx+1) % 5});
        }

        
        // cout << x << " != " << W-1 << " && " << y << " != " << H-1 << endl; //debug
    }
    return 0;
}