#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //WRITE ME!
  if (!str) {
    return;
  }
  size_t length = 0;
  char * ptr = str;
  char temp;
  while(*ptr != '\0') { // 确定str的长度
    length++;
    ptr++;
  }
  for (size_t i = 0; i < (length / 2); i++) { // 二叉搜索
    temp = str[i];
    str[i] = str[length-1 -i];
    str[length-1 -i] = temp;
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
