//
// Created by 大妖怪 on 2023/9/13.
//
#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int main()
{
    int n, x;
    unordered_map<int, int> primes;
    cin >> n;
    while(n --)
    {
        cin >> x;

        for(int i = 2; i <= x/i; ++i)
        {
            while(x % i == 0)
            {
                primes[i]++;
                x /= i;
            }
        }
        if(x > 1) primes[x] ++;
    }
    LL res = 1;
    for(auto t: primes)
        res = (res * (t.second+1)) % MOD;
    cout << res << endl;
    return 0;
}
