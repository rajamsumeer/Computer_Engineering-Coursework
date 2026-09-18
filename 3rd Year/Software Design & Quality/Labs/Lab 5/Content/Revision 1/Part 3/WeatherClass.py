## Student ID:
## Student Name: Raja Sumeer
## Weather Class
class WeatherData:
    """Simple Weather data class that stores and returns weather conditions"""
    def __init__(self, temperature, wind, windDirections, pressure, rain):
        self.temperature = temperature # C
        self.wind = wind # km/h
        self.windDirections = windDirections # S,N,W,E
        self.pressure = pressure #hPa
        self.rain = rain # mm

    # getter methods that returns weather conditions
    def get_pressure(self):
        """Return atmosphere pressure value"""
        return self.pressure

    def get_rain(self):
        """Return rain value"""
        return self.rain

    def airTemp(self):
        """Return air temperature value"""
        return self.temperature

    def windSpeeds(self):
        """Return wind speed value"""
        return self.wind

    def windDirections(self):
        """Return wind direction"""
        return self.windDirections

    # helper methods
    def collectWeatherData(self):
        """Return stored weather data"""
        return { 
            "airTemp": self.airTemp(), 
            "windSpeeds": self.windSpeeds(), 
            "windDirections": self.windDirections,
            "pressure": self.get_pressure(),
            "rain": self.get_rain()
        }

    def summarise(self):
        """Returns a string summary of weather data"""
        return f"Temperature: {self.temperature} C\n Wind Speed: {self.wind} km/h\n Wind Directions: {self.windDirections}\n Rain: {self.rain} mm"

    def is_raining(self):
        """Return true if rainfall greater than 0mm"""
        return self.rain > 0