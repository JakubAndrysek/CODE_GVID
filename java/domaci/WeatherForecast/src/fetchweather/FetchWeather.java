package fetchweather;

import java.io.IOException;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

/**
 *
 * @author kuba
 */
public class FetchWeather {

    protected String url;
    
    public FetchWeather(String url) {
        this.url = url;
    }
    
    public void setUrl(String url) {
        this.url = url;
    }
    
    public String getUrl() {
        return this.url;
    }
    
    public String fetch() throws IOException {
        try (Scanner scanner = new Scanner(new URL(this.url).openStream(), StandardCharsets.UTF_8.toString())) {
            scanner.useDelimiter("\\A");
            return scanner.hasNext() ? scanner.next() : "";
        }
    }

}
