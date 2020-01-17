#include "externcalculations.h"


ExternCalculations::ExternCalculations()
{
}

double ExternCalculations::Calculate(int operationNum, double A, double B, int &errorCode)
{
	double result;
	try
	{
		switch (operationNum)
		{
		case SUM:
			result = A + B;
			break;

		case DIF:
			result = A - B;
			break;

		case DIV:
			if (B == 0) throw 101;
			result = A / B;
		break;

		case MUL:
			result = A * B;
			break;
		}
		errorCode = 0;

	}
	catch (int err)
	{
		errorCode = err;
	}

	return result;
}
