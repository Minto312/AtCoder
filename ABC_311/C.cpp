#include <bits/stdc++.h>
using namespace std;

void search_route(int start,vector<int> side){
    int next = side[start];
    vector<int> route;
    route.emplace_back(start);
    while (next != start){
        route.emplace_back(next);
        next = side[next];
    }
    cout << route.size() << endl;
    for (int i=0;i<route.size();i++){
        cout << route[i] << " ";
    }
    return;
}

int main(){
    int N;
    cin >> N;

    vector<int> side(N+1);
    for (int i=1;i<=N;i++){
        cin >> side[i];
    }

    vector<bool> is_visited(N+1,false);
    for (int next=1;next<=N;next++){
        while (true){
            if (is_visited[next]){
                search_route(next,side);
                return 0;
            }
            is_visited[next] = true;
            next = side[next];
        }
    }
}