@echo off
call build.bat

echo Test 0
main-seq.exe tests/test0.txt
call compare.bat "0"

echo Test 1
main-seq.exe tests/test1.txt
call compare.bat "1"

echo Test 2
main-seq.exe tests/test2.txt
call compare.bat "2"


