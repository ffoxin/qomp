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

#ifndef QOMPPLAYLISTMODEL_H
#define QOMPPLAYLISTMODEL_H

#include <QAbstractListModel>

class Tune;

class QompPlayListModel : public QAbstractListModel
{
	Q_OBJECT
public:
	explicit QompPlayListModel(QObject *parent = 0);

	enum QompPlayListModelRole {
		ArtistRole   = Qt::UserRole+1,
		AlbumRole    = Qt::UserRole+2,
		TitleRole    = Qt::UserRole+3,
		TrackRole    = Qt::UserRole+4,
		DurationRole = Qt::UserRole+5,
		URLRole      = Qt::UserRole+6,
		FileRole     = Qt::UserRole+7,
		IsCurrentTuneRole = Qt::UserRole+8,
		CanDownloadRole	= Qt::UserRole+9,
		TuneRole	= Qt::UserRole+10,
		CoverRole	= Qt::UserRole+11,
		BitrateRole	= Qt::UserRole+12,
		DirectURLRole	= Qt::UserRole+13,
		DescriptionRole = Qt::UserRole+14,
		GenreRole	= Qt::UserRole+15
	};

	void addTunes(const QList<Tune*>& tunes);
	Tune *tune(const QModelIndex& index) const;
	Tune* currentTune() const;
	QModelIndex currentIndex() const;
	void setCurrentTune(Tune *tune);
	void removeTune(Tune* tune);
	QModelIndex indexForTune(Tune* tune) const;
	bool allTunesPlayed() const;
	void unsetAllTunesPlayed();

	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;

	virtual Qt::DropActions supportedDropActions() const Q_DECL_OVERRIDE;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
	virtual QStringList mimeTypes() const Q_DECL_OVERRIDE;
	virtual QMimeData *mimeData(const QModelIndexList &indexes) const Q_DECL_OVERRIDE;
	virtual bool canDropMimeData(const QMimeData *data,
	      Qt::DropAction action, int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
	virtual bool dropMimeData(const QMimeData *data,
	     Qt::DropAction action, int row, int column, const QModelIndex &parent) Q_DECL_OVERRIDE;

	void clear();
	void saveState();
	void restoreState();

	void saveTunes(const QString& fileName);
	void loadTunes(const QString& fileName);

	virtual QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

signals:
	void currentTuneChanged(Tune*);
	void totalTimeChanged(uint);

public slots:
	void tuneDataUpdated(Tune* tune);
	void currentTuneTotalTimeChanged(qint64 ms);
#ifdef QOMP_MOBILE
	void move(int oldRow, int newRow);
#endif

private:
	uint totalTime() const;
	void updateTuneTracks();
	void processTunesDrop(int row, const QMimeData *data);
	void processUrilistDrop(int row, const QMimeData *data);

private:
	QList<Tune*> tunes_;
	Tune* currentTune_;
};

#endif // PLAYLISTMODEL_H
