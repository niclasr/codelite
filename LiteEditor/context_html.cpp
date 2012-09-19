#include "context_html.h"
#include "cl_editor.h"
#include "editor_config.h"
#include "cl_editor_tip_window.h"

ContextHtml::ContextHtml(LEditor *editor)
    : ContextBase(editor)
{
    editor->SetWordChars(wxT("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_$"));
}

ContextHtml::ContextHtml()
    : ContextBase(wxT("Html"))
{
}

ContextHtml::~ContextHtml()
{
}

void ContextHtml::AddMenuDynamicContent(wxMenu* menu)
{
    wxUnusedVar(menu);
}

void ContextHtml::ApplySettings()
{
    SetName(wxT("Html"));
    LexerConfPtr lexPtr;
    if (EditorConfigST::Get()->IsOk()) {
        lexPtr = EditorConfigST::Get()->GetLexer(GetName());
    }
    LEditor &rCtrl = GetCtrl();
    if (lexPtr) {
        rCtrl.SetLexer(lexPtr->GetLexerId());
        for (int i = 0; i <= 4; ++i) {
            wxString keyWords = lexPtr->GetKeyWords(i);
            keyWords.Replace(wxT("\n"), wxT(" "));
            keyWords.Replace(wxT("\r"), wxT(" "));
            rCtrl.SetKeyWords(i, keyWords);
        }
    } else {
        rCtrl.SetLexer(wxSTC_LEX_NULL);
    }
    DoApplySettings(lexPtr);

}

