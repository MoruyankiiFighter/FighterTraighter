!include "MUI2.nsh"


Name "Fighter Traighter"
OutFile "Fighter Traighter setup.exe"
Unicode True
InstallDir "$PROGRAMFILES64\Fighter Traighter"
RequestExecutionLevel admin

!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "..\assets\Assets\images\installer\header_bitmap.bmp" ; NOTE: images have to be 8 bits in depth
!define MUI_HEADERIMAGE_UNBITMAP "..\assets\Assets\images\installer\header_bitmap.bmp" ; NOTE: images have to be 8 bits in depth

!define MUI_WELCOMEFINISHPAGE_BITMAP "..\assets\Assets\images\installer\welcomepage_bitmap.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "..\assets\Assets\images\installer\welcomepage_bitmap.bmp"

!insertmacro MUI_PAGE_WELCOME
; !insertmacro MUI_PAGE_LICENSE "${NSISDIR}\Docs\Modern UI\License.txt" ; PLACE A LICENSE
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

Var "FTName"

Section

	StrCpy $FTName "Fighter Traighter"
	
    # set the installation directory as the destination for the following actions
    SetOutPath $INSTDIR
	 
	# specify file to go in output path
	File test.txt
 
    # create the uninstaller
    WriteUninstaller "$INSTDIR\uninstall $FTName.exe"
	
    CreateShortcut "$SMPROGRAMS\Fighter Traighter.lnk" "$INSTDIR\test.txt" #change to the exe of the game

SectionEnd

# uninstaller section start
Section "Uninstall"
 
 	StrCpy $FTName "Fighter Traighter"
	
    # first, delete the uninstaller
    Delete "$INSTDIR\uninstall $FTName.exe"
 
    # second, remove the link from the start menu
    Delete "$SMPROGRAMS\$FTName.lnk"
	
	# now delete installed file
	Delete $INSTDIR\test.txt
 
	# Delete the directory
    RMDir $INSTDIR
# uninstaller section end
SectionEnd