/* +---------------------------------------------------------------------------+
   |          The Mobile Robot Programming Toolkit (MRPT) C++ library          |
   |                                                                           |
   |                   http://mrpt.sourceforge.net/                            |
   |                                                                           |
   |   Copyright (C) 2005-2010  University of Malaga                           |
   |                                                                           |
   |    This software was written by the Machine Perception and Intelligent    |
   |      Robotics Lab, University of Malaga (Spain).                          |
   |    Contact: Jose-Luis Blanco  <jlblanco@ctima.uma.es>                     |
   |                                                                           |
   |  This file is part of the MRPT project.                                   |
   |                                                                           |
   |     MRPT is free software: you can redistribute it and/or modify          |
   |     it under the terms of the GNU General Public License as published by  |
   |     the Free Software Foundation, either version 3 of the License, or     |
   |     (at your option) any later version.                                   |
   |                                                                           |
   |   MRPT is distributed in the hope that it will be useful,                 |
   |     but WITHOUT ANY WARRANTY; without even the implied warranty of        |
   |     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
   |     GNU General Public License for more details.                          |
   |                                                                           |
   |     You should have received a copy of the GNU General Public License     |
   |     along with MRPT.  If not, see <http://www.gnu.org/licenses/>.         |
   |                                                                           |
   +---------------------------------------------------------------------------+ */
#ifndef CFORMRAWMAP_H
#define CFORMRAWMAP_H

//(*Headers(CFormRawMap)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

// The "custom class" mpWindow, from the wxMathPlot libray by David Schalig
//  See http://sourceforge.net/projects/wxmathplot
#include <mrpt/otherlibs/mathplot/mathplot.h>

#include <mrpt/gui/CDisplayWindow3D.h>


class CFormRawMap: public wxDialog
{
public:

    CFormRawMap(wxWindow* parent,wxWindowID id = -1);
    virtual ~CFormRawMap();

    //(*Identifiers(CFormRawMap)
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT1;
    static const long ID_SLIDER1;
    static const long ID_SPINCTRL1;
    static const long ID_STATICTEXT3;
    static const long ID_SLIDER2;
    static const long ID_SPINCTRL2;
    static const long ID_STATICTEXT10;
    static const long ID_SLIDER3;
    static const long ID_SPINCTRL3;
    static const long ID_BUTTON2;
    static const long ID_BUTTON6;
    static const long ID_BUTTON5;
    static const long ID_BUTTON1;
    static const long ID_BUTTON3;
    static const long ID_BUTTON7;
    static const long ID_BUTTON8;
    static const long ID_BUTTON9;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT2;
    static const long ID_BITMAPBUTTON1;
    static const long ID_BUTTON4;
    static const long ID_TEXTCTRL1;
    static const long ID_PANEL1;
    static const long ID_CUSTOM2;
    static const long ID_PANEL3;
    //*)

public:

    //(*Handlers(CFormRawMap)
    void OnslFromCmdScrollThumbTrack(wxScrollEvent& event);
    void OnslToCmdScrollThumbTrack(wxScrollEvent& event);
    void OnbtnGenerateClick(wxCommandEvent& event);
    void OnbtnSaveTxtClick(wxCommandEvent& event);
    void OnbtnSave3DClick(wxCommandEvent& event);
    void OnbtnCloseClick(wxCommandEvent& event);
    void OnslDecimateCmdScrollThumbTrack(wxScrollEvent& event);
    void OnslToCmdScroll(wxScrollEvent& event);
    void OnbtnGeneratePathsClick(wxCommandEvent& event);
    void OnGenerateFromRTK(wxCommandEvent& event);
    void OnbtnSavePathClick(wxCommandEvent& event);
    void OnbtnSaveObsPathClick(wxCommandEvent& event);
    void OnbtnView3DClick(wxCommandEvent& event);
    void OnbtnHelpClick(wxCommandEvent& event);
    //*)

    //(*Declarations(CFormRawMap)
    wxSlider* slDecimate;
    wxSpinCtrl* edDec;
    wxStaticText* StaticText2;
    wxStaticText* lbLength;
    wxButton* btnClose;
    wxSpinCtrl* edLast;
    wxSpinCtrl* edFirst;
    wxFlexGridSizer* FlexGridSizer3;
    wxStaticText* lbCount;
    wxStaticText* StaticText6;
    wxBitmapButton* btnHelp;
    wxButton* btnSavePath;
    wxFlexGridSizer* FlexGridSizer2;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxButton* btnGeneratePaths;
    wxButton* btnGenerate;
    wxButton* btnSave3D;
    wxPanel* Panel3;
    wxTextCtrl* edOpts;
    wxStaticText* StaticText5;
    mpWindow* plotMap;
    wxSlider* slFrom;
    wxSlider* slTo;
    wxBoxSizer* BoxSizer1;
    wxButton* btnView3D;
    wxButton* btnSaveObsPath;
    wxPanel* Panel2;
    wxButton* btnSaveTxt;
    wxFlexGridSizer* FlexGridSizer1;
    wxStaticText* StaticText4;
    wxButton* btnGenerateRTK;
    //*)

private:


	mrpt::gui::CDisplayWindow3DPtr	win3Dmap;


    DECLARE_EVENT_TABLE()
};

#endif
