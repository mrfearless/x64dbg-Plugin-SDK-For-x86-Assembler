;=====================================================================================
; x64_dbg plugin SDK for Masm - fearless 2015
;
; Supports 32bit x32_dbg only.
;
; Remember to edit your .def file to include any additional exports for your plugin. 
;
; This is a small template for creating your own plugins for x32_dbg

; Please see the x64_dbg.chm Plugins section and the testplugin example code for more
; details on adding in functionality to your plugin.
;
;-------------------------------------------------------------------------------------

.686
.MMX
.XMM
.model flat,stdcall
option casemap:none


;=====================================================================================
; Main x64_dbg Plugin SDK for your program, and prototypes for the main exports
;-------------------------------------------------------------------------------------
include x64dbgpluginsdk.inc

pluginit	        PROTO C :DWORD
plugstop            PROTO C
plugsetup           PROTO C :DWORD
;=====================================================================================

include testplugin.inc

.CONST
;-------------------------------------------------------------------------------------
; Your Plugin Version for PLUG_INITSTRUCT.pluginVersion during pluginit
;-------------------------------------------------------------------------------------
PLUGIN_VERSION      EQU 1                   

.DATA
;-------------------------------------------------------------------------------------
; Your Plugin Name for PLUG_INITSTRUCT.pluginName during pluginit
;-------------------------------------------------------------------------------------
PLUGIN_NAME         DB "TestPlugin",0       

.DATA?
;-------------------------------------------------------------------------------------
; GLOBAL Plugin SDK variables
;-------------------------------------------------------------------------------------
PUBLIC              pluginHandle
PUBLIC              hwndDlg
PUBLIC              hMenu
PUBLIC              hMenuDisasm
PUBLIC              hMenuDump
PUBLIC              hMenuStack

pluginHandle        DD ?
hwndDlg             DD ?
hMenu               DD ?
hMenuDisasm         DD ?
hMenuDump           DD ?
hMenuStack          DD ?

.CODE

;=====================================================================================
; Main function for a DLL file.
;-------------------------------------------------------------------------------------
DllEntry PROC hInst:HINSTANCE, reason:DWORD, reserved:DWORD
    .IF reason == DLL_PROCESS_ATTACH
        mov eax, hInst
        mov hInstance, eax
    .ENDIF
	mov  eax,TRUE
	ret
DllEntry Endp


;=====================================================================================
; pluginit - Called by debugger when plugin.dp32 is loaded - needs to be EXPORTED
; 
; Arguments: initStruct - a pointer to a PLUG_INITSTRUCT structure
;
; Notes:     you must fill in the pluginVersion, sdkVersion and pluginName members. 
;            The pluginHandle is obtained from the same structure - it may be needed in
;            other function calls.
;
;            you can call your own setup routine from within this function to setup 
;            menus and commands, and pass the initStruct parameter to this function.
;
;-------------------------------------------------------------------------------------
pluginit PROC C PUBLIC USES EBX initStruct:DWORD
    mov ebx, initStruct

    ; Fill in required information of initStruct, which is a pointer to a PLUG_INITSTRUCT structure
    mov eax, PLUGIN_VERSION
    mov [ebx].PLUG_INITSTRUCT.pluginVersion, eax
    mov eax, PLUG_SDKVERSION
    mov [ebx].PLUG_INITSTRUCT.sdkVersion, eax
    Invoke lstrcpy, Addr [ebx].PLUG_INITSTRUCT.pluginName, Addr PLUGIN_NAME
    
    mov ebx, initStruct
    mov eax, [ebx].PLUG_INITSTRUCT.pluginHandle
    mov pluginHandle, eax
    
    ; Do any other initialization here

	mov eax, TRUE
	ret
pluginit endp


;=====================================================================================
; plugstop - Called by debugger when the plugin.dp32 is unloaded - needs to be EXPORTED
;
; Arguments: none
; 
; Notes:     perform cleanup operations here, clearing menus and other housekeeping
;
;-------------------------------------------------------------------------------------
plugstop PROC C PUBLIC 
    
    ; remove any menus, unregister any callbacks etc
    Invoke testStop
    
    mov eax, TRUE
    ret
plugstop endp



