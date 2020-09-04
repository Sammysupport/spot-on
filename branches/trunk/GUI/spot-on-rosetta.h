/*
** Copyright (c) 2011 - 10^10^10, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Spot-On without specific prior written permission.
**
** SPOT-ON IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** SPOT-ON, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _spoton_rosetta_h_
#define _spoton_rosetta_h_

#include "ui_spot-on-rosetta.h"

class QKeyEvent;
class spoton;

class spoton_rosetta: public QMainWindow
{
  Q_OBJECT

 public:
  spoton_rosetta(void);
  void setName(const QString &text);
  void show(spoton *parent);

 private:
  Ui_spoton_rosetta ui;
  spoton *m_parent;
  QByteArray copyMyRosettaPublicKey(void) const;
  void keyPressEvent(QKeyEvent *event);
  void populateContacts(void);
  void resizeEvent(QResizeEvent *event);
  void sortContacts(void);

 private slots:
  void slotAddContact(void);
  void slotClear(void);
  void slotClose(void);
  void slotConvert(void);
  void slotCopyConverted(void);
  void slotCopyMyRosettaPublicKey(void);
  void slotCopyOrPaste(void);
  void slotDecryptClear(void);
  void slotDecryptReset(void);
  void slotDelete(void);
  void slotParticipantAdded(const QString &type);
  void slotRename(void);
  void slotSaveName(void);
  void slotSetIcons(void);
  void slotSplitterMoved(int pox, int index);

 signals:
  void participantAdded(const QString &type);
  void participantDeleted(const QString &oid, const QString &type);
  void participantNameChanged(const QByteArray &publicKeyHash,
			      const QString &name);
};

#endif
