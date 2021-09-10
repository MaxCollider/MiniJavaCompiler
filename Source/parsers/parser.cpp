// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 21 "parsers/parser.y"

    #include "driver.h"
    #include "parsers/location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 54 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 145 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 51: // arguments_any
      case 52: // arguments
        value.YY_MOVE_OR_COPY< Arguments* > (YY_MOVE (that.value));
        break;

      case 67: // class_declaration
      case 68: // main_class
        value.YY_MOVE_OR_COPY< ClassStatement* > (YY_MOVE (that.value));
        break;

      case 69: // class_declarations
        value.YY_MOVE_OR_COPY< Classes* > (YY_MOVE (that.value));
        break;

      case 62: // var_declaration
      case 63: // method_declaration
      case 64: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case 65: // declarations
        value.YY_MOVE_OR_COPY< Declarations* > (YY_MOVE (that.value));
        break;

      case 47: // lvalue
      case 48: // field_invocation
      case 49: // method_invocation
      case 50: // expr
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case 66: // extends
        value.YY_MOVE_OR_COPY< ExtendsStatement* > (YY_MOVE (that.value));
        break;

      case 59: // formal
        value.YY_MOVE_OR_COPY< Formal* > (YY_MOVE (that.value));
        break;

      case 60: // formals_any
      case 61: // formals
        value.YY_MOVE_OR_COPY< Formals* > (YY_MOVE (that.value));
        break;

      case 70: // program
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case 53: // local_var_declaration
      case 54: // statement
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case 55: // statements
        value.YY_MOVE_OR_COPY< Statements* > (YY_MOVE (that.value));
        break;

      case 58: // type
        value.YY_MOVE_OR_COPY< Type* > (YY_MOVE (that.value));
        break;

      case 39: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 40: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 41: // "identifier"
      case 56: // array_type
      case 57: // simple_type
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 51: // arguments_any
      case 52: // arguments
        value.move< Arguments* > (YY_MOVE (that.value));
        break;

      case 67: // class_declaration
      case 68: // main_class
        value.move< ClassStatement* > (YY_MOVE (that.value));
        break;

      case 69: // class_declarations
        value.move< Classes* > (YY_MOVE (that.value));
        break;

      case 62: // var_declaration
      case 63: // method_declaration
      case 64: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case 65: // declarations
        value.move< Declarations* > (YY_MOVE (that.value));
        break;

      case 47: // lvalue
      case 48: // field_invocation
      case 49: // method_invocation
      case 50: // expr
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case 66: // extends
        value.move< ExtendsStatement* > (YY_MOVE (that.value));
        break;

      case 59: // formal
        value.move< Formal* > (YY_MOVE (that.value));
        break;

      case 60: // formals_any
      case 61: // formals
        value.move< Formals* > (YY_MOVE (that.value));
        break;

      case 70: // program
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case 53: // local_var_declaration
      case 54: // statement
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case 55: // statements
        value.move< Statements* > (YY_MOVE (that.value));
        break;

      case 58: // type
        value.move< Type* > (YY_MOVE (that.value));
        break;

      case 39: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 40: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 41: // "identifier"
      case 56: // array_type
      case 57: // simple_type
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 51: // arguments_any
      case 52: // arguments
        value.copy< Arguments* > (that.value);
        break;

      case 67: // class_declaration
      case 68: // main_class
        value.copy< ClassStatement* > (that.value);
        break;

      case 69: // class_declarations
        value.copy< Classes* > (that.value);
        break;

      case 62: // var_declaration
      case 63: // method_declaration
      case 64: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case 65: // declarations
        value.copy< Declarations* > (that.value);
        break;

      case 47: // lvalue
      case 48: // field_invocation
      case 49: // method_invocation
      case 50: // expr
        value.copy< Expression* > (that.value);
        break;

      case 66: // extends
        value.copy< ExtendsStatement* > (that.value);
        break;

      case 59: // formal
        value.copy< Formal* > (that.value);
        break;

      case 60: // formals_any
      case 61: // formals
        value.copy< Formals* > (that.value);
        break;

      case 70: // program
        value.copy< Program* > (that.value);
        break;

      case 53: // local_var_declaration
      case 54: // statement
        value.copy< Statement* > (that.value);
        break;

      case 55: // statements
        value.copy< Statements* > (that.value);
        break;

      case 58: // type
        value.copy< Type* > (that.value);
        break;

      case 39: // "bool"
        value.copy< bool > (that.value);
        break;

      case 40: // "number"
        value.copy< int > (that.value);
        break;

      case 41: // "identifier"
      case 56: // array_type
      case 57: // simple_type
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 51: // arguments_any
      case 52: // arguments
        value.move< Arguments* > (that.value);
        break;

      case 67: // class_declaration
      case 68: // main_class
        value.move< ClassStatement* > (that.value);
        break;

      case 69: // class_declarations
        value.move< Classes* > (that.value);
        break;

      case 62: // var_declaration
      case 63: // method_declaration
      case 64: // declaration
        value.move< Declaration* > (that.value);
        break;

      case 65: // declarations
        value.move< Declarations* > (that.value);
        break;

      case 47: // lvalue
      case 48: // field_invocation
      case 49: // method_invocation
      case 50: // expr
        value.move< Expression* > (that.value);
        break;

      case 66: // extends
        value.move< ExtendsStatement* > (that.value);
        break;

      case 59: // formal
        value.move< Formal* > (that.value);
        break;

      case 60: // formals_any
      case 61: // formals
        value.move< Formals* > (that.value);
        break;

      case 70: // program
        value.move< Program* > (that.value);
        break;

      case 53: // local_var_declaration
      case 54: // statement
        value.move< Statement* > (that.value);
        break;

      case 55: // statements
        value.move< Statements* > (that.value);
        break;

      case 58: // type
        value.move< Type* > (that.value);
        break;

      case 39: // "bool"
        value.move< bool > (that.value);
        break;

      case 40: // "number"
        value.move< int > (that.value);
        break;

      case 41: // "identifier"
      case 56: // array_type
      case 57: // simple_type
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 51: // arguments_any
      case 52: // arguments
        yylhs.value.emplace< Arguments* > ();
        break;

      case 67: // class_declaration
      case 68: // main_class
        yylhs.value.emplace< ClassStatement* > ();
        break;

      case 69: // class_declarations
        yylhs.value.emplace< Classes* > ();
        break;

      case 62: // var_declaration
      case 63: // method_declaration
      case 64: // declaration
        yylhs.value.emplace< Declaration* > ();
        break;

      case 65: // declarations
        yylhs.value.emplace< Declarations* > ();
        break;

      case 47: // lvalue
      case 48: // field_invocation
      case 49: // method_invocation
      case 50: // expr
        yylhs.value.emplace< Expression* > ();
        break;

      case 66: // extends
        yylhs.value.emplace< ExtendsStatement* > ();
        break;

      case 59: // formal
        yylhs.value.emplace< Formal* > ();
        break;

      case 60: // formals_any
      case 61: // formals
        yylhs.value.emplace< Formals* > ();
        break;

      case 70: // program
        yylhs.value.emplace< Program* > ();
        break;

      case 53: // local_var_declaration
      case 54: // statement
        yylhs.value.emplace< Statement* > ();
        break;

      case 55: // statements
        yylhs.value.emplace< Statements* > ();
        break;

      case 58: // type
        yylhs.value.emplace< Type* > ();
        break;

      case 39: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 40: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 41: // "identifier"
      case 56: // array_type
      case 57: // simple_type
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 123 "parsers/parser.y"
                                           { yystack_[1].value.as < Classes* > ()->Add(yystack_[2].value.as < ClassStatement* > ()); yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < Classes* > (), yystack_[2].value.as < ClassStatement* > ()); driver.program = yylhs.value.as < Program* > (); }
