;--------------------------------------------------------------------------------------------------------
; x64dbg plugin SDK for Masm - fearless 2016 - www.LetTheLight.in
;
; v1.0.0.5 - Last updated: 28/07/2016 
;
; Supports 32bit x32dbg only.
;
; Include file for x32bridge.dll exports, constants and structures.
;
; This is a conversion of the original plugin sdk files: bridgemain.h to a format that will work with 
; MASM and other assemblers (possibly).
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

; Bridge functions
BridgeAlloc                     PROTO C :DWORD ; (size_t size);
BridgeSettingFlush              PROTO C
BridgeFree                      PROTO C :DWORD ; (void* ptr);
BridgeGetDbgVersion             PROTO C
BridgeInit                      PROTO C
BridgeSettingGet                PROTO C :DWORD, :DWORD, :DWORD ; (const char* section, const char* key, char* value);
BridgeSettingGetUint            PROTO C :DWORD, :DWORD, :DWORD ; (const char* section, const char* key, duint* value);
BridgeSettingRead               PROTO C :DWORD  ; (int* errorLine)
BridgeSettingSet                PROTO C :DWORD, :DWORD, :DWORD ; (const char* section, const char* key, const char* value);
BridgeSettingSetUint            PROTO C :DWORD, :DWORD, :DWORD ; (const char* section, const char* key, duint value);
BridgeStart                     PROTO C

; Debugger functions
DbgInit                         PROTO C
DbgExit                         PROTO C
DbgMemRead                      PROTO C :DWORD, :DWORD, :DWORD ;(duint va, unsigned char* dest, duint size);
DbgMemWrite                     PROTO C :DWORD, :DWORD, :DWORD ;(duint va, const unsigned char* src, duint size);
DbgMemGetPageSize               PROTO C :DWORD ;(duint base);
DbgMemFindBaseAddr              PROTO C :DWORD, :DWORD ;(duint addr, duint* size);
DbgCmdExec                      PROTO C :DWORD;(const char* cmd);
DbgCmdExecDirect                PROTO C :DWORD ;(const char* cmd);
DbgMemMap                       PROTO C :DWORD ;(MEMMAP* memmap);
DbgIsValidExpression            PROTO C :DWORD ;(const char* expression);
DbgIsDebugging                  PROTO C
DbgIsJumpGoingToExecute         PROTO C :DWORD ;(duint addr);
DbgGetLabelAt                   PROTO C :DWORD, :DWORD, :DWORD ;(duint addr, SEGMENTREG segment, char* text);
DbgSetLabelAt                   PROTO C :DWORD, :DWORD ;(duint addr, const char* text);
DbgClearLabelRange              PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgGetCommentAt                 PROTO C :DWORD, :DWORD ;(duint addr, char* text);
DbgSetCommentAt                 PROTO C :DWORD, :DWORD ;(duint addr, const char* text);
DbgClearCommentRange            PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgGetBookmarkAt                PROTO C :DWORD ;(duint addr);
DbgSetBookmarkAt                PROTO C :DWORD, :DWORD ;(duint addr, bool isbookmark);
DbgClearBookmarkRange           PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgGetModuleAt                  PROTO C :DWORD, :DWORD ;(duint addr, char* text);
DbgGetBpxTypeAt                 PROTO C :DWORD ;(duint addr);
DbgValFromString                PROTO C :DWORD ;(const char* string);
DbgGetRegDump                   PROTO C :DWORD ;(REGDUMP* regdump);
DbgValToString                  PROTO C :DWORD, :DWORD ;(const char* string, duint value);
DbgMemIsValidReadPtr            PROTO C :DWORD ;(duint addr);
DbgGetBpList                    PROTO C :DWORD, :DWORD ;(BPXTYPE type, BPMAP* list);
DbgGetFunctionTypeAt            PROTO C :DWORD ;(duint addr);
DbgGetLoopTypeAt                PROTO C :DWORD, :DWORD ;(duint addr, int depth);
DbgGetBranchDestination         PROTO C :DWORD ;(duint addr);
DbgScriptLoad                   PROTO C :DWORD ;(const char* filename);
DbgScriptUnload                 PROTO C
DbgScriptRun                    PROTO C :DWORD ;(int destline);
DbgScriptStep                   PROTO C
DbgScriptBpToggle               PROTO C :DWORD ;(int line);
DbgScriptBpGet                  PROTO C :DWORD ;(int line);
DbgScriptCmdExec                PROTO C :DWORD ;(const char* command);
DbgScriptAbort                  PROTO C
DbgScriptGetLineType            PROTO C :DWORD ;(int line);
DbgScriptSetIp                  PROTO C :DWORD ;(int line);
DbgScriptGetBranchInfo          PROTO C :DWORD, :DWORD ;(int line, SCRIPTBRANCH* info);
DbgSymbolEnum                   PROTO C :DWORD, :DWORD, :DWORD ;(duint base, CBSYMBOLENUM cbSymbolEnum, void* user);
DbgSymbolEnumFromCache          PROTO C :DWORD, :DWORD, :DWORD ; (duint base, CBSYMBOLENUM cbSymbolEnum, void* user);
DbgAssembleAt                   PROTO C :DWORD, :DWORD ;(  duint addr, const char* instruction);
DbgModBaseFromName              PROTO C :DWORD ;(const char* name);
DbgDisasmAt                     PROTO C :DWORD, :DWORD ;(duint addr, DISASM_INSTR* instr);
DbgStackCommentGet              PROTO C :DWORD, :DWORD ;(duint addr, STACK_COMMENT* comment);
DbgGetThreadList                PROTO C :DWORD ;(THREADLIST* list);
DbgSettingsUpdated              PROTO C
DbgDisasmFastAt                 PROTO C :DWORD, :DWORD ;(duint addr, BASIC_INSTRUCTION_INFO* basicinfo);
DbgMenuEntryClicked             PROTO C :DWORD ;(int hEntry);
DbgFunctionGet                  PROTO C :DWORD, :DWORD, :DWORD ;(duint addr, duint* start, duint* end);
DbgFunctionOverlaps             PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgFunctionAdd                  PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgFunctionDel                  PROTO C :DWORD ;(duint addr);
DbgArgumentGet					PROTO C :DWORD, :DWORD, :DWORD ;(duint addr, duint* start, duint* end);
DbgArgumentOverlaps				PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgArgumentAdd					PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgArgumentDel					PROTO C :DWORD ;(duint addr);
DbgLoopGet                      PROTO C :DWORD, :DWORD, :DWORD, :DWORD;(int depth, duint addr, duint* start, duint* end);
DbgLoopOverlaps                 PROTO C :DWORD, :DWORD, :DWORD ;(int depth, duint start, duint end);
DbgLoopAdd                      PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgLoopDel                      PROTO C :DWORD, :DWORD ;(int depth, duint addr);
DbgXrefAdd                      PROTO C :DWORD, :DWORD ;(duint addr, duint from);
DbgXrefDelAll                   PROTO C :DWORD ;(duint addr);
DbgXrefGet                      PROTO C :DWORD, :DWORD ;(duint addr, XREF_INFO* info);
DbgGetXrefCountAt               PROTO C :DWORD ;(duint addr);
DbgGetXrefTypeAt                PROTO C :DWORD ;(duint addr);
DbgIsRunLocked                  PROTO C
DbgIsBpDisabled                 PROTO C :DWORD ;(duint addr);
DbgSetAutoCommentAt             PROTO C :DWORD, :DWORD ;(duint addr, const char* text);
DbgClearAutoCommentRange        PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgSetAutoLabelAt               PROTO C :DWORD, :DWORD ;(duint addr, const char* text);
DbgClearAutoLabelRange          PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgSetAutoBookmarkAt            PROTO C :DWORD ;(duint addr);
DbgClearAutoBookmarkRange       PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgSetAutoFunctionAt            PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgClearAutoFunctionRange       PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgGetStringAt                  PROTO C :DWORD, :DWORD ;(duint addr, char* text);
DbgFunctions                    PROTO C
DbgWinEvent                     PROTO C :DWORD, :DWORD ;(MSG* message, long* result);
DbgWinEventGlobal               PROTO C :DWORD ;(MSG* message);
DbgIsRunning                    PROTO C
DbgGetTimeWastedCounter         PROTO C
DbgGetArgTypeAt                 PROTO C :DWORD ;(duint addr);
DbgGetEncodeTypeBuffer          PROTO C :DWORD ;(duint addr);
DbgReleaseEncodeTypeBuffer      PROTO C :DWORD ;(void* buffer);
DbgGetEncodeTypeAt              PROTO C :DWORD, :DWORD ;(duint addr, duint size);
DbgGetEncodeSizeAt              PROTO C :DWORD, :DWORD ;(duint addr, duint codesize);
DbgSetEncodeType                PROTO C :DWORD, :DWORD, :DWORD ;(duint addr, duint size, ENCODETYPE type);
DbgDelEncodeTypeRange           PROTO C :DWORD, :DWORD ;(duint start, duint end);
DbgDelEncodeTypeSegment         PROTO C :DWORD ;(duint start);
DbgGetWatchList                 PROTO C :DWORD ;(ListOf(WATCHINFO) list);


