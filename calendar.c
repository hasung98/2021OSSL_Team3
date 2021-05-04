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
    scanf("%[^\n]s", p->type);
    fputs("어떤 과목입니까? ",stdout);
    scanf("%[^\n]s", p->subject);
    return 1;
} // 일정 추가 함수 

int readCalendar(Calendar p){
    printf("%d년 %d월 %d일, %s (%s)\n",p.year,p.month,p.day,p.type,p.subject);
    return 1;
}// 제품 출력 함수 

