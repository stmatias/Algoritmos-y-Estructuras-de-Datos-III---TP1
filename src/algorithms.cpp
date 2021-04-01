#include <tuple>
#include <vector>
using namespace std;


//////////////////////////FUERZA BRUTA/////////////////////////////////////////
int FB(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    if(i == tape.size()){   
        if (curRes >= 0){
            return elems;
        }
		return 0;
	} 
	int wi = get<0>(tape[i]);
	int gi = get<1>(tape[i]);
    return max(FB(tape, curRes, i+1, elems), FB(tape, min(curRes- wi, gi), i+1, elems+1));
    
}

