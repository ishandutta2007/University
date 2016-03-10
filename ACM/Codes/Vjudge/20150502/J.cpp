#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>

using namespace std;

map<char, char>dic;


int main(){


    dic['-'] = '[';
    dic['_'] = '{';
    dic['='] = ']';
    dic['+'] = '}';
    dic['q'] = '\'';
    dic['Q'] = '\"';
    dic['w'] = ',';
    dic['W'] = '<';
    dic['e'] = '.';
    dic['E'] = '>';
    dic['r'] = 'p';
    dic['R'] = 'P';
    dic['t'] = 'y';
    dic['T'] = 'Y';
    dic['y'] = 'f';
    dic['Y'] = 'F';
    dic['u'] = 'g';
    dic['U'] = 'G';
    dic['i'] = 'c';
    dic['I'] = 'C';
    dic['o'] = 'r';
    dic['O'] = 'R';
    dic['p'] = 'l';
    dic['P'] = 'L';
    dic['['] = '/';
    dic['{'] = '?';
    dic[']'] = '=';
    dic['}'] = '+';
    dic['s'] = 'o';
    dic['S'] = 'O';
    dic['d'] = 'e';
    dic['D'] = 'E';
    dic['f'] = 'u';
    dic['F'] = 'U';
    dic['g'] = 'i';
    dic['G'] = 'I';
    dic['h'] = 'd';
    dic['H'] = 'D';
    dic['j'] = 'h';
    dic['J'] = 'H';
    dic['k'] = 't';
    dic['K'] = 'T';
    dic['l'] = 'n';
    dic['L'] = 'N';
    dic[';'] = 's';
    dic[':'] = 'S';
    dic['\''] = '-';
    dic['\"'] = '_';
    dic['z'] = ';';
    dic['Z'] = ':';
    dic['x'] = 'q';
    dic['X'] = 'Q';
    dic['c'] = 'j';
    dic['C'] = 'J';
    dic['v'] = 'k';
    dic['V'] = 'K';
    dic['b'] = 'x';
    dic['B'] = 'X';
    dic['n'] = 'b';
    dic['N'] = 'B';
    dic[','] = 'w';
    dic['<'] = 'W';
    dic['.'] = 'v';
    dic['>'] = 'V';
    dic['/'] = 'z';
    dic['?'] = 'Z';


    char ch;

    while(scanf("%c", &ch) != EOF){
        if(!dic[ch])
            printf("%c", ch);
        else
            printf("%c", dic[ch]);
    }







    return 0;
}

