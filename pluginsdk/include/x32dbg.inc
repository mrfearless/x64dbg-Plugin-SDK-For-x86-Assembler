;--------------------------------------------------------------------------------------------------------
; x64dbg Plugin SDK For x86 Assembler - https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x86-Assembler
;
; fearless 2016 - www.LetTheLight.in
;
; v1.0.0.8 - Last updated: 17/10/2016 
; 
; Feature synced with x64dbg commit: https://github.com/x64dbg/x64dbg/commit/98d04b2a7842b92ea2eb2b2ba51a6256eb779453
;
; This SDK Supports 32bit x64dbg only.
;
; x64dbg Plugin SDK For x86 Assembler can be downloaded from here:
; https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x86-Assembler
;
; x64dbg Plugin SDK For x64 Assembler can be downloaded from here:
; https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x64-Assembler
;
; Include file for x32dbg.dll exports, constants and structures.
;
; This is a consolidation and conversion of the original plugin sdk files: _plugins.h, _plugin_types.h 
; & _exports.h to a format that will work with MASM and other assemblers (possibly).
;
; Where are name of a structure, structure field or other definitions conflict with a masm reserved word
; I have appended a underscore at the end of the item in most cases to work around that issue.
; There are a few exceptions: addr becomes address, end becomes finish, just for clarity.
;
; The enum macro provided emulates the enum behaviour in the origal pluginsdk files, however if masm 
; complains about line too complex during compilation, i have had to change some of the enums to
; to lines of ITEMNAME EQU VALUE type statements instead, which approximate the same function anyhow.
;
;--------------------------------------------------------------------------------------------------------

; x32dbg.inc functions - newer vsce2013 prototypes
;
_dbg_addrinfoget            PROTO C :DWORD, :DWORD, :DWORD ; (duint addr, SEGMENTREG segment, ADDRINFO* addrinfo);
_dbg_addrinfoset            PROTO C :DWORD, :DWORD ; (duint addr, ADDRINFO* addrinfo);
_dbg_bpgettypeat            PROTO C :DWORD ; (duint addr);
_dbg_dbgcmddirectexec       PROTO C :DWORD ; (const char* cmd);
_dbg_dbgcmdexec             PROTO C :DWORD ; (const char* cmd);
_dbg_dbgexitsignal          PROTO C 
_dbg_dbginit                PROTO C 
_dbg_functionoverlaps       PROTO C :DWORD, :DWORD ; (uint start, uint end);
_dbg_getbplist              PROTO C :DWORD, :DWORD ; (BPXTYPE type, BPMAP* list);
_dbg_getbranchdestination   PROTO C :DWORD ; (uint addr);
_dbg_getregdump             PROTO C :DWORD ; (REGDUMP* regdump);
_dbg_isdebugging            PROTO C
_dbg_isjumpgoingtoexecute   PROTO C :DWORD ; (duint addr);
_dbg_memfindbaseaddr        PROTO C :DWORD, :DWORD ; (duint addr, duint* size);
_dbg_memisvalidreadptr      PROTO C :DWORD ; (duint addr);
_dbg_memmap                 PROTO C :DWORD ; (MEMMAP* memmap);
_dbg_memread                PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (duint addr, unsigned char* dest, duint size, duint* read);
_dbg_memwrite               PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (duint addr, const unsigned char* src, duint size, duint* written);
_dbg_sendmessage            PROTO C :DWORD, :DWORD, :DWORD ; (DBGMSG type, void* param1, void* param2);
_dbg_valfromstring          PROTO C ;(const char* string, duint* value);
_dbg_valtostring            PROTO C :DWORD, :DWORD ; (const char* string, duint value);

; x64dbg.inc main plugin sdk exports/functions:
;
pluginit	        		PROTO C :DWORD          ; Required prototype and export for x64dbg plugin SDK
plugstop            		PROTO C                 ; Required prototype and export for x64dbg plugin SDK
plugsetup           		PROTO C :DWORD          ; Required prototype and export for x64dbg plugin SDK

