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
            printf("\n���α׷��� ����˴ϴ�. �̿����ּż� �����մϴ�:)\n\n");
            exit = 0; //���α׷� ����
        }
        if(menu ==1||menu==3||menu==4||menu ==5)
        {
            if(count == 0) 
            {
                printf("����� ������ �����ϴ�\n");
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
                printf("\n** ������ �����Ͻðڽ��ϱ�?(����: 1) ");
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
                printf("\n[ ���� �˻� ]\n");
                printf("\n�˻������ �Է����ּ���(����: 0)");
                printf("\n----------------------------\n");
                printf("1. �з��� �˻�(����/����/����/��Ÿ)\n2. ��¥�� �˻�\n");
                printf("----------------------------\n");
                fputs("=> ",stdout);
                clearbuffer();
                scanf("%s", buff);
                if(check_char(buff)){
                    printf("\n-> ���ڸ� �Է����ּ���\n\n");
                    continue;
                }
                choice=atoi(buff);
                if(choice == 0) break; //0 �Է½� ó������
                if(choice!=1 && choice!=2) printf("-> 1�Ǵ� 2�� �Է����ּ���\n\n");
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
                printf("\n[ �޷º��� ]\n");
                fputs("��: ",stdout);
                clearbuffer();
                scanf("%s", buff);
                if(check_char(buff)){
                    printf("-> ���ڸ� �Է����ּ���\n\n");
                    continue;
                }
                month=atoi(buff);
                if(month>12 || month<1) {
                    printf("-> 1~12�� ���ڸ� �Է����ּ���\n\n");
                    continue;
                }
                else break;
            }
            ndays = month_days(2021,month);
            d1= first_day(2021,month);
            printf("\n\n\t\t   [ 2021�� %d�� ]\n",month);
            showCalendar(ndays,d1);
        }
        else if (menu == 7){
            saveData(p,index); 
        }
    }
    return 0;
}