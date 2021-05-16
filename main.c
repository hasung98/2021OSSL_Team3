#include "calendar.h"

int main (){
    Planner p[100];
    int count = loadData(p); 
    int index = count; 
    int menu;
    int exit = 1;

    while(exit){
        menu = selectMenu();
        if(menu == 0) {
            exit = finish(); //프로그램 종료
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
            totalPlan(p,index);
        }
        else if(menu == 2){
            count += updatePlan(&p[index++]);
        }
        else if(menu == 3){
            int no = selectDataNo(p,index);
            if(no>0){
                updatePlan(&p[no-1]);
            }
        }
        else if(menu == 4){
            int ok=-1;
            int no = selectDataNo(p,index);
            if(no>0)
                ok = deletePlan(&p[no-1]);
            if(ok==1) count--;
        }
        else if (menu == 5){
            search_Plan(p, count);
        }
        else if (menu == 6){
            int year = 2021; //2021년도 달력으로 년도 고정
            Calendar(year);
        }
        else if (menu == 7){
            saveData(p,index); 
        }
    }
    return 0;
}