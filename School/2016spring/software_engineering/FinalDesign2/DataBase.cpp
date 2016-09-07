#include <bits/stdc++.h>
#include "AVL.cpp"

using namespace std;

char str1[100], str2[100];
int Id;
const int DATA_WIDTH = 28;
AVL::Node *ptr;

AVL avl;

int tot;
int lastid, lastpos;


void creatAVL()
{
  FILE *fp = fopen("a.data", "r");
  int id;
  int pos = 0;
  while(fscanf(fp, "%d %s %s", &id, str1, str2) == 3)
  {
    avl.insert(avl.root, id, pos++);
  }
  fclose(fp);
}

void saveAVL()
{
  FILE *fp = fopen("avl.data", "w");
  int tp = 0, tid = -1;
  avl.save(avl.root, fp);
  FILE *ftot = fopen("tot.data", "w");
  fprintf(ftot, "%d\n", tot);
  printf("avl saved into avl.data\n");
  fclose(fp);
  fclose(ftot);
}

void loadAVL()
{
  FILE *fp = fopen("avl.data", "r");
  int tpos = -1, tid = 0;
  avl.load(avl.root, fp, tpos, tid);
  FILE *ftot = fopen("tot.data", "r");
  fscanf(ftot, "%d", &tot);
  fclose(ftot);
  printf("load data successful!!\n");
  lastid = tid;
  printf("last id = %d\n", tid);
  fclose(fp);
}

int readById()
{
  int id;
  printf("input the id : ");
  scanf("%d", &id);
  ptr = avl.search(avl.root, id);
  return ptr == NULL? -1:ptr->pos;
}

void printData(int pos)
{
  FILE *fp = fopen("a.data", "r");
  printf("[%d]\n",pos);
  fseek(fp, pos * DATA_WIDTH, 0);
  fscanf(fp, "%d %s %s", &Id, str1, str2);
  printf("%d %s %s\n", Id, str1, str2);
  fclose(fp);
}
int searchdata()
{
  int pos =  readById();
  if (pos == -1)
  {
    printf("no data found\n");
    return -1;
  }
  else
  {
    printf("data found!\n");
    printData(pos);
  }
  return pos;
}

void insertdata()
{
  printf("input data\n");
  FILE *fp = fopen("a.data", "a");
  scanf("%d %s %s", &Id, str1, str2);
  fprintf(fp, "%d %s %s\n", Id, str1, str2);
  avl.insert(avl.root, Id, tot++);
  fclose(fp);
  printf("Insert data successful\n");
}

void deletedata()
{
  int delid;
  int delpos;
  printf("input id\n");
  scanf("%d", &delid);
  ptr = avl.search(avl.root, delid);
  if (ptr == NULL)
  {
    printf("no data found\n");
    return;
  }
  delpos = ptr->pos;
  // avl.del_data(delid);
  FILE *fp, *fswap;
  fp = fopen("a.data", "r");
  fswap = fopen("a.swap", "w");
  int tmpid;
  char tmpstr1[100], tmpstr2[100];
  fseek(fp, (tot-1) * DATA_WIDTH, 0);
  fscanf(fp, "%d %s %s", &tmpid, tmpstr1, tmpstr2);

  fseek(fp, 0, 0);
  for (int i = 0; i < tot; i++)
  {
    fscanf(fp, "%d %s %s", &Id, str1, str2);
    if (i == delpos)
    {
      fprintf(fswap, "%d %s %s\n", tmpid, tmpstr1, tmpstr2);
      avl.del_data(tmpid);
      avl.insert(avl.root, tmpid, i);
    }
    else
    {
      fprintf(fswap, "%d %s %s\n", Id, str1, str2);
    }
  }
  avl.del_data(delid);
  tot--;
  fclose(fp);
  fclose(fswap);
  fp = fopen("a.data", "w");
  fswap = fopen("a.swap", "r");
  for (int i = 0; i < tot; i++)
  {
    fscanf(fswap, "%d %s %s", &Id, str1, str2);
    fprintf(fp, "%d %s %s\n", Id, str1, str2);
  }
  // printf("Sorry , the delete operation is not completed yet!!\n");
  // find id of the lastpos;
  fclose(fp);
  fclose(fswap);

  printf("delete successful\n");
}

