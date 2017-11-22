CCC = clang++
LEX = flex
YACC = bison
CFLAGS = -g -std=c++11 -W -Wall -Weffc++ -Wextra -pedantic -O0
LEXFLAGS = -Wno-unused -Wno-sign-compare -Wno-deprecated-register

OBJS = ast.o poolOfNodes.o symbolTable.o parse.tab.o lex.yy.o main.o

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

parse.tab.c: includes/parse.y
	$(YACC) -d includes/parse.y

parse.tab.o: parse.tab.c
	$(CCC) $(CFLAGS) -c parse.tab.c

lex.yy.c: includes/scan.l parse.tab.o
	$(LEX) includes/scan.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c

ast.o: includes/ast.cpp includes/ast.h includes/literal.h
	$(CCC) $(CFLAGS) -c includes/ast.cpp

poolOfNodes.o: includes/poolOfNodes.cpp includes/poolOfNodes.h includes/node.h
	$(CCC) $(CFLAGS) -c includes/poolOfNodes.cpp

symbolTable.o: includes/symbolTable.cpp includes/symbolTable.h
	$(CCC) $(CFLAGS) -c includes/symbolTable.cpp

main.o: main.cpp
	$(CCC) $(CFLAGS) -c main.cpp

clean:
	rm -f run *.o parse.tab.c lex.yy.c
	rm -f parse.tab.h
	rm -f cases/*.out
	rm -f out
