// use the functions in modular inverse problems

// use these overloaded operators for both p and q

/*

#######start copy#####

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
    ll ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

ll divide(ll x, ll y)
{
    return mul(x, binpow(y, MOD - 2));
}
#######end copy#####
*/