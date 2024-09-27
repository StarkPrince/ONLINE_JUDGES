const geoTz = require('geo-tz');

function getTimezoneByCoordinates(lat, lon)
{
    // Find the timezone using latitude and longitude
    const timezone = geoTz.find(lat, lon);
    return timezone;
}

// Example usage:
const latitude = 40.7128;  // New York City latitude
const longitude = -74.0060;  // New York City longitude
console.log("IANA Timezone Code:", getTimezoneByCoordinates(latitude, longitude));
