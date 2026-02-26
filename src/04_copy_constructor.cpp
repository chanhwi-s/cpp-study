#include <string.h>
#include <iostream>

class Photon_Canon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    public:
    Photon_Canon(int x, int y);
    Photon_Canon(const Photon_Canon& pc);

    void show_status();
};
Photon_Canon::Photon_Canon(const Photon_Canon& pc){
    std::cout << "복삿 생성자 호출" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
Photon_Canon::Photon_Canon(int x, int y){
    std::cout << "생성자 호출!" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void Photon_Canon::show_status(){
    std::cout << "Photon Canon " << std::endl;
    std::cout << "Location: ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}
int main(){
    Photon_Canon pc1(3,3);
    Photon_Canon pc2(pc1);
    Photon_Canon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();

    return 0;
}
