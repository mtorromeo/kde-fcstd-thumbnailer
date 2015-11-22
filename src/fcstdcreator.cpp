/*
 * Copyright (C)
 * 	 2015 Stefan Hamminga <stefan@prjct.net>
 *   2012 Yorik van Havre <yorik@uncreated.net>
 *   2010 Ariel Constenla-Haile <ariel.constenla.haile@gmail.com>
 *
 * This file is part of Fcstd Thumbnail Creator.
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenDocument Thumbnail Creator.  If not, see
 * <http://www.gnu.org/licenses/> for a copy of the LGPLv3 License.
 */

#include "fcstdcreator.h"

#include <kzip.h>

#include <QImage>
#include <QPainter>

extern "C"
{
    Q_DECL_EXPORT ThumbCreator *new_creator() {
        return new FcstdCreator();
    }
}

FcstdCreator::FcstdCreator() { }

FcstdCreator::~FcstdCreator() { }

bool FcstdCreator::create(const QString &path, int w, int h, QImage &img) {
    Q_UNUSED(w);
    Q_UNUSED(h);

    bool bRet = false;
    KZip zip(path);
    if (zip.open(QIODevice::ReadOnly)) {
        const KArchiveDirectory* dir = zip.directory();
        const KArchiveEntry* entry = dir->entry ("thumbnails/Thumbnail.png");

        if ( (entry != NULL) && (entry->isFile())) {
            const KArchiveFile* file = (KArchiveFile*)entry;
            QByteArray data(file->data());

            if (data.size() > 0) {
                img.loadFromData(data, "PNG");
                if (!img.isNull()) {
                    //TODO: Check if this is really needed
                    // if (img.hasAlphaChannel()) {
                    //     QImage i = img.convertToFormat(QImage::Format_RGB32);
                    //     img.swap(i);
                    // }
                    bRet = true;
                }
            }
        }
    }
    zip.close();
    return bRet;
}

ThumbCreator::Flags FcstdCreator::flags() const {
    // FreeCAD already overlays a logo (TODO: file bug report about that)
    // return (Flags)(DrawFrame | BlendIcon);
    return None;
}
