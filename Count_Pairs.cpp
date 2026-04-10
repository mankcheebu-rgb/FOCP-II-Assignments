#include<bits/stdc++.h>
using namespace std;
int countDistinctPrimes(long long n){
    int count =0;
    for(long long i=2;i * i <= n; i++){
        if (n%i ==0){
            count++;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if (n>1) count++;
    return count;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
         int k = countDistinctPrimes(n);
         cout << (1LL << k) << '\n';
    }
    return 0;
}