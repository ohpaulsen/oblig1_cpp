Oblig 1, C++ Vår 2013
----------------------------------------------------

#Blackjack i et casino-rammeverk
Du skal implementere et spillrammeverk, som kan benyttes til å implementere flere typer spill, med flere typer grensesnitt, og både menneselige spillere og maskinspillere. Du skal foreølpig kun implementere blackjack, men ha mulighet for andre spill i bakhodet.

##De viktigste reglene
Blackjack er et kortspill som handler om å få så nært "21" som mulig, uten å gå over. Det fungerer som følger:
0. Alle billedkort (Konge, dame, knekt) er verdt 10, Ess (A) er verdt 1 eller 11 - det som gir "best" hånd. Andre kort er verdt sitt "tall" (også 10)
1. Spilleren satser penger. I våre blackjack-regler er det ingen grense.
2. Spilleren får to kort av "dealer", og dealer får selv to kort. Kun ett av dealers kort er synlige for spilleren.
3. Hvis spilleren får 21 på første hånd (10 og A), er det "Blackjack". Spiller vinner da 1.5 ganger sin innsats (3:2)
4. Spilleren må nå velge om hun/han vil ha et kort til (HIT), eller ikke (STAND)
5. Hvis spilleren står (STAND) på under 21, må dealer avgjøre sin hånd. 
   - Dealer må "HIT" på alt under 17, og "STAND" på 17 og høyere.
   - Hvis dealer går over 21 (BUST) vinner spilleren 1:1 av sin innsats
   - Hvis dealer kommer nærmere 21 enn spilleren uten å gå over, vinner dealer spillerens innsats
6. Dersom dealer og spiller ender på det samme, heter det "Push" - da vinner ingen. Dette gjelder også dersom det ble blackjack.

Det finnes to regler til, "DOUBLE" og "SPLIT". Disse kan vente med.

##Det som skal programmeres
- For hver klasse class_*.h, skal du skrive implementasjonen class_*.cpp
- Tanken med hver klasse er beskrevet i documentation.md, og blackjack-spillet skal implementeres i henhold til blackjack-reglene, i rulebook.md
- I tillegg skal du skrive blackjack.cpp, som skal gjøre følgende:
  - Starte et blackjackspill med en spiller og en dealer
  - Spilleren skal hente alle beslutninger fra brukeren, via standard input

##Rapport
- Det skal foreligge en liten rapport, i .md-format (som dette). Der skal du:
  - Beskrive implementasjonen, gjerne trekke frem ting du synes var interessant eller vanskelig
  - Diskutere et alternativt programdesign, hvis du har et, eller idéer til et. Er det noe du ville gjort anderledes? Noe du hadde gort anderledes, som gir fordeler eller ulemper?
  - Du kan legge ved din alternative implementasjon, i en mappe kalt "alt" i rotmappen i ditt "repository.
  - Rapporten skal hete "rapport.md" og ligge i rotmappen i ditt "repository"
  
##Hvordan du blir vurdert
- Hver klasse vil bli vurdert for seg, og gi et antall poeng
- blackjack.cpp blir også vurdert for seg
- Helheten blir vurdert og gir et antall poeng