GuiGetCurrentAddress			TEXTEQU <GuiSelectionGet> ; alias

; GUI functions
GuiDisasmAt                     PROTO C  :DWORD, :DWORD ; (duint addr, duint cip);
GuiSetDebugState                PROTO C  :DWORD ; (DBGSTATE state);
GuiAddLogMessage                PROTO C  :DWORD ; (const char* msg);
GuiLogClear                     PROTO C  
GuiUpdateAllViews               PROTO C  
GuiUpdateRegisterView           PROTO C 
GuiUpdateDisassemblyView        PROTO C  
GuiUpdateBreakpointsView        PROTO C  
GuiUpdateWindowTitle            PROTO C  :DWORD ; (const char* filename);
GuiGetWindowHandle              PROTO C  
GuiDumpAt                       PROTO C  :DWORD ; (duint va);
GuiScriptAdd                    PROTO C  :DWORD, :DWORD ; (int count, const char** lines);
GuiScriptClear                  PROTO C  
GuiScriptSetIp                  PROTO C  :DWORD ; (int line);
GuiScriptError                  PROTO C  :DWORD, :DWORD ; (int line, const char* message);
GuiScriptSetTitle               PROTO C  :DWORD ; (const char* title);
GuiScriptSetInfoLine            PROTO C  :DWORD, :DWORD ; (int line, const char* info);
GuiScriptMessage                PROTO C  :DWORD ; (const char* message);
GuiScriptMsgyn                  PROTO C  :DWORD ; (const char* message);
GuiScriptEnableHighlighting     PROTO C  :DWORD ; (bool enable);
GuiSymbolLogAdd                 PROTO C  :DWORD ; (const char* message);
GuiSymbolLogClear               PROTO C 
GuiSymbolSetProgress            PROTO C  :DWORD ; (int percent);
GuiSymbolUpdateModuleList       PROTO C  :DWORD, :DWORD ; (int count, SYMBOLMODULEINFO* modules);
GuiSymbolRefreshCurrent         PROTO C 
GuiReferenceAddColumn           PROTO C  :DWORD, :DWORD ; (int width, const char* title);
GuiReferenceSetRowCount         PROTO C  :DWORD ; (int count);
GuiReferenceGetRowCount			PROTO C	;()
GuiReferenceDeleteAllColumns    PROTO C  
GuiReferenceInitialize          PROTO C  :DWORD ; (const char* name);
GuiReferenceSetCellContent      PROTO C  :DWORD, :DWORD, :DWORD; (int row, int col, const char* str);
GuiReferenceGetCellContent      PROTO C  :DWORD, :DWORD ; (int row, int col);
GuiReferenceReloadData          PROTO C  
GuiReferenceSetSingleSelection  PROTO C  :DWORD, :DWORD ; (int index, bool scroll);
GuiReferenceSetProgress         PROTO C  :DWORD ; (int progress);
GuiReferenceSetCurrentTaskProgress PROTO C :DWORD, :DWORD ; (int progress, const char* taskTitle);
GuiReferenceSetSearchStartCol   PROTO C  :DWORD ; (int col);
GuiStackDumpAt                  PROTO C  :DWORD, :DWORD ; (duint addr, duint csp);
GuiUpdateDumpView               PROTO C
GuiUpdateWatchView				PROTO C
GuiUpdateThreadView             PROTO C
GuiUpdateMemoryView             PROTO C
GuiAddRecentFile                PROTO C  :DWORD ; (const char* file);
GuiSetLastException             PROTO C  :DWORD ; (unsigned int exception);
GuiGetDisassembly               PROTO C  :DWORD, :DWORD ; (duint addr, char* text);
GuiMenuAdd                      PROTO C  :DWORD, :DWORD ; (int hMenu, const char* title);
GuiMenuAddEntry                 PROTO C  :DWORD, :DWORD ; (int hMenu, const char* title);
GuiMenuAddSeparator             PROTO C  :DWORD ; (int hMenu);
GuiMenuClear                    PROTO C  :DWORD ; (int hMenu);
GuiSelectionGet                 PROTO C  :DWORD, :DWORD ; (int hWindow, SELECTIONDATA* selection);
GuiSelectionSet                 PROTO C  :DWORD, :DWORD ; (int hWindow, const SELECTIONDATA* selection);
GuiGetLineWindow                PROTO C  :DWORD, :DWORD ; (const char* title, char* text);
GuiAutoCompleteAddCmd           PROTO C  :DWORD ; (const char* cmd);
GuiAutoCompleteDelCmd           PROTO C  :DWORD ; (const char* cmd);
GuiAutoCompleteClearAll         PROTO C 
GuiAddStatusBarMessage          PROTO C  :DWORD ; (const char* msg);
GuiUpdateSideBar                PROTO C 
GuiRepaintTableView             PROTO C
GuiUpdatePatches                PROTO C
GuiUpdateCallStack              PROTO C
GuiUpdateSEHChain				PROTO C
GuiLoadSourceFile               PROTO C  :DWORD, :DWORD ; (const char* path, int line);
GuiMenuSetIcon                  PROTO C  :DWORD, :DWORD ; (int hMenu, const ICONDATA* icon);
GuiMenuSetEntryIcon             PROTO C  :DWORD, :DWORD ; (int hEntry, const ICONDATA* icon);
GuiShowCpu                      PROTO C
GuiAddQWidgetTab                PROTO C  :DWORD ; (void* qWidget);
GuiShowQWidgetTab               PROTO C  :DWORD ; (void* qWidget);
GuiCloseQWidgetTab              PROTO C  :DWORD ; (void* qWidget);
GuiExecuteOnGuiThread           PROTO C  :DWORD ; (GUICALLBACK cbGuiThread);
GuiUpdateTimeWastedCounter      PROTO C
GuiSetGlobalNotes               PROTO C  :DWORD ; (const char* text);
GuiGetGlobalNotes               PROTO C  :DWORD ; (char** text);
GuiSetDebuggeeNotes             PROTO C  :DWORD ; (const char* text);
GuiGetDebuggeeNotes             PROTO C  :DWORD ; (char** text);
GuiDumpAtN                      PROTO C  :DWORD, :DWORD ; (duint va, int index);
GuiDisplayWarning               PROTO C  :DWORD, :DWORD ; (const char* title, const char* text);
GuiRegisterScriptLanguage       PROTO C  :DWORD ; (SCRIPTTYPEINFO* info);
GuiUnregisterScriptLanguage     PROTO C  :DWORD ; (int id);
GuiUpdateArgumentWidget			PROTO C
GuiFocusView     				PROTO C  :DWORD ; (int hWindow);
GuiIsUpdateDisabled				PROTO C
GuiUpdateEnable     			PROTO C  :DWORD ; (bool updateNow);
GuiUpdateDisable				PROTO C
GuiLoadGraph     				PROTO C  :DWORD ; (BridgeCFGraphList* graph);
GuiGraphAt     					PROTO C  :DWORD ; (duint addr);
GuiUpdateGraphView				PROTO C



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

