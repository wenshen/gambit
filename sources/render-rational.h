//
// $Source$
// $Date$
// $Revision$
//
// DESCRIPTION:
// Declaration of wxSheet renderer for rational numbers
//
// This file is part of Gambit
// Copyright (c) 2005, The Gambit Project
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//

#ifndef RENDER_RATIONAL_H
#define RENDER_RATIONAL_H

#include "sheet.h"     // the wxSheet widget

//
// This class is based on the wxSheetCellStringRendererRefData implementation
//
class gbtRationalRendererRefData : public wxSheetCellRendererRefData {
public:
  gbtRationalRendererRefData(void) { }
    
  // draw the string
  virtual void Draw(wxSheet& grid, const wxSheetCellAttr& attr,
		    wxDC& dc, const wxRect& rect, 
		    const wxSheetCoords& coords, bool isSelected);

  // return the string extent
  virtual wxSize GetBestSize(wxSheet& grid, const wxSheetCellAttr& attr,
			     wxDC& dc, const wxSheetCoords& coords);

  void DoDraw(wxSheet& grid, const wxSheetCellAttr& attr,
	      wxDC& dc, const wxRect& rect, 
	      const wxSheetCoords& coords, bool isSelected);

  // set the text colours before drawing
  void SetTextColoursAndFont(wxSheet& grid, const wxSheetCellAttr& attr,
			     wxDC& dc, bool isSelected);

  // calc the string extent for given string/font
  wxSize DoGetBestSize(wxSheet& grid, const wxSheetCellAttr& attr, 
		       wxDC& dc, const wxString& text);

  bool Copy(const gbtRationalRendererRefData& other) 
  { return wxSheetCellRendererRefData::Copy(other); }
  DECLARE_SHEETOBJREFDATA_COPY_CLASS(gbtRationalRendererRefData, 
				     wxSheetCellRendererRefData)
};

#endif  // RENDER_RATIONAL_H
