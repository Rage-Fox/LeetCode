typedef long long ll;
class Solution {
public:
    const int mod = 1e9 + 7;
    ll binary_exp(ll x, ll n) {
        ll ans = 1;
        x %= mod;
        while (n) {
            if (n & 1)
                ans = (ans * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        ll ans = 0;
        for (auto num : nums) {
            ll w = num % 10;
            ll d = num / 10;
            string d_str = to_string(d);
            ll x = stoll(d_str.substr(0, w));
            ll y = stoll(d_str.substr(w));
            ans = (ans + binary_exp(x, y)) % mod;
        }
        return ans;
    }
};