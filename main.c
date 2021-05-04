#include "calendar.h"

int main (){
    Calendar p[100];
    int count = 0; 
    int index = 0; 
    int menu;
    int exit =1;

    while(exit){
        menu = selectMenu();
        if(menu == 0) {
            printf("프로그램이 종료됩니다!\n");
            exit = 0; //프로그램 종료
        }
        if(menu ==1||menu==3||menu==4||menu ==5)
        {
            if(count == 0) 
            {
                printf("저장된 일정이 없습니다\n");
                continue;
            }
        }
        if(menu == 1){
            listPlan(p,index);
        }
        else if(menu == 2){
            count += createPlan(&p[index++]);
        }
        else if(menu == 3){
            int no = selectDataNo(p,index);
            if(no>0){
                updatePlan(&p[no-1]);
            }
        }
        else if(menu == 4){
            int no = selectDataNo(p,index);
            if(no>0){
                int ok;
                printf("정말로 삭제하시겠습니까? (삭제를 하시려면 1을 입력하세요)");
                scanf(" %d",&ok);
                if(ok == 1){
                    deletePlan(&p[no-1]);
                    count--;
                }
            }
        }
    }
}