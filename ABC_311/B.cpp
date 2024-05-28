#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,D;
    cin >> N >> D;

    vector<string> days(N);

    for (int i=0;i < N;i++){
        cin >> days[i];
    }

    int streak = 0, max_streak = 0;
    bool is_ok;
    for (int i=0;i<D;i++){
        is_ok = true;
        for (int j=0;j<N;j++){
            if (days[j][i] == 'x'){
                is_ok = false;
                break;
            }
        }
        if (is_ok){
            streak++;
        }else{
            if (streak > max_streak){
                max_streak = streak;
            }
            streak = 0;
        }
    }
    if (streak > max_streak){
        max_streak = streak;
    }
    cout << max_streak << endl;
    return 0;
}