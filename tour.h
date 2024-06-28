#pragma once
#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include <string>

class Tour {
private:
    std::string tourName;
    std::string direction;
    double pricePerDay;
    int numberOfDays;
    bool mealIncluded;
    double travelCost;

public:
    Tour();
    Tour(const std::string& name, const std::string& dir, double price, int days, bool meal, double travel);
    Tour(const Tour& other);
    Tour& operator=(const Tour& other);
    ~Tour();

    std::string getTourName() const;
    std::string getDirection() const;
    double getPricePerDay() const;
    int getNumberOfDays() const;
    bool isMealIncluded() const;
    double getTravelCost() const;
};

#endif 
