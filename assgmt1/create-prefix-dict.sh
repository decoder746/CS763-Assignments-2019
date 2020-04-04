# g++ createletFSTallfinal.cpp -o createletFSTallfinal
# ./createletFSTallfinal "$1"
# fstcompile --isymbols=isymbolslet.txt --osymbols=osymbolslet.txt --keep_isymbols --keep_osymbols fstlet.txt bin2.fst
# # fstminimize bin2.fst bin2.fst
# fstinvert bin2.fst bin2invert.fst
# g++ createFSTallfinal.cpp -o createFSTallfinal
# ./createFSTallfinal "$1"
# fstcompile --isymbols=isymbols.txt --osymbols=osymbols.txt --keep_isymbols --keep_osymbols fst.txt binary.fst
# fstcompose bin2invert.fst binary.fst 
# fstdeterminize out.fst out.fst
# fstminimize out.fst out.fst
# fstrmepsilon out.fst out.fst
# fstdraw --isymbols=osymbolslet.txt --osymbols=osymbols.txt out.fst binary.dot
# dot -Tps binary.dot >binary.ps

fstprint "$1" > out.txt
g++ createallfinal.cpp -o createallfinal
./createallfinal out.txt
fstcompile --isymbols=osymbolslet.txt --osymbols=osymbols.txt fst1.txt 
