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

echo Test 3
main-seq.exe tests/test2.txt
call compare.bat "3"

echo Test parallel 0
main-parallel.exe tests/test0.txt
call compare.bat "0"

echo Test parallel 1
main-parallel.exe tests/test1.txt
call compare.bat "1"

echo Test parallel 2
main-parallel.exe tests/test2.txt
call compare.bat "2"

echo Test parallel 3
main-parallel.exe tests/test2.txt
call compare.bat "3"

