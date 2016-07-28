;--------------------------------------------------------------------------------------------------------
; x64dbg plugin SDK for Masm - fearless 2016 - www.LetTheLight.in
;
; v1.0.0.2 - Last updated: 01/03/2016 
;
; Supports 32bit x32dbg only.
;
; Include file for TitanEngine_x86.dll exports, constants and structures.
;
; This is a consolidation and conversion of the original plugin TitanEngine.h file to a format that will
;  work with MASM and other assemblers (possibly).
;
; Where are name of a structure, structure field or other definitions conflict with a masm reserved word
; I have appended a underscore at the end of the item in most cases to work around that issue.
; There are a few exceptions: addr becomes address, end becomes finish, just for clarity.
;
;--------------------------------------------------------------------------------------------------------

; Global.Function.Declaration:
; TitanEngine.Dumper.functions:
DumpProcess                     PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID ImageBase, const char* szDumpFileName, ULONG_PTR EntryPoint);
DumpProcessW                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD; (HANDLE hProcess, LPVOID ImageBase, const wchar_t* szDumpFileName, ULONG_PTR EntryPoint);
DumpProcessEx                   PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID ImageBase, const char* szDumpFileName, ULONG_PTR EntryPoint);
DumpProcessExW                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID ImageBase, const wchar_t* szDumpFileName, ULONG_PTR EntryPoint);
DumpMemory                      PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID MemoryStart, ULONG_PTR MemorySize, const char* szDumpFileName);
DumpMemoryW                     PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID MemoryStart, ULONG_PTR MemorySize, const wchar_t* szDumpFileName);
DumpMemoryEx                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID MemoryStart, ULONG_PTR MemorySize, const char* szDumpFileName);
DumpMemoryExW                   PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID MemoryStart, ULONG_PTR MemorySize, const wchar_t* szDumpFileName);
DumpRegions                     PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const char* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpRegionsW                    PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const wchar_t* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpRegionsEx                   PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const char* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpRegionsExW                  PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const wchar_t* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpModule                      PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID ModuleBase, const char* szDumpFileName);
DumpModuleW                     PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID ModuleBase, const wchar_t* szDumpFileName);
DumpModuleEx                    PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID ModuleBase, const char* szDumpFileName);
DumpModuleExW                   PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID ModuleBase, const wchar_t* szDumpFileName);
PastePEHeader                   PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID ImageBase, const char* szDebuggedFileName);
PastePEHeaderW                  PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID ImageBase, const wchar_t* szDebuggedFileName);
ExtractSection                  PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szDumpFileName, DWORD SectionNumber);
ExtractSectionW                 PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szDumpFileName, DWORD SectionNumber);
ResortFileSections              PROTO C :DWORD ; (const char* szFileName);
ResortFileSectionsW             PROTO C :DWORD ; (const wchar_t* szFileName);
FindOverlay                     PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, LPDWORD OverlayStart, LPDWORD OverlaySize);
FindOverlayW                    PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, LPDWORD OverlayStart, LPDWORD OverlaySize);
ExtractOverlay                  PROTO C :DWORD, :DWORD ; (const char* szFileName, const char* szExtactedFileName);
ExtractOverlayW                 PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szExtactedFileName);
AddOverlay                      PROTO C :DWORD, :DWORD ; (const char* szFileName, const char* szOverlayFileName);
AddOverlayW                     PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szOverlayFileName);
CopyOverlay                     PROTO C :DWORD, :DWORD ; (const char* szInFileName, const char* szOutFileName);
CopyOverlayW                    PROTO C :DWORD, :DWORD ; (const wchar_t* szInFileName, const wchar_t* szOutFileName);
RemoveOverlay                   PROTO C :DWORD ; (const char* szFileName);
RemoveOverlayW                  PROTO C :DWORD ; (const wchar_t* szFileName);
MakeAllSectionsRWE              PROTO C :DWORD ; (const char* szFileName);
MakeAllSectionsRWEW             PROTO C :DWORD ; (const wchar_t* szFileName);
AddNewSectionEx                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szSectionName, DWORD SectionSize, DWORD SectionAttributes, LPVOID SectionContent, DWORD ContentSize);
AddNewSectionExW                PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const char* szSectionName, DWORD SectionSize, DWORD SectionAttributes, LPVOID SectionContent, DWORD ContentSize);
AddNewSection                   PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szSectionName, DWORD SectionSize);
AddNewSectionW                  PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const char* szSectionName, DWORD SectionSize);
ResizeLastSection               PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD NumberOfExpandBytes, bool AlignResizeData);
ResizeLastSectionW              PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD NumberOfExpandBytes, bool AlignResizeData);
SetSharedOverlay                PROTO C :DWORD ; (const char* szFileName);
SetSharedOverlayW               PROTO C :DWORD ; (const wchar_t* szFileName);
GetSharedOverlay                PROTO C
GetSharedOverlayW               PROTO C
DeleteLastSection               PROTO C :DWORD ; (const char* szFileName);
DeleteLastSectionW              PROTO C :DWORD ; (const wchar_t* szFileName);
DeleteLastSectionEx             PROTO C :DWORD, :DWORD ; (const char* szFileName, DWORD NumberOfSections);
DeleteLastSectionExW            PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD NumberOfSections);
GetPE32DataFromMappedFile       PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD WhichSection, DWORD WhichData);
GetPE32Data                     PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD WhichSection, DWORD WhichData);
GetPE32DataW                    PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD WhichSection, DWORD WhichData);
GetPE32DataFromMappedFileEx     PROTO C :DWORD, :DWORD ; (ULONG_PTR FileMapVA, LPVOID DataStorage);
GetPE32DataEx                   PROTO C :DWORD, :DWORD ; (const char* szFileName, LPVOID DataStorage);
GetPE32DataExW                  PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, LPVOID DataStorage);
SetPE32DataForMappedFile        PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD WhichSection, DWORD WhichData, ULONG_PTR NewDataValue);
SetPE32Data                     PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD WhichSection, DWORD WhichData, ULONG_PTR NewDataValue);
SetPE32DataW                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD WhichSection, DWORD WhichData, ULONG_PTR NewDataValue);
SetPE32DataForMappedFileEx      PROTO C :DWORD, :DWORD ; (ULONG_PTR FileMapVA, LPVOID DataStorage);
SetPE32DataEx                   PROTO C :DWORD, :DWORD ; (const char* szFileName, LPVOID DataStorage);
SetPE32DataExW                  PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, LPVOID DataStorage);
GetPE32SectionNumberFromVA      PROTO C :DWORD, :DWORD ; (ULONG_PTR FileMapVA, ULONG_PTR AddressToConvert);
ConvertVAtoFileOffset           PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, ULONG_PTR AddressToConvert, bool ReturnType);
ConvertVAtoFileOffsetEx         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, ULONG_PTR ImageBase, ULONG_PTR AddressToConvert, bool AddressIsRVA, bool ReturnType);
ConvertFileOffsetToVA           PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, ULONG_PTR AddressToConvert, bool ReturnType);
ConvertFileOffsetToVAEx         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, ULONG_PTR ImageBase, ULONG_PTR AddressToConvert, bool ReturnType);
MemoryReadSafe                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead);
MemoryWriteSafe                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten);

; TitanEngine.Realigner.functions:
FixHeaderCheckSum               PROTO C :DWORD ; (const char* szFileName);
FixHeaderCheckSumW              PROTO C :DWORD ; (const wchar_t* szFileName);
RealignPE                       PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, DWORD RealingMode);
RealignPEEx                     PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD RealingFileSize, DWORD ForcedFileAlignment);
RealignPEExW                    PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD RealingFileSize, DWORD ForcedFileAlignment);
WipeSection                     PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, int WipeSectionNumber, bool RemovePhysically);
WipeSectionW                    PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, int WipeSectionNumber, bool RemovePhysically);
IsPE32FileValidEx               PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD CheckDepth, LPVOID FileStatusInfo);
IsPE32FileValidExW              PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD CheckDepth, LPVOID FileStatusInfo);
FixBrokenPE32FileEx             PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, LPVOID FileStatusInfo, LPVOID FileFixInfo);
FixBrokenPE32FileExW            PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, LPVOID FileStatusInfo, LPVOID FileFixInfo);
IsFileDLL                       PROTO C :DWORD, :DWORD ; (const char* szFileName, ULONG_PTR FileMapVA);
IsFileDLLW                      PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, ULONG_PTR FileMapVA);

