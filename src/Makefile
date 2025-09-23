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

# Objects that go into the library (no main.o)
OBJS_LIB = \
  $(OBJDIR)/myfilefunctions.o \
  $(OBJDIR)/mystrfunctions.o

OBJ_MAIN = $(OBJDIR)/main.o

.PHONY: all clean

# Default build: library + fully static executable
all: $(LIB) $(TARGET)

# Link the final program fully static
$(TARGET): $(OBJ_MAIN) $(LIB)
	@mkdir -p $(BINDIR)
	$(CC) -static $(OBJ_MAIN) -L$(LIBDIR) -lmyutils -o $(TARGET)

# Create static library
$(LIB): $(OBJS_LIB)
	@mkdir -p $(LIBDIR)
	ar rcs $(LIB) $(OBJS_LIB)

# Compile rules
$(OBJDIR)/myfilefunctions.o: myfilefunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $@

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $@

$(OBJDIR)/main.o: main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $@

# Clean
clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(LIB)
