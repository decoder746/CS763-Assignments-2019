g++ createletFST.cpp -o createletFST
./createletFST "$1"
fstcompile --isymbols=isymbolslet.txt --osymbols=osymbolslet.txt --keep_isymbols --keep_osymbols fstlet.txt bin2.fst
# fstminimize bin2.fst bin2.fst
fstinvert bin2.fst bin2invert.fst
fstcompose bin2invert.fst "$2"
# fstinfo m.fst 
# fstinfo bin2.fst 
# fstinfo "$2"
# fstdeterminize out.fst out.fst
# fstminimize out.fst out.fst
# fstrmepsilon out.fst out.fst
# fstdraw m.fst binary.dot
# dot -Tps binary.dot >binary.ps
