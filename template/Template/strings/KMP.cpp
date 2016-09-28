const int maxn = 1000020;
char src[maxn],substring[maxn];
int nxt[maxn];
void get_nxt(char* substring) {
  int substring_len = strlen(substring);
  memset(nxt, 0, sizeof(nxt));
  nxt[0] = -1;
  int j = -1;
  for(int i = 1; i < substring_len; i++)
  {
    while(j > -1 && substring[i] != substring[j + 1])
      j = nxt[j];
    if(substring[j+1] == substring[i])
      j = j + 1;
    nxt[i] = j;
  }
}
//process src & substring to get the position
int kmp(char* src, char* substring) {
  int j = -1; int ans = 0;
  int substring_len = strlen(substring);
  int src_len = strlen(src);
  for(int i = 0; i < src_len; i++) {
    while(j > -1 && src[i] != substring[j + 1])
      j = nxt[j];
    if(src[i] == substring[j + 1])
      j++;
    if(j == substring_len -1) {
      ans ++;
          printf("From position %d to position %d\n", i + 2 - substring_len, i+1);
      j = nxt[j];
    }
  }
  return ans;
}
