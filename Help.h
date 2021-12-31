#pragma once

#include <QWidget>
#include <QDialog>
#include "ui_Help.h"

class Help : public QDialog
{
	Q_OBJECT
public:
	Help(QWidget *parent = Q_NULLPTR);
	~Help();
protected:
	virtual void closeEvent(QCloseEvent* event);
signals:
	void backToMain();
private:
	Ui::Help ui;
};
