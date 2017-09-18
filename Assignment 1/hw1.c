/**************************************************************************************************************************************************************************************
Author: Dhairya Dhondiyal
E-Mail: dd339@njit.edu
**************************************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
static inline char* asm_sub_str(char *dest,char *src,int s_idx,int edix)
{
  int count=edix-s_idx+1;                                                            //Set loop count
  src+=s_idx;                                                                        //Set Starting Index
  __asm__ __volatile__("cld;"                                                        //}
                       "rep;"                                                        //}Move from Source register to Destination Register while incrementing address
                       "movsb;"                                                      //}
                       "xor %%al,%%al;"                                              // Set al bit to 0
                       "stosb"                                                       //Store byte from al to Destination
                       :
                       :"S"(src),"D"(dest),"c"(count)                                //Set source Destination and count registers, input parameters
                       :"memory"                                                     //Clobbered Register
                       );
    return dest;                                                                     
}
static inline char* sub_str(char *dest,char *src,int s_idx,int edix)
{
    int i;  
    src+=s_idx;                                                                      //Set Src pointer starting index
    for(i=0;i<edix-s_idx+1;i++)                                                      //Loop edix-s_idx+1 number of times
    {
      *dest++=*src++;                                                                //Copy srce pointer to dest pointer while incrementing
    }
    *dest='\0';                                                                      //Set last character as null character
    dest-=edix-s_idx+1;                                                              //Reset Dest pointer to the start
    return dest;
}
int main(int argc, char **argv)
{
    if(argc<4)                                                                        //If less commandline arguments then exit
    {
      printf("Usage:\t./hw1 <String> <Starting Index> <Ending Index>\n");
      exit(0);
    }
    char d[100],*d1,*d2;                                                             //Declare Variables
    d1=sub_str(d,argv[1],atoi(argv[2]),atoi(argv[3]));                               //Call sub_str and store the result in d1
    d2=asm_sub_str(d,argv[1],atoi(argv[2]),atoi(argv[3]));                           //Call asm_sub_str and store the result in d2
    printf("d1 =\t %s\n",d1);                                                        //Print d1  
    printf("d2 =\t %s\n",d2);                                                        //Print d2
    if(!strcmp(d1,d2))                                                               //Compare d1 and d2
      printf("Strings are exactly same\n");                                          //If Strings match display
    else
      printf("Strings are different\n");                                             //If Strings don't match display
    return 0;
}