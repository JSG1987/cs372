#include<iostream>
#include "KillerCircle.h"



int main() 
{
    int N, M;

    std::cout << "Enter the number of people (N): ";
    std::cin >> N;

    std::cout << "Enter the number of passes (M): ";
    std::cin >> M;

    KillerCircle<int> circle;
    circle.createCircle(N);
    circle.eliminatePeople(M);

    int winningPosition = circle.getWinningPosition();

    std::cout << "The winning position is: " << winningPosition <<std:: endl;

    return 0;
}
