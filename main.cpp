#include <iostream>
#include <vector>
#include <limits>
#include "WeatherStation.cpp" // Include the WeatherStation implementation directly
using namespace std;

class WeatherPredictor {
public:
    static float predictTemperature(const vector<float>& previousTemperatures) {
        if (previousTemperatures.empty()) return 0.0f;

        float sum = 0.0f;
        for (float temp : previousTemperatures) {
            sum += temp;
        }
        return sum / previousTemperatures.size(); // Average for prediction
    }
};

int main() {
    WeatherStation station;
    vector<float> previousTemperatures;
    vector<WeatherCondition> previousConditions;
    
    string city;
    int numReadings;

    cout << "***********************************" << endl;
    cout << "Welcome to the Weather Predictor! ☀️" << endl;
    cout << "Please enter the city for which you wish to predict the weather :🌆 ";
    getline(cin, city);
    
    cout << "How many readings would you like to input? (e.g., 5): " <<endl;
    cout <<"Give atleast 5 for more precise output."<<endl;
    cin >> numReadings;

    for (int i = 0; i < numReadings; ++i) {
        station.updateWeatherData();
        station.displayCurrentData(city);

        float currentTemp = station.getTemperature();
        WeatherCondition currentCondition = station.getCondition();

        // Calculate the predicted temperature based on previous readings
        if (!previousTemperatures.empty()) {
            float predictedTemp = WeatherPredictor::predictTemperature(previousTemperatures);
            cout << "🔮 Predicted Next Temperature: " << predictedTemp << "°C, Previous Condition: " 
                 << weatherConditionToString(previousConditions.back()) << " 🌤️\n";
        } else {
            cout << "⚠️ No previous temperature data available for prediction.\n";
        }

        // Store the current temperature and condition for future predictions
        previousTemperatures.push_back(currentTemp);
        previousConditions.push_back(currentCondition);
        if (previousTemperatures.size() > 5) { // Maintain the last 5 entries
            previousTemperatures.erase(previousTemperatures.begin());
            previousConditions.erase(previousConditions.begin());
        }
    }

    return 0;
}
