#include <cmath>
#include <iostream>
using namespace std;

int main(){
    
    int conditions = 0;
    
    for (int Onep = 0; Onep<199; Onep++){
        for (int Twop = 0; Twop<100;Twop++){
            for (int Fivep = 0; Fivep<40;Fivep++){
                for (int Tenp = 0; Tenp<20; Tenp++){
                    for (int Twentyp = 0; Twentyp<10; Twentyp++){
                        for (int fiftyp = 0; fiftyp<4; fiftyp++){
                            for (int OneP = 0; OneP<2; OneP++){
                                    if (Onep * 1 + Twop * 2 + Fivep * 5 + Tenp * 10 + Twentyp * 20 + fiftyp * 50 + OneP * 100 == 200) conditions++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Total conditions are: " << conditions + 8 << endl;
    // the +8 is for doing one less operation in each step. This is why Twod is omitted.
}
