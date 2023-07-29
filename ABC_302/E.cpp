#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()


void add_side(  vv<int>>& relation,
                // vector<bool>& relate_count,
                int& isolate_count){
    int a,b;
    cin >> a >> b;
    a--;b--;

    if (relation[a].empty()) isolate_count--;
    if (relation[b].empty()) isolate_count--;

    relation[a].emplace_back(b);
    relation[b].emplace_back(a);
    // relate_count[a]++;
    // relate_count[b]++;

    // relation[a][b] = true;
    // relation[b][a] = true;

    // if (relate_count[a]){
    //     relate_count[a] = false;
    //     isolate_count--;
    // }
    // if (relate_count[b]){
    //     relate_count[b] = false;
    //     isolate_count--;
    // }
}

void check_isolate( vv<int>>& relation,
                    vector<bool>& relate_count,
                    int& isolate_count,
                    int& node,int& N){
    rep(i,0,N){
        if (relation[i][node]) return;
    }
    isolate_count++;
    relate_count[node] = true;
    return;
}
void erase_side(vv<bool>>& relation,
                // vector<bool>& relate_count,
                int& isolate_count,
                int& N){
    int node;
    cin >> node;
    node--;
    // rep(i,0,N){
    //     if (relation[i][node]){
    //         relation[i][node] = false;
    //         relation[node][i] = false;
    //         check_isolate(relation,relate_count,isolate_count,i,N);
    //     }
    // }
    if (!relation[node].empty()){
        isolate_count++;
    }
    int cur;
    while(!relation[node].empty()){
        cur = relation[node].front();
        for (int i = 0,size = relation[cur].size();i < size;i++){
            if (relation[cur][i] == node){
                swap(relation[cur][i],relation[cur][size-1]);
                
            }
        }
        
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N,Q;
    cin >> N >> Q;

    int query;
    int isolate_count = N;
    vv<int>> relation(N,vector<int>(N));
    vector<int> relate_count(N,0);
    vector<string> res;
    rep(i,0,Q){
        cin >> query;

        if (query == 1){
            add_side(relation,relate_count,isolate_count);
        }else{
            erase_side(relation,relate_count,isolate_count,N);
        }
        res.emplace_back(to_string(isolate_count));
    }
    for(string x : res){
        cout << x << endl;
    }
    return 0;
}