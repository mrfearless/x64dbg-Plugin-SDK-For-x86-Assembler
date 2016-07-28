;--------------------------------------------------------------------------------------------------------
; x64dbg plugin SDK for Masm32 - fearless 2016 - www.LetTheLight.in
;
; v1.0.0.2 - Last updated: 01/03/2016 
;
; Supports 32bit x32dbg only.
;
; The x64dbg plugin SDK for JWasm64 can be downloaded from here:
; https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-JWasm64/overview
;
; Provided for ease of use in including the required lib and inc files used with the x64dbg plugin SDK 
;
; x64dbg website    : http://x64dbg.com
; x64dbg source     : https://github.com/x64dbg/x64dbg
; x64dbg testplugin : https://github.com/x64dbg/testplugin
;
; The most upto date x32dbg.lib, x32bridge.lib and corresponding .dll's can be found in the x64dbg source
; and/or from the latest snapshots downloadable from: http://sourceforge.net/projects/x64dbg
;
;--------------------------------------------------------------------------------------------------------

include windows.inc           ; Windows include file for MASM32

include user32.inc
include gdi32.inc
include kernel32.inc
include comdlg32.inc
include psapi.inc             ; MS Process Status include for psapi.dll exports.
include x32dbg.inc            ; Plugin SDK include for x32dbg.dll exports, constants and structures.
include x32bridge.inc         ; Plugin SDK include for x32bridge.dll exports, constants and structures.
include dbghelp_x86.inc       ; MS Debugging Tools include for dbghelp.dll exports, constants and structures.
include TitanEngine_x86.inc   ; Plugin SDK include for TitanEngine.dll exports, constants and structures.

includelib user32.lib
includelib gdi32.lib
includelib kernel32.lib
includelib comdlg32.lib
includelib psapi.lib          ; MS Process Status library for psapi.dll
includelib x32dbg.lib         ; Plugin SDK library for x32dbg.dll
includelib x32bridge.lib      ; Plugin SDK library for x32bridge.dll
includelib dbghelp_x86.lib    ; MS Debugging Tools library for dbghelp.dll
includelib TitanEngine_x86.lib; Plugin SDK library for TitanEngine.dll

