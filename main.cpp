#include <iostream>
#include <cstdlib>
#include <time.h>

///AIRLINE
class Airline{
public:
    Airline(std::string, std::string, unsigned int, unsigned int);
    Airline(const Airline&);
    std::string get_name();
    std::string get_location();
    unsigned int get_personal();
    unsigned int get_budget();
    void set_name(std::string);
    void set_location(std::string);
    void set_personal(unsigned int);
    void set_budget(unsigned int);
    friend std::istream& operator >> (std::istream& stream, Airline& airline);
    friend std::ostream& operator << (std::ostream& stream, Airline& airline);
    Airline operator = (Airline);
    void display();     //functie care ma ajuta sa afisez datele din clasa mama si pe care o voi apela si in clasele copil
    virtual~Airline(){};    //ma va ajuta la downcast si asigura polimorfismul
protected:
    static double upkeep;   //am facut-o protected ca sa pot sa o accesez in clasele copil
private:
    std::string name;
    std::string location;
    unsigned int personal;
    unsigned int budget;
};

Airline::Airline(std::string name="Null airline", std::string location="Null location", unsigned int personal=0, unsigned int budget=0){
    this->name=name;
    this->location=location;
    this->personal=personal;
    this->budget=budget;
}

Airline::Airline(const Airline& airline){
    name=airline.name;
    location=airline.location;
    personal=airline.personal;
    budget=airline.budget;
}

std::string Airline::get_name(){
    return this->name;
}

std::string Airline::get_location(){
    return this->location;
}

unsigned int Airline::get_personal(){
    return this->personal;
}

unsigned int Airline::get_budget(){
    return this->budget;
}

void Airline::set_name(std::string){
    this->name=name;
}

void Airline::set_location(std::string){
    this->location=location;
}

void Airline::set_personal(unsigned int){
    this->personal=personal;
}

void Airline::set_budget(unsigned int){
    this->budget=budget;
}

std::istream& operator >> (std::istream& stream, Airline& airline) {
    stream >> airline.name >> airline.location >> airline.personal >> airline.budget;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Airline& airline){
    stream << airline.name <<" "<< airline.location <<" "<< airline.personal <<" "<< airline.budget<<'\n';
    return stream;
}

Airline Airline::operator = (Airline airline){
    name=airline.name;
    location=airline.location;
    personal=airline.personal;
    budget=airline.budget;
    return (*this);
}

void Airline::display(){
    std::cout<<name<<" "<<location<<" "<<personal<<" "<<budget<<'\n';
}

double Airline::upkeep=10;


///CONTINENTAL FLIGHTS
class Continental_Flights: public Airline {
public:
    Continental_Flights(std::string, std::string, unsigned int, unsigned int, std::string, unsigned int, unsigned int, unsigned int);
    Continental_Flights (const Continental_Flights&);
    std::string getIdc();
    unsigned int get_nc();
    unsigned int get_npc();
    unsigned int get_ccc();
    void setIdc(std::string);
    void set_nc(unsigned int);
    void set_npc(unsigned int);
    void set_ccc(unsigned int);
    friend std::istream& operator >> (std::istream& stream, Continental_Flights& continental_flights);
    friend std::ostream& operator << (std::ostream& stream, Continental_Flights& continental_flights);
    Continental_Flights operator = (Continental_Flights&);
    void display_c();
    static double upkeep_passengers_continental(unsigned int);
private:
    std::string id_continental;
    unsigned int number_continental;
    unsigned int number_passengers_continental;
    unsigned int cabin_crew_continental;
};

Continental_Flights::Continental_Flights(std::string name="Null airline", std::string location="Null location", unsigned int personal=0, unsigned int budget=0, std::string id_continental="null", unsigned int number_continental=0, unsigned int number_passengers_continental=0, unsigned int cabin_crew_continental=0):Airline(name, location, personal, budget){
    this->id_continental = id_continental;
    this->number_continental = number_continental;
    this->number_passengers_continental = number_passengers_continental;
    this->cabin_crew_continental = cabin_crew_continental;
}

Continental_Flights::Continental_Flights(const Continental_Flights& continental_flights) {
    id_continental = continental_flights.id_continental;
    number_continental = continental_flights.number_continental;
    number_passengers_continental = continental_flights.number_passengers_continental;
    cabin_crew_continental = continental_flights.cabin_crew_continental;
}

