#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QWidget>
#include <QQueue>
#include <QTime>
#include "../externCalculations/externcalculations.h"
#include "common.h"




class CalculatorSimulator : public QObject
{
	Q_OBJECT
public:
	explicit CalculatorSimulator(QQueue<StructRequests>&, QQueue<StructResults>&);
private:
	ExternCalculations calcDll;
	bool	busy;
	double	m_lastResult;
	int		m_lastErrCode;
	QMap<int, char> m_operationToSymbol;
	StructResults	m_resultPack;
	StructRequests	m_requestPack;
	QQueue<StructRequests>	*Requests;
	QQueue<StructResults>	*Results;
	int		operationsDelayMs[NUM_OF_OPERATIONS]{0,0,0,0};
	QTime	*timer;


signals:
	void CalculationFinished();
private slots:
	void ResultHandler();
	void Calculate(StructRequests);


public slots:
	void SetOperationDelay (int operationCode, int msDelay);
	void OperateNewRequest();
	void Init();

};

#endif // CALCULATOR_H