void ContextHtml::AutoIndent(const wxChar& nChar)
{
    LEditor &rCtrl = GetCtrl();

    if (rCtrl.GetDisableSmartIndent()) {
        return;
    }
    if(rCtrl.GetLineIndentation(rCtrl.GetCurrentLine()) && nChar == wxT('\n')) {
        return;
    }

    int curpos = rCtrl.GetCurrentPos();
//	if (IsCommentOrString(curpos) && nChar == wxT('\n')) {
//		AutoAddComment();
//		return;
//	}

    if (IsCommentOrString(curpos)) {
        ContextBase::AutoIndent(nChar);
        return;
    }
    int line = rCtrl.LineFromPosition(curpos);
    if (nChar == wxT('\n')) {

        int      prevpos (wxNOT_FOUND);
        int      foundPos(wxNOT_FOUND);

        wxString word;
        wxChar ch = rCtrl.PreviousChar(curpos, prevpos );
        word      = rCtrl.PreviousWord(curpos, foundPos);

        // user hit ENTER after 'else'
        if ( word == wxT("else") ) {
            int prevLine = rCtrl.LineFromPosition(prevpos);
            rCtrl.SetLineIndentation(line, rCtrl.GetIndent() + rCtrl.GetLineIndentation(prevLine));
            rCtrl.SetCaretAt(rCtrl.GetLineIndentPosition(line));
            rCtrl.ChooseCaretX(); // set new column as "current" column
            return;
        }

        // User typed 'ENTER' immediatly after closing brace ')'
        if ( prevpos != wxNOT_FOUND && ch == wxT(')') ) {

            long openBracePos          (wxNOT_FOUND);
            int  posWordBeforeOpenBrace(wxNOT_FOUND);

            if (rCtrl.MatchBraceBack(wxT(')'), prevpos, openBracePos)) {
                rCtrl.PreviousChar(openBracePos, posWordBeforeOpenBrace);
                if (posWordBeforeOpenBrace != wxNOT_FOUND) {
                    word = rCtrl.PreviousWord(posWordBeforeOpenBrace, foundPos);

                    // c++ expression with single line and should be treated separatly
                    if ( word == wxT("if") || word == wxT("while") || word == wxT("for")) {
                        int prevLine = rCtrl.LineFromPosition(prevpos);
                        rCtrl.SetLineIndentation(line, rCtrl.GetIndent() + rCtrl.GetLineIndentation(prevLine));
                        rCtrl.SetCaretAt(rCtrl.GetLineIndentPosition(line));
                        rCtrl.ChooseCaretX(); // set new column as "current" column
                        return;
                    }
                }
            }
        }

        // User typed 'ENTER' immediatly after colons ':'
        if ( prevpos != wxNOT_FOUND && ch == wxT(':') ) {
            int  posWordBeforeColons(wxNOT_FOUND);

            rCtrl.PreviousChar(prevpos, posWordBeforeColons);
            if (posWordBeforeColons != wxNOT_FOUND) {
                word = rCtrl.PreviousWord(posWordBeforeColons, foundPos);
                int prevLine = rCtrl.LineFromPosition(posWordBeforeColons);

                // If we found one of the following keywords, un-indent their line by (foldLevel - 1)*indentSize
                if ( word == wxT("public") || word == wxT("private") || word == wxT("protected")) {

                    ContextBase::AutoIndent(nChar);

                    // Indent this line according to the block indentation level
                    int foldLevel = (rCtrl.GetFoldLevel(prevLine) & wxSTC_FOLDLEVELNUMBERMASK) - wxSTC_FOLDLEVELBASE;
                    if (foldLevel) {
                        rCtrl.SetLineIndentation(prevLine, ((foldLevel-1)*rCtrl.GetIndent()) );
                        rCtrl.ChooseCaretX();
                    }
                    return;
                }
            }
        }

        // use the previous line indentation level
        if (prevpos == wxNOT_FOUND || ch != wxT('{') || IsCommentOrString(prevpos)) {
            ContextBase::AutoIndent(nChar);
            return;
        }

        // Open brace? increase indent size
        int prevLine = rCtrl.LineFromPosition(prevpos);
        rCtrl.SetLineIndentation(line, rCtrl.GetIndent() + rCtrl.GetLineIndentation(prevLine));
        rCtrl.SetCaretAt(rCtrl.GetLineIndentPosition(line));

    } else if (nChar == wxT('}')) {

        long matchPos = wxNOT_FOUND;
        if (!rCtrl.MatchBraceBack(wxT('}'), rCtrl.PositionBefore(curpos), matchPos))
            return;
        int secondLine = rCtrl.LineFromPosition(matchPos);
        if (secondLine == line)
            return;
        rCtrl.SetLineIndentation(line, rCtrl.GetLineIndentation(secondLine));

    } else if (nChar == wxT('{')) {
        wxString lineString = rCtrl.GetLine(line);
        lineString.Trim().Trim(false);

        int matchPos = wxNOT_FOUND;
        wxChar previousChar = rCtrl.PreviousChar(rCtrl.PositionBefore(curpos), matchPos);
        if (previousChar != wxT('{') && lineString == wxT("{")) {
            // indent this line accroding to the previous line
            int line = rCtrl.LineFromPosition(rCtrl.GetCurrentPos());
            rCtrl.SetLineIndentation(line, rCtrl.GetLineIndentation(line-1));
            rCtrl.ChooseCaretX();
        }
    }

    // set new column as "current" column
    rCtrl.ChooseCaretX();
}

wxString ContextHtml::CallTipContent()
{
    return wxEmptyString;
}

void ContextHtml::CodeComplete(long pos)
{
}

void ContextHtml::CompleteWord()
{
}

int ContextHtml::DoGetCalltipParamterIndex()
{
    return ContextBase::DoGetCalltipParamterIndex();
}

wxString ContextHtml::GetCurrentScopeName()
{
    return wxT("");
}

wxMenu* ContextHtml::GetMenu()
{
    return ContextBase::GetMenu();
}

TagEntryPtr ContextHtml::GetTagAtCaret(bool scoped, bool impl)
{
    return NULL;
}

void ContextHtml::GoHyperlink(int start, int end, int type, bool alt)
{
}

void ContextHtml::GotoDefinition()
{
}

