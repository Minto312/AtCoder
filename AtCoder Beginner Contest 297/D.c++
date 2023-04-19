
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    cin >> a >> b;

    long long count = 0;
    long long dist;
    while(true){
        if(a > b){
            if(b != 1){
                dist = floor(a / b);
                a -= b * dist;
                count += dist;
            }else{
                a -= b;
                count++;
                break;
            }
        }else{
            if(a != 1){
                dist = floor(b / a);
                b -= a * dist;
                count += dist;
            }else{
                b -= a;
                count++;
                break;
            }
        }
    }
    cout << count;
}