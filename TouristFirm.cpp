#include "TouristFirm.h"
#include <cstring>
#include <iostream>
#include <algorithm>

void Tour::copy(const Tour& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    country = new char[strlen(other.country) + 1];
    strcpy(country, other.country);

    city = new char[strlen(other.city) + 1];
    strcpy(city, other.city);

    pricePerDay = other.pricePerDay;
    days = other.days;
    hasMeals = other.hasMeals;
    travelCost = other.travelCost;
}

Tour::Tour() : name(nullptr), country(nullptr), city(nullptr), pricePerDay(0.0), days(0), hasMeals(false), travelCost(0.0) {}

Tour::Tour(const char* name, const char* country, const char* city, double pricePerDay, int days, bool hasMeals, double travelCost) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->country = new char[strlen(country) + 1];
    strcpy(this->country, country);

    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);

    this->pricePerDay = pricePerDay;
    this->days = days;
    this->hasMeals = hasMeals;
    this->travelCost = travelCost;
}

Tour::Tour(const Tour& other) {
    copy(other);
}

Tour::~Tour() {
    delete[] name;
    delete[] country;
    delete[] city;
}

Tour& Tour::operator=(const Tour& other) {
    if (this == &other) return *this;

    delete[] name;
    delete[] country;
    delete[] city;

    copy(other);

    return *this;
}

const char* Tour::getName() const { return name; }
const char* Tour::getCountry() const { return country; }
const char* Tour::getCity() const { return city; }
double Tour::getPricePerDay() const { return pricePerDay; }
int Tour::getDays() const { return days; }
bool Tour::hasMeals() const { return hasMeals; }
double Tour::getTravelCost() const { return travelCost; }

double Tour::getTotalCost() const {
    return pricePerDay * days + travelCost;
}

void TouristFirm::createTours(const std::vector<Tour>& newTours) {
    tours = newTours;
}

void TouristFirm::printTours() const {
    for (const auto& tour : tours) {
        std::cout << "Tour: " << tour.getName() << ", Country: " << tour.getCountry() << ", City: " << tour.getCity()
            << ", Price per day: " << tour.getPricePerDay() << ", Days: " << tour.getDays()
            << ", Has meals: " << (tour.hasMeals() ? "Yes" : "No") << ", Travel cost: " << tour.getTravelCost()
            << ", Total cost: " << tour.getTotalCost() << std::endl;
    }
}

void TouristFirm::addTour(const Tour& newTour) {
    tours.push_back(newTour);
}

void TouristFirm::removeTourByName(const std::string& name) {
    tours.erase(std::remove_if(tours.begin(), tours.end(),
        [&name](const Tour& tour) { return strcmp(tour.getName(), name.c_str()) == 0; }), tours.end());
}

std::vector<Tour> TouristFirm::findToursByDestination(const std::string& destination) const {
    std::vector<Tour> result;
    std::copy_if(tours.begin(), tours.end(), std::back_inserter(result),
        [&destination](const Tour& tour) {
            return strcmp(tour.getCountry(), destination.c_str()) == 0 || strcmp(tour.getCity(), destination.c_str()) == 0;
        });
    return result;
}

void TouristFirm::sortByDestination() {
    std::sort(tours.begin(), tours.end(), [](const Tour& a, const Tour& b) {
        int cmpCountry = strcmp(a.getCountry(), b.getCountry());
        if (cmpCountry == 0) {
            return strcmp(a.getCity(), b.getCity()) < 0;
        }
        return cmpCountry < 0;
        });
}

void TouristFirm::sortByTravelCost() {
    std::sort(tours.begin(), tours.end(), [](const Tour& a, const Tour& b) {
        return a.getTravelCost() < b.getTravelCost();
        });
}
