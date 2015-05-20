/* === This file is part of Calamares - <http://github.com/calamares> ===
 *
 *   Copyright 2014, Aurélien Gâteau <agateau@kde.org>
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

#include <CalaPM.h>

#include <QDebug>

#include <backend/corebackendmanager.h>
#include <config.h>

namespace CalaPM
{

static bool s_inited = false;

bool init()
{
    if ( s_inited )
        return true;

    Config::instance( "calapmrc" );
    QByteArray backendName = qgetenv( "CALAPM_BACKEND" );
    if ( backendName.isEmpty() )
        backendName = "libparted";

    if ( !CoreBackendManager::self()->load( backendName ) )
    {
        qWarning() << "Failed to load backend plugin" << backendName;
        return false;
    }
    s_inited = true;
    return true;
}

} // namespace