; Bridge defines
MAX_SETTING_SIZE                EQU 65536
DBG_VERSION                     EQU 25

; Debugger defines
MAX_LABEL_SIZE                  EQU 256d
MAX_COMMENT_SIZE                EQU 512d
MAX_MODULE_SIZE                 EQU 256d
MAX_BREAKPOINT_SIZE             EQU 256d
MAX_CONDITIONAL_EXPR_SIZE 		EQU 256d
MAX_CONDITIONAL_TEXT_SIZE 		EQU 256d
MAX_SCRIPT_LINE_SIZE            EQU 2048d
MAX_THREAD_NAME_SIZE            EQU 256d
MAX_WATCH_NAME_SIZE 			EQU 256d
MAX_STRING_SIZE                 EQU 512d
MAX_ERROR_SIZE                  EQU 512d
RIGHTS_STRING_SIZE              EQU 6d ;(sizeof("ERWCG") + 1)
MAX_SECTION_SIZE                EQU 10d
MAX_COMMAND_LINE_SIZE 			EQU 256d
MAX_MNEMONIC_SIZE               EQU 64d
PAGE_SIZE                       EQU 1000h
TCP_ADDR_SIZE 					EQU 50


; Debugger enums
enum initialized,paused,running,stopped
enum SEG_DEFAULT,SEG_ES,SEG_DS,SEG_FS,SEG_GS,SEG_CS,SEG_SS ; SEGMENTREG
enum flagmodule=1,flaglabel=2,flagcomment=4,flagbookmark=8,flagfunction=16,flagloop=32
enum bp_none=0,bp_normal=1,bp_hardware=2,bp_memory=4 ; BPXTYPE
enum FUNC_NONE,FUNC_BEGIN,FUNC_MIDDLE,FUNC_END,FUNC_SINGLE
enum LOOP_NONE,LOOP_BEGIN,LOOP_MIDDLE,LOOP_ENTRY,LOOP_END
enum XREF_NONE,XREF_DATA,XREF_JMP,XREF_CALL
enum ARG_NONE,ARG_BEGIN,ARG_MIDDLE,ARG_END,ARG_SINGLE

DBG_SCRIPT_LOAD                 EQU 0 ;param1=const char* filename,      param2=unused
DBG_SCRIPT_UNLOAD               EQU 1 ;param1=unused,                    param2=unused
DBG_SCRIPT_RUN                  EQU 2 ;param1=int destline,              param2=unused
DBG_SCRIPT_STEP                 EQU 3 ;param1=unused,                    param2=unused
DBG_SCRIPT_BPTOGGLE             EQU 4 ;param1=int line,                  param2=unused
DBG_SCRIPT_BPGET                EQU 5 ;param1=int line,                  param2=unused
DBG_SCRIPT_CMDEXEC              EQU 6 ;param1=const char* command,       param2=unused
DBG_SCRIPT_ABORT                EQU 7 ;param1=unused,                    param2=unused
DBG_SCRIPT_GETLINETYPE          EQU 8 ;param1=int line,                  param2=unused
DBG_SCRIPT_SETIP                EQU 9 ;param1=int line,                  param2=unused
DBG_SCRIPT_GETBRANCHINFO        EQU 10 ;param1=int line,                  param2=SCRIPTBRANCH* info
DBG_SYMBOL_ENUM                 EQU 11 ;param1=SYMBOLCBINFO* cbInfo,      param2=unused
DBG_ASSEMBLE_AT                 EQU 12 ;param1=duint addr,                param2=const char* instruction
DBG_MODBASE_FROM_NAME           EQU 13 ;param1=const char* modname,       param2=unused
DBG_DISASM_AT                   EQU 14 ;param1=duint addr,                 param2=DISASM_INSTR* instr
DBG_STACK_COMMENT_GET           EQU 15 ;param1=duint addr,                param2=STACK_COMMENT* comment
DBG_GET_THREAD_LIST             EQU 16 ;param1=THREADALLINFO* list,       param2=unused
DBG_SETTINGS_UPDATED            EQU 17 ;param1=unused,                    param2=unused
DBG_DISASM_FAST_AT              EQU 18 ;param1=duint addr,                param2=BASIC_INSTRUCTION_INFO* basicinfo
DBG_MENU_ENTRY_CLICKED          EQU 19 ;param1=int hEntry,                param2=unused
DBG_FUNCTION_GET                EQU 20 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_FUNCTION_OVERLAPS           EQU 21 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_FUNCTION_ADD                EQU 22 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_FUNCTION_DEL                EQU 23 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_GET                    EQU 24 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_OVERLAPS               EQU 25 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_ADD                    EQU 26 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_DEL                    EQU 27 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_IS_RUN_LOCKED               EQU 28 ;param1=unused,                    param2=unused
DBG_IS_BP_DISABLED              EQU 29 ;param1=duint addr,                param2=unused
DBG_SET_AUTO_COMMENT_AT         EQU 30 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_COMMENT_RANGE   EQU 31 ;param1=duint start,               param2=duint end
DBG_SET_AUTO_LABEL_AT           EQU 32 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_LABEL_RANGE     EQU 33 ;param1=duint start,               param2=duint end
DBG_SET_AUTO_BOOKMARK_AT        EQU 34 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_BOOKMARK_RANGE  EQU 35 ;param1=duint start,               param2=duint end
DBG_SET_AUTO_FUNCTION_AT        EQU 36 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_FUNCTION_RANGE  EQU 37 ;param1=duint start,               param2=duint end
DBG_GET_STRING_AT               EQU 38 ;param1=duint addr,                param2=unused
DBG_GET_FUNCTIONS               EQU 39 ;param1=unused,                    param2=unused
DBG_WIN_EVENT                   EQU 40 ;param1=MSG* message,              param2=long* result
DBG_WIN_EVENT_GLOBAL            EQU 41 ;param1=MSG* message,              param2=unused
DBG_INITIALIZE_LOCKS            EQU 42 ;param1=unused,                    param2=unused
DBG_DEINITIALIZE_LOCKS          EQU 43 ;param1=unused,                    param2=unused
DBG_GET_TIME_WASTED_COUNTER     EQU 44 ;param1=unused,                    param2=unused
DBG_SYMBOL_ENUM_FROMCACHE       EQU 45 ;param1=SYMBOLCBINFO* cbInfo,      param2=unused
DBG_DELETE_COMMENT_RANGE        EQU 46 ;param1=duint start,               param2=duint end
DBG_DELETE_LABEL_RANGE          EQU 47 ;param1=duint start,               param2=duint end
DBG_DELETE_BOOKMARK_RANGE       EQU 48 ;param1=duint start,               param2=duint end
DBG_GET_XREF_COUNT_AT       	EQU 49 ;param1=duint addr,                param2=unused
DBG_GET_XREF_TYPE_AT       		EQU 50 ;param1=duint addr,                param2=unused
DBG_XREF_ADD       				EQU 51 ;param1=duint addr,                param2=duint from
DBG_XREF_DEL_ALL       			EQU 52 ;param1=duint addr,                param2=unused
DBG_XREF_GET       				EQU 53 ;param1=duint addr,                param2=XREF_INFO* info
DBG_GET_ENCODE_TYPE_BUFFER      EQU 54 ;param1=duint addr,                param2=unused
DBG_ENCODE_TYPE_GET       		EQU 55 ;param1=duint addr,                param2=duint size
DBG_DELETE_ENCODE_TYPE_RANGE    EQU 56 ;param1=duint start,               param2=duint end
DBG_ENCODE_SIZE_GET       		EQU 57 ;param1=duint addr,                param2=duint codesize
DBG_DELETE_ENCODE_TYPE_SEG      EQU 58 ;param1=duint addr,                param2=unused
DBG_RELEASE_ENCODE_TYPE_BUFFER  EQU 59 ;param1=void* buffer,              param2=unused
DBG_ARGUMENT_GET       			EQU 60 ;param1=FUNCTION* info,            param2=unused
DBG_ARGUMENT_OVERLAPS       	EQU 61 ;param1=FUNCTION* info,            param2=unused
DBG_ARGUMENT_ADD       			EQU 62 ;param1=FUNCTION* info,            param2=unused
DBG_ARGUMENT_DEL       			EQU 63 ;param1=FUNCTION* info,            param2=unused
DBG_GET_WATCH_LIST       		EQU 64 ;param1=ListOf(WATCHINFO),         param2=unused

