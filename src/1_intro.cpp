#include <iostream>

int main(){
    /*
    std::cout << "Hello World!" << std::endl;

    std::cout << "hello channie" << std::endl;

    std::cout << "hi" << std::endl
    << "my name is "
    << "Psi" << std::endl;

    return 0;
    */

    int lucky_number = 3;
   
    std::cout << "choose the lucky number " << std::endl;

    int user_input;

    while(1){
        std::cout << "input: ";
        std::cin >> user_input;
        if(lucky_number ==  user_input){
            std::cout<<"correct!"<<std::endl;
            break;
        }
        else{
            std::cout<<"false"<<std::endl;
        }
    }
    return 0;
}
