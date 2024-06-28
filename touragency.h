#pragma once
#ifndef TOURAGENCY_H
#define TOURAGENCY_H

#include "tour.h"
#include <vector>

class TourAgency {
private:
    std::vector<Tour> tours;

public:
    TourAgency();

    void createTourArray();
    void printAllTours() const;
    void addTour(const Tour& newTour);
    void removeTourByName(const std::string& name);
    std::vector<Tour> searchToursByDirection(const std::string& direction) const;
    void sortToursByDirection();
    void sortToursByTravelCost();
};

#endif
