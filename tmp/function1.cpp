#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int car(){
    cout<<"car"<<endl;
    return 0;
}

void Car::nameprint(){
    cout<<name<<endl;
}

void Calculator::Add(double a,double b){
    cout<<a+b<<endl;
    add++;
}
void Calculator::Div(double a,double b){
    cout<<a/b<<endl;
    div++;
}
void Calculator::Min(double a,double b){
    cout<<a-b<<endl;
    min++;
}
void Calculator::ShowOpCount(){
    cout<<"Add : "<<add<<endl<<"Min : "<<min<<endl<<"Div : "<<div<<endl;
}
void Calculator::Init(){
    add = 0;
    min = 0;
    div = 0;
}