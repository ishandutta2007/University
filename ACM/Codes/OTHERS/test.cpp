# include < stdio.h >
union {
int a [2];
double b ;
char c [8];
} x ;
int main ()
{
x. c [0] = ’G ’;
x. c [1] = ’O ’;
x. c [2] = ’O ’;
x. c [3] = ’D ’;
x. c [4] = ’B ’;
x. c [5] = ’A ’;
x. c [6] = ’B ’;
x. c [7] = ’Y ’;
printf ( " int :Ã% d Ã byte ( s )\ n " , sizeof ( int ));
printf ( " double :Ã% d Ã byte ( s )\ n " , sizeof ( double ));
printf ( " char :Ã% d Ã byte ( s )\ n " , sizeof ( char ));
printf ( " bool :Ã% d Ã bytes ( s )\ n " , sizeof ( bool ));
printf ( " \ n " );
printf ( " integer :Ã% d Ã% d \ n " , x . a [0] , x . a [1]);
printf ( " real Ã number :Ã% e \ n " , x . b );
printf ( " characters :Ã% c % c % c % c % c % c % c % c \ n " , x . c [0] , x . c [1] , x . c [2] ,
x . c [3] , x . c [4] , x . c [5] , x . c [6] , x . c [7]);
printf ( " HEX :Ã% X % X % X % X % X % X % X % X \ n " , x . c [0] , x . c [1] , x . c [2] , x . c [3] ,
x . c [4] , x . c [5] , x . c [6] , x . c [7]);
return 0;
}

