// Projekt: Chybová hlášení,  Autor: David Martinek
// Popis: Demonstrace toho, jak chápat chybová hlášení překladače a jak s nimi pracovat.
// Používej spodní záložky v Code::Blocks
// - Build messages: po kliknutí na řádek s hlášením tě přesune na problémový řádek
// - Build log: hlášení zde ukazují i na konkrétní místo v řádku, kde byla chyba detekována
//
// POZOR!!! NEVKLÁDEJ NOVÉ ŘÁDKY! CHYBOVÁ HLÁŠENÍ BY PAK NEODPOVÍDALA VÝSKYTŮM CHYB.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
/*** Chyba č. 1: Zapomenutý středník ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba1(void)
//{
//  // zapomenuty strednik
//  int x = 10
//
//  printf("%d\n", x);
//
//  // Chybové hlášení
//  // main.c: In function 'chyba1':
//  // main.c:20:3: error: expected ',' or ';' before 'printf'
//
//  // Vysvětlení
//  // main.c:20:3: -- chybu objevil v souboru main.c na řádku 20, ve 3. znaku
//  // Očekává se ',' nebo ';' před příkazem printf.
//  // Chyba se sice projevila až na řádku 20, ale ve skutečnosti vznikla už na řádku 18!
//  // Chybu je třeba hledat vždy před místem, kde se projeví.
//}

/*** Chyba č. 2: Čárka vs. tečka ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba2(void)
//{
//  float x = 10,2;
//  printf("%f\n", x);
//
//  // Chybové hlášení
//  // main.c: In function 'chyba2':
//  // main.c:37:16: error: expected identifier or '(' before numeric constant
//
//  // Vysvětlení
//  // Očekává se identifikátor nebo závorka před numerickou konstantou.
//  // Chyba je na řádku 37, na pozici 16: je to ta čárka. Má tam být desetinná tečka.
//  // Čárka je v C operátor, který má specifický význam při vyhodnocování výrazů, takže
//  // ji překladač nemůže automaticky označit za chybu. Místo toho napíše, že mu tam leží
//  // bezprizorní konstanta (ta dvojka) a hádá, že by tam mohl chybět identifikátor nebo
//  // nějaký výraz začínající závorkou.
//}

/*** Chyba č. 3: Čárka mezi argumenty ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba3(void)
//{
//  float x = 10.2;
//  printf("x\n");      // syntakticky správně, ale hodnotu x to nevytiskne
//  printf("%d\n", x);  // syntakticky správně, ale tiskne nesmysl kvůli chybné formátovací značce
//  printf("%f\n" x);
//
//  // Chybové hlášení
//  // main.c: In function 'chyba3':
//  // main.c:60:17: error: expected ')' before 'x'
//
//  // Vysvětlení
//  // Na řádku 60, pozici 17 očekává zavírací závorku před 'x'.
//  // Chyba je v parametrech funkce printf. Je zde textový řetězec následovaný písmenem x.
//  // To ale nedává v C smysl, proto si překladač myslí, že by se tady měl seznam parametrů
//  // funkce printf uzavřít. Až do konce toho řetězce tomu rozumí, dále už mu to nedává smysl.
//  // Správně zde má být čárka mezi argumenty funkce.
//}

/*** Chyba č. 4: Zapomenutý argument ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba4(void)
//{
//  double d;
//  scanf(d);
//
//  // Chybové hlášení
//  // main.c: In function 'chyba4':
//  // main.c:79:3: error: incompatible type for argument 1 of 'scanf'
//  // stdio.h:347:37: note: expected 'const char *' but argument is of type 'double'
//  //
//  // Vysvětlení
//  // Na řádku 79, na pozici 3: nekompatibilní typ argumentu č. 1 ve funkci scanf.
//  // Poznámka: očekává se něco typu 'const char *', ale argument je typu 'double'.
//  //
//  // Všimni si, že poznámka se vztahuje k hlavičkovému souboru stdio.h, kde se nachází
//  // deklarace funkce scanf. Jako první argument funkce scanf se očekává konstantní
//  // ukazatel na char, což je jinými slovy textový řetězec - v tomto případě se tady
//  // očekává formátovací řetězec s formátovacími značkami. Funkce scanf dále předpokládá,
//  // že bude následovat tolik dalších argumentů, kolik je v řetězci uvedeno formátovacích
//  // značek. V tomto případě je na místě formátovacího řetězce proměnná typu double, což
//  // je samozřejmě špatně.
//}

/*** Chyba č. 5: Argument předaný hodnotou vs. odkazem ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba5(void)
//{
//  double d;
//  scanf("%lf", d);
//  printf("%f", d);
//
//  // Varování
//  // main.c: In function 'chyba5':
//  // main.c:104:3: warning: format '%lf' expects argument of type 'double *', but argument 2 has type 'double' [-Wformat=]
//  // main.c:104:3: warning: 'd' is used uninitialized in this function [-Wuninitialized]
//
//  // Vysvětlení
//  // Na řádku 104 je použita formátovací značka '%lf', která očekává, že bude následovat argument typu 'double *', ale
//  // argument č. 2 má místo toho typ 'double'. Dalším vodítkem je druhé varování, že proměnná 'd' je zde použita neinicializovaná.
//  //
//  // To, že se očekává argument typu 'double *' naznačuje, že jde o parametr předávaný odkazem. Proměnná 'd'
//  // zde je předávaná přímo, což je chyba. Správně má být jako argument použit výraz '&d'.
//  //
//  // Všimni si, že tento kód jde přeložit, ale bude fungovat špatně. Po spuštění a zadání nějaké hodnoty na vstup
//  // dojde k havárii programu, protože přečtená hodnota se místo do proměnné 'd' zapíše na nějakou náhodnou adresu
//  // v paměti.
//}

/*** Chyba č. 6: Prázdné tělo funkce ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba6(void)
//{
//  int i;
//  for (i = 1; i <= 10; ++i);
//  {
//    printf("%d ", i);
//  }
//
//  // Chybové hlášení
//  // V tomto případě program žádnou syntaktickou chybu neobsahuje!
//  // Program obsahuje sémantickou chybu, kterou překladač neodhalí.
//  //
//  // Vysvětlení
//  // Program má zjevně vypsat posloupnost čísel od 1 do 10. Místo toho ale vypíše jen hodnotu 10.
//  // Problém je ve středníku na řádku 129. Tento středník má význam prázdného příkazu. --> Tělo
//  // cyklu je prázdný příkaz! Blok s příkazem printf teď nemá s příkazem for nic společného --
//  // teď není tělem příkazu for, i když to tak může na první pohled vypadat. V jazyce C jde blokový
//  // příkaz použít kdekoli, nemusí to být nutně jen tělo cyklu.
//  //
//  // Teď víš, že středník za hlavičkou cyklu znamená cyklus s prázdným tělem a toto chování
//  // tě už nepřekvapí. Opravou v tomto případě je smazání středníku na řádku 129.
//}

/*** Chyba č. 7: Prázdné tělo funkce ***/
// označ celou funkci, pak odkomentuj pomocí Ctrl+Shift+X
//void chyba7(void)
//{
//  int i;
//  for (i = 1; i <= 10; ++i)                                                                                                                                                     ; // to je sviňárna, co?
//  {
//    printf("%d ", i);
//  }
//
//  // Chybové hlášení
//  // V tomto případě program žádnou syntaktickou chybu neobsahuje!
//  // Program obsahuje sémantickou chybu, kterou překladač neodhalí.
//  //
//  // Vysvětlení
//  // Program má zjevně vypsat posloupnost čísel od 1 do 10. Místo toho ale vypíše jen hodnotu 10.
//  // Tady na první pohled žádná chyba vidět není. Pořádně ale prozkoumej řádek 154.
//  // Tento řádek má délku 200 znaků. Chyba je až za okrajem okna. Jde o stejnou chybu jako minule,
//  // jen není vidět na první pohled.
//  //
//  // K takovéto chybě může snadno dojít nešikovnými úpravami zdrojového textu. Může se vyskytnout
//  // v jakémkoli programovacím jazyce, proto je třeba o ní vědět. U chyb, které jsou zdánlivě neviditelné,
//  // stojí za to podívat se za okraj.
//}

