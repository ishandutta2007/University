#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
//#define DATAMAKER
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int NS = 5, TN = 1000, TC = 100;
const int BEI = 20;
const int MOD = TN * BEI, MAXM = MOD;

char tmpstr[NS + 1], testcase[TC + 1][NS + 1];
void datamaker()
{
    freopen("in.txt", "w", stdout);

    tmpstr[NS] = '\0';

    srand(time(0));

    printf("%d\n", TN);
    for (int i = 1; i <= TN; i++)
    {
        for (int j = 0; j < NS; j++)
            tmpstr[j] = rand() % 94 + 33; //33~126
        printf("%s\n", tmpstr);

        if (i <= TC)
            strcpy(testcase[i], tmpstr);
    }
    printf("\n%d\n", TC);
    for (int i = 1; i <= TC; i++)
        printf("%s\n", testcase[i]);
}

class HashTable
{
protected:
    unsigned int BKDRHash(const string& Str)
    {
        unsigned int seed = 131;
        unsigned int hash = 0;
        const char *str = Str.c_str();
        while (*str)
            hash = hash * seed + (*str++);
        return (hash & 0x7FFFFFFF) % MOD;
    }
public:
    virtual void clear() = 0;
    virtual int insert(const string&) = 0;
    virtual int query(const string&) = 0; //return Location
};

class HashTableOpen : HashTable //Open Hashing
{
private:
    string lst[MOD];
public:
    HashTableOpen() { clear(); }
    void clear() { for (int i = 0; i < MOD; i++) lst[i].clear(); }
    int insert(const string& str)
    {
        int h = BKDRHash(str), ret = 0;
        while (lst[h] != "")
        {
            ret++;
            if (++h >= MOD) //Suppose Never FULL
                h = 0;
        }

        lst[h] = str;
        return ret;
    }
    int query(const string& str)
    {
        int h = BKDRHash(str);
        while (lst[h] != "" && lst[h] != str)
            if (++h >= MOD)
                h = 0;
        if (lst[h] == "")
            return -1;
        return h;
    }
};

class HashTableClose : HashTable //Close Hashing
{
private:
    struct Node
    {
        string str; Node *next;
        inline Node() { next = NULL; }
        inline Node(const string& _str, Node *_next)
        { str = _str, next = _next; }
    }Npool[MAXM], *Nptr, *adj[MOD];
public:
    HashTableClose() { clear(); }
    void clear() { Nptr = Npool; }
    int insert(const string& str)
    {
        int h = BKDRHash(str);
        adj[h] = new(Nptr++)Node(str, adj[h]);
        return 0;
    }
    int query(const string& str)
    {
        int h = BKDRHash(str);
        for (Node *p = adj[h]; p; p = p->next)
            if (p->str == str)
                return h;
        return -1;
    }
};

string s[TN + 1], query[TN + 1]; int Nh, Q;
void input()
{
    scanf("%d", &Nh);
    for (int i = 1; i <= Nh; i++)
    {
        scanf("%s", tmpstr);
        s[i] = tmpstr;
    }

    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++)
    {
        scanf("%s", tmpstr);
        query[i] = tmpstr;
    }
}

void Work(HashTable *ht, const char* hint)
{
    printf("Operations on %s\n", hint);

    ht->clear();
    for (int i = 1; i <= Nh; i++)
    {
        int tmp = ht->insert(s[i]); //Reset
        if (tmp > 0)
        cout << s[i] << " inflicted " << tmp << " times.\n";
//            printf("%s inflicted %d times.\n", s[i], tmp);
    }

    for (int i = 1; i <= Q; i++)
    {
        int tmp = ht->query(query[i]);
        printf("\"%s\" ", query[i].c_str());
        if (tmp == -1)
            printf("Not found.\n");
        else
            printf("Found at: %d\n", tmp);
    }
    printf("\n");
}

HashTableOpen ht1;
HashTableClose ht2;
int main()
{
    srand(time(0));

#ifdef DATAMAKER
    datamaker();
#else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    input();

    Work((HashTable*)(&ht1), "HashTable in Open (rate: 0.05)");
    Work((HashTable*)(&ht2), "HashTable in Zip");
#endif // DATAMAKER

    return 0;
}
