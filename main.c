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
            printf("\n프로그램이 종료됩니다. 이용해주셔서 감사합니다:)\n\n");
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
            char buff[100];
            int choice = -1;
            while(choice != 1 && choice != 2){    
                printf("\n[ 일정 검색 ]\n");
                printf("\n검색방법을 입력해주세요(종료: 0)");
                printf("\n----------------------------\n");
                printf("1. 분류로 검색(시험/과제/팀플/기타)\n2. 날짜로 검색\n");
                printf("----------------------------\n");
                fputs("=> ",stdout);
                clearbuffer();
                scanf("%s", buff);
                if(check_char(buff)){
                    printf("\n-> 숫자를 입력해주세요\n\n");
                    continue;
                }
                choice=atoi(buff);
                if(choice == 0) break; //0 입력시 처음으로
                if(choice!=1 && choice!=2) printf("-> 1또는 2를 입력해주세요\n\n");
            }
            if(choice==1){
                searchPlan_type(p,count);
            }
            else if(choice==2){
                searchPlan_month(p,count);
            }
        }
        else if (menu == 6){
            int month,ndays,d1;

            while(YES){
                printf("\n[ 달력보기 ]\n");
                fputs("월: ",stdout);
                clearbuffer();
                scanf("%s", buff);
                if(check_char(buff)){
                    printf("-> 숫자를 입력해주세요\n\n");
                    continue;
                }
                month=atoi(buff);
                if(month>12 || month<1) {
                    printf("-> 1~12의 숫자를 입력해주세요\n\n");
                    continue;
                }
                else break;
            }
            ndays = month_days(2021,month);
            d1= first_day(2021,month);
            printf("\n\n\t\t   [ 2021년 %d월 ]\n",month);
            showCalendar(ndays,d1);
        }
        else if (menu == 7){
            saveData(p,index); 
        }
    }
    return 0;
}