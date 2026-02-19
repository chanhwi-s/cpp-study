#include <iostream>

class Animal{
    // 멤버 변수 선언
    // 객체 내부에서 보호됨, 외부에서 직접 접근 불가능
    private:
        int food;
        int weight;

    public:
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc){
        food += inc;
        weight += (inc/3);
    }
    void view_stat(){
        std::cout << "이 동물의 food    : " << food << std::endl;
        std::cout << "이 동물의 weight  : " << weight << std::endl;
    }
};

int main(){
    Animal animal;
    animal.set_animal(100,50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}