#line 948 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 3:
#line 125 "parsers/parser.y"
                           { yylhs.value.as < Classes* > () = new Classes(); }
#line 954 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 4:
#line 126 "parsers/parser.y"
                                           { yystack_[1].value.as < Classes* > ()->Add(yystack_[0].value.as < ClassStatement* > ()); yylhs.value.as < Classes* > () = yystack_[1].value.as < Classes* > (); }
#line 960 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 5:
#line 128 "parsers/parser.y"
                                                                                                    {
        auto tmp = new Declarations();
        tmp->Add(new Method("main", new SimpleType("void"), new Formals(), yystack_[2].value.as < Statements* > ()));
        yylhs.value.as < ClassStatement* > () = new ClassStatement(yystack_[11].value.as < std::string > (), new ExtendsStatement(), tmp);
    }
#line 970 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 6:
#line 134 "parsers/parser.y"
                                                                     { yylhs.value.as < ClassStatement* > () = new ClassStatement(yystack_[4].value.as < std::string > (), yystack_[3].value.as < ExtendsStatement* > (), yystack_[1].value.as < Declarations* > ()); }
#line 976 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 7:
#line 136 "parsers/parser.y"
                { yylhs.value.as < ExtendsStatement* > () = new ExtendsStatement(); }
#line 982 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 8:
#line 137 "parsers/parser.y"
                             { yylhs.value.as < ExtendsStatement* > () = new ExtendsStatement(yystack_[0].value.as < std::string > ()); }
