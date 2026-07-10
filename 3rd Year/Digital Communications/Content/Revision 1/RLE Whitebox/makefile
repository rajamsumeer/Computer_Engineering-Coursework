## Student ID:
## Student Name: Raja M. Sumeer
## Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)
## MAKEFILE
## Sources:
# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# https://makefiletutorial.com/
# https://medium.com/@ksaquib/boost-your-workflow-mastering-makefiles-for-efficient-development-c85e8b93446d
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# prepend: https://stackoverflow.com/questions/6498727/show-and-execute

# FLAGS
CC=gcc
SRCDIR=src
BINDIR=bin
SRCFILES=$(wildcard $(SRCDIR)/*.c)
EXEFILES=$(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.exe, $(SRCFILES))
RUNEXES=$(wildcard $(BINDIR)/*.exe)

all: $(BINDIR) $(EXEFILES)
	@echo "------------------------------------"
	@echo "ALL PROGRAMS COMPILED WITHOUT ERRORS"
	@echo "------------------------------------"

run:
	@$(foreach exe,$(RUNEXES),echo "----------------";echo "Running Program:" $(exe);echo "----------------";./$(exe);)

# CREATE BIN DIRECTORY
$(BINDIR):
	@mkdir -p $(BINDIR)
	@echo "BIN DIRECTORY CREATED - LAST STATE: MISSING"

# .C to .EXE
$(BINDIR)/%.exe: $(SRCDIR)/%.c
	@$(CC) -o $@ $<
	@echo "PROGRAM: $(@F) MADE"

clean:
	@rm -f $(BINDIR)/*.exe $(BINDIR)/*div*
	@echo "----------------------------------------------------"
	@echo "CLEANED UP EXECUTABLE & DIV FILES FROM BIN DIRECTORY"
	@echo "----------------------------------------------------"

## MANUAL COMPILING OF PROGRAMS 
01: $(SRCDIR)/uncompressed.c
	@$(CC) -o $(BINDIR)/uncompressed.exe $(SRCDIR)/uncompressed.c
	@echo "PROGRAM: $(basename $@) MADE"
	@echo "COMPILED $(basename $@) WITHOUT ERRORS"

02: $(SRCDIR)/compressed.c
	@$(CC) -o $(BINDIR)/compressed.exe $(SRCDIR)/compressed.c
	@echo "PROGRAM: $(basename $@) MADE"
	@echo "COMPILED $(basename $@) WITHOUT ERRORS"