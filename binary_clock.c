
#include "raylib.h"
#define CLOCK_IMPLEMENTATION
#include "clock.h"
#define window_height 480
#define window_width 640
#define numcolunm 2
#define numrow 4
#define x1 55
#define x2 55
#define x3 55
#define offset1 120
#define offset2 240
#define coloron  RED
#define coloroff BLUE
static int x=0;   ;
static int y= 0;

int main() {
InitWindow(window_width, window_height, "BINARY CLOCK");



SetTargetFPS(60); 
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
         for (int i = 1; i <= numrow; i++)
{
    for(int j=1;j<=numcolunm;j++){
    y =  i * x1;   
    x=  j *x1;
     int value;
if (j == 1){
    value = hour() / 10;  }
else{
    value = hour() % 10; }  

    int bit_value = 1 << (numrow - i);  
if (value & bit_value) {
    DrawCircle(x, y, 25, coloron);
} else {
    DrawCircle(x, y, 25, coloroff);
}

}}
       for (int i = 1; i <= numrow; i++)
{
    for(int j=1;j<=numcolunm;j++){
    y =  i * x2;   
    x=  j *x2;
     int value;
if (j == 1){
    value = min() / 10;  }
else{
    value = min() % 10; }  

       int bit_value = 1 << (numrow - i); 
if (value & bit_value) {
    DrawCircle(x + offset1, y, 25, coloron);
} else {
    DrawCircle(x + offset1, y, 25, coloroff);
}

}}
       for (int i = 1; i <= numrow; i++)
{
    for(int j=1;j<=numcolunm;j++){
    y =  i * x3;   
    x=   j*x3;
    int value;
if (j == 1){
    value = sec() / 10;  }
else{
    value = sec() % 10; }  

    int bit_value = 1 << (numrow - i);  
if (value & bit_value) {
    DrawCircle(x + offset2, y, 25, coloron);
} else {
    DrawCircle(x + offset2, y, 25, coloroff);
}

}}
 DrawFPS(450, 1); 
        EndDrawing();
    }

    CloseWindow();

    return 0;
}