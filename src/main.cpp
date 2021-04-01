#include "algorithms.cpp"
#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;




int main(int argc, char  *argv[]){
	char *input = argv[1];

	int n;
	int resistance;
	vector<tuple<int, int>> tape;

	ifstream inputFile;
  	inputFile.open(input);

  	inputFile >> n >> resistance;

  	cout << n <<" " << resistance << "\n";

  	for (int i = 0; i < n; i++) {
    	int wi; 
    	int ri;

    	inputFile >> wi >> ri;
    	cout << wi << " " << ri<< "\n";
    	tuple<int,int> wi_ri (wi,ri);

    	tape.push_back(wi_ri);
  }

  int result = FB(tape,resistance,0,0);
  cout <<"\n" << result<<"\n" ;

  int result2 = BTF(tape,resistance,0,0);
  cout <<"\n" << result<<"\n" ;

  int result3 = BTO(tape,resistance,0,0);
  cout <<"\n" << result<<"\n" ;

  int result4 = BT(tape,resistance,0,0);
  cout <<"\n" << result<<"\n" ;



}