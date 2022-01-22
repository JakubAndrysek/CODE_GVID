package parseweather;
import org.json.*;


/**
 *
 * @author kuba
 */
public class ParseWeather {
    protected String weatherJson;
    protected JSONObject parsedWeather;
    protected JSONObject mainWeather;
    
    public ParseWeather(String weatherJson) {
        this.weatherJson = weatherJson;
    }
    
    public void parse() {
        parsedWeather = new JSONObject(this.weatherJson);
        mainWeather = parsedWeather.getJSONObject("main");
    }
    
    private double getDoubleByName(String name) {
        String strVal = mainWeather.get(name).toString();
        return Double.parseDouble(strVal);
    }
    
    private int getIntByName(String name) {
        String strVal = mainWeather.get(name).toString();
        return Integer.parseInt(strVal);
    }    
    
    public double getTemp() {
        return getDoubleByName("temp");
    }
    
    public double getTempMin() {
        return getDoubleByName("temp_min");
    }
    
    public double getTempMax() {
        return getDoubleByName("temp_max");        
    }
    
    public int getPressure() {
        return getIntByName("pressure");
    }
    
    public int getHumidity() {
        return getIntByName("humidity");
    }
    
    public double getFeelsLike() {
        return getDoubleByName("feels_like");
    }
}
