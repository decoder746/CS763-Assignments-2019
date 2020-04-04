#!/bin/bash
if [ "$3" = "0" ]; then
	{
		g++ acctor.cpp -o acctor
		./acctor "$2" "$3"
		fstcompile --isymbols=isymbols.txt --acceptor acceptor.txt > I.ofst 
		fstcompose I.ofst "$1" | fstprint --isymbols=isymbols.txt --osymbols=osymbols.txt > out.txt  
		g++ modifier.cpp -o modifier
		./modifier out.txt "$3"
	}
	# } || {
	# 	# python isAccepted.py isymbols.txt osymbols.txt fst.txt "$2" out.txt
	# 	g++ modifier1.cpp -o modifier1
	# 	./modifier out.txt "$3"
	# }

else
	{
		g++ acctor.cpp -o acctor
		./acctor "$2" "$3"
		fstcompile --isymbols=osymbolslet.txt --acceptor acceptor.txt > I.ofst
		fstcompose I.ofst "$1" | fstprint --isymbols=osymbolslet.txt --osymbols=osymbols.txt > out.txt
		g++ modifier.cpp -o modifier
		./modifier out.txt "$3"
	}
	# } || {
	# 	g++ modifier1.cpp -o modifier1
	# 	./modifier1 out.txt "$3"
	# }
fi