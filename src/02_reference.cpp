#include <iostream>
    
int change_val_with_pointer(int *p){
    *p = 3;
    return 0;
}

int change_val_with_refernce(int &p){
    p = 10;
    return 0;
}

int return_local_variable() {
    int a = 2;
    std::cout << "&a: " << &a << std::endl;

    return a;
}

int main(){
    int number = 5;

    std::cout << "number: " << number << std::endl;
    change_val_with_pointer(&number);   // 포인터에게 주소값 전달
    std::cout << "number: " << number << std::endl;
    change_val_with_refernce(number);   // 참조하도록 값 전달
    std::cout << "number: " << number << std::endl;

    int a = 3;
    int& another_a = a;     // a의 참조자 another_a 선언, 반드시 참조할 값 명시해야함

    another_a = 5;

    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;
    
    std::cout << "&a: " << &a << std::endl;
    std::cout << "&another_a: " << &another_a << std::endl;

    int b = 3;
    another_a = b;          // a에 b를 대입(a=b와 동치), 다른 변수를 참조하도록 수정 불가능

    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;

    
    // 배열의 참조자
    int arr[3] = {1,2,3};
    int(&ref)[3] = arr;

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    
    const int& c = return_local_variable();
    std::cout << "c: " << c << std::endl;
    std::cout << "&c: " << &c << std::endl;

    return 0;
}