; x32dbg.inc plugin functions - vs2010/vsce2013 prototypes
;
_plugin_debugpause          PROTO C
_plugin_debugskipexceptions PROTO C :DWORD ; (bool skip);
;_plugin_logprintf           PROTO C :DWORD, :DWORD ; (const char* format, ...); ; todo
_plugin_logputs             PROTO C :DWORD ; (const char* text);
_plugin_menuadd             PROTO C :DWORD, :DWORD ; (int hMenu, const char* title);
_plugin_menuaddentry        PROTO C :DWORD, :DWORD, :DWORD ; (int hMenu, int hEntry, const char* title);
_plugin_menuaddseparator    PROTO C :DWORD ; (int hMenu);
_plugin_menuclear           PROTO C :DWORD ; (int hMenu);
_plugin_menuseticon         PROTO C :DWORD, :DWORD ; (int hMenu, const ICONDATA* icon);
_plugin_menuentryseticon    PROTO C :DWORD, :DWORD, :DWORD ; (int pluginHandle, int hEntry, const ICONDATA* icon);
_plugin_menuentrysetchecked	PROTO C :DWORD, :DWORD, :DWORD ; (int pluginHandle, int hEntry, bool checked)
_plugin_registercommand     PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (int pluginHandle, const char* command, CBPLUGINCOMMAND cbCommand, bool debugonly);
_plugin_registercallback    PROTO C :DWORD, :DWORD, :DWORD ; (int pluginHandle, CBTYPE cbType, CBPLUGIN cbPlugin);
_plugin_startscript         PROTO C :DWORD ; (CBPLUGINSCRIPT cbScript);
_plugin_unregistercallback  PROTO C :DWORD, :DWORD ; (int pluginHandle, CBTYPE cbType);
_plugin_unregistercommand   PROTO C :DWORD, :DWORD ; (int pluginHandle, const char* command);
_plugin_waituntilpaused     PROTO C
_plugin_registerexprfunction PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (int pluginHandle, const char* name, int argc, CBPLUGINEXPRFUNCTION cbFunction, void* userdata);
_plugin_unregisterexprfunction PROTO C :DWORD, :DWORD ; (int pluginHandle, const char* name);
_plugin_unload				PROTO C :DWORD ; (const char* pluginName);
_plugin_load				PROTO C :DWORD ; (const char* pluginName);


; Callback functions for plugins. Any that are used in your plugin need to be exported (added to list of functions in plugin.def)
; each callback function has two parameters: cbType and cbInfo. cbInfo is a pointer to a specific structure (depending on the function)
; 
; When creating your callback function use 'C' language identifier to be compatible with the x64dbg debugger - Example: CBMENUENTRY PROC C PUBLIC USES EBX cbType:DWORD, cbInfo:DWORD
;
CBINITDEBUG                 PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_INITDEBUG structure: szFileName
CBSTOPDEBUG                 PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_STOPDEBUG structure: reserved
CBCREATEPROCESS             PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_CREATEPROCESS structure: CreateProcessInfo, modInfo, DebugFileName, fdProcessInfo
CBEXITPROCESS               PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_EXITPROCESS structure: ExitProcess
CBCREATETHREAD              PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_CREATETHREAD structure: CreateThreadInfo, dwThreadId
CBEXITTHREAD                PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_EXITTHREAD structure: dwThreadId
CBSYSTEMBREAKPOINT          PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_SYSTEMBREAKPOINT structure: reserved
CBLOADDLL                   PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_LOADDLL structure: LoadDll, modInfo, modname
CBUNLOADDLL                 PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_UNLOADDLL structure: UnloadDll
CBOUTPUTDEBUGSTRING         PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_OUTPUTDEBUGSTRING structure: DebugStringInfo
CBEXCEPTION                 PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_EXCEPTION structure: Exception
CBBREAKPOINT                PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_BREAKPOINT structure: reserved
CBPAUSEDEBUG                PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_PAUSEDEBUG structure: reserved
CBRESUMEDEBUG               PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_RESUMEDEBUG structure: reserved
CBSTEPPED                   PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_STEPPED structure: reserved
CBATTACH                    PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_ATTACH structure: dwProcessId
CBDETACH                    PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_DETACH structure: fdProcessInfo
CBDEBUGEVENT                PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_DEBUGEVENT structure: DebugEvent (AVOID doing stuff that takes time here, this will slow the debugger down a lot!)
CBMENUENTRY                 PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_MENUENTRY structure: hEntry
CBWINEVENT                  PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_WINEVENT structure: message, result, retval (only set this to true, never to false)
CBWINEVENTGLOBAL            PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_WINEVENTGLOBAL structure: message, retval (only set this to true, never to false)
CBLOADDB					PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_LOADSAVEDB
CBSAVEDB					PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_LOADSAVEDB
CBFILTERSYMBOL				PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_FILTERSYMBOL
CBTRACEEXECUTE				PROTO C :DWORD, :DWORD ; cbType, cbInfo pointer to PLUG_CB_TRACEEXECUTE

