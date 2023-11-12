#include "mobile_robot.h"
#include <iostream>
#include <thread>


void RWA2::MobileRobot::add_sensor(
    std::unique_ptr<RWA2::Sensor> sensor) {
  sensors_.push_back(std::move(sensor));
}

void RWA2::MobileRobot::rotate(double angle) {
  if (angle >= 0) {
    orientation_ += orientation_;
  } else {
    orientation_ -= orientation_;
  }
}

// empty body because it is pure virtual
void RWA2::MobileRobot::move(double distance, double angle) {}

void RWA2::MobileRobot::print_status() {
  std::cout << "================\n";
  std::cout
      << " Model: " << model_ << ", Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << "\n";
}