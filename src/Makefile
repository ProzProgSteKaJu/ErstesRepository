# Online-Ressourcen zu Makefiles:
# http://www.gnu.org/software/make/
# http://www.gnu.org/software/make/manual/
# http://de.wikipedia.org/wiki/Make
# Das Programm "Make" wird zur Automatisierung des Kompilationsvorgangs 
# eingesetzt. Es bestimmt automatisch welche Teile eines grossen Programmes 
# (bestehend aus mehreren  Quelldateien) neu uebersetzt werden muessen und 
# fuehrt die entsprechenden Befehle aus. Es kann in Verbindung mit jeder 
# Programmiersprache genutzt werden, sofern der Kompiler von der Konsole 
# aufgerufen werden kann. Make nutzt eine Datei namens "makefile", um das
# ausfuehrbare Programm zu erzeugen. In einem Makefile stehen die Regeln, 
# welche Quelltextdatei der Kompiler zu welcher Objektdatei uebersetzt und 
# welche Objektdatei der Linker mit welchen anderen Objektdateien zum
# ausfuehrbaren Programm binden soll. Dabei beachtet Make die Zeitstempel
# der Dateien und initiiert die Uebersetzung einer Quelldatei nur dann, wenn 
# das Aenderungsdatum der zu uebersetzten Datei aelter ist als das der Quell- 
# bzw. Objektdateien von denen sie abhaengt. Bei grossen Softwarepaketen
# bringt das den Vorteil, dass bei kleinen Aenderungen der Quelltextdateien
# nur einige wenige davon abhaengige Objektdateien neu kompiliert werden 
# und nicht das gesamte Programmpaket. 
# Das Makefile spielt hierbei eine zentrale Rolle. Die Datei beschreibt mit
# Hilfe spezieller Regeln alle Abhaengigkeiten unter Quelltext- und Source-
# dateien des Programms. Das Erstellen einer Objektdatei wird im Makefile
# als Ziel (Target) bezeichnet. 
# In einem Makefile koennen auch Konstanten definiert werden. Diese nutzt 
# man des oefteren zur Angabe des erwuenschten Kompilers, der Kompilerflags, 
# Pfade zu speziellen Systembibliotheken usw.. Konstanten werden meistens
# gross geschrieben. Der Name fuer die Konstanten ist "frei" waehlbar, es gibt 
# jedoch einige Empfehlungen, an die man sich halten sollte, wenn andere 
# Entwickler sich schnell in dem makefile zurecht finden sollen. Auf den
# Inhalt der Konstanten greift man durch $(Konstantenname) zu. 
# Beispiel einer Regel im makefile:
#-------------------------------------------------------------------------
#     TName: Quelltextdatei1 Quelltextdatei2 ... Objektdatei1 ...
#            Befehl(e) zur Uebersetzung
#-------------------------------------------------------------------------
# Die erste Zeile stellt die Abhaengigkeitsliste fuer das Target "TName" dar. 
# Wenn das Ziel "TName" erstellt werden soll, wird die Abhaengigkeitsliste
# betrachtet. Ist eine der Dateien der Liste juenger als die Datei "TName",
# so wird (werden) der (die) Befehl(e) der nachfolgenden Zeile ausgefuehrt.
# Wichtig ist, dass die Befehlszeile mit einem Tabulator anfangen soll.
# Der Uebersetzungsprozess wird einfach durch Aufruf von make (Target) aus
# der Konsole angestossen. Make liest das Makefile im aktuellen Verzeichnis
# und befolgt die dort definierten Regeln zur Uebersetzung des angegebenen
# Targets. Wird an Make kein Target uebergeben, so wird das erste Target im 
# makefile genommen. 
# Definition der Konstanten CC die den Namen des Kompilers enthaelt. 
CC = gcc 
# Fuer Kompilerflags wird meistens die Konstante CFLAGS definiert
CFLAGS = -Wall -Wextra -ansi -pedantic
# erstes Target (braucht nicht explizit angegeben werden)
prefixcalc: ppn_calculator.o rpn_eval.o prefix2postfix.o
	$(CC) -o prefixcalc ppn_calculator.o rpn_eval.o prefix2postfix.o -lm
# zweites Target 
ppn_calculator.o: ppn_calculator.c rpn_eval.h prefix2postfix.h
	$(CC) $(CFLAGS) -c ppn_calculator.c
# drittes Target 
rpn_eval.o: rpn_eval.c rpn_eval.h
	$(CC) $(CFLAGS) -c rpn_eval.c
# viertes Target 
prefix2postfix.o: prefix2postfix.c prefix2postfix.h
	$(CC) $(CFLAGS) -c prefix2postfix.c


