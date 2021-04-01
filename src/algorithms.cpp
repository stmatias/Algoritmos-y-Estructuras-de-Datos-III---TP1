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
    return max(FB(tape, curRes, i+1, elems), FB(tape, min(curRes-wi, ri), i+1, elems+1));
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
		return max(BTF(tape, curRes, i+1, elems), BTF(tape, min(curRes-wi, ri), i+1, elems+1));
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
            // calculo si agregando los elementos hasta el final superaria mi maximo
            // En caso negativo, significa que no encontrare una solucion mejor a la que ya tengo
            return 0;
        }
        int wi = get<0>(tape[i]);
		int ri = get<1>(tape[i]);
        return max(BTO(tape, curRes, i+1, elems), BTO(tape, min(curRes-wi, ri), i+1, elems+1));
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
            // calculo si agregando los elementos hasta el final superaria mi maximo
            // En caso negativo, significa que no encontrare una solucion mejor a la que ya tengo
            return 0;
        }
        int wi = get<0>(tape[i]);
		int ri = get<1>(tape[i]);
        return max(BTO(tape, curRes, i+1, elems), BTO(tape, min(curRes-wi, ri), i+1, elems+1));
    }
}


