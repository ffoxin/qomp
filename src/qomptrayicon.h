/*
 * Copyright (C) 2013  Khryukin Evgeny
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef QOMPTRAYICON_H
#define QOMPTRAYICON_H

#include <QSystemTrayIcon>
#include <QTime>

class QIcon;
class QompMainWin;
class QompTrayAction;
typedef int QompTrayActionType;

class QompTrayIcon : public QObject
{
	Q_OBJECT
public:
	explicit QompTrayIcon(QompMainWin* parent);

	void setToolTip(const QString& text);
	void setIcon(const QIcon& ico);
	void setContextMenu(QMenu* m);

	void show();

	static QStringList availableActions();
	static QompTrayActionType actionTimeForName(const QString& name);
	
signals:
	void trayContextMenu();
	void trayWheeled(int delta);
	
private slots:
	void trayActivated(QSystemTrayIcon::ActivationReason reason);
	void trayClicked();

protected:
	bool eventFilter(QObject *o, QEvent *e);

private:
	QompTrayAction* actionForType(QompTrayActionType type) const;

private:
	QSystemTrayIcon* icon_;
	QompMainWin* win_;
	QTime lastClick_;
};

#endif // QOMPTRAYICON_H
