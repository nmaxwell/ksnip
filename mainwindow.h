/*
 *  Copyright (C) 2016 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "snippingarea.h"
#include "scribblearea.h"

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGraphicsScene;
class QGraphicsView;
class QClipboard;
class SnippingArea;
class QKeyEvent;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow();                                 /* Constructor                                                              */
    void show(QPixmap);                           /* Function used to show the widget, takes the image to present as argument */
    void show();
    
private slots:
    void newCaptureClicked();                     /* Slot called when the new capture button is clicked                       */
    void saveCaptureClicked();                    /* Slot called when the save button is clicked                              */
    void copyToClipboardClicked();                /* Slot called when the copy to clipboard button is clicked                 */
    void keyPressEvent(QKeyEvent *);
    void areaSelected(QRect);                     /* Slot called when the user finished selecting an capture area             */
       
private:
    QPushButton    *mNewCaptureButton;            /* Push button that starts new capture                                      */
    QPushButton    *mSaveButton;                  /* Button to save the captured image to disk                                */
    QPushButton    *mCopyToClipboardButton;       /* Button used to copy the image to clipboard                               */
    QHBoxLayout    *mButtonsLayout;               /* Layout used to organize all buttons on this widget                       */
    QVBoxLayout    *mWindowLayout;                /* Layout used to organize the overall widget layout                        */
    ScribbleArea   *mCaptureScene;                /* Graphics Scene used to present the captured image and allow editing      */ 
    QGraphicsView  *mCaptureView;                 /* Graphics view used to present the captured image and allow editing       */
    QClipboard     *mClipboard;                   /* Clipboard that is used to store capture images to the OS clipboard       */
    SnippingArea   *mSnippingArea;
    QPixmap         grabScreen(QRect);            /* Function that captures the screen between the two QPoints      */
    void            delay( int ms );              /* Adds some delay to execution so that the screen can be updated */
};

#endif // MAINWINDOW_H