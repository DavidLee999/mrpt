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
#include "CPanelCameraSelection.h"

//(*InternalHeaders(CPanelCameraSelection)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CPanelCameraSelection)
const long CPanelCameraSelection::ID_STATICTEXT1 = wxNewId();
const long CPanelCameraSelection::ID_SPINCTRL1 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT3 = wxNewId();
const long CPanelCameraSelection::ID_CHOICE1 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT6 = wxNewId();
const long CPanelCameraSelection::ID_CHOICE2 = wxNewId();
const long CPanelCameraSelection::ID_PANEL2 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT7 = wxNewId();
const long CPanelCameraSelection::ID_TEXTCTRL1 = wxNewId();
const long CPanelCameraSelection::ID_PANEL3 = wxNewId();
const long CPanelCameraSelection::ID_TEXTCTRL6 = wxNewId();
const long CPanelCameraSelection::ID_PANEL4 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT8 = wxNewId();
const long CPanelCameraSelection::ID_TEXTCTRL2 = wxNewId();
const long CPanelCameraSelection::ID_BUTTON7 = wxNewId();
const long CPanelCameraSelection::ID_PANEL5 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT9 = wxNewId();
const long CPanelCameraSelection::ID_TEXTCTRL3 = wxNewId();
const long CPanelCameraSelection::ID_BUTTON8 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT5 = wxNewId();
const long CPanelCameraSelection::ID_TEXTCTRL7 = wxNewId();
const long CPanelCameraSelection::ID_BUTTON9 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT10 = wxNewId();
const long CPanelCameraSelection::ID_TEXTCTRL8 = wxNewId();
const long CPanelCameraSelection::ID_STATICTEXT11 = wxNewId();
const long CPanelCameraSelection::ID_PANEL6 = wxNewId();
const long CPanelCameraSelection::ID_RADIOBOX1 = wxNewId();
const long CPanelCameraSelection::ID_CHECKBOX1 = wxNewId();
const long CPanelCameraSelection::ID_PANEL7 = wxNewId();
const long CPanelCameraSelection::ID_NOTEBOOK1 = wxNewId();
const long CPanelCameraSelection::ID_CHECKBOX2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CPanelCameraSelection,wxPanel)
	//(*EventTable(CPanelCameraSelection)
	//*)
END_EVENT_TABLE()

