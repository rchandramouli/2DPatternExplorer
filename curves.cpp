/*
  curves.cpp: Implements painting of the widget.
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

#include "curves.h"

Space::Space (QSize sz, QWidget *parent, const char *name, WFlags f)
  : QWidget (parent, name, f)
{
  setFixedSize (sz);
  surface = new QPixmap (sz.width (), sz.height ());
}

Space::~Space ()
{
}

void
Space::paintEvent (QPaintEvent *)
{
  bitBlt (this, 0, 0, surface, 0, 0, -1, -1, paintOption, true);
}

QSize
Space::getHW ()
{
  return (size ());
}

void
Space::paintPicture (Qt::RasterOp rop)
{
  paintOption = rop;
  repaint (false);
}
