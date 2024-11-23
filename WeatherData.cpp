#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;

// Enumeration for Weather Conditions
enum class WeatherCondition {
    ClearSunny,
    PartlyCloudy,
    Cloudy,
    Rain,
    Snow,
    Fog,
    Thunderstorms,
    Windy,
    ExtremeHeat,
    ExtremeCold,
    Hail,
    Tornado,
    HurricaneTyphoon,
    Blizzard,
    Unknown
};

// Function to convert enum to string for display purposes
string weatherConditionToString(WeatherCondition condition) {
    switch (condition) {
        case WeatherCondition::ClearSunny: return "Clear/Sunny ☀️";
        case WeatherCondition::PartlyCloudy: return "Partly Cloudy 🌤️";
        case WeatherCondition::Cloudy: return "Cloudy ☁️";
        case WeatherCondition::Rain: return "Rain 🌧️";
        case WeatherCondition::Snow: return "Snow ❄️";
        case WeatherCondition::Fog: return "Fog 🌫️";
        case WeatherCondition::Thunderstorms: return "Thunderstorms ⛈️";
        case WeatherCondition::Windy: return "Windy 🌬️";
        case WeatherCondition::ExtremeHeat: return "Extreme Heat 🔥";
        case WeatherCondition::ExtremeCold: return "Extreme Cold 🥶";
        case WeatherCondition::Hail: return "Hail 🌨️";
        case WeatherCondition::Tornado: return "Tornado 🌪️";
        case WeatherCondition::HurricaneTyphoon: return "Hurricane/Typhoon 🌀";
        case WeatherCondition::Blizzard: return "Blizzard ❄️🌨️";
        case WeatherCondition::Unknown: return "Unknown Condition ❓";
        default: return "Unknown Condition ❓";
    }
}

class WeatherData {
private:
    float temperature;
    float humidity;
    float wind_speed;
    WeatherCondition condition;

public:
    string City; 
    WeatherData() : temperature(0), humidity(0), wind_speed(0), condition(WeatherCondition::Unknown) {}

    void setData(float temp, float hum, float wind) {
        if (temp < -50 || temp > 50) {
            throw out_of_range("⚠️ Temperature out of range! Please enter a value between -50°C and 50°C.");
        }
        if (hum < 0 || hum > 100) {
            throw out_of_range(" ⚠️ Humidity out of range! Please enter a value between 0% and 100%.");
        }
        if (wind < 0) {
            throw out_of_range("⚠️ Wind speed cannot be negative! Please enter a valid value.");
        }

        temperature = temp;
        humidity = hum;
        wind_speed = wind;

        determineWeatherCondition();
    }

    void displayData() const {
        cout << "Weather Data for " << City 
             << ": 🌆 Temperature: " << temperature << "°C, "
             << "Humidity: " << humidity << "%, "
             << "Wind Speed: " << wind_speed << " m/s, "
             << "Condition: " << weatherConditionToString(condition) << "\n";
    }

    float getTemperature() const { return temperature; }
    WeatherCondition getCondition() const { return condition; }

private:
    void determineWeatherCondition() {
        if (temperature > 30) {
            condition = WeatherCondition::ExtremeHeat;
        } else if (temperature < 0) {
            condition = WeatherCondition::ExtremeCold;
        } else if (humidity > 80 && temperature > 20) {
            condition = WeatherCondition::Rain;
        } else if (humidity > 90) {
            condition = WeatherCondition::Fog;
        } else if (temperature < 0 && humidity > 70) {
            condition = WeatherCondition::Snow;
        } else if (wind_speed > 25) {
            condition = WeatherCondition::Windy;
        } else if (temperature >= 20 && humidity < 50) {
            condition = WeatherCondition::ClearSunny;
        } else {
            condition = WeatherCondition::Cloudy;
        }
    }
};
