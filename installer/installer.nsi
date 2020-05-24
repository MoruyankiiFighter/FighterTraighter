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
	
    # set the directory and files to go to the output directory
	
    SetOutPath $INSTDIR

	File "..\src\MF-FighterTraighter\x64\Release\MF-FighterTraighter.exe"
	File "..\src\MF-FighterTraighter\x64\Release\MF-FighterTraighter.iobj"
	File "..\src\MF-FighterTraighter\x64\Release\MF-FighterTraighter.ipdb"
	File "..\src\MF-FighterTraighter\x64\Release\MF-FighterTraighter.pdb"
	File "..\src\MF-FighterTraighter\x64\Release\libFLAC-8.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libfreetype-6.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libjpeg-9.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libmodplug-1.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libmpg123-0.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libogg-0.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libopus-0.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libopusfile-0.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libpng16-16.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libtiff-5.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libvorbis-0.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libvorbisfile-3.dll"
	File "..\src\MF-FighterTraighter\x64\Release\libwebp-7.dll"
	File "..\src\MF-FighterTraighter\x64\Release\SDL2.dll"
	File "..\src\MF-FighterTraighter\x64\Release\SDL2_image.dll"
	File "..\src\MF-FighterTraighter\x64\Release\SDL2_mixer.dll"
	File "..\src\MF-FighterTraighter\x64\Release\SDL2_ttf.dll"
	File "..\src\MF-FighterTraighter\x64\Release\zlib1.dll"
	
	SetOutPath $INSTDIR\assets\Assets
	
	File "..\assets\Assets\personaje.png"
	
	#end of files
 
 
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
	
	
	# now delete installed files
	
	Delete $INSTDIR\MF-FighterTraighter.exe
	Delete $INSTDIR\MF-FighterTraighter.iobj
	Delete $INSTDIR\MF-FighterTraighter.ipdb
	Delete $INSTDIR\MF-FighterTraighter.pdb
	Delete $INSTDIR\libFLAC-8.dll
	Delete $INSTDIR\libfreetype-6.dll
	Delete $INSTDIR\libjpeg-9.dll
	Delete $INSTDIR\libmodplug-1.dll
	Delete $INSTDIR\libmpg123-0.dll
	Delete $INSTDIR\libogg-0.dll
	Delete $INSTDIR\libopus-0.dll
	Delete $INSTDIR\libopusfile-0.dll
	Delete $INSTDIR\libpng16-16.dll
	Delete $INSTDIR\libtiff-5.dll
	Delete $INSTDIR\libvorbis-0.dll
	Delete $INSTDIR\libvorbisfile-3.dll
	Delete $INSTDIR\libwebp-7.dll
	Delete $INSTDIR\SDL2.dll
	Delete $INSTDIR\SDL2_image.dll
	Delete $INSTDIR\SDL2_mixer.dll
	Delete $INSTDIR\SDL2_ttf.dll
	Delete $INSTDIR\zlib1.dll
	
	Delete $INSTDIR\assets\Assets\personaje.png
	
	#end of files
 
 
	# Delete the directory
    RMDir $INSTDIR
# uninstaller section end
SectionEnd