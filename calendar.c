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