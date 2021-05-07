Link repo originale : https://gitlab.di.unimi.it/matteo.cucchi1/arduino-robotic-hand


# Arduino Robotic Hand

Il progetto consiste nella creazione di una mano meccanica in grado di mimare i movimenti compiuti dalla mano dell'utilizzatore mediante l'utilizzo di un guanto munito di sensori in grado di captare la flessione di ogni dito.

# Hardware utilizzato
  - Arduino Uno
  - 5 sensori di flessione (4 x 4,5", 1 x 2,2")
  - 5 resistenze 10KΩ
  - 5 servomotori MG995
  - 2 connettori RJ45 (femmina)
  - 1 cavo RJ45
  - 1 breadboard
  - 1 basetta millefori

# Guanto
Il guanto è un insieme di sensori che mi permettono di capire il livello di flessione di un dito.
I sensori sono alimentati direttamente da Arduino. 
Il segnale viene letto analogicamente, quindi assume un valore che può variare da 0 a 1023. 
Questo dato viene elaborato da Arduino e passato ai motori.
##### Sensori

I sensori che ho usato sono i SEN-08606 e sono dei semplici sensori di flessione.
Il sensore è basato su elementi resistivi di carbonio.
Quando il sensore è curvato, la resistenza varia in riferimento al raggio di curvatura, maggiore è il raggio, maggiore è il valore di resistenza (sensore non curvato: ~15 kohm, curvato di 90°: ~40 kohm).
Grazie a questa caratteristica a seconda di quanto è flesso la tensione in uscita sarà più o meno bassa rendendo possibile stabilire il livello di flessione.

![guanto](/uploads/225d7b0a84a2d9d20933dccba90eac3b/guanto.png)

##### Lettura Sensori Guanto

LetturaSensoriGuanto è uno sketch che permette di visualizzare sul plotter seriale l'andamento dei valori letti dai sensori.
Mi è stato molto utile per verificare il corretto funzionamento del guanto.

![Testsensori-1](/uploads/a379f550c2ea32a55ba6817b73e36e91/Testsensori-1.m4v)

Lo sketch MinMaxSensori l'ho utilizzato per capire quali erano i valori massimi e minimi che i sensori potevano raggiungere.
In questo modo ho potuto sfruttare al meglio la funzione map che trasforma il valore letto da ogni sensore nella posizione 
che il motore deve assumere per replicare la flessione del dito.

![Minmaxsensori-1](/uploads/b9c0303e31daf4fa9cd01ee6b1213ba5/Minmaxsensori-1.m4v)
Visualizzo graficamente valore massimo e valore minimo di ogni sensore.

Dopo aver chiuso e aperto la mano fino al massimo un paio di volte basta passare al monitor seriale e copiare una riga, che avrà la seguete struttura:
```
Pollice:826,Indice:758,Medio:662,Anulare:731,Mignolo:733,maxPollice:846,maxIndice:896,maxMedio:854,maxAnulare:864,maxMignolo:872,minPollice:748,minIndice:614,minMedio:512,minAnulare:558,minMignolo:559
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
```
da qui è possibile ricavare i valori massimi e minimi che ogni sensore andrà ad assumere, questi valori sono utilizzati nel programma completo.

# Mano meccanica
I modelli che ho usato in questo progetto li ho presi da un progetto francese open-source chiamato InMoov, che da a disposizione modelli da stampare con un’apposita stampante di tutto il corpo umano. Il progetto ha inizio nel 2012 e pubblica come primo pezzo quello della mano. Per poter stampare tutti i pezzi è necessaria una stampante che abbia il piatto di almeno 12cm x  12cm x 12cm.
##### Motori
Nell’avambraccio sono inseriti 5 servomotori MG995 che, tendendo un filo, sono in grado di piegare le dita. I servomotori compiono una rotazione di 180°, regolata da Arduino, simulando i muscoli che tirano i tendini.

I motori sono collegati ai pin 3,5,6,9,10.
Devono essere collegati a questi pin perchè sono dei pin pwm.
I servomotori sono alimentati da un alimentatore a tensione variabile, che ho impostato ad erogare una tensione di 6V e una corrente di 2,5A.
Non è possibile utilizzare l'alimentazione interna di Arduino in quanto anche se la tensione di lavoro dei motori va da 4.8V a 7.2V (quindi l'output a 5V di arduino risulterebbe sufficiente) la corrente assorbita da questi è molto maggiore di quella erogata da Arduino. 
Il segnale viene dato da Arduino, che passa un angolo di rotazione, compreso tra 0 e 180°, riprodotto poi dai motori.

![mano](/uploads/71e252b8385ecd27b68f1f834087e1d2/mano.png)

![Testmano-1](/uploads/44a962c2254aa9a21fdc9dcab01441a3/Testmano-1.m4v)

# Autori
 ##### Matteo Cucchi
 
# License
This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the LICENSE.md file for details