enum linecommand,linebranch,linelabel,linecomment,lineempty
enum scriptnobranch,scriptjmp,scriptjnejnz,scriptjejz,scriptjbjl,scriptjajg,scriptjbejle,scriptjaejge,scriptcall
enum instr_normal,instr_branch,instr_stack
enum arg_normal,arg_memory
enum str_none,str_ascii,str_unicode

; Thread Priority Enums
enum _PriorityIdle=-15,_PriorityAboveNormal=1,_PriorityBelowNormal=-1,_PriorityHighest=2,_PriorityLowest=-2,_PriorityNormal=0,_PriorityTimeCritical=15,_PriorityUnknown=7FFFFFFFh

; Threadwait reason enums
_Executive                      EQU  0
_FreePage                       EQU  1
_PageIn                         EQU  2
_PoolAllocation                 EQU  3
_DelayExecution                 EQU  4
_Suspended                      EQU  5
_UserRequest                    EQU  6
_WrExecutive                    EQU  7
_WrFreePage                     EQU  8
_WrPageIn                       EQU  9
_WrPoolAllocation               EQU  10d
_WrDelayExecution               EQU  11d
_WrSuspended                    EQU  12d
_WrUserRequest                  EQU  13d
_WrEventPair                    EQU  14d
_WrQueue                        EQU  15d
_WrLpcReceive                   EQU  16d
_WrLpcReply                     EQU  17d
_WrVirtualMemory                EQU  18d
_WrPageOut                      EQU  19d
_WrRendezvous                   EQU  20d
_Spare2                         EQU  21d
_Spare3                         EQU  22d
_Spare4                         EQU  23d
_Spare5                         EQU  24d
_WrCalloutStack                 EQU  25d
_WrKernel                       EQU  26d
_WrResource                     EQU  27d
_WrPushLock                     EQU  28d
_WrMutex                        EQU  29d
_WrQuantumEnd                   EQU  30d
_WrDispatchInt                  EQU  31d
_WrPreempted                    EQU  32d
_WrYieldExecution               EQU  33d
_WrFastMutex                    EQU  34d
_WrGuardedMutex                 EQU  35d
_WrRundown                      EQU  36d

; Memory Size Enums
enum size_byte=1,size_word=2,size_dword=4,size_qword=8

; Encode Type Enums
enc_unknown                    	EQU  0; must be 0
enc_byte                      	EQU  1; 1 byte
enc_word                      	EQU  2; 2 bytes
enc_dword                      	EQU  3; 4 bytes
enc_fword                      	EQU  4; 6 bytes
enc_qword                      	EQU  5; 8 bytes
enc_tbyte                      	EQU  6; 10 bytes
enc_oword                      	EQU  7; 16 bytes
enc_mmword                      EQU  8; 8 bytes
enc_xmmword                     EQU  9; 16 bytes
enc_ymmword                     EQU  10; 32 bytes
enc_zmmword                     EQU  11; 64 bytes avx512 not supported
enc_real4                      	EQU  12; 4 byte float
enc_real8                      	EQU  13; 8 byte double
enc_real10                      EQU  14; 10 byte decimal
enc_ascii                      	EQU  15; ascii sequence
enc_unicode                     EQU  16; unicode sequence
enc_code                      	EQU  17; start of code
enc_junk                      	EQU  18; junk code
enc_middle                      EQU  19; middle of data

; Watch Var Type Enums
TYPE_UINT                      	EQU  0 ;unsigned integer
TYPE_INT                      	EQU  1 ;signed integer
TYPE_FLOAT                      EQU  2 ;single precision floating point value
TYPE_ASCII                      EQU  3 ;ascii string
TYPE_UNICODE                    EQU  4 ;unicode string
TYPE_INVALID                    EQU  5 ;invalid watch expression or data type

; Watchdog Mode Enums
MODE_DISABLED                   EQU  0 ;watchdog is disabled
MODE_ISTRUE                    	EQU  1 ;alert if expression is not 0
MODE_ISFALSE                    EQU  2 ;alert if expression is 0
MODE_CHANGED                    EQU  3 ;alert if expression is changed
MODE_UNCHANGED                  EQU  4 ;alert if expression is not changed



; Debugger typedefs
DBGSTATE                        TYPEDEF DWORD
SEGMENTREG                      TYPEDEF DWORD
ADDRINFOFLAGS                   TYPEDEF DWORD
BPXTYPE                         TYPEDEF DWORD
FUNCTYPE                        TYPEDEF DWORD
LOOPTYPE                        TYPEDEF DWORD
DBGMSG                          TYPEDEF DWORD
SCRIPTLINETYPE                  TYPEDEF DWORD
SCRIPTBRANCHTYPE                TYPEDEF DWORD
DISASM_INSTRTYPE                TYPEDEF DWORD
DISASM_ARGTYPE                  TYPEDEF DWORD
STRING_TYPE                     TYPEDEF DWORD
THREADPRIORITY                  TYPEDEF DWORD
THREADWAITREASON                TYPEDEF DWORD
MEMORY_SIZE                     TYPEDEF DWORD
VALUE_SIZE                      TYPEDEF DWORD
GUIMSG                          TYPEDEF DWORD
WATCHVARTYPE					TYPEDEF DWORD
WATCHDOGMODE					TYPEDEF DWORD
XREFTYPE						TYPEDEF DWORD

; Debugger structs
MEMPAGE                         STRUCT 8
    mbi                         MEMORY_BASIC_INFORMATION <>
    info                        DB MAX_MODULE_SIZE DUP (?)
MEMPAGE                         ENDS

MEMMAP                          STRUCT 8
    count                       DWORD ?
    page                        DWORD ? ; pointer to MEMPAGE
MEMMAP                          ENDS

; BPXTYPE Breakpoint Type
BPNORMAL 				EQU 0
BPHARDWARE 				EQU 1
BPMEMORY 				EQU 2

