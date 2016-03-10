#include <stdio.h>
#include <string.h>
#define MAX_LEN (10004)
char msg_orig[MAX_LEN * 2], msg_modified[MAX_LEN * 2];
int main()
{
    int n, i, encoded;
    char input[3], key, msg;
    n = 0;
    input[2] = '\0';
    while (scanf("%s", msg_orig) != EOF) {
        n = strlen(msg_orig);
        n /= 2;
        scanf("%s", msg_modified);
        input[0] = msg_modified[0];
        input[1] = msg_modified[1];
        sscanf(input, "%X", &encoded);
        key = encoded ^ ' ';
        printf("%02X", key);
        for (i = 0; i < n; i++) {
            input[0] = msg_orig[2 * i];
            input[1] = msg_orig[2 * i + 1];
            sscanf(input, "%X", &encoded);
            msg = key ^ encoded;
            input[0] = msg_modified[2 * (i + 1)];
            input[1] = msg_modified[2 * (i + 1) + 1];
            sscanf(input, "%X", &encoded);
            key = msg ^ encoded;
            printf("%02X", key);
        }
        printf("\n");
    }
    return 0;
}