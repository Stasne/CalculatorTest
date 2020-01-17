#ifndef EXTERNCALCULATIONS_H
#define EXTERNCALCULATIONS_H

#include "externcalculations_global.h"

class EXTERNCALCULATIONSSHARED_EXPORT ExternCalculations
{

public:
	ExternCalculations();
	double Calculate(int operationNum, double A, double B, int &errorCode);
private:
	enum {
		SUM = 0,
		DIF = 1,
		DIV = 2,
		MUL = 3
	};
};

#endif // EXTERNCALCULATIONS_H