; enum macro is used to enumerate constants - similar to how enum works in c. 
enum macro _param_:VARARG
    _segname_ textequ @CurSeg
    _val_=0
    % forc _chr_,_segname_
        _val_=_val_+'&_chr_'
    endm
    IFNB <_param_>
        _count_=0
        _temp_ textequ <0>
        _ldata_ textequ <_DATA>
        for _arg_,<_param_>
            _pos_ instr <_arg_>,<=>
            if _pos_ ne 0
                _temp_ SubStr <_arg_>,_pos_+1
                if _val_ ne 179H ;;179H ='_' + 'D' + 'A' + 'T' + 'A'
                    @SubStr(<_arg_>,1,_pos_-1) equ _temp_
                else
                    @SubStr(<_arg_>,1,_pos_-1) dd _temp_
                endif
                _count_=1
            else
                if _val_ ne 179H ;;179H ='_' + 'D' + 'A' + 'T' + 'A'
                    _arg_ equ _temp_+_count_
                else
                    _arg_ dd _temp_+_count_
                endif
                _count_=_count_+1
            endif
        endm
    ENDIF
endm 

;-------------------------------------------------------------------------------

IFNDEF IMAGEHLP_MODULE64
IMAGEHLP_MODULE64       STRUCT 8
    SizeOfStruct        DWORD ?
    BaseOfImage         DWORD ?
    ImageSize           DWORD ?
    TimeDateStamp       DWORD ?
    CheckSum            DWORD ?
    NumSyms             DWORD ?
    SymType1            DWORD ?
    ModuleName          DB 256 DUP (?)
    ImageName           DB 256 DUP (?)
    LoadedImageName     DB 256 DUP (?)
    CVSig               DWORD ?
    CVData              DB 256 DUP (?)
    PdbSig              DWORD ?
    PdbSig70            GUID <>
    PdbAge              DWORD ?
    PdbUnmatched        DWORD ?
    DbgUnmatched        DWORD ?
    LineNumbers         DWORD ?
    GlobalSymbols       DWORD ?
    TypeInfo            DWORD ?
    SourceIndexed       DWORD ?
    Publics             DWORD ?
IMAGEHLP_MODULE64       ENDS
ENDIF


PLUG_SDKVERSION         EQU 1           ; x64_dbg pluging SDK version
PLUG_DB_LOADSAVE_DATA 	EQU 1
PLUG_DB_LOADSAVE_ALL 	EQU 2

; pluginit - This structure is used by the only needed export in the plugin interface
PLUG_INITSTRUCT         STRUCT
    pluginHandle        DWORD ?         ; Handle of the plugin, received from the pluginit call. Data provided by the debugger to the plugin.
    sdkVersion          DWORD ?         ; Plugin SDK version, use the PLUG_SDKVERSION define for this. Data provided by the plugin to the debugger (required).
    pluginVersion       DWORD ?         ; Plugin version, useful for crash reports. Data provided by the plugin to the debugger (required).
    pluginName          DWORD ?         ; Plugin name, also useful for crash reports. Data provided by the plugin to the debugger (required).
PLUG_INITSTRUCT         ENDS

; plugsetup - This structure is used by the function that allows the creation of plugin menu entries
PLUG_SETUPSTRUCT        STRUCT
    hwndDlg             DWORD ?         ; GUI window handle. Data provided by the debugger to the plugin.
    hMenu               DWORD ?         ; Plugin menu handle. Data provided by the debugger to the plugin.
    hMenuDisasm         DWORD ?         ; Plugin disasm menu handle. Data provided by the debugger to the plugin.
    hMenuDump           DWORD ?         ; Plugin dump menu handle. Data provided by the debugger to the plugin.
    hMenuStack          DWORD ?         ; Plugin stack menu handle. Data provided by the debugger to the plugin.
PLUG_SETUPSTRUCT        ENDS


; Callback structures

PLUG_SCRIPTSTRUCT		STRUCT
	data				DWORD ? ; user data
PLUG_SCRIPTSTRUCT		ENDS

; Called on debug initialization, useful to initialize some variables
PLUG_CB_INITDEBUG       STRUCT
    szFileName          DWORD ?
PLUG_CB_INITDEBUG       ENDS

PLUG_CB_STOPDEBUG       STRUCT
    reserved            DWORD ?
PLUG_CB_STOPDEBUG       ENDS

PLUG_CB_CREATEPROCESS   STRUCT
    CreateProcessInfo   DWORD ? ; pointer to CREATE_PROCESS_DEBUG_INFO <>
    modInfo             DWORD ? ; pointer to IMAGEHLP_MODULE64 <>
    DebugFileName       DWORD ?
    fdProcessInfo       DWORD ? ; pointer to PROCESS_INFORMATION <>
PLUG_CB_CREATEPROCESS   ENDS
    
PLUG_CB_EXITPROCESS     STRUCT
    ExitProcess         DWORD ? ; pointer to EXIT_PROCESS_DEBUG_INFO <> 
PLUG_CB_EXITPROCESS     ENDS

