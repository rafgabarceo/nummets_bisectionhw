/*

Bisection algorithm: 

1. Choose initial xl and xu such that f(xl)f(xu) < 0.
2. Find the midpoint as the estimate to the root. (xl+xu)/2
3. Case: 
    If f(x1)f(xm) < 0; xl = xl, xu = xm
    If f(x1)f(xm) > 0; xl = xm; xu = xu
    If f(x1)f(xm) == 0; stop. Xm is root

Initial function: 
    f(x) = x^2 - x - 12

*/
#include <stdio.h>
#include <math.h>
#define IXL -1
#define IXU 10 
#define ERROR 0.002

int main(){
    float currentError = 10; // initial value
    float currentMid = midpoint(IXL, IXU); // initial midpoint 
    float currentxl = IXL;
    float currentxu = IXU;
    int iterations = 0; 
    while(currentError >= ERROR){
        if(iterations != 0){
            currentMid = midpoint(currentxl, currentxu);
        }
        printf("Current iteration: %d", iterations);
        if((currentxl*currentMid) < 0){
            currentxu = currentMid;
        } else if((currentxl*currentMid) > 0){
            currentxl = currentMid;
        } else {
            break;
        }
    }
    return 0; 
}

float eval(int x){
    return (pow(x,2) - x - 12); 
}

float midpoint(int x, int y){
    return ((x + y)/2); 
}