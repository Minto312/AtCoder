#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int sequence[N];
    for (int i = 0;i < N;i++){
        cin >> sequence[i];
    }

    string output = "";
    int i = 0;
    while (i < N-1){
        if (sequence[i] < sequence[i+1]){
            for (int j = sequence[i];j < sequence[i+1];j++){
                output += to_string(j) + " ";
            }
        }else{
            for (int j = sequence[i];j > sequence[i+1];j--){
                output += to_string(j) + " ";
            }
        }
        i++;
    }
    output += to_string(sequence[i]);

    cout << output << endl;

    // system("pause");
    return 0;
}