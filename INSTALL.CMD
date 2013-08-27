/* REXX - Install Kill Folder Object */
 
Call RxFuncAdd 'SysLoadFuncs','REXXUTIL','SysLoadFuncs';
Call SysLoadFuncs; 

PathToDir=Directory()

Say PathToDir

ObjectClass = "WPProgram"
ObjectTitle = "Close All Folders"
ObjectLocation = "<WP_DESKTOP>"
ObjectSetupStr= "HELPPANEL=4083;"||,
                "DEFAULTVIEW=RUNNING;"||,
                "NOPRINT=YES;"||,
                "ICONPOS=40 53;"||,
                "ICONRESOURCE=58,PMWP.DLL;"||,
                "EXENAME="||PathToDir||"\KILLFOLD.EXE;"||,
                "PROGTYPE=WINDOWABLEVIO;"||,
                "MINIMIZED=YES;"
DefaultAction = "UpdateIfExists"

rc=SysCreateObject(ObjectClass,,
                   ObjectTitle,,
                   ObjectLocation,,
                   ObjectSetupStr,,
                   DefaultAction)

If rc<>1 Then Say "Error: Object could not be created or updated";
