// Generated by transforming |cwd:///work-in-progress/2.7.2-bisonified.y| on 2016-11-23 at 15:46:56 +0000
%{
  #include "includes/ast.h"
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
  unsigned depthOfFunc = 0;
  unsigned depthOfClass = 0;
  PoolOfNodes& pool = PoolOfNodes::getInstance();
  SymbolTable sTable;
  extern NoneTypeLiteral None;
%}


// 83 tokens, in alphabetical order:
%token AMPEREQUAL AMPERSAND AND AS ASSERT AT BACKQUOTE BAR BREAK CIRCUMFLEX
%token CIRCUMFLEXEQUAL CLASS COLON COMMA CONTINUE DEDENT DEF DEL DOT DOUBLESLASH
%token DOUBLESLASHEQUAL DOUBLESTAR DOUBLESTAREQUAL ELIF ELSE ENDMARKER EQEQUAL
%token EQUAL EXCEPT EXEC FINALLY FOR FROM GLOBAL GREATER GREATEREQUAL GRLT
%token IF IMPORT IN INDENT IS LAMBDA LBRACE LEFTSHIFT LEFTSHIFTEQUAL LESS
%token LESSEQUAL LPAR LSQB MINEQUAL MINUS NAME NEWLINE NOT NOTEQUAL INT FLOAT 
%token OR PASS PERCENT PERCENTEQUAL PLUS PLUSEQUAL PRINT RAISE RBRACE RETURN
%token RIGHTSHIFT RIGHTSHIFTEQUAL RPAR RSQB SEMI SLASH SLASHEQUAL STAR STAREQUAL
%token STRING TILDE TRY VBAREQUAL WHILE WITH YIELD NUMBER TRUE FALSE NONE

%start start

%type<node> atom plus_STRING power factor term arith_expr shift_expr opt_yield_test pick_yield_expr_testlist_comp testlist_comp pick_yield_expr_testlist testlist star_EQUAL expr_stmt test 
%type<node> or_test and_test not_test comparison expr xor_expr and_expr testlist1 listmaker opt_listmaker dictorsetmaker opt_dictorsetmaker pick_for_test argument pick_argument
%type<node> trailer small_stmt simple_stmt stmt compound_stmt if_stmt global_stmt
%type<node> fpdef opt_test print_stmt funcdef pick_NEWLINE_stmt flow_stmt return_stmt
%type<tuple> parameters varargslist star_fpdef_COMMA star_fpdef_notest fplist star_trailer star_COMMA_test star_SEMI_small_stmt arglist star_argument_COMMA opt_arglist star_ELIF star_COMMA_NAME
%type<suite> suite plus_stmt star_NEWLINE_stmt opt_ELSE
%type<id> NAME STRING
%type<integer> INT 
%type<floatnumber> FLOAT
%type<integer> comp_op pick_unop pick_multop pick_PLUS_MINUS pick_LEFTSHIFT_RIGHTSHIFT augassign 

%union {
  Node* node;
  TuplesLiteral* tuple;
  SuiteNode* suite;
  char *id;
  long integer;
  long double floatnumber;
}
%locations

%%

start
	: file_input
	;
file_input // Used in: start
	: star_NEWLINE_stmt ENDMARKER
    { if($1) $1 -> eval(&sTable); }
	;
pick_NEWLINE_stmt // Used in: star_NEWLINE_stmt
	: NEWLINE
    { $$ = nullptr; }
	| stmt
    {
      // XXX: Python doesn't consider root suite as a suite, they process each line
      // XXX: whenever it is available. That is, I need to figure out whether it is a suite
      $$ = $1;
    }

	;