; TitanEngine.Hider.functions:
GetPEBLocation                  PROTO C :DWORD ; (HANDLE hProcess);
GetPEBLocation64                PROTO C :DWORD ; (HANDLE hProcess);
GetTEBLocation                  PROTO C :DWORD ; (HANDLE hThread);
GetTEBLocation64                PROTO C :DWORD ; (HANDLE hThread);
HideDebugger                    PROTO C :DWORD, :DWORD ; (HANDLE hProcess, DWORD PatchAPILevel);
UnHideDebugger                  PROTO C :DWORD, :DWORD ; (HANDLE hProcess, DWORD PatchAPILevel);

; TitanEngine.Relocater.functions:
RelocaterCleanup                PROTO C
RelocaterInit                   PROTO C :DWORD, :DWORD, :DWORD ; (DWORD MemorySize, ULONG_PTR OldImageBase, ULONG_PTR NewImageBase);
RelocaterAddNewRelocation       PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR RelocateAddress, DWORD RelocateState);
RelocaterEstimatedSize          PROTO C
RelocaterExportRelocation       PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR StorePlace, DWORD StorePlaceRVA, ULONG_PTR FileMapVA);
RelocaterExportRelocationEx     PROTO C :DWORD, :DWORD ; (const char* szFileName, const char* szSectionName);
RelocaterExportRelocationExW    PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, const char* szSectionName);
RelocaterGrabRelocationTable    PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR MemoryStart, DWORD MemorySize);
RelocaterGrabRelocationTableEx  PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR MemoryStart, ULONG_PTR MemorySize, DWORD NtSizeOfImage);
RelocaterMakeSnapshot           PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const char* szSaveFileName, LPVOID MemoryStart, ULONG_PTR MemorySize);
RelocaterMakeSnapshotW          PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const wchar_t* szSaveFileName, LPVOID MemoryStart, ULONG_PTR MemorySize);
RelocaterCompareTwoSnapshots    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR LoadedImageBase, ULONG_PTR NtSizeOfImage, const char* szDumpFile1, const char* szDumpFile2, ULONG_PTR MemStart);
RelocaterCompareTwoSnapshotsW   PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR LoadedImageBase, ULONG_PTR NtSizeOfImage, const wchar_t* szDumpFile1, const wchar_t* szDumpFile2, ULONG_PTR MemStart);
RelocaterChangeFileBase         PROTO C :DWORD, :DWORD ; (const char* szFileName, ULONG_PTR NewImageBase);
RelocaterChangeFileBaseW        PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, ULONG_PTR NewImageBase);
RelocaterRelocateMemoryBlock    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, ULONG_PTR MemoryLocation, void* RelocateMemory, DWORD RelocateMemorySize, ULONG_PTR CurrentLoadedBase, ULONG_PTR RelocateBase);
RelocaterWipeRelocationTable    PROTO C :DWORD ; (const char* szFileName);
RelocaterWipeRelocationTableW   PROTO C :DWORD ; (const wchar_t* szFileName);

; TitanEngine.Resourcer.functions:
ResourcerLoadFileForResourceUse PROTO C :DWORD ; (const char* szFileName);
ResourcerLoadFileForResourceUseW PROTO C :DWORD ; (const wchar_t* szFileName);
ResourcerFreeLoadedFile         PROTO C :DWORD ; (LPVOID LoadedFileBase);
ResourcerExtractResourceFromFileEx PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, const char* szResourceType, const char* szResourceName, const char* szExtractedFileName);
ResourcerExtractResourceFromFile PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szResourceType, const char* szResourceName, const char* szExtractedFileName);
ResourcerExtractResourceFromFileW PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, char* szResourceType, const char* szResourceName, const char* szExtractedFileName);
ResourcerFindResource           PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szResourceType, DWORD ResourceType, const char* szResourceName, DWORD ResourceName, DWORD ResourceLanguage, PULONG_PTR pResourceData, LPDWORD pResourceSize);
ResourcerFindResourceW          PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szResourceType, DWORD ResourceType, const wchar_t* szResourceName, DWORD ResourceName, DWORD ResourceLanguage, PULONG_PTR pResourceData, LPDWORD pResourceSize);
ResourcerFindResourceEx         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, const wchar_t* szResourceType, DWORD ResourceType, const wchar_t* szResourceName, DWORD ResourceName, DWORD ResourceLanguage, PULONG_PTR pResourceData, LPDWORD pResourceSize);
ResourcerEnumerateResource      PROTO C :DWORD, :DWORD ; (const char* szFileName, void* CallBack);
ResourcerEnumerateResourceW     PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, void* CallBack);
ResourcerEnumerateResourceEx    PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, void* CallBack);

; TitanEngine.Threader.functions:
ThreaderImportRunningThreadData PROTO C :DWORD ; (DWORD ProcessId);
ThreaderGetThreadInfo           PROTO C :DWORD, :DWORD ; (HANDLE hThread, DWORD ThreadId);
ThreaderEnumThreadInfo          PROTO C :DWORD ; (void* EnumCallBack);
ThreaderPauseThread             PROTO C :DWORD ; (HANDLE hThread);
ThreaderResumeThread            PROTO C :DWORD ; (HANDLE hThread);
ThreaderTerminateThread         PROTO C :DWORD, :DWORD ; (HANDLE hThread, DWORD ThreadExitCode);
ThreaderPauseAllThreads         PROTO C :DWORD ; (bool LeaveMainRunning);
ThreaderResumeAllThreads        PROTO C :DWORD ; (bool LeaveMainPaused);
ThreaderPauseProcess            PROTO C
ThreaderResumeProcess           PROTO C
ThreaderCreateRemoteThread      PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR ThreadStartAddress, bool AutoCloseTheHandle, LPVOID ThreadPassParameter, LPDWORD ThreadId);
ThreaderInjectAndExecuteCode    PROTO C :DWORD, :DWORD, :DWORD ; (LPVOID InjectCode, DWORD StartDelta, DWORD InjectSize);
ThreaderCreateRemoteThreadEx    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR ThreadStartAddress, bool AutoCloseTheHandle, LPVOID ThreadPassParameter, LPDWORD ThreadId);
ThreaderInjectAndExecuteCodeEx  PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID InjectCode, DWORD StartDelta, DWORD InjectSize);
ThreaderSetCallBackForNextExitThreadEvent PROTO C :DWORD ; (LPVOID exitThreadCallBack);
ThreaderIsThreadStillRunning    PROTO C :DWORD ; (HANDLE hThread);
ThreaderIsThreadActive          PROTO C :DWORD ; (HANDLE hThread);
ThreaderIsAnyThreadActive       PROTO C
ThreaderExecuteOnlyInjectedThreads PROTO C
ThreaderGetOpenHandleForThread  PROTO C :DWORD ; (DWORD ThreadId);
ThreaderIsExceptionInMainThread PROTO C

