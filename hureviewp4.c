//Write a generic Riemann sum that computes the integral of 
//a given function from x to y using N intervals, 
//using the trapezoidal method 
//(average the output of f()  at the left and right location of each interval).

/*
The function prototype is 
double rsum(double x, double y, unsigned int N, double (*f)(double));
where f is a function that takes a double and returns a double.
*/

#include<stdio.h>

double rsum(double x, double y, unsigned int N, double (*f)(double)){
    double height = (y-x)/N;
    int i;
    double partial_area;
    double ans;
    for (i=0; i<N; i++){
        partial_area = (f(x) + f(x+height))*height/2;
        ans += partial_area;
        x += height;
    }
    return ans;
};

//dummy function y = x for testing purposes
double f(double x){
    return x*x;
}

//testing purposes
int main(){
    double leftbound = 0;
    double rightbound = 5;
    printf("The Riemann Sum on function y = x where x is from %lf to %lf is:", leftbound, rightbound);
    double ans = rsum(leftbound, rightbound, 5, f);
    printf("%d", ans);
}