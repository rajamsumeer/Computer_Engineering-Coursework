## Student ID:
## Student Name: Raja Sumeer
## Unit Test
import unittest

#importing weather class from weather module
from WeatherClass import WeatherData

#create test case that inherits from 'unittest.TestCase'
class TestWeather(unittest.TestCase):
    def test_conditions(self):
        print('test weather conditions')
        # Average numbers for C, km/h, Direction, hPa and mm
        weather = WeatherData(15, 29, ["S"], 1013, 1)
        self.assertEqual(weather.airTemp(), 15)
        self.assertEqual(weather.windSpeeds(), 29)
        self.assertEqual(weather.windDirections, ["S"])
        self.assertEqual(weather.get_pressure(), 1013)
        self.assertEqual(weather.get_rain(), 1)

    # Test summarise() returns a correctly formatted string
    def test_summary(self):
        print('test summary')
        weather = WeatherData(15, 29, ["S"], 1013, 0)
        summary = weather.summarise()
        self.assertIn("Temperature: 15", summary)
        print(summary)

    # Test that collectWeatherData() returns correct data
    def test_collectWeatherData(self):
        weather = WeatherData(15, 29, ["S"], 1013, 0)
        collectedData = weather.collectWeatherData()
        self.assertEqual(collectedData["airTemp"], 15)
    
    # Test bool of is_raining()
    def test_is_raining(self):
        print('test rain status')
        weather = WeatherData(15, 29, ["S"], 1013, 1)
        self.assertEqual(weather.is_raining(), True)

if __name__ == '__main__':
    unittest.main()