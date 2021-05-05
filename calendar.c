#include "calendar.h"

int selectMenu(){
    int menu;
    printf("\n\n========== �ѵ� A+ ����� ==========\n\n");
    printf("1. ��ü ���� ��ȸ\n");
    printf("2. ���� �߰�\n");
    printf("3. ���� ����\n");
    printf("4. ���� ����\n");
    printf("5. ���� �˻�\n");
    printf("6. �޷� ����\n");
    printf("0. ����\n");
    printf("\n====================================\n\n");
    printf("-> ���Ͻô� �޴��� �Է��ϼ���: ");
    scanf(" %d",&menu);
    return menu;
} // �޴� ���� �Լ� 

void clearbuffer(){
    while (getchar() != '\n');
}

int createPlan(Calendar *p){
    printf("\nex) ��:2021 ��:5 ��:1 �з�:2 �����:OSS \n\n");
    fputs("��: ",stdout);
    clearbuffer();
    scanf("%d",&p->year);
    fputs("��: ",stdout);
    scanf("%d",&p->month);
    fputs("��: ",stdout);
    scanf("%d",&p->day);
    fputs("�з�(1.���� 2.���� 3.����): ",stdout);
    scanf("%d", &p->type);
    fputs("�����: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);
    return 1;
} // ���� �߰� �Լ� 

char* transer(int type){  
    char* p_type = malloc(sizeof(char)*100);
    if(type==1) strcpy(p_type , "����");
    else if(type==2) strcpy(p_type, "����");
    else if(type==3) strcpy(p_type, "����");
    else strcpy(p_type, "��Ÿ");
    return p_type;
} //���ڷ� �� type�� ���ڷ� �ٲٴ� �Լ�

int readPlan(Calendar p){
    char *p_type;
    p_type = transer(p.type);
    printf("%d��\t%d��\t%d��\t%s\t%s\n",p.year,p.month,p.day,p_type,p.subject);
    free(p_type);
    return 1;
}// ���� read �Լ� 

void listPlan(Calendar *p, int count){
    int i = 0;
    printf("\nNo\t��\t��\t��\t�з�\t����\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < count; i++){
        if(p[i].year == -1) continue;
        printf("%d\t",i+1);
        readPlan(p[i]);
    }
} // ��ü ���� ��� �Լ�

int selectDataNo(Calendar *p, int count){
    int num;
    listPlan(p,count);
    printf("\n-> ��ȣ�� �Է��ϼ���(���:0): ");
    scanf(" %d",&num);
    return num;
} // data ���� �Լ� 

int updatePlan(Calendar *p){
    fputs("������ �⵵: ",stdout);
    clearbuffer();
    scanf("%d",&p->year);
    fputs("������ ��: ",stdout);
    scanf("%d",&p->month);
    fputs("������ ��: ",stdout);
    scanf("%d",&p->day);
    fputs("�з�(1.���� 2.���� 3.����): ",stdout);
    scanf("%d", &p->type);
    fputs("�����: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);
    return 1;
} // ���� ���� �Լ� 

int deletePlan(Calendar *s){
    s->year = -1;
    printf("\n-> ���� �Ǿ����ϴ�\n");
    return 1;
}

void searchPlan_type(Calendar p[], int count){
    int scnt = 0;
    int search;
    printf("\n�˻��� �з��� �Է����ּ���(����: 0)\n");
    printf("----------------------------\n");
    printf("1. ����\n2. ����\n3. ����\n");
    printf("----------------------------\n");
    printf("=> ");
    scanf("%d",&search);
    if(search==0) return; //0�Է½� ó������

    printf("\nNo\t��\t��\t��\t�з�\t����\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<count; i++)
    {
        if(p[i].year == -1) continue; 
        if(p[i].type==search){
            printf("%2d  ",i+1);
            readPlan(p[i]);
            scnt++;
        }
    }
    if(scnt==0){
        char *p_type;
        p_type = transer(search);
        printf("-> %s ������ �����ϴ�\n",p_type);
        free(p_type);
    }
    printf("\n");
}

void searchPlan_month(Calendar *p, int count){
    int check = -1;
    while(check == 1 || check == 2){
        printf("��(Month)�� �˻�: 1 \n��(Month) & ��(Day)�� �˻�: 2\n");
        printf("���Ͻô� ��ȣ�� �Է����ּ���(����: 0): ");
        scanf("%d",&check);
        if(check == 0) return;
        if(check!=1 || check!=2) printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
    }
    if(check ==1){
        int scnt = 0;
        int search;
        printf("��(Month)�� ������ �˻��մϴ�\n");
        printf("�˻��� ���Ͻô� ���� �Է����ּ���: ");
        scanf("%d",&search);
    printf("---------------------------------------------\n");
        printf("\nNo\t��\t��\t��\t�з�\t����\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month==search){
              printf("%2d  ",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> �ش� ������ ������ �����ϴ�\n");
        printf("\n");
    }
    else if(check == 2)
    {
        int scnt = 0;
        int s_month;
        int s_day;
        printf("��(Month)�� ��(Day)�� ������ �˻��մϴ�\n");
        printf("�˻��� ���Ͻô� ���� ���� ������� �Է����ּ���\n");
        printf("��: ");
        scanf("%d",&s_month);
        printf("��: ");
        scanf("%d",&s_day);    
        printf("---------------------------------------------\n");
        printf("\nNo\t��\t��\t��\t�з�\t����\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month == s_month && p[i].day == s_day){
                printf("%2d  ",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> �ش� ��¥���� ������ �����ϴ�\n");
        printf("\n");
    }
}

void showCalendar(){
}