; TitanEngine.Debugger.functions:
StaticDisassembleEx             PROTO C :DWORD, :DWORD ; (ULONG_PTR DisassmStart, LPVOID DisassmAddress);
StaticDisassemble               PROTO C :DWORD ; (LPVOID DisassmAddress);
DisassembleEx                   PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID DisassmAddress, bool ReturnInstructionType);
;Disassemble                     PROTO C :DWORD ; (LPVOID DisassmAddress);
StaticLengthDisassemble         PROTO C :DWORD ; (LPVOID DisassmAddress);
LengthDisassembleEx             PROTO C :DWORD, :DWORD ; (HANDLE hProcess, LPVOID DisassmAddress);
LengthDisassemble               PROTO C :DWORD ; (LPVOID DisassmAddress);
InitDebug                       PROTO C :DWORD, :DWORD, :DWORD ; (char* szFileName, char* szCommandLine, char* szCurrentFolder);
InitDebugW                      PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder);
InitDebugEx                     PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szCommandLine, const char* szCurrentFolder, LPVOID EntryCallBack);
InitDebugExW                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder, LPVOID EntryCallBack);
InitDLLDebug                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, bool ReserveModuleBase, const char* szCommandLine, const char* szCurrentFolder, LPVOID EntryCallBack);
InitDLLDebugW                   PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, bool ReserveModuleBase, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder, LPVOID EntryCallBack);
StopDebug                       PROTO C
SetBPXOptions                   PROTO C :DWORD ; (long DefaultBreakPointType);
IsBPXEnabled                    PROTO C :DWORD ; (ULONG_PTR bpxAddress);
EnableBPX                       PROTO C :DWORD ; (ULONG_PTR bpxAddress);
DisableBPX                      PROTO C :DWORD ; (ULONG_PTR bpxAddress);
SetBPX                          PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR bpxAddress, DWORD bpxType, LPVOID bpxCallBack);
DeleteBPX                       PROTO C :DWORD ; (ULONG_PTR bpxAddress);
SafeDeleteBPX                   PROTO C :DWORD ; (ULONG_PTR bpxAddress);
SetAPIBreakPoint                PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szDLLName, const char* szAPIName, DWORD bpxType, DWORD bpxPlace, LPVOID bpxCallBack);
DeleteAPIBreakPoint             PROTO C :DWORD, :DWORD, :DWORD ; (const char* szDLLName, const char* szAPIName, DWORD bpxPlace);
SafeDeleteAPIBreakPoint         PROTO C :DWORD, :DWORD, :DWORD ; (const char* szDLLName, const char* szAPIName, DWORD bpxPlace);
SetMemoryBPX                    PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR MemoryStart, SIZE_T SizeOfMemory, LPVOID bpxCallBack);
SetMemoryBPXEx                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR MemoryStart, SIZE_T SizeOfMemory, DWORD BreakPointType, bool RestoreOnHit, LPVOID bpxCallBack);
RemoveMemoryBPX                 PROTO C :DWORD, :DWORD ; (ULONG_PTR MemoryStart, SIZE_T SizeOfMemory);
GetContextFPUDataEx             PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, void* FPUSaveArea);
Getx87FPURegisters              PROTO C :DWORD, :DWORD, :DWORD ; (x87FPURegister_t x87FPURegisters[8], TITAN_ENGINE_CONTEXT_t* titcontext);
GetMMXRegisters                 PROTO C :DWORD, :DWORD ; (uint64_t mmx[8], TITAN_ENGINE_CONTEXT_t* titcontext);
GetFullContextDataEx            PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
SetFullContextDataEx            PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
GetContextDataEx                PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, DWORD IndexOfRegister);
GetContextData                  PROTO C :DWORD ; (DWORD IndexOfRegister);
SetContextFPUDataEx             PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, void* FPUSaveArea);
SetContextDataEx                PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hActiveThread, DWORD IndexOfRegister, ULONG_PTR NewRegisterValue);
SetContextData                  PROTO C :DWORD, :DWORD ; (DWORD IndexOfRegister, ULONG_PTR NewRegisterValue);
GetAVXContext                   PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
SetAVXContext                   PROTO C :DWORD, :DWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
ClearExceptionNumber            PROTO C
CurrentExceptionNumber          PROTO C
MatchPatternEx                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, void* MemoryToCheck, int SizeOfMemoryToCheck, void* PatternToMatch, int SizeOfPatternToMatch, PBYTE WildCard);
MatchPattern                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (void* MemoryToCheck, int SizeOfMemoryToCheck, void* PatternToMatch, int SizeOfPatternToMatch, PBYTE WildCard);
externdef C FindEx             :PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, LPBYTE WildCard);

Find                            PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; Find(LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, LPBYTE WildCard);
FillEx                          PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, PBYTE FillByte);
Fill                            PROTO C :DWORD, :DWORD, :DWORD ; (LPVOID MemoryStart, DWORD MemorySize, PBYTE FillByte);
PatchEx                         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, LPVOID ReplacePattern, DWORD ReplaceSize, bool AppendNOP, bool PrependNOP);
Patch                           PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (LPVOID MemoryStart, DWORD MemorySize, LPVOID ReplacePattern, DWORD ReplaceSize, bool AppendNOP, bool PrependNOP);
ReplaceEx                       PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, DWORD NumberOfRepetitions, LPVOID ReplacePattern, DWORD ReplaceSize, PBYTE WildCard);
Replace                         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, DWORD NumberOfRepetitions, LPVOID ReplacePattern, DWORD ReplaceSize, PBYTE WildCard);
GetDebugData                    PROTO C
GetTerminationData              PROTO C
GetExitCode                     PROTO C
GetDebuggedDLLBaseAddress       PROTO C
GetDebuggedFileBaseAddress      PROTO C
GetRemoteString                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, LPVOID StringAddress, LPVOID StringStorage, int MaximumStringSize);
GetFunctionParameter            PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD FunctionType, DWORD ParameterNumber, DWORD ParameterType);
GetJumpDestinationEx            PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR InstructionAddress, bool JustJumps);
GetJumpDestination              PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR InstructionAddress);
IsJumpGoingToExecuteEx          PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, HANDLE hThread, ULONG_PTR InstructionAddress, ULONG_PTR RegFlags);
IsJumpGoingToExecute            PROTO C
SetCustomHandler                PROTO C :DWORD, :DWORD ; (DWORD ExceptionId, LPVOID CallBack);
ForceClose                      PROTO C
StepInto                        PROTO C :DWORD ; (LPVOID traceCallBack);
StepOver                        PROTO C :DWORD ; (LPVOID traceCallBack);
StepOut                         PROTO C :DWORD, :DWORD ; (LPVOID StepOut, bool StepFinal);
SingleStep                      PROTO C :DWORD, :DWORD ; (DWORD StepCount, LPVOID StepCallBack);
GetUnusedHardwareBreakPointRegister PROTO C :DWORD ; (LPDWORD RegisterIndex);
SetHardwareBreakPointEx         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hActiveThread, ULONG_PTR bpxAddress, DWORD IndexOfRegister, DWORD bpxType, DWORD bpxSize, LPVOID bpxCallBack, LPDWORD IndexOfSelectedRegister);
SetHardwareBreakPoint           PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR bpxAddress, DWORD IndexOfRegister, DWORD bpxType, DWORD bpxSize, LPVOID bpxCallBack);
DeleteHardwareBreakPoint        PROTO C :DWORD ; (DWORD IndexOfRegister);
RemoveAllBreakPoints            PROTO C :DWORD ; (DWORD RemoveOption);
TitanGetProcessInformation      PROTO C ; returns pointer to PROCESS_INFORMATION
TitanGetStartupInformation      PROTO C ; returns pointer to STARTUPINFOW
DebugLoop                       PROTO C
SetDebugLoopTimeOut             PROTO C :DWORD ; (DWORD TimeOut);
SetNextDbgContinueStatus        PROTO C :DWORD ; (DWORD SetDbgCode);
AttachDebugger                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, bool KillOnExit, LPVOID DebugInfo, LPVOID CallBack);
DetachDebugger                  PROTO C :DWORD ; (DWORD ProcessId);
DetachDebuggerEx                PROTO C :DWORD ; (DWORD ProcessId);
DebugLoopEx                     PROTO C :DWORD ; (DWORD TimeOut);
AutoDebugEx                     PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, bool ReserveModuleBase, const char* szCommandLine, const char* szCurrentFolder, DWORD TimeOut, LPVOID EntryCallBack);
AutoDebugExW                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, bool ReserveModuleBase, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder, DWORD TimeOut, LPVOID EntryCallBack);
IsFileBeingDebugged             PROTO C
SetErrorModel                   PROTO C :DWORD ; (bool DisplayErrorMessages);

; TitanEngine.FindOEP.functions:
FindOEPInit                     PROTO C
FindOEPGenerically              PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, LPVOID TraceInitCallBack, LPVOID CallBack);
FindOEPGenericallyW             PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, LPVOID TraceInitCallBack, LPVOID CallBack);

