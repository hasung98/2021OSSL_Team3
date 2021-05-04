#include "calendar.h"

int selectMenu(){
    int menu;
    printf("\n******* 한동 A+ 도우미 *******\n");
    printf("1. 전체 일정 조회\n");
    printf("2. 일정 추가\n");
    printf("3. 일정 수정\n");
    printf("4. 일정 삭제\n");
    printf("5. 일정 검색\n");
    printf("5. 달력 보기\n");
    printf("0. 종료\n");
    printf("********************************\n");
    printf("==> 원하는 메뉴는 무엇입니까? ");
    scanf(" %d",&menu);
    return menu;
} // 메뉴 선택 함수 

void clearbuffer(){
    while (getchar() != '\n');
}

int create_plan(Calendar *p){
    printf("ex) 년:2021 월:5 일:1 분류:2 과목명:OSS \n");
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

int readPlan(Calendar p){
    char p_type[100] = "\0";
    if(p.type==1) strcpy(p_type , "시험");
    else if(p.type==2) strcpy(p_type, "과제");
    else if(p.type==3) strcpy(p_type, "팀플");
    else strcpy(p_type, "분류없음");

    printf(" %d년\t%d월\t%d일\t\t%s\t(%s)\n",p.year,p.month,p.day,p_type,p.subject);
    return 1;
}// 일정 read 함수 

void listPlan(Calendar *p, int count){
    int i = 0;
    printf("\nNo\t\t년\t월\t일\t\t분류\t과목\n");
    for(i = 0; i < count; i++){
        if(p[i].year == -1) continue;
        printf("%d \t",i+1);
        readPlan(p[i]);
    }
} // 전체 일정 출력 함수

int selectDataNo(Calendar *p, int count){
    int num;
    listPlan(p,count);
    printf("선택할 번호는 무엇입니까?(취소:0) ");
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
    s->month = -1;
    s->day = -1;
    s->type = -1;
    printf(" ==> 삭제 되었습니다! ");
    return 1;
}

void searchPlan_type(Calendar s[], int count){
    int scnt = 0;
    int search = 0;
    printf("검색할 분류를 입력하세요(1.시험 2.과제 3.팀플): ");
    scanf("%d",&search);
    printf("**********************************************\n");
    printf("\nNo\t\t년\t월\t일\t\t분류\t과목\n");
    for(int i=0; i<count; i++)
    {
        if(s[i].year == -1) continue;
        if(s[i].type==search){
            printf("%2d  ",i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    if(scnt==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchPlan_month(Calendar *s, int count){
}

void showCalendar(){
}

