/*
    1. 0~127까지의 ascii code를 출력하는 프로그램을 작성하시오.
    * ascii table
*/
#include <stdio.h>

int main(void)
{
 int ascii;
 for (ascii=0; ascii<=100; ascii++)
    {printf("%c", ascii);}
    return 0;
}