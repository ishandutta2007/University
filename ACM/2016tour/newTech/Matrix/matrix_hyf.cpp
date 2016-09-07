#define N 2
#define M 1000000007
LL fis[N];
struct mart
{
    LL a[N][N];
    mart(int x){
        memset(a,0,sizeof(a));
        if (x==1)
        rep(i,0,N) a[i][i]=1;
        if (x==2)
        {
            a[0][0]=lala;a[0][1]=0;
            a[1][0]=1;a[1][1]=1;
        }    
    };
    mart operator *(mart &b)
    {
        mart c(0);
        rep(i,0,N)
            rep(j,0,N)
            if (a[i][j])
                rep(k,0,N)
                c.a[i][k]=(c.a[i][k]+a[i][j]*b.a[j][k])%M;
        return c;
    }
    void show()
    {
        puts("_________________");
        rep(i,0,N)
        {
            rep(j,0,N)
            printf("%d ",a[i][j]);
            puts("");
        }
        puts("_________________");
    }
};
LL pow(LL k)
{
    if (k<0) return 1;
    mart ret(1),a(2);
    //a.show();
    while (k)
    {
        if (k&1) ret=ret*a;
        a=a*a;k>>=1; 
    }
    // ret.show();
    LL ans=0;
    rep(i,0,N)
    ans=(ans+fis[i]*ret.a[i][0]%M)%M;
    return ans;
}
