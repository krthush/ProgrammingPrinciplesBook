
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../../../std_lib_facilities.h"

/*

	Note that the calculator uses the following grammar for its calculate() function

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


*/

struct Token { // Used to store input from cin in a standardized format
	char kind;
	double value; // For number values
	string name; // For variable names
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) { }
};

class Token_stream { // Used to allow easier manipulation of iostream from cin
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }
	Token get(); // get token from cin
	void unget(Token t); // return recently get() token back into stream
	void ignore(char); // ignore from stream until input char is hit
};

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

const char let = 'L'; // t.kind for declaration token
const char quit = 'Q'; // t.kind for quit token
const char print = ';';
const char number = '8'; // t.kind for a number token
const char name = 'a'; // t.kind for a name token
const char root = 'r'; // t.kind for square root token
const char power = 'p'; // t.kind for pow token
const string prompt = "> ";
const string result = "= ";
// const string declKey = "let";
const string rootKey = "sqrt";
const string quitKey = "exit";
const string powKey = "pow";

Token Token_stream::get()
{
	if (full) { 
		full = false; 
		return buffer; 
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '.':
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
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (ch=='#') { // For one char declarations of #
			return Token(let);
		}
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			// if (s == declKey) return Token(let);
			if (s == quitKey) return Token(quit);
			if (s == rootKey) return Token(root);
			if (s == powKey) return Token(power);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::unget(Token t) {
	if (full) error("unget() into a full buffer");
	buffer = t; 
	full = true; 
}

void Token_stream::ignore(char c) // ignore from cin until char is hit
{
	if (full && c == buffer.kind) { // check buffer first then move to cin 
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	
		double d = expression();

		// Check for closing bracket
		t = ts.get();
		if (t.kind != ')') error("')' expected");

		return d;
	}
	case root:
	{
		// Check for starting bracket
		Token next = ts.get();
		if (next.kind != '(') error("'(' expected");

		double d = expression();

		if (d < 0) error("negative sqaure root attempted");

		d = sqrt(d);

		// Check for closing bracket
		next = ts.get();
		if (next.kind != ')') error("')' expected");

		return d;
	}
	case power:
	{
		// Check for starting bracket
		Token next = ts.get();
		if (next.kind != '(') error("'(' expected");

		double d = expression();

		// Check for comma separator
		next = ts.get();
		if (next.kind != ',') error("',' expected");

		int i = narrow_cast<int>(expression());

		d = pow(d,i);

		// Check for closing bracket
		next = ts.get();
		if (next.kind != ')') error("')' expected");

		return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	
			double d = primary();
			if (d == 0) error("cannot divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate() // get input from user then handle it through grammar functions, starting with statement()
{
	while (true) try {
		cout << prompt;

		// Check for print/quit
		Token t = ts.get(); // tokenize input
		while (t.kind == print) t = ts.get(); // discard prints
		if (t.kind == quit) return; // quit loop/program
		ts.unget(t); // otherwise return token for grammer functions

		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {
	// Add predefined variables
	names.push_back(Variable("k", 1000));

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != print);
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != print);
	return 2;
}