star_NEWLINE_stmt // Used in: file_input, star_NEWLINE_stmt
	: star_NEWLINE_stmt pick_NEWLINE_stmt
    { 
      if($1) {
        $1 -> addLine($2);
        $$ = $1;
      }
      else {
        $$ = new SuiteNode($2);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
decorator // Used in: decorators
	: AT dotted_name LPAR opt_arglist RPAR NEWLINE
	| AT dotted_name NEWLINE
	;
opt_arglist // Used in: decorator, trailer
	: arglist
    { $$ = $1; }
	| %empty
    { $$ = nullptr; }
	;
decorators // Used in: decorators, decorated
	: decorators decorator
	| decorator
	;
decorated // Used in: compound_stmt
	: decorators classdef
	| decorators funcdef
	;
funcdef // Used in: decorated, compound_stmt
	: DEF NAME parameters COLON suite
    {
      $$ = new FuncDef($2, $3, $5) ;
      pool.add($$);
      delete [] $2;
    }
	;
parameters // Used in: funcdef
	: LPAR varargslist RPAR
    { $$ = $2; }
	| LPAR RPAR
    { $$ = new TuplesLiteral; pool.add($$); }
	;
varargslist // Used in: parameters, old_lambdef, lambdef
	: star_fpdef_COMMA pick_STAR_DOUBLESTAR
    { $$ = $1; }
	| star_fpdef_COMMA fpdef opt_EQUAL_test opt_COMMA
    { 
      if($1) {
        $1 -> add_back($2);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral($2);
        pool.add($$);
      }
    }
	;
opt_EQUAL_test // Used in: varargslist, star_fpdef_COMMA
	: EQUAL test
	| %empty
	;
star_fpdef_COMMA // Used in: varargslist, star_fpdef_COMMA
	: star_fpdef_COMMA fpdef opt_EQUAL_test COMMA
    { 
      if($1) {
        $1 -> add_back($2);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral($2);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
opt_DOUBLESTAR_NAME // Used in: pick_STAR_DOUBLESTAR
	: COMMA DOUBLESTAR NAME
	| %empty
	;
pick_STAR_DOUBLESTAR // Used in: varargslist
	: STAR NAME opt_DOUBLESTAR_NAME
	| DOUBLESTAR NAME
	;
opt_COMMA // Used in: varargslist, opt_test, opt_test_2, testlist_safe, listmaker, testlist_comp, pick_for_test_test, pick_for_test, pick_argument
	: COMMA
	| %empty
	;
fpdef // Used in: varargslist, star_fpdef_COMMA, fplist, star_fpdef_notest
	: NAME
    { 
      $$ = new IdentNode($1);
      pool.add($$);
      delete [] $1;
    }
	| LPAR fplist RPAR
    { $$ = $2; } 
	;
fplist // Used in: fpdef
	: fpdef star_fpdef_notest COMMA
    {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }
      else {
        $$ = new TuplesLiteral($1);
        pool.add($$);
      }
    }
	| fpdef star_fpdef_notest
    {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }
      else {
        $$ = new TuplesLiteral($1);
        pool.add($$);
      }
    }
	;
star_fpdef_notest // Used in: fplist, star_fpdef_notest
	: star_fpdef_notest COMMA fpdef
    {
      if($1) {
        $1 -> add_back($3);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral($3);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
stmt // Used in: pick_NEWLINE_stmt, plus_stmt
	: simple_stmt
    { $$ = $1; }
	| compound_stmt
    { $$ = $1; }
	;
simple_stmt // Used in: stmt, suite
	: small_stmt star_SEMI_small_stmt SEMI NEWLINE
    { 
      if($2) {
        $2 -> add_front($1); 
        $$ = $2;
      }
      else 
        $$ = $1; 
    }
	| small_stmt star_SEMI_small_stmt NEWLINE
    { 
      if($2) {
        $2 -> add_front($1); 
        $$ = $2;
      }
      else 
        $$ = $1; 
    }
	;
star_SEMI_small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: star_SEMI_small_stmt SEMI small_stmt
    {
      if($1) {
        $1 -> add_front($3);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral($3);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: expr_stmt
    { $$ = $1; }
	| print_stmt
    { $$ = $1; }
	| del_stmt
    { $$ = nullptr; }
	| pass_stmt
    { $$ = nullptr; }
	| flow_stmt
    { $$ = $1; }
	| import_stmt
    { $$ = nullptr; }
	| global_stmt
    { $$ = $1; }
	| exec_stmt
    { $$ = nullptr; }
	| assert_stmt
    { $$ = nullptr; }
	;
expr_stmt // Used in: small_stmt
	: testlist augassign pick_yield_expr_testlist
    {
      Node* rhs;
      switch($2){
        case PLUSEQUAL:
          rhs = new AddBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
        case MINEQUAL:
          rhs = new SubBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
 	      case STAREQUAL:
          rhs = new MulBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
	      case SLASHEQUAL:
          rhs = new DivBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
	      case PERCENTEQUAL:
          rhs = new ModBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
	      case AMPEREQUAL:
          break;
	      case VBAREQUAL:
          break;
	      case CIRCUMFLEXEQUAL:
          break;
	      case LEFTSHIFTEQUAL:
          rhs = new ModBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new LeftShiftNode($$, rhs);
          pool.add($$);
          break;
	      case RIGHTSHIFTEQUAL:
          rhs = new ModBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new RightShiftNode($$, rhs);
          pool.add($$);
          break;
	      case DOUBLESTAREQUAL:
          rhs = new PowBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
	      case DOUBLESLASHEQUAL:
          rhs = new DoubleSlashBinaryNode($$, $3);
          pool.add(rhs);
          $$ = new AssBinaryNode($$, rhs);
          pool.add($$);
          break;
      }
    }
	| testlist star_EQUAL
    {
      if($2) {
        $$ = new AssBinaryNode($1, $2);
        pool.add($$);
      }
      else {
        $$ = $1;
      }
    }
  ;
pick_yield_expr_testlist // Used in: expr_stmt, star_EQUAL
	: yield_expr
    { $$ = nullptr; }
	| testlist
    { $$ = $1; }
	;
star_EQUAL // Used in: expr_stmt, star_EQUAL
  : EQUAL pick_yield_expr_testlist star_EQUAL 
    { 
      if($3) {
        $$ = new AssBinaryNode($2, $3); 
        pool.add($$);
      }
      else {
        $$ = $2;
      }
    }
  | %empty
    { $$ = nullptr; }
	;
augassign // Used in: expr_stmt
	: PLUSEQUAL
    { $$ = PLUSEQUAL; }
	| MINEQUAL
    { $$ = MINEQUAL; }
	| STAREQUAL
    { $$ = STAREQUAL; }
	| SLASHEQUAL
    { $$ = SLASHEQUAL; }
	| PERCENTEQUAL
    { $$ = PERCENTEQUAL; }
	| AMPEREQUAL
    { $$ = AMPEREQUAL; }
	| VBAREQUAL
    { $$ = VBAREQUAL; }
	| CIRCUMFLEXEQUAL
    { $$ = CIRCUMFLEXEQUAL; }
	| LEFTSHIFTEQUAL
    { $$ = LEFTSHIFTEQUAL; }
	| RIGHTSHIFTEQUAL
    { $$ = RIGHTSHIFTEQUAL; }
	| DOUBLESTAREQUAL
    { $$ = DOUBLESTAREQUAL; }
	| DOUBLESLASHEQUAL
    { $$ = DOUBLESLASHEQUAL; }
	;
print_stmt // Used in: small_stmt
	: PRINT opt_test
    { 
      $$ = new PrintNode($2);
      pool.add($$);
    }
	| PRINT RIGHTSHIFT test opt_test_2
    { 
      $$ = new PrintNode($3);
      pool.add($$);
    }
	;
star_COMMA_test // Used in: star_COMMA_test, opt_test, listmaker, testlist_comp, testlist, pick_for_test
	: star_COMMA_test COMMA test
    {
      if($1) {
        $1 -> add_back($3);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral($3);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
opt_test // Used in: print_stmt
	: test star_COMMA_test opt_COMMA
	  {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }  
      else {
        TuplesLiteral* printTuple = new TuplesLiteral($1);
        pool.add(printTuple);
        $$ = printTuple;
      }
    }
	| %empty
    { $$ = nullptr; }
	;
plus_COMMA_test // Used in: plus_COMMA_test, opt_test_2
	: plus_COMMA_test COMMA test
	| COMMA test
	;
opt_test_2 // Used in: print_stmt
	: plus_COMMA_test opt_COMMA
	| %empty
	;
del_stmt // Used in: small_stmt
	: DEL exprlist
	;
pass_stmt // Used in: small_stmt
	: PASS
	;
flow_stmt // Used in: small_stmt
	: break_stmt
    { $$ = nullptr; }
	| continue_stmt
    { $$ = nullptr; }
	| return_stmt
    { $$ = $1; }
	| raise_stmt
    { $$ = nullptr; }
	| yield_stmt
    { $$ = nullptr; }
	;
break_stmt // Used in: flow_stmt
	: BREAK
	;
continue_stmt // Used in: flow_stmt
	: CONTINUE
	;
return_stmt // Used in: flow_stmt
	: RETURN testlist
    {
      $$ = new ReturnNode($2);
      pool.add($$);
    }
	| RETURN
    {
      $$ = new ReturnNode(&None);
      pool.add($$);
    }
	;
yield_stmt // Used in: flow_stmt
	: yield_expr
	;
raise_stmt // Used in: flow_stmt
	: RAISE test opt_test_3
	| RAISE
	;
opt_COMMA_test // Used in: opt_test_3, exec_stmt
	: COMMA test
	| %empty
	;
opt_test_3 // Used in: raise_stmt
	: COMMA test opt_COMMA_test
	| %empty
	;
import_stmt // Used in: small_stmt
	: import_name
	| import_from
	;
import_name // Used in: import_stmt
	: IMPORT dotted_as_names
	;
import_from // Used in: import_stmt
	: FROM pick_dotted_name IMPORT pick_STAR_import
	;
pick_dotted_name // Used in: import_from
	: star_DOT dotted_name
	| star_DOT DOT
	;
pick_STAR_import // Used in: import_from
	: STAR
	| LPAR import_as_names RPAR
	| import_as_names
	;
import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: NAME AS NAME
	| NAME
	;
dotted_as_name // Used in: dotted_as_names
	: dotted_name AS NAME
	| dotted_name
	;
import_as_names // Used in: pick_STAR_import
	: import_as_name star_COMMA_import_as_name COMMA
	| import_as_name star_COMMA_import_as_name
	;
star_COMMA_import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: star_COMMA_import_as_name COMMA import_as_name
	| %empty
	;
dotted_as_names // Used in: import_name, dotted_as_names
	: dotted_as_name
	| dotted_as_names COMMA dotted_as_name
	;
dotted_name // Used in: decorator, pick_dotted_name, dotted_as_name, dotted_name
	: NAME
	| dotted_name DOT NAME
	;
global_stmt // Used in: small_stmt
	: GLOBAL NAME star_COMMA_NAME
    {
      IdentNode* id = new IdentNode($2);
      pool.add(id);
      delete [] $2;
      if($3) {
        $3 -> add_front(id);
        $$ = new GlobalNode($3);
        pool.add($$);
      }
      else {
        TuplesLiteral* nameList = new TuplesLiteral(id);
        pool.add(nameList);
        $$ = new GlobalNode(nameList);
        pool.add($$);
      }
    }
	;
star_COMMA_NAME // Used in: global_stmt, star_COMMA_NAME
	: star_COMMA_NAME COMMA NAME
    {
      IdentNode* id = new IdentNode($3);
      delete [] $3;
      pool.add(id);
      if($1) {
        $1 -> add_back(id);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral(id);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
exec_stmt // Used in: small_stmt
	: EXEC expr IN test opt_COMMA_test
	| EXEC expr
	;
assert_stmt // Used in: small_stmt
	: ASSERT test COMMA test
	| ASSERT test
	;
compound_stmt // Used in: stmt
	: if_stmt
    { $$ = $1; }
	| while_stmt
    { $$ = nullptr; }
	| for_stmt
    { $$ = nullptr; }
	| try_stmt
    { $$ = nullptr; }
	| with_stmt
    { $$ = nullptr; }
	| funcdef
    { $$ = $1; }
	| classdef
    { $$ = nullptr; }
	| decorated
    { $$ = nullptr; }
	;
if_stmt // Used in: compound_stmt
	: IF test COLON suite star_ELIF opt_ELSE
    {
      IFNode* ifNode = new IFNode($2, $4);
      pool.add(ifNode);
      if($5) {
        if($6) {
          $5 -> add_back($6);
        }
        ifNode -> add_suite($5);
      }
      else if($6) {
        ifNode -> add_line($6);
      }
      $$ = ifNode;
    }
	;
star_ELIF // Used in: if_stmt, star_ELIF
	: star_ELIF ELIF test COLON suite
    { 
      IFNode* ifNode = new IFNode($3, $5);
      pool.add(ifNode);
      if($1) {
        $1 -> add_back(ifNode);
        $$ = $1;
      } 
      else {
        $$ = new TuplesLiteral(ifNode);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
while_stmt // Used in: compound_stmt
	: WHILE test COLON { ++depthOfFunc; } suite opt_ELSE
    {
      --depthOfFunc;
    }
	;
for_stmt // Used in: compound_stmt
	: FOR exprlist IN testlist COLON { ++depthOfFunc; } suite opt_ELSE
    {
      --depthOfFunc;
    }
	;
try_stmt // Used in: compound_stmt
	: TRY COLON { ++depthOfFunc; } suite except_Finally
    {
      --depthOfFunc;
    }
	;
except_Finally // Used in: try_stmt
  : plus_except opt_ELSE opt_FINALLY
  | FINALLY COLON suite
  ;
plus_except // Used in: except_Finally, plus_except
	: plus_except except_clause COLON suite
	| except_clause COLON suite
	;
opt_ELSE // Used in: while_stmt for_stmt except_Finally
	: ELSE COLON suite
    { $$ = $3; }
	| %empty
    { $$ = nullptr; }
	;
opt_FINALLY // Used in: except_Finally
	: FINALLY COLON suite
	| %empty
	;
with_stmt // Used in: compound_stmt
	: WITH with_item star_COMMA_with_item COLON suite
	;
star_COMMA_with_item // Used in: with_stmt, star_COMMA_with_item
	: star_COMMA_with_item COMMA with_item
	| %empty
	;
with_item // Used in: with_stmt, star_COMMA_with_item
	: test AS expr
	| test
	;
except_clause // Used in: plus_except
	: EXCEPT test opt_AS_COMMA
	| EXCEPT
	;
pick_AS_COMMA // Used in: opt_AS_COMMA
	: AS
	| COMMA
	;
opt_AS_COMMA // Used in: except_clause
	: pick_AS_COMMA test
	| %empty
	;
suite // Used in: funcdef, if_stmt, star_ELIF, while_stmt, for_stmt, try_stmt, plus_except, opt_ELSE, opt_FINALLY, with_stmt, classdef, except_Finally
	: simple_stmt
    { $$ = new SuiteNode($1); pool.add($$); }
	| NEWLINE INDENT plus_stmt DEDENT
    { $$ = $3; }
	;
plus_stmt // Used in: suite, plus_stmt
	: plus_stmt stmt
    { 
      if($1) {
        $1 -> addLine($2);
        $$ = $1;
      }
      else
        throw "wrong expr at plus_stmt";
    }
	| stmt
    { 
      $$ = new SuiteNode($1);
      pool.add($$);
    }
	;
testlist_safe // Used in: list_for
	: old_test plus_COMMA_old_test opt_COMMA
	| old_test
	;
plus_COMMA_old_test // Used in: testlist_safe, plus_COMMA_old_test
	: plus_COMMA_old_test COMMA old_test
	| COMMA old_test
	;
old_test // Used in: testlist_safe, plus_COMMA_old_test, old_lambdef, list_if, comp_if
	: or_test
	| old_lambdef
	;
old_lambdef // Used in: old_test
	: LAMBDA varargslist COLON old_test
	| LAMBDA COLON old_test
	;
test // Used in: opt_EQUAL_test, print_stmt, star_COMMA_test, opt_test, plus_COMMA_test, raise_stmt, opt_COMMA_test, opt_test_3, exec_stmt, assert_stmt, if_stmt, star_ELIF, while_stmt, with_item, except_clause, opt_AS_COMMA, opt_IF_ELSE, listmaker, testlist_comp, lambdef, subscript, opt_test_only, sliceop, testlist, dictorsetmaker, star_test_COLON_test, opt_DOUBLESTAR_test, pick_argument, argument, testlist1
	: or_test opt_IF_ELSE
    { $$ = $1; }
	| lambdef
    { $$ = nullptr; }
	;
opt_IF_ELSE // Used in: test
	: IF or_test ELSE test
    { std::cout << "bug here" << std::endl; }
	| %empty
	;
or_test // Used in: old_test, test, opt_IF_ELSE, or_test, comp_for
	: and_test
    { $$ = $1; }
	| or_test OR and_test
    { $$ = nullptr; }
	;
and_test // Used in: or_test, and_test
	: not_test
    { $$ = $1; }
	| and_test AND not_test
    { $$ = nullptr; }
	;
not_test // Used in: and_test, not_test
	: NOT not_test
    { $$ = nullptr; }
	| comparison
    { $$ = $1; }
	;
comparison // Used in: not_test, comparison
	: expr
    { $$ = $1; }
	| comparison comp_op expr
    {
      switch($2) {
        case LESS:
          $$ = new LessNode($1, $3);
          break;
        case GREATER:
          $$ = new GreaterNode($1, $3);
          break;
        case GREATEREQUAL:
          $$ = new GreaterEQNode($1, $3);
          break;
        case LESSEQUAL:
          $$ = new LessEQNode($1, $3);
          break;
        case EQEQUAL:
          $$ = new EQEqualNode($1, $3);
          break;
        case NOTEQUAL:
          $$ = new NotEQNode($1, $3);
          break;
        default:
          throw "wrong way with compair";
          break;
      }
      pool.add($$);
    }
	;
comp_op // Used in: comparison
	: LESS
    { $$ = LESS; }
	| GREATER
    { $$ = GREATER; }
	| EQEQUAL
    { $$ = EQEQUAL; }
	| GREATEREQUAL
    { $$ = GREATEREQUAL; }
	| LESSEQUAL
    { $$ = LESSEQUAL; }
	| GRLT
    { $$ = GRLT; }
	| NOTEQUAL
    { $$ = NOTEQUAL; }
	| IN
    { $$ = IN; }
	| NOT IN
    { $$ = -IN; }
	| IS
    { $$ = IS; }
	| IS NOT
    { $$ = -IS; }
	;
expr // Used in: exec_stmt, with_item, comparison, expr, exprlist, star_COMMA_expr
	: xor_expr
    { $$ = $1; }
	| expr BAR xor_expr
	;
xor_expr // Used in: expr, xor_expr
	: and_expr
    { $$ = $1; }
	| xor_expr CIRCUMFLEX and_expr
	;
and_expr // Used in: xor_expr, and_expr
	: shift_expr
    { $$ = $1; }
	| and_expr AMPERSAND shift_expr
	;
shift_expr // Used in: and_expr, shift_expr
	: arith_expr
    { $$ = $1; }
	| shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr
    { 
      switch($2){
        case LEFTSHIFT:
          $$ = new LeftShiftNode($1, $3);
          pool.add($$);
          break;
        case RIGHTSHIFT:
          $$ = new RightShiftNode($1, $3);
          pool.add($$);
          break;
        default:
          break;
      }
    }
   
	;
pick_LEFTSHIFT_RIGHTSHIFT // Used in: shift_expr
	: LEFTSHIFT
    { $$ = LEFTSHIFT; }
	| RIGHTSHIFT
    { $$ = RIGHTSHIFT; }
	;
arith_expr // Used in: shift_expr, arith_expr
	: term
    { $$ = $1; }
	| arith_expr pick_PLUS_MINUS term
    { switch($2){
        case PLUS:
          $$ = new AddBinaryNode($1, $3);
          pool.add($$);
          break;
        case MINUS:
          $$ = new SubBinaryNode($1, $3);
          pool.add($$);
          break;
        default:
          break;
      }
    }
	;
pick_PLUS_MINUS // Used in: arith_expr
	: PLUS
    { $$ = PLUS; }
	| MINUS
    { $$ = MINUS; }
	;
term // Used in: arith_expr, term
	: factor
    { $$ = $1; }
	| term pick_multop factor
    { switch($2){
        case STAR:
          $$ = new MulBinaryNode($1, $3); 
          pool.add($$);
          break;
        case SLASH:
          $$ = new DivBinaryNode($1, $3);
          pool.add($$);
          break;
        case PERCENT:
          $$ = new ModBinaryNode($1, $3);
          pool.add($$);
          break;
        case DOUBLESLASH:
          $$ = new DoubleSlashBinaryNode($1, $3);
          pool.add($$);
          break;
        default:
          break;
      }
    }
	;
pick_multop // Used in: term
	: STAR
    { $$ = STAR; }
	| SLASH
    { $$ = SLASH; }
	| PERCENT
    { $$ = PERCENT; }
	| DOUBLESLASH
    { $$ = DOUBLESLASH; }
	;
factor // Used in: term, factor, power
	: pick_unop factor
    {
      Node* lhs;
      switch($1) {
        case PLUS:
          $$ = $2; 
          break; 
        case MINUS:
          lhs = new IntLiteral(0);
          pool.add(lhs);
          $$ = new SubBinaryNode(lhs, $2);
          pool.add($$);
          break; 
        case TILDE:
          lhs = new IntLiteral(-1);
          pool.add(lhs);
          $$ = new SubBinaryNode(lhs, $2);
          pool.add($$);
          break; 
      }
    }
	| power
    { $$ = $1; }
	;
pick_unop // Used in: factor
	: PLUS
    { $$ = PLUS; }
	| MINUS
    { $$ = MINUS; }
	| TILDE
    { $$ = TILDE; }
	;
power // Used in: factor
	: atom star_trailer DOUBLESTAR factor
    { 
      if($2) {
        IdentNode* id = dynamic_cast<IdentNode*>($1);
        if(id) {
          FuncCall* func = new FuncCall(id -> getIdent(), $2); 
          pool.add(func);
          $$ = new PowBinaryNode(func, $4); 
          pool.add($$);
        }
        else
          throw "wrong operation on function";
      }
      else {
        $$ = new PowBinaryNode($1, $4); 
        pool.add($$);
      }
    }
	| atom star_trailer
    { 
      if($2) {
        IdentNode* id = dynamic_cast<IdentNode*>($1);
        if(id) {
          $$ = new FuncCall(id -> getIdent(), $2); 
          pool.add($$);
        }
        else
          throw "wrong operation on function";
      }
      else
        $$ = $1;
    }
	;
star_trailer // Used in: power, star_trailer
	: star_trailer trailer
    {
      if($1) {
        if($1->getType() == tuple) {
          $1 -> add_back($2);
          $$ = $1;
        }
        else {
          std::cout << "wrong way @ star_trailer" << std::endl;
          $$ = new TuplesLiteral($2);
          pool.add($$);
        }
      }
      else {
        $$ = new TuplesLiteral($2);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
atom // Used in: power
	: LPAR opt_yield_test RPAR
    { 
      if($2) {
        TuplesLiteral* _tuple = dynamic_cast<TuplesLiteral*>($2);
        if(_tuple){
          _tuple->setType(tuple);
          $$ = _tuple;
        }
        else 
          $$ = $2; 
      } 
      else { 
        TuplesLiteral* _tuple = new TuplesLiteral(); 
        _tuple->setType(tuple); 
        $$ = _tuple;
        pool.add($$); 
      } 
    }
	| LSQB opt_listmaker RSQB
    { 
      if($2) {
        TuplesLiteral* _tuple = dynamic_cast<TuplesLiteral*>($2);
        if(_tuple){
          _tuple->setType(list);
          $$ = _tuple;
        }
        else {
          TuplesLiteral* new_tuple = new TuplesLiteral($2); 
          new_tuple->setType(list); 
          $$ = new_tuple;
          pool.add($$); 
        }
      } 
      else { 
        TuplesLiteral* _tuple = new TuplesLiteral(); 
        _tuple->setType(list); 
        $$ = _tuple;
        pool.add($$); 
      } 
    }
	| LBRACE opt_dictorsetmaker RBRACE
    { 
      if($2) {
        TuplesLiteral* _tuple = dynamic_cast<TuplesLiteral*>($2);
        if(_tuple){
          _tuple->setType(set);
          $$ = _tuple;
        }
        else 
          $$ = $2; 
      } 
      else { 
        TuplesLiteral* _tuple = new TuplesLiteral(); 
        _tuple->setType(set); 
        $$ = _tuple;
        pool.add($$); 
      } 
    }
	| BACKQUOTE testlist1 BACKQUOTE
    { $$ = nullptr; }
	| NAME
    { $$ = new IdentNode($1); pool.add($$); delete [] $1;       }
  | INT
    { $$ = new IntLiteral($1); pool.add($$);       }
  | FLOAT
    { $$ = new FloatLiteral($1); pool.add($$);     }
  | NUMBER
    { $$ = nullptr; }
  | TRUE
    { $$ = new BoolLiteral(true); pool.add($$);    }
  | FALSE
    { $$ = new BoolLiteral(false); pool.add($$);    }
  | NONE
    { $$ = &None; }
	| plus_STRING
    { $$ = $1; }
	;
pick_yield_expr_testlist_comp // Used in: opt_yield_test
	: yield_expr
    { $$ = nullptr; }
	| testlist_comp
    { $$ = $1; }
	;
opt_yield_test // Used in: atom
	: pick_yield_expr_testlist_comp
    { $$ = $1; }
	| %empty
    { $$ = nullptr; }
	;
opt_listmaker // Used in: atom
	: listmaker
    { $$ = $1; }
	| %empty
    { $$ = nullptr; }
	;
opt_dictorsetmaker // Used in: atom
	: dictorsetmaker
    { $$ = $1; }
	| %empty
    { $$ = nullptr; }
	;
plus_STRING // Used in: atom, plus_STRING
  : plus_STRING STRING
    { 
      Node* rhs = new StrLiteral($2);
      pool.add(rhs);
      $$ = new AddBinaryNode($1, rhs); 
      pool.add($$);
      delete [] $2;
    }
  | STRING
    { $$ = new StrLiteral($1); pool.add($$); delete [] $1; }
	;
listmaker // Used in: opt_listmaker
	: test list_for
    { $$ = $1; }
	| test star_COMMA_test opt_COMMA
	  {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }
      else {
        $$ = $1;
      }
    }
	;
testlist_comp // Used in: pick_yield_expr_testlist_comp
	: test comp_for
    { $$ = $1; }
	| test star_COMMA_test opt_COMMA
	  {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }
      else {
        $$ = $1;
      }
    }
;
lambdef // Used in: test
	: LAMBDA varargslist COLON test
	| LAMBDA COLON test
	;
trailer // Used in: star_trailer
	: LPAR opt_arglist RPAR
    {
      if($2) {
        $2 -> setType(list); 
        $$ = $2; 
      }
      // IS nullptr
      else {
        $$ = new TuplesLiteral();
        pool.add($$);
      }
    }
	| LSQB subscriptlist RSQB
    { $$ = nullptr; }
	| DOT NAME
    { $$ = nullptr; }
	;
subscriptlist // Used in: trailer
	: subscript star_COMMA_subscript COMMA
	| subscript star_COMMA_subscript
	;
star_COMMA_subscript // Used in: subscriptlist, star_COMMA_subscript
	: star_COMMA_subscript COMMA subscript
	| %empty
	;
subscript // Used in: subscriptlist, star_COMMA_subscript
	: DOT DOT DOT
	| test
	| opt_test_only COLON opt_test_only opt_sliceop
	;
opt_test_only // Used in: subscript
	: test
	| %empty
	;
opt_sliceop // Used in: subscript
	: sliceop
	| %empty
	;
sliceop // Used in: opt_sliceop
	: COLON test
	| COLON
	;
exprlist // Used in: del_stmt, for_stmt, list_for, comp_for
	: expr star_COMMA_expr COMMA
	| expr star_COMMA_expr
	;
star_COMMA_expr // Used in: exprlist, star_COMMA_expr
	: star_COMMA_expr COMMA expr
	| %empty
	;
testlist // Used in: expr_stmt, pick_yield_expr_testlist, return_stmt, for_stmt, opt_testlist, yield_expr
	: test star_COMMA_test COMMA
    {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }
      else {
        $$ = $1;
      }
    }
	| test star_COMMA_test
    {
      if($2) {
        $2 -> add_front($1);
        $$ = $2;
      }
      else {
        $$ = $1;
      }
    }
	;
dictorsetmaker // Used in: opt_dictorsetmaker
	: test COLON test pick_for_test_test
    { $$ = nullptr; }
	| test pick_for_test
		{
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>($2);
      if(tuples) {
        tuples -> add_front($1);
        $$ = tuples;
      }
      else {
        $$ = $1;
      }
    }
;
star_test_COLON_test // Used in: star_test_COLON_test, pick_for_test_test
	: star_test_COLON_test COMMA test COLON test
	| %empty
	;
pick_for_test_test // Used in: dictorsetmaker
	: comp_for
	| star_test_COLON_test opt_COMMA
	;
pick_for_test // Used in: dictorsetmaker
	: comp_for
    { $$ = nullptr; }
	| star_COMMA_test opt_COMMA
    { $$ = $1; }
	;
classdef // Used in: decorated, compound_stmt
	: CLASS NAME { ++depthOfClass; } LPAR opt_testlist RPAR COLON suite
    {
      --depthOfClass;
    }
	| CLASS NAME { ++depthOfClass; } COLON suite
    {
      --depthOfClass;
    }
	;
opt_testlist // Used in: classdef
	: testlist
	| %empty
	;
arglist // Used in: opt_arglist
	: star_argument_COMMA pick_argument
		{
      if($1) {
        if($2) {
          $1 -> add_back($2);
          $$ = $1;
        }
        else
          $$ = $1;
      }
      else {
        // XXX: return of arglist must be a list!
        $$ = new TuplesLiteral($2);
        pool.add($$);
      }
    }
	;
star_argument_COMMA // Used in: arglist, star_argument_COMMA
	: star_argument_COMMA argument COMMA
    {
      if($1) {
        $1 -> add_back($2);
        $$ = $1;
      }
      else {
        $$ = new TuplesLiteral($2);
        pool.add($$);
      }
    }
	| %empty
    { $$ = nullptr; }
	;
star_COMMA_argument // Used in: star_COMMA_argument, pick_argument
	: star_COMMA_argument COMMA argument
	| %empty
	;
opt_DOUBLESTAR_test // Used in: pick_argument
	: COMMA DOUBLESTAR test
	| %empty
	;
pick_argument // Used in: arglist
	: argument opt_COMMA
    { $$ = $1; } 
	| STAR test star_COMMA_argument opt_DOUBLESTAR_test
    { $$ = nullptr; }
	| DOUBLESTAR test
    { $$ = nullptr; }
	;
argument // Used in: star_argument_COMMA, star_COMMA_argument, pick_argument
	: test opt_comp_for
    { $$ = $1; }
	| test EQUAL test
    { $$ = nullptr; }
	;
opt_comp_for // Used in: argument
	: comp_for
	| %empty
	;
list_iter // Used in: list_for, list_if
	: list_for
	| list_if
	;
list_for // Used in: listmaker, list_iter
	: FOR exprlist IN testlist_safe list_iter
	| FOR exprlist IN testlist_safe
	;
list_if // Used in: list_iter
	: IF old_test list_iter
	| IF old_test
	;
comp_iter // Used in: comp_for, comp_if
	: comp_for
	| comp_if
	;
comp_for // Used in: testlist_comp, pick_for_test_test, pick_for_test, opt_comp_for, comp_iter
	: FOR exprlist IN or_test comp_iter
	| FOR exprlist IN or_test
	;
comp_if // Used in: comp_iter
	: IF old_test comp_iter
	| IF old_test
	;
testlist1 // Used in: atom, testlist1
	: test
    { $$ = $1; }
	| testlist1 COMMA test
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>($1);
      if(tuples) {
        tuples -> add_back($3);
        $$ = tuples;
      }
      else {
        tuples = new TuplesLiteral($3);
        $$ = tuples;
        pool.add($$);
      }
    }
	;
yield_expr // Used in: pick_yield_expr_testlist, yield_stmt, pick_yield_expr_testlist_comp
	: YIELD testlist
	| YIELD
	;
star_DOT // Used in: pick_dotted_name, star_DOT
	: star_DOT DOT
	| %empty
	;

%%
#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}