BRIDGEBP                        STRUCT 8
    bpxtype                     BPXTYPE ?
    address                     DWORD ?
    enabled                     BYTE ?
    singleshoot                 BYTE ?
    active                      BYTE ?
    bpname                      DB MAX_BREAKPOINT_SIZE DUP (?)
    modd                        DB MAX_MODULE_SIZE DUP (?)
    slot                        WORD ? ;unsigned short slot;
    ; extended part
    hitCount					DWORD ? ;unsigned int 
    fastResume					BYTE ? ;bool 
    silent						BYTE ? ;bool 
    breakCondition				DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
    logText						DB MAX_CONDITIONAL_TEXT_SIZE DUP (?)
    logCondition				DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
    commandText					DB MAX_CONDITIONAL_TEXT_SIZE DUP (?)
    commandCondition			DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
BRIDGEBP                        ENDS

BPMAP                           STRUCT 8
    count                       DWORD ?
    lpBridgeBp                  DWORD ? ; BRIDGEBP* ; additional BRIDGEBPs are located in memory one after another, at lpBridgeBp + (SIZEOF BRIDGEBP * bpindex) where first bpindex is 0, second is 1 and so on
BPMAP                           ENDS

WATCHINFO						STRUCT 8
    WatchName					DB MAX_WATCH_NAME_SIZE DUP (?)
    Expression					DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
    window						DWORD ?; unsigned int 
    id							DWORD ?; unsigned int 
    varType						WATCHVARTYPE ?
    watchdogMode				WATCHDOGMODE ?
    value						DWORD ? ; duint
    watchdogTriggered			BYTE ? ; bool 
WATCHINFO						ENDS

FUNCTION                        STRUCT 8
    start                       DWORD ? ; duint
    finish                      DWORD ? ; duint
	instrcount					DWORD ? ; duint
FUNCTION                        ENDS

LOOP_                           STRUCT 8
    depth                       DWORD ? ; int
    start                       DWORD ? ; duint
    finish                      DWORD ? ; duint
LOOP_                           ENDS

ADDRINFO                        STRUCT 8
    flags                       DWORD ?; //ADDRINFOFLAGS (IN)
    module                      DB MAX_MODULE_SIZE DUP (?) ; //module the address is in
    label_                      DB MAX_LABEL_SIZE DUP (?)
    comment_                    DB MAX_COMMENT_SIZE DUP (?)
    isbookmark                  DWORD ?;
    function                    FUNCTION <>
    loop_                       LOOP_ <>
ADDRINFO                        ENDS

SYMBOLINFO_                     STRUCT 8
    address                     DWORD ? ; duint
    decoratedSymbol             DWORD ? ; char*
    undecoratedSymbol           DWORD ? ; char*
	isImported					BYTE ? ; bool
SYMBOLINFO_                     ENDS

SYMBOLMODULEINFO                STRUCT 8
    base                        DWORD ? ; duint
    name                        DB MAX_MODULE_SIZE DUP (?)
SYMBOLMODULEINFO                ENDS

SYMBOLCBINFO                    STRUCT 8
    base                        DWORD ? ; duint
    cbSymbolEnum                DWORD ? ;CBSYMBOLENUM
    user                        DWORD ?
SYMBOLCBINFO                    ENDS

FLAGS                           STRUCT 8
    c_                          DWORD ?
    p                           DWORD ?
    a                           DWORD ?
    z                           DWORD ?
    s                           DWORD ?
    t                           DWORD ?
    i                           DWORD ?
    d                           DWORD ?
    o                           DWORD ?
FLAGS                           ENDS

MXCSRFIELDS                     STRUCT 8
    FZ                          DWORD ?
    PM                          DWORD ?
    UM                          DWORD ?
    OM                          DWORD ?
    ZM                          DWORD ?
    IM                          DWORD ?
    DM                          DWORD ?
    DAZ                         DWORD ?
    PE                          DWORD ?
    UE                          DWORD ?
    OE                          DWORD ?
    ZE                          DWORD ?
    DE                          DWORD ?
    IE                          DWORD ?
    RC                          WORD ?
MXCSRFIELDS                     ENDS

X87STATUSWORDFIELDS             STRUCT 8
    B                           DWORD ?
    C3                          DWORD ?
    C2                          DWORD ?
    C1                          DWORD ?
    C0                          DWORD ?
    IR                          DWORD ?
    SF                          DWORD ?
    P                           DWORD ?
    U                           DWORD ?
    O                           DWORD ?
    Z                           DWORD ?
    D                           DWORD ?
    I                           DWORD ?
    TOP                         WORD ?
X87STATUSWORDFIELDS             ENDS

X87CONTROLWORDFIELDS            STRUCT 8
    IC                          DWORD ?
    IEM                         DWORD ?
    PM                          DWORD ?
    UM                          DWORD ?
    OM                          DWORD ?
    ZM                          DWORD ?
    DM                          DWORD ?
    IM                          DWORD ?
    RC                          WORD ?
    PC                          WORD ?
X87CONTROLWORDFIELDS            ENDS

XMMREGISTER                     STRUCT 8
    XMMLow                      DWORD ?
    XMMHigh                     DWORD ?
XMMREGISTER                     ENDS
   
YMMREGISTER                     STRUCT 8
    YMMLow                      XMMREGISTER <>; //XMM/SSE part
    YMMHigh                     XMMREGISTER <>; //AVX part
YMMREGISTER                     ENDS

X87FPUREGISTER                  STRUCT 8
    data                        DB 10 DUP (?)
    st_value                    DWORD ?
    tag                         DWORD ?
X87FPUREGISTER                  ENDS

X87FPU                          STRUCT 8
    ControlWord                 WORD ?
    StatusWord                  WORD ?
    TagWord                     WORD ?
    ErrorOffset                 DWORD ?
    ErrorSelector               DWORD ?
    DataOffset                  DWORD ?
    DataSelector                DWORD ?
    Cr0NpxState                 DWORD ?
X87FPU                          ENDS

REGISTERCONTEXT                 STRUCT 8
    cax                         DWORD ?
    ccx                         DWORD ?
    cdx                         DWORD ?
    cbx                         DWORD ?
    csp                         DWORD ?
    cbp                         DWORD ?
    csi                         DWORD ?
    cdi                         DWORD ?
IFDEF _WIN64
    r8                          DWORD ?
    r9                          DWORD ?
    r10                         DWORD ?
    r11                         DWORD ?
    r12                         DWORD ?
    r13                         DWORD ?
    r14                         DWORD ?
    r15                         DWORD ?
ENDIF ; _WIN64
    cip                         DWORD ?
    eflags                      DWORD ?
    gs_                         WORD ?
    fs_                         WORD ?
    es_                         WORD ?
    ds_                         WORD ?
    cs_                         WORD ?
    ss_                         WORD ?
    dr0_                        DWORD ?
    dr1_                        DWORD ?
    dr2_                        DWORD ?
    dr3_                        DWORD ?
    dr6_                        DWORD ?
    dr7_                        DWORD ?
    RegisterArea                DB 80 DUP (?)
    x87fpu                      X87FPU <>
    MxCsr                       DWORD ?
IFDEF _WIN64
    XmmRegisters                XMMREGISTER 16 DUP ({})
    YmmRegisters                YMMREGISTER 16 DUP ({})
ELSE ; x86
    XmmRegisters                XMMREGISTER 8 DUP ({})
    YmmRegisters                YMMREGISTER 8 DUP ({})
ENDIF
REGISTERCONTEXT                 ENDS

LASTERROR						STRUCT 8
    code						DWORD ?;
    name						DB 128 DUP (?)
LASTERROR						ENDS

REGDUMP                         STRUCT 8
    regcontext                  REGISTERCONTEXT <>
    flags                       FLAGS <>
    x87FPURegisters             X87FPUREGISTER 8 DUP ({})
    mmx                         DQ ?
    MxCsrFields                 MXCSRFIELDS <>
    x87StatusWordFields         X87STATUSWORDFIELDS <>
    x87ControlWordFields        X87CONTROLWORDFIELDS <>
	lastError					LASTERROR <>
