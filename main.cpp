#include <iostream>
#include <fstream>
#include <sys/sysinfo.h>
#include <unistd.h>

using namespace std;

// Function to get CPU usage
double getCPUUsage() {
    ifstream fileStat("/proc/stat");
    string line;
    getline(fileStat, line); // Read the first line
    fileStat.close();

    // Extract CPU usage from the line and perform necessary computations
    double cpuUsage = 0.0; // Placeholder value
    // Compute CPU usage

    return cpuUsage;
}

// Function to get memory usage
double getMemoryUsage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    long long totalPhysMem = memInfo.totalram;
    totalPhysMem *= memInfo.mem_unit;
    long long freePhysMem = memInfo.freeram;
    freePhysMem *= memInfo.mem_unit;

    // Calculate memory usage
    double memoryUsage = (totalPhysMem - freePhysMem) / (1024.0 * 1024.0); // in MB
    return memoryUsage;
}

int main() {
    while (true) {
        // Get live resource usage
        double cpuUsage = getCPUUsage();
        double memoryUsage = getMemoryUsage();

        // Print the live resource usage
        cout << "CPU Usage: " << cpuUsage << "%" << endl;
        cout << "Memory Usage: " << memoryUsage << " MB" << endl;

        // Sleep for a few seconds before checking the resources again
        sleep(1); // Adjust the sleep duration as needed
    }

    return 0;
}