void ContextHtml::GotoPreviousDefintion()
{
}

bool ContextHtml::IsCommentOrString(long pos)
{
    return IsComment(pos);
}

bool ContextHtml::IsDefaultContext() const
{
    return false;
}

ContextBase* ContextHtml::NewInstance(LEditor* container)
{
    return new ContextHtml(container);
}

void ContextHtml::OnCallTipClick(wxStyledTextEvent& event)
{
}

void ContextHtml::OnCalltipCancel()
{
}

void ContextHtml::OnDbgDwellEnd(wxStyledTextEvent& event)
{
}

void ContextHtml::OnDbgDwellStart(wxStyledTextEvent& event)
{
}

void ContextHtml::OnDwellEnd(wxStyledTextEvent& event)
{
}

void ContextHtml::OnDwellStart(wxStyledTextEvent& event)
{
}

void ContextHtml::OnEnterHit()
{
}

void ContextHtml::OnFileSaved()
{
}

void ContextHtml::OnKeyDown(wxKeyEvent& event)
{
    event.Skip();
}

void ContextHtml::OnSciUpdateUI(wxStyledTextEvent& event)
{
    LEditor &ctrl = GetCtrl();
    if (ctrl.GetFunctionTip()->IsActive()) {
        ctrl.GetFunctionTip()->Highlight(DoGetCalltipParamterIndex());
    }
}

void ContextHtml::OnUserTypedXChars(const wxString& word)
{
}

void ContextHtml::RemoveMenuDynamicContent(wxMenu* menu)
{
}

void ContextHtml::RetagFile()
{
}

void ContextHtml::SemicolonShift()
{
    int foundPos    (wxNOT_FOUND);
    int semiColonPos(wxNOT_FOUND);
    LEditor &ctrl = GetCtrl();
    if (ctrl.NextChar(ctrl.GetCurrentPos(), semiColonPos) == wxT(')')) {

        // test to see if we are inside a 'for' statement
        long openBracePos          (wxNOT_FOUND);
        int  posWordBeforeOpenBrace(wxNOT_FOUND);

        if (ctrl.MatchBraceBack(wxT(')'), semiColonPos, openBracePos)) {
            ctrl.PreviousChar(openBracePos, posWordBeforeOpenBrace);
            if (posWordBeforeOpenBrace != wxNOT_FOUND) {
                wxString word = ctrl.PreviousWord(posWordBeforeOpenBrace, foundPos);

                // At the current pos, we got a ';'
                // at semiColonPos we got ;
                // switch
                ctrl.DeleteBack();
                ctrl.SetCurrentPos(semiColonPos);
                ctrl.InsertText(semiColonPos, wxT(";"));
                ctrl.SetCaretAt(semiColonPos+1);
                ctrl.GetFunctionTip()->Deactivate();
            }
        }
    }
}

void ContextHtml::SetActive()
{
}

bool ContextHtml::IsComment(long pos)
{
    int style = GetCtrl().GetStyleAt(pos);
    return  style == wxSTC_H_COMMENT       ||
            style == wxSTC_H_XCCOMMENT     ||
            style == wxSTC_H_SGML_COMMENT  ||
            style == wxSTC_HJ_COMMENT      ||
            style == wxSTC_HJ_COMMENTLINE  ||
            style == wxSTC_HJ_COMMENTDOC   ||
            style == wxSTC_HJA_COMMENT     ||
            style == wxSTC_HJA_COMMENTLINE ||
            style == wxSTC_HJA_COMMENTDOC  ||
            style == wxSTC_HB_COMMENTLINE  ||
            style == wxSTC_HBA_COMMENTLINE ||
            style == wxSTC_HP_COMMENTLINE  ||
            style == wxSTC_HPA_COMMENTLINE ||
            style == wxSTC_HPHP_COMMENT    ||
            style == wxSTC_HPHP_COMMENTLINE;
}
