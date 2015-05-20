/* === This file is part of Calamares - <http://github.com/calamares> ===
 *
 *   Copyright 2014, Teo Mrnjavac <teo@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#include "TextTreeItem.h"

#include "ProgressTreeModel.h"

TextTreeItem::TextTreeItem( const QString& text, ProgressTreeItem* parent )
    : ProgressTreeItem( parent )
    , m_text( text )
{}


QVariant
TextTreeItem::data( int role ) const
{
    if ( role == ProgressTreeModel::ProgressTreeItemRole )
        return this;
    if ( role == Qt::DisplayRole )
        return m_text;
    return QVariant();
}
