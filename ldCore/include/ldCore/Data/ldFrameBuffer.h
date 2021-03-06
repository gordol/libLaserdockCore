/**
    libLaserdockCore
    Copyright(c) 2018 Wicked Lasers

    This file is part of libLaserdockCore.

    libLaserdockCore is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libLaserdockCore is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libLaserdockCore.  If not, see <https://www.gnu.org/licenses/>.
**/

#ifndef LDFRAMEBUFFER_H
#define LDFRAMEBUFFER_H

#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>
#include <QtCore/QObject>

#include "ldCore/ldCore_global.h"
#include "ldCore/Utilities/ldBasicDataStructures.h"

#define FRAMEBUFFER_CAPACITY 4000

class ldFilter;
class ldFilterManager;

class LDCORESHARED_EXPORT ldFrameBuffer : public QObject
{
    Q_OBJECT

public:
    explicit ldFrameBuffer(QObject *parent = 0);
    ~ldFrameBuffer();

    void push(Vertex& val, bool skip_filters = false, bool alter_val = false);
    unsigned int get(Vertex * pbuffer, CompressedSample &pcbuffer, unsigned int size);

    void setFrameModes(int flags);

    void reset();
    void commit();

    void requestMore();

    qint32 getAvailable() const;
    bool isFilled() const;

signals:
    void isCleaned();

private:
    QMutex m_mutex;

    ldFilterManager *m_filterManager = nullptr;
    qint32 m_exhuasted_index = 0;
    qint32 m_fill = 0;
    bool m_isFilled = false;

    std::vector<Vertex> m_buffer;
    std::vector<CompressedSample> m_compressed_buffer;

    int m_frameModes = 0;

};

#endif // LDFRAMEBUFFER_H
