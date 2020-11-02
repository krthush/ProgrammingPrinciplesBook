//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This program implements a basic expression calculator. 

    Input from cin; output to cout. 
    
    The grammar for input is: 

    Calculation: 
        Statement 
        Print 
        Quit 
        Calculation Statement 
        
    Statement: 
        Declaration 
        Expression 
        
    Declaration: 
        "let" Name "=" Expression

    Print: 
        ;

    Quit: 
        q

    Expression: 
        Term 
        Expression + Term 
        Expression – Term 
        
    Term: 
        Primary 
        Term * Primary 
        Term / Primary 
        Term % Primary 
        
    Primary: 
        Number ( Expression ) 
        – Primary 
        + Primary 
        
    Number: 
        floating-point-literal 
    
    Input comes from cin through the Token_stream called ts.
*/

#include "../../../std_lib_facilities.h"

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token() :kind{ 0 } {} // default constructor 
    Token(char ch) :kind{ ch } { } // initialize kind with ch 
    Token(char ch, double val) :kind{ ch }, value{ val } { } // initialize kind and value 
    Token(char ch, string n) :kind{ ch }, name{ n } { } // initialize kind and name
};

class Variable { 
public: 
    string name; 
    double value; 
};

const char number = '8'; // t.kind==number means that t is a number Token
const char quit = 'q'; // t.kind==quit means that t is a quit Token 
const char print = ';'; // t.kind==print means that t is a print Token
const char name = 'a'; // name token 
const char let = 'L'; // declaration token 
const string declkey = "let"; // declaration keyword
const string prompt = "> "; 
const string result = "= "; // used to indicate that what follows is a result

//------------------------------------------------------------------------------
/*
Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}
*/
//------------------------------------------------------------------------------

class Token_stream {
public:
    Token get();            // get a Token
    void putback(Token t);  // put a Token back
    void ignore(char c); // discard characters up to and including a c
private:
    bool full{ false };      // is there a Token in the buffer?
    Token buffer = { '0' };           // where we store a 'putback' Token
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
{
    if (full) { // check if we already have a Token ready
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:       // for "print"
    case quit:       // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
        return Token{ ch };   // let each character represent itself
    case '.': // a floating-point-literal can start with a dot
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val;
        return Token{ number, val }; // read a floating-point number
    }
    default:
        if (isalpha(ch)) {
            string s; 
            s += ch; 
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; 
            cin.putback(ch);
            if (s == declkey)
                return Token{ let }; // declaration keyword 
            return Token{name,s}; 
        } 
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c) // c represents the kind of Token 
{ 
    // first look in buffer: 
    if (full && c==buffer.kind) { 
        full = false; 
        return; 
    } 
    full = false; 
    
    // now search input: 
    char ch = 0; 
    while (cin>>ch) 
        if (ch==c) return; 
}

//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s) // return the value of the Variable named s 
{
    for (const Variable& v : var_table)
        if (v.name == s)
            return v.value;
    error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

void set_value(string s, double d) // set the Variable named s to d 
{ 
    for (Variable& v : var_table) 
        if (v.name == s) { 
            v.value = d; 
            return; 
        } 
    error("set: undefined variable ", s); 
}

//------------------------------------------------------------------------------

bool is_declared(string var) // is var already in var_table? 
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val) // add {var,val} to var_table 
{ 
    if (is_declared(var)) error(var," declared twice"); 
    var_table.push_back(Variable{var,val}); 
    return val; 
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case name:
    {
        Token next = ts.get();
        if (next.kind == '=') {	// handle name = expression
            double d = expression();
            set_value(t.name, d);
            return d;
        }
        else {
            ts.putback(next);		// not an assignment: return the value
            return get_value(t.name); // return the variable's value
        }
    }
    case number:
        return t.value;  // return the number's value
    case '-': 
        return - primary();
    case '+': 
        return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%': { 
            double d = primary(); 
            if (d == 0) error("%:divide by zero"); 
            left = fmod(left, d); 
            t = ts.get(); 
            break; 
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double declaration() // assume we have seen "let” 
                     // handle: name = expression 
                     // declare a variable called "name” with the initial value "expression” 
{ 
    Token t = ts.get(); 
    if (t.kind != name) error ("name expected in declaration"); 
    string var_name = t.name; 
    
    Token next = ts.get();
    if (next.kind != '=') error("= missing in declaration of ", var_name);
    
    double d = expression();
    define_name(var_name, d); 
    return d;
}

//------------------------------------------------------------------------------

double statement() { 
    Token t = ts.get(); 
    switch (t.kind) { 
    case let: 
        return declaration(); 
    default: 
        ts.putback(t); 
        return expression(); 
    } 
}

//------------------------------------------------------------------------------

void clean_up_mess() // naive 
{ 
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate() {
    while (cin) 
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get(); // eat ‘;’ 
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement() << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << '\n'; // write error message 
        clean_up_mess(); 
    }
}

//------------------------------------------------------------------------------

int main()
try {
    calculate();
    keep_window_open(); // cope with Windows console mode
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------