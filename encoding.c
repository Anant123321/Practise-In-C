/*given is a string..take ascii value of every character and divide in group of 6..if perfect 6 is not possible...add required bits of 0
 and make groups of 6...now given is a pattren as char*s...for every group of 6 make..find the equivalent decimal value and use it as index 
on the pattren to get an encoded bit..if u are adding additional bits to make group of 6...add '=' at the end..2 "=" for inputs of 4,7,10 characters 
 and 1 "=" for 2,5,8 characters. Print the encoded string.*/


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* encode(char* input) {
    char *s="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";
    char *output=malloc((((strlen(input)*4)/3)+5)*sizeof(char));
    int i=0;
    int index=0,len=strlen(input);
    for(i=0;i<len-2;i=i+3)
    {
        output[index++]=s[input[i]>>2]; // selecting first 6 bits of Ist character
        output[index++]=s[(( input[i]&0x03 )<<4 ) | ((input[i+1] & 0xF0)>>4)]; // Selecting last 2 bits of 1st character and shiftig them by 4 so that next 4 bits of 2nd character can be added to it 
        output[index++]=s[((input[i+1]&0x0F)<<2) | (input[i+2]&0xC0)>>6];
        output[index++]=s[((input[i+2]&0x3F))];
    }
    if(len%3==1) //if input is of 4,7,10... characters
    {
       output[index++]=s[input[i]>>2];
       output[index++]=s[(( input[i]&0x03 )<<4 )];
       output[index++]= '=';
       output[index++]= '=';
        
    }else{
        if(len%3==2) //if input is of 2,5,8... characters
        {
            output[index++]=s[input[i]>>2];
            output[index++]=s[((input[i]&0x03)<<4 ) | ((input[i+1] & 0xF0)>>4)];
            output[index++]=s[((input[i+1]&0x0F)<<2)];
            output[index++]= '=';
            
        }
    }
    return output;
}
int main() {
   printf("%s",encode("a"));
}

