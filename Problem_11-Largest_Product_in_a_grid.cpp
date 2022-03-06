#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int main() {
	string numbers = "08022297381500400075040507785212507791084949994017811857608717409843694804566200814931735579142993714067538830034913366552709523046011426924685601325671370236912231167151676389419236542240402866331380244732609903450244753353783684203517125032988128642367102638406759547066183864706726206802621220956394396308409166499421245558056673992697177878968314883489637221362309750076442045351400613397343133957817532822753167159403800462161409535692163905429635314755588824001754243629855786560048357189070544443744602158515417581980816805944769287392138652177704895540045208839735991607975732162626793327986688366887576220720346336746551232639353690442167338253911249472180846293240627636206936417230238834629969826759857404361620733529783190017431497148868116235705540170547183515469169233486143520189196748";
        
    int product = 1;
    int max = 0;
    for (int b = 0; b<= 32; b+=2){
        for (int a = 38-b; a<=678; a += 40){
            product = 1;
            for (int i = 0; i<=3; i++) product *= (numbers[a + i*38] - 48) * 10 + numbers[a+1 + i*38] - 48;
            if (product > max) max = product;
        }
    }
    cout << "The max right-to-left diagonally is " << max  << "." << endl;


    
    product = 1;
    max = 0;
    for (int b = 0; b<= 32; b+=2){
        for (int a = b; a<= 640+b; a+=40){
            product = 1;
            for (int i = 0; i<=3; i++) product *= (numbers[a + i*42] - 48) * 10 + numbers[a+1 + i*42] - 48;
            if (product > max) max = product;
       }
    }
    cout << "The max left-to-right diagonally is " << max << "." << endl;
   
    
    
    
    int a, i, j;
    max = 1;
    for (a = 0; a <= 39; a+=2){
        for (i = 0+a; i<=16*40+a; i+=40){
            product = 1;
            for (j = 0; j<=3; j++) product *= (numbers[i+j*40]-48)*10 + numbers[i+j*40+1]-48;
            if (product>max) max = product;
        }
    }
    cout << "The max left/right is " << max  << "." << endl;
    
    
    
    max = 1;
    for (a = 0; a<=19; a++){
        for (i = a*40; i <= 33+(a*40); i+=2) {
            product = 1;
            for (j = 0; j <= 6; j+=2) product *= (numbers[i + j] - 48) * 10 + (numbers[i + 1 + j]) - 48;
            if (product > max) max = product;
        }
    }
    cout << "The max up/down is " << max << "." << endl << endl;
}
