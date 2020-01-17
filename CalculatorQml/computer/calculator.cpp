#include "calculator.h"
#include <QDebug>
#include <QThread>
#include <QTimer>


CalculatorSimulator::CalculatorSimulator(QQueue<StructRequests>& reqQ, QQueue<StructResults>& resQ)
{
	Requests = &reqQ;
	Results = &resQ;
	timer = new QTime();
	busy = false;
	// Где такую чушь разместить?
	m_operationToSymbol[SUM] = '+';
	m_operationToSymbol[DIF] = '-';
	m_operationToSymbol[DIV] = '/';
	m_operationToSymbol[MUL] = '*';

}

void CalculatorSimulator::Init()
{
	qDebug() << "I'm CalculatorPenetrator in new thread" << QThread::currentThreadId();
}

void CalculatorSimulator::SetOperationDelay(int operationCode, int msDelay)
{
	if (operationCode < NUM_OF_OPERATIONS) // Формально
	{
		operationsDelayMs[operationCode] = msDelay;
	}
}

void CalculatorSimulator::ResultHandler()
{
	Results->enqueue(m_resultPack);
	emit CalculationFinished();
	busy = false;
	if (!Requests->isEmpty())
		OperateNewRequest();
}

void CalculatorSimulator::Calculate(StructRequests income)
{
	m_lastErrCode = 0;
	m_lastResult = 0;
	m_resultPack.question = QString::number(income.a) + m_operationToSymbol[income.operationCode] + QString::number(income.b);

// Timeout сделать
	m_lastResult = calcDll.Calculate(income.operationCode, income.a, income.b, m_lastErrCode);

	if (m_lastErrCode)
	{
		m_resultPack.answer =	QString::number(m_lastErrCode);
		m_resultPack.isError = true;
	}
	else
	{
		m_resultPack.answer =	QString::number(m_lastResult);
		m_resultPack.isError = false;
	}


	QTimer::singleShot(operationsDelayMs[income.operationCode], this, SLOT(ResultHandler()));
}

void CalculatorSimulator::OperateNewRequest()
{
	if (Requests->isEmpty())
		return;
	if (busy)
		return;
	busy = true;
	Calculate(Requests->dequeue());
}





