#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define YES 1
#define NO 0


typedef struct{
  int year; // 년
  int month; // 월
  int day; // 일
  int type; // 과제 or 시험 or 팀프로젝트 or 기타
  char subject[100]; // 과목
  char text[100]; // 비고
} Planner;

// helper 함수
int check_char(char *buff);
char* transer(int type);
void clearbuffer();
int selectMenu(); // 메뉴 선택
int selectDataNo(Planner *p, int count); // 일정 선택
int finish(); // 프로그램 종료


// 일정 추가 or 삭제 함수
int createPlan(Planner *); // 일정 추가
int updatePlan(Planner *p); // 일정 수정
int deletePlan(Planner *p); // 일정 삭제

// 일정 출력 함수
int printPlan(Planner p); // 일정 출력
void totalPlan(Planner *p, int count); // 전체일정 출력


// 일정검색 함수
void search_Plan(Planner p[], int count); // 검색방법 선택
void searchPlan_type(Planner p[], int count); // 분류로 검색
void searchPlan_month(Planner p[], int count); // 날짜로 검색

// 달력 함수
void showCalendar(int month, int ndays, int d1); // 달력 출력
int is_leap_year(int x); // 윤년 판별
int month_days(int y, int m); // '월'이 몇일인지 확인
int first_day(int y, int m); // 시작 요일 확인
void Calendar(int year); //helper function 

// File I/O
int loadData(Planner *s); //파일 불러오기
void saveData(Planner *s, int index); //파일 저장하기

