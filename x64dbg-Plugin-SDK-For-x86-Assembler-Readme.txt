x64dbg Plugin SDK For x86 Assembler - https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x86-Assembler

fearless 2017 - www.LetTheLight.in


Overview
--------

This is a consolidation and conversion of the original x64dbg plugin SDK files: _plugins.h, _plugin_types.h, bridgemain.h & _exports.h to a format that will work with MASM and other assemblers. Currently this package only supports 32bit x64dbg (x32dbg).

For 64bit support use the x64dbg Plugin SDK for x64 Assembler found here: https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x64-Assembler


Whats included in this package
------------------------------

 - Masm32 version of the x64dbg plugin SDK found in the pluginsdk folder
 - RadASM testplugin project and files as a working example of how to use the plugin SDK
 - RadASM template for creating your own x32dbg plugins.
 - RadASM Code Completion files for easy use of the x64dbg Plugin SDK For x86 Assembler (Masm)


The files that comprise this version of the x64dbg Plugin SDK For x86 Assembler are

 - pluginsdk\include\x64dbgpluginsdk.inc     Main include file for ease of use - see below on how to use.
 - pluginsdk\include\x32dbg.inc              x32dbg masm style include converted from x64dbg _plugins.h, _plugin_type.h & _exports.h source files
 - pluginsdk\include\x32bridge.inc           x32bridge masm style include converted from x64dbg bridgemain.h source file
 - pluginsdk\include\dbghelp_x86.inc         dbghelp_x86 masm style include
 - pluginsdk\include\TitanEngine_x86.inc     TitanEngine masm style include converted from TitanEngine.h
 - pluginsdk\lib\x32dbg.lib                  x32dbg library from the x64dbg source for x32dbg.dll
 - pluginsdk\lib\x32bridge.lib               x32bridge library from the x64dbg source for x32bridge.dll
 - pluginsdk\lib\dbghelp_x86.lib             dbghelp_x86 library from x64dbg source for dbghelp.dll
 - pluginsdk\lib\TitanEngine_x86.lib         TitanEngine library from the x64dbg source for TitanEngine.dll


The files that are included in the extra's folder are

 - install.bat                               Copies the pluginsdk files to your Masm32 folders (lib, include) 
 - masmApiCall.api                           RadASM Code Completion file for api calls (for x64dbg plugin SDK)
 - masmApiConst.api                          RadASM Code Completion file for constants (for x64dbg plugin SDK)
 - masmApiStruct.api                         RadASM Code Completion file for structures (for x64dbg plugin SDK)
 - x32dbgplugin.tpl                          RadASM 32bit x64dbg plugin template for easy project creation

 
 
How to use
----------

There are a number of ways of using the pluginsdk files in your own projects

 - Copy the x64dbgpluginsdk.inc, x32dbg.inc, x32bridge.inc, debug_x86.inc and TitanEngine_x86.inc files from pluginsdk\include\ folder to your masm32\include folder
 - Copy the x32dbg.lib, x32bridge.lib, debug_x86.lib and TitanEngine_x86.lib files from pluginsdk\lib folder to your masm32\lib folder
 - Add a line in your source code:

    include x64dbgpluginsdk.inc

 - or add the following lines to your source code

    include x32dbg.inc
    include x32bridge.inc
    include debug_x86.inc
    include TitanEngine_x86.inc
    includelib x32dbg.lib
    includelib x32bridge.lib
    includelib debug_x86.lib
    includelib TitanEngine_x86.lib


Alternatively you can use the included template to easily create a x32dbg plugin project ready to use

 - Copy the template\x32dbg_plugin.tpl file to your RadASM\Masm\Templates folder.
 - Open RadASM and choose a new project.
 - Choose the project name and folder.
 - Specify project as a dll (dynamic link library) type .
 - Select 'x32dbg plugin' as the project template to use and allow it to create & setup a ready to run barebones x32dbg plugin.

With any of these options, feel free to add any other includes and libs as you normally would.


Manual compile and link settings
--------------------------------

 - Assemble: \MASM32\BIN\ML.EXE /c /coff /Cp /nologo /I"\Masm32\Include", "MyPlugin.asm"
 - Link:     \MASM32\BIN\LINK.EXE /SUBSYSTEM:WINDOWS /RELEASE /DLL /DEF:"MyPlugin.def" /LIBPATH:"\Masm32\Lib" /OUT:"MyPlugin.dp32", "MyPlugin.obj", "MyPlugin.res"
 - Resource: \MASM32\BIN\RC.EXE /v "MyPlugin.rc"


Notes
-----

For more information on the x64dbg plugin SDK functions and overall usage please read the x64dbg help manual section on plugins found here: http://x64dbg.com/help/index.htm.

Make sure you get the latest versions of the x32dbg.lib, x32bridge.lib files from the x64dbg source. The files provided here may become outdated as changes occur with the development of the x64dbg debugger. I may add changes to the x32dbg.inc and x32bridge.inc to take into account new features and functions in future - but I wont guarantee that I will, you may need to manually update the .inc files yourself and download the newest .lib files if you want this package to stay up to date.

Including a manifest and version info in your plugin .dll (.dp32) may prevent anti-virus false positives. The testplugin has an example of this usage.

 - RadASM IDE: http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml
 - Masm32: http://www.masm32.com/masmdl.htm


x64dbg
------
 - x64dbg website: http://x64dbg.com
 - x64dbg source: https://github.com/x64dbg/x64dbg
 - x64dbg downloads: http://sourceforge.net/projects/x64dbg
 - x64dbg plugin: https://github.com/x64dbg/testplugin
 - Mr. eXoDia: http://mrexodia.cf



