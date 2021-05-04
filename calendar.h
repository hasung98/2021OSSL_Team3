#include <string.h>
#include <stdio.h>

typedef struct{
  int year; //년
  int month;//월
  int day;//일
  char type[100]; // 과제 or 시험 or 팀프로젝트
  char subject[100]; // 과목
} Calendar;

int selectMenu();
int loadFile(Calendar *s); //파일 불러오기
void loadData(Calendar *s, int index); //파일 저장하기

int createPlan(Calendar *s);
void readPlan(Calendar *s);
void updatePlan(Calendar *s);
void deletePlan(Calendar *s);

int selectDataNo(Calendar *s, int count);
void listPlan(Calendar *s, int count);

void searchPlan_category(Calendar *s, int count);
void searchPlan_month(Calendar *s, int count);

void showCalendar();
