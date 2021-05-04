#include <string.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  int year; //년
  int month;//월
  int day;//일
  int type; // 과제 or 시험 or 팀프로젝트
  char subject[100]; // 과목
} Calendar;

int selectMenu();
void clearbuffer();
int createPlan(Calendar *s);
void readPlan(Calendar *s);

void listPlan(Calendar *s, int count);
int selectDataNo(Calendar *s, int count);

void updatePlan(Calendar *s);
void deletePlan(Calendar *s);

void searchPlan_category(Calendar *s, int count);
void searchPlan_month(Calendar *s, int count);

void showCalendar();

int loadFile(Calendar *s); //파일 불러오기
void loadData(Calendar *s, int index); //파일 저장하기