#include <string.h>
#include <stdio.h>
#include "calendar.h"

int main (void){
    Calendar s[100];
    int count = 0; 
    int index = 0; 
    int menu;

    while(1){
        menu = selectMenu();
        if(menu == 0) {
            printf("프로그램이 종료됩니다!\n");
            break;
        }
        else if(menu == 1){
            listCalendar(s,index);
        }
        else if(menu == 2){
            count += createCalendar(&s[index++]);
        }

    }
}