/*
 *    This file is part of the KDE project
 *    Copyright (c) 2002 Patrick Julien <freak@codepimps.org>
 *    Copyright (c) 2007 Jan Hambrecht <jaham@gmx.net>
 *    Copyright (c) 2007 Sven Langkamp <sven.langkamp@gmail.com>
 *    Copyright (C) 2011 Srikanth Tiyyagura <srikanth.tulasiram@gmail.com>
 *    Copyright (c) 2011 José Luis Vergara <pentalis@gmail.com>
 *    Copyright (c) 2013 Sascha Suelzer <s.suelzer@gmail.com>
 *    Copyright (c) 2019 Boudewijn Rempt <boud@valdyas.org> 
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Library General Public
 *    License as published by the Free Software Foundation; either
 *    version 2 of the License, or (at your option) any later version.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Library General Public License for more details.
 *
 *    You should have received a copy of the GNU Library General Public License
 *    along with this library; see the file COPYING.LIB.  If not, write to
 *    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *    Boston, MA 02110-1301, USA.
 */

#ifndef KISTAGCHOOSERWIDGET_H
#define KISTAGCHOOSERWIDGET_H

#include <QWidget>
#include "kritaresourcewidgets_export.h"

#include <KisTag.h>
#include <KisTagModel.h>

///
/// \brief The KisTagChooserWidget class is responsible
///
/// for all the logic that tags combobox has in various resource choosers.
/// (Example of usage: tag combobox in Brushes docker).
/// It uses KisTagModel as a model for items in the combobox.
/// It is also responsible for the popup for tag removal, renaming and creation
/// that appears on the right side of the tag combobox.
/// All the logic for adding and removing tags is done through KisTagModel.
///
/// For logic related to tagging and untagging resources, check KisTaggingManager
/// and KisItemChooserContextMenu.
///
class KRITARESOURCEWIDGETS_EXPORT KisTagChooserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KisTagChooserWidget(KisTagModel* model, QWidget* parent);
    ~KisTagChooserWidget() override;


    /// \brief setCurrentIndex sets the current index in the combobox
    /// \param index index is the
    ///
    void setCurrentIndex(int index);
    int currentIndex() const;

    /// \brief currentlySelectedTag returns the current tag from combobox
    /// \return the tag that is currently selected in the tag combobox
    ///
    KisTagSP currentlySelectedTag();
    ///
    /// \brief selectedTagIsReadOnly checks whether the tag is readonly (generated by Krita)
    /// \return true if the tag was generated by Krita, false if it's just a normal tag
    ///
    bool selectedTagIsReadOnly();
    void removeItem(KisTagSP item);
    void addItems(QList<KisTagSP> tagNames);
    void addReadOnlyItem(KisTagSP tagName);
    void clear();
    void setUndeletionCandidate(const KisTagSP tag);
    void showTagToolButton(bool show);

Q_SIGNALS:
    void newTagRequested(const KisTagSP tag);
    void tagDeletionRequested(const KisTagSP tag);
    void tagRenamingRequested(const KisTagSP oldTag, const KisTagSP newTag);
    void tagUndeletionRequested(const KisTagSP tag);
    void tagUndeletionListPurgeRequested();
    void popupMenuAboutToShow();
    void tagChosen(const KisTagSP tag);

public Q_SLOTS:
    KisTagSP insertItem(KisTagSP tag);
    void tagChanged(int index);


private Q_SLOTS:
    void tagRenamingRequested(const KisTagSP newName);
    void tagOptionsContextMenuAboutToShow();
    void contextDeleteCurrentTag();



private:
    class Private;
    Private* const d;

};
;

#endif // KOTAGCHOOSERWIDGET_H
