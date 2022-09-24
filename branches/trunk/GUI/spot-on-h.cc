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

#include <QApplication>
#include <QProgressDialog>
#include <QtConcurrent>

#include <limits>

#include "Common/spot-on-crypt.h"
#include "spot-on-documentation.h"
#if SPOTON_GOLDBUG == 0
#include "spot-on-emailwindow.h"
#endif
#include "spot-on-utilities.h"
#include "spot-on.h"
#include "ui_spot-on-postgresql-connect.h"
#include "ui_spot-on-socket-options.h"

QMap<QString, QByteArray> spoton::SMPWindowStreams
(const QStringList &keyTypes) const
{
  return m_smpWindow->streams(keyTypes);
}

QString spoton::listenerTransport(void) const
{
  int row = -1;

  if((row = m_ui.listeners->currentRow()) >= 0)
    {
      QTableWidgetItem *item = m_ui.listeners->item(row, 15);

      if(item)
	return item->text();
    }

  return QString("");
}

QString spoton::neighborTransport(void) const
{
  int row = -1;

  if((row = m_ui.neighbors->currentRow()) >= 0)
    {
      QTableWidgetItem *item = m_ui.neighbors->item(row, 27);

      if(item)
	return item->text();
    }

  return QString("");
}

QString spoton::participantKeyType(QTableWidget *table) const
{
  if(!table)
    return QString("");

  int row = -1;

  if((row = table->currentRow()) >= 0)
    {
      QTableWidgetItem *item = table->item(row, 1); // OID

      if(item)
	return item->data
	  (Qt::ItemDataRole(Qt::UserRole + 1)).toString().toLower();
    }

  return QString("");
}

QThread::Priority spoton::neighborThreadPriority(void) const
{
  int row = -1;

  if((row = m_ui.neighbors->currentRow()) >= 0)
    {
      QTableWidgetItem *item = m_ui.neighbors->item(row, 35);

      if(item)
	return QThread::Priority(item->data(Qt::UserRole).toInt());
    }

  return QThread::HighPriority;
}

QWidget *spoton::combinationBoxForTable(void) const
{
  QComboBox *comboBox = new QComboBox();
  QHBoxLayout *layout = new QHBoxLayout();
  QSpacerItem *spacer = new QSpacerItem
    (40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
  QWidget *widget = new QWidget();

  comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
  comboBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
  widget->setLayout(layout);
  layout->addWidget(comboBox);
  layout->addSpacerItem(spacer);
  layout->setContentsMargins(0, 0, 0, 0);
  return widget;
}

bool spoton::listenerSupportsSslTls(void) const
{
  int row = -1;

  if((row = m_ui.listeners->currentRow()) >= 0)
    {
      QTableWidgetItem *item1 = m_ui.listeners->item(row, 2);
      QTableWidgetItem *item2 = m_ui.listeners->item(row, 15);

      if(item1 && item2)
	{
	  QString string(item2->text().toLower().trimmed());
	  int integer = item1->text().toInt();

	  if(integer > 0 && string == "tcp")
	    return true;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)) && !defined(SPOTON_DTLS_DISABLED)
	  if(integer > 0 && string == "udp")
	    return true;
#endif

#if QT_VERSION >= 0x050300 && defined(SPOTON_WEBSOCKETS_ENABLED)
	  if(integer > 0 && string == "websocket")
	    return true;
#endif
	}
    }

  return false;
}

bool spoton::neighborSpecialClient(void) const
{
  int row = -1;

  if((row = m_ui.neighbors->currentRow()) >= 0)
    {
      QTableWidgetItem *item1 = m_ui.neighbors->item(row, 3); // SSL Key Size
      QTableWidgetItem *item2 = m_ui.neighbors->item(row, 27); // Transport
      QTableWidgetItem *item3 = m_ui.neighbors->item
	(row, 43); // Bind IP Address

      if(item1 && item2 && item3)
	{
	  QString string1(item2->text().toLower().trimmed());
	  QString string2(item3->text().toLower().trimmed());

	  return item1->text().toInt() > 0 &&
	    string1 == "tcp" &&
	    string2.length() > 0;
	}
    }

  return false;
}

bool spoton::neighborSupportsSslTls(void) const
{
  int row = -1;

  if((row = m_ui.neighbors->currentRow()) >= 0)
    {
      QTableWidgetItem *item1 = m_ui.neighbors->item(row, 3);
      QTableWidgetItem *item2 = m_ui.neighbors->item(row, 27);

      if(item1 && item2)
	{
	  QString string(item2->text().toLower().trimmed());
	  int integer = item1->text().toInt();

	  if(integer > 0 && string == "tcp")
	    return true;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)) && !defined(SPOTON_DTLS_DISABLED)
	  if(integer > 0 && string == "udp")
	    return true;
#endif

#if QT_VERSION >= 0x050300 && defined(SPOTON_WEBSOCKETS_ENABLED)
	  if(integer > 0 && string == "websocket")
	    return true;
#endif
	}
    }

  return false;
}

bool spoton::nodeExists(const QSqlDatabase &db,
			const QString &identifier,
			const QString &table) const
{
  spoton_crypt *crypt = m_crypts.value("chat", 0);

  if(!crypt)
    return true;

  QByteArray hash(crypt->keyedHash(identifier.toLatin1(), 0));

  if(hash.isEmpty())
    return true;

  QSqlQuery query(db);

  query.prepare
    (QString("SELECT EXISTS(SELECT 1 FROM %1 WHERE hash = ?)").arg(table));
  query.addBindValue(hash.toBase64());

  if(query.exec())
    return query.next() && query.value(0).toBool();
  else
    return true;
}

bool spoton::writeKernelSocketData(const QByteArray &bytes)
{
  return m_kernelSocket.write(bytes) == static_cast<qint64> (bytes.length());
}

