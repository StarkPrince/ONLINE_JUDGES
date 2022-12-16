class Airport:
    def __init__(self, code, city, country):
        self._code = code
        self._city = city
        self._country = country

    def __repr__(self) -> str:
        return f"{self._code} - {self._city}, {self._country}"

    def getCode(self):
        return self._code

    def getCity(self):
        return self._city

    def getCountry(self):
        return self._country

    def setCity(self, city):
        self._city = city

    def setCountry(self, country):
        self._country = country

    def setCode(self, code):
        self._code = code
