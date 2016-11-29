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

#ifndef QOPMPLAYER_H
#define QOPMPLAYER_H

#include <QObject>

#include "common.h"
#include "libqomp_global.h"

class QompMetaDataResolver;
class Tune;

class LIBQOMPSHARED_EXPORT QompPlayer : public QObject
{
	Q_OBJECT
public:
	Tune* currentTune() const;

	void resolveMetadata(const QList<Tune*> &tunes);
	Qomp::State lastAction() const;

	virtual void setVolume(qreal vol) = 0;
	/**
	 * Volume from 0 to 1
	 **/
	virtual qreal volume() const = 0;
	virtual void setMute(bool mute) = 0;
	virtual bool isMuted() const = 0;
	virtual void setPosition(qint64 pos) = 0;
	/**
	 * Position in miliseconds
	 */
	virtual qint64 position() const = 0;

	virtual Qomp::State state() const = 0;
	virtual void play();
	virtual void pause();
	virtual void stop();
	virtual qint64 currentTuneTotalTime() const = 0;

	virtual QStringList audioOutputDevice() const = 0;
	virtual void setAudioOutputDevice(const QString& devName) = 0;
	virtual QString defaultAudioDevice() const = 0;

public slots:
	void setTune(Tune* tune);

protected slots:
	virtual void doSetTune() = 0;
	
signals:
	void currentPositionChanged(qint64 pos);
	void currentTuneTotalTimeChanged(qint64 time);
	void stateChanged(Qomp::State newState);
	void mediaFinished();
	void volumeChanged(qreal newVolume);
	void mutedChanged(bool muted);
	void tuneChanged(Tune*);
	void mediaReady();

	void tuneDataUpdated(Tune*);

protected:
	QompPlayer();

	virtual QompMetaDataResolver* metaDataResolver() const { return 0; }

private:
	Tune* currentTune_;
	Qomp::State lastAction_;
};

#endif // QOPMPLAYER_H