REGDUMP                         ENDS

DISASM_ARG                      STRUCT 8
    type_                       DISASM_ARGTYPE ?
    segment_                    SEGMENTREG ?
    mnemonic                    DB 64 DUP (?)
    constant                    DWORD ? ; duint
    value                       DWORD ? ; duint
    memvalue                    DWORD ? ; duint
DISASM_ARG                      ENDS

DISASM_INSTR                    STRUCT 8
    instruction                 DB 64 DUP (?)
    type_                       DISASM_INSTRTYPE ?
    argcount                    DWORD ?
    instr_size                  DWORD ?
    arg                         DISASM_ARG 3 DUP ({})
DISASM_INSTR                    ENDS

STACK_COMMENT                   STRUCT
    color                       DB 8 DUP (?); //hex color-code
    comment_                    DB MAX_COMMENT_SIZE DUP (?);
STACK_COMMENT                   ENDS

THREADINFO                      STRUCT 8
    ThreadNumber                DWORD ?
    hThread                     HANDLE ? 
    dwThreadId                  DWORD ?
    ThreadStartAddress          DWORD ?
    ThreadLocalBase             DWORD ?
    threadName                  DB MAX_THREAD_NAME_SIZE DUP (?)
THREADINFO                      ENDS

THREADALLINFO                   STRUCT 8
    BasicInfo                   THREADINFO <>
    ThreadCip                   DWORD ?
    SuspendCount                DWORD ?
    Priority                    THREADPRIORITY <>
    WaitReason                  THREADWAITREASON <>     
    LastError                   DWORD ?
THREADALLINFO                   ENDS

THREADLIST                      STRUCT 8
    count                       DWORD ?
    list                        THREADALLINFO <>
    CurrentThread               DWORD ?
THREADLIST                      ENDS

MEMORY_INFO                     STRUCT 8
    value                       DWORD ?  ; ULONG_PTR //displacement / addrvalue (rip-relative)
    size_                       DWORD ? ;MEMORY_SIZE ?; //byte/word/dword/qword
    mnemonic                    DB MAX_MNEMONIC_SIZE DUP (?)
MEMORY_INFO                     ENDS

VALUE_INFO                      STRUCT 8
    value                       DWORD ?; ULONG_PTR;
    size_                       DWORD ? ;VALUE_SIZE ?
VALUE_INFO                      ENDS

TYPE_VALUE                      EQU 1d
TYPE_MEMORY                     EQU 2d
TYPE_ADDR                       EQU 4d

BASIC_INSTRUCTION_INFO          STRUCT 8
    type_                       DWORD ?; //value|memory|addr ;4
    value                       VALUE_INFO <>; //immediat
    memory                      MEMORY_INFO <>; 76
    address                     DWORD ? ;ULONG_PTR; //addrvalue (jumps + calls) ;88
    branch                      BYTE ?; //jumps/calls: 1 = jmp, 257 = call ;92
    call_                       BYTE ?; //instruction is a call - this is the length of the instruction ; 94
    ;boolpad                     WORD ? ;padding for boolean fields branch and call - not needed align struct 8 instead
    size_                       DWORD ? ;96
    instruction                 DB [MAX_MNEMONIC_SIZE * 4] DUP (?); 100
BASIC_INSTRUCTION_INFO          ENDS

SCRIPTBRANCH                    STRUCT 8
    type_                       SCRIPTBRANCHTYPE <>
    dest                        DWORD ?
    branchlabel                 DB 256 DUP (?)
SCRIPTBRANCH                    ENDS

FUNCTION_LOOP_INFO              STRUCT 8
    address                     DWORD ?
    start                       DWORD ?
    finish                      DWORD ?
    manual                      DWORD ?
    depth                       DWORD ?
FUNCTION_LOOP_INFO              ENDS

XREF_RECORD						STRUCT 8
	address						DWORD ? ; duint 
    type_						XREFTYPE ? ;  
XREF_RECORD						ENDS

XREF_INFO						STRUCT 8
    refcount					DWORD ? ; duint
    references					DWORD ? ; XREF_RECORD* 
XREF_INFO						ENDS

; Gui defines
GUI_PLUGIN_MENU                 EQU 0
GUI_DISASM_MENU                 EQU 1
GUI_DUMP_MENU                   EQU 2
GUI_STACK_MENU                  EQU 3

GUI_DISASSEMBLY                 EQU 0
GUI_DUMP                        EQU 1
GUI_STACK                       EQU 2

GUI_MAX_LINE_SIZE               EQU 65536d
GUI_MAX_DISASSEMBLY_SIZE        EQU 2048d


