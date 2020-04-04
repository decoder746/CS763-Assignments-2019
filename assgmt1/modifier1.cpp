#include<bits/stdc++.h>
#include<fstream>
using namespace std;

vector<string> splitstring(string line){
	stringstream ss(line);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);
	return vstrings;
}

int main(int argc, char const *argv[]){
	ifstream is(argv[1]);
	int count=0;
	int index;
	vector< vector<string> > findpro;
	if(is.is_open()){
		string line;
		while(getline(is,line)){
			
			if(line=="") continue;
			vector<string> s=splitstring(line);
			if(s.size()!=1||s[0]=="<OOV>"){
				findpro.push_back(s);
				if(s[0]=="1") index=count;
			}
			count++;
		}
		if(count==0){
			cout<<"<OOV>\n";
			is.close();
			return 0;
		}
		int maxilen=0;
		string final;
		int ind;
		for(int jk=0;jk<index;jk++){
			ind = jk;
			string pron;
			int lenofpro=0;
			while(ind<findpro.size()){
				pron=pron+findpro[ind][3]+" ";
				ind = stoi(findpro[ind][1])+index-1;
				lenofpro +=1;
			}
			if(lenofpro>=maxilen){
				maxilen=lenofpro;
				final = pron;
			}
		}
		cout<<final;
		cout<<'\n';
	}
	else "Error in opening file";
	is.close();
	return 0;
}
