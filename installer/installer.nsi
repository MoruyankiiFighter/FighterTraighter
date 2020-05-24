Var "FTName"

# InstallDir $PROGRAMFILES\$FTName is replaced by this?
Function .onInit

StrCpy $FTName "Fighter Traighter"
StrCpy $INSTDIR "$PROGRAMFILES64\$FTName"

FunctionEnd

OutFile "Fighter Traighter setup.exe"

RequestExecutionLevel admin

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