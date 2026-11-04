#include <stdio.h>
#include <stdbool.h>

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    } else if (n == 2 || n == 3) {
        return true;
    } else {
        for (long long i = 2; i*i <= n; ++i) {
            if (!(n % i == 0)) {
                return true;
                
            } 
        }
        return false;
    }
}


int main() {
    long long n;
    char c;
    long long savedsmall = 0;
    long long otherone = 0;
    //bool gonethru;
    printf("Give me a number: \n");
    scanf("%lld", &n);
    printf("Give me a search type (g or p): \n");
    while (!(scanf("%c", &c) == 'g') && !(scanf("%c", &c) != 'p')) {
        printf("Give me a valid search type (g or p): \n");
    }
    if (c == 'g') {
        if (n > 2) {
            if (n % 2 == 0) {
                //gonethru = false;
                for (long long i = 1; i <= n; ++i) {
                    for (long long j = 1; j <= n; ++j) {
                        if (isPrime(i) == true && isPrime(j) == true) {
                            if (i + j == n) {
                                if (savedsmall == 0) {
                                    savedsmall = i;
                                    otherone = j;
                                    //gonethru = true;
                                } else if (savedsmall > i) {
                                    savedsmall = i;
                                    otherone = j;
                                    //gonethru = true;
                                } else if (savedsmall > j) {
                                    savedsmall = j;
                                    otherone = i;
                                    //gonethru = true;
                               }
                            }
                        }
                    }    
                //} if (gonethru == true) {
                //} else {
                  //  printf("Couldn't find a correct match\n");
                    }                                   
                printf("%lld = %lld + %lld \n", n, savedsmall, otherone);

            }else{
                printf("Your number is not divisible by 2\n");
            }                        
        
        } else {
            printf("Your number is smaller than 2\n");
            }
    } else if (c == 'p') {
        if (isPrime(n) == true) {
            printf("%lld is a prime number\n", n);
        } else if (isPrime(n) == false) {
            printf("%lld is not a prime number\n", n);
        } else {
            printf("Error\n");
        }
    }
}


 

/* 
Επιληση Πρωτου Αρηθμου (Και κατανοηση απο το παραδειγμα στην python): http://repfiles.kallipos.gr/html_books/3403/main/node20.html
Υπενθυμηση της χρησης του printf (γιατι το ξεχασα): https://stackoverflow.com/questions/16675287/using-printf-on-a-variable-in-c
Τροπος εξοδου απο ενα function (Δεν χρησημοποιηθηκε): https://www.geeksforgeeks.org/c/c-exit-abort-and-assert-functions/
https://stackoverflow.com/questions/8440816/message-warning-implicit-declaration-of-function
*/