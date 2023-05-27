#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int bnt_dp (int person[], int n){
    int temp1, temp2;

    if(n < 3){
        return person[n-1];
    } else if (n == 3) {
        return person[0] + person[1] + person[2];
    } else {
        temp1 =  person[n-1] + person[0] + person[n - 2] + person[0];
        temp2 =  person[1] + person[0] + person[n - 1] + person[1];

        if (temp1 < temp2){
            return temp1 + bnt_dp(person, n-2);
        } else if (temp2 < temp1){
            return temp2 + bnt_dp(person, n-2);
        } else {
            return temp2 + bnt_dp(person, n-2);
        }
    }
}


int main()
{
    int jml_orang, time_min, time_temp;

    cout << "Masukkan jumlah orang: ";
    cin >> jml_orang;
    int a[jml_orang];

    cout << "Masukkan waktu masing-masing orang:\n";
    for(int i = 0; i < jml_orang; i++){
        cout << i + 1 << ". ";
        cin >> a[i];
    }

    sort(a, a+jml_orang);

    for(int i = 0; i < jml_orang; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Waktu minimum: " << endl;
    cout << bnt_dp(a, jml_orang);
    return 0;
}
