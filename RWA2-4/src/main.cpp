#include <iostream>
#include <memory>
#include <vector>
#include "sensor.h"
#include "mobile_robot.h"
#include "aerial_robot.h"
#include "legged_robot.h"

void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>>& robots) {
    for (const auto& robot : robots) {
        std::cout << "Moving Robot " << robot->get_model() << "\n";
            robot->move(10,20);
    }
}

// Robot models:
// AquaticRobot - HoloOcean (does not have fins) and SoFi (has fins)
// AerialRobot - Erle-Plane (has wings) and Crazyflie (does not have wings)
// WheeledRobot - Turtlebot (2-wheeled), Hiwonder (4-wheeled) and Dagu (6-wheeled)
// LeggedRobot - Atlas (bipedal), Spot (quadrupedal), and Mx-Phoeniz(hexapod)

// Battery models:
// Li-ion - charges at a rate of 2%/second
// LiFePO4 - charges at a rate of 4%/second

// Sensor models:
// From Ouster - OSDome, OD0, OS1, OS2
// From SICK - multiScan100, LMS5xx, LD-MRS

int main() {

    std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;

    std::unique_ptr<RWA2::MobileRobot> aerial_ptr =
    std::make_unique<RWA2::AerialRobot>(2.5, 5.5, 45.0, "Erle-Plane", "Li-ion", true, 100, false);
    aerial_ptr->add_sensor(std::make_unique<RWA2::Sensor>("OSDome"));
    aerial_ptr->add_sensor(std::make_unique<RWA2::Sensor>("OS0"));

    std::unique_ptr<RWA2::MobileRobot> legged_ptr =
    std::make_unique<RWA2::LeggedRobot>(3.5, 6.5, 45.0, "Atlas", "LiFePO4", 2, 8, 100, false, 2);
    legged_ptr->add_sensor(std::make_unique<RWA2::Sensor>("OS2"));
    legged_ptr->add_sensor(std::make_unique<RWA2::Sensor>("multiScan100"));

    mobile_robots.push_back(std::move(aerial_ptr));
    mobile_robots.push_back(std::move(legged_ptr));


    move_robot(mobile_robots);
}