#include <iostream>

// 윤년인지 아닌지 판별하는 함수
bool is_leap_year(int year){
    if (year%4==0 && (year%100 != 0 || year%400 == 0)) return true;
    else return false;
}

// 현재 년도 및 달을 이용해서 말일이 몇일인지 반환해주는 함수
int return_max_day(int year, int month){
    if (month == 2){
        if (is_leap_year(year)) return 29;
        else return 28;
    }
    else if(month== 1 || month== 3 || month== 5 || month== 7 || month== 8 || month== 10 || month== 12) return 31;
    else return 30;
}

class Date{
    int year_;
    int month_;
    int day_;

    public:
    void SetDate(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    }
    void AddDay(int inc){
        // 증가분(inc)만큼 바로 일수 증가
        day_+=inc;
        // 증가된 일이 현재 년/월에 해당하는 말일을 초과하면 한달씩 증가하도록 for문을 통해 날짜 보정
        for(;;){
            int max_day = return_max_day(year_, month_);    // 현재 년/월의 말일 계산
            if(day_>max_day){   // 말일 초과시 1달 증가 및 일 보정
                month_++;
                day_-=max_day;
            }                  
            else break;         // 말일 초과 안했다면 이대로 종료

            // 달이 12월 초과했을 시, 1년 증가 및 1월로 설정
            if(month_>12){ 
                year_++;
                month_=1;
            }
        }
    }
    void AddMonth(int inc){
        // 증가분(inc)만큼 바로 달 증가
        month_ += inc;
        // 증가된 달이 12를 넘는다면 연도 보정
        if (month_>12){
            // 24, 36 등과 같이 12로 나누어 떨어지는 경우 0월이 되는것을 방지하기 위해 (month_-1)을 이용해 연/월 보정
            // ex1) 2020년 23월 -> 2020 + (22/12) = 2021년, (22)%12 + 1 = 12월 -> 2021년 11월
            // ex2) 2020년 24월 -> 2020 + (23/12) = 2021년, (23)%12 + 1 = 12월 -> 2021년 12월
            year_ += (month_-1)/12;
            month_ = (month_-1)%12 + 1;
        }

        // 달이 변경됨에 따라 일이 변경된 달의 말일을 초과했을 수 있으므로, 변경된 달의 말일로 보정
        int max_day = return_max_day(year_, month_);
        if(day_>max_day){
            day_=max_day;
        }
    }
    void AddYear(int inc){
        // 증가 전 날짜가 2월 29일 이면서(당연히 윤년이었을 것)
        if(month_==2 && day_==29){
            // 변경 후 년도가 윤년이 아니라면 3월 1일로 변경
            if(!is_leap_year(year_+inc)){
                month_=3;
                day_=1;
            }
        }
        // 증가분(inc)만큼 년도 증가
        year_ += inc;
    }
    void ShowDate(){
        std::cout << year_ << "/" << month_ << "/" << day_ << std::endl;
    }
};

int main(){
    Date date;
    int year, month, day;
    
    for(;;){
        std::cout << "설정 년: ";
        std::cin >> year;
        if(year<0) std::cout << "0 이상의 정수만 가능합니다." << std::endl;
        else break;
    }
    for(;;){
        std::cout << "설정 달: ";
        std::cin >> month;
        if(month<1 || month>12) std::cout << "1 이상 12 이하의 정수만 가능합니다." << std::endl;
        else break;
    }
    for(;;){
        int max_day = return_max_day(year, month);
        std::cout << "설정 일: ";
        std::cin >> day;
        if(day<1 || day>max_day) std::cout << "1 이상 " << max_day <<" 이하의 정수만 가능합니다." << std::endl;
        else break;
    }

    date.SetDate(year, month, day);

    for(;;){
        int mode, inc;
        std::cout << "--- 현재 날짜 ---" << std::endl;
        date.ShowDate();

        std::cout << "1. 일 증가" << std::endl;
        std::cout << "2. 달 증가" << std::endl;
        std::cout << "3. 년 증가" << std::endl;
        std::cout << "4. 종료" << std::endl;
        std::cout << "입력: ";
        std::cin >> mode;

        if (mode==4) break;
        
        for(;;){
            std::cout << "증가할 양: ";
            std::cin >> inc;
            if(inc<0) std::cout << "0 이상의 정수만 가능합니다." << std::endl;
            else break;
        }

        switch (mode){
            case 1:
                date.AddDay(inc);
                break;
            case 2:
                date.AddMonth(inc);
                break;
            case 3:
                date.AddYear(inc);
                break;
            break;
        }
    }
}