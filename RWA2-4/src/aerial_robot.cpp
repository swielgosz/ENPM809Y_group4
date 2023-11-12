#include "aerial_robot.h"
#include "battery.h"
#include "sensor.h"
#include <chrono>
#include <iostream>
#include <thread>

// Implement take_off method
void RWA2::AerialRobot::take_off(double altitude) {
  if (!(is_flying_)) {

    // flight time in milliseconds
    int flight_time_ms{};
    if (has_wings_) {
       flight_time_ms = static_cast<int>(1000*altitude/3);
    } else {
      flight_time_ms = static_cast<int>(1000*altitude/1.5);
    }

    // program sleeps for flight duration
    std::this_thread::sleep_for(std::chrono::milliseconds(flight_time_ms));

    // fly to new altitude
    altitude_ = altitude;

  }
}

// Implement land method
void RWA2::AerialRobot::land() {
  if (is_flying_) {

    // landing time in milliseconds
    int land_time_ms{};
    if (has_wings_) {
      land_time_ms = static_cast<int>(1000*altitude_/4);
    } else {
      land_time_ms = static_cast<int>(1000*altitude_/2);
    }

    // program sleeps for flight duration
    std::this_thread::sleep_for(std::chrono::milliseconds(land_time_ms));

    // altitude is 0 after landing
    altitude_ = 0.0;
  }
}

// Implement rotate method
void RWA2::AerialRobot::rotate(double angle) {
  RWA2::MobileRobot::rotate(angle);
  std::cout << "AerialRobot::"<<RWA2::MobileRobot::model_ <<" rotated " << angle << " degrees.\n"; 
}

// Implement print status method
void RWA2::AerialRobot::print_status() {
  RWA2::MobileRobot::print_status();
  std::cout << "================\n";
  std::cout
       << "Has wings: " << std::boolalpha << has_wings_ << ", Flying: " << std::boolalpha << is_flying_ << ", Altitude: " << altitude_ << "\n\n";
}

// Implement move method
void RWA2::AerialRobot::move(double distance, double angle) {

  if (distance > 50) { // check that distance <= 50 m; if true, proceed
    std::cout << "Max distance value is 50 m.\n\n";
  } else {
    // required battery to take off to distance and land, where 2% of batter is consumed each m the robot moves
    double required_battery = 2*distance;

    // if batter does not have enough charge, land and charge
    if (battery_.get_current_charge() <required_battery) {
      // land the robot, which discharges battery during landing at 2% per m
      land();
      battery_.discharge(2*altitude_); 
      //charge the robot
      battery_.start_charging(); 
    } 

    // when charge is sufficient, move robot
    battery_.discharge(required_battery);
    // sensors_.read_data(5); // NOT SURE IF THIS IS CORRECT WAY TO CALL
    for (const auto& sensor : sensors_) {
    sensor->read_data(5);
    }
    take_off(distance/2);
    rotate(angle);
    land();
    std::cout << model_ << " reached an altitude of " << distance/2 << " meters and then landed.\n";
    print_status();
  }
}