void spoton::generalConcurrentMethod(const QHash<QString, QVariant> &settings)
{
  if(!settings.value("is_kernel_active").toBool())
    {
      QString connectionName("");

      {
	QSqlDatabase db = spoton_misc::database(connectionName);

	db.setDatabaseName(spoton_misc::homePath() +
			   QDir::separator() +
			   "friends_public_keys.db");

	if(db.open())
	  {
	    QSqlQuery query(db);

	    /*
	    ** OK, so the kernel is inactive. All participants are offline.
	    */

	    query.exec
	      ("UPDATE friends_public_keys SET status = 'offline' WHERE "
	       "status <> 'offline'");
	  }

	db.close();
      }

      QSqlDatabase::removeDatabase(connectionName);

      {
	QSqlDatabase db = spoton_misc::database(connectionName);

	db.setDatabaseName
	  (spoton_misc::homePath() + QDir::separator() + "listeners.db");

	if(db.isOpen())
	  {
	    QSqlQuery query(db);

	    /*
	    ** OK, so the kernel is inactive. Discover the
	    ** listeners that have not been deleted and update some of their
	    ** information.
	    */

	    query.exec("PRAGMA secure_delete = ON");
	    query.exec("DELETE FROM listeners WHERE "
		       "status_control = 'deleted'");
	    query.exec("DELETE FROM listeners_accounts WHERE "
		       "listener_oid NOT IN "
		       "(SELECT OID FROM listeners)");
	    query.exec
	      ("DELETE FROM listeners_accounts_consumed_authentications "
	       "WHERE listener_oid >= 0");
	    query.exec("DELETE FROM listeners_allowed_ips WHERE "
		       "listener_oid NOT IN "
		       "(SELECT OID FROM listeners)");
	    query.exec("UPDATE listeners SET connections = 0, "
		       "external_ip_address = NULL, "
		       "external_port = NULL, "
		       "status = 'offline' WHERE "
		       "connections > 0 OR status = 'online'");
	  }

	db.close();
      }

      QSqlDatabase::removeDatabase(connectionName);

      {
	QSqlDatabase db = spoton_misc::database(connectionName);

	db.setDatabaseName
	  (spoton_misc::homePath() + QDir::separator() + "neighbors.db");

	if(db.open())
	  {
	    QSqlQuery query(db);

	    /*
	    ** OK, so the kernel is inactive. Discover the
	    ** neighbors that have not been deleted and not disconnected
	    ** and update some of their information.
	    */

	    query.exec("PRAGMA secure_delete = ON");
	    query.exec
	      ("DELETE FROM neighbors WHERE status_control = 'deleted'");
	    query.exec
	      ("UPDATE neighbors SET "
	       "account_authenticated = NULL, "
	       "buffered_content = 0, "
	       "bytes_discarded_on_write = 0, "
	       "bytes_read = 0, "
	       "bytes_written = 0, "
	       "external_ip_address = NULL, "
	       "external_port = NULL, "
	       "is_encrypted = 0, "
	       "local_ip_address = NULL, "
	       "local_port = NULL, "
	       "ssl_session_cipher = NULL, "
	       "status = 'disconnected', "
	       "uptime = 0 WHERE "
	       "local_ip_address IS NOT NULL OR local_port IS NOT NULL "
	       "OR status <> 'disconnected'");
	  }

	db.close();
      }

      QSqlDatabase::removeDatabase(connectionName);
    }

  if(settings.value("keep_only_user_defined_neighbors").toBool())
    {
      QString connectionName("");

      {
	QSqlDatabase db = spoton_misc::database(connectionName);

	db.setDatabaseName
	  (spoton_misc::homePath() + QDir::separator() + "neighbors.db");

	if(db.open())
	  {
	    /*
	    ** Delete disconnected peers.
	    */

	    QSqlQuery query(db);

	    query.exec("PRAGMA secure_delete = ON");
	    query.exec("DELETE FROM neighbors WHERE "
		       "status <> 'connected' AND "
		       "status_control <> 'blocked' AND "
		       "user_defined = 0");
	  }

	db.close();
      }

      QSqlDatabase::removeDatabase(connectionName);
    }
}

void spoton::inspectPQUrlDatabase(const QByteArray &name,
				  const QByteArray &password)
{
  QSettings settings;
  QSqlDatabase db;
  QString connectionName(spoton_misc::databaseName());
  QString options
    (settings.value("gui/postgresql_connection_options",
		    spoton_common::POSTGRESQL_CONNECTION_OPTIONS).
     toString().trimmed());

  if(!options.contains("connect_timeout="))
    options.append(";connect_timeout=5");

  if(settings.value("gui/postgresql_ssltls", true).toBool())
    options.append(";requiressl=1");

  db = QSqlDatabase::addDatabase("QPSQL", connectionName);
  db.setConnectOptions(spoton_misc::adjustPQConnectOptions(options));
  db.setDatabaseName
    (settings.value("gui/postgresql_database", "").toString().trimmed());
  db.setHostName
    (settings.value("gui/postgresql_host", "localhost").toString().trimmed());
  db.setPort(settings.value("gui/postgresql_port", 5432).toInt());

  if(!db.open(name, password))
    {
      QString error(db.lastError().text().toLower());

      if(!error.contains("password authentication") &&
	 !error.contains("query results lost"))
	{
	  qDebug() << "spoton::inspectPQUrlDatabase(): "
		   << db.lastError()
		   << ".";

	  if(m_pqUrlFaultyCounter.fetchAndAddOrdered(1) > 5)
	    emit pqUrlDatabaseFaulty();
	}
    }
  else
    m_pqUrlFaultyCounter.fetchAndStoreOrdered(0);

  db.close();
  db = QSqlDatabase();
  QSqlDatabase::removeDatabase(connectionName);
}

void spoton::prepareOtherOptions(void)
{
  QMapIterator<QString, QVariant> it
    (spoton_misc::otherOptions(QByteArray::
			       fromBase64(m_settings.value("gui/other_options").
					  toByteArray())));

  m_optionsUi.other_options->clear();

  while(it.hasNext())
    {
      it.next();
      m_settings[it.key()] = it.value();
      m_optionsUi.other_options->appendPlainText
	(it.key() + " := " + it.value().toString());
    }

  m_optionsUi.other_options->appendPlainText("");

  if(m_optionsUi.other_options->toPlainText().trimmed().isEmpty())
    {
      m_optionsUi.other_options->appendPlainText
	("MAXIMUM_KERNEL_WEB_SERVER_SOCKET_READ_BUFFER_SIZE := " +
	 QString::number(spoton_common::
			 MAXIMUM_KERNEL_WEB_SERVER_SOCKET_READ_BUFFER_SIZE));
      m_optionsUi.other_options->appendPlainText
	("P2P_SERVERLESS_CONNECT_INTERVAL_MS := 1");
      m_optionsUi.other_options->appendPlainText
	("SMP_PREFERRED_HASH_ALGORITHM := sha3-512");
      m_optionsUi.other_options->appendPlainText
	("WEB_SERVER_CERTIFICATE_LIFETIME := " +
	 QString::number(spoton_common::WEB_SERVER_CERTIFICATE_LIFETIME));
      m_optionsUi.other_options->appendPlainText
	("WEB_SERVER_HTTP_SO_LINGER := -1");
      m_optionsUi.other_options->appendPlainText
	("WEB_SERVER_HTTPS_SO_LINGER := -1");
      m_optionsUi.other_options->appendPlainText
	("WEB_SERVER_KEY_SIZE := " +
	 QString::number(spoton_common::WEB_SERVER_KEY_SIZE));
      m_optionsUi.other_options->appendPlainText
	("WEB_SERVER_SSL_OPTION_DISABLE_SESSION_TICKETS := true");
      m_optionsUi.other_options->appendPlainText("");
    }
}

