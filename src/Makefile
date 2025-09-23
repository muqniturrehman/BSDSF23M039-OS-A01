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
# ===== Install / Uninstall =====
PREFIX      ?= /usr/local
BINDIR_SYS   = $(PREFIX)/bin
MANDIR_SYS   = $(PREFIX)/share/man
MAN1DIR_SYS  = $(MANDIR_SYS)/man1
MAN3DIR_SYS  = $(MANDIR_SYS)/man3

# Choose which executable to install; for Feature-4 you likely want client_dynamic
INSTALL_BIN ?= $(BINDIR)/client_dynamic

.PHONY: install uninstall

install: $(INSTALL_BIN)
	@echo "Installing binary to $(BINDIR_SYS)"
	install -d "$(BINDIR_SYS)"
	install -m 0755 "$(INSTALL_BIN)" "$(BINDIR_SYS)/client"

	@echo "Installing man pages"
	install -d "$(MAN1DIR_SYS)" "$(MAN3DIR_SYS)"
	# compress on the fly to .gz (common on many systems)
	gzip -c -9 ../man/man1/client.1    > "$(MAN1DIR_SYS)/client.1.gz"
	gzip -c -9 ../man/man3/mystrlen.3  > "$(MAN3DIR_SYS)/mystrlen.3.gz"
	gzip -c -9 ../man/man3/mystrcpy.3  > "$(MAN3DIR_SYS)/mystrcpy.3.gz"
	gzip -c -9 ../man/man3/mystrncpy.3 > "$(MAN3DIR_SYS)/mystrncpy.3.gz"
	gzip -c -9 ../man/man3/mystrcat.3  > "$(MAN3DIR_SYS)/mystrcat.3.gz"
	gzip -c -9 ../man/man3/wordCount.3 > "$(MAN3DIR_SYS)/wordCount.3.gz"
	gzip -c -9 ../man/man3/mygrep.3    > "$(MAN3DIR_SYS)/mygrep.3.gz"

	@echo "Updating man database (may require root)"
	-which mandb >/dev/null 2>&1 && sudo mandb >/dev/null || true
	@echo "Install complete."

uninstall:
	@echo "Removing binary and man pages from $(PREFIX)"
	-rm -f "$(BINDIR_SYS)/client"
	-rm -f "$(MAN1DIR_SYS)/client.1" "$(MAN1DIR_SYS)/client.1.gz"
	-rm -f "$(MAN3DIR_SYS)/mystrlen.3"  "$(MAN3DIR_SYS)/mystrlen.3.gz"
	-rm -f "$(MAN3DIR_SYS)/mystrcpy.3"  "$(MAN3DIR_SYS)/mystrcpy.3.gz"
	-rm -f "$(MAN3DIR_SYS)/mystrncpy.3" "$(MAN3DIR_SYS)/mystrncpy.3.gz"
	-rm -f "$(MAN3DIR_SYS)/mystrcat.3"  "$(MAN3DIR_SYS)/mystrcat.3.gz"
	-rm -f "$(MAN3DIR_SYS)/wordCount.3" "$(MAN3DIR_SYS)/wordCount.3.gz"
	-rm -f "$(MAN3DIR_SYS)/mygrep.3"    "$(MAN3DIR_SYS)/mygrep.3.gz"
	@echo "Uninstall complete."
