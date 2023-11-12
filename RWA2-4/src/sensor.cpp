#include "sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>

//==============================================================================
void RWA2::Sensor::read_data(unsigned int duration){
    std::cout << "Sensor " << model_ << " gathering data for " << duration << " seconds." << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(duration));

    // Fill out the array data_ with random numbers between 0 and 30
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 30.0);

    for (int i=0;i<50;i++) {
        data_[i] = dis(gen);
    }
}

