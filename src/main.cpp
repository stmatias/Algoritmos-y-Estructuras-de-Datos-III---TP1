#include "algorithms.cpp"
#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FUERZA_BRUTA "fb"
#define BACKTRACKING "bt"
#define BACKTRACKING_FACTIBILIDAD "btf"
#define BACKTRACKING_OPTIMALIDAD "bto"
#define PROGRAMACION_DINAMICA "pd"

int main(int argc, char  *argv[]){
	char *input = argv[1];
	string algorithm = argv[2];

	int n;
	int resistance;
	vector<tuple<int, int>> tape;

	ifstream inputFile;
  	inputFile.open(input);

  	inputFile >> n >> resistance;

  	//cout << n <<" " << resistance << "\n";

  	for (int i = 0; i < n; i++) {
    	int wi; 
    	int ri;

    	inputFile >> wi >> ri;
    	//cout << wi << " " << ri<< "\n";
    	tuple<int,int> wi_ri (wi,ri);

    	tape.push_back(wi_ri);
  	}

	if (algorithm == "FB") {
		cout << FB(tape,resistance,0,0) << endl;

	} else if (algorithm == "BT") {
		cout << BT(tape,resistance,0,0) << endl;
	
	} else if (algorithm == "BTF") {
		cout << BTF(tape,resistance,0,0) << endl;
	
	} else if (algorithm == "BTO") {
		cout << BTO(tape,resistance,0,0) << endl;
	
	} else if (algorithm == "PD"){
		cout << PD(tape,resistance) << endl;
	
	}else{
		cout << algorithm << " no es una entrada valida" <<endl;
	}
	
	
/*
  	int result = FB(tape,resistance,0,0);
  	cout <<"\n" << "Fuerza Bruta: " << result<<"\n" ;

  	int result2 = BTF(tape,resistance,0,0);
  	cout <<"\n" << "Backtracking por factibilidad: "<<  result2<<"\n" ;

  	int result3 = BTO(tape,resistance,0,0);
  	cout <<"\n" << "Backtracking por optimalidad: "<< result3<<"\n" ;

  	int result4 = BT(tape,resistance,0,0);
  	cout <<"\n" << "Backtracking: "<< result4<<"\n" ;
*/
}