void spoton::prepareStyleSheet(void)
{
  QApplication::processEvents();
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  bool ok = true;
  int index = m_settings.value("gui/theme", -1).toInt();

  if(index == 0 || index == 1 || index == 2)
    {
      QFile file;

      if(index == 0)
	file.setFileName(":qdarkstyle/qdarkstyle.qss");
      else if(index == 1)
	file.setFileName(":darkstyle/darkstyle.qss");
      else if(index == 2)
	file.setFileName(":darkorange/darkorange.qss");

      if((ok = file.open(QFile::ReadOnly | QFile::Text)))
	{
	  QTextStream textStream(&file);

	  qobject_cast<QApplication *> (QApplication::instance())->
	    setStyleSheet(textStream.readAll());
	  setStyleSheet
	    (qobject_cast<QApplication *> (QApplication::instance())->
	     styleSheet());

	  if(textStream.status() != QTextStream::Ok)
	    ok = false;
	}
    }
  else
    ok = false;

  if(!ok)
    {
      qobject_cast<QApplication *> (QApplication::instance())->setStyleSheet
	(m_defaultStyleSheet);
      setStyleSheet(m_defaultStyleSheet);
    }

  QApplication::restoreOverrideCursor();
}

void spoton::retrieveNeighbors(void)
{
  QFileInfo fileInfo
    (spoton_misc::homePath() + QDir::separator() + "neighbors.db");

  if(fileInfo.exists())
    {
      if(fileInfo.lastModified() >= m_neighborsLastModificationTime)
	{
	  if(fileInfo.lastModified() == m_neighborsLastModificationTime)
	    m_neighborsLastModificationTime = fileInfo.lastModified().
	      addMSecs(1);
	  else
	    m_neighborsLastModificationTime = fileInfo.lastModified();
	}
      else
	return;
    }
  else
    m_neighborsLastModificationTime = QDateTime();

  QString connectionName("");

  {
    QSqlDatabase *db = new QSqlDatabase(spoton_misc::database(connectionName));

    db->setDatabaseName(fileInfo.absoluteFilePath());

    if(db->open())
      {
	QSqlQuery *query = new QSqlQuery(*db);
	int size = 0;

	if(query->exec("SELECT COUNT(*) FROM neighbors "
		       "WHERE status_control <> 'deleted'"))
	  if(query->next())
	    size = query->value(0).toInt();

	if(query->exec("SELECT sticky, "                   // 0
		       "uuid, "                            // 1
		       "status, "                          // 2
		       "ssl_key_size, "                    // 3
		       "status_control, "                  // 4
		       "local_ip_address, "                // 5
		       "local_port, "                      // 6
		       "external_ip_address, "             // 7
		       "external_port, "                   // 8
		       "country, "                         // 9
		       "remote_ip_address, "               // 10
		       "remote_port, "                     // 11
		       "scope_id, "                        // 12
		       "protocol, "                        // 13
		       "proxy_hostname, "                  // 14
		       "proxy_port, "                      // 15
		       "maximum_buffer_size, "             // 16
		       "maximum_content_length, "          // 17
		       "echo_mode, "                       // 18
		       "uptime, "                          // 19
		       "allow_exceptions, "                // 20
		       "certificate, "                     // 21
		       "bytes_read, "                      // 22
		       "bytes_written, "                   // 23
		       "ssl_session_cipher, "              // 24
		       "account_name, "                    // 25
		       "account_authenticated, "           // 26
		       "transport, "                       // 27
		       "orientation, "                     // 28
		       "motd, "                            // 29
		       "is_encrypted, "                    // 30
		       "0, " // Certificate                // 31
		       "ae_token, "                        // 32
		       "ae_token_type, "                   // 33
		       "ssl_control_string, "              // 34
		       "priority, "                        // 35
		       "lane_width, "                      // 36
		       "passthrough, "                     // 37
		       "waitforbyteswritten_msecs, "       // 38
		       "private_application_credentials, " // 39
		       "silence_time, "                    // 40
		       "socket_options, "                  // 41
		       "buffered_content, "                // 42
		       "bind_ip_address, "                 // 43
		       "OID "                              // 44
		       "FROM neighbors WHERE status_control <> 'deleted'"))
	  {
	    while(query->next())
	      {
	      }

	    emit neighborsQueryReady(db, query, connectionName, size);
	    return;
	  }

	db->close();
	delete db;
	delete query;
      }
    else
      delete db;
  }

  QSqlDatabase::removeDatabase(connectionName);
}