; TitanEngine.Importer.functions:
ImporterAddNewDll               PROTO C :DWORD, :DWORD ; (const char* szDLLName, ULONG_PTR FirstThunk);
ImporterAddNewAPI               PROTO C :DWORD, :DWORD ; (const char* szAPIName, ULONG_PTR ThunkValue);
ImporterAddNewOrdinalAPI        PROTO C :DWORD, :DWORD ; (ULONG_PTR OrdinalNumber, ULONG_PTR ThunkValue);
ImporterGetAddedDllCount        PROTO C
ImporterGetAddedAPICount        PROTO C
ImporterExportIAT               PROTO C :DWORD, :DWORD, :DWORD ; (ULONG_PTR StorePlace, ULONG_PTR FileMapVA, HANDLE hFileMap);
ImporterEstimatedSize           PROTO C
ImporterExportIATEx             PROTO C :DWORD, :DWORD, :DWORD ; (const char* szDumpFileName, const char* szExportFileName, const char* szSectionName);
ImporterExportIATExW            PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szDumpFileName, const wchar_t* szExportFileName, const wchar_t* szSectionName = L".RL!TEv2");
ImporterFindAPIWriteLocation    PROTO C :DWORD ; (const char* szAPIName);
ImporterFindOrdinalAPIWriteLocation PROTO C :DWORD ; (ULONG_PTR OrdinalNumber);
ImporterFindAPIByWriteLocation  PROTO C :DWORD ; (ULONG_PTR APIWriteLocation);
ImporterFindDLLByWriteLocation  PROTO C :DWORD ; (ULONG_PTR APIWriteLocation);
ImporterGetDLLName              PROTO C :DWORD ; (ULONG_PTR APIAddress);
ImporterGetDLLNameW             PROTO C :DWORD ; (ULONG_PTR APIAddress);
ImporterGetAPIName              PROTO C :DWORD ; (ULONG_PTR APIAddress);
ImporterGetAPIOrdinalNumber     PROTO C :DWORD ; (ULONG_PTR APIAddress);
ImporterGetAPINameEx            PROTO C :DWORD, :DWORD ; (ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetRemoteAPIAddress     PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetRemoteAPIAddressEx   PROTO C :DWORD, :DWORD ; (const char* szDLLName, const char* szAPIName);
ImporterGetLocalAPIAddress      PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetDLLNameFromDebugee   PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetDLLNameFromDebugeeW  PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetAPINameFromDebugee   PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetAPIOrdinalNumberFromDebugee      PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetDLLIndexEx           PROTO C :DWORD, :DWORD ; (ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetDLLIndex             PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetRemoteDLLBase        PROTO C :DWORD, :DWORD ; (HANDLE hProcess, HMODULE LocalModuleBase);
ImporterGetRemoteDLLBaseEx      PROTO C :DWORD, :DWORD ; (HANDLE hProcess, const char* szModuleName);
ImporterGetRemoteDLLBaseExW     PROTO C :DWORD, :DWORD ; (HANDLE hProcess, const wchar_t* szModuleName);
ImporterIsForwardedAPI          PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetForwardedAPIName     PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetForwardedDLLName     PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetForwardedDLLIndex    PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetForwardedAPIOrdinalNumber PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetNearestAPIAddress    PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetNearestAPIName       PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterCopyOriginalIAT         PROTO C :DWORD, :DWORD ; (const char* szOriginalFile, const char* szDumpFile);
ImporterCopyOriginalIATW        PROTO C :DWORD, :DWORD ; (const wchar_t* szOriginalFile, const wchar_t* szDumpFile);
ImporterLoadImportTable         PROTO C :DWORD ; (const char* szFileName);
ImporterLoadImportTableW        PROTO C :DWORD ; (const wchar_t* szFileName);
ImporterMoveOriginalIAT         PROTO C :DWORD, :DWORD, :DWORD ; (const char* szOriginalFile, const char* szDumpFile, const char* szSectionName);
ImporterMoveOriginalIATW        PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szOriginalFile, const wchar_t* szDumpFile, const char* szSectionName);
ImporterAutoSearchIAT           PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const char* szFileName, ULONG_PTR SearchStart, LPVOID pIATStart, LPVOID pIATSize);
ImporterAutoSearchIATW          PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessIds, const wchar_t* szFileName, ULONG_PTR SearchStart, LPVOID pIATStart, LPVOID pIATSize);
ImporterAutoSearchIATEx         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, ULONG_PTR ImageBase, ULONG_PTR SearchStart, LPVOID pIATStart, LPVOID pIATSize);
ImporterEnumAddedData           PROTO C :DWORD ; (LPVOID EnumCallBack);
ImporterAutoFixIATEx            PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const char* szDumpedFile, const char* szSectionName, bool DumpRunningProcess, bool RealignFile, ULONG_PTR EntryPointAddress, ULONG_PTR ImageBase, ULONG_PTR SearchStart, bool TryAutoFix, bool FixEliminations, LPVOID UnknownPointerFixCallback);
ImporterAutoFixIATExW           PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const wchar_t* szDumpedFile, const wchar_t* szSectionName, bool DumpRunningProcess, bool RealignFile, ULONG_PTR EntryPointAddress, ULONG_PTR ImageBase, ULONG_PTR SearchStart,  bool TryAutoFix, bool FixEliminations, LPVOID UnknownPointerFixCallback);
ImporterAutoFixIAT              PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const char* szDumpedFile, ULONG_PTR SearchStart);
ImporterAutoFixIATW             PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, const wchar_t* szDumpedFile, ULONG_PTR SearchStart);
ImporterDeleteAPI               PROTO C :DWORD ; (DWORD_PTR apiAddr);

; Global.Engine.Hook.functions:
HooksSafeTransitionEx           PROTO C :DWORD, :DWORD, :DWORD ; (LPVOID HookAddressArray, int NumberOfHooks, bool TransitionStart);
HooksSafeTransition             PROTO C :DWORD, :DWORD ; (LPVOID HookAddress, bool TransitionStart);
HooksIsAddressRedirected        PROTO C :DWORD ; (LPVOID HookAddress);
HooksGetTrampolineAddress       PROTO C :DWORD ; (LPVOID HookAddress);
HooksGetHookEntryDetails        PROTO C :DWORD ; (LPVOID HookAddress);
HooksInsertNewRedirection       PROTO C :DWORD, :DWORD, :DWORD ; (LPVOID HookAddress, LPVOID RedirectTo, int HookType);
HooksInsertNewIATRedirectionEx  PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, ULONG_PTR LoadedModuleBase, const char* szHookFunction, LPVOID RedirectTo);
HooksInsertNewIATRedirection    PROTO C :DWORD, :DWORD, :DWORD ; (const char* szModuleName, const char* szHookFunction, LPVOID RedirectTo);
HooksRemoveRedirection          PROTO C :DWORD, :DWORD ; (LPVOID HookAddress, bool RemoveAll);
HooksRemoveRedirectionsForModule PROTO C :DWORD ; (HMODULE ModuleBase);
HooksRemoveIATRedirection       PROTO C :DWORD, :DWORD, :DWORD ; (const char* szModuleName, const char* szHookFunction, bool RemoveAll);
HooksDisableRedirection         PROTO C :DWORD, :DWORD ; (LPVOID HookAddress, bool DisableAll);
HooksDisableRedirectionsForModule PROTO C :DWORD ; (HMODULE ModuleBase);
HooksDisableIATRedirection      PROTO C :DWORD, :DWORD, :DWORD ; (const char* szModuleName, const char* szHookFunction, bool DisableAll);
HooksEnableRedirection          PROTO C :DWORD, :DWORD ; (LPVOID HookAddress, bool EnableAll);
HooksEnableRedirectionsForModule PROTO C :DWORD ; (HMODULE ModuleBase);
HooksEnableIATRedirection       PROTO C :DWORD, :DWORD, :DWORD ; (const char* szModuleName, const char* szHookFunction, bool EnableAll);
HooksScanModuleMemory           PROTO C :DWORD, :DWORD ; (HMODULE ModuleBase, LPVOID CallBack);
HooksScanEntireProcessMemory    PROTO C :DWORD ; (LPVOID CallBack);
HooksScanEntireProcessMemoryEx  PROTO C

