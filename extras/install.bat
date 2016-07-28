REM x64dbg Plugin SDK For x86 Assembler (MASM32)
REM Copies the *.lib files to \Masm32\Lib and *.inc files to \Masm32\Include folder
REM
@ECHO OFF
ECHO x64dbg Plugin SDK For x86 Assembler
ECHO.
ECHO Installing files...

Copy ..\pluginsdk\lib\*.lib \Masm32\lib\ /Y > NUL
Copy ..\pluginsdk\include\*.inc \Masm32\Include\ /Y > NUL
ECHO Finished.
PAUSE
EXIT