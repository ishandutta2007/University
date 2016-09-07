/*
 * getH(s, l, H)
 * 求从位置s开始长度为l的字符串的hash值
 * O(n) 预处理，O(1) 查询
 */
const ull xxx = 131;
ull H[maxn], HR[maxn], xl[maxn];
void prepre()
{
  xl[0] = 1;
  for (int i = 1; i < maxn; i++)
    xl[i] = xxx * xl[i-1];
}
void pre(char *str, ull *H)
{
  memset(H, 0, sizeof(H));
  int len = strlen(str);
  H[len] = 0;  
  for (int i = len-1; i >= 0; i--)
  {
    H[i] = H[i+1]*xxx + str[i];
  }
}

ull getH(int s, int l, ull *H)
{
  return H[s] - H[s+l] * xl[l];
}

// BKDR Hash Function
// 也可以将返回类型设为ull, 免去取模运算(&)
unsigned int BKDRHash(char *str)
{
  unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
  unsigned int hash = 0;
  while (*str)
  {
    hash = hash * seed + (*str++);
  }
  return (hash & 0x7FFFFFFF);
}
