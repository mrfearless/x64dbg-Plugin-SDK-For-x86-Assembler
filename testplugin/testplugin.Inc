;=====================================================================================
; x64_dbg plugin SDK for Masm - fearless 2015
;
; testplugin include file - Supports 32bit x32_dbg only.
;
;-------------------------------------------------------------------------------------
include windows.inc
include user32.inc
include kernel32.inc
includelib user32.lib
includelib kernel32.lib


; Your prototypes for initializing, stopping and setting up your plugin.
testPluginDlgProc           PROTO :DWORD, :DWORD, :DWORD, :DWORD
testSetup                   PROTO ; helps setup plugin
testStop                    PROTO ; cleanup routine for plugin
testDisasm                  PROTO ; custom function called from menu item added to debugger

JustFname                   PROTO :DWORD, :DWORD ; custom internal function
JustExt                     PROTO :DWORD, :DWORD ; custom internal function

cbDumpProcessCommand        PROTO :DWORD, :DWORD ; Exported function for a custom registered command 


.CONST
; Constants for any plugin menus
MENU_TEST1                  EQU 1
MENU_OPENDIALOG             EQU 2
MENU_TEST3                  EQU 3
MENU_DISASM                 EQU 4
MENU_DUMP                   EQU 5
MENU_STACK                  EQU 6
MENU_DUMPPROCESS            EQU 7
IDD_PluginDlg               EQU 1000


.DATA
; Data and strings for your menus and commands
szMenuTest1                 DB "Plugin Menu Item.",0
szMenuOpenDialog            DB "Open Test Dialog.",0
szMenuTest3                 DB "Another Menu Item.",0
szMenuDisasm                DB "Disasm Test Menu Item.",0
szMenuDump                  DB "Dump Test Menu Item.",0
szMenuStack                 DB "Stack Test Menu Item.",0
szMenuDumpProcess           DB "&DumpProcess...",0

; Error strings
szErrorDbgGetModuleAt       DB "DumpProcess Error: could not get module.",0
szErrorDbgModBaseFromName   DB "DumpProcess Error: could not get module base.",0
szErrorGetModuleBaseNameA   DB "DumpProcess Error: could not get module base name.",0
szErrorGetSaveFileName      DB "DumpProcess Error: could not dump file.",0
szErrorDumpProcess          DB "DumpProcess Error: Failed to dump file.",0
szSuccessDumpProcess        DB "DumpProcess: Success dumping file.",0

; Info strings
szStatusMsg                 DB "x32_dbg masm32 plugin",0
szStackMsg                  DB "The stack is looking sweet!",0
szDisamMsg                  DB "Not much happening at the moment.",0
szDumpMsg                   DB "Fetching label and printing it on status bar.",0
szPluginLoaded              DB "x32_dbg masm32 plugin loaded.",13,10,0
szPluginUnloaded            DB "x32_dbg masm32 plugin unloaded.",13,10,0
szDebuggingRequired         DB "x32_dbg masm32 plugin: you need to be debugging to use this option",13,10,0
szDebuggingIsAvailable      DB "x32_dbg masm32 plugin: Debugging in operation, you are good to go!",13,10,0

; DumpProcess strings
szDumpProcess               DB "DumpProcess",0
szDump                      DB "_dump.",0
szFilterString              DB "Executables (*.exe, *.dll)",0,"*.exe;*.dll",0,"All Files (*.*)",0,"*.*",0,0
szDialogTitle               DB "Select dump file...",0


lpszLabel                   DB MAX_LABEL_SIZE DUP (0)

.DATA?
hInstance                   DD ?