void spoton::retrieveParticipants(spoton_crypt *crypt)
{
  if(!crypt)
    return;

  QFileInfo fileInfo
    (spoton_misc::homePath() + QDir::separator() + "friends_public_keys.db");

  if(fileInfo.exists())
    {
      if(fileInfo.lastModified() >= m_participantsLastModificationTime)
	{
	  if(fileInfo.lastModified() == m_participantsLastModificationTime)
	    m_participantsLastModificationTime = fileInfo.lastModified().
	      addMSecs(1);
	  else
	    m_participantsLastModificationTime = fileInfo.lastModified();
	}
      else
	return;
    }
  else
    m_participantsLastModificationTime = QDateTime();

  QString connectionName("");

  {
    QSqlDatabase *db = new QSqlDatabase(spoton_misc::database(connectionName));

    db->setDatabaseName(fileInfo.absoluteFilePath());

    if(db->open())
      {
	QSqlQuery *query = new QSqlQuery(*db);
	bool ok = true;

	query->prepare("SELECT "
		       "name, "               // 0
		       "OID, "                // 1
		       "neighbor_oid, "       // 2
		       "public_key_hash, "    // 3
		       "status, "             // 4
		       "last_status_update, " // 5
		       "gemini, "             // 6
		       "gemini_hash_key, "    // 7
		       "key_type, "           // 8
		       "public_key "          // 9
		       "FROM friends_public_keys "
		       "WHERE key_type_hash IN (?, ?, ?, ?)");
	query->bindValue
	  (0, crypt->keyedHash(QByteArray("chat"), &ok).toBase64());

	if(ok)
	  query->bindValue
	    (1, crypt->keyedHash(QByteArray("email"), &ok).toBase64());

	if(ok)
	  query->bindValue
	    (2, crypt->keyedHash(QByteArray("poptastic"), &ok).toBase64());

	if(ok)
	  query->bindValue
	    (3, crypt->keyedHash(QByteArray("url"), &ok).toBase64());

	if(ok && query->exec())
	  {
	    while(query->next())
	      {
	      }

	    emit participantsQueryReady(db, query, connectionName);
	    return;
	  }

	db->close();
	delete db;
	delete query;
      }
    else
      delete db;
  }

  QSqlDatabase::removeDatabase(connectionName);
}

void spoton::slotApplyOtherOptions(void)
{
  m_settings["gui/other_options"] = m_optionsUi.other_options->
    toPlainText().trimmed().toLatin1().toBase64();

  QSettings settings;

  settings.setValue
    ("gui/other_options",
     m_optionsUi.other_options->toPlainText().trimmed().toLatin1().toBase64());
  prepareOtherOptions();
}

void spoton::slotEmailLettersPerPageChanged(int value)
{
  m_settings["gui/email_letters_per_page"] = value;

  QSettings settings;

  settings.setValue("gui/email_letters_per_page", value);
}

void spoton::slotEmailPageChanged(int value)
{
  Q_UNUSED(value);
  populateMail();
}

void spoton::slotFindInSearch(void)
{
#if SPOTON_GOLDBUG == 0
  QString text(m_ui.find->text());

  if(!m_ui.urls->find(text))
    m_ui.urls->moveCursor(QTextCursor::Start);
#endif
}

void spoton::slotFindInSearchInitialize(void)
{
#if SPOTON_GOLDBUG == 0
  m_ui.find->selectAll();
  m_ui.find->setFocus();
#endif
}

void spoton::slotGenerateInstitutionKeyPair(void)
{
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  m_ui.institutionName->setText(spoton_crypt::strongRandomBytes(32).toBase64());
  m_ui.institutionPostalAddress->setText
    (spoton_crypt::
     strongRandomBytes(spoton_crypt::XYZ_DIGEST_OUTPUT_SIZE_IN_BYTES).
     toBase64());
  QApplication::restoreOverrideCursor();
}

void spoton::slotInitiateSSLTLSSession(void)
{
  QAction *action = qobject_cast<QAction *> (sender());

  if(!action)
    return;

  if(m_kernelSocket.state() != QAbstractSocket::ConnectedState)
    return;

  if(m_ui.neighborsActionMenu->menu())
    m_ui.neighborsActionMenu->menu()->repaint();

  repaint();
  QApplication::processEvents();
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  QString oid("");
  int row = -1;

  if((row = m_ui.neighbors->currentRow()) >= 0)
    {
      QTableWidgetItem *item = m_ui.neighbors->item
	(row, m_ui.neighbors->columnCount() - 1); // OID

      if(item)
	oid = item->text();
    }

  if(oid.isEmpty())
    {
      QApplication::restoreOverrideCursor();
      return;
    }

  QByteArray message;
  int mode = action->property("mode").toString() == "client" ? 1 : 0;

  message.append("initiatessltls_");
  message.append(QByteArray::number(mode));
  message.append("_");
  message.append(oid.toUtf8());
  message.append("\n");

  if(!writeKernelSocketData(message))
    spoton_misc::logError
      (QString("spoton::slotInitiateSSLTLSSession(): write() failure "
	       "for %1:%2.").
       arg(m_kernelSocket.peerAddress().toString()).
       arg(m_kernelSocket.peerPort()));

  QApplication::restoreOverrideCursor();

}

void spoton::slotKeysIndexChanged(const QString &text)
{
#ifndef SPOTON_OPEN_LIBRARY_SUPPORTED
  if(text == "Open Library")
    m_ui.regenerate->setEnabled(false);
  else
    m_ui.regenerate->setEnabled(true);
#else
  Q_UNUSED(text);
#endif
}

void spoton::slotLimitSqliteSynchronization(bool state)
{
  m_settings["gui/limit_sqlite_synchronization"] = state;

  QSettings settings;

  settings.setValue("gui/limit_sqlite_synchronization", state);
}

void spoton::slotMailContextMenu(const QPoint &point)
{
#if SPOTON_GOLDBUG == 0
  QModelIndexList list
    (m_ui.mail->selectionModel()->selectedRows(5)); // Gold Bug
  bool enabled = false;

  if(!list.isEmpty())
    {
      if(list.at(0).data().toString() == "0")
	enabled = true;
      else
	enabled = false;
    }

  QAction *action = 0;
  QMenu menu(this);

  action = menu.addAction(tr("Read (New Window)..."),
			  this,
			  SLOT(slotNewEmailWindow(void)));
  action->setEnabled(enabled);

  if(enabled)
    {
      action->setProperty("message", m_ui.mailMessage->toHtml());
      list = m_ui.mail->selectionModel()->selectedRows(3); // Subject
      action->setProperty("subject", list.value(0).data().toString());
      list = m_ui.mail->selectionModel()->
	selectedRows(8); // receiver_sender_hash
      action->setProperty
	("receiver_sender_hash", list.value(0).data().toString());
    }

  menu.exec(m_ui.mail->mapToGlobal(point));
#else
  Q_UNUSED(point);
#endif
}

void spoton::slotMonitorEvents(bool state)
{
  m_settings["gui/monitorEvents"] = state;

  QSettings settings;

  settings.setValue("gui/monitorEvents", state);
}

