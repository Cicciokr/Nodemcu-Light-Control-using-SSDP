Progetto "LightControl" di Francesco Pantisano realizzato utilizzando "Plant" di Diomede Mazzone con la collaborazione di Fabio Z Tessitore (@FabioZTessitore).

Tag: NodeJS, ExpressJS, HTML 5, client/server, Simple Service Discovery Protocol (SSDP)

Licenza: GPL 3.0 o successive

#LIGHTCONTROL

questo pacchetto ha una parte di script Arduino da poter lanciare su tutte le vostre NodeMcu e una parte applicativa realizzata con nodejs che gestisce le periferiche ed interagisce con loro utilizzando il protocollo SSDP che trovo veramente interessante per l'aspetto iot, evita di utilizzare/conoscere gli ip delle schede, ogni device connessione in rete espone una propria scheda identificativa, tramite le quale potete riconoscerlo e quindi interagirci.

SSDP.setHTTPPort(80);
SSDP.setName("NodemcuLightOne");
SSDP.setModelName("nodemcu");
SSDP.setDeviceType("upnp:nodemculight");

Il client nodejs è in ascolto sulla porta 3000.
Il device nodemcu viene interrogato sulla porta 80.


##NodeMCU 

per configurarlo bisogna prima scaricare i driver
https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers e poi, per comodita', abbiamo utilizzato l'ide di Arduino, debitamente onfigurato così come indicato nelle numerose guide on line.

Per installare il mio script su nodemcu ho utilizzato Arduino IDE, se avete bisogno di maggiori informazioni contattatemi pure.
https://www.arduino.cc/en/Main/Software

##Node.js

va installato su una macchina e messo in ascolto sulla porta 3000, così come indicato nel pacchetto. riferimenti https://nodejs.org/en/docs/

##INSTALLAZIONE
per avviare il server bisogna procedere nel seguente modo:

1. Scaricare e installare la versione idonea di node ed npm: https://nodejs.org/it/download/
2. installare il framework express tramite il gestore dei pacchetti: npm intall express

è possibile anche configurare tutto tramite npm install, a patto che il file package.json sia aggiornato nelle dipendenze necessarie.
 

a questo punto si potrà avviare il server:

node app.js

Da notare che su sistemi Debian Node viene avviato con nodejs app.js, in quanto node è un altro applicativo presente sui repository.
