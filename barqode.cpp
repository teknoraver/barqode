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
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QTimer>
#include <QFileDialog>


#include "barqode.h"

BarQode::BarQode() : QMainWindow(0)
{
	setupUi(this);
	connect(actionAbout, SIGNAL(triggered()), SLOT(about()));
	connect(message, SIGNAL(textChanged()), SLOT(textChanged()));
	connect(zoom, SIGNAL(valueChanged(int)), SLOT(textChanged()));
	connect(save, SIGNAL(clicked()), SLOT(saveSlot()));
	enc = dmtxEncodeCreate();
	enc->pixelPacking = DmtxPack24bppRGB;
	last.start();
	textChanged();
}

BarQode::~BarQode()
{
	dmtxEncodeDestroy(&enc);
}

void BarQode::textChanged()
{
	if(last.elapsed() < 100) {
		QTimer::singleShot(100, this, SLOT(textChanged()));
		return;
	}
	QString qmsg = message->toPlainText();
	if(qmsg.isEmpty())
		qmsg = "http://teknoraver.net/";
	const char *msg = qmsg.toUtf8().constData();
	enc->moduleSize = zoom->value();
	enc->marginSize = enc->moduleSize;
	if(!dmtxEncodeDataMatrix(enc, strlen(msg), (unsigned char*)msg)) {
		QTimer::singleShot(100, this, SLOT(textChanged()));
		return;
	}
	DmtxImage *img = enc->image;
	const int w = img->width, h = img->height;
	QPixmap code(w, h);
	code.fill(Qt::white);

	QPainter painter(&code);
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			if(!img->pxl[i * 3 * w + j * 3])
				painter.drawPoint(j, i);
	image->setPixmap(code);
	last.start();
}

void BarQode::saveSlot()
{
	QString path = QFileDialog::getSaveFileName(this, QString(), QString(), "PNG Images (*.png)");
	if(path.length()) {
		image->pixmap()->toImage().convertToFormat(QImage::Format_Mono).save(path);
		QMessageBox::information(this, "Saved", "DataMatrix saved to " + path);
	}
}

void BarQode::about()
{
	QIcon old = windowIcon();
	setWindowIcon(QIcon(":/matteo.png"));
	QMessageBox::about(this, "About BarQode", "BarQode - a DataMatrix tool<br>by Matteo Croce <a href=\"http://teknoraver.net/\">http://teknoraver.net/</a>");
	setWindowIcon(old);
}
