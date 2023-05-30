#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()

int main(){
    int move_cnt,item_cnt,hp,min_hp;
    cin >> move_cnt >> item_cnt >> hp >> min_hp;

    string move;
    cin >> move;

    set<pair<int,int>> items; 
    rep(i,0,item_cnt){
        int x,y;
        cin >> x >> y;
        items.insert({x,y});
    }

    int x = 0,y = 0;
    rep(i,0,move_cnt){
        char m = move[i];
        if (m == 'U') y++;
        if (m == 'D') y--;
        if (m == 'L') x--;
        if (m == 'R') x++;

        hp--;
        if (hp < 0){
            cout << "No" << endl;
            return 0;
        }

        if (hp >= min_hp) continue;

        if (items.count({x,y})){
            hp = min_hp;
            items.erase({x,y});
        }
    }
    cout << "Yes" << endl;
    return 0;
}