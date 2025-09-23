# -----------------------------
# File: src/Makefile
# -----------------------------

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -I../include
CFLAGS_PIC  = $(CFLAGS) -fPIC          # required for .so objects

# Directories
OBJDIR  = ../obj
BINDIR  = ../bin
LIBDIR  = ../lib

# Targets (names)
STATIC_LIB     = $(LIBDIR)/libmyutils.a
DYNAMIC_LIB    = $(LIBDIR)/libmyutils.so
CLIENT_STATIC  = $(BINDIR)/client_static
CLIENT_DYNAMIC = $(BINDIR)/client_dynamic

# Sources
SRCS_LIB  = myfilefunctions.c mystrfunctions.c
SRCS_MAIN = main.c

# Objects for static lib
OBJS_LIB_STATIC = \
  $(OBJDIR)/myfilefunctions.o \
  $(OBJDIR)/mystrfunctions.o

# Objects for dynamic lib (MUST be built with -fPIC)
OBJS_LIB_DYNAMIC = \
  $(OBJDIR)/myfilefunctions.pic.o \
  $(OBJDIR)/mystrfunctions.pic.o

# Main object
OBJ_MAIN = $(OBJDIR)/main.o

.PHONY: all clean static dynamic

# Build both libraries and dynamic client by default
all: static dynamic $(CLIENT_DYNAMIC)

# ---------- Static library + (optional) static client ----------
static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJS_LIB_STATIC)
	@mkdir -p $(LIBDIR)
	ar rcs $(STATIC_LIB) $(OBJS_LIB_STATIC)

$(OBJDIR)/myfilefunctions.o: myfilefunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o

# Fully static client (from Feature-3) — optional; keep if you need size comparison
$(CLIENT_STATIC): $(OBJ_MAIN) $(STATIC_LIB)
	@mkdir -p $(BINDIR)
	$(CC) -static $(OBJ_MAIN) -L$(LIBDIR) -lmyutils -o $(CLIENT_STATIC)

# ---------- Dynamic library + dynamic client ----------
dynamic: $(DYNAMIC_LIB)

# Build the shared object from PIC objects
$(DYNAMIC_LIB): $(OBJS_LIB_DYNAMIC)
	@mkdir -p $(LIBDIR)
	$(CC) -shared -Wl,-soname,libmyutils.so -o $(DYNAMIC_LIB) $(OBJS_LIB_DYNAMIC)

# PIC object rules for the .so
$(OBJDIR)/myfilefunctions.pic.o: myfilefunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS_PIC) -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.pic.o

$(OBJDIR)/mystrfunctions.pic.o: mystrfunctions.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS_PIC) -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.pic.o

# Dynamic client links against the .so (no -static here)
$(CLIENT_DYNAMIC): $(OBJ_MAIN) $(DYNAMIC_LIB)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJ_MAIN) -L$(LIBDIR) -lmyutils -o $(CLIENT_DYNAMIC)
	@echo "Built $(CLIENT_DYNAMIC) (dynamically linked)"

# Main object (common)
$(OBJ_MAIN): main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $(OBJ_MAIN)

# Cleanup
clean:
	rm -f $(OBJDIR)/*.o $(STATIC_LIB) $(DYNAMIC_LIB) $(CLIENT_STATIC) $(CLIENT_DYNAMIC)
