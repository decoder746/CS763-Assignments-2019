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
  int ip=1;
  ifstream input(argv[1]);
  ofstream fst("fstletrev.txt");
  if (input.is_open())
  {
    while ( getline (input,line))
    {
    	vector<string> split = splitstring(line);
    	string x = split[0];
      reverse(split[0].begin(),split[0].end());
    	string fl = "0 " + to_string(state+1)+" "+x+" "+split[0][0]+"\n";state++;
    	fst<<fl;
    	for(int i=0;i<split[0].length()-1;i++){
    		string fl = to_string(state)+" "+to_string(state+1)+" <eps1> "+split[0][i+1]+"\n";
    		state++;
    		fst<<fl;
    	}
    	fl = to_string(state)+"\n";
    	fst<<fl;
    }

    input.close();
  }


  else cout << "Unable to open file"; 
  fst.close();

  return 0;
}
