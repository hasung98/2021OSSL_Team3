#include "calendar.h"

int check_char(char *buff) // ���ڰ� ����ִ��� check �Լ�
{
    int N=strlen(buff);
    int i ;
    for(i =0;i<N;i++){
        if(!isdigit(buff[i]))   return 1;
    }
    return 0; 
}

void clearbuffer(){
    while (getchar() != '\n');
}

char* transer(int type){  //����"type"�� ����"type"���� ��ȯ �Լ�
    char* p_type = malloc(sizeof(char)*100);
    if(type==1) strcpy(p_type , "����");
    else if(type==2) strcpy(p_type, "����");
    else if(type==3) strcpy(p_type, "����");
    else if(type==4) strcpy(p_type, "��Ÿ");
    return p_type;
} 

int selectDataNo(Planner *p, int count){ // ���� ���� �Լ�
    int num;
    char buff[100];
    totalPlan(p,count);
    while(1){
        fputs("\n-> ��ȣ�� �Է��ϼ���(����: 0): ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue; 
        }
        break;
    }
    num=atoi(buff);
    return num;
} 

int selectMenu(){ // �޴� ����
    printf("\n\n========== �ѵ� A+ ����� ==========\n\n");
    printf("1. ��ü ���� ��ȸ\n");
    printf("2. ���� �߰�\n");
    printf("3. ���� ����\n");
    printf("4. ���� ����\n");
    printf("5. ���� �˻�\n");
    printf("6. �޷� ����\n");
    printf("7. ���� ����\n");
    printf("0. ����\n");
    printf("\n====================================\n\n");

    char buff[100];
    int menu = -1;
    int check = -1;
    while(menu<0||menu>7||check!=1){ 
        fputs("-> ���Ͻô� �޴��� �Է��ϼ���: ",stdout);
        //clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        menu=atoi(buff);
        check=1;
        if(menu<0||menu>7){
            printf("-> 0~7�� ���ڸ� �Է����ּ���\n\n");
        }
    }
    return menu;
} 

int finish(){ // ���α׷� ���� �Լ�
    printf("\n���α׷��� ����˴ϴ�. �̿����ּż� �����մϴ�:)\n\n");
    return 0;
}

