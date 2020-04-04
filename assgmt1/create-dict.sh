#!/bin/bash
g++ createFST.cpp -o createFST
./createFST "$1"
fstcompile --isymbols=isymbols.txt --osymbols=osymbols.txt --keep_isymbols --keep_osymbols fst.txt 
# # fstdraw --isymbols=isymbols.txt --osymbols=osymbols.txt binary.fst binary.dot
# # dot -Tps binary.dot >binary.ps


