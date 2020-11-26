#include <iostream>
#include<math.h>
#define N 1000

using namespace std;

int n, a[N][N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> a[i][j];
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            a[i][j] += min(a[i+1][j], a[i+1][j+1]);
        }
    }
    cout << a[0][0];

    system("pause");
    return 0;
}