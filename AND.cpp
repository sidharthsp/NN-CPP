#include "neuron.h"
#include<iostream>

int main(){
cout<<" Logic Gate : AND GATE (Testing) \n\n";

Perceptron *p = new Perceptron(2);

p->set_weights({10,10,-15});

cout<< "GATE: " << endl;


cout<<"{0,0} ->  " << round(p->run({0,0}))<<endl;
cout<<"{0,1} ->  " << round(p->run({0,1}))<<endl;
cout<<"{1,0} ->  " << round(p->run({1,0}))<<endl;
cout<<"{1,1} ->  " << round(p->run({1,1}))<<endl;
}