/*** Chyba č. 8: Ukazatel jako parametr ***/
// označ celý zakomentovaný blok, pak odkomentuj pomocí Ctrl+Shift+X
//bool ciselnaOtazka(char *otazka, float *cislo)
//{
//  printf("%s", otazka);
//  int err = scanf("%f", cislo);
//  if (err == 1)
//  {
//    if (!isspace(getchar()))
//      err = 0;
//  }
//  return err == 1;
//}
//
//void chyba8(void)
//{
//  float promenna;
//  if (!ciselnaOtazka("Zadej desetinne cislo (+ Enter): ", &promenna))
//    fprintf(stderr, "Pri cteni hodnoty nastala chyba");
//  else
//    printf("Zadal jsi hodnotu %g.\n", promenna);
//
//  // Varování
//  // main.c:179:19: warning: format '%f' expects argument of type 'float *', but argument 2 has type 'float **' [-Wformat=]
//  // Na řádku 179 se podle formátovací značky '%f' očekává argument typu 'float *', ale druhý argument je typu 'float **'.
//  //
//  // Vysvětlení
//  // Argumenty jednoduchých typů se do funkce scanf předávají odkazem. V tomto případě je mechanicky použit
//  // referenční operátor & aniž by byl brán ohled na použitou proměnnou cislo. Zde se očekává argument typu
//  // 'float *' a proměnná cislo už tohoto typu je, protože je sama deklarována jako parametr funkce ciselnaOtazka.
//  // Použití operátoru & vrátí ukazatel na proměnnou cislo, což už je ukazatel, vrátí to tedy dvojitý ukazatel 'float **'.
//  // Program se sice přeloží, ale nefunguje správně. Do argumentu promenna (resp. cislo) se načtená hodnota nikdy nezapíše.
//  //
//  // Řešení
//  // V tomto případě stačí na řádku 179 operátor & nepoužívat. Očekává se tam 'float *', parametr cislo je typu 'float *',
//  // proto tam stačí dosadit proměnnou cislo bez jakéhokoliv dalšího operátoru.
//  // Nepoužívejte konstrukce mechanicky. Programování není čarování pomocí zaklínadel...
//}

