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

#ifndef gridmapSimulMAIN_H
#define gridmapSimulMAIN_H

//(*Headers(gridmapSimulFrame)
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

class CMyGLCanvas;


#define GRIDMAPSIMUL_VERSION  "1.0"

class gridmapSimulFrame: public wxFrame
{
    public:

        gridmapSimulFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~gridmapSimulFrame();

    private:

        //(*Handlers(gridmapSimulFrame)
        void OnbtnQuitClick(wxCommandEvent& event);
        void OntimRunTrigger(wxTimerEvent& event);
        void OnbtnStartClick(wxCommandEvent& event);
        void OnbtnEndClick(wxCommandEvent& event);
        void OnbtnExploreClick(wxCommandEvent& event);
        void OnbtnSetLaserClick(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnResimulateClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(gridmapSimulFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT16;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT11;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT14;
        static const long ID_TEXTCTRL11;
        static const long ID_STATICTEXT4;
        static const long ID_BUTTON4;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_BUTTON6;
        static const long ID_PANEL3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT15;
        static const long ID_TEXTCTRL12;
        static const long ID_PANEL6;
        static const long ID_PANEL4;
        static const long ID_PANEL2;
        static const long ID_PANEL1;
        static const long ID_PANEL5;
        static const long ID_SPLITTERWINDOW1;
        static const long ID_TIMER1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        //*)
		static const long ID_TEXTCTRL_INPUT;

        //(*Declarations(gridmapSimulFrame)
        wxTextCtrl* edSpan;
        wxMenuItem* MenuItem1;
        wxTextCtrl* edOutGT;
        wxButton* btnExplore;
        wxSpinCtrl* edDecimate;
        wxPanel* Panel1;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
        wxMenu* Menu1;
        wxButton* btnSetLaser;
        wxCheckBox* cbJoy;
        wxTextCtrl* edAys;
        wxStaticText* StaticText1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText16;
        wxPanel* Panel2;
        wxSplitterWindow* SplitterWindow1;
        wxStaticText* StaticText3;
        wxPanel* Panel4;
        wxButton* btnExit;
        wxTextCtrl* edAyb;
        wxTextCtrl* edStdNoiseAng;
        wxButton* btnResimulate;
        wxPanel* Panel5;
        wxStaticText* StaticText8;
        wxTextCtrl* edOutFile;
        wxStaticText* StaticText12;
        wxTextCtrl* edCount;
        wxTimer timRun;
        wxPanel* Panel3;
        wxStaticText* StaticText7;
        wxTextCtrl* edStdNoise;
        wxStaticText* StaticText4;
        wxTextCtrl* edAxb;
        wxButton* btnEnd;
        wxStaticText* StaticText5;
        wxMenuBar* MenuBar1;
        wxStaticText* StaticText2;
        wxTextCtrl* edApb;
        wxPanel* panelGL;
        wxStaticText* StaticText6;
        wxMenu* Menu2;
        wxTextCtrl* edAps;
        wxTextCtrl* edAxs;
        wxButton* btnStart;
        wxStaticText* StaticText9;
        wxStaticText* StaticText11;
        //*)

        DECLARE_EVENT_TABLE()


        CMyGLCanvas		*m_canvas;
};


#ifdef wxUSE_UNICODE
#define _U(x) wxString((x),wxConvUTF8)
#define _UU(x,y) wxString((x),y)
#else
#define _U(x) (x)
#define _UU(x,y) (x)
#endif


#define WX_START_TRY \
    try \
    {


#define WX_END_TRY \
    } \
	catch(std::exception &e) \
    { \
        wxMessageBox( wxString(e.what(),wxConvUTF8), wxT("Exception"), wxOK, this); \
    } \
    catch(...) \
    { \
        wxMessageBox( _("Untyped exception!"), _("Exception"), wxOK, this); \
    }



#endif // gridmapSimulMAIN_H