#line 988 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 9:
#line 139 "parsers/parser.y"
                     { yylhs.value.as < Declarations* > () = new Declarations(); }
#line 994 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 10:
#line 140 "parsers/parser.y"
                               { yystack_[1].value.as < Declarations* > ()->Add(yystack_[0].value.as < Declaration* > ()); yylhs.value.as < Declarations* > () = yystack_[1].value.as < Declarations* > (); }
#line 1000 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 11:
#line 142 "parsers/parser.y"
                             { yylhs.value.as < Declaration* > () = yystack_[0].value.as < Declaration* > (); }
#line 1006 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 12:
#line 143 "parsers/parser.y"
                         { yylhs.value.as < Declaration* > () = yystack_[0].value.as < Declaration* > (); }
#line 1012 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 13:
#line 145 "parsers/parser.y"
                                       { yylhs.value.as < Declaration* > () = new VariableDeclaration(yystack_[2].value.as < Type* > (), yystack_[1].value.as < std::string > ()); }
#line 1018 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 14:
#line 147 "parsers/parser.y"
                                                                                  { yylhs.value.as < Declaration* > () = new Method(yystack_[6].value.as < std::string > (), yystack_[7].value.as < Type* > (), yystack_[4].value.as < Formals* > (), yystack_[1].value.as < Statements* > ()); }
#line 1024 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 15:
#line 149 "parsers/parser.y"
                   { yylhs.value.as < Statements* > () = new Statements(); }
#line 1030 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 16:
#line 150 "parsers/parser.y"
                           { yystack_[1].value.as < Statements* > ()->Add(yystack_[0].value.as < Statement* > ()); yylhs.value.as < Statements* > () = yystack_[1].value.as < Statements* > (); }
#line 1036 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 17:
#line 152 "parsers/parser.y"
                { yylhs.value.as < Formals* > () = new Formals(); }
#line 1042 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 18:
#line 153 "parsers/parser.y"
                  { yylhs.value.as < Formals* > () = yystack_[0].value.as < Formals* > (); }
#line 1048 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 19:
#line 155 "parsers/parser.y"
                    { yylhs.value.as < Formals* > () = new Formals(); yylhs.value.as < Formals* > ()->Add(yystack_[0].value.as < Formal* > ()); }
#line 1054 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 20:
#line 156 "parsers/parser.y"
                             { yystack_[2].value.as < Formals* > ()->Add(yystack_[0].value.as < Formal* > ()); yylhs.value.as < Formals* > () = yystack_[2].value.as < Formals* > (); }
#line 1060 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 21:
#line 158 "parsers/parser.y"
                          { yylhs.value.as < Formal* > () = new Formal(yystack_[1].value.as < Type* > (), yystack_[0].value.as < std::string > ()); }
#line 1066 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 22:
#line 160 "parsers/parser.y"
                  { yylhs.value.as < Type* > () = new SimpleType(yystack_[0].value.as < std::string > ()); }
#line 1072 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 23:
#line 161 "parsers/parser.y"
                 { yylhs.value.as < Type* > () = new ArrayType(yystack_[0].value.as < std::string > ()); }
#line 1078 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 24:
#line 163 "parsers/parser.y"
                   { yylhs.value.as < std::string > () = "int"; }
#line 1084 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 25:
#line 164 "parsers/parser.y"
                { yylhs.value.as < std::string > () = "boolean"; }
#line 1090 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 26:
#line 165 "parsers/parser.y"
             { yylhs.value.as < std::string > () = "void"; }
