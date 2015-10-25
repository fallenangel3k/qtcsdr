/*
This software is part of qtcsdr.

Copyright (c) 2015, Andras Retzler <randras@sdr.hu>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANDRAS RETZLER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef QMYSPECTRUMWIDGET_H
#define QMYSPECTRUMWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QPointer>

class QMySpectrumWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QMySpectrumWidget(QWidget *parent = 0);
    QImage* spectrumImage;
    int FFTSize = 2048;
    bool takeOneWaterfallLine(QByteArray* from);
    int sampleRate = 2400000;
    int offsetFreq = 0;
    int filterLowCut = 0;
    int filterHighCut = 0;
private:
    void reinit();
    virtual void paintEvent(QPaintEvent*);
    virtual void resizeEvent(QResizeEvent * event);
    void shiftImageOneLineDown();

signals:

public slots:

};

#endif // QMYSPECTRUMWIDGET_H
