/****************************************************************************
 *  BarQode - a DataMatrix tool                                             *
 *  Copyright (C) 2009  Matteo Croce <rootkit85@yahoo.it>                   *
 *                                                                          *
 *  This program is free software: you can redistribute it and/or modify    *
 *  it under the terms of the GNU General Public License as published by    *
 *  the Free Software Foundation, either version 3 of the License, or       *
 *  (at your option) any later version.                                     *
 *                                                                          *
 *  This program is distributed in the hope that it will be useful,         *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *  GNU General Public License for more details.                            *
 *                                                                          *
 *  You should have received a copy of the GNU General Public License       *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

#ifndef BARQODE_H
#define BARQODE_H

#include <dmtx.h>
#include <QMainWindow>
#include <QTime>

#include "ui_barqodewidget.h"

class BarQode: public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT

public:
	BarQode();
	~BarQode();

private slots:
	void about();
	void textChanged();
	void saveSlot();

private:
	QTime last;
	DmtxEncode *enc;
};

#endif
