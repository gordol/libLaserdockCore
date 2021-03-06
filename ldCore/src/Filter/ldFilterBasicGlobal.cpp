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

#include "ldCore/Filter/ldFilterBasicGlobal.h"

#include <math.h>
#include <QtCore/QDebug>
#include "ldCore/Helpers/Color/ldColorUtil.h"


ldFilterBasicGlobal::ldFilterBasicGlobal()
    : ldFilter()
    , m_ttlFilter(new ldTtlFilter())
    , m_colorCurveFilter(new ldColorCurveFilter())
    , m_colorFaderFilter(new ldColorFaderFilter())
    , m_hueFilter(new ldHueFilter())
    , m_hueMatrixFilter(new ldHueMatrixFilter())
    , m_hueShiftFilter(new ldHueShiftFilter())
    , m_soundLevelFilter(new ldSoundLevelFilter())
    , m_tracerFilter(new ldTracerFilter())
{
}

ldFilterBasicGlobal::~ldFilterBasicGlobal()
{
}

void ldFilterBasicGlobal::process(Vertex &v)
{
    if (m_ttlFilter->m_enabled)
        m_ttlFilter->process(v);
    
    if (m_tracerFilter->m_enabled)
        m_tracerFilter->processFilter(v);

    if (m_hueMatrixFilter->m_enabled)
        m_hueMatrixFilter->processFilter(v);

    if(m_hueShiftFilter->m_enabled)
        m_hueShiftFilter->processFilter(v);

    if(m_hueFilter->m_enabled)
        m_hueFilter->processFilter(v);

    if(m_colorCurveFilter->m_enabled)
        m_colorCurveFilter->processFilter(v);

    m_soundLevelFilter->processFilter(v);

    m_colorFaderFilter->processFilter(v);
}

ldTtlFilter *ldFilterBasicGlobal::ttlFilter() const
{
    return m_ttlFilter.get();
}

ldColorCurveFilter *ldFilterBasicGlobal::colorCurveFilter() const
{
    return m_colorCurveFilter.get();
}

ldColorFaderFilter *ldFilterBasicGlobal::colorFaderFilter() const
{
    return m_colorFaderFilter.get();
}

ldHueFilter *ldFilterBasicGlobal::hueFilter() const
{
    return m_hueFilter.get();
}

ldHueMatrixFilter *ldFilterBasicGlobal::hueMatrixFilter() const
{
    return m_hueMatrixFilter.get();
}

ldHueShiftFilter *ldFilterBasicGlobal::hueShiftFilter() const
{
    return m_hueShiftFilter.get();
}

ldTracerFilter *ldFilterBasicGlobal::tracerFilter() const
{
    return m_tracerFilter.get();
}

ldSoundLevelFilter *ldFilterBasicGlobal::soundLevelFilter() const
{
    return m_soundLevelFilter.get();
}
