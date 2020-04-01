@echo OFF

echo Nastaveni vychozi konfigurace programu Code::Blocks
echo Autor: David Martinek, GVID, 2019
echo Verze 2.0

SET adresar=%USERPROFILE%\AppData\Roaming\CodeBlocks

SET kde=pf

IF NOT EXIST "c:\Program Files\CodeBlocks"  ( 
  IF EXIST "c:\Program Files (x86)\CodeBlocks" (
    SET kde=pf86
  ) ELSE (
    echo CodeBlocks neni na znamem miste. Asi neni nainstalovany. Koncim.
    pause
    exit
  )
)


IF NOT EXIST default-%kde%.conf ( 
  echo V aktualnim adresari chybi soubor default-%kde%.conf. Koncim.
  pause
  exit
)

IF NOT EXIST %adresar% ( 
  echo Adresar %adresar% neexistuje. Asi tady jeste nebyl C::B nikdy spusten. 
  echo Zkusim ho vytvorit.
  mkdir %adresar%
)

echo.
echo Soubor default-%kde%.conf obsahuje vychozi konfiguraci programu Code::Blocks
echo upravenou pro pouziti v ucebnach IVT na GVID. Po instalaci muzes sve nastaveni
echo v C::B menit. Toto nastaveni zustane na tomto konkretnim pocitaci, ne jinde.
echo Nastaveni take neprezije odhlaseni z docasnych uctu (student).
echo.
echo Konfigurace obsahuje:
echo - spravne nastaveny debugger
echo - pridany zkratky pro tvorbu kodu (pres Ctrl+J): fori, print, struct
echo - vypnuty modul pro kontrolu pravopisu (nemame nainstalovany cesky slovnik)
echo - vypnuty dalsi nepotrebne a matouci moduly
echo - kontrastnejsi barvy komentaru
echo - a dalsi...
echo.
echo Budu kopirovat do adresare %adresar%
echo.

:vyber
set /P c=Mam skutecne prepsat tvou C::B konfiguraci[A/N]?
if /I "%c%" EQU "A" goto :kopie
if /I "%c%" EQU "N" goto :konec
echo Vybral jsi variantu, ktere nerozumim. Zkus to znovu.
echo.
goto :vyber

:kopie
echo "Kopiruji soubor default-%kde%.conf."
COPY default-%kde%.conf %adresar%\default.conf
pause
exit

:konec
echo "Nic kopirovat nebudu."
pause
exit
