///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "syntaxhighlightbasedlg.h"

///////////////////////////////////////////////////////////////////////////

SyntaxHighlightBaseDlg::SyntaxHighlightBaseDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Output Panes and Terminals Global Settings:") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, _("Global foreground Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	fgSizer4->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_colourPickerOutputPanesFgColour = new wxColourPickerCtrl( this, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL|wxCLRP_USE_TEXTCTRL );
	m_colourPickerOutputPanesFgColour->SetToolTip( _("This is where you can set the foreground colour for the Output View panes (where you can see the output from e.g. 'Build' or 'Debug') and terminal (where you see the trace output while debugging)") );
	
	fgSizer4->Add( m_colourPickerOutputPanesFgColour, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText911 = new wxStaticText( this, wxID_ANY, _("Global background Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText911->Wrap( -1 );
	fgSizer4->Add( m_staticText911, 0, wxALL, 5 );
	
	m_colourPickerOutputPanesBgColour = new wxColourPickerCtrl( this, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL|wxCLRP_USE_TEXTCTRL );
	m_colourPickerOutputPanesBgColour->SetToolTip( _("This is where you can set the background colour for the Output View panes (where you can see the output from e.g. 'Build' or 'Debug') and terminal (where you see the trace output while debugging)") );
	
	fgSizer4->Add( m_colourPickerOutputPanesBgColour, 0, wxALL|wxEXPAND, 5 );
	
	sbSizer4->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer4, 0, wxEXPAND|wxALL, 10 );
	
	wxBoxSizer* buttonSizer;
	buttonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonOk = new wxButton( this, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonOk->SetDefault(); 
	buttonSizer->Add( m_buttonOk, 0, wxALL, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( m_buttonCancel, 0, wxALL, 5 );
	
	m_buttonApply = new wxButton( this, wxID_ANY, _("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonApply->SetToolTip( _("Apply the current changes to the editor without closing the dialog") );
	
	buttonSizer->Add( m_buttonApply, 0, wxALL, 5 );
	
	m_buttonDefaults = new wxButton( this, wxID_ANY, _("Defaults..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonDefaults->SetToolTip( _("Restore all lexers to default values") );
	
	buttonSizer->Add( m_buttonDefaults, 0, wxALL, 5 );
	
	bSizer1->Add( buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_colourPickerOutputPanesFgColour->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( SyntaxHighlightBaseDlg::OnOutputViewColourChanged ), NULL, this );
	m_colourPickerOutputPanesBgColour->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( SyntaxHighlightBaseDlg::OnOutputViewColourChanged ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnButtonOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnButtonCancel ), NULL, this );
	m_buttonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnButtonApply ), NULL, this );
	m_buttonDefaults->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnRestoreDefaults ), NULL, this );
}

SyntaxHighlightBaseDlg::~SyntaxHighlightBaseDlg()
{
	// Disconnect Events
	m_colourPickerOutputPanesFgColour->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( SyntaxHighlightBaseDlg::OnOutputViewColourChanged ), NULL, this );
	m_colourPickerOutputPanesBgColour->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( SyntaxHighlightBaseDlg::OnOutputViewColourChanged ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnButtonOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnButtonCancel ), NULL, this );
	m_buttonApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnButtonApply ), NULL, this );
	m_buttonDefaults->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SyntaxHighlightBaseDlg::OnRestoreDefaults ), NULL, this );
	
}