;=====================================================================================
; plugsetup - Called by debugger to initialize your plugins setup - needs to be EXPORTED
;
; Arguments: setupStruct - a pointer to a PLUG_SETUPSTRUCT structure
; 
; Notes:     setupStruct contains useful handles for use within x64_dbg, mainly Qt 
;            menu handles (which are not supported with win32 api) and the main window
;            handle with this information you can add your own menus and menu items 
;            to an existing menu, or one of the predefined supported right click 
;            context menus: hMenuDisam, hMenuDump & hMenuStack
;
;-------------------------------------------------------------------------------------
plugsetup PROC C PUBLIC USES EBX setupStruct:DWORD
    mov ebx, setupStruct

    ; Extract handles from setupStruct which is a pointer to a PLUG_SETUPSTRUCT structure  
    mov eax, [ebx].PLUG_SETUPSTRUCT.hwndDlg
    mov hwndDlg, eax
    mov eax, [ebx].PLUG_SETUPSTRUCT.hMenu
    mov hMenu, eax
    mov eax, [ebx].PLUG_SETUPSTRUCT.hMenuDisasm
    mov hMenuDisasm, eax
    mov eax, [ebx].PLUG_SETUPSTRUCT.hMenuDump
    mov hMenuDump, eax
    mov eax, [ebx].PLUG_SETUPSTRUCT.hMenuStack
    mov hMenuStack, eax
    
    ; Do any setup here: add menus, menu items, callback and commands etc
    Invoke testSetup

    ret
plugsetup endp


;=====================================================================================
; CBMENUENTRY - Called by debugger when a menu item is clicked - needs to be EXPORTED
;
; Arguments: cbType
;            cbInfo - a pointer to a PLUG_CB_MENUENTRY structure. The hEntry contains 
;            the resource id of menu item identifiers
;  
; Notes:     hEntry can be used to determine if the user has clicked on your plugins
;            menu item(s) and to do something in response to it.
;            Needs to be PROC C type procedure call to be compatible with debugger
;-------------------------------------------------------------------------------------
CBMENUENTRY PROC C PUBLIC USES EBX cbType:DWORD, cbInfo:DWORD
    mov ebx, cbInfo
    mov eax, [ebx].PLUG_CB_MENUENTRY.hEntry
    
    .IF eax == MENU_TEST1 ; on the main plugin's sub menu
        Invoke MessageBox, 0, Addr szPluginLoaded, Addr szStatusMsg, MB_OK
    
    .ELSEIF eax == MENU_OPENDIALOG ; on the main plugin's sub menu
        Invoke DialogBoxParam, hInstance, IDD_PluginDlg, hwndDlg, OFFSET testPluginDlgProc, NULL
    
    .ELSEIF eax == MENU_TEST3 ; on the main plugin's sub menu
        Invoke DbgIsDebugging
        .IF eax == FALSE
            Invoke GuiAddStatusBarMessage, Addr szDebuggingRequired
            Invoke GuiAddLogMessage, Addr szDebuggingRequired
            ret
        .ELSE
            Invoke GuiAddStatusBarMessage, Addr szDebuggingIsAvailable
            Invoke GuiAddLogMessage, Addr szDebuggingIsAvailable
        .ENDIF
    
    .ELSEIF eax == MENU_DISASM ; on the right click context menu of the cpu window
        Invoke MessageBox, 0, Addr szDisamMsg, Addr szStatusMsg, MB_OK
        
    .ELSEIF eax == MENU_DUMP ; on the right click context menu of the ascii hex view window
        Invoke testDisasm
    
    .ELSEIF eax == MENU_STACK ; on the right click context menu of the stack window
        Invoke MessageBox, 0, Addr szStackMsg, Addr szStatusMsg, MB_OK
    
    .ELSEIF eax == MENU_DUMPPROCESS ; on the main plugin's sub menu
        Invoke DbgIsDebugging
        .IF eax == FALSE
            Invoke GuiAddStatusBarMessage, Addr szDebuggingRequired
            Invoke GuiAddLogMessage, Addr szDebuggingRequired
        .ELSE
            Invoke DbgCmdExec, Addr szDumpProcess
        .ENDIF        
    
    .ENDIF
    ret
CBMENUENTRY endp


