#include "calendar.h"

int selectMenu(){
    char buff[100];
    int menu;
    printf("\n\n========== 한동 A+ 도우미 ==========\n\n");
    printf("1. 전체 일정 조회\n");
    printf("2. 일정 추가\n");
    printf("3. 일정 수정\n");
    printf("4. 일정 삭제\n");
    printf("5. 일정 검색\n");
    printf("6. 달력 보기\n");
    printf("7. 일정 저장\n");
    printf("0. 종료\n");
    printf("\n====================================\n\n");

    int check = -1;
    while(menu<0||menu>7||check!=1){
        fputs("-> 원하시는 메뉴를 입력하세요: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("\n-> 숫자를 입력해주세요\n\n");
            continue;
        }
        menu=atoi(buff);
        if(menu<0||menu>7){
            printf("-> 0~7의 숫자를 입력해주세요\n\n");
        }
    }
    return menu;
} // 메뉴 선택 함수 

void clearbuffer(){
    while (getchar() != '\n');
}

int createPlan(Calendar *p){
    char buff[100];
    int check=-1; //숫자로만 구성되었는지 확인
    printf("\nex) 년:2021 월:5 일:1 과목명:OSS 분류:2\n\n");

    while(check!=1){
        fputs("년: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue; //check_char가 1이면 다시 입력
        }
        p->year=atoi(buff);
        check=1;
    }

    p->month= -1;
    check = -1;
    while(p->month>12||p->month<=0||check!=1){
        fputs("월: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        p->month=atoi(buff);
        check=1;
        if(p->month>12||p->month<=0) printf("-> 1~12의 숫자를 입력해주세요\n\n");  //1~12 이외의 숫자 입력시 다시 입력
    }

    p->day = -1;
    check = -1;
    while(p->day>31||p->day<=0||check!=1){
        fputs("일: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        p->day=atoi(buff);
        check=1;
        if(p->day>31||p->day<=0) printf("-> 1~31의 숫자를 입력해주세요\n\n");
    }

    fputs("과목명: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);

    p->type = -1;
    check = -1;
    while(p->type<1||p->type>4||check!=1){
        fputs("분류(1.시험 2.과제 3.팀플 4.기타): ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        p->type=atoi(buff);
        check=1;
        if(p->type<1||p->type>4) printf("-> 1~4의 숫자를 입력해주세요\n\n");
    }

    int choice = -1;
    check=-1;
    while((choice!=1&&choice!=2)||check!=1)
    {
        printf("비고를 입력하시겠습니까?(1.예 2.아니오): ");
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        choice=atoi(buff);
        check=1;
        if(choice!=1&&choice!=2) printf("-> 1또는 2를 입력해주세요\n\n");
    }
    if(choice ==1){  //비고 입력(1.예) 선택시 비고 입력받음
        fputs("비고: ",stdout);
        clearbuffer();
        scanf("%[^\n]s", p->text);
    }
    else strcpy(p->text,"-");

    return 1;
} // 일정 추가 함수 

int check_char(char *buff)
{
    int N=strlen(buff);
    int i ;
    for(i =0;i<N;i++){
        if(!isdigit(buff[i]))   return 1;
    }
    return 0;       //문자가 들어있으면 1, 숫자로만 구성되어있으면 0 return
}

char* transer(int type){  
    char* p_type = malloc(sizeof(char)*100);
    if(type==1) strcpy(p_type , "시험");
    else if(type==2) strcpy(p_type, "과제");
    else if(type==3) strcpy(p_type, "팀플");
    else if(type==4) strcpy(p_type, "기타");
    return p_type;
} //숫자로 된 type을 문자로 바꾸는 함수

int readPlan(Calendar p){
    char *p_type;
    p_type = transer(p.type);
    printf("%d년\t%d월\t%d일\t%s\t%s\t%s\n",p.year,p.month,p.day,p_type,p.subject,p.text);
    free(p_type);
    return 1;
}// 일정 read 함수 

void listPlan(Calendar *p, int count){
    int i = 0;
    printf("\nNo\t년\t월\t일\t분류\t과목\t비고\n");
    printf("-------------------------------------------------------\n");
    for(i = 0; i < count; i++){
        if(p[i].year == -1) continue;
        printf("%d\t",i+1);
        readPlan(p[i]);
    }
} // 전체 일정 출력 함수

int selectDataNo(Calendar *p, int count){
    int num;
    listPlan(p,count);
    printf("\n-> 번호를 입력하세요(종료: 0): ");
    scanf(" %d",&num);
    return num;
} // data 선택 함수 

int updatePlan(Calendar *p){
    char buff[100];
    int check=-1; //숫자로만 구성되었는지 확인

    while(check!=1){
        printf("\n[수정]\n");
        fputs("년도: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue; //check_char가 1이면 다시 입력
        }
        p->year=atoi(buff);
        check=1;
    }

    p->month= -1;
    check = -1;
    while(p->month>12||p->month<=0||check!=1){
        fputs("월: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        p->month=atoi(buff);
        check=1;
        if(p->month>12||p->month<=0) printf("-> 1~12의 숫자를 입력해주세요\n\n");  //1~12 이외의 숫자 입력시 다시 입력
    }

    p->day = -1;
    check = -1;
    while(p->day>31||p->day<=0||check!=1){
        fputs("일: ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        p->day=atoi(buff);
        check=1;
        if(p->day>31||p->day<=0) printf("-> 1~31의 숫자를 입력해주세요\n\n");
    }

    fputs("과목명: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);

    p->type = -1;
    check = -1;
    while(p->type<1||p->type>4||check!=1){
        fputs("분류(1.시험 2.과제 3.팀플 4.기타): ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        p->type=atoi(buff);
        check=1;
        if(p->type<1||p->type>4) printf("-> 1~4의 숫자를 입력해주세요\n\n");
    }

    int choice = -1;
    check=-1;
    while((choice!=1&&choice!=2)||check!=1)
    {
        printf("비고를 입력하시겠습니까?(1.예 2.아니오): ");
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        choice=atoi(buff);
        check=1;
        if(choice!=1&&choice!=2) printf("-> 1또는 2를 입력해주세요\n\n");
    }
    if(choice ==1){  //비고 입력(1.예) 선택시 비고 입력받음
        fputs("[수정] 비고: ",stdout);
        clearbuffer();
        scanf("%[^\n]s", p->text);
    }
    else strcpy(p->text,"-");

    return 1;
} // 일정 수정 함수 

int deletePlan(Calendar *s){
    s->year = -1;
    printf("\n-> 삭제 되었습니다\n");
    return 1;
}

void searchPlan_type(Calendar p[], int count){
    char buff[100];
    int scnt = 0;
    int search=-1;
    printf("\n검색할 분류를 입력해주세요(종료: 0)\n");
    printf("----------------------------\n");
    printf("1. 시험\n2. 과제\n3. 팀플\n4. 기타\n");
    printf("----------------------------\n");
    while(search<0||search>4){   
        fputs("=> ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        search=atoi(buff);
        if((search<0||search>4)) printf("-> 1~4의 숫자를 입력해주세요\n\n");
    }
    if(search==0) return; //0입력시 처음으로
    char *p_type = transer(search);

    printf("\n> %s 일정을 검색합니다\n",p_type);
    printf("\nNo\t년\t월\t일\t분류\t과목\t비고\n");
    printf("-------------------------------------------------------\n");
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
        printf("-> %s 일정이 없습니다\n",p_type);
        free(p_type);
    }
    printf("\n");
}

void searchPlan_month(Calendar *p, int count){
    char buff[100];
    int choice = -1;
    while(choice != 1 && choice != 2){
        printf("\n날짜 검색방법을 입력해주세요(종료: 0)");
        printf("\n----------------------------\n");
        printf("1. 월(Month)로 검색\n2. 월(Month) & 일(Day)로 검색\n");
        printf("----------------------------\n");
        fputs("=> ",stdout);
        clearbuffer();
        scanf("%s", buff);
        if(check_char(buff)){
            printf("-> 숫자를 입력해주세요\n\n");
            continue;
        }
        choice=atoi(buff);
        if(choice == 0) return;
        if(choice!=1 && choice!=2) printf("-> 1또는 2를 입력해주세요\n\n");
    }
    if(choice ==1){
        printf("\n[ 월(Month)로 일정검색 ]\n");
        int scnt = 0;
        int s_month = 0;
        while(s_month<=0||s_month>12){
            fputs("\n검색을 원하시는 월을 입력해주세요: ",stdout);
            clearbuffer();
            scanf("%s", buff);
            if(check_char(buff)){
                printf("-> 숫자를 입력해주세요\n\n");
                continue;
            }
            s_month=atoi(buff);
            if(s_month<=0||s_month>12) printf("-> 1~12의 숫자를 입력해주세요\n\n");
        }
        printf("\n> %d월 일정을 검색합니다\n",s_month);
    
        printf("\nNo\t년\t월\t일\t분류\t과목\t비고\n");
        printf("-------------------------------------------------------\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month==s_month){
                printf("%d\t",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> 해당 월에는 일정이 없습니다\n");
        printf("\n");
    }
    else if(choice == 2)
    {
        printf("\n[ 월(Month)과 일(Day)로 일정검색 ]\n");
        int scnt = 0;
        int s_month=-1;
        int s_day=-1;
        while(s_month<=0||s_month>12||s_day<=0||s_day>31){ 
            printf("\n검색을 원하시는 월과 일을 순서대로 입력해주세요\n");
            fputs("월: ",stdout);
            clearbuffer();
            scanf("%s", buff);
            if(check_char(buff)){
                printf("-> 숫자를 입력해주세요\n\n");
                continue;
            }
            s_month=atoi(buff);
            if(s_month<=0||s_month>12) 
            {
                printf("-> 1~12의 숫자를 입력해주세요\n\n");
                continue;
            }

            fputs("일: ",stdout);
            clearbuffer();
            scanf("%s", buff);
            if(check_char(buff)){
                printf("-> 숫자를 입력해주세요\n\n");
                continue;
            }
            s_day=atoi(buff); 
            if(s_day<=0||s_day>31) printf("-> 1~31의 숫자를 입력해주세요\n\n");  
        }
        
        printf("\n> %d월 %d일 일정을 검색합니다.\n",s_month,s_day);
        printf("\nNo\t년\t월\t일\t분류\t과목\t비고\n");
        printf("-------------------------------------------------------\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month == s_month && p[i].day == s_day){
                printf("%d\t",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> 해당 날짜에는 일정이 없습니다\n");
        printf("\n");
    }
}

void showCalendar(int ndays, int d1){
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for(int i = 0; i<d1; i++){
        printf("\t"); 
    }
    for(int i = 1; i<=ndays; i++){
        printf(" %d\t",i); // day 출력
        if((i+d1)%7 == 0) printf("\n"); //7로 나눠서 나머지가 0 이면 줄바꿈
    }
}// 년도와 월을 입력받아 해당 월의 calender를 출력하는 함수


int is_leap_year(int y){
    if(((y%4 == 0)&&(y%100 != 0))||(y%400 == 0)) return YES;
    else return NO;
} // 윤년을 판별하기 위한 help function 

int month_days(int y, int m){
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) 
        return 31;
    else if(m==4||m==6||m==9||m==11) 
        return 30;
    else if(is_leap_year(y) == YES) // 윤년이면 29 return
        return 29;
    else
        return 28; 
} // 해당 월이 몇 일인지 확인하기 위한 help function 

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
} // 달력의 시작 요일을 확인하는 함수 

void saveData(Calendar *s, int index){
    FILE *fp;
    fp = fopen("calendar.txt","wt");
    for(int i = 0; i < index; i++){ 
        if(s[i].year == -1) continue;
        fprintf(fp, "%d %d %d %d %s %s\n",s[i].year, s[i].month, s[i].day, s[i].type, s[i].text, s[i].subject);
        }
    fclose(fp); printf("\n-> 일정이 저장되었습니다\n");
    }  


int loadData(Calendar *s){
    int i = 0;
    FILE *fp;
    fp = fopen("calendar.txt", "rt");
    if(fp ==NULL) printf("\n-> 저장된 일정이 없습니다\n");
    else{
        for(; i < 100; i++){
            fscanf(fp, "%d", &s[i].year); 
            if(feof(fp)) break;
            fscanf(fp, "%d", &s[i].month); 
            fscanf(fp, "%d", &s[i].day); 
            fscanf(fp, "%d", &s[i].type); 
            fscanf(fp, "%s", s[i].text);
            fscanf(fp, "%[^\n]s", s[i].subject);
        }
        fclose(fp);
        printf("\n-> 저장된 일정을 로딩했습니다\n");
        return i;
    }
    return 0;
}
