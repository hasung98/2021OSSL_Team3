CC = gcc
CFLAGS = -W -Wall
TARGET = calendar
DTARGET = calender_debug
OBJECTS = main.c calendar.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o $(TARGET) $(DTARGET)