PLUG_CB_CREATETHREAD    STRUCT
    CreateThread        DWORD ? ; pointer to CREATE_THREAD_DEBUG_INFO <>
    dwThreadId          DWORD ?
PLUG_CB_CREATETHREAD    ENDS

PLUG_CB_EXITTHREAD      STRUCT
    ExitThread          DWORD ? ; pointer to EXIT_THREAD_DEBUG_INFO <> 
    dwThreadId          DWORD ?
PLUG_CB_EXITTHREAD      ENDS

PLUG_CB_SYSTEMBREAKPOINT STRUCT
    reserved            DWORD ?
PLUG_CB_SYSTEMBREAKPOINT ENDS

PLUG_CB_LOADDLL         STRUCT
    LoadDll             DWORD ? ; pointer to LOAD_DLL_DEBUG_INFO <>
    modInfo             DWORD ? ; pointer to IMAGEHLP_MODULE64 <> 
    modname             DWORD ?
PLUG_CB_LOADDLL         ENDS

PLUG_CB_UNLOADDLL       STRUCT
    UnloadDll           DWORD ? ; pointer to UNLOAD_DLL_DEBUG_INFO <>
PLUG_CB_UNLOADDLL       ENDS

PLUG_CB_OUTPUTDEBUGSTRING STRUCT
    DebugString         DWORD ? ; pointer to OUTPUT_DEBUG_STRING_INFO <>
PLUG_CB_OUTPUTDEBUGSTRING ENDS

PLUG_CB_EXCEPTION       STRUCT
    Exception           DWORD ? ; pointer to EXCEPTION_DEBUG_INFO <>
PLUG_CB_EXCEPTION       ENDS

PLUG_CB_BREAKPOINT      STRUCT
    breakpoint          DWORD ? ; pointer to BRIDGEBP <>
PLUG_CB_BREAKPOINT      ENDS

PLUG_CB_PAUSEDEBUG      STRUCT
    reserved            DWORD ?
PLUG_CB_PAUSEDEBUG      ENDS

PLUG_CB_RESUMEDEBUG     STRUCT
    reserved            DWORD ?
PLUG_CB_RESUMEDEBUG     ENDS

PLUG_CB_STEPPED         STRUCT
    reserved            DWORD ?
PLUG_CB_STEPPED         ENDS
       
PLUG_CB_ATTACH          STRUCT
    dwProcessId         DWORD ?
PLUG_CB_ATTACH          ENDS

PLUG_CB_DETACH          STRUCT
    fdProcessInfo       DWORD ? ; pointer to PROCESS_INFORMATION <>
PLUG_CB_DETACH          ENDS

PLUG_CB_DEBUGEVENT      STRUCT
    DebugEvent          DWORD ? ; pointer to DEBUG_EVENT <>
PLUG_CB_DEBUGEVENT      ENDS

PLUG_CB_MENUENTRY       STRUCT
    hEntry              DWORD ?
PLUG_CB_MENUENTRY       ENDS

PLUG_CB_WINEVENT        STRUCT
    message             DWORD ? pointer to MSG <>
    result              DWORD ?
    retval              DWORD ?
PLUG_CB_WINEVENT        ENDS

PLUG_CB_WINEVENTGLOBAL  STRUCT
    message             DWORD ? ; pointer to MSG <>;
    retval              DWORD ?
PLUG_CB_WINEVENTGLOBAL  ENDS

PLUG_CB_LOADSAVEDB		STRUCT
    root				DWORD ? ; point to JSON <>
    loadSaveType		DWORD ?
PLUG_CB_LOADSAVEDB		ENDS

PLUG_CB_FILTERSYMBOL	STRUCT
	symbol				DWORD ? ; pointer to const char* 
    retval				DWORD ? ; bool
PLUG_CB_FILTERSYMBOL	ENDS

PLUG_CB_TRACEEXECUTE	STRUCT 
	cip					DWORD ?
	stop				DWORD ? ; bool
PLUG_CB_TRACEEXECUTE	ENDS



enum CB_INITDEBUG,CB_STOPDEBUG,CB_CREATEPROCESS,CB_EXITPROCESS,CB_CREATETHREAD,CB_EXITTHREAD,CB_SYSTEMBREAKPOINT,CB_LOADDLL,CB_UNLOADDLL,CB_OUTPUTDEBUGSTRING,CB_EXCEPTION
enum CB_BREAKPOINT=11d,CB_PAUSEDEBUG,CB_RESUMEDEBUG,CB_STEPPED,CB_ATTACH,CB_DETACH,CB_DEBUGEVENT,CB_MENUENTRY,CB_WINEVENT,CB_WINEVENTGLOBAL
enum CB_LOADDB=21d,CB_SAVEDB,CB_FILTERSYMBOL,CB_TRACEEXECUTE,CB_LAST
