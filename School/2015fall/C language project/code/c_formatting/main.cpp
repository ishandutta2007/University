#include<stdio.h>
#include<string.h>
#include<stdlib.h>


using namespace std;
int format_and_save(char input_file[], char output_file[]);
void start_and_intro();
int formatting();
//int split();
void line_ajust(char s[100000], int *n);


int main(){


    start_and_intro();
    if(formatting()) printf("Your code has been formatted .\n");
    else printf("Formatting denied .\n");
    return 0;
}

void start_and_intro(){
/*
this function shows the basic information to the user
and give a brief introduction of the program
*/

//program informations
    printf("=======================================================\n");
    printf("=                 Hello Hello Hello                   =\n");
    printf("=      Welcome to the C language formatting tool      =\n");
    printf("=             This is a PoorE product                 =\n");
    printf("=             Last built in 2015.05.28                =\n");
    printf("=         If you find any bugs, please tell me        =\n");
    printf("=                  py@hit.edu.cn                      =\n");
    printf("=======================================================\n");
    printf("\
*This tool can Format a C/C++ code into a PoorE's style code\n\
*You can choose the source file and the output file\n");
    printf("\n\n\n\npress any key to continue\n");
    char cmd[10];
    gets(cmd);
//*do you wanna to see more details of the programs?(yes/no)\n
//    char cmd[10];
    //if(yes) showdetail();
}


int formatting(){
    FILE *fin,*fout;
    char input_file[40], output_file[40];
    printf("Now please input the name of the source code file you want to format:\n");
    while(true){
        scanf("%s",input_file);
        fin = fopen(input_file, "r");

        if(fin){
            printf("%s opened\n", input_file);
            break;
        }
        else
            printf("failed to open %s, please check the file name and try again:\n", input_file);
    }
    fclose(fin);

    while(true){
        printf("Please input the name of the file where you want to save the formatted code:\n");
        scanf("%s", output_file);
        fout = fopen(output_file, "r");
        if(fout){
            printf("%s has been existed, do you want to overwrite it?(yes/no)\n", output_file);
            char cmd[10];
            scanf("%s", cmd);
            if(strcmp(cmd, "yes") == 0)
            {
                fclose(fout);
                break;
            }
            else if(strcmp(cmd, "no") == 0)
            {
                fclose(fout);
            }
        }
        else{
            fclose(fout);
            break;
        }
    }

    printf("Formatting code from %s to %s ...\n", input_file, output_file);

    while(true){
        if(format_and_save(input_file, output_file))
            return 1;

        else
        {
            printf("Something unexpected has happened when formatting you code, try it again?(yes / no)\n");
            char cmd[10];
            scanf("%s", cmd);
            if(strcmp(cmd, "no") == 1)
                return 0;
        }
    }
}

char instr[100000][100];
char oustr[100000][100];

int format_and_save(char input_file[], char output_file[]){

    int instr_len = 0;
    int oustr_len = 0;
    FILE *fin = fopen(input_file, "r");
    memset(instr, 0, sizeof(instr));
    memset(oustr, 0, sizeof(oustr));

/*
    while(fscanf(fin, "%s", instr[instr_len]) != EOF){
        instr_len ++;
        if(instr[instr_len - 1][0] == '#')
            continue;
        while(split() == 1);
    }

    for(int i = 0; i < instr_len; i++){
        printf("%s\n", instr[i]);
    }


    fclose(fin);

    FILE *fout = fopen(output_file, "w");
    int cnttab = 0;
    int is_first = 1;
    for(int i = 0; i < instr_len; i++){
        if(is_first){
            for(int j = 1; j <= cnttab; j++)
                fprintf(fout, "    ");
            is_first = 0;
        }
        if(instr[i][0] == '#'){
            fprintf(fout, "%s\n", instr[i]);
            is_first = 1;
            continue;
        }
        fprintf(fout, "%s ", instr[i]);
        if(instr[i][strlen(instr[i]) - 1] == ';') {
            fprintf(fout, "\n");
            is_first = 1;
        }
        if(instr[i][strlen(instr[i]) - 1] == '{') {
            fprintf(fout, "\n");
            is_first = 1;
            cnttab++;
        }
        if(instr[i][strlen(instr[i]) - 1] == '}') {
            fprintf(fout, "\n");
            is_first = 1;
            cnttab--;
        }

    }
    */
    int is_blank(char s[100000]);
    while(fgets(instr[instr_len], 100000 - 1, fin)){
        int head = 0;
        while(instr[instr_len][head] == ' ') head++;

        for(int i = head, len = strlen(instr[instr_len]); i <= len; i++)
            instr[instr_len][i - head] = instr[instr_len][i];
        if(is_blank(instr[instr_len]) == 1) instr_len--;
        instr_len ++;
    }
    fclose(fin);
    printf("Reading file completed...\n");


    FILE *fout = fopen(output_file, "w");
    int cnt_tab = 0;
    for(int i = 0; i < instr_len; i++)
    {

        if(instr[i][0] == '}') cnt_tab --;
        for(int j = 1; j <= cnt_tab; j++) fprintf(fout, "    ");
        if(instr[i][0] == '#')
        {
            fprintf(fout, "%s", instr[i]);
            continue;
        }

        line_ajust(instr[i], &cnt_tab);
        fprintf(fout, "%s", instr[i]);
    }

    printf("Formatting completed...\n");
    return 1;
}


void line_ajust(char s[100000], int *cnt){

    if(s[strlen(s) - 2] == '{')
        (*cnt) ++;
//    else if(s[strlen(s) - 2] == '}')
//        (*cnt) --;
}
int is_blank(char s[100000]){
    for(int i = 0, len = strlen(s); i < len; i++)
        if((s[i] != ' ') && (s[i] != '\n')) return 0;
    return 1;
}

/*
char symbol_blank[20] = {'<','>','{','}','(',')','=','+','-','*','/'};
int split(){
    printf("In split \n");

    if(strlen(instr[instr_len - 1]) <= 1) return 0;
    for(int i = 0,len = strlen(instr[instr_len - 1]) ; i < len; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if(instr[instr_len - 1][i] == symbol_blank[j])
            {
                instr[instr_len][0] = symbol_blank[j];
                strcpy(instr[instr_len + 1], instr[instr_len - 1] + i + 1);
                instr[instr_len - 1][i] = '\0';
                instr_len += 2;
                if(strlen(instr[instr_len - 1]) ==  0) instr_len -- ;
                return 1;
            }
        }
    }
    return 0;
}
*/
