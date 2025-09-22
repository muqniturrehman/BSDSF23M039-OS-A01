# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -I../include

# Directories
OBJDIR  = ../obj
BINDIR  = ../bin
LIBDIR  = ../lib

# Targets
TARGET  = $(BINDIR)/client_static
LIB     = $(LIBDIR)/libmyutils.a

# Objects
OBJS_LIB = \
  $(OBJDIR)/myfilefunctions.o \
  $(OBJDIR)/mystrfunctions.o

OBJ_MAIN = $(OBJDIR)/main.o

.PHONY: all clean

# Default build: library + executable
all: $(LIB) $(TARGET)

# Link final executable from main.o and the library
$(TARGET): $(OBJ_MAIN) $(LIB)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJ_MAIN) -L$(LIBDIR) -lmyutils -o $(TARGET)

# Build static library from object files
$(LIB): $(OBJS_LIB)
	@mkdir -p $(LIBDIR)
	ar rcs $(LIB) $(OBJS_LIB)

# Explicit compile rules
$(OBJDIR)/myfilefunctions.o: myfilefunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o

$(OBJDIR)/main.o: main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $(OBJDIR)/main.o

# Clean build artifacts
clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(LIB)
