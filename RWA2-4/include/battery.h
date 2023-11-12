#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the RWA2 assignment
 *
 */
namespace RWA2 {
/**
 * @brief Class for the battery
 *
 */
class Battery {
 private:
  // ==================== attributes ====================
  /*< Capacity*/
  std::string model_;
  int current_charge_;
  bool is_charging_;

 public:
  // ==================== constructors ====================
  Battery()
      : 
        current_charge_{100},
        is_charging_{false} {}
  
  Battery(std::string model, int current_charge, bool is_charging)
      : model_{model},
        current_charge_{current_charge},
        is_charging_{is_charging} {}

  // ==================== accessors ====================
  /**
   * @brief Get the capacity of the battery
   *
   * @return double
   */
  double get_current_charge() const { return current_charge_; }

  // ==================== methods ====================
  /**
   * @brief Start charging the battery
   *
   */
  void start_charging();
  /**
   * @brief Discharge the battery
   *
   * @param amount Battery discharges by amount
   */
  void discharge(double amount);
  
 private:
  /**
   * @brief Stop charging the battery
   *
   */
  void stop_charging();
  

};  // class Battery
}  // namespace MazeNavigation
