#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define YES 1
#define NO 0


typedef struct{
  int year; //년
  int month;//월
  int day;//일
  int type; // 과제 or 시험 or 팀프로젝트
  char subject[100]; // 과목
  char text[100];
} Planner;


int check_char(char *buff);
int finish();

int selectMenu();
void clearbuffer();
int createPlan(Planner *p);
int readPlan(Planner p);

void listPlan(Planner *p, int count);
int selectDataNo(Planner *p, int count);

int updatePlan(Planner *p);
int deletePlan(Planner *p);

void search_Plan(Planner p[], int count);
void searchPlan_type(Planner p[], int count);
void searchPlan_month(Planner p[], int count);

void showCalendar(int month, int ndays, int d1);
int is_leap_year(int x);
int month_days(int y, int m);
int first_day(int y, int m);
void Calendar(int year);

int loadData(Planner *s); //파일 불러오기
void saveData(Planner *s, int index); //파일 저장하기