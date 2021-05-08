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
    while(p->month>12||p->month<0){
        fputs("��: ",stdout);
        scanf("%d",&p->month);
        if(p->month>12||p->month<0) printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }
    while(p->day>31||p->day<0){
        fputs("������ ��: ",stdout);
        scanf("%d",&p->day);
        if(p->day>12||p->day<0) printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }
    while(p->type!=1&&p->type!=2&&p->type!=3&&p->type!=4){
        fputs("�з�(1.���� 2.���� 3.���� 4.��Ÿ): ",stdout);
        scanf("%d", &p->type);
        if(p->type!=1&&p->type!=2&&p->type!=3&&p->type!=4) printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }
    if(p->type==4){
        fputs("������ �Է��ϼ���: ",stdout);
        clearbuffer();
        scanf("%[^\n]s", p->text);
    }
    else strcpy(p->text,"-");
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
    else if(type==4) strcpy(p_type, "��Ÿ");
    return p_type;
} //���ڷ� �� type�� ���ڷ� �ٲٴ� �Լ�

int readPlan(Calendar p){
    char *p_type;
    p_type = transer(p.type);
    printf("%d��\t%d��\t%d��\t%s\t%s\t",p.year,p.month,p.day,p_type,p.subject);
    if(!strcmp(p.text,"-")){
        printf("%s\n",p.text);
    }
    else printf("\n");
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
    while(p->month>12||p->month<0){
        fputs("��: ",stdout);
        scanf("%d",&p->month);
        if(p->month>12||p->month<0) printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }
    while(p->day>31||p->day<0){
        fputs("������ ��: ",stdout);
        scanf("%d",&p->day);
        if(p->day>12||p->day<0) printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }
    p->type=0;
    while(p->type!=1&&p->type!=2&&p->type!=3&&p->type!=4){
        fputs("�з�(1.���� 2.���� 3.���� 4.��Ÿ): ",stdout);
        scanf("%d", &p->type);
        if(p->type!=1&&p->type!=2&&p->type!=3&&p->type!=4) printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }
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
    printf("1. ����\n2. ����\n3. ����\n4. ��Ÿ\n");
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
            printf("%d\t",i+1);
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
    while(check != 1 && check != 2){
        printf("\n\n��¥ �˻������ �Է����ּ���(����: 0)");
        printf("\n----------------------------\n");
        printf("1. ��(Month)�� �˻�\n2. ��(Month) & ��(Day)�� �˻�\n");
        printf("----------------------------\n");
        printf("=> ");
        scanf("%d",&check);
        if(check == 0) return;
        if(check!=1 && check!=2) printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
    }
    if(check ==1){
        int scnt = 0;
        int search;
        printf("\n[ ��(Month)�� �����˻� ]\n");
        printf("�˻��� ���Ͻô� ���� �Է����ּ���: ");
        scanf("%d",&search);
        printf("\nNo\t��\t��\t��\t�з�\t����\n");
        printf("---------------------------------------------\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month==search){
                printf("%d\t",i+1);
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
        printf("\n[ ��(Month)�� ��(Day)�� �����˻� ]\n");
        printf("�˻��� ���Ͻô� ���� ���� ������� �Է����ּ���\n");
        printf("��: ");
        scanf("%d",&s_month);
        printf("��: ");
        scanf("%d",&s_day);    
        printf("\nNo\t��\t��\t��\t�з�\t����\n");
        printf("---------------------------------------------\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month == s_month && p[i].day == s_day){
                printf("%d\t",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> �ش� ��¥���� ������ �����ϴ�\n");
        printf("\n");
    }
}

void showCalendar(int ndays, int d1){
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for(int i = 0; i<d1; i++){
        printf("\t"); 
    }
    for(int i = 1; i<=ndays; i++){
        printf(" %d\t",i); // day ���
        if((i+d1)%7 == 0) printf("\n"); //7�� ������ �������� 0 �̸� �ٹٲ�
    }
}// �⵵�� ���� �Է¹޾� �ش� ���� calender�� ����ϴ� �Լ�


int is_leap_year(int y){
    if(((y%4 == 0)&&(y%100 != 0))||(y%400 == 0)) return YES;
    else return NO;
} // ������ �Ǻ��ϱ� ���� help function 

int month_days(int y, int m){
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) 
        return 31;
    else if(m==4||m==6||m==9||m==11) 
        return 30;
    else if(is_leap_year(y) == YES) // �����̸� 29 return
        return 29;
    else
        return 28; 
} // �ش� ���� �� ������ Ȯ���ϱ� ���� help function 

int first_day(int y, int m){
    int total = 1;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int i = 1900; i<y; i++){
        if(is_leap_year(i)){
            total += 366;
        }
        else 
            total += 365;
    }
    for(int j = 0; j<m-1; j++){
        total = total + month[j]; 
    }
    if(is_leap_year(y) && m>=3) total++; 
    return total%7;
} // �޷��� ���� ������ Ȯ���ϴ� �Լ� 