#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Data{
    int num;
    char lname[20];
    char fname[20];
    double balance;
}data[120];


void init_file(){
    FILE *fin = fopen("credit.dat","r");

    for(int i = 1; i <= 100; i++){
        printf("Enter account number\n");
        scanf("%d", &data[i].num);
        if(data[i].num == 0)
        {
            fclose(fin);
            return;
        }
        printf("Enter lastname, firstname, balance\n");
        scanf("%s%s%lf",data[i].lname,data[i].fname, &data[i].balance);
    }
    fclose(fin);
    return;
}

void write_file(){


}




int main(){

    init_file();
//    write_file();



    return 0;
}
