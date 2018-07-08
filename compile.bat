@echo off
call "win-env.bat"
call %VCVARSALL% x64

set c=0
for /F "tokens=1,2,3" %%A in (.problem-config) do (
  set sourceLoc="%%A" & set heapSize="%%B" & set stackSize="%%C"
  set /a c=!c!+1
  goto out
)
:out

if %heapSize%=="" set heapSize=16777216
if %stackSize%=="" set stackSize=1048576

if not exist _binary/ md _binary
set compilerflags=/Od /Zi /EHsc /Fo_binary/ /Fd_binary/
set linkerflags=/HEAP:%heapSize% /STACK:%stackSize% /OUT:_binary/run.exe
cl %compilerflags% %sourceLoc% /link %linkerflags%