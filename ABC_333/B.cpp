#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string n1, n2;
    cin >> n1 >> n2;


    int s1 = n1[0] - 'A';
    int s2 = n1[1] - 'A';
    int s3 = n2[0] - 'A';
    int s4 = n2[1] - 'A';

    // cout << n1 << " " << n2 << endl;
    // cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
    // cout << abs(s2-s1) << " " << abs(s4-s3) << endl;

    int comp1 = abs(s2-s1) <= 2 ? abs(s2-s1) : 5 - abs(s2-s1);
    int comp2 = abs(s4-s3) <= 2 ? abs(s4-s3) : 5 - abs(s4-s3);
    // cout << comp1 << " " << comp2 << endl;

    if (comp1 == comp2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}