; TitanEngine.Tracer.functions:
TracerInit                      PROTO C
TracerLevel1                    PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace);
HashTracerLevel1                PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace, DWORD InputNumberOfInstructions);
TracerDetectRedirection         PROTO C :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace);
TracerFixKnownRedirection       PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace, DWORD RedirectionId);
TracerFixRedirectionViaModule   PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HMODULE hModuleHandle, HANDLE hProcess, ULONG_PTR AddressToTrace, DWORD IdParameter);
TracerFixRedirectionViaImpRecPlugin PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const char* szPluginName, ULONG_PTR AddressToTrace);

; TitanEngine.Exporter.functions:
ExporterCleanup                 PROTO C
ExporterSetImageBase            PROTO C :DWORD ; (ULONG_PTR ImageBase);
ExporterInit                    PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (DWORD MemorySize, ULONG_PTR ImageBase, DWORD ExportOrdinalBase, const char* szExportModuleName);
ExporterAddNewExport            PROTO C :DWORD, :DWORD ; (const char* szExportName, DWORD ExportRelativeAddress);
ExporterAddNewOrdinalExport     PROTO C :DWORD, :DWORD ; (DWORD OrdinalNumber, DWORD ExportRelativeAddress);
ExporterGetAddedExportCount     PROTO C
ExporterEstimatedSize           PROTO C
ExporterBuildExportTable        PROTO C :DWORD, :DWORD ; (ULONG_PTR StorePlace, ULONG_PTR FileMapVA);
ExporterBuildExportTableEx      PROTO C :DWORD, :DWORD ; (const char* szExportFileName, const char* szSectionName);
ExporterBuildExportTableExW     PROTO C :DWORD, :DWORD ; (const wchar_t* szExportFileName, const char* szSectionName);
ExporterLoadExportTable         PROTO C :DWORD ; (const char* szFileName);
ExporterLoadExportTableW        PROTO C :DWORD ; (const wchar_t* szFileName);

; TitanEngine.Librarian.functions:
LibrarianSetBreakPoint          PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szLibraryName, DWORD bpxType, bool SingleShoot, LPVOID bpxCallBack);
LibrarianRemoveBreakPoint       PROTO C :DWORD, :DWORD ; (const char* szLibraryName, DWORD bpxType);
LibrarianGetLibraryInfo         PROTO C :DWORD ; (const char* szLibraryName);
LibrarianGetLibraryInfoW        PROTO C :DWORD ; (const wchar_t* szLibraryName);
LibrarianGetLibraryInfoEx       PROTO C :DWORD ; (void* BaseOfDll);
LibrarianGetLibraryInfoExW      PROTO C :DWORD ; (void* BaseOfDll);
LibrarianEnumLibraryInfo        PROTO C :DWORD ; (void* EnumCallBack);
LibrarianEnumLibraryInfoW       PROTO C :DWORD ; (void* EnumCallBack);

; TitanEngine.Process.functions:
GetActiveProcessId              PROTO C :DWORD ; (const char* szImageName);
GetActiveProcessIdW             PROTO C :DWORD ; (const wchar_t* szImageName);
EnumProcessesWithLibrary        PROTO C :DWORD, :DWORD ; (const char* szLibraryName, void* EnumFunction);
TitanOpenProcess                PROTO C :DWORD, :DWORD, :DWORD ; (DWORD dwDesiredAccess, bool bInheritHandle, DWORD dwProcessId);

; TitanEngine.TLSFixer.functions:
TLSBreakOnCallBack              PROTO C :DWORD, :DWORD, :DWORD ; (LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks, LPVOID bpxCallBack);
TLSGrabCallBackData             PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, LPVOID ArrayOfCallBacks, LPDWORD NumberOfCallBacks);
TLSGrabCallBackDataW            PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, LPVOID ArrayOfCallBacks, LPDWORD NumberOfCallBacks);
TLSBreakOnCallBackEx            PROTO C :DWORD, :DWORD ; (const char* szFileName, LPVOID bpxCallBack);
TLSBreakOnCallBackExW           PROTO C :DWORD, :DWORD ; (const wchar_t* szFileName, LPVOID bpxCallBack);
TLSRemoveCallback               PROTO C :DWORD ; (const char* szFileName);
TLSRemoveCallbackW              PROTO C :DWORD ; (const wchar_t* szFileName);
TLSRemoveTable                  PROTO C :DWORD ; (const char* szFileName);
TLSRemoveTableW                 PROTO C :DWORD ; (const wchar_t* szFileName);
TLSBackupData                   PROTO C :DWORD ; (const char* szFileName);
TLSBackupDataW                  PROTO C :DWORD ; (const wchar_t* szFileName);
TLSRestoreData                  PROTO C
TLSBuildNewTable                PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, ULONG_PTR StorePlace, ULONG_PTR StorePlaceRVA, LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks);
TLSBuildNewTableEx              PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szSectionName, LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks);
TLSBuildNewTableExW             PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const char* szSectionName, LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks);

; TitanEngine.TranslateName.functions:
TranslateNativeName             PROTO C :DWORD ; (const char* szNativeName);
TranslateNativeNameW            PROTO C :DWORD ; (const wchar_t* szNativeName);

; TitanEngine.Handler.functions:
HandlerGetActiveHandleCount     PROTO C :DWORD ; (DWORD ProcessId);
HandlerIsHandleOpen             PROTO C :DWORD, :DWORD ; (DWORD ProcessId, HANDLE hHandle);
HandlerGetHandleName            PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD ProcessId, HANDLE hHandle, bool TranslateName);
HandlerGetHandleNameW           PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD ProcessId, HANDLE hHandle, bool TranslateName);
HandlerEnumerateOpenHandles     PROTO C :DWORD, :DWORD, :DWORD ; (DWORD ProcessId, LPVOID HandleBuffer, DWORD MaxHandleCount);
HandlerGetHandleDetails         PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD ProcessId, HANDLE hHandle, DWORD InformationReturn);
HandlerCloseRemoteHandle        PROTO C :DWORD, :DWORD ; (HANDLE hProcess, HANDLE hHandle);
HandlerEnumerateLockHandles     PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (char* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated, LPVOID HandleDataBuffer, DWORD MaxHandleCount);
HandlerEnumerateLockHandlesW    PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated, LPVOID HandleDataBuffer, DWORD MaxHandleCount);
HandlerCloseAllLockHandles      PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);
HandlerCloseAllLockHandlesW     PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);
HandlerIsFileLocked             PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);
HandlerIsFileLockedW            PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);

; TitanEngine.Handler[Mutex].functions:
HandlerEnumerateOpenMutexes     PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD ProcessId, LPVOID HandleBuffer, DWORD MaxHandleCount);
HandlerGetOpenMutexHandle       PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD ProcessId, const char* szMutexString);
HandlerGetOpenMutexHandleW      PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, DWORD ProcessId, const wchar_t* szMutexString);
HandlerGetProcessIdWhichCreatedMutex PROTO C :DWORD ; (const char* szMutexString);
HandlerGetProcessIdWhichCreatedMutexW PROTO C :DWORD ; (const wchar_t* szMutexString);

; TitanEngine.Injector.functions:
RemoteLoadLibrary               PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const char* szLibraryFile, bool WaitForThreadExit);
RemoteLoadLibraryW              PROTO C :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, const wchar_t* szLibraryFile, bool WaitForThreadExit);
RemoteFreeLibrary               PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, HMODULE hModule, const char* szLibraryFile, bool WaitForThreadExit);
RemoteFreeLibraryW              PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hProcess, HMODULE hModule, const wchar_t* szLibraryFile, bool WaitForThreadExit);
RemoteExitProcess               PROTO C :DWORD ; (HANDLE hProcess, DWORD ExitCode);

