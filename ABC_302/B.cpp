#include <bits/stdc++.h>
using namespace std;
#define loop(i,s,e) for(int i = s;i < e;i++)


void print_arr(vector<vector<char>>& arr){
    loop(i,0,8){
        loop(j,0,8){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

bool search(const pair<int,int> current,
            int snuke_idx,vector<vector<char>>& words,
            string snuke,
            stack<string>& result,
            vector<vector<bool>>& cant_go){

    while(true){

        int row = current.first;
        int col = current.second;

        string ret = to_string(row) + " " + to_string(col);
        if (snuke_idx == 5){
            // cout << "snuke_idx == 5" << endl; //debug
            result.push(ret);
            return true;
        }
        // cout << "current  " << ret << "   idx = " << snuke_idx << endl; //debug

        bool res;
        char cur_snuke = snuke.at(snuke_idx);
        for (int row_d = -1;row_d <= 1;row_d++){
            for (int col_d = -1;col_d <= 1;col_d++){
                if (row_d == 0 && col_d == 0) continue;
                if (words[row+row_d][col+col_d] == '#') continue;
                if (cant_go[row_d+1][col_d+1]) continue;

                if (words[row+row_d][col+col_d] == cur_snuke){
                    cant_go.assign(3,vector<bool>(3,true));
                    cant_go[row_d+1][col_d+1] = false;
                    res = search(make_pair(row+row_d,col+col_d),snuke_idx + 1,words,snuke,result,cant_go);
                    if (res){
                        result.push(ret);
                        // cout << "return  " << cur_snuke << endl; //debug
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
}
pair<int,int> make_pair(int a,int b){
    pair<int,int> ret;
    ret.first = a;
    ret.second = b;
    return ret;
}

int main(){
    const string snuke = "snuke";

    int H,W;
    cin >> H >> W;
    vector<vector<char>> words(H+2,vector<char>(W+2));

    queue<pair<int,int>> searching;
    string temp;
    char cur_char;
    char s;
    s = snuke.at(0);
    pair<int,int> append;
    loop(i,0,W+2){
        words[0][i] = '#';
        words[H+1][i] = '#';
    }
    loop(i,0,H+2){
        words[i][0] = '#';
        words[i][W+1] = '#';
    }
    loop(i,1,H+1){
        cin >> temp;
        loop(j,1,W+1){
            cur_char = temp.at(j-1);
            if (cur_char == s){
                append.first = i;
                append.second = j;
                searching.push(append);
            }
            words[i][j] = cur_char;
        }
    }
    // print_arr(words); //debug

    bool res = false;
    stack<string> result;
    vector<vector<bool>> cant_go(3,vector<bool>(true));
    while(result.empty()){
        cant_go.assign(3,vector<bool>(3,false));
        search(searching.front(),1,words,snuke,result,cant_go);
        if (res) break;
        searching.pop();
    }
    // cout << "start pop" << endl; //debug
    // cout << "res size  =  " << result.size() << endl; //debug
    while(!result.empty()){
        cout << result.top() << endl;
        result.pop();
    }
    return 0;
}