;=====================================================================================
; Registered custom command - DumpProcess 
;-------------------------------------------------------------------------------------
cbDumpProcessCommand PROC PUBLIC USES EBX argc:DWORD, argv:DWORD
    LOCAL entry:DWORD
    LOCAL base:DWORD
    LOCAL hProcess:DWORD
    LOCAL modname[MAX_MODULE_SIZE]:BYTE
    LOCAL szFileName[MAX_PATH]:BYTE
    LOCAL ext[MAX_PATH]:BYTE
    LOCAL lenModname:DWORD
    LOCAL sSaveFileName:OPENFILENAME
    LOCAL File[MAX_PATH]:BYTE
    
    Invoke RtlZeroMemory, Addr szFileName, SIZEOF szFileName
    Invoke RtlZeroMemory, Addr ext, SIZEOF ext
    Invoke RtlZeroMemory, Addr File, SIZEOF File
    
    .IF argc < 2
        Invoke GetContextData, UE_CIP
    .ELSE
        mov ebx, argv
        add ebx, 4d ; argv +1
        Invoke DbgValFromString, ebx
    .ENDIF
    mov entry, eax
 
    Invoke DbgGetModuleAt, entry, Addr modname
    .IF eax == FALSE
        Invoke GuiAddStatusBarMessage, Addr szErrorDbgGetModuleAt
        ret
    .ENDIF

    Invoke DbgModBaseFromName, Addr modname
    .IF eax == 0
        Invoke GuiAddStatusBarMessage, Addr szErrorDbgModBaseFromName
        ret
    .endif
    mov base, eax
    
    Invoke TitanGetProcessInformation 
    mov eax, [eax].PROCESS_INFORMATION.hProcess
    mov hProcess, eax
    Invoke GetModuleBaseNameA, hProcess, base, Addr modname, MAX_MODULE_SIZE
    .IF eax == FALSE
        Invoke GuiAddStatusBarMessage, Addr szErrorGetModuleBaseNameA
        ret   
    .ENDIF

    ; create dump file name by adding _dump after filename part and before extension part
    Invoke JustFname, Addr modname, Addr szFileName
    Invoke JustExt, Addr modname, Addr ext
    Invoke lstrcat, Addr szFileName, Addr szDump
    Invoke lstrcat, Addr szFileName, Addr ext

    ; Prompt user where to save dump file
    Invoke lstrcpy, Addr File, Addr szFileName ; copy over our _dump file part of filename to buffer for saving filename with GetSaveFileName
    mov sSaveFileName.lStructSize, SIZEOF OPENFILENAME
    lea eax, szFilterString
    mov sSaveFileName.lpstrFilter, eax
    lea eax, File
    mov sSaveFileName.lpstrFile, eax
    mov sSaveFileName.nMaxFile, MAX_PATH
    mov sSaveFileName.Flags, OFN_OVERWRITEPROMPT + OFN_HIDEREADONLY
    lea eax, szDialogTitle
    mov sSaveFileName.lpstrTitle, eax
    mov eax, hwndDlg
    mov sSaveFileName.hwndOwner, eax ; = GuiGetWindowHandle();
    Invoke GetSaveFileName, Addr sSaveFileName
    .IF eax == 0 ; no file name was specified - user clicked cancel
        Invoke GuiAddStatusBarMessage, Addr szErrorGetSaveFileName
        ret
    .ENDIF
    
    ; User clicked ok when saving filename so we are good to go    
    Invoke DumpProcess, hProcess, base, Addr File, entry
    .IF eax == FALSE
        Invoke GuiAddStatusBarMessage, Addr szErrorDumpProcess
    .ELSE
        Invoke GuiAddStatusBarMessage, Addr szSuccessDumpProcess
    .ENDIF
    ret

cbDumpProcessCommand endp



;-------------------------------------------------------------------------------------
; Custom procedure for continuing with the setup of the plugin 
;-------------------------------------------------------------------------------------
testSetup PROC
    Invoke _plugin_menuaddentry, hMenu, MENU_TEST1, Addr szMenuTest1
    Invoke _plugin_menuaddentry, hMenu, MENU_OPENDIALOG, Addr szMenuOpenDialog
    Invoke _plugin_menuaddseparator, hMenu
    Invoke _plugin_menuaddentry, hMenu, MENU_TEST3, Addr szMenuTest3
    
    Invoke _plugin_menuaddentry, hMenuDisasm, MENU_DISASM, Addr szMenuDisasm
    Invoke _plugin_menuaddentry, hMenuDump, MENU_DUMP, Addr szMenuDump
    Invoke _plugin_menuaddentry, hMenuStack, MENU_STACK, Addr szMenuStack

    Invoke _plugin_menuaddentry, hMenu, MENU_DUMPPROCESS, Addr szMenuDumpProcess
    Invoke _plugin_registercommand, pluginHandle, Addr szDumpProcess, Addr cbDumpProcessCommand, TRUE
        
    Invoke GuiAddLogMessage, Addr szPluginLoaded
    
    mov eax, TRUE
    ret
testSetup endp


