#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include <iostream>

using namespace std;

typedef unsigned short extchar;
typedef unsigned char boolean;
char* caeser_encrypt(char* plain_text, int k)
{

  // printf("%d %d\n", sizeof(char), sizeof(extchar));
  //
  char k_real = (char)(k % 52); // 周期 62
  int length = strlen(plain_text);

  char* encrypted_text = (char*)malloc(sizeof(char) * length);
  char* plain_text_inner = plain_text;
  // its outer plain test in fact!!!

  char* encrypted_text_inner = encrypted_text;
  
  memset(encrypted_text_inner, 0, sizeof(encrypted_text_inner));
  printf("%s\n%s\n", plain_text_inner, encrypted_text_inner);


  for (int index = 0; index < length; index++)
  {
    extchar current_char = (extchar)*plain_text_inner;
    if ((current_char > 64 && current_char < 91) || (current_char > 96 && current_char < 123)) {
      // current_char += k_real; // cuo! ascii code is not consecutive
      int tmp = k_real;
      while (tmp--)
      {
        current_char++;
        if (current_char == 'z' + 1) current_char = 'A';
        else if (current_char == 'Z' + 1) current_char = 'a';
      }
    }

    *encrypted_text_inner = (char)current_char;
    plain_text_inner++;
    encrypted_text_inner++;
  }
*encrypted_text_inner = '\0';
  // printf("!!%s!!\n", encrypted_text);
return encrypted_text;
}
char* caeser_decrypt(char* encrypted_text, int k)
{
  char k_real = (char)(k % 52);
  int length = strlen(encrypted_text);
  char* plain_text = (char*)malloc(sizeof(char) * length);
  char* encrypted_text_inner = encrypted_text;
  char* plain_text_inner = plain_text;
  for (int index = 0; index < length; index++)
  {
  extchar current_char = (extchar)*encrypted_text_inner;
  if ((current_char > 64 && current_char < 91) || (current_char > 96 && current_char < 123))
  {
    //ascii code is not consecutive
    int tmp = k_real;
    while (tmp--)
    {
      current_char--;
      if (current_char == 'a' - 1) current_char = 'Z';
      else if (current_char == 'A' - 1) current_char = 'z';
    }
  }
  *plain_text_inner = (char)current_char;
  encrypted_text_inner++;
  plain_text_inner++;
  }
  *plain_text_inner = '\0';
  return plain_text;
}
int main()
{
char* input = "MSC Debug Contest 2016";
int length = strlen(input);




char* encrypt_output = caeser_encrypt(input, 25);




printf("Encrypted Text: %s\n", encrypt_output);
char* decrypt_output = caeser_decrypt(encrypt_output, 25);
printf("Decrypted Text: %s\n", decrypt_output);
printf("\n");
    return 0;
}
