#include "touragency.h"
#include <algorithm>
#include <iostream> 

TourAgency::TourAgency() {}

void TourAgency::createTourArray() {
    tours.clear();

    Tour tour1("Paris Voyage", "France", 1000.0, 7, true, 500.0);
    Tour tour2("Barcelona Tale", "Spain", 900.0, 5, true, 400.0);
    Tour tour3("Roman Empire", "Italy", 1100.0, 6, true, 600.0);

    tours.push_back(tour1);
    tours.push_back(tour2);
    tours.push_back(tour3);
}


void TourAgency::printAllTours() const {
    for (const auto& tour : tours) {
        std::cout << "Tour Name: " << tour.getTourName() << std::endl;
        std::cout << "Direction: " << tour.getDirection() << std::endl;
        std::cout << "Price per Day: " << tour.getPricePerDay() << std::endl;
        std::cout << "Number of Days: " << tour.getNumberOfDays() << std::endl;
        std::cout << "Meal Included: " << (tour.isMealIncluded() ? "Yes" : "No") << std::endl;
        std::cout << "Travel Cost: " << tour.getTravelCost() << std::endl;
        std::cout << std::endl;
    }
}

void TourAgency::addTour(const Tour& newTour) {
    tours.push_back(newTour);
}

void TourAgency::removeTourByName(const std::string& name) {
    tours.erase(std::remove_if(tours.begin(), tours.end(), [&](const Tour& tour) {
        return tour.getTourName() == name;
        }), tours.end());
}

std::vector<Tour> TourAgency::searchToursByDirection(const std::string& direction) const {
    std::vector<Tour> foundTours;
    for (const auto& tour : tours) {
        if (tour.getDirection() == direction) {
            foundTours.push_back(tour);
        }
    }
    return foundTours;
}

void TourAgency::sortToursByDirection() {
    std::sort(tours.begin(), tours.end(), [](const Tour& tour1, const Tour& tour2) {
        return tour1.getDirection() < tour2.getDirection();
        });
}

void TourAgency::sortToursByTravelCost() {
    std::sort(tours.begin(), tours.end(), [](const Tour& tour1, const Tour& tour2) {
        return tour1.getTravelCost() < tour2.getTravelCost();
        });
}