; TitanEngine.StaticUnpacker.functions:
StaticFileLoad                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD DesiredAccess, bool SimulateLoad, LPHANDLE FileHandle, LPDWORD LoadedSize, LPHANDLE FileMap, PULONG_PTR FileMapVA);
StaticFileLoadW                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD DesiredAccess, bool SimulateLoad, LPHANDLE FileHandle, LPDWORD LoadedSize, LPHANDLE FileMap, PULONG_PTR FileMapVA);
StaticFileUnload                PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, bool CommitChanges, HANDLE FileHandle, DWORD LoadedSize, HANDLE FileMap, ULONG_PTR FileMapVA);
StaticFileUnloadW               PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, bool CommitChanges, HANDLE FileHandle, DWORD LoadedSize, HANDLE FileMap, ULONG_PTR FileMapVA);
StaticFileOpen                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, DWORD DesiredAccess, LPHANDLE FileHandle, LPDWORD FileSizeLow, LPDWORD FileSizeHigh);
StaticFileOpenW                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, DWORD DesiredAccess, LPHANDLE FileHandle, LPDWORD FileSizeLow, LPDWORD FileSizeHigh);
StaticFileGetContent            PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE FileHandle, DWORD FilePositionLow, LPDWORD FilePositionHigh, void* Buffer, DWORD Size);
StaticFileClose                 PROTO C :DWORD ; (HANDLE FileHandle);
StaticMemoryDecrypt             PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (LPVOID MemoryStart, DWORD MemorySize, DWORD DecryptionType, DWORD DecryptionKeySize, ULONG_PTR DecryptionKey);
StaticMemoryDecryptEx           PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (LPVOID MemoryStart, DWORD MemorySize, DWORD DecryptionKeySize, void* DecryptionCallBack);
StaticMemoryDecryptSpecial      PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (LPVOID MemoryStart, DWORD MemorySize, DWORD DecryptionKeySize, DWORD SpecDecryptionType, void* DecryptionCallBack);
StaticSectionDecrypt            PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (ULONG_PTR FileMapVA, DWORD SectionNumber, bool SimulateLoad, DWORD DecryptionType, DWORD DecryptionKeySize, ULONG_PTR DecryptionKey);
StaticMemoryDecompress          PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (void* Source, DWORD SourceSize, void* Destination, DWORD DestinationSize, int Algorithm);
StaticRawMemoryCopy             PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hFile, ULONG_PTR FileMapVA, ULONG_PTR VitualAddressToCopy, DWORD Size, bool AddressIsRVA, const char* szDumpFileName);
StaticRawMemoryCopyW            PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hFile, ULONG_PTR FileMapVA, ULONG_PTR VitualAddressToCopy, DWORD Size, bool AddressIsRVA, const wchar_t* szDumpFileName);
StaticRawMemoryCopyEx           PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hFile, DWORD RawAddressToCopy, DWORD Size, const char* szDumpFileName);
StaticRawMemoryCopyExW          PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hFile, DWORD RawAddressToCopy, DWORD Size, const wchar_t* szDumpFileName);
StaticRawMemoryCopyEx64         PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hFile, DWORD64 RawAddressToCopy, DWORD64 Size, const char* szDumpFileName);
StaticRawMemoryCopyEx64W        PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (HANDLE hFile, DWORD64 RawAddressToCopy, DWORD64 Size, const wchar_t* szDumpFileName);
StaticHashMemory                PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (void* MemoryToHash, DWORD SizeOfMemory, void* HashDigest, bool OutputString, int Algorithm);
StaticHashFileW                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, char* HashDigest, bool OutputString, int Algorithm);
StaticHashFile                  PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, char* HashDigest, bool OutputString, int Algorithm);

; TitanEngine.Engine.functions:
EngineUnpackerInitialize        PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szUnpackedFileName, bool DoLogData, bool DoRealignFile, bool DoMoveOverlay, void* EntryCallBack);
EngineUnpackerInitializeW       PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szUnpackedFileName, bool DoLogData, bool DoRealignFile, bool DoMoveOverlay, void* EntryCallBack);
EngineUnpackerSetBreakCondition PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (void* SearchStart, DWORD SearchSize, void* SearchPattern, DWORD PatternSize, DWORD PatternDelta, ULONG_PTR BreakType, bool SingleBreak, DWORD Parameter1, DWORD Parameter2);
EngineUnpackerSetEntryPointAddress PROTO C :DWORD ; (ULONG_PTR UnpackedEntryPointAddress);
EngineUnpackerFinalizeUnpacking PROTO C

; TitanEngine.Engine.functions:
SetEngineVariable               PROTO C :DWORD, :DWORD ; (DWORD VariableId, bool VariableSet);
EngineCreateMissingDependencies  PROTO C :DWORD, :DWORD, :DWORD ; (const char* szFileName, const char* szOutputFolder, bool LogCreatedFiles);
EngineCreateMissingDependenciesW PROTO C :DWORD, :DWORD, :DWORD ; (const wchar_t* szFileName, const wchar_t* szOutputFolder, bool LogCreatedFiles);
EngineFakeMissingDependencies   PROTO C :DWORD ; (HANDLE hProcess);
EngineDeleteCreatedDependencies PROTO C
EngineCreateUnpackerWindow      PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; (const char* WindowUnpackerTitle, const char* WindowUnpackerLongTitle, const char* WindowUnpackerName, const char* WindowUnpackerAuthor, void* StartUnpackingCallBack);
EngineAddUnpackerWindowLogMessage PROTO C :DWORD ; (const char* szLogMessage);
EngineCheckStructAlignment      PROTO C :DWORD, :DWORD ; (DWORD StructureType, ULONG_PTR StructureSize);

; Global.Engine.Extension.Functions:
ExtensionManagerIsPluginLoaded  PROTO C :DWORD ; (const char* szPluginName);
ExtensionManagerIsPluginEnabled PROTO C :DWORD ; (const char* szPluginName);
ExtensionManagerDisableAllPlugins PROTO C
ExtensionManagerDisablePlugin   PROTO C :DWORD ; (const char* szPluginName);
ExtensionManagerEnableAllPlugins PROTO C
ExtensionManagerEnablePlugin    PROTO C :DWORD ; (const char* szPluginName);
ExtensionManagerUnloadAllPlugins PROTO C
ExtensionManagerUnloadPlugin    PROTO C :DWORD ; (const char* szPluginName);
ExtensionManagerGetPluginInfo   PROTO C :DWORD ; (const char* szPluginName);

; Scylla imports
scylla_addImport PROTO C :VARARG
scylla_addModule PROTO C :VARARG
scylla_cutImport PROTO C :VARARG
scylla_dumpProcessA PROTO C :VARARG
scylla_dumpProcess equ <scylla_dumpProcessA>

scylla_dumpProcessW PROTO C :VARARG
scylla_enumImportTree PROTO C :VARARG
scylla_estimatedIATSize PROTO C :VARARG
scylla_findImportNameByWriteLocation PROTO C :VARARG
scylla_findImportWriteLocation PROTO C :VARARG
scylla_findModuleNameByWriteLocation PROTO C :VARARG
scylla_findOrdinalImportWriteLocation PROTO C :VARARG
scylla_fixDump PROTO C :VARARG
scylla_fixMappedDump PROTO C :VARARG
scylla_getImportCount PROTO C :VARARG
scylla_getImports PROTO C :VARARG
scylla_getModuleCount PROTO C :VARARG
scylla_importsValid PROTO C :VARARG
scylla_rebuildFileA PROTO C :VARARG
scylla_rebuildFile equ <scylla_rebuildFileA>

scylla_rebuildFileW PROTO C :VARARG
scylla_searchIAT PROTO C :VARARG


; Global.Constant.Structure.Declaration:
; Engine.External:
IFNDEF TITANENGINE
TITANENGINE                             EQU 1
ENDIF

