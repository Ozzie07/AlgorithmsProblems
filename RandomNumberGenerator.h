#pragma once
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
class RandomNumberGenerator
{

    int entity = 100;
    int Min = 0;
    int Max = 99;
public:
    void Generate() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(Min, Max);

        std::cout << entity << "\n";
        for (size_t i = 0; i < entity; i++)
        {
            std::cout << dis(gen) << " ";
        }
    }

    void Init(int entity_, int min_, int max_)
    {
        entity = entity_;
        Min = min_;
        Max = max_;
    }
};
