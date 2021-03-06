/*
 * Copyright (C) 2017  Khryukin Evgeny
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

#ifndef TAGHELPERS_H
#define TAGHELPERS_H

#include "libqomp_global.h"

class Tune;

namespace TagLib {
class String;
class File;
class FileRef;
}

namespace Qomp {

LIBQOMPSHARED_EXPORT QString safeTagLibString2QString(const TagLib::String& string);
LIBQOMPSHARED_EXPORT TagLib::FileRef fileName2TaglibRef(const QString& file, bool getAudioProps = true);

LIBQOMPSHARED_EXPORT Tune* tuneFromFile(const QString& file);
LIBQOMPSHARED_EXPORT bool getAudioInfo(const QString& file, qint64* durationMiliSecs, int* bitrate);

LIBQOMPSHARED_EXPORT void loadCover(Tune* tune, TagLib::File* file);

}
#endif // TAGHELPERS_H
