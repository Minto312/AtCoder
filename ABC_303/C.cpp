#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()


int main(){
    const int padding = 200000;
    int move_cnt,item_cnt,hp,min_hp;
    cin >> move_cnt >> item_cnt >> hp >> min_hp;

    string move;
    cin >> move;

    int items[padding*2][padding*2] = false;
    cout << "create items \n"; //debug
    int a,b;
    rep(i,0,item_cnt){
        cin >> a >> b;
        a += padding;
        b += padding;
        items[a][b] = true;
    }
    pair<int,int> cur;
    cur.first = padding;
    cur.second = padding;
    char m;
    rep(i,0,move_cnt){
        m = move[i];
        if (m == 'U') cur.second--;
        if (m == 'D') cur.second++;
        if (m == 'L') cur.first--;
        if (m == 'R') cur.first++;

        hp--;
        if (hp >= min_hp) continue;

        if (items[cur.first][cur.second]){
            hp = min_hp;
            items[cur.first+padding][cur.second+padding] = false;
        }
        if (hp == -1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}