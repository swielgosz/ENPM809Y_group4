#include <iostream>
#include <memory>
#include <vector>

#include "mobile_robot.h"
// #include "aerial_robot.h"
// #include "legged_robot.h"

int main(){

  
  std::string model = "test";
  RWA2::MobileRobot robot (1, 2, 10, model);
  // robot.print_status(); // testing robot constructor - need to move print_status into public (instead of protected) for code to use this test
}