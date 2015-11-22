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

#ifndef _FCSTD_CREATOR_H_
#define _FCSTD_CREATOR_H_

#include <QObject>
#include <kio/thumbcreator.h>

class FcstdCreator : public QObject, public ThumbCreator
{
    Q_OBJECT
public:
    FcstdCreator();
    virtual ~FcstdCreator();
    virtual bool create(const QString &path, int w, int h, QImage &thumb);
    virtual Flags flags() const;
};

#endif // _FCSTD_CREATOR_H_