std::string Continental_Flights::getIdc() {
    return this->id_continental;
}

unsigned int Continental_Flights::get_nc(){
    return this->number_continental;
}

unsigned int Continental_Flights::get_npc(){
    return this->number_passengers_continental;
}

unsigned int Continental_Flights::get_ccc(){
    return this->cabin_crew_continental;
}

void Continental_Flights::setIdc(std::string) {
    this->id_continental = id_continental;
}

void Continental_Flights::set_nc(unsigned int){
    this->number_continental=number_continental;
}

void Continental_Flights::set_npc(unsigned int){
    this->number_passengers_continental=number_passengers_continental;
}

void Continental_Flights::set_ccc(unsigned int){
    this->cabin_crew_continental=cabin_crew_continental;
}

std::istream& operator >> (std::istream& stream, Continental_Flights& continental_flights) {
    stream>>continental_flights.id_continental >> continental_flights.number_continental >> continental_flights.number_passengers_continental >> continental_flights.cabin_crew_continental;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Continental_Flights&  continental_flights){
    stream<<continental_flights.id_continental <<" "<< continental_flights.number_continental <<" "<< continental_flights.number_passengers_continental<< " " << continental_flights.cabin_crew_continental<<'\n';
    return stream;
}

Continental_Flights Continental_Flights::operator = (Continental_Flights& continental_flights){
    (*this).Airline::operator = (continental_flights);
    id_continental = continental_flights.id_continental;
    number_continental = continental_flights.number_continental;
    number_passengers_continental = continental_flights.number_passengers_continental;
    cabin_crew_continental = continental_flights.cabin_crew_continental;
    return(*this);
}

void Continental_Flights::display_c(){
    Airline::display();
    std::cout<<id_continental<<" "<<number_continental<<" "<<number_passengers_continental<<" "<<cabin_crew_continental<<'\n';
}

double Continental_Flights::upkeep_passengers_continental(unsigned int number_passengers_continental){
    return upkeep*number_passengers_continental;
}


///INTERCONTINENTAL FLIGHTS
class Intercontinental_Flights: public Airline {
public:
    Intercontinental_Flights(std::string, std::string, unsigned int, unsigned int, std::string, unsigned int, unsigned int, unsigned int );
    Intercontinental_Flights (const Intercontinental_Flights&);
    std::string getIdi();
    unsigned int get_ni();
    unsigned int get_npi();
    unsigned int get_cci();
    void setIdi(std::string);
    void set_ni(unsigned int);
    void set_npi(unsigned int);
    void set_cci(unsigned int);
    friend std::istream& operator >> (std::istream& stream, Intercontinental_Flights& continental_flights);
    friend std::ostream& operator << (std::ostream& stream, Intercontinental_Flights& continental_flights);
    Intercontinental_Flights operator = (Intercontinental_Flights&);
    void display_i();
    static double upkeep_passengers_intercontinental(unsigned int);
private:
    std::string id_intercontinental;
    unsigned int number_intercontinental;
    unsigned int number_passengers_intercontinental;
    unsigned int cabin_crew_intercontinental;
};

Intercontinental_Flights::Intercontinental_Flights(std::string name="Null airline", std::string location="Null location", unsigned int personal=0, unsigned int budget=0, std::string id_intercontinental="null", unsigned int number_intercontinental=0, unsigned int number_passengers_intercontinental=0, unsigned int cabin_crew_intercontinental=0):Airline(name, location, personal, budget){
    this->id_intercontinental = id_intercontinental;
    this->number_intercontinental = number_intercontinental;
    this->number_passengers_intercontinental = number_passengers_intercontinental;
    this->cabin_crew_intercontinental = cabin_crew_intercontinental;
}

Intercontinental_Flights::Intercontinental_Flights(const Intercontinental_Flights& intercontinental_flights) {
    id_intercontinental = intercontinental_flights.id_intercontinental;
    number_intercontinental = intercontinental_flights.number_intercontinental;
    number_passengers_intercontinental = intercontinental_flights.number_passengers_intercontinental;
    cabin_crew_intercontinental = intercontinental_flights.cabin_crew_intercontinental;
}