LexerPageBase::LexerPageBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebook1 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0|wxNO_BORDER );
	m_panel2 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( m_panel2, wxID_ANY, _("Global Font:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer2->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_globalFontPicker = new wxFontPickerCtrl( m_panel2, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_USEFONT_FOR_LABEL );
	m_globalFontPicker->SetMaxPointSize( 100 ); 
	m_globalFontPicker->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 76, 90, 90, false, wxEmptyString ) );
	m_globalFontPicker->SetToolTip( _("Use this to select a font to be used by *all* styles of this lexer") );
	
	fgSizer2->Add( m_globalFontPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText7 = new wxStaticText( m_panel2, wxID_ANY, _("Global background Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer2->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_globalBgColourPicker = new wxColourPickerCtrl( m_panel2, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL|wxCLRP_USE_TEXTCTRL );
	m_globalBgColourPicker->SetToolTip( _("Use this to select a background colour to be used by *all* styles of this lexer") );
	
	fgSizer2->Add( m_globalBgColourPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText8 = new wxStaticText( m_panel2, wxID_ANY, _("File Extensions:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer2->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_fileSpec = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_fileSpec->SetToolTip( _("Associate this lexer with files which have these extensions") );
	
	fgSizer2->Add( m_fileSpec, 0, wxALL|wxEXPAND, 5 );
	
	bSizer6->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer6 );
	m_panel2->Layout();
	bSizer6->Fit( m_panel2 );
	m_auinotebook1->AddPage( m_panel2, _("Global Settings"), true, wxNullBitmap );
	m_panel1 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_properties = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer8->Add( m_properties, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Style Font:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_fontPicker = new wxFontPickerCtrl( m_panel1, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_USEFONT_FOR_LABEL );
	m_fontPicker->SetMaxPointSize( 100 ); 
	m_fontPicker->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 76, 90, 90, false, wxEmptyString ) );
	m_fontPicker->SetToolTip( _("Select a font to be used with the selected style") );
	
	fgSizer1->Add( m_fontPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, _("Foreground Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer1->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_colourPicker = new wxColourPickerCtrl( m_panel1, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL|wxCLRP_USE_TEXTCTRL );
	m_colourPicker->SetToolTip( _("Select the foreground colour for the selected style") );
	
	fgSizer1->Add( m_colourPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _("Background Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_bgColourPicker = new wxColourPickerCtrl( m_panel1, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL|wxCLRP_USE_TEXTCTRL );
	m_bgColourPicker->SetToolTip( _("Select the background colour for the selected style") );
	
	fgSizer1->Add( m_bgColourPicker, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_eolFilled = new wxCheckBox( m_panel1, wxID_ANY, _("Style is EOL Filled"), wxDefaultPosition, wxDefaultSize, 0 );
	m_eolFilled->SetToolTip( _("If a line ends with a character/word which has this style, the remaining of the line will be coloured with this style background colour") );
	
	fgSizer1->Add( m_eolFilled, 0, wxALL, 5 );
	
	
	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_styleWithinPreProcessor = new wxCheckBox( m_panel1, wxID_ANY, _("Styling Within Pre-processor Line"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_styleWithinPreProcessor, 0, wxALL, 5 );
	
	bSizer9->Add( fgSizer1, 1, wxEXPAND|wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, _("Edit Lexer Keyword Sets:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer9->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button5 = new wxButton( m_panel1, wxID_ANY, _("Set &0"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer5->Add( m_button5, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button6 = new wxButton( m_panel1, wxID_ANY, _("Set &1"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer5->Add( m_button6, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button7 = new wxButton( m_panel1, wxID_ANY, _("Set &2"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer5->Add( m_button7, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button8 = new wxButton( m_panel1, wxID_ANY, _("Set &3"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer5->Add( m_button8, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button9 = new wxButton( m_panel1, wxID_ANY, _("Set &4"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer5->Add( m_button9, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer9->Add( bSizer5, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	bSizer51->Add( bSizer8, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer51 );
	m_panel1->Layout();
	bSizer51->Fit( m_panel1 );
	m_auinotebook1->AddPage( m_panel1, _("Customize"), false, wxNullBitmap );
	m_panel3 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText9 = new wxStaticText( m_panel3, wxID_ANY, _("Selected Text Background Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer3->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_colourPickerSelTextBgColour = new wxColourPickerCtrl( m_panel3, wxID_ANY, wxColour( 192, 192, 192 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL|wxCLRP_USE_TEXTCTRL );
	fgSizer3->Add( m_colourPickerSelTextBgColour, 0, wxALL|wxEXPAND, 5 );
	
	bSizer7->Add( fgSizer3, 0, wxEXPAND|wxALL, 5 );
	
	m_buttonTextSelApplyToAll = new wxButton( m_panel3, ID_buttonTextSelApplyToAll, _("Apply these choices to all lexors"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonTextSelApplyToAll->SetToolTip( _("To save having to go through every lexor to set your text selection preferences, click here to apply these settings to all the lexors in this theme") );
	
	bSizer7->Add( m_buttonTextSelApplyToAll, 0, wxALL|wxEXPAND, 5 );
	
	m_panel3->SetSizer( bSizer7 );
	m_panel3->Layout();
	bSizer7->Fit( m_panel3 );
	m_auinotebook1->AddPage( m_panel3, _("Text Selection"), false, wxNullBitmap );
	
	bSizer3->Add( m_auinotebook1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	// Connect Events
	m_globalFontPicker->Connect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( LexerPageBase::OnFontChanged ), NULL, this );
	m_globalBgColourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnColourChanged ), NULL, this );
	m_fileSpec->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LexerPageBase::OnText ), NULL, this );
	m_properties->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( LexerPageBase::OnItemSelected ), NULL, this );
	m_fontPicker->Connect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( LexerPageBase::OnFontChanged ), NULL, this );
	m_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnColourChanged ), NULL, this );
	m_bgColourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnColourChanged ), NULL, this );
	m_eolFilled->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LexerPageBase::OnEolFilled ), NULL, this );
	m_styleWithinPreProcessor->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LexerPageBase::OnStyleWithinPreprocessor ), NULL, this );
	m_styleWithinPreProcessor->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( LexerPageBase::OnStyleWithingPreProcessorUI ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton0 ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton1 ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton2 ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton3 ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton4 ), NULL, this );
	m_colourPickerSelTextBgColour->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnSelTextChanged ), NULL, this );
	m_buttonTextSelApplyToAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnTextSelApplyToAll ), NULL, this );
}

LexerPageBase::~LexerPageBase()
{
	// Disconnect Events
	m_globalFontPicker->Disconnect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( LexerPageBase::OnFontChanged ), NULL, this );
	m_globalBgColourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnColourChanged ), NULL, this );
	m_fileSpec->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LexerPageBase::OnText ), NULL, this );
	m_properties->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( LexerPageBase::OnItemSelected ), NULL, this );
	m_fontPicker->Disconnect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( LexerPageBase::OnFontChanged ), NULL, this );
	m_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnColourChanged ), NULL, this );
	m_bgColourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnColourChanged ), NULL, this );
	m_eolFilled->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LexerPageBase::OnEolFilled ), NULL, this );
	m_styleWithinPreProcessor->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LexerPageBase::OnStyleWithinPreprocessor ), NULL, this );
	m_styleWithinPreProcessor->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( LexerPageBase::OnStyleWithingPreProcessorUI ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton0 ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton1 ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton2 ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton3 ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnEditKeyWordsButton4 ), NULL, this );
	m_colourPickerSelTextBgColour->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( LexerPageBase::OnSelTextChanged ), NULL, this );
	m_buttonTextSelApplyToAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LexerPageBase::OnTextSelApplyToAll ), NULL, this );
	
}
