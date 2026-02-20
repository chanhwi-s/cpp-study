#include <iostream>

double CalculateSlope(int x1, int y1, int x2, int y2){
    if(x1==x2) return std::numeric_limits<double>::infinity();     // x좌표가 같은 경우 무한대 처리 위함
    else return (y2-y1)/(x2-x1);
}

class Point{
    int x, y;

    public:
    Point(int pos_x, int pos_y){
        x = pos_x;
        y = pos_y;
    }

    int GetX() const{return x;}
    int GetY() const{return y;}
};

class Geometry{
    Point* point_array[100];
    int num_points;

    public:
    Geometry(){
        num_points = 0;
    }

    void AddPoint(const Point &point){
        point_array[num_points++] = new Point(point.GetX(), point.GetY());
    }

    // 모든 점들 간의 거리를 출력하는 함수
    void PrintDistance();
    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력하는 함수
    void PrintNumMeets();
};

void Geometry::PrintDistance(){
    int x1, x2, y1, y2;
    double dist;
    for (int i=0; i<num_points; i++){
        int x1 = point_array[i]->GetX();
        int y1 = point_array[i]->GetY();

        for (int j=i+1; j<num_points; j++){
            int x2 = point_array[j]->GetX();
            int y2 = point_array[j]->GetY();

            dist = std::sqrt(std::pow((x1-x2),2) + std::pow((y1-y2),2));
            std::cout << "from point " << i+1 << " to " << "point " << j+1 << std::endl;
            std::cout << "(" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << "): " << dist << std::endl;
        }
    }
}

void Geometry::PrintNumMeets(){
}

int main(){
    int num, x, y;
    Geometry geometry;

    std::cout << "등록할 점 개수: ";
    std::cin >> num;

    for (int i=0; i<num; i++){
        std::cout << i+1 << "번째 x: ";
        std::cin >> x;
        std::cout << i+1 << "번째 y: ";
        std::cin >> y;
        Point point(x,y);
        geometry.AddPoint(point);
    }

    geometry.PrintDistance();
    geometry.PrintNumMeets();

    return 0;
}