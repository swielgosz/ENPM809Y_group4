#include "legged_robot.h"
// #include "battery.h"  INCLUDE THIS WHEN BATTERY CLASS IS MADE
// #include "sensor.h"  INCLUDE THIS WHEN SENSOR CLASS IS MADE
#include <thread>
#include <chrono>

// Implement kick method
void RWA2::LeggedRobot::kick() {
  std::cout << RWA2::MobileRobot::model_ <<" kicks with a strength of  " << leg_strength_ << "\n"; 
}

// Implement jump method
void RWA2::LeggedRobot::jump(double amount) {
  // height in m
  height_ = amount*leg_strength_/100;
  std::cout << RWA2::MobileRobot::model_ << " jumps at a height of  " << height_*100 << " cm above the ground\n"; 
}

void RWA2::LeggedRobot::rotate(double angle) {
  std::cout << "LeggedRobot::"<<RWA2::MobileRobot::model_ <<" rotated " << angle << " degrees.\n"; 
}

void RWA2::LeggedRobot::print_status() {
  RWA2::MobileRobot::print_status();
  std::cout << "================\n";
  std::cout
      << "Height (cm): " << height_*100 << ", Leg strength: " << leg_strength_ <<", Number of legs: " << number_of_legs_ << "\n";
}

// void RWA2::LeggedRobot::move() {
//   std::cout << "LeggedRobot: Moving\n";
// }

// Implement move method
void RWA2::LeggedRobot::move(double distance, double angle) {

  if (distance > 10) { // check that distance <= 10 m; if true, proceed
    std::cout << "Max distance value is 10 m.\n\n";
  } else {
    // required battery to jump to distance, where 1% battery charge is used for every cm the robot jumps above the ground, and 1% battery used per leg_strength_
    double required_height = distance*leg_strength_/100; // units = (m)
    double required_battery = required_height*100 + leg_strength_; 

    // if batter does not have enough charge, charge it
    if (battery_.get_current_charge() <required_battery) {
      //charge the robot
      battery_.start_charging(); 
    } 

    // when charge is sufficient, move robot
    battery_.discharge(required_battery);
    sensors_.read_data(5); // NOT SURE IF THIS IS CORRECT WAY TO CALL
    rotate(angle);
    jump(distance);
    kick()
    print_status();
  }
}