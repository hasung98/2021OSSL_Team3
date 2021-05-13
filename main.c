#include "calendar.h"

int main (){
    Calendar p[100];
    int count = loadData(p); 
    int index = count; 
    int menu;
    int exit =1;
    char buff[100];

    while(exit){
        menu = selectMenu();
        if(menu == 0) {
            exit = exit(); //프로그램 종료
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
            int month,ndays,d1;

            month = helpCalendar(buff);   
            ndays = month_days(2021,month);
            d1= first_day(2021,month);
            showCalendar(month, ndays,d1);
        }
        else if (menu == 7){
            saveData(p,index); 
        }
    }
    return 0;
}