char bf[maxn];
int cnt;
int main() {
  cnt = sprintf(bf, "%d ", 100);
  cnt += sprintf(bf+cnt, "%d ", 101);
  cnt += sprintf(bf+cnt, "%s ", "sdfdf");
  printf("%s\n", bf);
  return 0;
}

