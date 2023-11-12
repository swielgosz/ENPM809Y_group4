#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include "sensor.h"
#include "battery.h"

namespace RWA2 {
class MobileRobot{
 
 protected:
  // ==================== attributes ====================
  // Position of the robot
  std::pair<double, double> position_;
  // Orientation of the robot (degrees)
  double orientation_;
  // Speed of the robot
  double speed_{0.0};
  // Model of the robot
  std::string model_;

  // BATTERY AND SENSOR - INCLUDE THESE WHEN SENSOR AND BATTERY CLASS ARE CREATED
  //<! battery of the robot
  RWA2::Battery battery_;
  //<! list of sensors for the robot
  std::vector<std::unique_ptr<RWA2::Sensor>> sensors_;
  
  // ==================== constructors ====================
public:
  /**
   * @brief Construct a new Mobile Robot object
   */
  // Default ctor
  MobileRobot() : 
    position_{std::make_pair(0, 0)}, 
    orientation_{0},
    speed_{0.0} {}

  /**
   * @brief Construct a new Mobile Robot object
   * 
   * @param x x coordinate 
   * @param y y coordinate
   * @param orientation orientation of the robot (in degrees)
   * @param model model of the robot
   */    
  MobileRobot(double x, double y, double orientation, std::string model)
      : position_{std::make_pair(x, y)}, 
      orientation_{orientation},
      speed_{0.0},
      model_{model} {}

  /**
   * @brief Construct a new Mobile Robot object
   * 
   * @param x x coordinate 
   * @param y y coordinate
   * @param orientation orientation of the robot (in degrees)
   * @param model model of the robot
   * @param battery_model model of the robot's battery
   * @param current_charge robot's battery level
   * @param is_charging battery charging bool 
   */    
  
  MobileRobot(double x, double y, double orientation, std::string model, std::string battery_model, int current_charge = 100, bool is_charging = false)
      : position_{std::make_pair(x, y)}, 
      orientation_{orientation},
      speed_{0.0},
      model_{model},
      battery_{battery_model,current_charge,is_charging} {}

  /**
   * @brief Construct a new Mobile Robot object
   * 
   * @param x x coordinate 
   * @param y y coordinate
   * @param orientation orientation of the robot (in degrees)
   */    
  MobileRobot(double x, double y, double orientation)
      : position_{std::make_pair(x, y)}, 
      orientation_{orientation},
      speed_{0.0} {}
      
  // ==================== accessors ====================
  /**
   * @brief Get the position of the robot
   *
   * @return std::pair<double, double> position
   */
  std::pair<double, double> get_position() const { return position_; }
  /**
   * @brief Get the orientation of the robot
   *
   * @return double orientation (in rad)
   */
  double get_orientation() const { return orientation_; }
  /**
   * @brief Get the speed of the robot
   *
   * @return double speed
   */
  double get_speed() const { return speed_; }
  /**
   * @brief Get the model of the robot
   *
   * @return std::string model
   */
  std::string get_model() const { return model_; }

  // ADD THIS BACK IN AFTER BATTERY UPDATE
  /**
   * @brief Get the battery level of the robot
   *
   * @return double battery level
   */
  // double get_battery_level() const { return battery_level_; }


  // ==================== methods ====================
protected:
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle angle to rotate (in degrees)
   */
  virtual void rotate(double angle);

  // ONLY USE THIS FOR TESTING - otherwise it should be protected, not private
  // virtual void print_status();

 public:
  /**
  * @brief Move the robot by a given distance and angle
  *
  * @param distance distance to move
  * @param angle angle to rotate (in degrees)
  */
  virtual void move(double distance, double angle);
  /**
  * @brief print the status of the robot (position, orientation, and speed)
  */
  virtual void print_status();
  /**
   * @brief Add a sensor to the robot
   *
   * @param sensor sensor to add
   */
  void add_sensor(std::unique_ptr<RWA2::Sensor> sensor);


};  // class MobileRobot
}  // namespace RWA2