; Gui enums
GUI_DISASSEMBLE_AT              EQU 0  ; param1=(duint)va,            param2=(duint)cip
GUI_SET_DEBUG_STATE             EQU 1  ; param1=(DBGSTATE)state,      param2=unused
GUI_ADD_MSG_TO_LOG              EQU 2  ; param1=(const char*)msg,     param2=unused
GUI_CLEAR_LOG                   EQU 3  ; param1=unused,               param2=unused
GUI_UPDATE_REGISTER_VIEW        EQU 4  ; param1=unused,               param2=unused
GUI_UPDATE_DISASSEMBLY_VIEW     EQU 5  ; param1=unused,               param2=unused
GUI_UPDATE_BREAKPOINTS_VIEW     EQU 6  ; param1=unused,               param2=unused
GUI_UPDATE_WINDOW_TITLE         EQU 7  ; param1=(const char*)file,    param2=unused
GUI_GET_WINDOW_HANDLE           EQU 8  ; param1=unused,               param2=unused
GUI_DUMP_AT                     EQU 9  ; param1=(duint)va             param2=unused
GUI_SCRIPT_ADD                  EQU 10 ; param1=int count,            param2=const char** lines
GUI_SCRIPT_CLEAR                EQU 11 ; param1=unused,               param2=unused
GUI_SCRIPT_SETIP                EQU 12 ; param1=int line,             param2=unused
GUI_SCRIPT_ERROR                EQU 13 ; param1=int line,             param2=const char* message
GUI_SCRIPT_SETTITLE             EQU 14 ; param1=const char* title,    param2=unused
GUI_SCRIPT_SETINFOLINE          EQU 15 ; param1=int line,             param2=const char* info
GUI_SCRIPT_MESSAGE              EQU 16 ; param1=const char* message,  param2=unused
GUI_SCRIPT_MSGYN                EQU 17 ; param1=const char* message,  param2=unused
GUI_SYMBOL_LOG_ADD              EQU 18 ; param1(const char*)msg,      param2=unused
GUI_SYMBOL_LOG_CLEAR            EQU 19 ; param1=unused,               param2=unused
GUI_SYMBOL_SET_PROGRESS         EQU 20 ; param1=int percent           param2=unused
GUI_SYMBOL_UPDATE_MODULE_LIST   EQU 21 ; param1=int count,            param2=SYMBOLMODULEINFO* modules
GUI_REF_ADDCOLUMN               EQU 22 ; param1=int width,            param2=(const char*)title
GUI_REF_SETROWCOUNT             EQU 23 ; param1=int rows,             param2=unused
GUI_REF_GETROWCOUNT             EQU 24 ; param1=unused,               param2=unused
GUI_REF_DELETEALLCOLUMNS        EQU 25 ; param1=unused,               param2=unused
GUI_REF_SETCELLCONTENT          EQU 26 ; param1=(CELLINFO*)info,      param2=unused
GUI_REF_GETCELLCONTENT          EQU 27 ; param1=int row,              param2=int col
GUI_REF_RELOADDATA              EQU 28 ; param1=unused,               param2=unused
GUI_REF_SETSINGLESELECTION      EQU 29 ; param1=int index,            param2=bool scroll
GUI_REF_SETPROGRESS             EQU 30 ; param1=int progress,         param2=unused
GUI_REF_SETCURRENTTASKPROGRESS  EQu 31 ; param1=int progress,         param2=const char* taskTitle
GUI_REF_SETSEARCHSTARTCOL       EQU 32 ; param1=int col               param2=unused
GUI_STACK_DUMP_AT               EQU 33 ; param1=duint addr,           param2=duint csp
GUI_UPDATE_DUMP_VIEW            EQU 34 ; param1=unused,               param2=unused
GUI_UPDATE_THREAD_VIEW          EQU 35 ; param1=unused,               param2=unused
GUI_ADD_RECENT_FILE             EQU 36 ; param1=(const char*)file,    param2=unused
GUI_SET_LAST_EXCEPTION          EQU 37 ; param1=unsigned int code,    param2=unused
GUI_GET_DISASSEMBLY             EQU 38 ; param1=duint addr,           param2=char* text
GUI_MENU_ADD                    EQU 39 ; param1=int hMenu,            param2=const char* title
GUI_MENU_ADD_ENTRY              EQU 40 ; param1=int hMenu,            param2=const char* title
GUI_MENU_ADD_SEPARATOR          EQU 41 ; param1=int hMenu,            param2=unused
GUI_MENU_CLEAR                  EQU 42 ; param1=int hMenu,            param2=unused
GUI_SELECTION_GET               EQU 43 ; param1=int hWindow,          param2=SELECTIONDATA* selection
GUI_SELECTION_SET               EQU 44 ; param1=int hWindow,          param2=const SELECTIONDATA* selection
GUI_GETLINE_WINDOW              EQU 45 ; param1=const char* title,    param2=char* text
GUI_AUTOCOMPLETE_ADDCMD         EQU 46 ; param1=const char* cmd,      param2=ununsed
GUI_AUTOCOMPLETE_DELCMD         EQU 47 ; param1=const char* cmd,      param2=ununsed
GUI_AUTOCOMPLETE_CLEARALL       EQU 48 ; param1=unused,               param2=unused
GUI_SCRIPT_ENABLEHIGHLIGHTING   EQU 49 ; param1=bool enable,          param2=unused
GUI_ADD_MSG_TO_STATUSBAR        EQU 50 ; param1=const char* msg,      param2=unused
GUI_UPDATE_SIDEBAR              EQU 51 ; param1=unused,               param2=unused
GUI_REPAINT_TABLE_VIEW          EQU 52 ; param1=unused,               param2=unused
GUI_UPDATE_PATCHES              EQU 53 ; param1=unused,               param2=unused
GUI_UPDATE_CALLSTACK            EQU 54 ; param1=unused,               param2=unused
GUI_UPDATE_SEHCHAIN				EQU 55 ; param1=unused,               param2=unused
GUI_SYMBOL_REFRESH_CURRENT      EQU 56 ; param1=unused,               param2=unused
GUI_UPDATE_MEMORY_VIEW          EQU 57 ; param1=unused,               param2=unused
GUI_REF_INITIALIZE              EQU 58 ; param1=const char* name      param2=unused
GUI_LOAD_SOURCE_FILE            EQU 59 ; param1=const char* path,     param2=line
GUI_MENU_SET_ICON               EQU 60 ; param1=int hMenu,            param2=ICONINFO*
GUI_MENU_SET_ENTRY_ICON         EQU 61 ; param1=int hEntry,           param2=ICONINFO*
GUI_SHOW_CPU                    EQU 62 ; param1=unused,               param2=unused
GUI_ADD_QWIDGET_TAB             EQU 63 ; param1=QWidget*,             param2=unused
GUI_SHOW_QWIDGET_TAB            EQU 64 ; param1=QWidget*,             param2=unused
GUI_CLOSE_QWIDGET_TAB           EQU 65 ; param1=QWidget*,             param2=unused
GUI_EXECUTE_ON_GUI_THREAD       EQU 66 ; param1=GUICALLBACK,          param2=unused
GUI_UPDATE_TIME_WASTED_COUNTER  EQU 67 ; param1=unused,               param2=unused
GUI_SET_GLOBAL_NOTES            EQU 68 ; param1=const char* text,     param2=unused
GUI_GET_GLOBAL_NOTES            EQU 69 ; param1=char** text,          param2=unused
GUI_SET_DEBUGGEE_NOTES          EQU 70 ; param1=const char* text,     param2=unused
GUI_GET_DEBUGGEE_NOTES          EQU 71 ; param1=char** text,          param2=unused
GUI_DUMP_AT_N                   EQU 72 ; param1=int index,            param2=duint va
GUI_DISPLAY_WARNING             EQU 73 ; param1=const char *text,     param2=unused
GUI_REGISTER_SCRIPT_LANG        EQU 74 ; param1=SCRIPTTYPEINFO* info, param2=unused
GUI_UNREGISTER_SCRIPT_LANG      EQU 75 ; param1=int id,               param2=unused
GUI_UPDATE_ARGUMENT_VIEW      	EQU 76 ; param1=unused,               param2=unused
GUI_FOCUS_VIEW      			EQU 77 ; param1=int hWindow,          param2=unused
GUI_UPDATE_WATCH_VIEW      		EQU 78 ; param1=unused,               param2=unused
GUI_LOAD_GRAPH      			EQU 79 ; param1=BridgeCFGraphList*    param2=unused
GUI_GRAPH_AT      				EQU 80 ; param1=duint addr            param2=unused
GUI_UPDATE_GRAPH_VIEW      		EQU 81 ; param1=unused,               param2=unused

; GUI Typedefs
GUICALLBACK                     PROTO C
GUISCRIPTEXECUTE                PROTO C  :DWORD ; (const char* text);
GUISCRIPTCOMPLETER              PROTO C  :DWORD, :DWORD, :DWORD ;(const char* text, char** entries, int* entryCount);

; GUI structures
CELLINFO                        STRUCT 8
    row                         DWORD ?
    col                         DWORD ?
    string                      DWORD ?
CELLINFO                        ENDS

SELECTIONDATA                   STRUCT 8
    start                       DWORD ?
    finish                      DWORD ?
SELECTIONDATA                   ENDS

ICONDATA                        STRUCT 8
    data                        DWORD ?
    size_                       DWORD ?
ICONDATA                        ENDS

SCRIPTTYPEINFO                  STRUCT 8
    name                        DB 64 DUP (?)
    id                          DWORD ?
    execute                     DWORD ? ; pointer to GUISCRIPTEXECUTE ?
    completeCommand             DWORD ? ; pointer to GUISCRIPTCOMPLETER ?
SCRIPTTYPEINFO                  ENDS


; Dbg functions
dbgfunctionsget                 PROTO C
dbgfunctionsinit                PROTO C

; DbgFunction Structures
DBGPATCHINFO                    STRUCT 8
    module                      DB MAX_MODULE_SIZE DUP (?)
    address                     DWORD ?
    oldbyte                     DB ?
    newbyte                     DB ?
DBGPATCHINFO                    ENDS

DBGCALLSTACKENTRY               STRUCT 8
    address                     DWORD ?
    from                        DWORD ?
    to                          DWORD ?
    comment_                    DB MAX_COMMENT_SIZE DUP (?)
DBGCALLSTACKENTRY               ENDS

DBGCALLSTACK                    STRUCT 8
    total                       DWORD ?
    entries                     DBGCALLSTACKENTRY {<>}
DBGCALLSTACK                    ENDS

