//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC38D8InitBitmapResources();

static bool bBitmapLoaded = false;


SvnCommitDialogBaseClass::SvnCommitDialogBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC38D8InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    wxFlexGridSizer* flexGridSizer5 = new wxFlexGridSizer(  0, 2, 0, 0);
    flexGridSizer5->SetFlexibleDirection( wxBOTH );
    flexGridSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer5->AddGrowableCol(1);
    
    boxSizer1->Add(flexGridSizer5, 0, wxALL|wxEXPAND, 5);
    
    m_staticText32 = new wxStaticText(this, wxID_ANY, _("Feature Request ID:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer5->Add(m_staticText32, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
    m_textCtrlFrID = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer5->Add(m_textCtrlFrID, 0, wxEXPAND|wxALL, 5);
    
    m_staticTextBugID = new wxStaticText(this, wxID_ANY, _("Bug ID:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer5->Add(m_staticTextBugID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
    m_textCtrlBugID = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer5->Add(m_textCtrlBugID, 0, wxEXPAND|wxALL, 5);
    
    m_splitter1 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxSP_LIVE_UPDATE|wxSP_3DSASH);
    m_splitter1->SetSashGravity(0.500000);
    m_splitter1->SetMinimumPaneSize(10);
    
    boxSizer1->Add(m_splitter1, 1, wxALL|wxEXPAND, 5);
    
    m_panel1 = new wxPanel(m_splitter1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer15 = new wxBoxSizer(wxVERTICAL);
    m_panel1->SetSizer(boxSizer15);
    
    m_staticText17 = new wxStaticText(m_panel1, wxID_ANY, _("Modified Paths:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer15->Add(m_staticText17, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    
    wxArrayString m_checkListFilesArr;
    m_checkListFiles = new wxCheckListBox(m_panel1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_checkListFilesArr, wxLB_SINGLE);
    
    boxSizer15->Add(m_checkListFiles, 1, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_splitterPage14 = new wxPanel(m_splitter1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitter1->SplitVertically(m_panel1, m_splitterPage14, 0);
    
    wxBoxSizer* boxSizer16 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage14->SetSizer(boxSizer16);
    
    m_staticText19 = new wxStaticText(m_splitterPage14, wxID_ANY, _("Message:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer16->Add(m_staticText19, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    
    m_textCtrlMessage = new wxTextCtrl(m_splitterPage14, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_RICH2|wxTE_PROCESS_ENTER|wxTE_MULTILINE);
    wxFont m_textCtrlMessageFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_textCtrlMessage->SetFont(m_textCtrlMessageFont);
    
    boxSizer16->Add(m_textCtrlMessage, 1, wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxStaticBoxSizer* statixBoxSizer24 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Recent commit messages:")), wxVERTICAL);
    
    boxSizer1->Add(statixBoxSizer24, 0, wxEXPAND|wxALL, 5);
    
    wxArrayString m_choiceMessagesArr;
    m_choiceMessages = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_choiceMessagesArr, 0);
    
    statixBoxSizer24->Add(m_choiceMessages, 0, wxEXPAND|wxALL, 5);
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer1->Add(boxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    
    m_button3 = new wxButton(this, wxID_OK, _("C&ommit"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button3->SetDefault();
    m_button3->SetToolTip(_("Commit"));
    
    boxSizer2->Add(m_button3, 0, wxALL, 5);
    
    m_button4 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer2->Add(m_button4, 0, wxALL, 5);
    
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_choiceMessages->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnChoiceMessage), NULL, this);
    
}

SvnCommitDialogBaseClass::~SvnCommitDialogBaseClass()
{
    m_choiceMessages->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnChoiceMessage), NULL, this);
    
}

SvnSyncDialogBaseClass::SvnSyncDialogBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC38D8InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer26 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer26);
    
    wxBoxSizer* boxSizer32 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer26->Add(boxSizer32, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    
    m_staticText31 = new wxStaticText(this, wxID_ANY, _("Root URL:"), wxDefaultPosition, wxSize(-1,-1), 0);
    wxFont m_staticText31Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText31Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText31->SetFont(m_staticText31Font);
    
    boxSizer32->Add(m_staticText31, 0, wxALL, 5);
    
    m_staticTextSvnInfo = new wxStaticText(this, wxID_ANY, _("<none detected>"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer32->Add(m_staticTextSvnInfo, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer37 = new wxFlexGridSizer(  0, 2, 0, 0);
    flexGridSizer37->SetFlexibleDirection( wxBOTH );
    flexGridSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer37->AddGrowableCol(1);
    
    boxSizer26->Add(flexGridSizer37, 0, wxALL|wxEXPAND, 5);
    
    m_staticText34 = new wxStaticText(this, wxID_ANY, _("Root Directory:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer37->Add(m_staticText34, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
    m_dirPickerRootDir = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxSize(-1,-1), wxDIRP_DEFAULT_STYLE);
    
    flexGridSizer37->Add(m_dirPickerRootDir, 0, wxEXPAND|wxALL, 5);
    
    m_staticText40 = new wxStaticText(this, wxID_ANY, _("Exclude these file extensions:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer37->Add(m_staticText40, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
    m_textCtrlExclude = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_RICH2);
    
    flexGridSizer37->Add(m_textCtrlExclude, 0, wxEXPAND|wxALL, 5);
    
    flexGridSizer37->Add(0, 0, 0, wxALL, 5);
    
    m_checkBoxBin = new wxCheckBox(this, wxID_ANY, _("Exclude binary (application/octet-stream) files"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxBin->SetValue(false);
    
    flexGridSizer37->Add(m_checkBoxBin, 0, wxALL, 5);
    
    boxSizer26->Add(0, 0, 1, wxEXPAND|wxALL, 5);
    
    wxBoxSizer* boxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer26->Add(boxSizer27, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    
    m_button28 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button28->SetDefault();
    
    boxSizer27->Add(m_button28, 0, wxALL, 5);
    
    m_button29 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer27->Add(m_button29, 0, wxALL, 5);
    
    
    SetSizeHints(500,200);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_button28->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnSyncDialogBaseClass::OnOkUI), NULL, this);
    m_button28->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SvnSyncDialogBaseClass::OnButtonOK), NULL, this);
    
}

SvnSyncDialogBaseClass::~SvnSyncDialogBaseClass()
{
    m_button28->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnSyncDialogBaseClass::OnOkUI), NULL, this);
    m_button28->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SvnSyncDialogBaseClass::OnButtonOK), NULL, this);
    
}
