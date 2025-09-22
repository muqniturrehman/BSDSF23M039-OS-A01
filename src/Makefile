CC      = gcc
CFLAGS  = -Wall -I../include
OBJDIR  = ../obj
BINDIR  = ../bin
TARGET  = $(BINDIR)/client

OBJS = $(OBJDIR)/main.o $(OBJDIR)/myfilefunctions.o $(OBJDIR)/mystrfunctions.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJDIR)/main.o: main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $@

$(OBJDIR)/myfilefunctions.o: myfilefunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $@

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
