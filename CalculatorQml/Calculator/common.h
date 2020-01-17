#ifndef COMMON
#define COMMON
#include <QString>
#include <QMap>
struct StructRequests
{
	int operationCode;
	double a;
	double b;
	StructRequests(int opCode=0, double operandA=0, double operandB=0)
	{
		operationCode = opCode;
		a = operandA;
		b = operandB;
	}
};

struct StructResults
{
	QString question;
	QString answer;
	bool isError;
	StructResults(QString q = QString(""), QString a = QString(""), bool err = false)
	{
		question = q;
		answer = a;
		isError = err;
	}
};

enum {NUM_OF_OPERATIONS = 4};
enum {
	SUM = 0,
	DIF = 1,
	DIV = 2,
	MUL = 3
	};

#endif // COMMON

