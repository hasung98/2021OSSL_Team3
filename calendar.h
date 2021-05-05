#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define YES 1
#define NO 0

typedef struct{
  int year; //��
  int month;//��
  int day;//��
  int type; // ���� or ���� or ��������Ʈ
  char subject[100]; // ����
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

int loadData(Calendar *s); //���� �ҷ�����
void saveData(Calendar *s, int index); //���� �����ϱ