@echo off
cd src/structs
mkdir target
for /f %%i in ('dir /b /s *.java') do echo %%i >> files.list
javac -d target @files.list
jar -cf ../../lib/structs.jar -C target .
del files.list
rd /s/ q target
