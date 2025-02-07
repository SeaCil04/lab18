#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *a,Rect *b){
    double sw1,sw2;;
    if(a->x + a->w <= b->x or b->x + b->w <= a->x) return 0;
    if(a->y + a->h <= b->y or b->y + b->h <= a->y) return 0;
    
    if(a->x + a->w < b->x + b->w) {
        if(a->x > a->w){
            sw1 = (a->w + a->w) -a->w;
        }else{
            sw1 = (a->x + a->w) - b->x;
        }
    }else{
        if(a->x > b->x){
            sw1 = (b->x + b->w) - a->x; 
        }else{
            sw1 = (b->x + b->w) - b->x;
        }
    }
    if(a->y < b->y){
        if(a->y - a->h > b->y - b->h){
            sw2 = a->y - (a->y - a->h);
        }else{
            sw2 = a->y - (b->y - b->h);
        }
    }else{
        if(a->y - a->h > b->y - b->h){
            sw2 = b->y - (a->y - a->h);
        }else{
            sw2 = b->y - (b->y - b->h);
        }
    }
    return sw1*sw2;

}