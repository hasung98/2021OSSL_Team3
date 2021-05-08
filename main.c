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
                printf("\n** 정말로 삭제하시겠습니까?(삭제: 1) ");
                scanf(" %d",&ok);
                if(ok == 1){
                    deletePlan(&p[no-1]);
                    count--;
                }
            }
        }
        else if (menu == 5){
            int check = -1;
            while(check != 1 && check != 2){    
                printf("\n[ 일정 검색 ]\n");
                printf("\n검색방법을 입력해주세요(종료: 0)");
                printf("\n----------------------------\n");
                printf("1. 분류로 검색(시험/과제/팀플/기타)\n2. 날짜로 검색\n");
                printf("----------------------------\n");
                printf("=> ");
                scanf("%d",&check);
                if(check == 0) break; //0 입력시 처음으로
                if(check!=1 && check!=2) printf("\n잘못 입력하셨습니다. 다시 입력해주세요\n");
            }
            if(check==1){
                searchPlan_type(p,count);
            }
            else if(check==2){
                searchPlan_month(p,count);
            }
        }
        else if (menu == 6){
            int y,m,ndays,d1;
            while(YES){
                printf("년도: ");
                scanf(" %d",&y);
                if(y<2000) {
                    printf("다시 입력하세요\n");
                    continue;
                }
                else break;
            }
            
            while(YES){
                printf("월: ");
                scanf(" %d",&m);
                if(m>12 || m<1) {
                    printf("다시 입력하세요\n");
                    continue;
                }
                else break;
            }
            ndays = month_days(y,m);
            d1= first_day(y,m);
            showCalendar(ndays,d1);
        }
    }
    return 0;
}