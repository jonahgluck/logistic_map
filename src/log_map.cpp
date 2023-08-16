#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

const double Initialr = 1.0;
const double Finalr = 4.0;
const int Divisions = 500;

const int Iterates = 1000;
const double Perturbation = 1.0e-8;

double MapEquation(double r, double x) {
    return r * x * (1.0 - x);
}

double LyapunovFunction(double r, double x, double dx) {
    double f = MapEquation(r, x);
    double fp = MapEquation(r, x + dx);
    return std::log(std::abs(fp - f) / dx);
}

int main() {
    double ParameterRangeStep = (Finalr - Initialr) / (Divisions + 1);
    
    std::vector<std::pair<double, double>> LyapunovData;
    
    for (double r = Initialr; r <= Finalr; r += ParameterRangeStep) {
        double sumLyapunov = 0.0;
        double x = static_cast<double>(rand()) / RAND_MAX;
        double dx = Perturbation;

        for (int i = 0; i < Iterates; ++i) {
            double lyap = LyapunovFunction(r, x, dx);
            sumLyapunov += lyap;
            
            x = MapEquation(r, x);
        }
        
        double averageLyapunov = sumLyapunov / Iterates;
        LyapunovData.push_back(std::make_pair(r, averageLyapunov));
    }
    
    std::ofstream outFile("lyapunov_exponents.txt");
    if (outFile.is_open()) {
        for (const auto& data : LyapunovData) {
            outFile << data.first << "\t" << data.second << std::endl;
        }
        outFile.close();
        std::cout << "Lyapunov exponents saved to lyapunov_exponents.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    return 0;
}

