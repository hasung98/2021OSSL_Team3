typedef struct{
  int year; //년
  int month;//월
  int day;//일
  char type[100] // 과제 or 시험 or 팀프로젝트
  char subject[100] // 과목
} Calender;

int selectMenu();
int loadFile(Calender *s); //파일 불러오기
void loadData(Calender *s, int index); //파일 저장하기

int createCalender(Calender *s);
void readCalender(Calender *s);
void updateCalender(Calender *s);
void deleteCalender(Calender *s);

int selectDataNo(Calender *s, int count);
void listCalender(Calender *s, int count);

void searchCalender_category(Calender *s, int count);
void searchCalender_month(Calender *s, int count);

void showCalender();
