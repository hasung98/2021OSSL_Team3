CC = gcc
CFLAGS = -W -Wall
TARGET = calendar_main
OBJECTS = calendar_main.c calendar.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o
	rm calendar_main