void spoton::slotNewEmailWindow(void)
{
#if SPOTON_GOLDBUG == 0
  QAction *action = qobject_cast<QAction *> (sender());
  spoton_emailwindow *window = 0;

  if(action)
    window = new spoton_emailwindow
      (action->property("message").toString(),
       action->property("subject").toString(),
       action->property("receiver_sender_hash").toString(),
       this);
  else
    window = new spoton_emailwindow("", "", "", this);

  connect(this,
	  SIGNAL(newEmailName(const QString &)),
	  window,
	  SLOT(slotNewEmailName(const QString &)));
  connect(this,
	  SIGNAL(participantAdded(const QString &)),
	  window,
	  SLOT(slotPopulateParticipants(void)));
  connect(this,
	  SIGNAL(participantDeleted(const QString &, const QString &)),
	  window,
	  SLOT(slotParticipantDeleted(const QString &, const QString &)));
  connect(this,
	  SIGNAL(participantNameChanged(const QByteArray &,
					const QString &)),
	  window,
	  SLOT(slotParticipantNameChanged(const QByteArray &,
					  const QString &)));
  connect(this,
	  SIGNAL(updateEmailWindows(void)),
	  window,
	  SLOT(slotUpdate(void)));
  connect(window,
	  SIGNAL(configurePoptastic(void)),
	  this,
	  SLOT(slotConfigurePoptastic(void)));
  spoton_utilities::centerWidget(window, this);
  window->show();
#endif
}

void spoton::slotPQUrlDatabaseFaulty(void)
{
  if(findChildren<QProgressDialog *> ().isEmpty())
    {
      m_pqUrlFaultyCounter.fetchAndStoreOrdered(0);
      slotPostgreSQLDisconnect(0);
    }
}

void spoton::slotPopPoptastic(void)
{
  writeKernelSocketData("poptasticpop");
}

void spoton::slotPopulateNeighbors(void)
{
  if(currentTabName() != "neighbors")
    return;
  else if(m_ui.neighborsTemporarilyPause->isChecked())
    return;

  if(m_neighborsFuture.isFinished())
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    m_neighborsFuture = QtConcurrent::run(&spoton::retrieveNeighbors, this);
#else
    m_neighborsFuture = QtConcurrent::run(this, &spoton::retrieveNeighbors);
#endif
}

void spoton::slotPopulateParticipants(void)
{
  if(m_participantsFuture.isFinished())
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    m_participantsFuture = QtConcurrent::run
      (&spoton::retrieveParticipants, this, m_crypts.value("chat", 0));
#else
    m_participantsFuture = QtConcurrent::run
      (this, &spoton::retrieveParticipants, m_crypts.value("chat", 0));
#endif
}

void spoton::slotPostgreSQLKernelUrlDistributionTimeout(int value)
{
  m_settings["gui/postgresql_kernel_url_distribution_timeout"] = value;

  QSettings settings;

  settings.setValue("gui/postgresql_kernel_url_distribution_timeout", value);
}

void spoton::slotPostgreSQLWebServerCredentials(void)
{
  spoton_crypt *crypt = m_crypts.value("chat", 0);

  if(!crypt)
    {
      QMessageBox::critical
	(this,
	 tr("%1: Error").arg(SPOTON_APPLICATION_NAME),
	 tr("Invalid spoton_crypt object. This is a fatal flaw."));
      QApplication::processEvents();
      return;
    }

  QByteArray name;
  QByteArray password;
  QDialog dialog(this);
  QSettings settings;
  Ui_spoton_postgresqlconnect ui;
  bool ok = true;

  name = crypt->decryptedAfterAuthenticated
    (QByteArray::fromBase64(settings.value("gui/postgresql_web_name", "").
			    toByteArray()), &ok);

  if(ok)
    password = crypt->decryptedAfterAuthenticated
      (QByteArray::fromBase64(settings.value("gui/postgresql_web_password", "").
			      toByteArray()), &ok);

  ui.setupUi(&dialog);
  dialog.setWindowTitle
    (tr("%1: PostgreSQL Connect").arg(SPOTON_APPLICATION_NAME));
  ui.connection_options->setText
    (settings.
     value("gui/postgresql_web_connection_options",
	   spoton_common::POSTGRESQL_CONNECTION_OPTIONS).toString().trimmed());
  ui.database->setEnabled(false);
  ui.database->setText
    (settings.value("gui/postgresql_database", "").toString().trimmed());
  ui.database->selectAll();
  ui.database->setFocus();
  ui.host->setEnabled(false);
  ui.host->setText
    (settings.value("gui/postgresql_host", "localhost").toString().trimmed());

  if(ok)
    ui.name->setText(name);

  if(ok)
    ui.password->setText(password);

  ui.port->setEnabled(false);
  ui.port->setValue(settings.value("gui/postgresql_port", 5432).toInt());
  ui.ssltls->setChecked
    (settings.value("gui/postgresql_ssltls", true).toBool());
  ui.ssltls->setEnabled(false);

  do
    {
      if(dialog.exec() == QDialog::Accepted)
	{
	  QApplication::processEvents();
	  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

	  if(QSqlDatabase::contains("URLDatabaseWeb"))
	    QSqlDatabase::removeDatabase("URLDatabaseWeb");

	  QSqlDatabase db = QSqlDatabase::addDatabase
	    ("QPSQL", "URLDatabaseWeb");
	  QString options(ui.connection_options->text().trimmed());

	  if(!options.contains("connect_timeout="))
	    options.append(";connect_timeout=10");

	  if(ui.ssltls->isChecked())
	    db.setConnectOptions
	      (spoton_misc::adjustPQConnectOptions(options + ";requiressl=1"));
	  else
	    db.setConnectOptions
	      (spoton_misc::adjustPQConnectOptions(options));

	  db.setHostName(ui.host->text());
	  db.setDatabaseName(ui.database->text());
	  db.setPort(ui.port->value());
	  db.open(ui.name->text(), ui.password->text());
	  QApplication::restoreOverrideCursor();

	  if(!db.isOpen())
	    {
	      QString str(db.lastError().text().trimmed());

	      db = QSqlDatabase();

	      if(QSqlDatabase::contains("URLDatabaseWeb"))
		QSqlDatabase::removeDatabase("URLDatabaseWeb");

	      QMessageBox::critical
		(this, tr("%1: Error").arg(SPOTON_APPLICATION_NAME),
		 tr("Could not open (%1) a database connection.").arg(str));
	      QApplication::processEvents();
	    }
	  else
	    {
	      db.close();
	      db = QSqlDatabase();

	      if(QSqlDatabase::contains("URLDatabaseWeb"))
		QSqlDatabase::removeDatabase("URLDatabaseWeb");

	      bool ok = true;

	      settings.setValue
		("gui/postgresql_web_connection_options",
		 spoton_misc::adjustPQConnectOptions(options));
	      settings.setValue
		("gui/postgresql_web_name",
		 crypt->encryptedThenHashed(ui.name->text().toUtf8(),
					    &ok).toBase64());

	      if(!ok)
		settings.remove("gui/postgresql_web_name");

	      settings.setValue
		("gui/postgresql_web_password",
		 crypt->encryptedThenHashed(ui.password->text().toUtf8(),
					    &ok).toBase64());

	      if(!ok)
		settings.remove("gui/postgresql_web_password");

	      break;
	    }
	}
      else
	{
	  QApplication::processEvents();
	  break;
	}
    }
  while(true);
}

