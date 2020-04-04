#include<bits/stdc++.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


vector<string> splitstring(string line){
	stringstream ss(line);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);
	return vstrings;
}

// string GetStdoutFromCommand(string cmd) {

//     string data;
//     FILE * stream;
//     const int max_buffer = 256;
//     char buffer[max_buffer];
//     cmd.append(" 2>&1"); // Do we want STDERR?

//     stream = popen(cmd.c_str(), "r");
//     if (stream) {
//         while (!feof(stream))
//             if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
//         pclose(stream);
//     }
//     return data;
// }

int main(int argc, char const *argv[])
{
	string s(argv[1]);
	string dir(argv[2]);
	int count=0;
	int max=0;
	string final;
	for(int i=1;i<s.length();i++){
		string x = s.substr(i);
		cout<<"Trying out the combination " + s.substr(0,i)+" + "+x +"\n";
		reverse(x.begin(),x.end());

		string call1 = "./lookup.sh ./"+dir+"/QPrefix.fst "+s.substr(0,i)+" 1 > out1.txt";
		string call2 = "./lookup.sh ./"+dir+"/QSuffix.fst "+ x + " 1 > out2.txt";
		system(call1.c_str());
		system(call2.c_str());
		ifstream is1("out1.txt");
		ifstream is2("out2.txt");
		string line1,line2;
		if(is1.is_open()){
			getline(is1,line1);
			if(line1=="<OOV>") {cout<<"Gives nothing\n";is1.close();continue;}
			is1.close();
		}
		if(is2.is_open()){
			getline(is2,line2);
			if(line2=="<OOV>") {cout<<"Gives nothing\n";is2.close();continue;}
			is2.close();
		}
		// string line1 = GetStdoutFromCommand(call1); 
		// string line2 = GetStdoutFromCommand(call2);
		// cout<<line1<<"\n"<<line2;
		count+=1;
		reverse(line2.begin(),line2.end());
		string fl = line1+line2;
		cout<<"Gives the pronounciation "+fl+"\n"; 
		if(fl.substr(fl.length()-6)==">1spe<") 
			// cout<<fl.substr(0,fl.length()-6)+"\n";
			fl = fl.substr(0,fl.length()-6);
			if(fl.length()>max){
				max = fl.length();
				final = fl;
			}
		else{
			if(fl.length()>max){
				max=fl.length();
				final=fl;
			}
			// cout<<fl<<"\n";
		}
 	}
 	if(count==0){
 		cout<<"No pronounciations were found for this\n";
 		return 0;
 	}
 	else{
 		cout<<"The final answer is \n"<<final<<"\n";
 	}
	return 0;
}