#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef char BYTE;

extern "C" int _cdecl iq(BYTE*, int*, BYTE);
extern "C" int _cdecl oq(BYTE*, int*, BYTE*);
extern "C" int _cdecl pq(BYTE*, int, int);

extern "C" BYTE buffer[16];
extern "C" int ip;
extern "C" int op;
extern "C" int buffersize;

extern "C" void incp(int *p)
{
    *p = (*p + 1) % 16;
}

int main()
{

    ip = 0;
    op = 0;
    buffersize = 0;

    int ret;
    char c;
    char t;


    printf("��ѡ��ESC �˳�; - �Ӷ�����ȡԪ����ʾ + ��ӡ��ǰ���У� 0-9A-Z������У������ַ�������\n");


    while (1)
    {
        c = _getche();

        if (c == 0x1B)
        {
            break;
        }

        if (c == '-')
        {
            ret = oq(buffer, &op, &t);

            if (ret == 0)
            {
                printf("EMPTY!\n");
            }
            else
            {
                printf("��ȡ��Ԫ��Ϊ��%c\n", t);
            }

            continue;
        }

        if (c == '+')
        {
            printf("\n��ǰ��������Ϊ��");
            pq(buffer, ip, op);
            printf("�����±�Ϊ��%d ��β�±�Ϊ��%d\n", op, ip);
            continue;
        }

        if ((c>='0' && c<='9') || (c>='A' && c<='Z'))
        {

            ret = iq(buffer, &ip, c);

            if(ret == 0)
            {
                printf("\nFULL!\n");
            }

            continue;
        }
    }

    return 0;
}