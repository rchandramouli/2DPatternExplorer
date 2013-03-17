#ifndef FRMDRAW_H
#define FRMDRAW_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>
#include "curves.h"

class Space;
class QPushButton;

class frmDraw : public QWidget
{
  Q_OBJECT

public:
  frmDraw(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
  ~frmDraw();

  QPushButton* cmdDraw;
  Space* scribPad;

private slots:
  void genPattern();
};

#endif // FRMDRAW_H
