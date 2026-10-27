// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2009 Matteo Croce <rootkit85@yahoo.it>

#include <QApplication>
#include "barqode.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BarQode qfm;
	qfm.show();
	return a.exec();
}
