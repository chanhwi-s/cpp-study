#include <iostream>

typedef struct Animal{
    char name[30];  // 이름
    int age;        // 나이

    int health;     // 체력
    int food;       // 포만감
    int clean;      // 청결도
} Animal;

typedef struct Bird {
    char name[30];  // 이름
    int age;        // 나이

    int health;     // 체력
    int food;       // 포만감
    int clean;      // 청결도

    int height;
} Bird;

typedef struct Fish {
    char name[30];  // 이름
    int age;        // 나이

    int health;     // 체력
    int food;       // 포만감
    int clean;      // 청결도

    int deep;
} Fish;

void create_animal(Animal *animal){
    std::cout << "name: " ;
    std::cin >> animal->name;

    std::cout << "age: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal *animal){
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal *animal){
    std::cout << animal->name << "'s status" << std::endl;
    std::cout << "체력: " << animal->health << std::endl;
    std::cout << "포만감: " << animal->food << std::endl;
    std::cout << "청결도: " << animal->clean << std::endl;
}

int main(void){
    Animal *list[10];
    int animal_num = 0;

    for(;;){
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기" << std::endl;
        std::cout << "3. 상태 보기" << std::endl;

        int input;
        std::cin >> input;

        switch (input){
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);

                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀까?: ";
                std::cin >> play_with;
                if (play_with < animal_num) play(list[play_with]);
                break;
            case 3:
                std::cout << "누구껄 볼까?: ";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(list[play_with]);
            break;
        }
        for (int i=0; i!=animal_num; i++){
            one_day_pass(list[i]);
        }
    }
    for (int i=0; i!=animal_num; i++){
        delete list[i];
    }
}