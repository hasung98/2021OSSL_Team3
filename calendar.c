#include <string.h>
#include <stdio.h>

typedef struct{
  int year; //년
  int month;//월
  int day;//일
  char type[100]; // 과제 or 시험 or 팀프로젝트
  char subject[100]; // 과목
} Calendar;

int selectMenu(){
    int menu;
    printf("\n******* 한동 A+ 도우미 *******\n");
    printf("1. 일정 조회\n");
    printf("2. 일정 추가\n");
    printf("3. 일정 수정\n");
    printf("4. 일정 삭제\n");
    printf("5. 달력 출력\n");
    printf("0. 종료\n");
    printf("******* 한동 A+ 도우미 *******\n");
    printf("==> 원하는 메뉴는 무엇입니까? ");
    scanf(" %d",&menu);
    return menu;
} // 메뉴 선택 함수 

void clearbuffer(){
    while (getchar() != '\n');
}

int createCalendar(Calendar *p){
    fputs("년: ",stdout);
    clearbuffer();
    scanf("%d",&p->year);
    fputs("월: ",stdout);
    scanf("%d",&p->month);
    fputs("일: ",stdout);
    scanf("%d",&p->day);
    fputs("어떤 종류의 일정입니까?(과제, 시험, 팀플)",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->type);
    fputs("어떤 과목입니까? ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);
    return 1;
} // 일정 추가 함수 

int readCalendar(Calendar p){
    printf(" %d년  %d월 \t %d일 \t\t %s \t (%s)\n",p.year,p.month,p.day,p.type,p.subject);
    return 1;
}// 일정 read 함수 

void listCalendar(Calendar *p, int count){
    int i = 0;
    printf("\nNo \t 년 \t 월 \t 일 \t\t 종류 \t 과목\n");
    for(i = 0; i < count; i++){
        if(p[i].year == -1) continue;
        printf("%d \t",i+1);
        readCalendar(p[i]);
    }
} // 전체 일정 출력 함수

int selectData(Calendar *p, int count){
    int num;
    listCalendar(p,count);
    printf("선택할 번호는 무엇입니까?(취소:0) ");
    scanf(" %d",&num);
    return num;
} // data 선택 함수 

int updateCalendar(Calendar *p){
    fputs("수정할 년도: ",stdout);
    clearbuffer();
    scanf("%d",&p->year);
    fputs("수정할 월: ",stdout);
    scanf("%d",&p->month);
    fputs("수정할 일: ",stdout);
    scanf("%d",&p->day);
    fputs("어떤 종류의 일정입니까?(과제, 시험, 팀플)",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->type);
    fputs("어떤 과목입니까? ",stdout);
    clearbuffer();
    scanf("%[^\n]s", p->subject);
    return 1;
} // 일정 수정 함수 

int deleteCalendar(Calendar *s){
    s->year = -1;
    s->month = -1;
    s-> day = -1;
    printf(" ==> 삭제 되었습니다! ");
    return 1;
}