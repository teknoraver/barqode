// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2009 Matteo Croce <rootkit85@yahoo.it>

#ifndef BARQODE_H
#define BARQODE_H

#include <dmtx.h>
#include <QMainWindow>
#include <QElapsedTimer>

#include "ui_barqodewidget.h"

class BarQode: public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT

public:
	BarQode();
	~BarQode() override;

private slots:
	void about();
	void textChanged();
	void saveSlot();

private:
	QElapsedTimer last;
	DmtxEncode *enc;
};

#endif
