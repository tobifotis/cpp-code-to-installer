; --- Installer for C++ Compression Demo ---

!define APP_NAME "Compression Demo"
!define APP_VERSION "1.0"
!define APP_EXE "compression-demo.exe"

; Installer output file name
OutFile "CompressionDemo-Setup.exe"

; Default installation directory
InstallDir "$PROGRAMFILES\CompressionDemo"

; Request admin privileges (needed for Program Files)
RequestExecutionLevel admin

; Installer pages (the wizard screens the user sees)
Page directory
Page instfiles

; What gets installed
Section "Install"
    ; Set the output path to the install directory
    SetOutPath $INSTDIR

    ; Copy the executable
    File "build\${APP_EXE}"

    ; Create a Start Menu shortcut
    CreateDirectory "$SMPROGRAMS\${APP_NAME}"
    CreateShortcut "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk" "$INSTDIR\${APP_EXE}"

    ; Create an uninstaller
    WriteUninstaller "$INSTDIR\Uninstall.exe"
SectionEnd

; Uninstaller section
Section "Uninstall"
    ; Remove the executable
    Delete "$INSTDIR\${APP_EXE}"
    Delete "$INSTDIR\Uninstall.exe"

    ; Remove the Start Menu shortcut
    Delete "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk"
    RMDir "$SMPROGRAMS\${APP_NAME}"

    ; Remove the install directory
    RMDir "$INSTDIR"
SectionEnd