UE_STRUCT_PE32STRUCT                    EQU 1
UE_STRUCT_PE64STRUCT                    EQU 2
UE_STRUCT_PESTRUCT                      EQU 3
UE_STRUCT_IMPORTENUMDATA                EQU 4
UE_STRUCT_THREAD_ITEM_DATA              EQU 5
UE_STRUCT_LIBRARY_ITEM_DATA             EQU 6
UE_STRUCT_LIBRARY_ITEM_DATAW            EQU 7
UE_STRUCT_PROCESS_ITEM_DATA             EQU 8
UE_STRUCT_HANDLERARRAY                  EQU 9
UE_STRUCT_PLUGININFORMATION             EQU 10
UE_STRUCT_HOOK_ENTRY                    EQU 11
UE_STRUCT_FILE_STATUS_INFO              EQU 12
UE_STRUCT_FILE_FIX_INFO                 EQU 13
UE_STRUCT_X87FPUREGISTER                EQU 14
UE_STRUCT_X87FPU                        EQU 15
UE_STRUCT_TITAN_ENGINE_CONTEXT          EQU 16

UE_ACCESS_READ                          EQU 0
UE_ACCESS_WRITE                         EQU 1
UE_ACCESS_ALL                           EQU 2

UE_HIDE_PEBONLY                         EQU 0
UE_HIDE_BASIC                           EQU 1

UE_PLUGIN_CALL_REASON_PREDEBUG          EQU 1
UE_PLUGIN_CALL_REASON_EXCEPTION         EQU 2
UE_PLUGIN_CALL_REASON_POSTDEBUG         EQU 3
UE_PLUGIN_CALL_REASON_UNHANDLEDEXCEPTION EQU 4

TEE_HOOK_NRM_JUMP                       EQU 1
TEE_HOOK_NRM_CALL                       EQU 3
TEE_HOOK_IAT                            EQU 5

UE_ENGINE_ALOW_MODULE_LOADING           EQU 1
UE_ENGINE_AUTOFIX_FORWARDERS            EQU 2
UE_ENGINE_PASS_ALL_EXCEPTIONS           EQU 3
UE_ENGINE_NO_CONSOLE_WINDOW             EQU 4
UE_ENGINE_BACKUP_FOR_CRITICAL_FUNCTIONS EQU 5
UE_ENGINE_CALL_PLUGIN_CALLBACK          EQU 6
UE_ENGINE_RESET_CUSTOM_HANDLER          EQU 7
UE_ENGINE_CALL_PLUGIN_DEBUG_CALLBACK    EQU 8
UE_ENGINE_SET_DEBUG_PRIVILEGE           EQU 9

UE_OPTION_REMOVEALL                     EQU 1
UE_OPTION_DISABLEALL                    EQU 2
UE_OPTION_REMOVEALLDISABLED             EQU 3
UE_OPTION_REMOVEALLENABLED              EQU 4

UE_STATIC_DECRYPTOR_XOR                 EQU 1
UE_STATIC_DECRYPTOR_SUB                 EQU 2
UE_STATIC_DECRYPTOR_ADD                 EQU 3

UE_STATIC_DECRYPTOR_FOREWARD            EQU 1
UE_STATIC_DECRYPTOR_BACKWARD            EQU 2

UE_STATIC_KEY_SIZE_1                    EQU 1
UE_STATIC_KEY_SIZE_2                    EQU 2
UE_STATIC_KEY_SIZE_4                    EQU 4
UE_STATIC_KEY_SIZE_8                    EQU 8

UE_STATIC_APLIB                         EQU 1
UE_STATIC_APLIB_DEPACK                  EQU 2
UE_STATIC_LZMA                          EQU 3

UE_STATIC_HASH_MD5                      EQU 1
UE_STATIC_HASH_SHA1                     EQU 2
UE_STATIC_HASH_CRC32                    EQU 3

UE_RESOURCE_LANGUAGE_ANY                EQU -1

UE_PE_OFFSET                            EQU 0
UE_IMAGEBASE                            EQU 1
UE_OEP                                  EQU 2
UE_SIZEOFIMAGE                          EQU 3
UE_SIZEOFHEADERS                        EQU 4
UE_SIZEOFOPTIONALHEADER                 EQU 5
UE_SECTIONALIGNMENT                     EQU 6
UE_IMPORTTABLEADDRESS                   EQU 7
UE_IMPORTTABLESIZE                      EQU 8
UE_RESOURCETABLEADDRESS                 EQU 9
UE_RESOURCETABLESIZE                    EQU 10
UE_EXPORTTABLEADDRESS                   EQU 11
UE_EXPORTTABLESIZE                      EQU 12
UE_TLSTABLEADDRESS                      EQU 13
UE_TLSTABLESIZE                         EQU 14
UE_RELOCATIONTABLEADDRESS               EQU 15
UE_RELOCATIONTABLESIZE                  EQU 16
UE_TIMEDATESTAMP                        EQU 17
UE_SECTIONNUMBER                        EQU 18
UE_CHECKSUM                             EQU 19
UE_SUBSYSTEM                            EQU 20
UE_CHARACTERISTICS                      EQU 21
UE_NUMBEROFRVAANDSIZES                  EQU 22
UE_BASEOFCODE                           EQU 23
UE_BASEOFDATA                           EQU 24
;leaving some enum space here for future additions
UE_SECTIONNAME                          EQU 40
UE_SECTIONVIRTUALOFFSET                 EQU 41
UE_SECTIONVIRTUALSIZE                   EQU 42
UE_SECTIONRAWOFFSET                     EQU 43
UE_SECTIONRAWSIZE                       EQU 44
UE_SECTIONFLAGS                         EQU 45

UE_VANOTFOUND                           EQU -2;

UE_CH_BREAKPOINT                        EQU 1
UE_CH_SINGLESTEP                        EQU 2
UE_CH_ACCESSVIOLATION                   EQU 3
UE_CH_ILLEGALINSTRUCTION                EQU 4
UE_CH_NONCONTINUABLEEXCEPTION           EQU 5
UE_CH_ARRAYBOUNDSEXCEPTION              EQU 6
UE_CH_FLOATDENORMALOPERAND              EQU 7
UE_CH_FLOATDEVIDEBYZERO                 EQU 8
UE_CH_INTEGERDEVIDEBYZERO               EQU 9
UE_CH_INTEGEROVERFLOW                   EQU 10
UE_CH_PRIVILEGEDINSTRUCTION             EQU 11
UE_CH_PAGEGUARD                         EQU 12
UE_CH_EVERYTHINGELSE                    EQU 13
UE_CH_CREATETHREAD                      EQU 14
UE_CH_EXITTHREAD                        EQU 15
UE_CH_CREATEPROCESS                     EQU 16
UE_CH_EXITPROCESS                       EQU 17
UE_CH_LOADDLL                           EQU 18
UE_CH_UNLOADDLL                         EQU 19
UE_CH_OUTPUTDEBUGSTRING                 EQU 20
UE_CH_AFTEREXCEPTIONPROCESSING          EQU 21
UE_CH_SYSTEMBREAKPOINT                  EQU 23
UE_CH_UNHANDLEDEXCEPTION                EQU 24
UE_CH_RIPEVENT                          EQU 25
UE_CH_DEBUGEVENT                        EQU 26

UE_OPTION_HANDLER_RETURN_HANDLECOUNT    EQU 1
UE_OPTION_HANDLER_RETURN_ACCESS         EQU 2
UE_OPTION_HANDLER_RETURN_FLAGS          EQU 3
UE_OPTION_HANDLER_RETURN_TYPENAME       EQU 4

UE_BREAKPOINT_INT3                      EQU 1
UE_BREAKPOINT_LONG_INT3                 EQU 2
UE_BREAKPOINT_UD2                       EQU 3

UE_BPXREMOVED                           EQU 0
UE_BPXACTIVE                            EQU 1
UE_BPXINACTIVE                          EQU 2

UE_BREAKPOINT                           EQU 0
UE_SINGLESHOOT                          EQU 1
UE_HARDWARE                             EQU 2
UE_MEMORY                               EQU 3
UE_MEMORY_READ                          EQU 4
UE_MEMORY_WRITE                         EQU 5
UE_MEMORY_EXECUTE                       EQU 6
UE_BREAKPOINT_TYPE_INT3                 EQU 10000000h
UE_BREAKPOINT_TYPE_LONG_INT3            EQU 20000000h
UE_BREAKPOINT_TYPE_UD2                  EQU 30000000h

UE_HARDWARE_EXECUTE                     EQU 4
UE_HARDWARE_WRITE                       EQU 5
UE_HARDWARE_READWRITE                   EQU 6

