#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

int main(){
    int N;
    cin >> N;

    int first;
    cin >> first;
    int max = first;
    bool is_changed = false;
    for (int i=1;i<N;i++){
        int temp;
        cin >> temp;
        if (temp >= max){
            max = temp;
            is_changed = true;
        }
    }
    if (max == first && is_changed){
        cout << 1 << endl;
    }else if (max == first && !is_changed){
        cout << 0 << endl;
    }else{
        cout << max - first + 1 << endl;
    }
    return 0;
}