void showData(AVL::Node *&now)
{
  if (now == NULL) return;
  showData(now->lson);
  printData(now->pos);
  showData(now->rson);
}

int caltest()
{
  int ret = 0;
  for (int i = 0; i < 100000000; i++)
  {
    ptr = avl.search(avl.root, i);
    if (ptr != NULL)
    {
      ret++;
      // printf("id %d found\n", ptr->data);
    }
  }
  return ret;
}

void DBoperation()
{
  char cmd[10];
  while (true)
  {
    printf("input 1 for search\n");
    printf("input 2 for insert\n");
    printf("input 3 for delete\n");
    printf("input 4 for display\n");
    printf("input 5 for test\n");
    printf("input 0 for quit\n");
    scanf("%s", cmd);
    if (cmd[0] == '1')
    {
      searchdata();
    }
    else if (cmd[0] == '2')
    {
      insertdata();
    }
    else if (cmd[0] == '3')
    {
      deletedata();
    }
    else if (cmd[0] == '4')
    {
      // FILE *fp = fopen("a.data", "r");
      showData(avl.root);
      // fclose(fp);
    }
    else if (cmd[0] == '5')
    {
      cout << clock() << endl;
      printf("found %d datas\n", caltest());
      cout << clock() << endl;
    }
    else if (cmd[0] == '0')
      break;
  }


  /*
  FILE *fp = fopen("a.data", "r");
  int pos =  readById();
  if (pos == -1)
  {
    printf("no data found\n");
    return;
  }
  else
  {
    fseek(fp, pos * DATA_WIDTH, 0);
    fscanf(fp, "%d %s %s", &Id, str1, str2);
    printf("data found!\n");
    printf("%d %s %s", Id, str1, str2);
  }
  */
}

void tos(char str[100], int x)
{
  int m[8] = {10000000,1000000,100000,10000,1000, 100, 10, 1};
  for (int i = 0; i < 8; i++)
  {
    str[i] = x / m[i] + '0';
    x %= m[i];
  }
  str[8] = '\0';
  // printf("!!!\n");
}

void initData()
{
  char cmd[10];
  printf("input 1 for random\n");
  printf("input 2 for input\n");

  scanf("%s", cmd);

  if (cmd[0] == '1')
  {
    FILE *fp = fopen("a.data", "w");
    printf("Input the total numbers of data\n");
    scanf("%d", &tot);
    printf("[%d]\n", tot);
    for (int i = 1; i <= tot; i ++)
    {
      Id = i;
      tos(str1, i);
      tos(str2, i);
      fprintf(fp, "%8d %8s %8s\n", Id, str1, str2);
    }
    fclose(fp);
    return;
  }


  FILE *fp = fopen("a.data", "w");
  printf("Input the total numbers of data\n");
  scanf("%d", &tot);
  for (int i = 0; i < tot; i++)
  {
    scanf("%d %s %s", &Id, str1, str2);
    fprintf(fp, "%8d %8s %8s\n", Id, str1, str2); 
  }
  fclose(fp);
  printf("init data successful!!\n");
}



int main()
{
  char cmd[10];
  printf("input 1 for input data\n");
  printf("input 2 for load data\n");
  scanf("%s", cmd);
  if ( cmd[0] == '1')
  {
    initData();
    creatAVL();
  }
  else if (cmd[0] == '2')
  {
    loadAVL();
  }
  // avl.show(avl.root);
  DBoperation();
  // saveAVL to avl.data;
  saveAVL();
  return 0;
}

