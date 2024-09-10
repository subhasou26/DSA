#include <stdio.h>
#include <string.h>
 
char* reverseString(char *string, int leftIndex, int rightIndex);
 
int main() {
   //char inputArray[100];
  
   char val1[100];
        printf("enter the string to reverse:\n");
        gets(val1);
    
   reverseString(val1, 0, strlen(val1) - 1);
   printf("Reversed string\n%s", val1);
 
   return 0;
}
 
char* reverseString(char *string, int leftIndex, int rightIndex){
      char ch;
       
      if(NULL == string || leftIndex > rightIndex)
          return NULL;
 
      ch = string[leftIndex];
      string[leftIndex] = string[rightIndex];
      string[rightIndex] = ch;
       
      reverseString(string, leftIndex + 1, rightIndex - 1);
      return string;
}