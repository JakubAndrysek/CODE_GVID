package weatherforecast;

import java.io.*;
import fetchweather.FetchWeather;
import parseweather.ParseWeather;


/**
 *
 * @author kuba
 */
public class WeatherForecast {    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {        
        String urlBrno = "https://fcc-weather-api.glitch.me/api/current?lat=49.195221&lon=16.60796";
        FetchWeather weatherFatcher = new FetchWeather(urlBrno);
        String weatcherJson = "";
        
        try {
            weatcherJson = weatherFatcher.fetch();            
        } catch (IOException ex) {
            ex.printStackTrace();
        } finally {
            System.out.println("Fetch OK");
            System.out.println(weatcherJson);
        }
        
        ParseWeather weather = new ParseWeather(weatcherJson);
        weather.parse();
        
        System.out.println("Weather in Brno");
        System.out.printf("Temp: %.2f (min %.2f | max %.2f)\n", weather.getTemp(), weather.getTempMin(), weather.getTempMax());
        System.out.printf("Feels like: %.2f\n", weather.getFeelsLike());
        System.out.printf("Humidity: %d | pressure: %d\n", weather.getHumidity(), weather.getPressure());
    }    
}
