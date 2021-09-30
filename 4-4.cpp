#include <iostream>

enum class Seasons {
    JANUARY = 1,
    FEBRUARY,
    MARCH = 3,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main() {
    std::cout << "Input season: 1 for january, ..." << std::endl;
    Seasons season;
    int season_number;
    std::cin >> season_number;
    season = static_cast<Seasons>(season_number);
    switch (season) {
        case Seasons::JANUARY:
            std::cout << 31 << std::endl;
            break;
        case Seasons::APRIL:
            std::cout << 30 << std::endl;
            break;
        case Seasons::AUGUST:
            std::cout << 31 << std::endl;
            break;
        case Seasons::NOVEMBER:
            std::cout << 30 << std::endl;
            break;
        case Seasons::FEBRUARY:
            std::cout << 28 << std::endl;
            break;
        case Seasons::MARCH:
            std::cout << 31 << std::endl;
            break;
        case Seasons::MAY:
            std::cout << 31 << std::endl;
            break;
        case Seasons::JUNE:
            std::cout << 30 << std::endl;
            break;
        case Seasons::JULY:
            std::cout << 31 << std::endl;
            break;
        case Seasons::SEPTEMBER:
            std::cout << 30 << std::endl;
            break;
        case Seasons::OCTOBER:
            std::cout << 31 << std::endl;
            break;
        case Seasons::DECEMBER:
            std::cout << 31 << std::endl;
            break;
        default:
            std::cout << "Unknown month!" << std::endl;
    }
}
