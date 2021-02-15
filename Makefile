CXX = g++
CXXFLAGS = -O2 -Wall -Werror -std=c++17 -Iinclude
LDFLAGS = -lncurses

EXE = snake
SRCDIR = src
OBJDIR = obj
TESTDIR = test

OBJECTS = obj/Board.o obj/GameController.o

all: $(EXE) $(TESTEXE)

$(EXE): $(OBJECTS) obj/main.o
	$(CXX) $(OBJECTS) obj/main.o -o $(EXE) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(OBJDIR)/*.d)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXE) $(TESTEXE)

.PHONY: clean all