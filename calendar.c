#include "calendar.h"

int selectMenu(){
    int menu;
    printf("\n\n========== 한동 A+ 도우미 ==========\n\n");
    printf("1. 전체 일정 조회\n");
    printf("2. 일정 추가\n");
    printf("3. 일정 수정\n");
    printf("4. 일정 삭제\n");
    printf("5. 일정 검색\n");
    printf("6. 달력 보기\n");
    printf("0. 종료\n");
    printf("\n====================================\n\n");
    printf("-> 원하시는 메뉴를 입력하세요: ");
    scanf(" %d",&menu);
    return menu;
} // 메뉴 선택 함수 

void clearbuffer(){
    while (getchar() != '\n');
}

int createPlan(Calendar *p){
    printf("\nex) 년:2021 월:5 일:1 분류:2 과목명:OSS \n\n");
    fputs("년: ",stdout);
    clearbuffer();
    scanf("%d",&p->year);
    fputs("월: ",stdout);
    scanf("%d",&p->month);
    fputs("일: ",stdout);
    scanf("%d",&p->day);
    fputs("분류(1.시험 2.과제 3.팀플): ",stdout);
    scanf("%d", &p->type);
    fputs("과목명: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);
    return 1;
} // 일정 추가 함수 

char* transer(int type){  
    char* p_type = malloc(sizeof(char)*100);
    if(type==1) strcpy(p_type , "시험");
    else if(type==2) strcpy(p_type, "과제");
    else if(type==3) strcpy(p_type, "팀플");
    else strcpy(p_type, "기타");
    return p_type;
} //숫자로 된 type을 문자로 바꾸는 함수

int readPlan(Calendar p){
    char *p_type;
    p_type = transer(p.type);
    printf("%d년\t%d월\t%d일\t%s\t%s\n",p.year,p.month,p.day,p_type,p.subject);
    free(p_type);
    return 1;
}// 일정 read 함수 

void listPlan(Calendar *p, int count){
    int i = 0;
    printf("\nNo\t년\t월\t일\t분류\t과목\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < count; i++){
        if(p[i].year == -1) continue;
        printf("%d\t",i+1);
        readPlan(p[i]);
    }
} // 전체 일정 출력 함수

int selectDataNo(Calendar *p, int count){
    int num;
    listPlan(p,count);
    printf("\n-> 번호를 입력하세요(취소:0): ");
    scanf(" %d",&num);
    return num;
} // data 선택 함수 

int updatePlan(Calendar *p){
    fputs("수정된 년도: ",stdout);
    clearbuffer();
    scanf("%d",&p->year);
    fputs("수정된 월: ",stdout);
    scanf("%d",&p->month);
    fputs("수정된 일: ",stdout);
    scanf("%d",&p->day);
    fputs("분류(1.시험 2.과제 3.팀플): ",stdout);
    scanf("%d", &p->type);
    fputs("과목명: ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);
    return 1;
} // 일정 수정 함수 

int deletePlan(Calendar *s){
    s->year = -1;
    printf("\n-> 삭제 되었습니다\n");
    return 1;
}

void searchPlan_type(Calendar p[], int count){
    int scnt = 0;
    int search;
    printf("\n검색할 분류를 입력해주세요(종료: 0)\n");
    printf("----------------------------\n");
    printf("1. 시험\n2. 과제\n3. 팀플\n");
    printf("----------------------------\n");
    printf("=> ");
    scanf("%d",&search);
    if(search==0) return; //0입력시 처음으로

    printf("\nNo\t년\t월\t일\t분류\t과목\n");
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
        printf("-> %s 일정이 없습니다\n",p_type);
        free(p_type);
    }
    printf("\n");
}

void searchPlan_month(Calendar *p, int count){
    int check = -1;
    while(check == 1 || check == 2){
        printf("월(Month)로 검색: 1 \n월(Month) & 일(Day)로 검색: 2\n");
        printf("원하시는 번호를 입력해주세요(종료: 0): ");
        scanf("%d",&check);
        if(check == 0) return;
        if(check!=1 || check!=2) printf("잘못 입력하셨습니다. 다시 입력해주세요\n");
    }
    if(check ==1){
        int scnt = 0;
        int search;
        printf("월(Month)로 일정을 검색합니다\n");
        printf("검색을 원하시는 월을 입력해주세요: ");
        scanf("%d",&search);
    printf("---------------------------------------------\n");
        printf("\nNo\t년\t월\t일\t분류\t과목\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month==search){
              printf("%2d  ",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> 해당 월에는 일정이 없습니다\n");
        printf("\n");
    }
    else if(check == 2)
    {
        int scnt = 0;
        int s_month;
        int s_day;
        printf("월(Month)과 일(Day)로 일정을 검색합니다\n");
        printf("검색을 원하시는 월과 일을 순서대로 입력해주세요\n");
        printf("월: ");
        scanf("%d",&s_month);
        printf("일: ");
        scanf("%d",&s_day);    
        printf("---------------------------------------------\n");
        printf("\nNo\t년\t월\t일\t분류\t과목\n");
        for(int i=0; i<count; i++)
        {
            if(p[i].year == -1) continue;
            if(p[i].month == s_month && p[i].day == s_day){
                printf("%2d  ",i+1);
                readPlan(p[i]);
                scnt++;
            }
        }
        if(scnt==0) printf("\n-> 해당 날짜에는 일정이 없습니다\n");
        printf("\n");
    }
}

void showCalendar(){
}

