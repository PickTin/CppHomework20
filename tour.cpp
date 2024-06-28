#include "tour.h"

Tour::Tour() : tourName(""), direction(""), pricePerDay(0.0), numberOfDays(0), mealIncluded(false), travelCost(0.0) {}

Tour::Tour(const std::string& name, const std::string& dir, double price, int days, bool meal, double travel)
    : tourName(name), direction(dir), pricePerDay(price), numberOfDays(days), mealIncluded(meal), travelCost(travel) {}

Tour::Tour(const Tour& other)
    : tourName(other.tourName), direction(other.direction), pricePerDay(other.pricePerDay),
    numberOfDays(other.numberOfDays), mealIncluded(other.mealIncluded), travelCost(other.travelCost) {}

Tour& Tour::operator=(const Tour& other) {
    if (this != &other) {
        tourName = other.tourName;
        direction = other.direction;
        pricePerDay = other.pricePerDay;
        numberOfDays = other.numberOfDays;
        mealIncluded = other.mealIncluded;
        travelCost = other.travelCost;
    }
    return *this;
}

Tour::~Tour() {}

std::string Tour::getTourName() const {
    return tourName;
}

std::string Tour::getDirection() const {
    return direction;
}

double Tour::getPricePerDay() const {
    return pricePerDay;
}

int Tour::getNumberOfDays() const {
    return numberOfDays;
}

bool Tour::isMealIncluded() const {
    return mealIncluded;
}

double Tour::getTravelCost() const {
    return travelCost;
}