void spoton::slotPrepareContextMenuMirrors(void)
{
  prepareContextMenuMirrors();
}

void spoton::slotSOSSMaximumClientsChanged(int value)
{
  QSettings settings;

  m_settings["gui/soss_maximum_clients"] = value;
  settings.setValue("gui/soss_maximum_clients", value);
}

void spoton::slotSaveExternalIPUrl(void)
{
  m_optionsUi.external_ip_url->setText
    (m_optionsUi.external_ip_url->text().trimmed());
  m_optionsUi.external_ip_url->selectAll();
  m_settings["gui/external_ip_url"] = m_optionsUi.external_ip_url->text();

  QSettings settings;

  settings.setValue
    ("gui/external_ip_url", m_optionsUi.external_ip_url->text());
}

void spoton::slotSaveLineLimits(int value)
{
  QSettings settings;

  if(m_optionsUi.buzz_maximum_lines == sender())
    {
      m_settings["gui/buzz_maximum_lines"] = value;
      settings.setValue("gui/buzz_maximum_lines", value);
    }
  else
    {
      m_settings["gui/chat_maximum_lines"] = value;
      settings.setValue("gui/chat_maximum_lines", value);
    }
}

void spoton::slotSetCongestionMaxPageCount(int value)
{
  m_settings["gui/congestion_control_max_page_count"] = value;

  QSettings settings;

  settings.setValue("gui/congestion_control_max_page_count", value);
}

