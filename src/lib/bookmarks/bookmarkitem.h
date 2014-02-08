/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2014  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef BOOKMARKITEM_H
#define BOOKMARKITEM_H

#include <QString>
#include <QList>
#include <QUrl>

#include "qz_namespace.h"

class QT_QUPZILLA_EXPORT BookmarkItem
{
public:
    enum Type {
        Root,
        Url,
        Folder,
        Separator,
        Invalid
    };

    explicit BookmarkItem(Type type, BookmarkItem* parent = 0);
    ~BookmarkItem();

    Type type() const;
    void setType(Type type);

    bool isFolder() const;
    bool isUrl() const;
    bool isSeparator();

    BookmarkItem* parent() const;
    QList<BookmarkItem*> children() const;

    QUrl url() const;
    void setUrl(const QUrl &url);

    QString title() const;
    void setTitle(const QString &title);

    QString description() const;
    void setDescription(const QString &description);

    QString keyword() const;
    void setKeyword(const QString &keyword);

    bool isExpanded() const;
    void setExpanded(bool expanded);

    void addChild(BookmarkItem* child, int index = -1);
    void removeChild(BookmarkItem* child);

    static Type typeFromString(const QString &string);
    static QString typeToString(Type type);

private:
    Type m_type;
    BookmarkItem* m_parent;
    QList<BookmarkItem*> m_children;

    QUrl m_url;
    QString m_title;
    QString m_description;
    QString m_keyword;
    bool m_expanded;
};

#endif // BOOKMARKITEM_H