int createPlan(Planner *p){ //���� �߰� �Լ�
    char buff[100];
    int check = -1; //���ڷθ� �����Ǿ����� Ȯ��
    printf("\nex) ��:2021 ��:5 ��:1 �����:OSS �з�:2\n\n");

    while(check!=1){
        fputs("��: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue; //check_char�� 1�̸� �ٽ� �Է�
        }
        p->year=atoi(buff);
        check=1;
    }

    p->month= -1;
    check = -1;
    while(p->month>12||p->month<=0||check!=1){
        fputs("��: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        p->month=atoi(buff);
        check=1;
        if(p->month>12||p->month<=0) printf("-> 1~12�� ���ڸ� �Է����ּ���\n\n");  //1~12 �̿��� ���� �Է½� �ٽ� �Է�
    }

    p->day = -1;
    check = -1;
    while(p->day>31||p->day<=0||check!=1){
        fputs("��: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        p->day=atoi(buff);
        check=1;
        if(p->day>31||p->day<=0) printf("-> 1~31�� ���ڸ� �Է����ּ���\n\n");
    }

    fputs("�����: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);

    p->type = -1;
    check = -1;
    while(p->type<1||p->type>4||check!=1){
        fputs("�з�(1.���� 2.���� 3.���� 4.��Ÿ): ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        p->type=atoi(buff);
        check=1;
        if(p->type<1||p->type>4) printf("-> 1~4�� ���ڸ� �Է����ּ���\n\n");
    }

    int choice = -1;
    check=-1;
    while((choice!=1&&choice!=2)||check!=1)
    {
        printf("��� �Է��Ͻðڽ��ϱ�?(1.�� 2.�ƴϿ�): ");
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        choice=atoi(buff);
        check=1;
        if(choice!=1&&choice!=2) printf("-> 1�Ǵ� 2�� �Է����ּ���\n\n");
    }
    if(choice ==1){  //��� �Է�(1.��) ���ý� ��� �Է¹���
        fputs("���: ",stdout);
        clearbuffer();
        scanf("%[^\n]s", p->text);
    }
    else strcpy(p->text,"-");

    return 1;
}  

int updatePlan(Planner *p){ // ���� ����
    char buff[100];
    int check=-1; //���ڷθ� �����Ǿ����� Ȯ��

    while(check!=1){
        printf("\n[����]\n");
        fputs("�⵵: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue; //check_char�� 1�̸� �ٽ� �Է�
        }
        p->year=atoi(buff);
        check=1;
    }

    p->month= -1;
    check = -1;
    while(p->month>12||p->month<=0||check!=1){
        fputs("��: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        p->month=atoi(buff);
        check=1;
        if(p->month>12||p->month<=0) printf("-> 1~12�� ���ڸ� �Է����ּ���\n\n");  //1~12 �̿��� ���� �Է½� �ٽ� �Է�
    }

    p->day = -1;
    check = -1;
    while(p->day>31||p->day<=0||check!=1){
        fputs("��: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        p->day=atoi(buff);
        check=1;
        if(p->day>31||p->day<=0) printf("-> 1~31�� ���ڸ� �Է����ּ���\n\n");
    }

    fputs("�����: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);

    p->type = -1;
    check = -1;
    while(p->type<1||p->type>4||check!=1){
        fputs("�з�(1.���� 2.���� 3.���� 4.��Ÿ): ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        p->type=atoi(buff);
        check=1;
        if(p->type<1||p->type>4) printf("-> 1~4�� ���ڸ� �Է����ּ���\n\n");
    }

    int choice = -1;
    check=-1;
    while((choice!=1&&choice!=2)||check!=1)
    {
        printf("��� �Է��Ͻðڽ��ϱ�?(1.�� 2.�ƴϿ�): ");
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        choice=atoi(buff);
        check=1;
        if(choice!=1&&choice!=2) printf("-> 1�Ǵ� 2�� �Է����ּ���\n\n");
    }
    if(choice ==1){  //��� �Է�(1.��) ���ý� ��� �Է¹���
        fputs("���: ",stdout);
        clearbuffer();
        scanf("%[^\n]s", p->text);
    }
    else strcpy(p->text,"-");

    return 1;
} 

int deletePlan(Planner *s){ // ���� ���� �Լ�
    int ok=-1;
    char buff[100];
    while(ok!=0&&ok!=1){
        fputs("\n** ������ �����Ͻðڽ��ϱ�?(��:1 �ƴϿ�:0) ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        ok=atoi(buff);
        if(ok!=1&&ok!=0) printf("0�Ǵ� 1�� �Է����ּ���\n\n");
    }
    if(ok == 1){
        s->year = -1;
        printf("\n-> ���� �Ǿ����ϴ�\n");
        return 1;
    }
    else return 0;
}

int printPlan(Planner p){ // ���� ��� �Լ�
    char *p_type;
    p_type = transer(p.type);
    printf("%d��\t%d��\t%d��\t%s\t%s\t%s\n",p.year,p.month,p.day,p_type,p.subject,p.text);
    free(p_type);
    return 1;
} 

void totalPlan(Planner *p, int count){ // ��ü���� ��� �Լ�
    int i = 0;
    printf("\nNo\t��\t��\t��\t�з�\t����\t���\n");
    printf("-------------------------------------------------------\n");
    for(i = 0; i < count; i++){
        if(p[i].year == -1) continue;
        printf("%d\t",i+1);
        printPlan(p[i]);
    }
} 


void search_Plan(Planner p[], int count){ // �˻���� ���� �Լ�
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

void searchPlan_type(Planner p[], int count){ // �з��� �����˻�
    char buff[100];
    int scnt = 0;
    int search=-1;
    printf("\n�˻��� �з��� �Է����ּ���(����: 0)\n----------------------------\n");
    printf("1. ����\n2. ����\n3. ����\n4. ��Ÿ\n----------------------------\n");
    while(search<0||search>4){   
        fputs("=> ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        search=atoi(buff);
        if((search<0||search>4)) printf("-> 1~4�� ���ڸ� �Է����ּ���\n\n");
    }
    if(search==0) return; //0�Է½� ó������
    char *p_type = transer(search);

    printf("\n> %s ������ �˻��մϴ�\n",p_type);
    printf("\nNo\t��\t��\t��\t�з�\t����\t���\n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i<count; i++)
    {
        if(p[i].year == -1) continue; 
        if(p[i].type==search){
            printf("%d\t",i+1);
            printPlan(p[i]);
            scnt++;
        }
    }
    if(scnt==0){
        printf("-> %s ������ �����ϴ�\n",p_type);
        free(p_type);
    }
    printf("\n");
}

void searchPlan_month(Planner *p, int count){
    char buff[100];
    int choice = -1;
    while(choice != 1 && choice != 2){
        printf("\n��¥ �˻������ �Է����ּ���(����: 0)\n----------------------------\n");
        printf("1. ��(Month)�� �˻�\n2. ��(Month) & ��(Day)�� �˻�\n----------------------------\n");
        fputs("=> ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> ���ڸ� �Է����ּ���\n\n");
            continue;
        }
        choice=atoi(buff);
        if(choice == 0) return;
        if(choice!=1 && choice!=2) printf("-> 1�Ǵ� 2�� �Է����ּ���\n\n");
    }
    if(choice ==1){
        printf("\n[ ��(Month)�� �����˻� ]\n");
        int scnt = 0;
        int s_month = 0;
        while(s_month<=0||s_month>12){
            fputs("\n�˻��� ���Ͻô� ���� �Է����ּ���: ",stdout);
            clearbuffer();
            scanf("%s", buff);
            if(check_char(buff)){
                printf("-> ���ڸ� �Է����ּ���\n\n");
                continue;
            }
            s_month=atoi(buff);
            if(s_month<=0||s_month>12) printf("-> 1~12�� ���ڸ� �Է����ּ���\n\n");
        }
        printf("\n> %d�� ������ �˻��մϴ�\n",s_month);
        printf("\nNo\t��\t��\t��\t�з�\t����\t���\n-------------------------------------------------------\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month==s_month){
                printf("%d\t",i+1);
                printPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> �ش� ������ ������ �����ϴ�\n");
        printf("\n");
    }
    else if(choice == 2)
    {
        printf("\n[ ��(Month)�� ��(Day)�� �����˻� ]\n");
        int scnt = 0;
        int s_month=-1;
        int s_day=-1;
        while(s_month<=0||s_month>12||s_day<=0||s_day>31){ 
            printf("\n�˻��� ���Ͻô� ���� ���� ������� �Է����ּ���\n");
            fputs("��: ",stdout);
            clearbuffer();
            scanf("%s", buff);
            if(check_char(buff)){
                printf("-> ���ڸ� �Է����ּ���\n\n");
                continue;
            }
            s_month=atoi(buff);
            if(s_month<=0||s_month>12) 
            {
                printf("-> 1~12�� ���ڸ� �Է����ּ���\n\n");
                continue;
            }

            fputs("��: ",stdout);
            clearbuffer();
            scanf("%s", buff);
            if(check_char(buff)){
                printf("-> ���ڸ� �Է����ּ���\n\n");
                continue;
            }
            s_day=atoi(buff); 
            if(s_day<=0||s_day>31) printf("-> 1~31�� ���ڸ� �Է����ּ���\n\n");  
        }
        
        printf("\n> %d�� %d�� ������ �˻��մϴ�.\n",s_month,s_day);
        printf("\nNo\t��\t��\t��\t�з�\t����\t���\n");
        printf("-------------------------------------------------------\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month == s_month && p[i].day == s_day){
                printf("%d\t",i+1);
                printPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> �ش� ��¥���� ������ �����ϴ�\n");
        printf("\n");
    }
}

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

void showCalendar(int month, int ndays, int d1){
    printf("\n\n\t\t   [ 2021�� %d�� ]\n",month);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for(int i = 0; i<d1; i++){
        printf("\t"); 
    }
    for(int i = 1; i<=ndays; i++){
        printf(" %d\t",i); // day ���
        if((i+d1)%7 == 0) printf("\n"); //7�� ������ �������� 0 �̸� �ٹٲ�
    }
}// ���� �Է¹޾� �ش� ���� calender�� ����ϴ� �Լ�

void Calendar(int year){
    char buff[100];
    int month=-2;
    int ndays,d1;

     while(month>12 || month<1){
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
    }
    ndays = month_days(year,month);
    d1= first_day(2021,month);
    showCalendar(month, ndays,d1);
}


int loadData(Planner *s){
    int i = 0;
    FILE *fp;
    fp = fopen("calendar.txt", "rt");
    if(fp ==NULL) printf("\n-> ����� ������ �����ϴ�\n");
    else{
        for(; i < 100; i++){
            fscanf(fp, "%d", &s[i].year); 
            if(feof(fp)) break;
            fscanf(fp, "\t%d\t%d\t%d\t%[^\n]s\t%[^\n]s\n", &s[i].month, &s[i].day, &s[i].type, s[i].subject, s[i].text); 
        }
        fclose(fp);
        printf("\n-> ����� ������ �ε��߽��ϴ�\n");
        return i;
    }
    return 0;
}

void saveData(Planner *s, int index){
    FILE *fp;
    fp = fopen("calendar.txt","wt");
    for(int i = 0; i < index; i++){ 
        if(s[i].year == -1) continue;
        fprintf(fp, "%d\t%d\t%d\t%d\t%s\t%s\n",s[i].year, s[i].month, s[i].day, s[i].type, s[i].subject,s[i].text);
        }
    fclose(fp); printf("\n-> ������ ����Ǿ����ϴ�\n");
    }  

