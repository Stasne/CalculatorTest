#ifndef COMPUTER_H
#define COMPUTER_H
#include <QMainWindow>
#include <QThread>
#include <QQueue>
#include <QPoint>
#include <QSize>
#include "calculator.h"
#include "queuecontroller.h"
#include "common.h"


class computer : public QMainWindow
{
	Q_OBJECT

public:
	explicit computer(QWidget *parent = 0);
	~computer();
public slots:


private:	// Логика
	QQueue<StructRequests> Requests;
	QQueue<StructResults> Results;
	QThread *CalculationThread;
	QThread *RequestResultThread;
	CalculatorSimulator *CalculationSimulator;
	QueueController *QueueHandler;
private: // обработка ввода с клавиатуры
	enum
	{
		operandA = 0,
		operation = 1,
		operandB = 2
	};
	int stage=0;
	double a;
	double b;
	int operationCode;
private:	// Окошкино положение
	QSize m_windowSize;
	QPoint m_windowPosition;

protected:
	void keyPressEvent(QKeyEvent *);
	void moveEvent(QMoveEvent *);
	void resizeEvent(QResizeEvent *);
	void closeEvent(QCloseEvent *);
};

#endif // COMPUTER_H