void spoton::slotSetSocketOptions(void)
{
  QAction *action = qobject_cast<QAction *> (sender());

  if(!action)
    return;

  QString type(action->property("type").toString());

  if(!(type == "listeners" || type == "neighbors"))
    return;

  QString oid("");
  QString socketOptions("");
  QString transport("");
  int row = -1;

  if(type == "listeners")
    {
      if((row = m_ui.listeners->currentRow()) >= 0)
	{
	  QTableWidgetItem *item = m_ui.listeners->item
	    (row, m_ui.listeners->columnCount() - 1); // OID

	  if(item)
	    oid = item->text();

	  item = m_ui.listeners->item(row, 24); // Socket Options

	  if(item)
	    socketOptions = item->text();

	  item = m_ui.listeners->item(row, 15); // Transport

	  if(item)
	    transport = item->text().toUpper();
	}
    }
  else
    {
      if((row = m_ui.neighbors->currentRow()) >= 0)
	{
	  QTableWidgetItem *item = m_ui.neighbors->item
	    (row, m_ui.neighbors->columnCount() - 1); // OID

	  if(item)
	    oid = item->text();

	  item = m_ui.neighbors->item(row, 41); // Socket Options

	  if(item)
	    socketOptions = item->text();

	  item = m_ui.neighbors->item(row, 27); // Transport

	  if(item)
	    transport = item->text().toUpper();
	}
    }

  if(row < 0)
    return;

  QDialog dialog(this);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
  QStringList list(socketOptions.split(";", Qt::SkipEmptyParts));
#else
  QStringList list(socketOptions.split(";", QString::SkipEmptyParts));
#endif
  Ui_spoton_socket_options ui;

  ui.setupUi(&dialog);
  ui.nodelay->setEnabled(transport != "BLUETOOTH" && transport != "UDP");

#ifndef SPOTON_SCTP_ENABLED
  if(transport == "SCTP")
    ui.nodelay->setEnabled(false);
#endif

  if(transport == "WEBSOCKET")
    {
      if(type == "listeners")
#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
	ui.nodelay->setEnabled(true);
#else
        ui.nodelay->setEnabled(false);
#endif
      else
	ui.nodelay->setEnabled(false);
    }

  if(!ui.nodelay->isEnabled())
    ui.nodelay->setToolTip(tr("SCTP, if available, and TCP only."));

  ui.so_keepalive->setEnabled(transport != "BLUETOOTH" && transport != "UDP");

#ifndef SPOTON_SCTP_ENABLED
  if(transport == "SCTP")
    ui.so_keepalive->setEnabled(false);
#endif

  if(transport == "WEBSOCKET")
    {
      if(type == "listeners")
#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
	ui.so_keepalive->setEnabled(true);
#else
        ui.so_keepalive->setEnabled(false);
#endif
      else
	ui.so_keepalive->setEnabled(false);
    }

  if(!ui.so_keepalive->isEnabled())
    ui.so_keepalive->setToolTip(tr("SCTP, if available, and TCP only."));

  ui.so_linger->setEnabled(transport != "BLUETOOTH" && transport != "UDP");

#ifndef SPOTON_SCTP_ENABLED
  if(transport == "SCTP")
    ui.so_linger->setEnabled(false);
#endif

  if(transport == "WEBSOCKET")
    {
      if(type == "listeners")
#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
	ui.so_linger->setEnabled(true);
#else
        ui.so_linger->setEnabled(false);
#endif
      else
	ui.so_linger->setEnabled(false);
    }

  if(!ui.so_linger->isEnabled())
    ui.so_linger->setToolTip(tr("SCTP, if available, and TCP only."));

  ui.so_rcvbuf->setMaximum(std::numeric_limits<int>::max());
  ui.so_sndbuf->setMaximum(std::numeric_limits<int>::max());

#if defined(SO_TIMESTAMPING)
  ui.so_timestamping->setEnabled(transport != "BLUETOOTH");

  if(transport == "WEBSOCKET")
    {
      if(type == "listeners")
#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
	ui.so_timestamping->setEnabled(true);
#else
        ui.so_timestamping->setEnabled(false);
#endif
      else
	ui.so_timestamping->setEnabled(false);
    }

  if(!ui.so_timestamping->isEnabled())
    ui.so_timestamping->setToolTip
      (tr("SCTP, if available, TCP, and UDP only."));
#else
  ui.so_timestamping->setEnabled(false);
  ui.so_timestamping->setToolTip(tr("SO_TIMESTAMPING is not defined."));
#endif

  if(type == "listeners")
    {
      dialog.setWindowTitle
	(tr("%1: Listener Socket Options").arg(SPOTON_APPLICATION_NAME));
      ui.information->setText
	(tr("SCTP socket options will be applied to a listener's socket "
	    "after the socket is created. SCTP peers will also "
	    "inherit some options. "
	    "TCP and UDP socket options will be applied to "
	    "peer sockets after connections are established. "
	    "For a WebSocket listener, the socket options will be applied "
	    "after the server has successfully listened."));
    }
  else
    {
      dialog.setWindowTitle
	(tr("%1: Neighbor Socket Options").arg(SPOTON_APPLICATION_NAME));
      ui.information->setText
	(tr("SCTP socket options will be applied to a socket "
	    "after the socket is created and after the socket is connected. "
	    "TCP and UDP socket options will be applied after "
	    "connections are established."));
    }

  if(type == "listeners")
    {
      if(transport != "BLUETOOTH" && transport != "WEBSOCKET")
	{
	  ui.so_rcvbuf->setEnabled(true);
	  ui.so_sndbuf->setEnabled(true);
	}
      else
	{
	  ui.so_rcvbuf->setEnabled(false);
	  ui.so_rcvbuf->setToolTip(tr("SCTP, TCP, UDP listeners only."));
	  ui.so_sndbuf->setEnabled(false);
	  ui.so_sndbuf->setToolTip(tr("SCTP, TCP, UDP listeners only."));
	}

#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
      if(transport == "WEBSOCKET")
	{
	  ui.so_rcvbuf->setEnabled(true);
	  ui.so_rcvbuf->setToolTip("");
	  ui.so_sndbuf->setEnabled(true);
	  ui.so_sndbuf->setToolTip("");
	}
#endif
    }
  else
    {
      if(transport != "BLUETOOTH" && transport != "WEBSOCKET")
	{
	  ui.so_rcvbuf->setEnabled(true);
	  ui.so_sndbuf->setEnabled(true);
	}
      else
	{
	  ui.so_rcvbuf->setEnabled(false);
	  ui.so_rcvbuf->setToolTip(tr("SCTP, TCP, UDP neighbors only."));
	  ui.so_sndbuf->setEnabled(false);
	  ui.so_sndbuf->setToolTip(tr("SCTP, TCP, UDP neighbors only."));
	}
    }

#ifndef SPOTON_SCTP_ENABLED
  if(transport == "SCTP")
    {
      ui.so_rcvbuf->setEnabled(false);
      ui.so_rcvbuf->setToolTip(tr("SCTP is not available."));
      ui.so_sndbuf->setEnabled(false);
      ui.so_sndbuf->setToolTip(tr("SCTP is not available."));
    }
#endif

#ifdef Q_OS_WIN
  ui.type_of_service->setEnabled(false);
  ui.type_of_service->setToolTip(tr("Not available on Windows."));
#endif

  foreach(const QString &string, list)
    if(string.startsWith("ip_tos="))
      {
	if(ui.type_of_service->isEnabled())
	  {
	    QString str(string.mid(static_cast<int> (qstrlen("ip_tos="))));

	    ui.type_of_service->setCurrentIndex(str.toInt() / 32);
	  }
      }
    else if(string.startsWith("nodelay="))
      {
	if(ui.nodelay->isEnabled())
	  ui.nodelay->setChecked
	    (string.mid(static_cast<int> (qstrlen("nodelay="))).toInt());
      }
    else if(string.startsWith("so_keepalive="))
      {
	if(ui.so_keepalive->isEnabled())
	  ui.so_keepalive->setChecked
	    (string.mid(static_cast<int> (qstrlen("so_keepalive="))).toInt());
      }
    else if(string.startsWith("so_linger="))
      {
	if(ui.so_linger->isEnabled())
	  ui.so_linger->setValue
	    (string.mid(static_cast<int> (qstrlen("so_linger="))).toInt());
      }
    else if(string.startsWith("so_rcvbuf="))
      {
	if(ui.so_rcvbuf->isEnabled())
	  ui.so_rcvbuf->setValue
	    (string.mid(static_cast<int> (qstrlen("so_rcvbuf="))).toInt());
      }
    else if(string.startsWith("so_sndbuf="))
      {
	if(ui.so_sndbuf->isEnabled())
	  ui.so_sndbuf->setValue
	    (string.mid(static_cast<int> (qstrlen("so_sndbuf="))).toInt());
      }
    else if(string.startsWith("so_timestamping="))
      {
	if(ui.so_timestamping->isEnabled())
	  ui.so_timestamping->setChecked
	    (string.
	     mid(static_cast<int> (qstrlen("so_timestamping="))).toInt());
      }

  if(dialog.exec() != QDialog::Accepted)
    {
      QApplication::processEvents();
      return;
    }

  QApplication::processEvents();
  socketOptions.clear();

  if(ui.nodelay->isEnabled())
    {
      socketOptions.append(QString("nodelay=%1").arg(ui.nodelay->isChecked()));
      socketOptions.append(";");
    }

  if(ui.so_keepalive->isEnabled())
    {
      socketOptions.append
	(QString("so_keepalive=%1").arg(ui.so_keepalive->isChecked()));
      socketOptions.append(";");
    }

  if(ui.so_linger->isEnabled())
    {
      socketOptions.append(QString("so_linger=%1").arg(ui.so_linger->value()));
      socketOptions.append(";");
    }

  if(ui.so_rcvbuf->isEnabled())
    {
      socketOptions.append(QString("so_rcvbuf=%1").arg(ui.so_rcvbuf->value()));
      socketOptions.append(";");
    }

  if(ui.so_sndbuf->isEnabled())
    {
      socketOptions.append(QString("so_sndbuf=%1").arg(ui.so_sndbuf->value()));
      socketOptions.append(";");
    }

  if(ui.so_timestamping->isEnabled())
    {
      socketOptions.append
	(QString("so_timestamping=%1").arg(ui.so_timestamping->isChecked()));
      socketOptions.append(";");
    }

  if(ui.type_of_service->isEnabled())
    {
      socketOptions.append
	(QString("ip_tos=%1").
	 arg(ui.type_of_service->currentText().
	     mid(0, ui.type_of_service->currentText().indexOf(' '))));
      socketOptions.append(";");
    }

  if(socketOptions.endsWith(";"))
    socketOptions = socketOptions.mid(0, socketOptions.length() - 1);

  QString connectionName("");

  {
    QSqlDatabase db = spoton_misc::database(connectionName);

    db.setDatabaseName(spoton_misc::homePath() +
		       QDir::separator() +
		       QString("%1.db").arg(type));

    if(db.open())
      {
	QSqlQuery query(db);

	query.prepare
	  (QString("UPDATE %1 SET socket_options = ? WHERE OID = ?").arg(type));
	query.addBindValue(socketOptions);
	query.addBindValue(oid);
	query.exec();
      }

    db.close();
  }

  QSqlDatabase::removeDatabase(connectionName);
}

