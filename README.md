                                                                  DOCUMENTATIE

Am realizat 3 clase pentru acest proiect: clasa mama Airline si cele doua clase copil: Continental Flights, respectiv Intercontinental Flights.
      
      1.	Clasa Airline
              -	am realizat set-eri si get-eri pentru toate atributele clasei: name, location, personal si budget, cu scopul obtinerii valorilor lor
              -	am supraincarcat operatorii de citire si afisare
              -	am supraincarcat operatorul de atribuire, pentru ca, in lipsa lui, compilatorul va genera o copie membru cu membru a datelor clasei
              -	am realizat o functie display() care ma va ajuta, mai tarziu, sa afisez, pe langa atributele claselor copil, si atributele din clasa mama
              -	tot in clasa mama am declarant un atribut de tip protected ca sa poata sa fie vizibila in clasele copil caruia i-am dat o valoare de tip double
              -	functia virtual ma va ajuta, ulterior, la realizarea downcast-ului, intrucat imi asigura polimorfismul

       2.	 Clasa Continental_Flights
              -	am realizat set-eri si get-eri pentru toate atributele clasei: id_continental, number_continental, number_passengers_continental si             cabin_crew_continental, cu scopul obtinerii valorilor lor si, pe langa asta, am si mostenit atributele din clasa mama 
              -	am supraincarcat operatorii de citire si afisare
              -	am supraincarcat operatorul de atribuire pentru clasa copil, apeland, initial, opearatorul de atribuire din clasa mama, intrucat trebuie mostenite  atributele de acolo
              -	am realizat o functie display_c() care apeleaza functia display() din clasa mama care afiseaza atributele de acolo si, dupa aceea, afiseaza atributele clasei Continental_Flights
              -	am facut o functie statica upkeep_passengers_continental() care imi calculeaza pretul platit in medie de companie pentru fiecare pasager pentru fiecare zbor continental

        3.	Clasa Intercontinental_Flights
              -	am realizat set-eri si get-eri pentru toate atributele clasei: id_intercontinental, number_intercontinental, number_passengers_intercontinental si cabin_crew_intercontinental, cu scopul obtinerii valorilor lor si, pe langa asta, am si mostenit atributele din clasa mama 
              -	am supraincarcat operatorii de citire si afisare
              -	am supraincarcat operatorul de atribuire pentru clasa copil, apeland, initial, opearatorul de atribuire din clasa mama, intrucat trebuie mostenite atributele de acolo
              -	am realizat o functie display_i() care apeleaza functia display() din clasa mama care afiseaza atributele de acolo si, dupa aceea, afiseaza atributele clasei Intercontinental_Flights
              -	am facut o functie statica upkeep_passengers_intercontinental() care imi calculeaza pretul platit in medie de companie pentru fiecare pasager pentru fiecare zbor intercontinental
              
In int main() am citit n obiecte, le-am memorat si le-am afisat, compania fiind deja predefinita, am testat atribuirea cu doua zboruri random din cele memorate, din fiecare clasa copil, am testa functiile statice, am realizat upcasting-ul, downcasting-ul si try catch si meniul interactiv.

									                                                                                              Iftimi Ruxandra, 134
