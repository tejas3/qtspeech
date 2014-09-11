/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWidgets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include "qtexttospeech.h"
#include "qtexttospeech_p.h"

#include <qdebug.h>

QT_BEGIN_NAMESPACE


// FIXME: check that the private copying actually works
// FIXME: disentangle SPD from the generic stuff


// /*!
//  \class QTextToSpeechVoice
//  \brief The QTextToSpeechVoice class represents a voice in QTextToSpeech.

//  A voice is bound to a language.
//*/

//QTextToSpeechVoice::QTextToSpeechVoice(const QTextToSpeechVoice &other)
//    : d(other.d)
//{
//}

//QTextToSpeechVoice::~QTextToSpeechVoice()
//{}

//QString QTextToSpeechVoice::name() const
//{
//    return d->name();
//}

//QLocale QTextToSpeechVoice::locale() const
//{
//    return d->locale();
//}


QTextToSpeechPrivate::QTextToSpeechPrivate(QTextToSpeech *speech)
    : m_speech(speech), m_state(QTextToSpeech::Ready)
{
}

/*!
  \class QTextToSpeech
  \brief The QTextToSpeech class provides a convenient access to text-to-speech engines

  On Linux by default speech-dispatcher is used.
*/



QTextToSpeech::State QTextToSpeech::state() const
{
    Q_D(const QTextToSpeech);
    return d->state();
}

void QTextToSpeech::say(const QString &text)
{
    Q_D(QTextToSpeech);
    d->say(text);
}

void QTextToSpeech::stop()
{
    Q_D(QTextToSpeech);
    d->stop();
}

/*!
  Pause the current speech.
  \note this function depends on the platform and backend and may not work at all,
  take several seconds until it takes effect or may pause instantly.
  Some synthesizers will look for a break that they can later resume from, such as
  a sentence end.
 */
void QTextToSpeech::pause()
{
    Q_D(QTextToSpeech);
    d->pause();
}

void QTextToSpeech::resume()
{
    Q_D(QTextToSpeech);
    d->resume();
}

//QTextToSpeechVoice QTextToSpeech::currentVoice() const
//{
//    Q_D(const QTextToSpeech);
//    return d->currentVoice();
//}

//void QTextToSpeech::setVoice(const QTextToSpeechVoice &voice)
//{
//    Q_D(QTextToSpeech);
//    d->setVoice(voice);
//}

//QVector<QTextToSpeechVoice> QTextToSpeech::availableVoices() const
//{
//    Q_D(const QTextToSpeech);
//    return d->availableVoices();
//}

//QVector<QString> QTextToSpeech::availableVoiceTypes() const
//{
//    Q_D(const QTextToSpeech);
//    return d->availableVoiceTypes();
//}

//void QTextToSpeech::setVoiceType(const QString& type)
//{
//    Q_D(QTextToSpeech);
//    d->setVoiceType(type);
//}
//QString QTextToSpeech::currentVoiceType() const
//{
//    Q_D(const QTextToSpeech);
//    return d->currentVoiceType();
//}


/*!
 Sets the voice \a pitch to a value between -1.0 and 1.0.
 The default of 0.0 is normal speech.
*/
void QTextToSpeech::setPitch(double pitch)
{
    Q_D(QTextToSpeech);
    d->setPitch(pitch);
}

/*!
 Sets the voice \a rate to a value between -1.0 and 1.0.
 The default of 0.0 is normal speech flow.
*/
void QTextToSpeech::setRate(double rate)
{
    Q_D(QTextToSpeech);
    d->setRate(rate);
}

/*!
 Sets the \a volume to a value between -1.0 and 1.0.
 The default is 0.0.
*/
void QTextToSpeech::setVolume(double volume)
{
    Q_D(QTextToSpeech);
    d->setVolume(volume);
}

QT_END_NAMESPACE