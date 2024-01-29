/*
 * Copyright (C) 2017 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     caitao <caitao@deepin.com>
 *
 * Maintainer:  caitao <caitao@deepin.com>
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
#pragma once

#include <QAtomicPointer>
#include <QReadWriteLock>
#include <QMutex>
#include <QDebug>

template<class T>

class Singleton
{
public:
    static T &getInstance(void);

private:
    Singleton();
    Singleton(const Singleton<T> &);
    Singleton<T> &operator=(const Singleton<T> &);

    QReadWriteLock internalMutex;
    static QMutex mutex;
    static QAtomicPointer<T> m_pInstance;
};

template<class T>
QAtomicPointer<T> Singleton<T>::m_pInstance;

template<class T>
QMutex Singleton<T>::mutex(QMutex::Recursive);

template<class T>
T &Singleton<T>::getInstance(void)
{
    QMutexLocker locker(&mutex);
    if (m_pInstance.testAndSetOrdered(0, 0)) {
        m_pInstance.testAndSetOrdered(0, new T);
    }

    return *m_pInstance.load();
}

#define DEFENDER_MUTEX_LOCKER(mutex_ptr) QMutexLocker locker(mutex_ptr)

class CMutex : public QObject
{
    Q_OBJECT
public:
    explicit CMutex(QObject *parent = nullptr);
    QMutex m_mutex;
};
typedef Singleton<CMutex> SMutex;
