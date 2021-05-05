#include "calendar.h"

int main (){
    Calendar p[100];
    int count = 0; 
    int index = 0; 
    int menu;
    int exit =1;
    int *p_type;

    while(exit){
        menu = selectMenu();
        if(menu == 0) {
            printf("���α׷��� ����˴ϴ�!\n");
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
                printf("������ �����Ͻðڽ��ϱ�?(����:1)");
                scanf(" %d",&ok);
                if(ok == 1){
                    deletePlan(&p[no-1]);
                    count--;
                    free(p_type);
                }
            }
        }
        else if (menu == 5){
            int check = -1;
            while(check == 1 || check == 2){    
                printf("����� ������ �˻��մϴ�\n");
                printf("�з��� �˻�(����/����/����): 1\n��¥�� �˻�: 2\n");
                printf("���Ͻô� �˻������ �Է����ּ���(����: 0)");
                scanf("%d",&check);
                if(check == 0) continue; //0 �Է½� ó������
                if(check!=1 || check!=2) printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
            }
            if(check==1){
                searchPlan_type(p,count);
            }
            else if(check==2){
                searchPlan_month(p,count);
            }
        }
        else if (menu == 6){
            showCalendar();
        }
    }
    return 0;
}