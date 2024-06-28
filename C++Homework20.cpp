#include <iostream>
#include "tour.h"
#include "touragency.h"

int main() {
    Tour tour1("Paris Voyage", "France", 1000.0, 7, true, 500.0);
    Tour tour2("Barcelona Tale", "Spain", 900.0, 5, true, 400.0);
    Tour tour3("Roman Empire", "Italy", 1100.0, 6, true, 600.0);

    TourAgency agency;
    agency.addTour(tour1);
    agency.addTour(tour2);
    agency.addTour(tour3);

    std::cout << "All tours:" << std::endl;
    agency.printAllTours();

    std::cout << "\nSearching for tours to Spain:" << std::endl;
    std::vector<Tour> spainTours = agency.searchToursByDirection("Spain");
    for (const auto& tour : spainTours) {
        std::cout << tour.getTourName() << " (" << tour.getDirection() << ")" << std::endl;
    }

    std::cout << "\nSorting tours by direction:" << std::endl;
    agency.sortToursByDirection();
    agency.printAllTours();

    std::cout << "\nSorting tours by travel cost:" << std::endl;
    agency.sortToursByTravelCost();
    agency.printAllTours();

    std::cout << "\nRemoving tour Paris Voyage:" << std::endl;
    agency.removeTourByName("Paris Voyage");
    agency.printAllTours();

    return 0;
}