#line 1096 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 27:
#line 166 "parsers/parser.y"
                   { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1102 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 28:
#line 168 "parsers/parser.y"
                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1108 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 29:
#line 170 "parsers/parser.y"
                                     { yylhs.value.as < Statement* > () = new AssertStatement(yystack_[2].value.as < Expression* > ()); }
#line 1114 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 30:
#line 171 "parsers/parser.y"
                            { yylhs.value.as < Statement* > () = yystack_[0].value.as < Statement* > (); }
#line 1120 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 31:
#line 172 "parsers/parser.y"
                         { yylhs.value.as < Statement* > () = yystack_[1].value.as < Statements* > (); }
#line 1126 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 32:
#line 173 "parsers/parser.y"
                                  { yylhs.value.as < Statement* > () = new IfStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); }
#line 1132 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 33:
#line 174 "parsers/parser.y"
                                                   { yylhs.value.as < Statement* > () = new IfStatement(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Statement* > (), yystack_[0].value.as < Statement* > ()); }
#line 1138 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 34:
#line 175 "parsers/parser.y"
                                     { yylhs.value.as < Statement* > () = new WhileStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); }
#line 1144 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 35:
#line 176 "parsers/parser.y"
                                            { yylhs.value.as < Statement* > () = new PrintlnFunction(yystack_[2].value.as < Expression* > ()); }
#line 1150 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 36:
#line 177 "parsers/parser.y"
                          { yylhs.value.as < Statement* > () = new AssignmentOperator(yystack_[3].value.as < Expression* > (), yystack_[1].value.as < Expression* > ()); }
#line 1156 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 37:
#line 178 "parsers/parser.y"
                        { yylhs.value.as < Statement* > () = new ReturnStatement(yystack_[1].value.as < Expression* > ()); }
#line 1162 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 38:
#line 179 "parsers/parser.y"
                            { yylhs.value.as < Statement* > () = new ExpressionStatement(yystack_[1].value.as < Expression* > ()); }
#line 1168 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 39:
#line 181 "parsers/parser.y"
                                       { yylhs.value.as < Statement* > () = new LocalVariableDeclaration(yystack_[0].value.as < Declaration* > ()); }
#line 1174 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 40:
#line 183 "parsers/parser.y"
                                                           { yylhs.value.as < Expression* > () = new MethodInvocation(yystack_[5].value.as < Expression* > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < Arguments* > ()); }
#line 1180 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 41:
#line 184 "parsers/parser.y"
                                                { yylhs.value.as < Expression* > () = new MethodInvocation(new ThisExpression(), yystack_[3].value.as < std::string > (), yystack_[1].value.as < Arguments* > ()); }
#line 1186 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 42:
#line 186 "parsers/parser.y"
                  { yylhs.value.as < Arguments* > () = new Arguments(); }
#line 1192 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 43:
#line 187 "parsers/parser.y"
                    { yylhs.value.as < Arguments* > () = yystack_[0].value.as < Arguments* > (); }
#line 1198 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 44:
#line 189 "parsers/parser.y"
                    { yylhs.value.as < Arguments* > () = new Arguments(); yylhs.value.as < Arguments* > ()->Add(yystack_[0].value.as < Expression* > ()); }
#line 1204 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 45:
#line 190 "parsers/parser.y"
                             { yystack_[2].value.as < Arguments* > ()->Add(yystack_[0].value.as < Expression* > ()); yylhs.value.as < Arguments* > () = yystack_[2].value.as < Arguments* > (); }
#line 1210 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 46:
#line 192 "parsers/parser.y"
                                          { yylhs.value.as < Expression* > () = new ThisField(yystack_[0].value.as < std::string > ()); }
