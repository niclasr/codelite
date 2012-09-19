///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EDITOROPTIONSGENERALGUIDESPANELBASE_H__
#define __EDITOROPTIONSGENERALGUIDESPANELBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class EditorOptionsGeneralGuidesPanelBase
///////////////////////////////////////////////////////////////////////////////
class EditorOptionsGeneralGuidesPanelBase : public wxPanel 
{
	private:
	
	protected:
		wxCheckBox* m_displayLineNumbers;
		wxCheckBox* m_showIndentationGuideLines;
		wxCheckBox* m_checkBoxMatchBraces;
		wxCheckBox* m_checkBoxAutoCompleteCurlyBraces;
		wxCheckBox* m_checkBoxDisableSemicolonShift;
		wxCheckBox* m_checkBoxAutoCompleteNormalBraces;
		wxCheckBox* m_checkBoxHideChangeMarkerMargin;
		wxCheckBox* m_checkBoxDoubleQuotes;
		wxStaticText* m_staticText2;
		wxChoice* m_whitespaceStyle;
		wxStaticText* m_staticText4;
		wxChoice* m_choiceEOL;
		wxCheckBox* m_highlightCaretLine;
		wxStaticText* m_staticText1;
		wxColourPickerCtrl* m_caretLineColourPicker;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnHighlightCaretLine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnhighlightCaretLineUI( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		EditorOptionsGeneralGuidesPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~EditorOptionsGeneralGuidesPanelBase();
	
};

#endif //__EDITOROPTIONSGENERALGUIDESPANELBASE_H__