CPanelCameraSelection::CPanelCameraSelection(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(CPanelCameraSelection)
	wxFlexGridSizer* FlexGridSizer16;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer18;
	wxFlexGridSizer* FlexGridSizer13;
	wxFlexGridSizer* FlexGridSizer12;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;
	
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	pagesCameras = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxNB_MULTILINE, _T("ID_NOTEBOOK1"));
	Panel2 = new wxPanel(pagesCameras, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer10 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer10->AddGrowableCol(1);
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Camera index:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer10->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	opencvCamIndex = new wxSpinCtrl(Panel2, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL1"));
	opencvCamIndex->SetValue(_T("0"));
	FlexGridSizer10->Add(opencvCamIndex, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Camera type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer10->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cbOpencvCamType = new wxChoice(Panel2, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	cbOpencvCamType->SetSelection( cbOpencvCamType->Append(_("CAMERA_CV_AUTODETECT")) );
	cbOpencvCamType->Append(_("CAMERA_CV_DC1394"));
	cbOpencvCamType->Append(_("CAMERA_CV_VFL"));
	cbOpencvCamType->Append(_("CAMERA_CV_VFW"));
	cbOpencvCamType->Append(_("CAMERA_CV_MIL"));
	cbOpencvCamType->Append(_("CAMERA_CV_DSHOW"));
	FlexGridSizer10->Add(cbOpencvCamType, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("Resolution:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer10->Add(StaticText6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	cbOpencvResolution = new wxChoice(Panel2, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	cbOpencvResolution->SetSelection( cbOpencvResolution->Append(_("default")) );
	cbOpencvResolution->Append(_("320x240"));
	cbOpencvResolution->Append(_("640x480"));
	FlexGridSizer10->Add(cbOpencvResolution, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel2->SetSizer(FlexGridSizer10);
	FlexGridSizer10->Fit(Panel2);
	FlexGridSizer10->SetSizeHints(Panel2);
	Panel3 = new wxPanel(pagesCameras, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer11 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer11->AddGrowableCol(0);
	StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("IP Camera URL:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer11->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	edIPcamURL = new wxTextCtrl(Panel3, ID_TEXTCTRL1, _("rtsp://192.168.0.1/live.sdp"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer11->Add(edIPcamURL, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(FlexGridSizer11);
	FlexGridSizer11->Fit(Panel3);
	FlexGridSizer11->SetSizeHints(Panel3);
	Panel4 = new wxPanel(pagesCameras, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	FlexGridSizer16 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer16->AddGrowableCol(0);
	FlexGridSizer16->AddGrowableRow(0);
	edCustomCamConfig = new wxTextCtrl(Panel4, ID_TEXTCTRL6, _("// Configuration block for the CCameraSensor object.\n// Check out its documentation at:\n// http://reference.mrpt.org/svn/classmrpt_1_1hwdrivers_1_1_c_camera_sensor.html\n\n[CONFIG]\ngrabber_type = opencv \ncv_camera_index = 0\ncv_camera_type = CAMERA_CV_AUTODETECT\n\n"), wxDefaultPosition, wxDefaultSize, wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxHSCROLL|wxTE_DONTWRAP|wxVSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	wxFont edCustomCamConfigFont = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
	if ( !edCustomCamConfigFont.Ok() ) edCustomCamConfigFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
	edCustomCamConfigFont.SetPointSize(7);
	edCustomCamConfig->SetFont(edCustomCamConfigFont);
	FlexGridSizer16->Add(edCustomCamConfig, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel4->SetSizer(FlexGridSizer16);
	FlexGridSizer16->Fit(Panel4);
	FlexGridSizer16->SetSizeHints(Panel4);
	Panel5 = new wxPanel(pagesCameras, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	FlexGridSizer12 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer12->AddGrowableCol(0);
	StaticText8 = new wxStaticText(Panel5, ID_STATICTEXT8, _("Video file to open:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer12->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	edVideoFile = new wxTextCtrl(Panel5, ID_TEXTCTRL2, _("test.avi"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer12->Add(edVideoFile, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnBrowseVideo = new wxButton(Panel5, ID_BUTTON7, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	FlexGridSizer12->Add(btnBrowseVideo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel5->SetSizer(FlexGridSizer12);
	FlexGridSizer12->Fit(Panel5);
	FlexGridSizer12->SetSizeHints(Panel5);
	Panel6 = new wxPanel(pagesCameras, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	FlexGridSizer13 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer13->AddGrowableCol(1);
	StaticText9 = new wxStaticText(Panel6, ID_STATICTEXT9, _("Rawlog \nfile:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer13->Add(StaticText9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	edRawlogFile = new wxTextCtrl(Panel6, ID_TEXTCTRL3, _("test.rawlog"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer13->Add(edRawlogFile, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnBrowseRawlog = new wxButton(Panel6, ID_BUTTON8, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	FlexGridSizer13->Add(btnBrowseRawlog, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel6, ID_STATICTEXT5, _("External \nimages:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer13->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	edRawlogImgDir = new wxTextCtrl(Panel6, ID_TEXTCTRL7, _("./Images"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	FlexGridSizer13->Add(edRawlogImgDir, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnBrowseRawlogDir = new wxButton(Panel6, ID_BUTTON9, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	FlexGridSizer13->Add(btnBrowseRawlogDir, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(Panel6, ID_STATICTEXT10, _("Sensor\nlabel:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer13->Add(StaticText10, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	edRawlogLabel = new wxTextCtrl(Panel6, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	FlexGridSizer13->Add(edRawlogLabel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(Panel6, ID_STATICTEXT11, _("(empty=any)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer13->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel6->SetSizer(FlexGridSizer13);
	FlexGridSizer13->Fit(Panel6);
	FlexGridSizer13->SetSizeHints(Panel6);
	Panel1 = new wxPanel(pagesCameras, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
	FlexGridSizer18 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString __wxRadioBoxChoices_1[2] = 
	{
		_("Left"),
		_("Right")
	};
	rbBumblebeeSel = new wxRadioBox(Panel1, ID_RADIOBOX1, _("Select monocular input"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	rbBumblebeeSel->SetSelection(0);
	FlexGridSizer18->Add(rbBumblebeeSel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cbBumblebeeRectif = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Use vendor\'s rectify"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	cbBumblebeeRectif->SetValue(false);
	FlexGridSizer18->Add(cbBumblebeeRectif, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 10);
	Panel1->SetSizer(FlexGridSizer18);
	FlexGridSizer18->Fit(Panel1);
	FlexGridSizer18->SetSizeHints(Panel1);
	pagesCameras->AddPage(Panel2, _("Camera (opencv)"), false);
	pagesCameras->AddPage(Panel3, _("Camera (FFmpeg)"), false);
	pagesCameras->AddPage(Panel4, _("Camera (custom)"), false);
	pagesCameras->AddPage(Panel5, _("Video file"), false);
	pagesCameras->AddPage(Panel6, _("Rawlog file"), false);
	pagesCameras->AddPage(Panel1, _("Bumblebee"), false);
	FlexGridSizer1->Add(pagesCameras, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbGrayscale = new wxCheckBox(this, ID_CHECKBOX2, _("Capture in grayscale"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	cbGrayscale->SetValue(true);
	FlexGridSizer1->Add(cbGrayscale, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CPanelCameraSelection::OnbtnBrowseVideoClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CPanelCameraSelection::OnbtnBrowseRawlogClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CPanelCameraSelection::OnbtnBrowseRawlogDirClick);
	//*)
}

CPanelCameraSelection::~CPanelCameraSelection()
{
	//(*Destroy(CPanelCameraSelection)
	//*)
}

