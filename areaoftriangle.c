#include <stdio.h>
#include <math.h>
float perimeter(float a, float b, float c){
    return (a+b+c);
}
float area(float a, float b, float c){
    float s=0.5*(a+b+c);
    float x=s-a;
    float y=s-b;
    float z=s-c;
    float area=sqrt(s*x*y*z);
    return area;
}
int main(){
    printf("Area of triangle is: %f\n",area(2,4,3));
    printf("Perimeter of triangle is: %f\n",perimeter(2,4,3));
    return 0;
}