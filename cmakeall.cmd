@echo off

set basePath = %~dp0
where "C:\Program Files\CMake\bin\;C:\Program Files (x86)\CMake\bin\;%PATH%:cmake.exe" > tmp
set /P cmake=<tmp
del tmp

cd LearnOpenCV\libraries\Build
"%cmake%" -D CMAKE_GENERATOR_PLATFORM:INTERNAL=Win32 -A Win32 ..\
cd ../../..
echo %~dp0

for /d %%a in (*) do if exist %%a\CMakeLists.txt (
  echo build %%a ...
  if not exist %%a\Build md %%a\Build
  cd %%a\Build
  "%cmake%" -D CMAKE_GENERATOR_PLATFORM:INTERNAL=Win32 -A Win32 ..\
  cd ../..
  echo %~dp0
)

pause