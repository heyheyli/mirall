/*
 * Copyright (C) by Krzesimir Nowak <krzesimir@endocode.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#include <QNetworkRequest>

#include "mirall/mirallaccessmanager.h"
#include "mirall/utility.h"

namespace Mirall
{

MirallAccessManager::MirallAccessManager(QObject* parent)
    : QNetworkAccessManager (parent)
{}

QNetworkReply* MirallAccessManager::createRequest(QNetworkAccessManager::Operation op, const QNetworkRequest& request, QIODevice* outgoingData)
{
    QNetworkRequest newRequest(request);

    newRequest.setRawHeader( QByteArray("User-Agent"), Utility::userAgentString());
    return QNetworkAccessManager::createRequest (op, newRequest, outgoingData);
}

} // ns Mirall
