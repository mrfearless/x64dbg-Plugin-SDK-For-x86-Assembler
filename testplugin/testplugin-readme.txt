------------------------------------------------------------------------------------------------------------

 x64dbg plugin SDK for Masm - fearless 2016 - www.LetTheLight.in

 Supports 32bit x32dbg only.

 The x64dbg plugin SDK for JWasm64 can be downloaded from here:
 https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-jwasm64

 The x64dbg plugin SDK for Masm can be downloaded from here:
 https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-masm
 
------------------------------------------------------------------------------------------------------------

 About

 x64dbg plugin SDK for Masm

 This is a consolidation and conversion of the original x64dbg plugin SDK files: _plugins.h, _plugin_types.h, 
 bridgemain.h & _exports.h to a format that will work with MASM and other assemblers.

 The files that comprise this version of the x64dbg plugin SDK for Masm are:

 - pluginsdk\x64dbgpluginsdk.inc    Main include for ease of use
 - pluginsdk\x32dbg.inc             x32dbg masm style include converted from x64dbg _plugins.h etc
 - pluginsdk\x32dbg.lib             x32dbg library from the x64dbg source for x32dbg.dll
 - pluginsdk\x32bridge.inc          x32bridge masm style include converted from x64dbg bridgemain.h
 - pluginsdk\x32bridge.lib          x32bridge library from the x64dbg source for x32bridge.dll
 - pluginsdk\dbghelp_x86.inc        dbghelp_x86 masm style include
 - pluginsdk\dbghelp_x86.lib        Library for dbghelp.dll from Microsoft Debugging Tools
 - pluginsdk\TitanEngine_x86.inc    TitanEngine masm style include converted from TitanEngine.h
 - pluginsdk\TitanEngine_x86.lib    TitanEngine library from the x64dbg source for TitanEngine.dll


------------------------------------------------------------------------------------------------------------

 testplugin

 This is a RadASM project to show the basic usage of the x64dbg plugin SDK for Masm32

 The files that comprise this example project are:

 - testplugin.rap                   The main RadASM project file for testplugin
 - testplugin.asm                   Assembler source file
 - testplugin.inc                   Include file
 - testplugin.def                   Definitions file for the dll (dp32) exports
 - testplugin.rc                    Resource file script
 - testplugin.res                   Resource file compiled binary
 - testplugin.xml                   Manifest file
 - testplugin.dlg                   Dialog used in the testplugin example
 - testplugin.dp32                  x32dbg plugin (renamed from .dll to .dp32)
 - testplugin-readme.txt            This readme
 - Res\testpluginDlg.rc             Resource script for dialog used in testplugin
 - Res\testpluginRes.rc             Other resources used in testplugin
 - Res\testpluginVer.rc             Version info to add to .dll (.dp32)


------------------------------------------------------------------------------------------------------------

 Extras

 Extra bits and pieces provided for your convenience:

 - install.bat                      Copies the pluginsdk files to your Masm32 folders (lib, include) 
 - masmApiCall.api                  RadASM Code Completion file for api calls (for x64dbg plugin SDK)
 - masmApiConst.api                 RadASM Code Completion file for constants (for x64dbg plugin SDK)
 - masmApiStruct.api                RadASM Code Completion file for structures (for x64dbg plugin SDK)
 - x64dbgplugin.tpl                 RadASM x32dbg plugin template for easy project creation
 - plugins\AutoCmdLine              RadASM source and compiled AutoCmdLine.dp32 plugin & readme
 - plugins\APISearch                RadASM source and compiled APISearch.dp32 plugin & readme


------------------------------------------------------------------------------------------------------------

 Notes

 For more information on the x64dbg plugin SDK functions and overall usage please read the x64dbg help 
 manual section on plugins found here: http://x64dbg.com/help/index.htm

 - x64dbg website    : http://x64dbg.com
 - x64dbg source     : https://github.com/x64dbg/x64dbg
 - x64dbg downloads  : http://sourceforge.net/projects/x64dbg
 - x64dbg testplugin : https://github.com/x64dbg/testplugin

 The most upto date x32dbg.lib, x32bridge.lib and corresponding .dll's can be found in the x64dbg source

 - RadASM IDE: http://www.oby.ro/rad_asm/
 - Masm32: http://www.masm32.com/masmdl.htm






