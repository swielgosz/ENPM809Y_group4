#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the RWA2 assignment
 */
namespace RWA2 {
/**
 * @brief Class for the sensor
 *
 */
class Sensor {
 private:
  // ==================== attributes ====================
  std::string model_;
  std::array<double, 50> data_;

 public:
  // ==================== constructors ====================
  Sensor(std::string model) : model_{model} {}

  // ==================== methods ====================
  /**
   * @brief Gather sensor data
   *
   * @param duration Duration to gather data
   */
  void read_data(unsigned int duration);


};  // class Sensor
}  // namespace MazeNavigation
