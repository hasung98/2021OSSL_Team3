#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define YES 1
#define NO 0

typedef struct{
  int year; //년
  int month;//월
  int day;//일
  int type; // 과제 or 시험 or 팀프로젝트
  char subject[100]; // 과목
} Calendar;

int selectMenu();
void clearbuffer();
int createPlan(Calendar *p);
int readPlan(Calendar p);

void listPlan(Calendar *p, int count);
int selectDataNo(Calendar *p, int count);

int updatePlan(Calendar *p);
int deletePlan(Calendar *p);

void searchPlan_type(Calendar p[], int count);
void searchPlan_month(Calendar p[], int count);

void showCalendar();
int is_leap_year(int x);

int loadData(Calendar *s); //파일 불러오기
void saveData(Calendar *s, int index); //파일 저장하기