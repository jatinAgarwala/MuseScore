//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2021 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#include "abpaintprovider.h"

#include "log.h"

using namespace mu::autobot;

const std::shared_ptr<AbPaintProvider>& AbPaintProvider::instance()
{
    static std::shared_ptr<AbPaintProvider> p = std::shared_ptr<AbPaintProvider>(new AbPaintProvider());
    return p;
}

AbPaintProvider::AbPaintProvider()
{
}

void AbPaintProvider::beginTarget(const std::string& name)
{
    LOGI() << name;
    BufferedPaintProvider::beginTarget(name);
}

bool AbPaintProvider::endTarget(bool endDraw)
{
    bool ok = BufferedPaintProvider::endTarget(endDraw);
    if (ok && drawData().name == "notationview") {
        m_notationViewDrawData = drawData();
    }
    return ok;
}

const mu::draw::DrawData& AbPaintProvider::notationViewDrawData() const
{
    return m_notationViewDrawData;
}