std::string Intercontinental_Flights::getIdi() {
    return this->id_intercontinental;
}

unsigned int Intercontinental_Flights::get_ni(){
    return this->number_intercontinental;
}

unsigned int Intercontinental_Flights::get_npi(){
    return this->number_passengers_intercontinental;
}

unsigned int Intercontinental_Flights::get_cci(){
    return this->cabin_crew_intercontinental;
}

void Intercontinental_Flights::setIdi(std::string) {
    this->id_intercontinental = id_intercontinental;
}

void Intercontinental_Flights::set_ni(unsigned int){
    this->number_intercontinental=number_intercontinental;
}

void Intercontinental_Flights::set_npi(unsigned int){
    this->number_passengers_intercontinental=number_passengers_intercontinental;
}

void Intercontinental_Flights::set_cci(unsigned int){
    this->cabin_crew_intercontinental=cabin_crew_intercontinental;
}

std::istream& operator >> (std::istream& stream, Intercontinental_Flights& intercontinental_flights) {
    stream >> intercontinental_flights.id_intercontinental >> intercontinental_flights.number_intercontinental >> intercontinental_flights.number_passengers_intercontinental >>intercontinental_flights.cabin_crew_intercontinental;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Intercontinental_Flights&  intercontinental_flights){
    stream<<intercontinental_flights.id_intercontinental <<" "<< intercontinental_flights.number_intercontinental <<" "<< intercontinental_flights.number_passengers_intercontinental<<" "<< intercontinental_flights.cabin_crew_intercontinental<<'\n';
    return stream;
}

Intercontinental_Flights Intercontinental_Flights::operator = (Intercontinental_Flights& intercontinental_flights){
    (*this).Airline::operator = (intercontinental_flights);
    id_intercontinental = intercontinental_flights.id_intercontinental;
    number_intercontinental = intercontinental_flights.number_intercontinental;
    number_passengers_intercontinental = intercontinental_flights.number_passengers_intercontinental;
    cabin_crew_intercontinental = intercontinental_flights.cabin_crew_intercontinental;
    return(*this);
}

void Intercontinental_Flights::display_i(){
    Airline::display();
    std::cout<<id_intercontinental<<" "<<number_intercontinental<<" "<<number_passengers_intercontinental<<" "<<cabin_crew_intercontinental<<'\n';
}

double Intercontinental_Flights::upkeep_passengers_intercontinental(unsigned int number_passengers_intercontinental){
    return upkeep*number_passengers_intercontinental;
}

