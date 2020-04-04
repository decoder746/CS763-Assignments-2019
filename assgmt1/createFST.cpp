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
  string line;
  int state=0;
  set<string> op;
  int ip=1;
  ifstream input(argv[1]);
  ofstream fst("fst.txt");
  ofstream is("isymbols.txt");
  ofstream os("osymbols.txt");
  is<<"<eps> 0\n";
  is<<"<eps1> 1\n";
  os<<"<eps> 0\n";
  os<<"<eps1> 1\n";
  if (input.is_open())
  {
    while ( getline (input,line))
    {
    	vector<string> split = splitstring(line);
    	string fl = "0 " + to_string(state+1)+" "+split[0]+" "+split[1]+"\n";state++;
    	string il = split[0]+" "+to_string(ip=ip+1)+"\n";
    	op.insert(split[1]);
    	fst<<fl;is<<il;
    	for(int i=0;i<split.size()-2;i++){
    		string fl = to_string(state)+" "+to_string(state+1)+" <eps1> "+split[i+2]+"\n";
    		state++;
    		op.insert(split[i+2]);
    		fst<<fl;
    	}
      fl=to_string(state)+" "+to_string(state)+" <eps1> <eps1>"+"\n";
      fst<<fl;
    	fl = to_string(state) + "\n";
    	fst<<fl;
    }

    input.close();
  }


  else cout << "Unable to open file"; 
  fst.close();
  is.close();
  int count=2;
  for(auto it = op.begin();it!=op.end();it++){
  	string ol = *it + " " + to_string(count)+"\n";
  	os<<ol;count++;
  }
  os.close();

  return 0;
}