DBGPROCESSINFO                  STRUCT 8
    dwProcessId                 DWORD ?
    szExeFile                   DB MAX_PATH DUP (?)
DBGPROCESSINFO                  ENDS

; TraceRecord Byte Type
enum InstructionBody=0,InstructionHeading,InstructionTailing,InstructionOverlapped
enum DataByte=4,DataWord,DataDWord,DataQWord,DataFloat,DataDouble,DataLongDouble,DataXMM,DataYMM,DataMMX,DataMixed,InstructionDataMixed

; TraceRecord Type
enum TraceRecordNone,TraceRecordBitExec,TraceRecordByteWithExecTypeAndCounter,TraceRecordWordWithExecTypeAndCounter

HANDLEINFO						STRUCT 8
    Handle						DWORD ? ; duint
    TypeNumber					BYTE ? ; unsigned char 
    GrantedAccess				DWORD ? ; unsigned int
HANDLEINFO						ENDS

TCPCONNECTIONINFO				STRUCT 8
	RemoteAddress				DB TCP_ADDR_SIZE DUP (?)
    RemotePort					WORD ? ; unsigned short 
    LocalAddress				DB TCP_ADDR_SIZE DUP (?)
    LocalPort					WORD ? ; unsigned short 
    StateText					DB TCP_ADDR_SIZE DUP (?)
    State						DWORD ? ; unsigned int 
TCPCONNECTIONINFO				ENDS

;--------------------------------------------------------------------------------------------------------
; DbgFunctions returns a pointer to a DBGFUNCTIONS structure, which contains a list of function calls.
; The _DbgFunctions macro provided helps with calling these indirect functions.
;
; Example to call the ModPathFromAddr function:
;
; LOCAL sel:SELECTIONDATA
; LOCAL modpath[MAX_PATH]:BYTE
;
; Invoke GuiSelectionGet, GUI_DISASSEMBLY, Addr sel
; _DbgFunctions ModPathFromAddr, sel.start, Addr modpath, MAX_PATH
;
;--------------------------------------------------------------------------------------------------------
DBGFUNCTIONS                    STRUCT 8
    AssembleAtEx                DWORD ? ; (duint addr, const char* instruction, char* error, bool fillnop);
    SectionFromAddr             DWORD ? ; (duint addr, char* section);
    ModNameFromAddr             DWORD ? ; (duint addr, char* modname, bool extension);
    ModBaseFromAddr             DWORD ? ; (duint addr);
    ModBaseFromName             DWORD ? ; (const char* modname);
    ModSizeFromAddr             DWORD ? ; (duint addr);
    Assemble                    DWORD ? ; (duint addr, unsigned char* dest, int* size, const char* instruction, char* error);
    PatchGet                    DWORD ? ; (duint addr);
    PatchInRange                DWORD ? ; (duint start, duint end);
    MemPatch                    DWORD ? ; (duint va, const unsigned char* src, duint size);
    PatchRestoreRange           DWORD ? ; (duint start, duint end);
    PatchEnum                   DWORD ? ; (DBGPATCHINFO* patchlist, size_t* cbsize);
    PatchRestore                DWORD ? ; (duint addr)
    PatchFile                   DWORD ? ; (DBGPATCHINFO* patchlist, int count, const char* szFileName, char* error);
    ModPathFromAddr             DWORD ? ; (duint addr, char* path, int size);
    ModPathFromName             DWORD ? ; (const char* modname, char* path, int size);
    DisasmFast                  DWORD ? ; (unsigned char* data, duint addr, BASIC_INSTRUCTION_INFO* basicinfo);
    MemUpdateMap                DWORD ? ; 
    GetCallStack                DWORD ? ; (DBGCALLSTACK* callstack);
	GetSEHChain					DWORD ? ; (DBGSEHCHAIN* sehchain);
    SymbolDownloadAllSymbols    DWORD ? ; (const char* szSymbolStore);
    GetJitAuto                  DWORD ? ; (bool* jitauto)
    GetJit                      DWORD ? ; (char* jit, bool x64);
    GetDefJit                   DWORD ? ; (char* defjit);
    GetProcessList              DWORD ? ; (DBGPROCESSINFO** entries, int* count);
    GetPageRights               DWORD ? ; (duint addr, char* rights);
    SetPageRights               DWORD ? ; (duint addr, const char* rights);
    PageRightsToString          DWORD ? ; (DWORD protect, char* rights);
    IsProcessElevated           DWORD ? ;
    GetCmdline                  DWORD ? ; (char* cmdline, size_t* cbsize);
    SetCmdline                  DWORD ? ; (const char* cmdline);
    FileOffsetToVa              DWORD ? ; (const char* modname, duint offset);
    VaToFileOffset              DWORD ? ; (duint va);
    GetAddrFromLine             DWORD ? ; (const char* szSourceFile, int line);
    GetSourceFromAddr           DWORD ? ; (duint addr, char* szSourceFile, int* line);
    ValFromString               DWORD ? ; (const char* string, duint* value);
    PatchGetEx                  DWORD ? ; (duint addr, DBGPATCHINFO* info);
	GetBridgeBP					DWORD ? ; (BPXTYPE type, duint addr, BRIDGEBP* bp);
	StringFormatInline			DWORD ? ; (const char* format, size_t resultSize, char* result);
	GetMnemonicBrief			DWORD ? ; (const char* mnem, size_t resultSize, char* result);
	GetTraceRecordHitCount		DWORD ? ; (duint address);
	GetTraceRecordByteType		DWORD ? ; (duint address);
	SetTraceRecordType			DWORD ? ; (duint pageAddress, TRACERECORDTYPE type);
	GetTraceRecordType			DWORD ? ; (duint pageAddress);
	EnumHandles					DWORD ? ; (ListOf(HANDLEINFO) handles);
	GetHandleName				DWORD ? ; (duint handle, char* name, size_t nameSize, char* typeName, size_t typeNameSize);
	EnumTCPConnections			DWORD ? ; (ListOf(TCPCONNECTIONINFO) connections);
	GetDbgEvents				DWORD ? ; ();
	ModGetParty					DWORD ? ; (duint base);
	ModSetParty					DWORD ? ; (duint base, int party);
	WatchIsWatchDogTriggered	DWORD ? ; (unsigned int id);
DBGFUNCTIONS                    ENDS



;--------------------------------------------------------------------------------------------------------
; _DbgFunctions macro for calling indirect functions stored in the DBGFUNCTIONS structure
; The return value from the DbgFunctions() call is a pointer to the DBGFUNCTIONS structure
; which this macro handles for you. 
;
; Simply specify the name of the function (the structure member name in DBGFUNCTIONS)
; and pass any required parameters as specified in the comments at the end of each line.
;
;--------------------------------------------------------------------------------------------------------
_DbgFunctions MACRO funcname:REQ,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20
LOCAL pos
LOCAL __dbgfunction
.DATA
__dbgfunction DD 0
.CODE
    Invoke DbgFunctions
    mov eax, [eax].DBGFUNCTIONS.funcname
    mov __dbgfunction, eax
    FOR arg,<p20,p19,p18,p17,p16,p15,p14,p13,p12,p11,p10,p9,p8,p7,p6,p5,p4,p3,p2,p1>
        IFNB <arg>
            pos=@InStr(1,arg,<ADDR>) OR @InStr(1,arg,<addr>) OR @InStr(1,arg,<Addr>)
            IF pos
                IF (OPATTR(@SubStr(arg,%pos+5))) EQ 98
                    lea eax,@SubStr(<arg>,%pos+5)
                    push eax
                ELSE
                    push OFFSET @SubStr(<arg>,%pos+5)
                ENDIF
            ELSE
                push arg
            ENDIF
        ENDIF
    ENDM
call __dbgfunction
ENDM


