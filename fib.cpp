#include <iostream>
#include <stdio.h>


int main(){
    int up_to;
    printf("enter num");
    std::cin >> up_to;

    int fib1 = 0;
    int fib2 = 1;
    int f;
    printf("%d", fib1);

    for (int i = 0; i<=up_to; i++){
        printf("%d ", fib2);

        f = fib1;
        fib1 = fib2;
        fib2 += f;


    }
    return 0;

}
