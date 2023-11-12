#include "battery.h"

#include <chrono>
#include <thread>

void RWA2::Battery::start_charging() {
    if (!(is_charging_)) {

        std::cout << "Battery " << model_ << " is charging. \n";
        is_charging_ = true;

        // Time needed for charging based on battery model
        int charge_needed = 100 - current_charge_;
        int charge_time_ms{};
        if (model_ == "Li-ion") {
            charge_time_ms = static_cast<int>(1000*charge_needed/2.0);
        } else if (model_ == "LiFePO4") {
            charge_time_ms = static_cast<int>(1000*charge_needed/4.0);
        }

         // program sleeps for charging duration
        std::chrono::milliseconds duration(charge_time_ms);
        std::this_thread::sleep_for(duration);

        // battery full after charging
        current_charge_ = 100;

        stop_charging();
        
    }
}

void RWA2::Battery::stop_charging() {
  is_charging_ = false;
  std::cout << "Battery " << model_ << "is fully charged.\n";
}

void RWA2::Battery::discharge(double amount) {
  current_charge_ -= amount;
}