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
  ofstream fst("fstrev.txt");
  if (input.is_open())
  {
    while ( getline (input,line))
    {
    	vector<string> split = splitstring(line);
    	string fl = "0 " + to_string(state+1)+" "+split[0]+" "+split[split.size()-1]+"\n";state++;
    	fst<<fl;
    	for(int i=split.size()-3;i>=0;i--){
    		string fl = to_string(state)+" "+to_string(state+1)+" <eps1> "+split[i+1]+"\n";
    		state++;
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

  return 0;
}
