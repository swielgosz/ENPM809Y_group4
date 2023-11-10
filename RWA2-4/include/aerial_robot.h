#pragma once

#include <iostream>
#include <utility>
#include <chrono>
#include "mobile_robot.h"

/**
 * @brief Namespace for RWA2 assignment
 *
 */
namespace RWA2 {
/**
 * @brief Class for the derived aerial robot from base class MobileRobot
 *
 */
class AerialRobot : public MobileRobot {
 private:
  // ==================== attributes ====================

  //<! wing status of robot
  bool has_wings_;
  //<! altitude of the robot
  double altitude_{0.0};
  //<! flying status of robot
  bool is_flying_{false};

// ==================== constructors ====================

public:
  /**
   * @brief Construct a new AerialRobot object
   */

  // Default ctor
  AerialRobot(): MobileRobot(), altitude_{0.0}, is_flying_{false} {}

  /**
   * @brief Construct a new AerialRobot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: has wings
   */
  AerialRobot(double x_position, double y_position, double orientation, std::string model, bool has_wings) 
  : MobileRobot(x_position, y_position, orientation, model), 
  has_wings_{has_wings},
  altitude_{0.0},
  is_flying_{false} {}


  // ==================== methods ====================

public:
  /**
   * @brief Move aerial robot 
   *
   * @param distance distance to increase altitude by
   * @param angle angle to rotate aerial robot
   */
  virtual void move(double distance, double angle) override final;
  /**
   * @brief Print base class and AerialRobot class attributes
   */
  virtual void print_status() override final;

protected:  
  /**
   * @brief Rotate aerial robot 
   * 
   * @param angle angle to rotate aerial robot by (in degrees)
   */
  virtual void rotate(double angle) override final; 

private:
  /**
   * @brief Aerial Robot takes off to given altitude
   *
   * @param altitude_ altitude to take off to
   */
  void take_off(double altitude_);
  /**
   * @brief Land the aerial robot
   */
  void land();

}; // class MobileRobot
} // namespace RWA2