package tvary;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author kuba
 */
public class TvarReader {
    
    String fileName;
    Scanner sc = null;
    final String regex = "(?<tvar>[a-zA-Z]+): (?<x>[+-]?([0-9]*[.])?[0-9]+) (?<y>[+-]?([0-9]*[.])?[0-9]+) (?<a>[+-]?([0-9]*[.])?[0-9]+) ?(?<b>[+-]?([0-9]*[.])?[0-9]+)?";
    final Pattern pattern = Pattern.compile(regex);

    public TvarReader(String fileName) {
        this.fileName = fileName;
        
        try {
            sc = new Scanner(new FileInputStream(fileName)).useLocale(Locale.US);
        } catch(FileNotFoundException e) {
            System.out.println("Pozadovany soubor nebyl nalezen");
        }
    }
    
    
    public boolean hasNextTvar() {
        if(!checkFile()) {
            return false;
        }
        
        Matcher parsedLine = parseLine();
        return parsedLine.find(); // bool val
    }
    
    
    public Tvar nextTvar() throws FileNotFoundException, Throwable {
        if(!checkFile()) {
            throw new FileNotFoundException();
        }
        
        Matcher pars = parseLine();
        if(!pars.find()) {
            System.out.println("Nepodarilo se nic rozparsovat");
            throw new ArithmeticException("Nepodarilo se nic rozparsovat");
        }

        System.out.println("Tvar: " + pars.group("tvar") + "[" +pars.group("x") + "]");
        
        
        return tvarInstancer("Obdelnik", new Bod(matchToDouble(pars, "x"), matchToDouble(pars, "y")), matchToDouble(pars, "a"), matchToDouble(pars, "b"));

    }
    
    protected boolean checkFile() {
        if(sc == null) {
            System.out.println("Soubor neexistuje");
            return false;
        }
        
        if(!sc.hasNextLine()) {
            System.out.println("Neni co nacist");
            return false;
        }    
        
        return true;
    }
    
    protected Matcher parseLine() {
        String stringLine = sc.nextLine();
        System.out.println("Nacteno:" + stringLine);
        final Matcher matcher = pattern.matcher(stringLine);
        
        return matcher;
    }
    
    protected Tvar tvarInstancer(String tvarNazev, Bod bod, Double a, Double b) throws Throwable {
        
//        Object constructorParam;
//        
//        Class tvarClass = Tvar.class;
        
        
        try{
            String fullTvarNazev = "tvary." + tvarNazev;
            Constructor c = Class.forName(fullTvarNazev).getConstructor(new Class[]{double.class, double.class, Bod.class});
            c.setAccessible(true);
            Tvar instance = (Tvar) c.newInstance(new Object[]{a, b, bod}) ; 
            return instance;
        } catch (ClassNotFoundException e) {
                e.printStackTrace();
        }

        return null;
    }
    
    private double matchToDouble(Matcher parsedLine, String group) {
        return Double.parseDouble(parsedLine.group(group));
    }
}
