#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()

int main(){
    int N,length;
    cin >> N >> length;

    vector<string> words(N);
    rep(i,0,N){
        cin >> words[i];
        // cout << "input word   " << words[i] << endl; //debug
    }

    sort(all(words));
    bool ok = true;
    int mis_count = 0;
    // int permutation_count = 0; //debug
    do{
        ok = true;
        mis_count = 0;
        rep(i,0,N-1){
            rep(j,0,length){
                if (words[i][j] != words[i+1][j]){
                    mis_count++;
                    // if (mis_count == 2) break;
                }
                // cout << words[i][j] << "  !=  " << words[i+1][j] << "\nmis  " << mis_count << endl; //debug
            }
            if (mis_count != 1){
                ok = false;
                // break;
            }
            mis_count = 0;
        }
        if (ok){
            cout << "Yes" << endl;
            return 0;
        }
        // cout << "permutation  " << ++permutation_count << endl; //debug
    }while(next_permutation(all(words)));

    cout << "No" << endl;
    
    return 0;
}