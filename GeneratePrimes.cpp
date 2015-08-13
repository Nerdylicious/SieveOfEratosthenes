//Purpose: Generate prime numbers up to n
//This implementation uses the Sieve of Eratosthenes
//to generate prime numbers
#include <iostream>
#include <math.h>
using namespace std;

#define N 121

void init_number_markers(bool number_markers[]){
    for(int i = 2; i < (N + 1); i ++){
        number_markers[i] = false;
    }
}

void print_primes(bool number_markers[]){

    cout << "Prime numbers up to " << N << " are:" << endl;
    for(int i = 2; i < (N + 1); i ++){
        if(!number_markers[i]){
            cout << i << " ";
        }
    }
}

void generate_primes(bool number_markers[]){

    for(int i = 2; i < (int)sqrt(N); i ++){
        if(!number_markers[i]){
            for(int j = i; (i * j) < (N + 1); j ++){
                number_markers[i * j] = true;
            }
        }
    }
}

int main(){
    //algorithm has O(n) space complexity
    bool number_markers[N];
    init_number_markers(number_markers);
    generate_primes(number_markers);
    print_primes(number_markers);
    return 0;
}
