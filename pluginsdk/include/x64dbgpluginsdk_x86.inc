;=========================================================================================
;
; x64dbgpluginsdk_x86 Library v1.0.0.0
;
; 2016 by fearless
;
; http://www.LetTheLight.in
;
; x64dbg plugin SDK For Assembler x86 - fearless
; https://github.com/mrfearless/x64dbg-Plugin-SDK-for-x86-Assembler
;
;=========================================================================================

include comctl32.inc
includelib comctl32.lib

;-----------------------------------------------------------------------------------------
; x64dbgpluginsdk_x86 Prototypes
;-----------------------------------------------------------------------------------------

; Plugin functions
_plugin_loadmenuicon            PROTO :DWORD, :DWORD, :DWORD
_plugin_getmenutoolbarhandles   PROTO :DWORD, :DWORD
_plugin_getmainscreenhandle     PROTO :DWORD
_plugin_starttoolbargui         PROTO :DWORD, :DWORD
_plugin_stoptoolbargui          PROTO

; DbgFunctions Prototypes:
AssembleAtEx                    PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; duint addr, const char* instruction, char* error, bool fillnop
SectionFromAddr                 PROTO :DWORD, :DWORD                            ; duint addr, char* section
ModNameFromAddr                 PROTO :DWORD, :DWORD, :DWORD                    ; duint addr, char* modname, bool extension
ModBaseFromAddr                 PROTO :DWORD                                    ; duint addr;
ModBaseFromName                 PROTO :DWORD                                    ; const char* modname;
ModSizeFromAddr                 PROTO :DWORD                                    ; duint addr;
Assemble                        PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; duint addr, unsigned char* dest, int* size, const char* instruction, char* error
PatchGet                        PROTO :DWORD                                    ; duint addr
PatchInRange                    PROTO :DWORD, :DWORD                            ; duint start, duint end
MemPatch                        PROTO :DWORD, :DWORD, :DWORD                    ; duint va, const unsigned char* src, duint size
PatchRestoreRange               PROTO :DWORD, :DWORD                            ; duint start, duint end
PatchEnum                       PROTO :DWORD, :DWORD                            ; DBGPATCHINFO* patchlist, size_t* cbsize
PatchRestore                    PROTO :DWORD                                    ; duint addr
PatchFile                       PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; DBGPATCHINFO* patchlist, int count, const char* szFileName, char* error
ModPathFromAddr                 PROTO :DWORD, :DWORD, :DWORD                    ;
ModPathFromName                 PROTO :DWORD, :DWORD, :DWORD                    ; const char* modname, char* path, int size
DisasmFast                      PROTO :DWORD, :DWORD, :DWORD                    ; unsigned char* data, duint addr, BASIC_INSTRUCTION_INFO* basicinfo
GetPageRights                   PROTO :DWORD, :DWORD                            ; duint addr, char* rights
SetPageRights                   PROTO :DWORD, :DWORD                            ; duint addr, const char* rights
PageRightsToString              PROTO :DWORD, :DWORD                            ; DWORD protect, char* rights
IsProcessElevated               PROTO                                           ;
GetCmdline                      PROTO :DWORD, :DWORD                            ; char* cmdline, size_t* cbsize
SetCmdline                      PROTO :DWORD                                    ; const char* cmdline
FileOffsetToVa                  PROTO :DWORD, :DWORD                            ; const char* modname, duint offset
VaToFileOffset                  PROTO :DWORD                                    ; duint va
GetAddrFromLine                 PROTO :DWORD, :DWORD                            ; const char* szSourceFile, int line
GetSourceFromAddr               PROTO :DWORD, :DWORD, :DWORD                    ; (duint addr, char* szSourceFile, int* line
ValFromString                   PROTO :DWORD, :DWORD                            ; const char* string, duint* value
PatchGetEx                      PROTO :DWORD, :DWORD                            ; duint addr, DBGPATCHINFO* info
GetBridgeBP					    PROTO :DWORD, :DWORD, :DWORD                    ; BPXTYPE type, duint addr, BRIDGEBP* bp
StringFormatInline			    PROTO :DWORD, :DWORD, :DWORD                    ; const char* format, size_t resultSize, char* result
GetMnemonicBrief			    PROTO :DWORD, :DWORD, :DWORD                    ; const char* mnem, size_t resultSize, char* result
GetTraceRecordHitCount		    PROTO :DWORD                                    ; duint address
GetTraceRecordByteType		    PROTO :DWORD                                    ; duint address
SetTraceRecordType			    PROTO :DWORD, :DWORD                            ; duint pageAddress, TRACERECORDTYPE type
GetTraceRecordType			    PROTO :DWORD                                    ; duint pageAddress
EnumHandles					    PROTO :DWORD                                    ; ListOf(HANDLEINFO) handles
GetHandleName				    PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; duint handle, char* name, size_t nameSize, char* typeName, size_t typeNameSize
EnumTCPConnections			    PROTO :DWORD                                    ; ListOf(TCPCONNECTIONINFO) connections
GetDbgEvents				    PROTO                                           ;
ModGetParty					    PROTO :DWORD                                    ; duint base
ModSetParty					    PROTO :DWORD, :DWORD                            ; duint base, int party
WatchIsWatchDogTriggered	    PROTO :DWORD                                    ; unsigned int id
MemIsCodePage				    PROTO :DWORD, :DWORD                            ; duint addr, bool refresh
AnimateCommand				    PROTO :DWORD                                    ; const char* command
DbgSetDebuggeeInitScript	    PROTO :DWORD                                    ; const char* fileName
DbgGetDebuggeeInitScript	    PROTO                                           ;


; Other useful functions
DbgMapPE32File                  PROTO :DWORD, :DWORD
DbgUnmapPE32File                PROTO :DWORD

DbgGetEntryExitPoints           PROTO :DWORD, :DWORD
DbgGetSectionsFromAddr          PROTO :DWORD, :DWORD, :DWORD
DbgGetSectionsFromName          PROTO :DWORD, :DWORD, :DWORD
DbgMemGetPageRights             PROTO :DWORD, :DWORD


GuiGetActiveViewID              PROTO
GuiGetActiveViewHwnd            PROTO

MODSECTIONINFO                  STRUCT
    dwSectionAddress            DD ? ; Virtual address duint
    dwSectionSize               DD ? ; Virtual size duint 
    szSectionName               DB [MAX_SECTION_SIZE * 5] DUP (?) ; Escaped section name char 
MODSECTIONINFO                  ENDS


.CONST
GUI_VIEW_CPU                    EQU 1
GUI_VIEW_DUMP                   EQU 2 
GUI_VIEW_REGISTERS              EQU 3
GUI_VIEW_STACK                  EQU 4
GUI_VIEW_ARGUMENTS              EQU 5
GUI_VIEW_INFOBOX                EQU 6
GUI_VIEW_SIDEBAR                EQU 7
GUI_VIEW_CMDBAR                 EQU 8
GUI_VIEW_GRAPH                  EQU 20
GUI_VIEW_NOTES                  EQU 21
GUI_VIEW_LOG                    EQU 22
GUI_VIEW_SOFTBP                 EQU 30
GUI_VIEW_HARDBP                 EQU 31
GUI_VIEW_MEMBP                  EQU 32
GUI_VIEW_EXCEPTBP               EQU 33
GUI_VIEW_DLLBP                  EQU 34
GUI_VIEW_MEMMAP                 EQU 40
GUU_VIEW_CALLSTACK              EQU 41
GUI_VIEW_SEH                    EQU 42
GUI_VIEW_SCRIPT                 EQU 43
GUI_VIEW_SYMBOLS                EQU 44
GUI_VIEW_SOURCE                 EQU 45
GUI_VIEW_REF                    EQU 46
GUI_VIEW_REF_MGR                EQU 47
GUI_VIEW_THREADS                EQU 50
GUI_VIEW_HANDLES                EQU 60
GUI_VIEW_TCP                    EQU 61
GUI_VIEW_PRIV                   EQU 62