/*****************************/
/*** Tipy pro hledání chyb ***/
/*****************************/
//1. Omez vytváření chyb -- pracuj inkrementálně:
//   -- Piš kód po malých kouscích (1--2 řádky, 1--2 příkazy).
//   -- Hned překládej.
//   -- Když překladač ohlásí chybu nebo varování, problém bude nejpravděpodobněji
//      právě v tom malém kousku kódu.
//   -- Když poprvé překládáš až po napsání celého programu, strávíš opravami více času,
//      než samotným prvotním psaním.
//
//2. Sleduj pozorně chybová hlášení překladače.
//   -- Pozor! Místo výskytu chyby často není místem, kde problém vznikl.
//   -- Hledej problém i před místem detekce chyby.
//
//3. Sleduj i varování překladače.
//   -- Varování je téměř vždy příznak budoucí chyby.
//   -- Některé konstrukce jsou v C/C++ legální, ale překladač v nich dokáže
//      poznat špatné návyky a potenciální problémy. Neignoruj jeho rady.
//
//4. Hlášení vždy řeš shora dolů.
//   -- První zjištěný problém může generovat další problémy, takže další hlášení
//      mohou být falešná.
//   -- Vyřešením prvního problému často dojde k vyřešení několika ostatních.
//
//5. Pokud překladač nehlásí chybu, ale přesto program nefunguje správně:
//   -- Hledej problém od funkce main, jinak zase můžeš řešit problémy tam, kde žádné nejsou.
//   -- Používej debugger!
//   -- Krokuj program od začátku a sleduj hodnoty proměnných.
//   -- Pokud víš, že chyba vzniká až při nějaké specifické situaci, používej podmíněné zarážky.
//   -- Sleduj, jestli se nějaký kód neukrývá za okrajem obrazovky.
//   -- Pozor na netisknutelné, neviditelné, unicode znaky. Zvláště při kopírování kódu z webu
//      se snadno stane, že místo mínus se vloží unicode znak pro dlouhou pomlčku.
//
//6. Testuj i s nepředpokládanými vstupy.
//   -- Co když uživatel zadá místo čísla text?
//   -- Co když zadá záporné číslo tam, kde čekáš jen kladné?
//   -- Co když jsou v souboru chybné hodnoty?
//   -- Co když zadaná cesta k souboru je špatně?
//   -- Co když soubor nejde otevřít?
//
//7. Největším nepřítelem tvého programu jsi ty!
//   -- Pojisti se proti vlastní hlouposti.
//   -- Používej sebeobranné techniky (proti vlastní hlouposti a zapomětlivosti).
//   -- Piš dokumentační komentáře ještě před psaním kódu. Ujasni si a pak popiš, co chceš,
//      aby tvůj kód dělal.
//   -- Testuj návratové hodnoty, chybové kódy, výjimky atd.
//   -- Nespoléhej na to, že v budoucnu svůj kód použiješ správně.
//   -- Testuj hodnoty parametrů svých funkcí.
//   -- Ošetřuj chyby, vracej chybové kódy, vyhazuj výjimky apod. Dej uživateli své funkce vědět,
//      že je něco špatně.
//   -- Chybová hlášení tiskni až ve funkci main, ne v místě výskytu chyby. Místo toho vracej
//      chybový kód. Tisk hlášení je k ničemu, když po něm dovolíš, aby program pokračoval a havaroval.


int main()
{
  printf("Projekt Chybová hlášení\nDavid Martinek, 2019\n");
//  chyba1();
//  chyba2();
//  chyba3();
//  chyba4();
//  chyba5();
//  chyba6();
//  chyba7();
//  chyba8();
  return 0;
}