;-------------------------------------------------------------------------------------
; Custom procedure for cleaning up at the end of the plugin
;-------------------------------------------------------------------------------------
testStop PROC
    Invoke _plugin_menuclear, hMenu
    Invoke _plugin_unregistercommand, pluginHandle, Addr szDumpProcess
    Invoke GuiAddLogMessage, Addr szPluginUnloaded
    ret
testStop endp


;-------------------------------------------------------------------------------------
; Custom procedure - called from right click context menu MENU_DUMP (cpu log screen)
;-------------------------------------------------------------------------------------
testDisasm PROC USES EBX
    LOCAL sel:SELECTIONDATA
    
    Invoke DbgIsDebugging
    .IF eax == FALSE
        Invoke GuiAddStatusBarMessage, Addr szDebuggingRequired
        Invoke GuiAddLogMessage, Addr szDebuggingRequired
        ret
    .ENDIF
    
    Invoke GuiSelectionGet, GUI_DISASSEMBLY, Addr sel
    .IF eax == TRUE
        Invoke DbgGetLabelAt, sel.start, SEG_DEFAULT, Addr lpszLabel
        Invoke GuiAddStatusBarMessage, Addr lpszLabel
    .ENDIF
    ret
testDisasm endp


;-------------------------------------------------------------------------------------
; Test Plugin Dialog Procedure - called from MENU_OPENDIALOG menu item
;-------------------------------------------------------------------------------------
testPluginDlgProc PROC hWin:HWND,iMsg:DWORD,wParam:WPARAM, lParam:LPARAM
    
	mov  eax,iMsg
	.if eax==WM_INITDIALOG
	
	.elseif eax==WM_CLOSE
       	invoke EndDialog,hWin,NULL
	
	.elseif eax==WM_COMMAND
 		mov eax,wParam
		and eax,0FFFFh

	.else
      	mov eax,FALSE
		ret
	.endif
	
	mov  eax,TRUE
	ret

testPluginDlgProc endp


;**************************************************************************
; Just Filename - Strip path name to just filename without extention
;**************************************************************************
JustFname PROC USES ESI EDI szFilePathName:DWORD, szFileName:DWORD
	LOCAL LenFilePathName:DWORD
	LOCAL nPosition:DWORD
	
	Invoke lstrlen, szFilePathName
	mov LenFilePathName, eax
	mov nPosition, eax
	
	.IF LenFilePathName == 0
		mov edi, szFileName
		mov byte ptr [edi], 0
		ret
	.ENDIF
	
	mov esi, szFilePathName
	add esi, eax
	
	mov eax, nPosition
	.WHILE eax != 0
		movzx eax, byte ptr [esi]
		.IF al == '\' || al == ':' || al == '/'
			inc esi
			.BREAK
		.ENDIF
		dec esi
		dec nPosition
		mov eax, nPosition
	.ENDW
	mov edi, szFileName
	mov eax, nPosition
	.WHILE eax != LenFilePathName
		movzx eax, byte ptr [esi]
		.IF al == '.' ; stop here
		    .BREAK
		.ENDIF
		mov byte ptr [edi], al
		inc edi
		inc esi
		inc nPosition
		mov eax, nPosition
	.ENDW
	mov byte ptr [edi], 0h
	ret
JustFname	ENDP


;===============================================================================
; Just Extention - Strip path and filename to just extention
;===============================================================================
JustExt PROC USES ESI EDI szFilePathName:DWORD, szFileExtention:DWORD
	LOCAL LenFilePathName:DWORD
	LOCAL nPosition:DWORD
	
	Invoke lstrlen, szFilePathName
	mov LenFilePathName, eax
	mov nPosition, eax
	
	.IF LenFilePathName == 0
		mov edi, szFileExtention
		mov byte ptr [edi], 0
		ret
	.ENDIF
	
	mov esi, szFilePathName
	add esi, eax
	
	mov eax, nPosition
	.WHILE eax != 0
		movzx eax, byte ptr [esi]
		.IF al == '.'
			inc esi
			.BREAK
		.ENDIF
		dec esi
		dec nPosition
		mov eax, nPosition
		.IF eax == 0 ; not found .
		    mov edi, szFileExtention
		    mov byte ptr [edi], 0		
		    mov eax, FALSE
		    ret
		.ENDIF
	.ENDW
	mov edi, szFileExtention
	mov eax, nPosition
	.WHILE eax != LenFilePathName
		movzx eax, byte ptr [esi]
		mov byte ptr [edi], al
		inc edi
		inc esi
		inc nPosition
		mov eax, nPosition
	.ENDW
	mov byte ptr [edi], 0h ; null out filename
	mov eax, TRUE
	ret
JustExt	ENDP




END DllEntry