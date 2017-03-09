/*
 * windowheader.cpp
 * Copyright (C) 2010, 2017  Khryukin Evgeny, Vitaly Tonkacheyev
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */


#ifndef PSIWINDOWHEADER_H
#define PSIWINDOWHEADER_H

#include "ui_windowheader.h"

#include <QToolButton>
#include <QMouseEvent>
#include <QRect>

class WindowHeader : public QWidget
{
	Q_OBJECT
public:
	WindowHeader(QWidget* p);
	~WindowHeader();

private:
	Ui::WindowHeader ui_;
	QWidget *parent_;
	QPoint movepath;
	bool isDrag;
	bool isResize;
	bool inVRect;
	bool inLDRect;
	bool inRDRect;
	bool maximized;
	QRect oldSize;
	QSize defaultSize;
	void mouseEnterEvent(const int mouse_x, const int mouse_y, const QRect &geom);

private slots:
	void hidePressed();
	void closePressed();
	void maximizePressed();

protected:
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);

};

#endif // PSIWINDOWHEADER_H
