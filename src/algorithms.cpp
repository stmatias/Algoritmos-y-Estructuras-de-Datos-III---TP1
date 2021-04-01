#include <tuple>
#include <vector>
using namespace std;


//////////////////////////FUERZA BRUTA/////////////////////////////////////////
int FB(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    if(i == tape.size()){   
        if (curRes < 0){
            return 0;
        }
		return elems;
	} else {
        return max(FB(tape, min(curRes-get<0>(tape[i]), get<1>(tape[i])), i+1, elems+1),
                   FB(tape, curRes, i+1, elems));
    }
}

