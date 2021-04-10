#include "algorithms.h"



//////////////////////////FUERZA BRUTA/////////////////////////////////////////
int FB(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    if(i == tape.size()){   
        if (curRes >= 0){
            return elems;
        }
		return 0;
	} 
	int wi = get<0>(tape[i]);
	int ri = get<1>(tape[i]);
    return max(
            FB(tape, curRes, i+1, elems), 
            FB(tape, min(curRes-wi, ri), i+1, elems+1)
        );
 }


//////////////////////////BACKTRACKING////////////////////////////////////////////////
int k = 0;


int BTF(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    if(curRes<0){   
		return 0;
	}
	if(i == tape.size()){ 
    	return elems;
	}else{
		int wi = get<0>(tape[i]);
		int ri = get<1>(tape[i]);
		return max(
                BTF(tape, curRes, i+1, elems), 
                BTF(tape, min(curRes-wi, ri), i+1, elems+1)
            );
	}
}


int BTO(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    if(i == tape.size()){
    	if(curRes>=0){
        	return elems;
    	}
    	return 0;
    } else {
        if (i == 0){
            k = 0;
        }
       
        if(elems>k){
        	k=elems;
        }
        if(elems + (tape.size()-i) < k){
            return 0;
        }
        int wi = get<0>(tape[i]);
		int ri = get<1>(tape[i]);
        return max(
                BTO(tape, curRes, i+1, elems), 
                BTO(tape, min(curRes-wi, ri), i+1, elems+1)
            );
    }
}

int BT(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    
    //Factibilidad
    if(curRes < 0){ 
        return 0;
    }


    if(i == tape.size()){
        return elems;
    } else {
        if (i == 0){
            k = 0;
        }
       
        if(elems>k){
        	k=elems;
        }
        // Optimalidad
        if(elems + (tape.size()-i) < k){
            return 0;
        }
        int wi = get<0>(tape[i]);
		int ri = get<1>(tape[i]);
        return max(BTO(tape, curRes, i+1, elems), BTO(tape, min(curRes-wi, ri), i+1, elems+1));
    }
}


//////////////////////////PROGRAMACION DINAMICA////////////////////////////////////////////////

#define INF -1

int max_elem = 0;
vector<vector<int>> memory;

int _PD(vector<tuple<int, int>>& tape, int curRes, int i, int elems){
    if(curRes < 0){ 
        return 0;
    }
    if(i == tape.size()){
        if(elems>max_elem){
        	max_elem=elems;
        }
        return elems;
    } 
    if(elems + (tape.size()-i) < k){
            return 0;
    }    
    if (memory[i][curRes] == INF){
        int wi = get<0>(tape[i]);
        int ri = get<1>(tape[i]);
        memory[i][curRes] = max(
                                _PD(tape, curRes, i+1, elems), 
                                _PD(tape, min(curRes-wi, ri), i+1, elems+1)
                            );
    }
    
    return memory[i][curRes];
    
}


int PD(vector<tuple<int, int>>& tape, int curRes){
    memory.resize(tape.size(), vector<int> (curRes + 1, INF));
    return _PD(tape, curRes, 0, 0);

}