void spoton::slotShowErrorMessage(void)
{
  QTimer *timer = qobject_cast<QTimer *> (sender());

  if(!timer)
    return;

  QString str(timer->property("text").toString().trimmed());

  timer->deleteLater();
  QMessageBox::critical
    (this, tr("%1: Error").arg(SPOTON_APPLICATION_NAME), str);
  QApplication::processEvents();
}

void spoton::slotShowReleaseNotes(void)
{
  spoton_utilities::centerWidget(m_releaseNotes, this);
  m_releaseNotes->showNormal();
  m_releaseNotes->activateWindow();
  m_releaseNotes->raise();
}

void spoton::slotStyleSheetChanged(int index)
{
  m_settings["gui/theme"] = index;

  QSettings settings;

  settings.setValue("gui/theme", index);
  prepareStyleSheet();
}

void spoton::slotTerminateKernelOnUIExit(bool state)
{
  m_settings["gui/terminate_kernel_on_ui_exit"] = state;

  QSettings settings;

  settings.setValue("gui/terminate_kernel_on_ui_exit", state);
}

void spoton::slotWebServerAllowServingLocalContent(bool state)
{
  m_settings["gui/web_server_serve_local_content"] = state;

  QSettings settings;

  settings.setValue("gui/web_server_serve_local_content", state);
}

void spoton::slotWebServerInformationTimeout(void)
{
  if(m_ui.web_server_port->value() == 0)
    {
      m_ui.web_server_information_label->clear();
      m_ui.web_server_information_label->setVisible(false);
    }
  else
    {
      m_ui.web_server_information_label->setText
	(tr("The Spot-On Search Engine may be accessed via "
	    "<a href=\"http://%1:%2\">http://%1:%2</a> and "
	    "<a href=\"https://%1:%3\">https://%1:%3</a>.").
	 arg(spoton_misc::localAddressIPv4().toString()).
	 arg(m_ui.web_server_port->value()).
	 arg(m_ui.web_server_port->value() + 5));
      m_ui.web_server_information_label->setVisible(true);
    }
}

void spoton::slotWebServerPortChanged(int value)
{
  Q_UNUSED(value);
  connect(&m_webServerValueChangedTimer,
	  SIGNAL(timeout(void)),
	  this,
	  SLOT(slotWebServerValueChangedTimeout(void)),
	  Qt::UniqueConnection);
  m_webServerValueChangedTimer.setSingleShot(true);
  m_webServerValueChangedTimer.start(2500);
}

void spoton::slotWebServerValueChangedTimeout(void)
{
  int value = m_ui.web_server_port->value();

  m_settings["gui/web_server_port"] = value;

  QSettings settings;

  settings.setValue("gui/web_server_port", value);

  if(value == 0)
    {
      QString connectionName("");

      {
	QSqlDatabase db = spoton_misc::database(connectionName);

	db.setDatabaseName(spoton_misc::homePath() +
			   QDir::separator() +
			   "kernel_web_server.db");

	if(db.open())
	  {
	    QSqlQuery query(db);

	    query.exec("PRAGMA secure_delete = ON");
	    query.exec("DELETE FROM kernel_web_server");
	  }

	db.close();
      }

      QSqlDatabase::removeDatabase(connectionName);
    }
  else
    {
      spoton_crypt *crypt = m_crypts.value("chat", 0);

      if(!crypt)
	{
	  QMessageBox::critical
	    (this, tr("%1: Error").arg(SPOTON_APPLICATION_NAME),
	     tr("Invalid spoton_crypt object. This is a fatal flaw."));
	  QApplication::processEvents();
	  return;
	}

      QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

      QByteArray certificate;
      QByteArray privateKey;
      QByteArray publicKey;
      QString error("");

      m_sb.status->setText
	(tr("Generating %1-bit SSL/TLS data. Please be patient.").
	 arg(m_settings.value("WEB_SERVER_KEY_SIZE",
			      spoton_common::WEB_SERVER_KEY_SIZE).
	     toInt()));
      m_sb.status->repaint();
      spoton_crypt::generateSslKeys
	(m_settings.value("WEB_SERVER_KEY_SIZE",
			  spoton_common::WEB_SERVER_KEY_SIZE).toInt(),
	 certificate,
	 privateKey,
	 publicKey,
	 spoton_misc::localAddressIPv4(),
	 m_settings.value("WEB_SERVER_CERTIFICATE_LIFETIME",
			  static_cast<int> (spoton_common::
					    WEB_SERVER_CERTIFICATE_LIFETIME)).
	 toInt(),
	 error);
      m_sb.status->clear();

      if(error.isEmpty())
	{
	  QString connectionName("");

	  {
	    QSqlDatabase db = spoton_misc::database(connectionName);

	    db.setDatabaseName(spoton_misc::homePath() +
			       QDir::separator() +
			       "kernel_web_server.db");

	    if(db.open())
	      {
		QSqlQuery query(db);
		bool ok = true;

		query.prepare("INSERT INTO kernel_web_server "
			      "(certificate, private_key) "
			      "VALUES (?, ?)");
		query.addBindValue
		  (crypt->encryptedThenHashed(certificate, &ok).toBase64());
		query.addBindValue
		  (crypt->encryptedThenHashed(privateKey, &ok).toBase64());
		query.exec();
	      }

	    db.close();
	  }

	  QSqlDatabase::removeDatabase(connectionName);
	}
      else
	{
	  m_sb.status->setText(tr("Error generating Web Server credentials."));
	  QTimer::singleShot(5000, m_sb.status, SLOT(clear(void)));
	}

      QApplication::restoreOverrideCursor();
    }
}
