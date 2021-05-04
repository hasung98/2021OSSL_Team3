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
        else if(menu == 3){
            int no = selectDataNo(s,index);
            if(no>0){
                updateCalendar(&s[no-1]);
            }
        }
        else if(menu == 4){
            int no = selectDataNo(s,index);
            if(no>0){
                int ok;
                printf("정말로 삭제하시겠습니까? (삭제를 하시려면 1을 입력하세요)");
                scanf(" %d",&ok);
                if(ok == 1){
                    deleteCalendar(&s[no-1]);
                    count--;
                }
            }
        }
    }
}