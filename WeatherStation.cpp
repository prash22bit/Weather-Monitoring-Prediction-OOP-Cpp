#include <iostream>
#include <vector>
#include "WeatherData.cpp" // Include the WeatherData implementation directly
  
using namespace std;

class WeatherStation {
private:
    WeatherData currentData;

public:
    string City;
    void updateWeatherData() {
        float temp, hum, wind;

        cout << "🌡️ Enter Temperature (°C): ";
        while (!(cin >> temp)) {
            cout << "⚠️ Invalid input! Please enter a numeric value for temperature: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "💧 Enter Humidity (%): ";
        while (!(cin >> hum)) {
            cout << "⚠️ Invalid input! Please enter a numeric value for humidity: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "💨 Enter Wind Speed (m/s): ";
        while (!(cin >> wind)) {
            cout << "⚠️ Invalid input! Please enter a numeric value for wind speed: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        currentData.setData(temp, hum, wind);
    }

    void displayCurrentData(string ct) {
        currentData.City = ct;
        currentData.displayData();
    }

    float getTemperature() const { return currentData.getTemperature(); }
    WeatherCondition getCondition() const { return currentData.getCondition(); }
};
