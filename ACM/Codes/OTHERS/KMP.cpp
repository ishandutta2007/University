#include <iostream>
#include<stdio.h>
using namespace std;

const int* get_substring_arr(const char* sequence);
void kmp(const char* src, const char* substring, const int* a);

int main()
{
    char* src = "acabaabaabcacaabcacabaabaabcacaabc";
    char* substring = "abaabcac";
    kmp(src, substring, get_substring_arr(substring));
    return 0;
}

//process the substring
const int* get_substring_arr(const char* substring)
{
    int substring_len = strlen(substring);
    int* a = new int[substring_len];
    a[0] = -1;
    int j = -1;
    for(int i = 1; i < substring_len; i++)
    {
        while(j > -1 && substring[i] != substring[j + 1])
            j = a[j];
        if(substring[j+1] == substring[i])
            j = j + 1;
        a[i] = j;
    }
    for(int i = 0; i < substring_len; i++)
        printf("%d ",a[i]);
    printf("\n");
    return a;
}

//process src & substring to get the position
void kmp(const char* src, const char* substring, const int* a)
{
    int j = -1;
    int substring_len = strlen(substring);
    int src_len = strlen(src);
    for(int i = 0; i < src_len; i++)
    {
        while(j > -1 && src[i] != substring[j + 1])
            j = a[j];
        if(src[i] == substring[j + 1])
            j++;

        if(j == substring_len -1)
        {
            printf("From position %d to position %d\n", i + 2 - substring_len, i+1);
            j = a[j];
        }
    }
}