#line 1216 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 47:
#line 193 "parsers/parser.y"
                                           { yylhs.value.as < Expression* > () = new IndexationOperator(new ThisField(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < Expression* > ()); }
#line 1222 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 48:
#line 195 "parsers/parser.y"
                     { yylhs.value.as < Expression* > () = new VariableReference(yystack_[0].value.as < std::string > ()); }
#line 1228 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 49:
#line 196 "parsers/parser.y"
                                { yylhs.value.as < Expression* > () = new IndexationOperator(new VariableReference(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < Expression* > ()); }
#line 1234 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 50:
#line 197 "parsers/parser.y"
                       { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1240 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 51:
#line 200 "parsers/parser.y"
               { yylhs.value.as < Expression* > () = new NegationOperator(yystack_[0].value.as < Expression* > ()); }
#line 1246 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 52:
#line 201 "parsers/parser.y"
                     { yylhs.value.as < Expression* > () = new AndOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1252 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 53:
#line 202 "parsers/parser.y"
                     { yylhs.value.as < Expression* > () = new OrOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1258 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 54:
#line 203 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new LessOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1264 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 55:
#line 204 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new GreaterOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1270 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 56:
#line 205 "parsers/parser.y"
                     { yylhs.value.as < Expression* > () = new EqualityOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1276 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 57:
#line 206 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new AdditionOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1282 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 58:
#line 207 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new SubtractionOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1288 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 59:
#line 208 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new MultiplicationOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1294 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 60:
#line 209 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new DivisionOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1300 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 61:
#line 210 "parsers/parser.y"
                    { yylhs.value.as < Expression* > () = new ModuloOperator(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1306 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 62:
#line 211 "parsers/parser.y"
                        { yylhs.value.as < Expression* > () = new IndexationOperator(yystack_[3].value.as < Expression* > (), yystack_[1].value.as < Expression* > ()); }
#line 1312 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 63:
#line 212 "parsers/parser.y"
                        { yylhs.value.as < Expression* > () = new LengthOperator(yystack_[2].value.as < Expression* > ()); }
#line 1318 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 64:
#line 213 "parsers/parser.y"
                                     { yylhs.value.as < Expression* > () = new AllocateStatement(new ArrayType(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < Expression* > ()); }
#line 1324 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 65:
#line 214 "parsers/parser.y"
                                { yylhs.value.as < Expression* > () = new AllocateStatement(new SimpleType(yystack_[2].value.as < std::string > ())); }
#line 1330 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 66:
#line 215 "parsers/parser.y"
               { yylhs.value.as < Expression* > () = new NotOperator(yystack_[0].value.as < Expression* > ()); }
#line 1336 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 67:
#line 216 "parsers/parser.y"
                   { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1342 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 68:
#line 217 "parsers/parser.y"
                   { yylhs.value.as < Expression* > () = new VariableReference(yystack_[0].value.as < std::string > ()); }
#line 1348 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 69:
#line 218 "parsers/parser.y"
               { yylhs.value.as < Expression* > () = new NumberLiteral(yystack_[0].value.as < int > ()); }
#line 1354 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 70:
#line 219 "parsers/parser.y"
             { yylhs.value.as < Expression* > () = new ThisExpression(); }
#line 1360 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 71:
#line 220 "parsers/parser.y"
             { yylhs.value.as < Expression* > () = new BooleanLiteral(yystack_[0].value.as < bool > ()); }
#line 1366 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 72:
#line 221 "parsers/parser.y"
                        { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1372 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;

  case 73:
#line 222 "parsers/parser.y"
                       { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1378 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"
    break;


#line 1382 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -131;

  const signed char parser::yytable_ninf_ = -51;

  const short
  parser::yypact_[] =
  {
     -20,   -32,  -131,    16,     2,     5,  -131,     8,  -131,     0,
    -131,    11,    14,    20,    12,    30,    31,  -131,  -131,    51,
      -1,    52,  -131,  -131,  -131,  -131,   -10,  -131,  -131,    47,
      29,  -131,  -131,  -131,    54,    32,    53,    56,  -131,    61,
    -131,  -131,   104,   -10,    65,    65,    65,  -131,    59,   -10,
      60,    66,    65,    69,    75,    78,  -131,  -131,     1,   109,
     110,    95,   438,  -131,  -131,  -131,    83,  -131,    72,   116,
    -131,  -131,  -131,   103,   438,   229,   133,  -131,    10,    85,
      65,   248,    65,    65,    65,    65,    65,  -131,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    -6,
    -131,   -10,   117,  -131,  -131,   119,    65,    17,   267,  -131,
     286,   305,   324,   343,   362,   103,   103,     6,     6,     6,
      81,    81,    81,   457,   457,   381,   118,  -131,  -131,  -131,
    -131,   400,    65,    65,   127,   130,   191,   191,  -131,  -131,
    -131,    65,   162,  -131,   438,    94,   136,   419,  -131,  -131,
     122,  -131,   138,  -131,    65,  -131,  -131,   191,  -131,   438,
    -131
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     3,     0,     0,     0,     1,     0,     2,     0,
       4,     0,     7,     0,     0,     0,     0,     8,     9,     0,
       0,     0,     6,    24,    25,    26,     0,    27,    23,    22,
       0,    11,    12,    10,     0,     0,     0,     0,    15,     0,
      28,    13,     0,    17,     0,     0,     0,    15,     0,     0,
      70,     0,     0,     0,     0,     0,    71,    69,    68,     0,
      73,    72,     0,    30,    16,    39,     0,    19,    18,     0,
      68,    73,    72,    51,    66,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,    67,    31,     0,     0,    46,     0,    37,
       0,     0,     0,     0,     0,    58,    57,    59,    60,    61,
      54,    55,    56,    52,    53,     0,     0,    63,    20,    15,
      65,     0,    42,     0,     0,     0,     0,     0,    49,    36,
      62,    42,     0,    64,    44,    43,     0,     0,    29,    35,
      32,    34,     0,    14,     0,    41,    47,     0,    40,    45,
      33
  };

  const short
  parser::yypgoto_[] =
  {
    -131,  -131,   -42,   -40,   -34,  -131,    21,  -131,  -130,   -46,
    -131,   106,   -23,    62,  -131,  -131,   141,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    59,    71,    72,    62,   145,   146,    63,    64,    42,
      28,    29,    30,    67,    68,    69,    65,    32,    33,    20,
      15,    10,     2,     5,     3
  };

  const short
  parser::yytable_[] =
  {
      60,    76,    61,    35,   -48,     8,   150,   151,     1,     4,
      73,    74,    75,    23,    24,    25,     6,    22,    81,     7,
      66,    85,    23,    24,    25,   105,    98,   160,    99,    26,
     106,    27,   132,     9,    60,   126,    61,   133,    11,   127,
      27,    12,   -27,    14,    13,    16,   108,    18,   110,   111,
     112,   113,   114,    17,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    19,    21,    36,    34,    44,
      37,    38,   131,    39,    40,    41,    43,    77,    66,    45,
      46,    80,    79,   142,    82,    88,    89,    90,    91,    92,
      83,    49,    50,    84,    60,    60,    61,    61,   144,   147,
      60,    98,    61,    99,    56,    57,    70,   144,    44,    90,
      91,    92,    86,   -50,    87,    60,   101,    61,    45,    46,
     159,    47,    48,    98,   100,    99,   107,    23,    24,    25,
      49,    50,   102,   141,   129,   130,    51,    44,   154,    52,
      53,    54,    55,    56,    57,    58,   148,    45,    46,   149,
      47,   104,   155,   157,   158,    78,    23,    24,    25,    49,
      50,    31,   152,   128,     0,    51,    44,     0,    52,    53,
      54,    55,    56,    57,    58,     0,    45,    46,     0,    47,
     153,     0,     0,     0,     0,    23,    24,    25,    49,    50,
       0,     0,     0,     0,    51,    44,     0,    52,    53,    54,
      55,    56,    57,    58,     0,    45,    46,     0,    47,     0,
       0,     0,     0,     0,    23,    24,    25,    49,    50,     0,
       0,     0,     0,    51,     0,     0,    52,    53,    54,    55,
      56,    57,    58,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,     0,   103,     0,     0,     0,    98,
       0,    99,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,   109,    98,     0,
      99,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,   134,     0,     0,     0,    98,     0,    99,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,     0,   135,     0,     0,     0,    98,     0,    99,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
       0,   136,     0,     0,     0,    98,     0,    99,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,     0,
     137,     0,     0,     0,    98,     0,    99,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,   138,    99,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,   139,    98,     0,    99,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,   140,    99,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,   143,    99,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
     156,    99,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,     0,
      99,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,    99
  };

  const short
  parser::yycheck_[] =
  {
      42,    47,    42,    26,     3,     0,   136,   137,    28,    41,
      44,    45,    46,    23,    24,    25,     0,    18,    52,    17,
      43,    20,    23,    24,    25,    15,    20,   157,    22,    30,
      20,    41,    15,    28,    76,    41,    76,    20,    30,    45,
      41,    41,    41,    29,    33,    25,    80,    17,    82,    83,
      84,    85,    86,    41,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    34,    15,    20,    16,     4,
      41,    17,   106,    41,    21,    19,    15,    18,   101,    14,
      15,    15,    22,   129,    15,     4,     5,     6,     7,     8,
      15,    26,    27,    15,   136,   137,   136,   137,   132,   133,
     142,    20,   142,    22,    39,    40,    41,   141,     4,     6,
       7,     8,     3,     3,    19,   157,    44,   157,    14,    15,
     154,    17,    18,    20,    41,    22,    41,    23,    24,    25,
      26,    27,    16,    15,    17,    16,    32,     4,    44,    35,
      36,    37,    38,    39,    40,    41,    19,    14,    15,    19,
      17,    18,    16,    31,    16,    49,    23,    24,    25,    26,
      27,    20,   141,   101,    -1,    32,     4,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    14,    15,    -1,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    32,     4,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,
      -1,    22,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      22,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,    -1,    -1,    20,    -1,    22,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    -1,    -1,    -1,    20,    -1,    22,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    22,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      22,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22
  };

  const signed char
  parser::yystos_[] =
  {
       0,    28,    68,    70,    41,    69,     0,    17,     0,    28,
      67,    30,    41,    33,    29,    66,    25,    41,    17,    34,
      65,    15,    18,    23,    24,    25,    30,    41,    56,    57,
      58,    62,    63,    64,    16,    58,    20,    41,    17,    41,
      21,    19,    55,    15,     4,    14,    15,    17,    18,    26,
      27,    32,    35,    36,    37,    38,    39,    40,    41,    47,
      48,    49,    50,    53,    54,    62,    58,    59,    60,    61,
      41,    48,    49,    50,    50,    50,    55,    18,    57,    22,
      15,    50,    15,    15,    15,    20,     3,    19,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    20,    22,
      41,    44,    16,    16,    18,    15,    20,    41,    50,    19,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    41,    45,    59,    17,
      16,    50,    15,    20,    16,    16,    16,    16,    21,    19,
      21,    15,    55,    21,    50,    51,    52,    50,    19,    19,
      54,    54,    52,    18,    44,    16,    21,    31,    16,    50,
      54
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    70,    69,    69,    68,    67,    66,    66,    65,
      65,    64,    64,    62,    63,    55,    55,    61,    61,    60,
      60,    59,    58,    58,    57,    57,    57,    57,    56,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    53,
      49,    49,    52,    52,    51,    51,    48,    48,    47,    47,
      47,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     0,     2,    13,     6,     0,     2,     0,
       2,     1,     1,     3,     9,     0,     2,     0,     1,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     5,
       1,     3,     5,     7,     5,     5,     4,     3,     2,     1,
       6,     6,     0,     1,     1,     3,     3,     6,     1,     4,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     5,     4,     2,     3,     1,     1,
       1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"%\"", "\"<\"", "\">\"", "\"==\"", "\"&&\"",
  "\"||\"", "\"!\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\";\"", "\"[\"",
  "\"]\"", "\".\"", "\"int\"", "\"boolean\"", "\"void\"", "\"new\"",
  "\"this\"", "\"class\"", "\"extends\"", "\"public\"", "\"else\"",
  "\"assert\"", "\"static\"", "\"main\"", "\"return\"",
  "\"System.out.println\"", "\"if\"", "\"while\"", "\"bool\"",
  "\"number\"", "\"identifier\"", "\"<=\"", "\">=\"", "\",\"",
  "\"length\"", "$accept", "lvalue", "field_invocation",
  "method_invocation", "expr", "arguments_any", "arguments",
  "local_var_declaration", "statement", "statements", "array_type",
  "simple_type", "type", "formal", "formals_any", "formals",
  "var_declaration", "method_declaration", "declaration", "declarations",
  "extends", "class_declaration", "main_class", "class_declarations",
  "program", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   123,   123,   125,   126,   128,   134,   136,   137,   139,
     140,   142,   143,   145,   147,   149,   150,   152,   153,   155,
     156,   158,   160,   161,   163,   164,   165,   166,   168,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   181,
     183,   184,   186,   187,   189,   190,   192,   193,   195,   196,
     197,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1940 "/home/maxim/Desktop/work/compiler-checkpoint_2/Source/parsers/parser.cpp"

#line 224 "parsers/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
