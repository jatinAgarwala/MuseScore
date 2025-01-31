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
#ifndef MU_APPSHELL_PREFERENCEPAGEITEM_H
#define MU_APPSHELL_PREFERENCEPAGEITEM_H

#include <QObject>

#include "ui/view/iconcodes.h"

namespace mu::appshell {
class PreferencePageItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id NOTIFY idChanged)
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(int icon READ icon NOTIFY iconChanged)
    Q_PROPERTY(QString path READ path NOTIFY pathChanged)

public:
    explicit PreferencePageItem(QObject* parent = nullptr);
    virtual ~PreferencePageItem();

    QString id() const;
    QString title() const;
    int icon() const;
    QString path() const;

    PreferencePageItem* parentItem() const;
    void setParentItem(PreferencePageItem* parent);

    QList<PreferencePageItem*> childrenItems() const;
    bool isEmpty() const;

    PreferencePageItem* childAtRow(const int row) const;

    void appendChild(PreferencePageItem* child);

    int childCount() const;
    int row() const;

public slots:
    void setTitle(QString title);
    void setId(QString id);
    void setIcon(ui::IconCode::Code icon);
    void setPath(QString path);

signals:
    void idChanged(QString id);
    void titleChanged(QString title);
    void iconChanged(int icon);
    void pathChanged(QString path);

private:
    QList<PreferencePageItem*> m_children;
    PreferencePageItem* m_parent = nullptr;

    QString m_title;
    QString m_id;
    ui::IconCode::Code m_icon = ui::IconCode::Code::NONE;
    QString m_path;
};
}

#endif // MU_APPSHELL_PREFERENCEPAGEITEM_H