int main(int argc, const char * argv[]) {

    ///citirea a n obiecte + memorare + afisare

    Airline airline("KLM", "Amsterdam", 100, 100000);
    std::cout<<"Airline: \n"<<airline<<'\n';

    int i,n;
    std::cin>>n;
    Continental_Flights *continental_flights=new Continental_Flights[n];
    for(i=0;i<n;i++)
        std::cin>>continental_flights[i];
    std::cout<<"\n\n";
    for(i=0;i<n;i++)
        std::cout<<continental_flights[i];
    std::cout<<"\n\n\n\n";

    Intercontinental_Flights *intercontinental_flights=new Intercontinental_Flights[n];
    for(i=0;i<n;i++)
        std::cin>>intercontinental_flights[i];
    for(i=0;i<n;i++)
        std::cout<<intercontinental_flights[i];
    std::cout<<"\n\n\n\n";


    ///operator atribuire

    int no1, no2;
    no1=rand()%n;
    no2=rand()%n;
    std::cout<<no1<<' '<<no2<<'\n';
    continental_flights[no1]=continental_flights[no2];
    std::cout<<continental_flights[no1];
    std::cout<<"\n\n\n\n";

    intercontinental_flights[no2]=intercontinental_flights[no1];
    std::cout<<intercontinental_flights[no2];
    std::cout<<"\n\n\n\n";


    ///variabila + functie statica continental

    std::cout<<continental_flights[no2].upkeep_passengers_continental(continental_flights[no2].get_npc())<<'\n';


    ///variabila + functie statica intercontinental

    std::cout<<intercontinental_flights[no1].upkeep_passengers_intercontinental(intercontinental_flights[no1].get_npi())<<'\n';

    std::cout<<"\n\n\n\n";


    ///upcast
    int no3;
    no3=rand()%n;
    std::cout<<no3<<'\n';
    Airline *air=new Continental_Flights(continental_flights[no3]);

    ///downcasting
    try {
        Continental_Flights* f1=dynamic_cast<Continental_Flights*>(air);
        std::cout<<*f1<<'\n';
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
    }
    std::cout<<"\n\n\n\n";

    ///upcast
    int no4;
    no4=rand()%n;
    std::cout<<no4<<'\n';
    Airline *air1=new Intercontinental_Flights(intercontinental_flights[no4]);

    ///downcasting
    try {
        Intercontinental_Flights* f2=dynamic_cast<Intercontinental_Flights*>(air1);
        std::cout<<*f2<<'\n';
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
    }
    std::cout<<"\n\n\n\n";


    ///meniu interactiv

    int choice,j;
    bool var = true;
    while (var != false) {
        std::cout << "*****\n\n";
        std::cout << " 1 - Welcome to the page!\n";
        std::cout << " 2 - Choose your destination \n";
        std::cout << " 3 - Europe\n";
        std::cout << " 4 - North America\n";
        std::cout << " 5 - South America\n";
        std::cout << " 6 - Asia\n";
        std::cout << " 7 - Africa\n";
        std::cout << " 8 - Australia\n";
        std::cout << " 9 - Antarctica\n";
        std::cout << " 10 - Help!\n";
        std::cout << " 11 - Exit\n\n";
        std::cout << "Enter your choice and press return: ";

        std::cin >> choice;
        std::cout<< "\n\n";

        switch (choice)
        {
            case 1:
                std::cout << "Let's plan a flight!\n\n\n\n";
                break;

            case 2:
                std::cout << "Choose your destination!\n\n\n\n";
                break;

            case 3:
                j=rand()%n;
                std::cout << "What are you choosing: Eiffel Tower, Colosseum or Tower Bridge?\n\n";
                std::cout << "Your flight:\n"<< continental_flights[j] << "\n\n\n\n";
                break;

            case 4:
                j=rand()%n;
                std::cout << "Do you want to live your American dream?\n\n";
                std::cout << "Your flight:\n" << intercontinental_flights[j] << "\n\n\n\n";
                break;

            case 5:
                j=rand()%n;
                std::cout << "Latino is ALWAYS a good idea!\n\n";
                std::cout << "Your flight:\n" << intercontinental_flights[j] << "\n\n\n\n";
                break;

            case 6:
                j=rand()%n;
                std::cout << "Mixing cultures...lovely!\n\n";
                std::cout << "Your flight:\n" << intercontinental_flights[j] << "\n\n\n\n";
                break;

            case 7:
                j=rand()%n;
                std::cout << "Safari trip?...sounds good to me!\n\n";
                std::cout << "Your flight:\n" << intercontinental_flights[j] << "\n\n\n\n";
                break;

            case 8:
                j=rand()%n;
                std::cout << "Kangaroos are waiting for you! \n\n";
                std::cout << "Your flight:\n" << intercontinental_flights[j] << "\n\n\n\n";
                break;

            case 9:
                j=rand()%n;
                std::cout << "Pack your warm clothes...you're gonna be a penguin!\n\n";
                std::cout << "Your flight:\n" << intercontinental_flights[j] << "\n\n\n\n";
                break;

            case 10:
                std::cout << "What can I do for you?\n\n\n\n";
                break;

            case 11:
                std::cout << "Thank you for choosing us!\n\n\n\n";
                var=false;
                break;

            default:
                std::cout << "Not a Valid Choice. \n\n";
                std::cout << "Choose again!\n\n";
                break;
        }
}
    return 0;
}


///exemplu de input
/*
    8
kl123 123 23 3
kl124 124 30 9
kl125 125 15 3
kl126 126 20 6
kl127 127 19 7
kl128 128 21 5
kl129 129 28 10
kl130 130 27 6

kl131 131 33 13
kl132 132 30 8
kl133 133 40 14
kl134 134 45 18
kl135 135 34 9
kl136 136 50 15
kl137 137 28 10
kl138 138 29 7
*/
