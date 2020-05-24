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
	
    SetOutPath $INSTDIR\DELETE\ME\IM\USELESS

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
	
	SetOutPath $INSTDIR\assets\Assets\Fonts
	
	File "..\assets\Assets\Fonts\Roboto-Black.ttf"

	SetOutPath $INSTDIR\assets\Assets\Sounds\Songs

	File "..\assets\Assets\Sounds\Songs\New Hope menu.ogg"
	File "..\assets\Assets\Sounds\Songs\Never Surrender.ogg"
	File "..\assets\Assets\Sounds\Songs\Boss Fight.ogg"
	
	SetOutPath $INSTDIR\assets\Assets\Sounds\Taunts\MKW00P
	
	File "..\assets\Assets\Sounds\Taunts\MKW00P\buzz.wav"
	File "..\assets\Assets\Sounds\Taunts\MKW00P\clonk.wav"
	File "..\assets\Assets\Sounds\Taunts\MKW00P\piribi.wav"
	File "..\assets\Assets\Sounds\Taunts\MKW00P\robotau.wav"

	SetOutPath $INSTDIR\assets\Assets\Sounds\Taunts\F10R
	
	File "..\assets\Assets\Sounds\Taunts\F10R\zombidolor.mp3"

	SetOutPath $INSTDIR\assets\Assets\Sounds\Taunts\Mockingbird
	
	File "..\assets\Assets\Sounds\Taunts\Mockingbird\ouch.wav"
	File "..\assets\Assets\Sounds\Taunts\Mockingbird\pain.wav"
	File "..\assets\Assets\Sounds\Taunts\Mockingbird\yeow.wav"
	
	
	#end of files
 
 
    # create the uninstaller
    WriteUninstaller "$INSTDIR\uninstall $FTName.exe"
	
    CreateShortcut "$SMPROGRAMS\Fighter Traighter.lnk" "$INSTDIR\MF-FighterTraighter.exe" #change to the exe of the game

SectionEnd

# uninstaller section start
Section "Uninstall"
 
 	StrCpy $FTName "Fighter Traighter"
	
    # first, delete the uninstaller
    Delete "$INSTDIR\uninstall $FTName.exe"
 
    # second, remove the link from the start menu
    Delete "$SMPROGRAMS\$FTName.lnk"
	
	
	# now delete installed files
	
	Delete $INSTDIR\DELETE\ME\IM\USELESS\MF-FighterTraighter.exe
	Delete $INSTDIR\DELETE\ME\IM\USELESS\MF-FighterTraighter.iobj
	Delete $INSTDIR\DELETE\ME\IM\USELESS\MF-FighterTraighter.ipdb
	Delete $INSTDIR\DELETE\ME\IM\USELESS\MF-FighterTraighter.pdb
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libFLAC-8.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libfreetype-6.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libjpeg-9.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libmodplug-1.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libmpg123-0.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libogg-0.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libopus-0.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libopusfile-0.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libpng16-16.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libtiff-5.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libvorbis-0.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libvorbisfile-3.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\libwebp-7.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\SDL2.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\SDL2_image.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\SDL2_mixer.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\SDL2_ttf.dll
	Delete $INSTDIR\DELETE\ME\IM\USELESS\zlib1.dll
	
	Delete $INSTDIR\assets\Assets\Fonts\Roboto-Black.ttf
	
	Delete "$INSTDIR\assets\Assets\Sounds\Songs\New Hope menu.ogg"
	Delete "$INSTDIR\assets\Assets\Sounds\Songs\Never Surrender.ogg"
	Delete "$INSTDIR\assets\Assets\Sounds\Songs\Boss Fight.ogg"
	
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\MKW00P\buzz.wav"
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\MKW00P\clonk.wav"
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\MKW00P\piribi.wav"
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\MKW00P\robotau.wav"
	
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\F10R\zombidolor.mp3"
	
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\Mockingbird\ouch.wav"
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\Mockingbird\pain.wav"
	Delete "$INSTDIR\assets\Assets\Sounds\Taunts\Mockingbird\yeow.wav"

	
	#end of files
 
 
	# Delete all directories
	
	RMDir $INSTDIR\DELETE\ME\IM\USELESS
	RMDir $INSTDIR\DELETE\ME\IM
	RMDir $INSTDIR\DELETE\ME
	RMDir $INSTDIR\DELETE
	RMDir $INSTDIR\assets\Assets\Fonts
	RMDir $INSTDIR\assets\Assets\Sounds\Songs
	RMDir $INSTDIR\assets\Assets\Sounds\Taunts\MKW00P
	RMDir $INSTDIR\assets\Assets\Sounds\Taunts\F10R
	RMDir $INSTDIR\assets\Assets\Sounds\Taunts\Mockingbird
	RMDir $INSTDIR\assets\Assets\Sounds\Taunts
	RMDir $INSTDIR\assets\Assets\Sounds
	RMDir $INSTDIR\assets\Assets
	RMDir $INSTDIR\assets
    RMDir $INSTDIR

	
# uninstaller section end
SectionEnd