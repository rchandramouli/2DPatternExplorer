/*
  frmcurve.cpp: Draws the function in the drawing area.
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

#include "frmcurve.h"

#include <math.h>
#include <qdialog.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qpixmap.h>
#include <qpainter.h>

frmDraw::frmDraw( QWidget* parent, const char* name, WFlags fl )
  : QWidget( parent, name, fl )
{
  QSize s (800, 600);

  if ( !name )
    setName( "frmDraw" );

  cmdDraw = new QPushButton( this, "cmdDraw" );
  cmdDraw->setGeometry( QRect( 10, 10, 291, 31 ) );
  cmdDraw->setText ("Draw Pattern");

  scribPad = new Space (s, this);
  scribPad->setGeometry (QRect (10, 50, 810, 660));
  resize( QSize(530, 570).expandedTo(minimumSizeHint()) );

  // signals and slots connections
  connect (cmdDraw, SIGNAL (clicked ()), this, SLOT (genPattern ()));
}

frmDraw::~frmDraw()
{
}

void
frmDraw::genPattern ()
{
  QPainter p;
  QSize s = scribPad->getHW ();

  p.begin (scribPad->surface);

  /*
    Comment this "#define" if you donot want the pattern to be drawn 
    symmetrically.
  */
#define SYMMETRY
#ifdef SYMMETRY
  for (long long int x=0; x<=s.width ()/2; x++)
    for (long long int y=0; y<=s.height ()/2; y++)
#else
  for (long long int x=0; x<=s.width (); x++)
    for (long long int y=0; y<=s.height (); y++)
#endif
      {
	/* Plug in various functions here */
	QColor clr (x+y);

	p.setPen (clr);
	p.drawPoint (x, y);
#ifdef SYMMETRY
	p.drawPoint (s.width ()-x, y);
	p.drawPoint (x, s.height ()-y);
	p.drawPoint (s.width ()-x, s.height ()-y);
#endif
      }

  p.end ();
  scribPad->paintPicture ();
}
