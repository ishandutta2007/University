#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int MAXN = 2400001, MAXS = 111;

class HashTable
{
private:
    struct Node
    {
        string key, value; Node *next;
        inline Node() { next = NULL; }
        inline Node(const string& _key, const string& _value, Node *_next)
        { key = _key, value = _value, next = _next; }
    }Npool[MAXN], *Nptr, *adj[MAXN];

    unsigned int BKDRHash(const string& Str)
    {
        unsigned int seed = 131;
        unsigned int hash = 0;
        const char *str = Str.c_str();
        while (*str)
            hash = hash * seed + (*str++);
        return (hash & 0x7FFFFFFF) % MAXN;
    }
public:
    HashTable() { clear(); }
    void clear() { Nptr = Npool; }
    void insert(const string& key, const string& value)
    {
        int h = BKDRHash(key);
        adj[h] = new(Nptr++)Node(key, value, adj[h]);
    }
    string query(const string& key)
    {
        int h = BKDRHash(key);
        for (Node *p = adj[h]; p; p = p->next)
            if (p->key == key)
                return p->value;
        return "NULL";
    }
};

HashTable ht;
char str[MAXS]; int N;

string key, value; char s2[MAXS];

void input()
{
    for (int i = 1; i <= 2352079; i++)
    {
        gets(str);


        str[42] = '\0';
        key = str + 10;

        value = str + 43;

        /*cout << str << '\n';
        cout << key << ' ' << value << '\n';*/

        ht.insert(key, value);

        if (i % 100000 == 0)
            printf("Now inserting %d\n", i);
    }
}

int main()
{
    srand(time(0));
    //datamaker();
    //datamaker2();

    freopen("J:\\NodeInfo.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    input();

    cin >> key;
    cout << ht.query(key);

    cin >> key;
    cout << ht.query(key);
    return 0;
}
