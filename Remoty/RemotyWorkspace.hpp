#ifndef REMOTEWORKSPACE_HPP
#define REMOTEWORKSPACE_HPP

#include "IWorkspace.h" // Base class: IWorkspace
#include "clFileSystemEvent.h"
#include "clFileSystemWorkspaceConfig.hpp"
#include "clRemoteTerminal.hpp"
#include "cl_command_event.h"
#include "ssh_account_info.h"
#include <deque>
#include <functional>

#define WORKSPACE_TYPE_NAME "Remote over SSH"

class RemotyWorkspaceView;
class RemotyWorkspace : public IWorkspace
{
    bool m_eventsConnected = false;
    RemotyWorkspaceView* m_view = nullptr;
    SSHAccountInfo m_account;
    wxString m_remoteWorkspaceFile;
    wxString m_localWorkspaceFile;
    wxString m_localUserWorkspaceFile;
    clFileSystemWorkspaceSettings m_settings;
    IProcess* m_buildProcess = nullptr;
    IProcess* m_cmdProcess = nullptr;
    IProcess* m_scanFilesProcess = nullptr;
    long m_execPID = wxNOT_FOUND;
    clRemoteTerminal::ptr_t m_remote_terminal;

public:
    RemotyWorkspace();
    RemotyWorkspace(bool dummy);
    virtual ~RemotyWorkspace();

protected:
    void ConfigureClangd();
    void BindEvents();
    void UnbindEvents();
    void Initialise();
    void OnOpenWorkspace(clCommandEvent& event);
    void OnCloseWorkspace(clCommandEvent& event);

    void DoClose(bool notify);
    /// open a workspace file. the expected file format is: ssh://user@host:[port:]/path/to/file
    void DoOpen(const wxString& workspaceFileURI);
    void DoBuild(const wxString& kind);
    IProcess* DoRunSSHProcess(const wxString& scriptContent, bool sync = false);
    wxString GetTargetCommand(const wxString& target) const;
    void DoPrintBuildMessage(const wxString& message);
    void GetExecutable(wxString& exe, wxString& args, wxString& wd);

    void OnBuildStarting(clBuildEvent& event);
    void OnBuildProcessTerminated(clProcessEvent& event);
    void OnBuildProcessOutput(clProcessEvent& event);
    void OnIsBuildInProgress(clBuildEvent& event);
    void OnStopBuild(clBuildEvent& event);
    void OnBuildHotspotClicked(clBuildEvent& event);
    void OnCustomTargetMenu(clContextMenuEvent& event);
    void OnNewWorkspace(clCommandEvent& event);
    void OnDebugStarting(clDebugEvent& event);
    void OnDebugEnded(clDebugEvent& event);
    void OnRun(clExecuteEvent& event);
    void OnStop(clExecuteEvent& event);
    void OnIsProgramRunning(clExecuteEvent& event);
    void OnExecProcessTerminated(clProcessEvent& event);
    void OnFindSwapped(clFileSystemEvent& event);
    wxString GetRemoteWorkingDir() const;
    wxString CreateEnvScriptContent() const;
    wxString UploadScript(const wxString& content, const wxString& script_path = wxEmptyString) const;
    void DoScanFiles();

public:
    // IWorkspace
    virtual wxString GetActiveProjectName() const
    {
        return wxEmptyString;
    }
    virtual wxFileName GetFileName() const;
    virtual wxString GetFilesMask() const;
    virtual wxFileName GetProjectFileName(const wxString& projectName) const;
    virtual void GetProjectFiles(const wxString& projectName, wxArrayString& files) const;
    virtual wxString GetProjectFromFile(const wxFileName& filename) const;
    virtual void GetWorkspaceFiles(wxArrayString& files) const;
    virtual wxArrayString GetWorkspaceProjects() const;
    virtual bool IsBuildSupported() const;
    virtual bool IsProjectSupported() const;

    // API
    bool IsOpened() const;
    const SSHAccountInfo& GetAccount() const
    {
        return m_account;
    }
    const wxString& GetLocalWorkspaceFile() const
    {
        return m_localWorkspaceFile;
    }
    const wxString& GetRemoteWorkspaceFile() const
    {
        return m_remoteWorkspaceFile;
    }
    const clFileSystemWorkspaceSettings& GetSettings() const
    {
        return m_settings;
    }
    clFileSystemWorkspaceSettings& GetSettings()
    {
        return m_settings;
    }
    /**
     * @brief save the settings to the remote machine
     */
    void SaveSettings();
};

#endif // RemoteWorkspace_HPP
