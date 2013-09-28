CC = gcc -g
CFLAGS = -O4 -W -Wall
EXEC = list
LDLIBS =

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin

MAIN = $(BINDIR)/$(EXEC)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS) 

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$*.o 

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$*.o 

$(OBJDIR) : 
	mkdir $(OBJDIR)

$(BINDIR) : 
	mkdir $(BINDIR)

clean : 
	rm $(OBJ);

veryclean : clean
	rm $(BINDIR)/$(EXEC)
