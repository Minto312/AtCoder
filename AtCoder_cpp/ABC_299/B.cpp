#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;

    string color;
    cin >> color;

    string colorArr;
    getline(cin,colorArr);

    string numbers;
    getline(cin,numbers);

    cout << endl << N << color << colorArr << numbers;
    cin >> N;

}