// O(N) 预处理质数

vector <int> prime;
bool is_prime[MAXN];
void prime_table(){
    for(int i = 0; i < MAXN; i ++) is_prime[i] = true;
    for(int i = 2 ; i < MAXN; i ++){
        if(is_prime[i]) prime.pb(i);
        for(int j = 0; j < prime.size() && i * prime[j] < MAXN; j ++){
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}

// 快速幂

#define LL long long

LL pow_mod(LL x, LL y, LL z) {
    LL res = 1;
    while(y) {
       if(y & 1) res *= x, res %= z;
       x *= x, x %= z, y >>= 1;
    }
    return res % z;
}

// 扩展欧几里得

void ext_gcd(LL a, LL b, LL &d, LL &x, LL &y) {
     if(!b) {d = a, x = 1, y = 0;}
     else {ext_gcd(b, a % b, d, y, x), y -= x * (a / b);}
}

// 用扩展欧几里得求逆元

LL inv(LL a, LL c) {
    LL d, x, y;
    ext_gcd(a, c, d, x, y);
    return (x + c) % c;
}
