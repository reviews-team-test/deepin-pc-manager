/*
 * Copyright (C) 2020 ~ 2022 Uniontech Software Co., Ltd.
 *
 * Author:     shenfusheng <shenfusheng@uniontech.com>
 *
 * Maintainer: shenfusheng <shenfusheng@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "aesencrpyobj.h"

AesEncrpyObj::AesEncrpyObj(QObject *parent)
    : QObject(parent)
    , m_ctx()
{
}

void AesEncrpyObj::initKey()
{
    uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    AES_init_ctx(&m_ctx, key);
}

QByteArray AesEncrpyObj::encryptData(const QByteArray &strData)
{
    QByteArray byOrigData = strData;
    QByteArrayList byList;
    QByteArray byEncrypt;

    while (byOrigData.size() >= AES_BLOCKLEN) {
        QByteArray byTemp = byOrigData.left(AES_BLOCKLEN);
        byList.push_back(byTemp);
        byOrigData = byOrigData.remove(0, AES_BLOCKLEN);
    }

    //进行补足AES_BLOCKLEN的操作
    if (byOrigData.size() > 0) {
        QByteArray byTemp = QByteArray::fromStdString(byOrigData.toStdString());
        int iCount = AES_BLOCKLEN - byTemp.size();
        byTemp += QByteArray(iCount, ' ');
        byList.push_back(byTemp);
        byOrigData.clear();
    }

    foreach (QByteArray byData, byList) {
        u_int8_t buf[AES_BLOCKLEN] = {0};
        memcpy(buf, (u_int8_t *)byData.constData(), AES_BLOCKLEN);
        AES_ECB_encrypt(&m_ctx, buf);
        byEncrypt += QByteArray((char *)buf, AES_BLOCKLEN);
    }

    return byEncrypt;
}

QByteArray AesEncrpyObj::decryptData(const QByteArray &byData)
{
    QByteArrayList byList;
    QByteArray byOrigData = byData;
    QByteArray byDecrypt;

    while (byOrigData.size() >= AES_BLOCKLEN) {
        QByteArray byTemp = byOrigData.left(AES_BLOCKLEN);
        byList.push_back(byTemp);
        byOrigData = byOrigData.remove(0, AES_BLOCKLEN);
    }

    //进行补足AES_BLOCKLEN的操作
    if (byOrigData.size() > 0) {
        QByteArray byTemp = QByteArray::fromStdString(byOrigData.toStdString());
        int iCount = AES_BLOCKLEN - byTemp.size();
        byTemp += QByteArray(iCount, ' ');
        byList.push_back(byTemp);
        byOrigData.clear();
    }

    foreach (QByteArray byData, byList) {
        u_int8_t buf[AES_BLOCKLEN] = {0};
        memcpy(buf, (u_int8_t *)byData.constData(), AES_BLOCKLEN);
        AES_ECB_decrypt(&m_ctx, buf);
        byDecrypt += QByteArray((char *)buf, AES_BLOCKLEN);
    }

    return byDecrypt.trimmed();
}
