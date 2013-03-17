/*
  curves.h: "curves" widget header.
  Copyright (C) 2005  Ramasamy.C <ramasamy@phiepsilon.org>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef _CURVES_H_
#define _CURVES_H_

#include <qpainter.h>
#include <qpicture.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <math.h>

class Space : public QWidget
{
  Q_OBJECT

public:
  Space (QSize sz, QWidget *parent=0, const char *name=0,
	 WFlags f=(Qt::WResizeNoErase | Qt::WRepaintNoErase));
  ~Space ();

  QPixmap *surface;
  QSize   getHW ();

  void paintPicture (Qt::RasterOp p=Qt::CopyROP);

signals:
 void onPaint (void);

protected:
  void	paintEvent (QPaintEvent *);

private:
  Qt::RasterOp paintOption;
};

#endif // _CURVES_H_
