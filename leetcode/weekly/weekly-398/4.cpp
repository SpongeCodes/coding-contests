using ll = long long;
const ll MOD = 1e9 + 7;
ll fact[35];
class Solution
{
private:
    ll modInv(ll x)
    {
        return x <= 1 ? 1 : MOD - (MOD / x) * modInv(MOD % x) % MOD;
    }
    ll C(int n, int k)
    {
        ll res = fact[n];
        res = (res * modInv(fact[k])) % MOD;
        res = (res * modInv(fact[n - k])) % MOD;
        return res;
    }

public:
    int waysToReachStair(int k)
    {
        // calculate factorials
        // can also precompute combinations using pascals triangle formula
        fact[0] = 1;
        for (int i = 1; i <= 30; i++)
            fact[i] = (i * fact[i - 1]) % MOD;
        ll res = 0, current = 1;
        for (int jmps = 0; jmps <= 30; jmps++)
        {
            // 2^30 is highest number of jumps
            if (current >= k)
            {
                int extra = current - k;
                if (extra <= jmps + 1)
                    res += C(jmps + 1, extra);
                else
                    break;
                // j+1 for spaces for backwards move to fill when
                // j jumps are made
            }
            current += 1 << jmps;
        }
        return res;
    }
};