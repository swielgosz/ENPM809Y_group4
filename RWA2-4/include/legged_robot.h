#pragma once

#include <iostream>
#include <utility>
#include "mobile_robot.h"

/**
 * @brief Namespace for RWA2 assignment
 *
 */
namespace RWA2 {
  /**
 * @brief Class for the derived legged robot from base class MobileRobot
 *
 */
class LeggedRobot: public MobileRobot {
  private:
    // ==================== attributes ====================
    //<! distance between robot's feet and ground
    double height_;
    //<! leg strength of the robot
    int leg_strength_; 
    //<! number of legs of the robot (2, 4, or 6)
    int number_of_legs_{2};

  // ==================== constructors ====================
 public:
  /**
   * @brief Construct a new LeggedRobot object
   */
  // Default ctor
  LeggedRobot(): MobileRobot(), number_of_legs_{2} {}

  /**
   * @brief Construct a new LeggedRobot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: model
   * - fifth argument: height
   * - sixth argument: leg strength
   * - seventh argument: number of legs (default = 2)
   */
  LeggedRobot(double x_position, double y_position, double orientation, std::string model, double height, int leg_strength, int number_of_legs = 2): 
  MobileRobot(x_position, y_position, orientation, model), 
  height_{height},
  leg_strength_{leg_strength},
  number_of_legs_{number_of_legs} {}
  

  // ==================== methods ====================
 public:
  /**
   * @brief Move legged robot 
   *
   * @param distance distance to jump
   * @param angle angle to rotate legged
   */
  virtual void move(double distance, double angle) override final;
  /**
   * @brief Print base class and LeggedRobot class attributes
   */
  virtual void print_status() override final;

 protected:
  /**
   * @brief Rotate legged robot 
   * 
   * @param angle angle to rotate legged robot by (in degrees)
   */
  virtual void rotate(double angle) override final; 

 private:
  /**
   * @brief kick with strength of leg_strength_
   */  
  void kick();
  /**
   * @brief Legged robot jumps
   * 
   * @param amount amount in m, robot jumps to height leg_strength*amount
   */
  void jump(double amount);

};  // class MobileRobot
}  // namespace RWA2