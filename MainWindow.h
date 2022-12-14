#pragma once

#include "Board.h"
#include "ControllerBoard.h"
#include "Pixel.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <qcolor.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qpainter.h>
#include <QPainter>
#include <QTimer>
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  // A macro that allows the property to be used in QML.
  Q_OBJECT

  // A macro that allows the property to be used in QML.
  Q_PROPERTY(QColor color READ color NOTIFY colorChanged);

 public:
  /**
  * @brief Main constructor.
  * @param ControllerBoard  pointer to class who control pixel board.
  * @param QWidget default parameter in qt.
  */
  MainWindow(ControllerBoard *pBControllerBoard, QWidget *parent = nullptr);

  ~MainWindow();

  /**
  * @brief This is a getter function for the color property.
  */
  QColor color() const {
    return colorMax;
  }

  signals:

      /**
      * @brief This is a signal that is emitted when the color property changes.
      * @param QColor color property.
      */
      void colorChanged(QColor arg);
 private
  slots:

      /**
      * @brief This is a slot that is called when the color property changes.
      */
      void onColorChanged();

  /**
  * @brief This is a slot that is called when comboBox property changes.
  * @param index comboBox property.
  */
  void comboBoxActivityChanged(int index);

  /**
  * @brief This is a slot that is called when comboBox property changes.
  * @param index comboBox property.
  */
  void comboBoxTimeChanged(int index);

  /**
  * @brief This is a slot that is called when the timer is triggered.
  */
  void timeChanged();

 private:

  /**
  * @brief This is a pointer to the class that is generated by Qt Designer.
  */
  Ui::mainwindowClass ui;

  /**
  * @brief This is a pointer to the class for control pixel board.
  */
  ControllerBoard *pControllerBoard;

  /**
  * @brief This is a pointer to class QTimer, for control change state in pixel board.
  */
  QTimer *timer;

  /**
  * @brief Parameter for store time.
  * @param sec second.
  * @param min minutes.
  */
  int sec, min;

  /**
  * @brief value for store max color state.
  */
  QColor colorMax;

  /**
  * @brief value for store min color state.
  */
  QColor colorMin;

};