UE_HARDWARE_SIZE_1                      EQU 7
UE_HARDWARE_SIZE_2                      EQU 8
UE_HARDWARE_SIZE_4                      EQU 9
UE_HARDWARE_SIZE_8                      EQU 10

UE_ON_LIB_LOAD                          EQU 1
UE_ON_LIB_UNLOAD                        EQU 2
UE_ON_LIB_ALL                           EQU 3

UE_APISTART                             EQU 0
UE_APIEND                               EQU 1

UE_PLATFORM_x86                         EQU 1
UE_PLATFORM_x64                         EQU 2
UE_PLATFORM_ALL                         EQU 3

UE_FUNCTION_STDCALL                     EQU 1
UE_FUNCTION_CCALL                       EQU 2
UE_FUNCTION_FASTCALL                    EQU 3
UE_FUNCTION_STDCALL_RET                 EQU 4
UE_FUNCTION_CCALL_RET                   EQU 5
UE_FUNCTION_FASTCALL_RET                EQU 6
UE_FUNCTION_STDCALL_CALL                EQU 7
UE_FUNCTION_CCALL_CALL                  EQU 8
UE_FUNCTION_FASTCALL_CALL               EQU 9
UE_PARAMETER_BYTE                       EQU 0
UE_PARAMETER_WORD                       EQU 1
UE_PARAMETER_DWORD                      EQU 2
UE_PARAMETER_QWORD                      EQU 3
UE_PARAMETER_PTR_BYTE                   EQU 4
UE_PARAMETER_PTR_WORD                   EQU 5
UE_PARAMETER_PTR_DWORD                  EQU 6
UE_PARAMETER_PTR_QWORD                  EQU 7
UE_PARAMETER_STRING                     EQU 8
UE_PARAMETER_UNICODE                    EQU 9

UE_EAX                                  EQU 1
UE_EBX                                  EQU 2
UE_ECX                                  EQU 3
UE_EDX                                  EQU 4
UE_EDI                                  EQU 5
UE_ESI                                  EQU 6
UE_EBP                                  EQU 7
UE_ESP                                  EQU 8
UE_EIP                                  EQU 9
UE_EFLAGS                               EQU 10
UE_DR0                                  EQU 11
UE_DR1                                  EQU 12
UE_DR2                                  EQU 13
UE_DR3                                  EQU 14
UE_DR6                                  EQU 15
UE_DR7                                  EQU 16
UE_RAX                                  EQU 17
UE_RBX                                  EQU 18
UE_RCX                                  EQU 19
UE_RDX                                  EQU 20
UE_RDI                                  EQU 21
UE_RSI                                  EQU 22
UE_RBP                                  EQU 23
UE_RSP                                  EQU 24
UE_RIP                                  EQU 25
UE_RFLAGS                               EQU 26
UE_R8                                   EQU 27
UE_R9                                   EQU 28
UE_R10                                  EQU 29
UE_R11                                  EQU 30
UE_R12                                  EQU 31
UE_R13                                  EQU 32
UE_R14                                  EQU 33
UE_R15                                  EQU 34
UE_CIP                                  EQU 35
UE_CSP                                  EQU 36
IFDEF _WIN64
UE_CFLAGS                               EQU UE_RFLAGS
ELSE
UE_CFLAGS                               EQU UE_EFLAGS
ENDIF
UE_SEG_GS                               EQU 37
UE_SEG_FS                               EQU 38
UE_SEG_ES                               EQU 39
UE_SEG_DS                               EQU 40
UE_SEG_CS                               EQU 41
UE_SEG_SS                               EQU 42
UE_x87_r0                               EQU 43
UE_x87_r1                               EQU 44
UE_x87_r2                               EQU 45
UE_x87_r3                               EQU 46
UE_x87_r4                               EQU 47
UE_x87_r5                               EQU 48
UE_x87_r6                               EQU 49
UE_x87_r7                               EQU 50
UE_X87_STATUSWORD                       EQU 51
UE_X87_CONTROLWORD                      EQU 52
UE_X87_TAGWORD                          EQU 53
UE_MXCSR                                EQU 54
UE_MMX0                                 EQU 55
UE_MMX1                                 EQU 56
UE_MMX2                                 EQU 57
UE_MMX3                                 EQU 58
UE_MMX4                                 EQU 59
UE_MMX5                                 EQU 60
UE_MMX6                                 EQU 61
UE_MMX7                                 EQU 62
UE_XMM0                                 EQU 63
UE_XMM1                                 EQU 64
UE_XMM2                                 EQU 65
UE_XMM3                                 EQU 66
UE_XMM4                                 EQU 67
UE_XMM5                                 EQU 68
UE_XMM6                                 EQU 69
UE_XMM7                                 EQU 70
UE_XMM8                                 EQU 71
UE_XMM9                                 EQU 72
UE_XMM10                                EQU 73
UE_XMM11                                EQU 74
UE_XMM12                                EQU 75
UE_XMM13                                EQU 76
UE_XMM14                                EQU 77
UE_XMM15                                EQU 78
UE_x87_ST0                              EQU 79
UE_x87_ST1                              EQU 80
UE_x87_ST2                              EQU 81
UE_x87_ST3                              EQU 82
UE_x87_ST4                              EQU 83
UE_x87_ST5                              EQU 84
UE_x87_ST6                              EQU 85
UE_x87_ST7                              EQU 86
UE_YMM0                                 EQU 87
UE_YMM1                                 EQU 88
UE_YMM2                                 EQU 89
UE_YMM3                                 EQU 90
UE_YMM4                                 EQU 91
UE_YMM5                                 EQU 92
UE_YMM6                                 EQU 93
UE_YMM7                                 EQU 94
UE_YMM8                                 EQU 95
UE_YMM9                                 EQU 96
UE_YMM10                                EQU 97
UE_YMM11                                EQU 98
UE_YMM12                                EQU 99
UE_YMM13                                EQU 100
UE_YMM14                                EQU 101
UE_YMM15                                EQU 102

IFNDEF CONTEXT_EXTENDED_REGISTERS
CONTEXT_EXTENDED_REGISTERS              EQU 0
ENDIF

TEE_MAXIMUM_HOOK_SIZE                   EQU 14
TEE_MAXIMUM_HOOK_RELOCS                 EQU 7
IFDEF _WIN64
TEE_MAXIMUM_HOOK_INSERT_SIZE            EQU 14
ELSE
TEE_MAXIMUM_HOOK_INSERT_SIZE            EQU 5
ENDIF

UE_DEPTH_SURFACE                        EQU 0
UE_DEPTH_DEEP                           EQU 1

UE_UNPACKER_CONDITION_SEARCH_FROM_EP    EQU 1

UE_UNPACKER_CONDITION_LOADLIBRARY       EQU 1
UE_UNPACKER_CONDITION_GETPROCADDRESS    EQU 2
UE_UNPACKER_CONDITION_ENTRYPOINTBREAK   EQU 3
UE_UNPACKER_CONDITION_RELOCSNAPSHOT1    EQU 4
UE_UNPACKER_CONDITION_RELOCSNAPSHOT2    EQU 5

UE_FIELD_OK                             EQU 0
UE_FIELD_BROKEN_NON_FIXABLE             EQU 1
UE_FIELD_BROKEN_NON_CRITICAL            EQU 2
UE_FIELD_BROKEN_FIXABLE_FOR_STATIC_USE  EQU 3
UE_FIELD_BROKEN_BUT_CAN_BE_EMULATED     EQU 4
UE_FIELD_FIXABLE_NON_CRITICAL           EQU 5
UE_FIELD_FIXABLE_CRITICAL               EQU 6
UE_FIELD_NOT_PRESET                     EQU 7
UE_FIELD_NOT_PRESET_WARNING             EQU 8

UE_RESULT_FILE_OK                       EQU 10
UE_RESULT_FILE_INVALID_BUT_FIXABLE      EQU 11
UE_RESULT_FILE_INVALID_AND_NON_FIXABLE  EQU 12
UE_RESULT_FILE_INVALID_FORMAT           EQU 13
















