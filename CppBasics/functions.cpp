#include <iostream>

int sum (int a, int b){
    return a+b;
}
double sum(double a, double b){
    return a+b;
}

template <class T>
T sumTemplate(T a, T b){
    return a+b;
}



int main(){
    //overloaded function
    std::cout << "3 + 11 is: " << sum(3,11) << std::endl;
    std::cout << "3.5 + 7.33 is: " << sum(3.5,7.33) << std::endl;

    //pointer to function
    int (*ptr)(int, int) = sum;
    std::cout << ptr(2,1) << std::endl;

    //template function
    std::cout << "21474836471 + 21474836471 is: " << sumTemplate(21474836471, 21474836471) << std::endl;
    std::cout << "3.52313 + 7.333213213 is: " << sumTemplate(3.52313, 7.333213213) << std::endl;

    //lambda
    std::cout << "Lambda divide: 4 / 2 is: " << [](int a, int b){return a/b;}(4,2) << std::endl;
    return 0;
}