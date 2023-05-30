#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()


int calc_after( vector<int>& run_length,
                bool is_caps,
                int a,
                int shift_a,
                int s){

    long long time = 0;
    // rep(i,s,run_length.size()){
        if (is_caps){
            if (s % 2 == 0){
                time += shift_a * run_length[s];
            }else{
                time += a * run_length[s];
            }
        }else{
            if (s % 2 == 0){
                time += a * run_length[s];
            }else{
                time += shift_a * run_length[s];
            }
        }
    // }
    return time;
}

int main(){
    int a,shift_a,caps_lock;
    string text;
    cin >> a >> shift_a >> caps_lock >> text;

    vector<int> run_length;
    int a_count = 0,A_count = 0;
    bool check_a = true;
    run_length.emplace_back(0);
    for (int i = 0,e = text.size();i < e;i++){
        if (check_a){
            if (text[i] == 'a'){
                run_length.back()++;
                a_count++;
            }else{
                check_a = false;
                run_length.emplace_back(1);
                A_count++;
            }
        }else{
            if (text[i] == 'A'){
                run_length.back()++;
                A_count++;
            }else{
                check_a = true;
                run_length.emplace_back(1);
                a_count++;
            }
        }
    }
    // rep(i,0,run_length.size()) cout << run_length[i] << endl << endl; //debug

    bool is_caps = false;
    long long time = 0;
    for (int i = 0,size = run_length.size();i < size;i++){
        long long no_caps,caps;
        no_caps = calc_after(run_length,is_caps,a,shift_a,i);
        caps = calc_after(run_length,!is_caps,a,shift_a,i) + caps_lock;

        if (i % 2 == 0){
            A_count -= run_length[i];
        }else{
            a_count -= run_length[i];
        }
        if (no_caps > caps){
            is_caps = !is_caps;
            time += caps_lock;
            // cout <<"press caps\n"; //debug
        }else if (no_caps == caps){
            if (is_caps){
                if (a_count < A_count){
                    is_caps = !is_caps;
                    time += caps_lock;
                    // cout <<"press caps\n"; //debug
                }
            }else{
                is_caps = !is_caps;
                time += caps_lock;
                // cout <<"press caps\n"; //debug
            }
        }

        if (is_caps){
            if (i % 2 == 0){
                time += shift_a * run_length[i];
                // cout << i << " caps shift\n"; //debug
            }else{
                time += a * run_length[i];
                // cout << i << " caps a\n"; //debug
            }
        }else{
            if (i % 2 == 0){
                time += a * run_length[i];
                // cout << i << " a\n"; //debug
            }else{
                time += shift_a * run_length[i];
                // cout << i << " shift\n"; //debug
            }
        }
    }

    cout << time << endl;
    return 0;
}