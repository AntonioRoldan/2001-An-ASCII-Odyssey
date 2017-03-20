#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <unistd.h> //Import the sleep function (only works with linux compiler)
#include <thread>
#include <chrono>
#include <functional>
#include <future>

using namespace std::chrono;

class Star
{

    friend class Spaceship;

    private:

        float _starssurface;
        int _starsheat;
        int _starsradius;

    protected:
        char _startype;
        int _starsradiation;
        int _starsgravitationalforce;

    public:

        int random_number_generator();

        int randRange(int, int);

        int getstarsheat();

        int getstarsradiation();

        int getstartype();

        void display_stars_data(std::string);

        void define_type_of_star();

        void stars_generator();

        Star();
};

int Star::random_number_generator(){
    int n;
    n = (rand()%4 + 1);
    return n;
}


void Star::display_stars_data(std::string star_name){
    std::string startype;
    if(_startype == 1){
        startype = "Neutron star";
    }
    else if(_startype == 2){
        startype = "Blue giant";
    }
    else if(_startype == 3){
        startype = "Yellow star";
    }
    else if(_startype == 4){
        startype = "Red giant";
    }
    std::cout<<"|--"<<star_name<<"--|"<<"\n"
    <<"Type of star: "<<startype<<"\n"
    <<"Star's temperature: "<<_starsheat<<" celcius"<<"\n"
    <<"Star's surface :"<<_starssurface<<" millions of square km"<<"\n"
    <<"Star's radiaton level :"<<_starsradiation<<std::endl;
}

int Star::randRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

void Star::define_type_of_star()
{

    _starsradius = randRange(1,800); //In millions of kilometers
    if(_starsradius >= 1 && _starsradius <= 250)
        _startype = 1;
    else if(_starsradius >= 260 && _starsradius <= 500)
        _startype = 2;
    else if(_starsradius >= 510 && _starsradius <= 750)
        _startype = 3;
    else if(_starsradius >= 760 && _starsradius <= 800)
        _startype = 4;
    _starssurface = randRange(100000, 1000000);

}

void Star::stars_generator()
{

        define_type_of_star();
            //We are going to start by defining the stars heat, this is set in relation to its radius (which in turn determines the kind of star)
        if(_startype == 1)
            _starsheat = randRange(100000, 200000 ); //We are defining the heat of a white dwarf here in celcius
        else if(_startype == 2)
            _starsheat = randRange(10000, 20000); //We are defining the heat of a blue giant here in celcius
        else if(_startype == 3)
            _starsheat = randRange(5000, 7000); //We are defining the heat of a yellow star here in celcius
        else if(_startype == 4)
            _starsheat = randRange(1000, 5000); //We are defining the heat of a red giant here in celcius

            //We proceed with the radiation definition, this is set in relation to its heat

        if(_starsheat >= 3000 && _starsheat <= 4000)
            _starsradiation = randRange(8, 10); //We are defining the radiation of a white dwarf here

        else if(_starsheat >= 2000 && _starsheat <= 3000)
            _starsradiation = randRange(6, 7); //We are defining the radiation of a blue giant here

        else if(_starsheat >= 1000 && _starsheat <= 2000)
            _starsradiation = randRange(3, 5); //We are defining the radiation of a yellow star here
        else if(_starsheat >= 0 && _starsheat <= 1000)
            _starsradiation = randRange(2, 3); //We are defining the radiation of a red giant here
}
Star::Star(){

    _starsradiation = randRange(1, 10);

    define_type_of_star();

    stars_generator();

}

class Planet: public Star
{
    friend class Spaceship;

    private:
        int _planetsradius;
        int _gravitationalforce;
        int _planetstemperature;
        float _planetssurface;
        char _planettype;
        bool _rockyorgas;
        bool _defeated = false;
        std::string _atmospherecomposition;
        bool _breathableatmosphere;
        bool _magneticprotection;
        int _magneticfieldintensity;
        int _magneticfieldvsradiation;
        int _distancefromstar;
        bool _habitable;
        bool _potentiallyhabitable = false;
        int _rotationangle; //From 90 to 180
        std::string _planetname;
        int _diamonds; //Diamonds is given as a currency automatically
        int _mercury; //It is given in megatons of fuel
        int _gas; //It is also given in megatons, along with antimatter it will power the WARP drive
        int _metal; //Metal can be classified at will to define the weaponery, space ships and
        int _bacteria; //Bacteria will be classified by the game itself in order to determine what kind of bacteria there is
        int _humans; //Humans can be classified at will to define the crew
        int _antimatter; //Mixed with the gas you can power the WARP drive
        int _protozoo; //Amount of protozoo to strengthen the army
        int _staphillococcus; //
        int _pseudomona;





    public:


        int random_number_generator();

        int random_percentage_generator();

        int randRangep(int, int);

        int gethabitability();

        bool getpotentialhabitability();

        char getplanettype();

        int getmetal();

        int getdiamonds();

        int getmercury();

        int gethumans();

        std::vector<int> getbacteriae();

        int getgas();

        int gettemperature();

        int getplanetsdistance();

        int getmagneticfieldvsradiation();

        bool getbreathableatmosphere();

        int getstaphilloccocus();

        int getdistancefromstar();

        int getprotozoo();

        int getpseudomona();

        void turn_into_habitable();

        void setmetal(int);

        void setdiamonds(int);

        void setmercury(int);

        void sethumans(int);

        void setbacteriae(int, int, int);

        void setgas(int);

        void defeat();

        bool getdefeat();

        std::string getplanetsname();

        bool element_finder();

        void define_type_of_planet();

        void define_planetstemperature();

        float determine_orbit_eccentricity();

        void define_atmosphere_composition();

        void define_planets_orbit();

        void determine_magnetic_field();

        void determine_type_of_bacteria();

        void determine_amount_of_resources();

        void determine_habitability();

        void display_planets_data(std::string, int);

        Planet();
};
int Planet::random_number_generator(){
        int n;
        n = (rand()%4 + 1);
        return n;
    }

int Planet::random_percentage_generator(){
    int n;
    n = (rand()%100 + 1);
    return n;
    }

int Planet::randRangep(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

int Planet::gethabitability(){
    return _habitable;
}

int Planet::getplanetsdistance(){
    return _distancefromstar;
}

bool Planet::getbreathableatmosphere(){
    return _breathableatmosphere;
}

int Planet::getmetal(){
    return _metal;
}

int Planet::gettemperature(){
    return _planetstemperature;
}

int Planet::getdiamonds(){
    return _diamonds;
}

int Planet::getmercury(){
    return _mercury;
}

int Planet::gethumans(){
    return _humans;
}


int Planet::getstaphilloccocus(){
    return _staphillococcus;
}

int Planet::getprotozoo(){
    return _protozoo;
}

int Planet::getpseudomona(){
    return _pseudomona;
}

std::vector<int> Planet::getbacteriae(){
    std::vector<int> bacteriae = {_protozoo, _staphillococcus, _pseudomona};
    return bacteriae;
}

int Planet::getgas(){
    return _gas;
}

int Planet::getmagneticfieldvsradiation(){
    return _magneticfieldvsradiation;
}

void Planet::turn_into_habitable(){
    _habitable = true;
}

void Planet::setmetal(int n){
    _metal += n;
}

void Planet::setdiamonds(int n){
    _diamonds += n;
}

void Planet::setmercury(int n){
    _mercury += n;
}

void Planet::sethumans(int n){
    _humans += n;
}

void Planet::setgas(int n){
    _gas += n;
}

void Planet::defeat(){
    _defeated = true;
}

bool Planet::getdefeat(){
    return _defeated;
}

void Planet::setbacteriae(int x, int y, int z){
    _protozoo += x;
    _staphillococcus += y;
    _pseudomona += z;
}

void Planet::define_type_of_planet()
{
    int random_event = random_number_generator();
    //It will randomly predetermine the radius of our planet
    if(random_event == 0){
        _planetsradius = randRangep(10000, 30000); //This should be size of a small rocky planet like pluto
        _rockyorgas = true;
    }
    else if(random_event == 1){
        _planetsradius = randRangep(10000, 30000); //This should be size of a small rocky planet like pluto
        _rockyorgas = true;
    }
    else if(random_event == 2){
        _planetsradius = randRangep(40000, 100000); //This should be size of a normal rocky planet like earth
        _rockyorgas = true;
    }
    else if(random_event == 3){
        _planetsradius = randRangep(60000, 170000); //This should be the size of a gigantic rocky planet
        _rockyorgas = true;
    }

    else if(random_event == 4){
        _planetsradius = randRangep(60000, 170000); //This is the expected size of a gas giant
        _rockyorgas = false;

    }


    float pi = 3.14;
    _planetssurface = (4*pi*_planetsradius) / 3;
}


void Planet::define_planetstemperature()
{
    int _distancefromstar = randRange(100, 4000);
    define_type_of_planet();
    if(_startype == 1){
        if(_rockyorgas){
                if(_distancefromstar <= 1300){
                    _planetstemperature = randRange(1000, 1500);
                    _planettype = 2; //Diamond planet you can use it to trade with other civilisations and make money
                }
                else if(_distancefromstar >= 1300){
                    _planetstemperature = randRange(500, 1000); //Just for the sake of realism
                    _planettype = 1; //It will be considered a lava planet, you can get metal for weapons and technology
                }
            }
            else
                _planettype = 6; //It is a gas planet, can be used to power light-speed travel mode
                _planetstemperature = randRange(200, 1000);
    } //If the star is a white dwarf

    else if(_startype == 2){ //If the star is a blue giant
        if(_rockyorgas){
            if(_distancefromstar <= 1300){
                _planetstemperature = randRange(1000, 1500);
                _planettype = 1; //It will be considered a lava planet, you can get metal for weapons and technology
            }
            else if(_distancefromstar >= 1300){
                _planetstemperature = randRange(200, 350);
                _planettype = 2; // Diamond planet you can use it to purchase points
            }
        }
        else
            _planettype = 6;
            _planetstemperature = randRange(200, 1000); //It is a gas planet, can be used to power light-speed travel mode
    }


    else if(_startype == 3){ //If it is a yellow star
        if(_rockyorgas){
            if(_distancefromstar <= 1300){
                _planetstemperature = randRange(100, 500);
                _planettype = 3; //Mercury planet can be used to extract minerals and process fuel
            } else if(_distancefromstar >= 1300){
                _planetstemperature = randRange(20, 40);
                _planettype = 4; //This planet is likely to be habitable if it has people you can increase your space ship crew to colonise other planets depending how advanced their civilisation is
            }
        } else
            _planettype = 6;
            _planetstemperature = randRange(200, 1000); //It is a gas planet, can be used to power light-speed travel mode

    }
    else if(_startype == 4){ //If it is a red giant
        if(_rockyorgas){
            if(_distancefromstar <= 1300){
                _planetstemperature = randRange(20, 40);
                _planettype = 4; //This planet is likely to be habitable if it has people you can increase your space ship crew t
            } else if(_distancefromstar >= 1300){
                _planetstemperature = randRange(-500, 0);
                _planettype = 5; //This is a frozen planet, you can extract water molecules and bacteria to perform genetical modifications on your enslaved humans
            }
        }
        else
            _planettype = 6;
            _planetstemperature = randRange(0, 1000); //It is a gas planet, can be used to power light-speed travel mode

    }

}

char Planet::getplanettype(){
    return _planettype;
}

bool Planet::getpotentialhabitability(){
    return _potentiallyhabitable;
}

void Planet::define_atmosphere_composition(){
    if(_planettype == 1)
        _atmospherecomposition = "Carbon dioxide";
    else if(_planettype == 2)
        _atmospherecomposition ="Cosmic rays";
    else if(_planettype == 3)
        _atmospherecomposition ="Cyanide";
    else if(_planettype == 4)
        _atmospherecomposition ="Oxygen";
    else if(_planettype == 5)
        _atmospherecomposition = "Kriptonite";
    else if(_planettype == 6)
        _atmospherecomposition = "Nitrogen";

}

float Planet::determine_orbit_eccentricity(){
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

void Planet::determine_magnetic_field(){
    if(_breathableatmosphere){
        int random_constant = randRange(1, 2);
        switch(random_constant){

            case 1: _magneticfieldintensity = randRange(5, 7);
                if(_magneticfieldintensity >= _starsradiation)
                    _magneticprotection = true;
                else if(_magneticfieldintensity <= _starsradiation);
                    _magneticprotection = false;
                    _magneticfieldvsradiation = randRange(3, 5); //This variable will let the user the amount of resources that will have to be put into the creation of a magnetic field

            case 2: _magneticfieldintensity = randRange(0, 5);
                    if(_magneticfieldintensity >= _starsradiation)
                        _magneticprotection = true;
                    else if(_magneticfieldintensity <= _starsradiation)
                        _magneticprotection = false;
                        _magneticfieldvsradiation =  randRange(5, 7); //This variable will let the user know the amount of technology that will be needed for a stronger magnetic field
        }
    }
    else
        ;
}


void Planet::determine_habitability(){
    if(_planettype == 4){
        if(_magneticprotection && _breathableatmosphere){
        _habitable = true;
        _humans = randRange(1000000, 7000000);
        }

        else if(_breathableatmosphere){
            _habitable = false;
            _potentiallyhabitable = true;
            }
        else
            _habitable = false;
        }
    else
        _habitable = false;
}

void Planet::determine_amount_of_resources(){

    switch(_planettype){

        case 1: _metal = randRange(1000, 10000); //measured in kg

        case 2: _diamonds = randRange(1000, 10000); //measured in kg

        case 3: _mercury = randRange(1000, 10000); //Given in megatons

        case 5: _protozoo = randRange(10000, 60000);
                _staphillococcus = randRange(10000, 60000);
                _pseudomona = randRange(10000, 60000);
                //Given in thousands of millions

        case 6: _gas = randRange(1000, 10000); //Given in  megatons
    }
}


std::string Planet::getplanetsname(){
    return _planetname;
}


void Planet::display_planets_data(std::string planetsname, int distancefromstar){
    std::string planettype;
    if(_planettype == 1)
        planettype = "Lava rivers and lakes";
    else if(_planettype == 2)
        planettype = "Diamond surface";
    else if(_planettype == 3)
        planettype = "Mercury oceans";
    else if(_planettype == 4){
        if(_habitable){
            planettype = "Fully habitable planet";
        }
        else if(!_habitable){
            if(_breathableatmosphere){
                planettype ="Potentially habitable planet";
            }
            else
                planettype = "Post apocaliptyc planet full of nuclear radiation";
        }
    }
    else if(_planettype == 5){
        planettype = "Frozen planet, contains ice and primitive uni-cellular forms of life";
    }
    else if(_planettype == 6){
        planettype = "Gas giant";
    }
    _distancefromstar = distancefromstar; //This way we will be able to access the variable with a getter before inserting it in a database
    std::cout<<"|--"<<planetsname<<"--|"<<"\n"
    <<"Planet type: "<< planettype<<"\n"
    <<"Average temperature: "<<_planetstemperature<<" Celcius"<<"\n"
    <<"Surface in square km: "<<_planetssurface<<"\n"
    <<"Atmosphere's composition: "<<_atmospherecomposition<<"\n"
    <<"Intensity of magnetic field: "<<_magneticfieldintensity<<"\n"
    <<"Distance from its star: "<<distancefromstar<<" million kilometers"<<"\n"
    <<"Orbit's eccentricity: "<<determine_orbit_eccentricity()<<"\n"
    <<"Rotation angle: "<<randRange(90, 180)<<std::endl;
    if(_planettype == 1)
        std::cout<<"Amount of metal to be processed: "<<_metal<<" kg"<<std::endl;
    else if(_planettype == 2)
        std::cout<<"Amount of diamonds: "<<_diamonds<<" kg"<<std::endl;
    else if(_planettype == 3)
        std::cout<<"Amount of mercury: "<<_mercury<<" megatons"<<std::endl;
    else if(_planettype == 4){
        if(_habitable)
            std::cout<<"Alien population: "<<_humans<<" specimens"<<std::endl;
        else if(!_habitable){
            if(_breathableatmosphere)
                std::cout<<"Can be turned into a habitable planet by intensifying its magnetic field by "<<_magneticfieldvsradiation<<" magneto units"<<std::endl;
            else
                std::cout<<"Post apocalyptic planet full of radiation, it was destroyed by nukes approximately 10000000 years ago, nothing can be done with it"<<std::endl;
        }
    }
    else if(_planettype == 5){
        std::cout<<"These are the bacteriae contained in our deposits along with the different types "<<"\n"
        <<"Protozoo: "<<_protozoo<<"\n"
        <<"Staphilococcus: "<<_staphillococcus<<"\n"
        <<"Pseudomonae: "<<_pseudomona<<std::endl;
    }
    else if(_planettype == 6){
        planettype = "Gas giant";
        std::cout<<"This is the amount of fuel you can use to power your WARP drive: "<<_gas<<std::endl;
    }
}


Planet::Planet(){
 //PLANET CLASS METHOD

    define_planetstemperature();

    define_atmosphere_composition();

    determine_magnetic_field();

    if(_magneticfieldintensity > 10){
        _magneticfieldintensity = randRange(1, 10);
    }

    determine_amount_of_resources();

    determine_habitability();
}


class Spaceship
{
    static std::vector<std::string> planetnames;
    static std::vector<std::string> starnames;
    static std::vector<std::string> planetnamesbuffer;
    static std::vector<std::string> starnamesbuffer;
    static int starsnumber;
    static int outcome_calculator(long, int, bool, int);
    static void casualties(long, int, bool, int);
    static void battle_processor(std::vector<std::string>, long, long, long, long, int, int, int);
    static long _drones;
    static long _armors;
    static long _missiles;
    static long _bombs;
    static long _metalamount;
    static int _slaveslevel;
    static long _specimens;
    static void battle_reports(int, long, int, long, int, int, bool, int);
    static void battle_preparation(long, long, long, long, long, long);
    static void damage_calculation(std::vector<std::string>, std::string, int, float, int, long, int, int);
    static int _soldierslevel;
    static int randRange(int, int);
    static void metallurgy(int);
    static int efficiency_calculation(int, int, bool);
    static float soldiers_fate(float);
    static long random_victim_assignment(long);
    static bool turn_assignment(int);
    static void AI(std::vector<int>,  int, long, int, int, int, int);
    static void decision_maker(int, long, long, long, long, float, float, bool);
    static void balance_counter(std::vector<std::string>, bool, bool);
    static void check_victory(std::vector<std::string>, long, long, long, bool, int);
    static void update_energy(int, int, int);
    static void update_morale(std::vector<std::string>, int, int);
    static void battle_end(int, std::string);

    private:

        int _diamondsamount = 1234257463; //This is the amount that will be spent on manufacturing processes
        int _fuelcapacity = 134135; //This will be used to refill fuel tanks
        int _WARPdrive = 10000; //This is going to be used to power the interstellar travelling mode
        int _antimatterweapon; //Planetdestroyer
        int _soldiers = 12335; //Soldiers to subjugate other civilisations
        int _scientists = 12334; //Scientists to perfom experiments on subyugated civilisations
        int _slaves = 12345; //Slaves are going to be used to extract minerals from other planets
        int _protozoolevels = 0; //In theory only WARP drive and fuel should be set
        int _staphilococcuslevels = 200;
        int _pseudomonalevels = 0;
        int _evolutionexpressaccelerator = 0;
        int _soldierspoints = 0;
        int _scientistspoints = 0;
        int _slavespoints = 5;
        int _scientistslevel = 5;
        int _points;
        int _overalllevel;


    public:

        void civilisation_interaction(int, int);
        void planet_interaction();
        std::vector<Star> stars_interaction();
        void interstellar_travel();
        int cabin();
        void classify_specimens();
        void assign_points(int, std::string);
        void laboratory();
        int genetical_modification(int, std::vector<char>, std::vector<int>);
        void setlevel(int, std::string, int, int, int, int, int, bool, std::vector<int>, std::vector<int>);
        void purchasepoints(int);
        void pointstransaction(int);
        std::string define_stars_name();
        std::string define_planets_name();
        void planet_destroyer(int);
        void civilisation_history(std::string, std::string, int);
        void surrender_treaty(std::string, std::string);
        void assign_troops(long, int, int);
        void refill_vector(std::string);
        void to_solar_system();
        void display_planets_database();
        void generate_solar_data_base(std::vector<Planet>);
        void display_colonies();
        std::string show_title();
        void read_story();
        void save_game(); //DATABASE
        void game_over(); //DATABASE

};

std::vector<std::string> Spaceship::planetnames = {"Lok", "Erinar", "Golrath", "Imrooso", "Maryx Minor", "Qat Chrystac", "RZ7-6113-23", "Taspir III", "55 Cancri e", "Zachayphus", "Iewhoutis", "Foclillon", "Weplov", "Reter", "Crevugan", "Obloethea", "Ethuetera", "Asnypso", "Ciocury", "Glabuwei", "Spiri 29N4", "Grypso Y1J", "Slequhiri", "Tasloaclite", "Dragatan", "Sethurilia", "Hadrion", "Geuliv","Celaris", "Adrara", "Upruna", "Fraxetis", "Cuprillon", "Woilara", "Stuzaria", "Xiotune", "Hafloth", "Pludaphus", "Glarvis 10", "Vespin", "Oclore", "Oaphus", "Clugonus", "Veskaiter", "Godriuturn"};

std::vector<std::string> Spaceship::planetnamesbuffer;

std::vector<std::string> Spaceship::starnames = {"Acamar", "Adhafera", "Kornephoros", "Hoedus II", "Miaplacidus", "Procyon", "Pleione", "Rastaban", "Rotanev", "Sarir", "Cassiopeia", "Sterope", "Tabit", "Veritate", "Zaurak", "Sceptrum", "Sadachbia", "Rukbat", "Cygnus", "Capricorni", "Rotanev", "Ceasar 43", "Zeus", "Colossus", "Dranicus", "Rimbokhan", "Tiranuslae", "Criptilocus"};

std::vector<std::string> Spaceship::starnamesbuffer;

long Spaceship::_metalamount = 150000;

long Spaceship::_drones = 100000;

long Spaceship::_armors = 10000;

long Spaceship::_bombs = 10000;

long Spaceship:: _missiles = 10000;

long Spaceship::_specimens = 19482109;

int Spaceship::_slaveslevel;

int Spaceship::starsnumber; //IMPORTANT We might need to create a function that updates the value using the database
//The reason for this is that once the program is initialised again the variable will also be initialised and set to zero!
int Spaceship::_soldierslevel = 0;

int Spaceship::randRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}


std::string Spaceship::define_stars_name(){
    auto name = starnames.begin() + (rand()%starnames.size());
    starnamesbuffer.emplace_back(*name);
    starnames.erase(name);
    return *name;
}


std::vector<Star> Spaceship::stars_interaction(){
        if(starnames.size() <= 25){
            refill_vector("Stars");
        }
        std::string starsname;
        int stars_number = randRange(5, 15);
        std::vector<Star> stars(stars_number);
        std::cout<<"\n"
        <<"\n"
        <<"<<<STARS>>>"<<"\n"
        <<"\n"
        <<"\n"<<std::endl;
        for(int i = 0; i < stars_number; i++){
            starsname = define_stars_name();
            std::cout<<"\n"
            <<"Type "<<i + 1<<" to explore this solar system"<<"\n"
            <<"\n"<<std::endl;
            stars[i].display_stars_data(starsname);
            std::cout<<std::endl;
        }
        return stars;
}

std::string Spaceship::define_planets_name(){

    auto it = planetnames.begin() + (rand()%planetnames.size());
    planetnamesbuffer.emplace_back(*it);
    planetnames.erase(it);
    return *it;
}

std::vector<int> ORgate(bool protozoo, bool staphilloccocus, bool pseudomona){
    std::vector<bool> booleanvalues;
    std::vector<int> missingindeces;
    booleanvalues.push_back(protozoo);
    booleanvalues.push_back(staphilloccocus);
    booleanvalues.push_back(pseudomona);
    for(int i = 0; i < 3; i++){
        if(booleanvalues[i] == true){
               missingindeces.push_back(i + 1);
            }
        else
            missingindeces.push_back(0);
    }
    return missingindeces;
}

int Spaceship::genetical_modification(int choice, std::vector<char> planetsavailable, std::vector<int> planetstemperatures){
    int desired_amount;
    std::string atmosphere;
    std::string desired_atmosphere;
    int temperature;
    int slaves_number = 0;
    int radiation;
    int slaves_temperature_resistance = 0;
    std::string slaves_atmosphere_resistance;
    int slaves_radiation_resistance = 0;
    if(planetsavailable[choice - 1] == 1){
        temperature = randRange(300, 1000);
        atmosphere = "Carbon dioxide";
    }
    else if(planetsavailable[choice - 1] == 2){
        temperature = randRange(300, 1000);
        atmosphere = "Cosmic rays";
    }
    else if(planetsavailable[choice - 1] == 3){
        temperature = randRange(300, 1000);
        atmosphere = "Cyanide";
    }
    else if(planetsavailable[choice - 1] == 5){
        temperature = randRange(300, 1000);
        atmosphere = "Kriptonite";
    }
    else if(planetsavailable[choice - 1] == 6){
        temperature = randRange(300, 1000);
        atmosphere = "Nitrogen";
    }
    radiation = rand() % 4 + 1;
    planetsavailable.empty();
    std::cout<<"We will have to adapt to the following conditions"<<"\n"
    <<"Temperature: "<<temperature<<"\n"
    <<"Atmosphere: "<<atmosphere<<"\n"
    <<"Radiation: "<<radiation<<"\n"
    <<"Let's go to the laboratory to modify our specimens accordingly"<<"\n"
    <<"\n"
    <<"<<<LABORATORY>>>"<<"\n"
    <<"\n"
    <<"This is how many specimens we could obtain in our expeditions my lord"<<"\n"
    <<_specimens<<"\n"
    <<"Please choose how many you would like to send to this planet"<<std::endl;
    std::cin>>desired_amount;
    if(desired_amount > _specimens){
        std::cout<<"My lord, I must inform you that we still do not have that many specimens left"<<std::endl;
    }
    else if(desired_amount <= _specimens){
        _specimens -= desired_amount;
        slaves_number = desired_amount;
        std::cout<<"The following number of specimens are ready to become your slaves my lord: "<<desired_amount<<"\n"
        <<"Please, choose what variables you want to modify"<<"\n"
        <<"What is the temperature level your slaves will have to resist?"<<std::endl;
        std::cin>>desired_amount;
        slaves_temperature_resistance += desired_amount;
        std::cout<<std::endl;
        std::cout<<"Perfect my lord, now just give us the level of radiation they will be exposed to"<<std::endl;
        std::cin>>desired_amount;
        slaves_radiation_resistance = desired_amount;
        std::cout<<"Now we just need to know the atmosphere composition to perform our experiments my lord"<<std::endl;
        std::getline(std::cin, desired_atmosphere);
        std::cout<<"This is your legion of slaves"<<"\n"
        <<"1. Number: "<<slaves_number<<"\n"
        <<"2. Temperature resistance: "<<slaves_temperature_resistance<<"\n"
        <<"3. Radiation resistance: "<<slaves_radiation_resistance<<"\n"
        <<"4. Atmosphere resistance: "<<atmosphere<<"\n"
        <<"\n"
        <<"We are ready to send our slaves and extract the minerals my lord!"<<std::endl;
        slaves_radiation_resistance = 0;
        slaves_temperature_resistance = 0;

    }
    return slaves_number;

}



void Spaceship::civilisation_history(std::string social_structure, std::string civilisationname, int enemies_level){
//Reads the civilisations' stories from text files
    if(social_structure == "Techno fascist regime"){
        std::cout<<civilisationname<<"\n"
        <<"Level: "<<enemies_level<<std::endl;
        std::ifstream Technofascist;
        std::string line;
        Technofascist.open("Technofascistregime.txt");
        if( !Technofascist.is_open() ){
            std::cout<<"Could not open file"<<"\n";
        }
        while(getline(Technofascist, line)){
            std::cout<<line<<std::endl;
        }
        Technofascist.close();
    }
    else if(social_structure == "Liberal democracy"){
        std::cout<<civilisationname<<"\n"
        <<"Level: "<<enemies_level<<std::endl;
        std::ifstream Liberaldemocracy;
        std::string line;
        Liberaldemocracy.open("Liberaldemocraticregime.txt");
        if( !Liberaldemocracy.is_open()){
            std::cout<<"Could not open file"<<"\n";
        }
        while(getline(Liberaldemocracy, line)){
            std::cout<<line<<std::endl;
        }
        Liberaldemocracy.close();
    }
    else if(social_structure == "Techno-utopian anarchy"){
        std::cout<<civilisationname<<"\n"
        <<"Level: "<<enemies_level<<std::endl;
        std::ifstream Technoutopian;
        std::string line;
        Technoutopian.open("Technoutopiananarchistregime.txt");
        if( !Technoutopian.is_open()){
            std::cout<<"Could not open file"<<std::endl;
        }
        while(getline(Technoutopian, line)){
            std::cout<<line<<std::endl;
        }
        Technoutopian.close();
    }
    else if(social_structure == "AI-ruled planetary nation"){
        std::cout<<civilisationname<<"\n"
        <<"Level: "<<enemies_level<<std::endl;
        std::ifstream AIruled;
        std::string line;
        AIruled.open("AI-ruledregime.txt");
        if(! AIruled.is_open()){
            std::cout<<"Could not open file"<<std::endl;
        }
        while(getline(AIruled, line)){
            std::cout<<line<<std::endl;
        }
        AIruled.close();
    }
}


void Spaceship::surrender_treaty(std::string social_structure, std::string civilisationname){
//Reads the surrender treaties from text files
    if(social_structure == "Techno fascist regime"){
        ;
    }
    else if(social_structure == "Liberal democracy"){
        ;
    }
    else if(social_structure == "Techno utopian anarchy"){
        ;
    }
    else if(social_structure == "AI-ruled planetary nation"){
        ;
    }
}



void Spaceship::metallurgy(int counter){
    int choice;
    int amount;
    while(1){
        std::cout<<"\n"
        <<"\n"
        <<"<--METALLURGY LABORATORY-->"<<"\n"
        <<"\n"
        <<"Metal: "<<_metalamount<<"\n"
        <<"\n"
        <<"Specimens: "<<_specimens<<"\n"
        <<"1. Drones factory"<<"\n"
        <<"2. Cyborg's armors and weapons"<<"\n"
        <<"3. Bombs\n"
        <<"4. Missiles\n"
        <<"5. Exit" <<std::endl;
        std::cin>>choice;
    }
        switch(choice){

            case 1:
                    std::cout<<std::endl;
                    std::cout<<"Tell us how many drones you want to create my lord!"<<"\n"
                    <<"Drone's price: 17"<<"\n"
                    <<"Metal: "<<_metalamount<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < 25 * amount){
                        while(1){
                            if(_metalamount > amount * 25)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>amount;
                        }
                        usleep(efficiency_calculation(amount, 1000, false));
                        _metalamount -= amount * 25;
                        _drones += amount;
                        if(_specimens < _drones){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _drones -= amount;
                            break;
                        }
                        else if(_specimens >= _drones){
                            _specimens -= _drones;
                            std::cout<<"Our drones will fly the enemy's sky and cause the greatest fear in its soul.."<<std::endl;
                            break;
                        }
                    }
                    else if(amount == 0)
                        break;
                    else if(_metalamount > amount * 25){
                        usleep(efficiency_calculation(amount, randRange(1, 2), false));
                        _metalamount -= amount * 25;
                        _drones += amount;
                        if(_specimens < _drones){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _drones -= amount;
                            break;
                        }
                        else if(_specimens >= _drones){
                            _specimens -= _drones;
                            std::cout<<"Our drones will fly the enemy's sky and cause the greatest fear in its soul.."<<std::endl;
                            break;
                        }

                    }
                    break;


            case 2:
                    std::cout<<std::endl;
                    std::cout<<"Metal: "<<_metalamount<<"\n"
                    <<"Armor's price: "<<"17"<<"\n"
                    <<"\n"<<std::endl;
                    std::cout<<"How many armors and weapons?"<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < amount * 17){
                        while(1){
                            if(_metalamount < amount * 17)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>choice;
                        }
                        usleep(efficiency_calculation(amount, 1000, false));
                        _metalamount -= amount * 17;
                        _armors += amount;
                        if(_specimens < _armors){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _armors -= amount;
                            break;
                        }
                        else if(_specimens >= _armors){
                            _specimens -= _armors;
                            std::cout<<"Oh yes my lord, this new armors are worth dying for!"<<std::endl;
                            break;
                        }

                    else if(choice == 0)
                        break;
                    else if(_metalamount > amount * 17){
                        usleep(efficiency_calculation(amount, 1000, false));
                        _metalamount -= amount * 17;
                        _armors += amount;
                        if(_specimens < _armors){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _armors -= amount;
                            break;
                        }
                        else if(_specimens >= _armors){
                            _specimens -= _armors;
                            std::cout<<"Oh yes my lord, this new armors are worth dying for!"<<std::endl;
                            break;
                        }
                    }
                    break;

            case 3:
                    std::cout<<std::endl;
                    std::cout<<"Metal: "<<_metalamount<<"\n"
                    <<"Bomb's price: "<<"10"<<"\n"
                    <<"\n"<<std::endl;
                    std::cout<<"How many bombs?"<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < amount * 10){
                        while(1){
                            if(_metalamount < amount * 10)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>amount;
                        }
                        efficiency_calculation(amount, 1000, false);
                        _metalamount -= amount * 10;
                    _bombs += amount;
                    }
                    else if(amount == 0)
                        break;
                    else if(_metalamount > amount * 10){
                        efficiency_calculation(amount, 1000, false);
                        _metalamount -= amount * 10;
                        _bombs += amount;
                        }

                    break;
            case 4:
                    std::cout<<std::endl;
                    std::cout<<"Metal: "<<_metalamount<<"\n"
                    <<"Missile's price: "<<"10"<<"\n"
                    <<"\n"<<std::endl;
                    std::cout<<"How many missiles?"<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < amount * 10){
                        while(1){
                            if(_metalamount < amount * 10)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>choice;
                        }
                        _metalamount -= amount * 10;
                        _missiles += amount;
                    }
                    else if(choice == 0)
                        break;
                    else if(_metalamount > amount * 10){
                        usleep(efficiency_calculation(amount, randRange(1, 2), false));
                        _metalamount -= amount * 10;
                        _missiles += amount;
                    }
                    break;

            case 5: break;
        }
        break;
    }
}

void Spaceship::damage_calculation(std::vector<std::string> balance, std::string attack_type, int amount, float hp, int level, long civilians, int morale, int counter){
    int _soldierslevel;
    if(level == 5)
        _soldierslevel = 5;
    float total_damage;
    long targets;
    int random_civilians_casualties = randRange(1000, 10000);
    int morale_effect;
    if(attack_type == "Civilians attack"){
        for(int i = 0; i < amount; i++){
            civilians -= 1;
        }
        morale_effect = efficiency_calculation(amount, randRange(1, 2), true);
        morale -= morale_effect;
    }
    else if(attack_type == "Cyborgs attack"){
        total_damage = amount * 50 * level - morale;
        targets = std::ceil(total_damage/hp);
        civilians -= random_civilians_casualties;
        if(turn_assignment(counter))
            battle_processor(balance, 0, targets, 0, targets, level, _soldierslevel, counter);
        else
            battle_processor(balance, 0, targets, 0, 0, level, _soldierslevel, counter);
    }
    else if(attack_type == "Missiles attack"){
        total_damage = amount * 50 * level - morale;
        targets = std::ceil(total_damage/hp);
        civilians -= random_civilians_casualties;
        if(turn_assignment(counter))
            battle_processor(balance, targets, 0, targets, 0, level, _soldierslevel, counter);
        else
            battle_processor(balance, targets, 0, targets, 0, level, _soldierslevel, counter);
    }
    else if(attack_type == "Drone bombardment"){
        total_damage = amount * 50 * level - morale;
        targets = std::ceil(total_damage/hp);
        civilians -= random_civilians_casualties;
        if(turn_assignment(counter))
            battle_processor(balance, targets, 0, 0, targets, level, _soldierslevel, counter);
        else
            battle_processor(balance, 0, targets, 0, targets, level, _soldierslevel, counter);
    }
}

bool Spaceship::turn_assignment(int counter){
    if(counter % 2)
        return false;
    else
        return true;
}

void Spaceship::decision_maker(int choice, long arsenal1, long arsenal2, long enemies_metal, long enemies_energy, float relative_difference, float marginal_loss, bool arsenal1_or_arsenal2){
//The production choice that will be passed into metallurgy
    if(arsenal1 - arsenal2 <= relative_difference){   //If the difference between both arsenals is greater than the average casualties per battle
            if(arsenal1 <= relative_difference){     //If the AI has lost more men than there are elements within the arsenal
                if(enemies_energy > 500000){        //If the AI has more than enough energy
                    if(arsenal1_or_arsenal2){       //If the AI has a specific preference for one arsenal or the other
                        choice = 1;                 //This function will also be used for missiles and bombs
                    }
                    else{
                        choice = 2;
                    }
                }
                else{
                    choice = 2; //More drones need to be produced, the metallurgy function will be called!
                }
            }
            else{                                //Since there is more of that item than there have been deaths, the ratio is good so the AI produces more of the other item
                if(enemies_energy > 500000){ //If the AI has more than enough energy
                    if(arsenal1_or_arsenal2){ //If it has a preference for one over the other because there is more of one item than the other
                        choice = 1;             //Note this decision may lead to errors in the sense it might not be the most optimal but the AI can make mistakes too
                    }                           //as long as they are controlled
                    else{
                        choice = 2;
                    }
                } //Else we don't want to waste energy so we will try to optimise by spending metal instead then energy will hopefully be updated positively in the next iteration
                if(30 > marginal_loss){  //If we have more metal than the total amount of metal we lost 30 is the average price of an item in the metallurgy laboratory
                    choice = 2;         //We can afford Drones/Cyborgs!
                }
                else{
                    choice = randRange(1, 2); //Else the AI is fucked so it will choose either one or two randomly
                }
            }
        }
        else
            if(arsenal1_or_arsenal2)
                choice = 1;
            else
                choice = 2;

}

void Spaceship::battle_end(int count, std::string final_outcome){
    //It will give the final battle reports
    //It should take deaths as a parameter as well as casualties and all the resources that have been wasted
    //The amount of battles during the war
    //It will take morale as a parameter and print a message in a tone that suits the soldiers' mood !

}

void Spaceship::balance_counter(std::vector<std::string> balance, bool end_battle, bool turn){
    int counter;
    for(int i = 0; i < balance.size(); i++){
        if(balance[i] == "Defeat")
            counter += 1;
        continue;
    }
    if(!turn){ //If it's the AI's turn
        if(counter >= balance.size()/2){
            battle_end(counter, "Victory");
            end_battle = true; //More user's defeats mean that the machine was closer to winning than the player but lacked resources
        }
        else{
            battle_end(counter, "Defeat");
            end_battle = true; //More user's victories mean that the machine was really far from a victory
        }
    }
    else{ //If it's the user's turn
        if(counter >= balance.size()/2){
            battle_end(counter, "Defeat"); //Inputs are inverted according to the turn variable
            end_battle = true;
        }
        else{
            battle_end(counter, "Victory");
            end_battle = true;
        }
    }
}

void Spaceship::check_victory(std::vector<std::string> balance, long enemy_energy, long energy, long enemy_metal, bool end_battle, int _metalamount){
    bool  turn = false; //User or AI, both require different outcome calculations
    if(!enemy_energy || !enemy_metal) //If the enemy is out of resources
        balance_counter(balance, end_battle, turn);
    turn = true; //Switch to user's turn
    if(!energy || !_metalamount) //If the user is out of resources
        balance_counter(balance, end_battle, turn);
}

void Spaceship::update_energy(int level, int energy, int morale){
    if(level < 5 && level > 5)
        energy += randRange(50, 100) + morale; //Energy will be updated in each iteration through the loop to allow for more realism
    else if(level > 10 && level < 15)
        energy += randRange(100, 150) + morale; //It will be in accordance to the level but morale can also add a bias
    else if(level > 15 &&  level < 17)
        energy += randRange(150, 200) + morale;
}

void Spaceship::update_morale(std::vector<std::string> balance, int morale, int enemy_morale){
    int count;
    for(int i = 0; i < balance.size(); i++){
        if(balance[i] == "Victory") //It can count victory or defeat, logic would just have to be inverted
            count += 1;
    }
    if(count > balance.size()/2) //If the balance is positive (more victories than defeats)
        morale += randRange(50, 100);  //We increase morale by random amount (morale has an effect on the hp)
    else
        morale -= randRange(50, 100);
        morale = std::abs(morale); //We don't want it to be negative
}

void Spaceship::AI(std::vector<int> metal_stock, int choice, long aliens, int arsenal1, int arsenal2, int enemies_metal, int enemies_energy){
    metal_stock.push_back(enemies_metal);
    std::vector<int> average_loss; //Keeps track of the average losses in order to compute marginal loss as an average
    float marginal_loss; //Marginal loss gives the AI a notion of how much metal has been lost, in terms of units
    float relative_difference;
    int total;
    std::reverse(metal_stock.begin(), metal_stock.end());
    if(metal_stock.size() == 1){
        relative_difference = aliens/3;
        marginal_loss = randRange(1, 9);
    }
    else{
        for(int i = 0; i < metal_stock.size(); i++){
        average_loss.push_back(metal_stock[i] - metal_stock[i + 1]); //Each member will be subtracted to its posterior neighbour
        }                                                               //This is to compute by how much the metal variable has been reduced
                                                                    //On an individual basis throughout the battle
        for(int i = 0; i < average_loss.size(); i++){ //We are going to compute the average;
        total = average_loss[i] + average_loss[i + 1];
        }
        marginal_loss = total/average_loss.size();
        relative_difference = aliens/3; //This variable lets the AI know how many people must join the airforce(e.g how many airplanes must be produced) or the cyborg's army
    }                                    //Given a certain amount of aliens
    if(arsenal1 > arsenal2)  //It will use drones if there are more drones than cyborgs and viceversa
        decision_maker(choice, enemies_metal, enemies_energy, arsenal1, arsenal2, relative_difference, marginal_loss, true);
        //true if the AI decides to attack with drones
    else //false if the AI decides to attack with cyborgs
        decision_maker(choice, enemies_metal, enemies_energy, arsenal1, arsenal2, relative_difference, marginal_loss, false);
}




void Spaceship::battle_preparation(long enemies_drones, long enemies_cyborgs, long enemies_level, long energy, long enemy_energy, long aliens){
    std::vector<std::string> balance;
    std::vector<int> metal_stock;
    int choice;
    int amount;
    int missiles_amount = 200000; //AI's choice of how many missiles will be dropped
    long enemies_missiles = 2000; //Amount of missiles the enemy has at disposal
    long enemies_bombs = 20000;
    long bombs_amount = 20000;
    long enemies_metal;
    int morale = 100;
    int enemy_morale = 100;
    int counter = 1;
    bool done = false;
    bool back_to_menu = false;
    bool end_battle = false;
    float enemy_cyborgs_hp = 50.0 * enemies_level + morale;
    float enemy_drones_hp = 100.0 * enemies_level + morale;
    int cyborgs_hp = 50 * 5 + morale;
    int drones_hp = 100 * 5 + morale;
    while(!end_battle){
        std::cout<<std::endl;
        if(back_to_menu)
            ;
        else
            counter += 1;
            counter % 2 ?  std::cout<<"It is the enemy's turn my lord!"<<std::endl : std::cout<<"It is your turn master!"<<std::endl;
        std::cout<<std::endl;
        check_victory(balance, enemy_energy, energy, enemies_metal, end_battle, 500000);
        update_morale(balance, morale, enemy_morale); //First we update the morale for both user and AI
        update_energy(enemies_level, enemy_energy, enemy_morale); //We update the energy for both user and AI separately (allows for code reusability)
        update_energy(5, energy, morale);
        if( turn_assignment(counter)){
             std::cout<<"<---HEADQUARTERS--->"<<"\n"
            <<"1. Cyborg attack\n"
            <<"2. Drones attack\n"
            <<"3. Metallurgy"<<std::endl;
            std::cin>>choice;
        }
        else{
            AI(metal_stock, choice , aliens, enemies_drones, enemies_cyborgs, enemies_metal, enemy_energy);
        }
        switch(choice){

            case 1:{
                    done = false;
                    while(!done){
                        if( turn_assignment(counter) ){
                            std::cout<<std::endl;
                            std::cout<<"<--CYBORG HEADQUARTERS-->\n"
                            <<"Welcome commander! we are pleased to serve you!\n"
                            <<"Tell us what to do my master\n"<<"\n"
                            <<"1. Annihilate civilians(it will have an effect on the enemy's morale,)\n"
                            <<"2. Attack enemy(reduce the enemy's army)\n"
                            <<"3  Return"<<std::endl;
                            std::cin>>choice;
                        }
                        else
                            choice = randRange(1, 2);
                        switch(choice){

                            case 1: while(1){
                                        std::cout<<std::endl;
                                        if(turn_assignment(counter)){
                                            std::cout<<"How many civilians do you want to kill my master?"<<std::endl;
                                            std::cin>>amount;
                                            while(energy < amount/2 || _armors < amount){
                                                if(_armors == 0){
                                                    std::cout<<"My lord you will need to produce more armors my lord"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<std::endl;
                                                std::cout<<"My lord these are our available resources"<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<"Armors: "<<_armors<<"\n"
                                                <<"\n"<<std::endl;
                                                std::cin>>amount;
                                            }
                                            energy -= std::floor(amount / 2.0);
                                            damage_calculation(balance, "Civilians attack", amount, 100.0, _soldierslevel, aliens, enemy_morale, counter);
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(10000, 100000);
                                                enemy_energy -= randRange(1000, 100000);
                                                std::cout<<"Civilians attack\n"<<std::endl;
                                                damage_calculation(balance, "Civilians attack", amount, 100.0, _soldierslevel, aliens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(10000, 100000);
                                                enemy_energy -= randRange(1000, 100000);
                                                std::cout<<"Civilians attack"<<std::endl;
                                                damage_calculation(balance, "Civilians attack", amount, 100.0, enemies_level, aliens, morale, counter);
                                                break;
                                            }

                                     }
                                }
                                done = true;
                                break;

                            case 2: while(1){
                                        if(turn_assignment(counter)){
                                            std::cout<<std::endl;
                                            std::cout<<"How many enemies do you want to kill my master?"<<std::endl;
                                            std::cin>>amount;
                                            while(energy < enemies_cyborgs/2 || enemies_cyborgs < amount){
                                                if(_armors == 0){
                                                    std::cout<<"My lord you will need to produce more armors"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<std::endl;
                                                std::cout<<"My lord these are our available resources"<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<"Armors: "<<_armors<<"\n"
                                                <<"\n"<<std::endl;
                                                std::cin>>amount;
                                            }
                                            energy -= std::floor(amount / 2.0);
                                            damage_calculation(balance, "Cyborgs attack", amount, enemy_cyborgs_hp, _soldierslevel, aliens, enemy_morale, counter);
                                            done = true;
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(100000, 300000);
                                                enemy_energy = randRange(10000, 250000);
                                                std::cout<<"Cyborgs attack\n"<<std::endl;
                                                damage_calculation(balance, "Cyborgs attack", amount, cyborgs_hp, enemies_level, aliens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(100000, 300000);
                                                enemy_energy = randRange(10000, 250000);
                                                std::cout<<"Cyborgs attack\n"<<std::endl;
                                                damage_calculation(balance, "Cyborgs attack", amount, cyborgs_hp, enemies_level, aliens, morale, counter);
                                                break;
                                            }
                                        }
                                    }
                                    done = true;
                                    break;
                            case 3: back_to_menu = true;
                                    done = true;
                                    break;


                        }
                    }
                    break;
                }
            case 2: done = false;
                    while(!done){
                        if(turn_assignment(counter)){
                            std::cout<<std::endl;
                            std::cout<<"<--DRONES HEADQUARTERS-->"<<"\n"
                            <<"1. Missiles (DronesvsDrones)\n"
                            <<"2. Bombardment(DronesvsCyborgs)\n"
                            <<"3. Return"<<std::endl;
                            std::cin>>choice;
                        }
                        else
                            AI(metal_stock, choice, aliens, enemies_bombs, enemies_missiles, enemies_metal, enemy_energy);

                        switch(choice){

                            case 1: while(1){
                                        std::cout<<std::endl;
                                        if(turn_assignment(counter)){
                                            std::cout<<"<--DRONES HEADQUARTERS-->"<<"\n"
                                            <<"Lord let us know how many missiles you want each drone to drop!"<<std::endl;
                                            std::cin>>missiles_amount;
                                            while(amount > _missiles || energy < missiles_amount / 2){
                                                if(_missiles == 0){
                                                    std::cout<<"My lord you will need to produce more bombs"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Missiles: "<<_missiles<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>missiles_amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Now my lord, type in the amount of drones you want to send for this attack\n"<<std::endl;
                                            std::cin>>amount;
                                            while(amount > _drones || energy < amount / 2){
                                                if(_drones == 0){
                                                    std::cout<<"My lord we will need to produce more drones"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord, this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Bombs: "<<_bombs<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Missiles: "<<_missiles<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Fantastic my lord, we will send our drones to this miserable planet!\n"
                                            <<"and take these dirty inferior beings to an intergalactic hell...\n"<<std::endl;
                                            energy -= std::floor(amount/2.0);
                                            damage_calculation(balance, "Missiles attack", amount*missiles_amount, enemy_drones_hp, _soldierslevel, aliens, enemy_morale, counter);
                                            done = true;
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(1, 40);
                                                missiles_amount = randRange(1, 40);
                                                enemies_missiles -= missiles_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Missiles attack"<<std::endl;
                                                damage_calculation(balance, "Missiles attack", amount*missiles_amount, drones_hp, 5, _specimens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(1, 40);
                                                missiles_amount = randRange(1, 40);
                                                enemies_missiles -= missiles_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Missile attack\n"<<std::endl;
                                                damage_calculation(balance, "Missiles attack", amount*missiles_amount, drones_hp, 5, _specimens, morale, counter);
                                                break;
                                            }
                                        }

                                    }
                                    done = true;
                                    break;

                            case 2: while(1){
                                         std::cout<<std::endl;
                                        if(turn_assignment(counter)){
                                            std::cout<<"<--DRONES HEADQUARTERS-->"<<"\n"
                                            <<"Lord let us know how many bombs you want each drone to drop!"<<std::endl;
                                            std::cin>>bombs_amount;
                                            while(amount > _bombs || energy < amount / 2){
                                                if(_bombs == 0){
                                                    std::cout<<"My lord you will need to produce more bombs"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Bombs: "<<_bombs<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>bombs_amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Now my lord, type in the amount of drones you want to send for this attack\n"<<std::endl;
                                            std::cin>>amount;
                                            while(amount > _drones || energy < amount / 2){
                                                if(_drones == 0){
                                                    std::cout<<"My lord you will need to produce more drones in the factory"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord, this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Bombs: "<<_bombs<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Fantastic my lord, we will send our drones to this miserable planet!\n"
                                            <<"and take these dirty inferior beings to an intergalactic hell...\n"<<std::endl;
                                            damage_calculation(balance, "Drone bombardment", amount*bombs_amount, enemy_drones_hp, enemies_level, aliens, enemy_morale, counter);
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(1, 40);
                                                bombs_amount = randRange(1, 40);
                                                enemies_bombs -= bombs_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Drone bombardment"<<std::endl;
                                                damage_calculation(balance, "Drone bombardment", amount*bombs_amount, drones_hp, 5, _specimens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(1, 40);
                                                bombs_amount = randRange(1, 40);
                                                enemies_bombs -= bombs_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Drone bombardment"<<std::endl;
                                                damage_calculation(balance, "Drone bombardment", amount*bombs_amount, drones_hp, 5, aliens, morale, counter);
                                                break;
                                            }
                                        }
                                    }
                                    done = true;
                                    break;
                            case 3: done = true;
                                    back_to_menu = true;
                                    break;

                        }
                    }
                    break;
            case 3: metallurgy(counter);
                    break;
        }
    }
}

void Spaceship::battle_reports(int warriors, long surrender_limit, int deaths, long arbitrary_stop, int adjustment, int nanoseconds, bool players_attack, int counter){
    int results;
    std::string report;
    if(turn_assignment(counter)){
        if(players_attack){
            report = "The enemy had ";
        }
        else{
            report = "My lord we had ";
        }
    }
    else if(!turn_assignment(counter)){
        if(players_attack)
            report = "The enemy had ";
        else
            report = "My lord we had ";
    }
    while(warriors >= surrender_limit){
        if (deaths > 300000){
            results = deaths;
            deaths  = 0;
            adjustment = 5;
        }
        arbitrary_stop = rand() % adjustment + deaths;
        usleep(nanoseconds);
        warriors -= 1;
        deaths += 1;
        if(deaths == arbitrary_stop){
            if(results > 0){
                std::cout<<report<<deaths + results<<" casualties"<<std::endl;
                adjustment = deaths;
            }
            else{
                std::cout<<report<<deaths<<" casualties"<<std::endl;
                adjustment = deaths;
            }
        }
    }
}

void Spaceship::casualties(long warriors, int level, bool players_attack, int counter){
    int nanoseconds = 17 - level;
    long surrender_limit;
    int deaths;
    int arbitrary_stop;
    int adjustment = 13;
    if(warriors % 2){
        surrender_limit = rand() % warriors/4; //This variable will be used for the while condition, it must not be a float!
    }
    else if(warriors % 2 != 0){
        warriors += 1;
        surrender_limit = rand() % warriors/4;
    }
    std::thread t1(battle_reports, warriors, surrender_limit, deaths, arbitrary_stop, adjustment, nanoseconds, players_attack, counter);
    t1.join();
}

int Spaceship::outcome_calculator(long warriors, int level, bool players_attack, int counter){
    high_resolution_clock::time_point p1 = high_resolution_clock::now();
    std::thread t2(casualties, warriors, level, players_attack, counter);
    t2.join();
    high_resolution_clock::time_point p2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(p2 - p1).count();
    return duration;
}

float Spaceship::soldiers_fate(float ceilling){
    float addition = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ceilling));
    return addition;
}

long Spaceship::random_victim_assignment(long warriors){
    float pivot;
    float fate;
    float ceilling;
    int random_constant;
    pivot = std::floor(warriors/2);
    random_constant = randRange(1, 2);
    ceilling = warriors - pivot;
    fate = soldiers_fate(ceilling);
    if(random_constant == 1){
        warriors += fate;
    }
    else if(random_constant == 2){
        warriors -= fate;
    }
    int n = static_cast<long>(warriors);
    return n;
}


void Spaceship::battle_processor(std::vector<std::string> balance, long drones, long cyborgs, long enemies_drones, long enemies_cyborgs, int level, int _soldierslevel, int counter){    //One processor to rule them all, One processor to find them,
    //One processor to bring them all and in the darkness bind them
    std::cout<<"\n"  //REWRITE PROCESS CHECK THE FIGHTER VARIABLE ASSIGNMENT!
    <<"Our soldiers will get ready for the glorious day my lord!"<<"\n"
    <<"Always willing to serve you and die for you! "<<"\n"
    <<std::endl;
    long first_turn;
    long second_turn;
    long player_warriors = drones + cyborgs;
    long enemy_warriors = enemies_drones + enemies_cyborgs;
    long strike_back_victims;
    int fighter_level1;
    int fighter_level2;
    bool players_attack;
    if(turn_assignment(counter)){
        players_attack = true;
        strike_back_victims = enemy_warriors;
        first_turn = random_victim_assignment(enemy_warriors);
        second_turn = strike_back_victims;
        fighter_level1 = _soldierslevel;
        fighter_level2 = level;
    }
    else if(!turn_assignment(counter)){
        players_attack = false;
        strike_back_victims = player_warriors;
        first_turn = random_victim_assignment(player_warriors);
        second_turn = strike_back_victims;
        fighter_level1 = level;
        fighter_level2 = _soldierslevel;
    }
    std::future<int> result1(std::async(outcome_calculator, first_turn, fighter_level1, players_attack, counter));
    int players_duration = result1.get();
    players_attack = true ? players_attack = false : players_attack = true;
    std::future<int> result2(std::async(outcome_calculator, second_turn, fighter_level2, players_attack, counter));
    int enemys_duration = result2.get();
    if(players_duration >= enemys_duration)
        balance.push_back("Victory");
    else if(players_duration < enemys_duration)
        balance.push_back("Defeat");
}


int Spaceship::efficiency_calculation(int resources, int slaves, bool battle){
    int efficiency;
    int time;
    int level;
    if(battle)
        level = _soldierslevel;
    else
        level = _slaveslevel;
    if(level >= 0 && level <= 5){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = 20* 2 - slaves;
            if(efficiency > 30){
                time = 3;
            }
            else
                time = 4;

        }
        else if(resources > 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = 20 * 2 - slaves;
            if(efficiency > 30){
                time = 4;
            }
            else
                time = 5;
        }
    }
    else if(_slaveslevel >= 5 && _slaveslevel <= 10){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = randRange(10, 15) * 2 - slaves;
            if(efficiency >= 15){
                time = 2;
            }
            else
                time = 3;

        }
        else if(resources > 5000){
            slaves % 2  == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = randRange(10, 15) * 2 - slaves;
            if(efficiency >= 15){
                time = 3;
            }
            else
                time = 4;
        }
    }
    else if(level > 10 && level <= 15){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = randRange(5, 10) * 2 - slaves;
            if(efficiency > 15)
                time = 1;
            else
                time = 2;
        }
        else if(resources > 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = randRange(5, 10) * 2 - slaves;
            if(efficiency > 10)
                time = 2;
            else
                time = 3;
        }
    }
    else if(level >= 15){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = randRange(1, 5) * 2 - slaves;
            if(efficiency > 5)
                time = 0;
            else
                time = 1;

        }
        else if(resources >= 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = randRange(1, 5) * 2 - slaves;
            if(efficiency > 5)
                time = 1;
            else
                time = 2;
        }
    }
    return time;
}

void Spaceship::display_colonies(){

}

void Spaceship::display_planets_database(){

}

void Spaceship::generate_solar_data_base(std::vector<Planet>){

}

void Spaceship::to_solar_system(){


    std::cout<<"Puta"<<std::endl;

}

void Spaceship::assign_troops(long aliens, int enemies_drones, int enemies_cyborgs){
    std::cout<<aliens<<std::endl;
    enemies_drones = randRange(int(std::round(aliens/2)), aliens);
    enemies_cyborgs = randRange(1000000, std::floor(aliens/2.0));
    aliens -= enemies_cyborgs + enemies_cyborgs;
}

void Spaceship::civilisation_interaction(int desired_respect, int aliens){
    std::vector<std::string> civilisationsnames = {"Epthot", "Quni", "Gowan", "Geeceind", "Srekloa", "Smorthue", "Absu", "Oimnere", "Lizul", "Thelzahue", "Qolush", "Vlesruom", "Twakten", "Vantoh", "Qefill", "Druzguo"};
    int enemies_level;
    int random_constant = rand() % 4;
    int earned_respect;
    int surrender_calculation;
    long enemies_drones;
    long enemies_cyborgs;
    int selection;
    long energy = 10000000.0;
    long enemy_energy = 10000000.0;
    bool turn = true;
    bool surrender = false;
    bool done = false;
    std::string social_structure;
    if(random_constant == 1)
    {
        social_structure = "Techno fascist regime";
        earned_respect = 3; //Fascist regimes are inferior but more corageous than democracies
        surrender_calculation = earned_respect - desired_respect;
        enemies_level = randRange(1, 4);
        if(surrender_calculation <= 0)
            surrender = true;
        else{
            surrender = false;
        }
    }
    else if(random_constant == 2){
        social_structure = "Liberal democracy";  //Still not very advanced
        earned_respect = 2;
        surrender_calculation = earned_respect - desired_respect;
        enemies_level = randRange(5, 7);
        if(surrender_calculation <= 0)
            surrender = true;
        else
            surrender = false;

    }
    else if(random_constant == 3){
        social_structure = "Techno-utopian anarchy";
        earned_respect = 5; //These guys are tough cookies
        surrender_calculation = earned_respect - desired_respect; //They share their wives!! XDD
        enemies_level = randRange(8, 13);
        if(surrender_calculation <= 0)
            surrender = true;
        else
            surrender = false;
    }
    else if(random_constant == 4){
        social_structure = "AI-ruled planetary nation"; //Run away motherfucker
        enemies_level = randRange(13, 17); //No surrender option
    }

    if(surrender){
        surrender_treaty(social_structure, civilisationsnames[rand() % civilisationsnames.size()]);
    }
    else if(!surrender){
        while(!done){
            std::cout<<"\n"
            <<"<<WAR DECLARATION>>"<<"\n"
            <<"\n"
            <<"Type of civilisation: "<<social_structure<<"\n"
            <<"\n"
            <<"Your current resources"<<"\n"
            <<"\n"
            <<"DRONES: "<<_drones<<"\n"
            <<"CYBORG-ARMORS AND WEAPONS: "<<_armors<<"\n"<<std::endl;
            assign_troops(aliens, enemies_drones, enemies_cyborgs);
            std::cout<<"\n"
            <<"Enemy's resources"<<"\n"
            <<"\n"
            <<"ENEMIES DRONES: "<<enemies_drones<<"\n"
            <<"ENEMIES CYBORGS: "<<enemies_cyborgs<<"\n"
            <<"\n"
            <<"The confidential reports must be read in order to find out the enemy's level"<<"\n"
            <<"1. Start battle"<<"\n"
            <<"2. Confidential reports from intelligence agency"<<std::endl;
            std::cin>>selection;
            switch(selection){
                    case 1: battle_preparation(enemies_drones, enemies_cyborgs, enemies_level, energy, enemy_energy, aliens);
                            //Function switching turns
                            break;


                    case 2: civilisation_history(social_structure, civilisationsnames[rand() % civilisationsnames.size()], enemies_level);
                            break;
            }
        }
    }
}

void Spaceship::save_game(){
//This will save the amount of each resource that has been accumulated(fuel, WARPdrive, diamonds, metal, protozoo, pseudomona, staphilloccocus)
//Number of colonies
//Number of civilisations that have been dominated
//Player's level!! (including soldierslevel, slaveslevel and scientistslevel)
//
}

void Spaceship::game_over(){
//This function must pick up a database and display the following values
//Distance travelled in light years
//Planets destroyed
//Colonies created
//Dominated civilisations
//Amount of diamonds collected
//Level reached
}



void Spaceship::planet_destroyer(int desired_respect){
    desired_respect += 1; //THIS FUNCTION SHOULD DELETE THE CHOSEN ROW FROM THE DATABASE MORE SPECIFICALLY THE SOLAR SYSTEM DATABASE
}

void Spaceship::refill_vector(std::string vectortype){
    if(vectortype == "Planets"){
        for(int i = 0; i <= planetnamesbuffer.size(); i++){
            planetnames.emplace_back(planetnamesbuffer[i]);
            planetnamesbuffer.erase(planetnamesbuffer.begin());
        }
    }
    else if(vectortype == "Stars"){
        for(int i = 0; i <= starnamesbuffer.size(); i++){
            starnames.emplace_back(starnamesbuffer[i]);
            starnamesbuffer.erase(starnamesbuffer.begin());
        }
    }
}

void Spaceship::planet_interaction(){
    if(planetnames.size() <= 8){
        refill_vector("Planets");
    }
    int choice;
    bool potential_colony = true; //We start by assuming the solar system can be colonised
    bool dead_solar_system = true;
    int slaves;
    std::string colony_approbation;
    unsigned int efficiency;
    int desired_respect = 0;
    int distancefromstar;
    int adjustment = 50;
    int adjustment1;
    int adjustment2;
    std::string planettype;
    std::string planetname;
    std::vector<int> distancesmap;
    std::vector<int> planetstemperatures;
    std::vector<char> planets_available;
    int planets_number = rand() % 4 + 4;
    std::vector<Planet> planets(planets_number);
    std::cout<<"\n"
    <<"<<<PLANETS>>>"<<"\n"
    <<"\n"
    "\n"<<std::endl;
    for(int j = 0; j < planets_number; j++){
        adjustment1 = adjustment + 2 * j;
        adjustment2 = adjustment1 + 4 * j;
        planetname = define_planets_name();
        distancefromstar = randRange(adjustment1, adjustment2);
        distancesmap.push_back(distancefromstar);
        std::cout<<std::endl;
        std::cout<<"Type "<<j + 1<<" to explore this planet"<<std::endl;
        std::cout<<std::endl;
        planets[j].display_planets_data(planetname, distancefromstar); //A TEMPORARY DATABASE SHOULD BE INITIALISED HERE
        planets_available.push_back(planets[j].getplanettype());  //ROWS AND ENTITIES WILL BE ADDED THROUGH THE LOOP
        planetstemperatures.push_back(planets[j].gettemperature());
        std::cout<<"\n"
        <<"\n"
        <<std::endl;
        adjustment += adjustment + randRange(150, 347);
        adjustment1 += adjustment1 + randRange(150, 347);
    }
    generate_solar_data_base(planets);
    std::cout<<std::endl;
    std::cout<<"Do you want to make this solar system a colony?"<<std::endl;
    std::cin>>colony_approbation;
    if(colony_approbation == "Yes" || colony_approbation == "yes" || colony_approbation == "y" || colony_approbation == "YES" || colony_approbation == "Y"){
        if(potential_colony){
            for(int i = 0; i < planets_available.size(); i++){
                if(planets_available[i] == 4){
                    if(planets[i].gethabitability()){
                        if(planets[i].getdefeat()){  //Important to use setdefeat for when a civilisation has been destroyed
                            continue;
                        }
                        else
                            potential_colony = false;

                    }
                    else if(potential_colony && !planets[i].gethabitability()){
                        dead_solar_system = true;
                    }
                    else if(planets[i].getpotentialhabitability()){
                        dead_solar_system = false;
                    }
                }
                else
                    continue;
            }
        }
        if(potential_colony){
            if(dead_solar_system){
                std::cout<<"This solar system can be colonised"<<"\n"
                <<"Since all of its planets are dead"<<std::endl;
            }
            else if(!dead_solar_system)  //Planettype can still be four but potentially habitable
                std::cout<<"There might be one or more potentially habitable planets in this solar system"<<std::endl;
        }
        else if(!potential_colony){
            std::cout<<"You still must conquer those planets that are habitable"<<std::endl;

        }
    }
    else if(colony_approbation == "No" || colony_approbation == "no" || colony_approbation == "n" || colony_approbation == "NO" || colony_approbation == "N"){
        std::cout<<"Your wishes are our commands master, you will still be given the option of making it a colony when you are back in this system"<<std::endl;
    }
    std::cout<<"Type in the planet number you wish to visit "<<std::endl;
    std::cin>>choice;
    if(_fuelcapacity < 2*(distancesmap[planets_number - 1] - distancesmap[choice - 1])){
        std::cout<<"You have no fuel capacity to travel to this planet"<<"\n"
        <<"Choose a closer planet, the last one will always be the closest"<<std::endl;
    }
    else{
        _fuelcapacity -= 2*(distancesmap[planets_number - 1] - distancesmap[choice -1]); //Two megatons per million of km will be consumed
        if(planets[choice -1].getplanettype()== 1){
            int selection;//This way when the level
            while(1){
                std::cout<<"\n"
                <<"<<LAVA PLANET>>"<<"\n"
                <<"1. Extract metal"<<"\n"
                <<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 0)
                    break;
                else if(selection == 1){
                    int desired_amount;
                    slaves = genetical_modification(choice , planets_available, planetstemperatures);
                    std::cout<<"\n"
                    <<"\n"<<std::endl;
                    while(1){
                        std::cout<<"Tell us the amount of metal that you want my lord"<<std::endl;
                        std::cin>>desired_amount;
                        efficiency = efficiency_calculation(planets[choice - 1].getmetal(), slaves, false);
                        std::cout<<efficiency<<std::endl;
                        if(desired_amount > planets[choice - 1].getmetal()){
                            std::cout<<"Try typing in the amount again"<<std::endl;
                        }
                        else
                            break;
                    }
                    std::cout<<"Your wishes are our commands, my lord!"<<std::endl; //WAIT FUNCTION INCLUDED HERE
                    sleep(efficiency);
                    planets[choice - 1].setmetal(-desired_amount);
                    _metalamount += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" kg of metal my lord"<<std::endl;
                    break;
                }
                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }
            }

        }


        else if(planets[choice -1].getplanettype() == 2){
            int selection;
            while(1){
                std::cout<<"\n"
                <<"<<DIAMOND PLANET>>"<<"\n"
                <<"\n"<<"1. Extract diamonds"<<"\n"
                <<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int desired_amount;
                    slaves = genetical_modification(choice, planets_available, planetstemperatures);
                    std::cout<<"\n"
                    <<"\n"<<std::endl;
                    while(1){
                        std::cout<<"Please, tell us the amount of diamonds that you want my lord"<<std::endl;
                        std::cin>>desired_amount;
                        efficiency = efficiency_calculation(slaves, planets[choice -1].getdiamonds(), false);
                        if(desired_amount > planets[choice - 1].getdiamonds()){
                            std::cout<<"There is not that many diamonds my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    std::cout<<"Your wishes are our commands, my lord"<<std::endl; //WAIT FUNCTION INCLUDED HERE
                    sleep(efficiency);
                    planets[choice - 1].setdiamonds(-desired_amount);
                    _diamondsamount += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" kg of diamonds to fill your archs my lord"<<std::endl;
                    break;
                }
                else if(selection == 0)
                    break;
                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }
            }
        }

        else if(planets[choice - 1].getplanettype() == 3){
            int selection;
            while(1){
                std::cout<<"\n"
                <<"<<MERCURY PLANET>>"<<"\n"
                <<"1. Extract mercury"<<"\n"
                <<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection== 1){
                    int desired_amount;
                    slaves = genetical_modification(choice, planets_available, planetstemperatures);
                    std::cout<<"\n"
                    <<"\n"<<std::endl;
                    while(1){
                        std::cout<<"Let us know how many megatons you want my lord"<<std::endl;
                        std::cin>>desired_amount;
                        efficiency = efficiency_calculation(slaves, planets[choice -1].getmercury(), false);
                        if(desired_amount > planets[choice - 1].getmercury()){
                            std::cout<<"There is not that much mercury my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    std::cout<<"Your wishes are our commands my lord!"<<std::endl;//wAIT FUNCTION INCLUDED HERE
                    sleep(efficiency);
                    planets[choice - 1].setmercury(-desired_amount);
                    _fuelcapacity += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" megatons of fuel to propell our gigantic space ship my lord"<<std::endl;
                    break;
                }
                else if(selection == 0)
                    break;
                else if(selection == 2){
                    planet_destroyer(desired_respect);
                    _antimatterweapon -= 3000;
                }
            }
        }
        else if(planets[choice -1].getplanettype() == 4){
            int selection;
            while(1){
                std::cout<<"\n"
                <<"<<HABITABLE OR POTENTIALLY HABITABLE PLANET>>"<<"\n"
                <<"1. Interact with civilisation/make potentially habitable"<<"\n"
                <<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int variableadjustment;
                    bool done = false;
                    std::string missingelement1;
                    std::string missingelement2;
                    std::string missingelement3;
                    long aliens = randRange(1000000, 5000000);
                    if(planets[choice - 1].gethabitability() == false){
                        if(planets[choice - 1].getbreathableatmosphere() == true){
                             while(1){
                                if(planets[choice -1].gethabitability() == true)
                                    break;
                                else{
                                    std::cout<<"My lord, we need to increase the magnetic field's intensity, adjust it using the magneto-weapon"<<"\n"
                                    <<"The amount by which we must adjust it is "<<"\n"
                                    <<planets[choice-1].getmagneticfieldvsradiation()<<std::endl;
                                    std::cin>>variableadjustment; //WAIT FUNCTION HERE
                                    planets[choice - 1].turn_into_habitable();
                                }

                            }

                            while(!done){
                                std::cout<<"My lord, we will need to accelerate the evolution process to get our specimens as soon as possible"<<"\n"
                                <<"Use your powers to bring this doom planet to life!"<<"\n"
                                <<"Press 1 to use the evolution express accelerator"<<std::endl;
                                std::cin>>variableadjustment;
                                if(_evolutionexpressaccelerator == 0){
                                    std::cout<<"Before your vindictive and glorious anger is inflicted upon our condemned miserable souls"<<"\n"
                                    <<"I need to let you know that we are out of the evolutionexpressaccelerator"<<"\n"
                                    <<"However it can still be processed in the laboratory"<<std::endl;
                                    //Wait function here
                                    while(1){
                                        bool protozoo = false;
                                        bool staphilloccocus = false;
                                        bool pseudomona = false;
                                        std::cout<<"\n"
                                        <<"<<--LABORATORY-->>"<<"\n"
                                        <<"\n"
                                        <<"Welcome to the laboratory my lord, we will process the evolutionexpressaccelerator combining the necessary bacteriae"<<std::endl;
                                        if(_protozoolevels == 0 && _staphilococcuslevels == 0 && _pseudomonalevels == 0){
                                            std::cout<<"My lord I am begging you to punish me with the most unimaginably horrible of tortures"<<"\n"
                                            <<"Our bacteriae deposits are empty"<<"\n"
                                            <<"It is time to go explore the universe in search for more"<<std::endl;
                                            done = true;
                                            break;
                                        }
                                        else if(_protozoolevels < 200 || _staphilococcuslevels < 100 || _pseudomonalevels < 50){
                                            int missing_element_calculation = _protozoolevels - 200;
                                            if(missing_element_calculation <= 0)
                                                    protozoo = true;
                                            missing_element_calculation = _staphilococcuslevels - 100;
                                            if(missing_element_calculation <= 0)
                                                    staphilloccocus = true;
                                            missing_element_calculation = _pseudomonalevels - 50;
                                            if(missing_element_calculation <= 0)
                                                    pseudomona = true;

                                            for(int i = 0; i < 3; i++){   //Checking the abscence of three elements involves too many if statements, this function makes it faster but not simpler unfortunately
                                                if(ORgate(protozoo, staphilloccocus, pseudomona)[i] > 0){
                                                    if(ORgate(protozoo, staphilloccocus, pseudomona)[i] == 1)
                                                        missingelement1 = "Protozoo";
                                                    else if(ORgate(protozoo, staphilloccocus, pseudomona)[i] == 2)
                                                        missingelement2 = "Staphilloccocus";
                                                    else if(ORgate(protozoo, staphilloccocus, pseudomona)[i] == 3)
                                                        missingelement3 = "Pseudomona";

                                                }
                                            }
                                            std::cout<<"We are out of "<<"\n"
                                            <<"\n"
                                            <<missingelement1<<"\n"
                                            <<missingelement2<<"\n"
                                            <<missingelement3<<"\n"
                                            <<"\n"
                                            <<"Slightly increasing the chimpancee's inteligence up to the ironically named homo-sapiens"<<"\n"
                                            <<"will take longer than we thought..."<<"\n"
                                            <<"Time to keep on exploring the universe!"<<std::endl;
                                            done = true;
                                            break;
                                        }
                                        else{
                                            efficiency = efficiency_calculation(400, randRange(1, 2), false);
                                            usleep(efficiency);
                                            _protozoolevels -= rand()%200 + 1;
                                            _staphilococcuslevels -= rand()%100 + 1;
                                            _pseudomonalevels -= rand()%100 + 1;
                                            _evolutionexpressaccelerator += 1;
                                            std::cout<<"We just increased the amount of evolution express accelerator by one my lord"<<"\n"
                                            <<"God save the lord!"<<"\n"
                                            <<"Shall the ancient gods worship you my lord for no other than thee can defy their magnanimous and ubiquitus power"<<std::endl;
                                            _specimens += aliens;
                                            _evolutionexpressaccelerator -= 1;
                                            std::cout<<"\n"
                                            <<"Our crew has been increased by "<<aliens<<" specimens"<<std::endl;
                                            done = true;
                                            break;


                                    }

                                }


                            }

                         }


                      }



                    }
                    else if(planets[choice -1].gethabitability() == true)
                        civilisation_interaction(desired_respect, aliens);
                        break;

                }
                else if(selection == 0)
                    break;

                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }

            }
        }

        else if(planets[choice - 1].getplanettype() == 5){
            int selection;
            while(1){
               std::cout<<"\n"
               <<"<<FROZEN PLANET CONTAINING SIMPLE FORMS OF LIFE>>"<<"\n"
                <<"1. Extract bacteria"<<"\n"
                <<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int desired_amount_protozoo;
                    int desired_amount_staphillococcus;
                    int desired_amount_pseudomona;
                    while(1){
                        std::cout<<"Type in the amount of protozoo that you want my lord"<<std::endl;
                        std::cin>>desired_amount_protozoo;
                        if(_slaveslevel >= 0 && _slaveslevel <= 10)
                            efficiency = 4;
                        else if(_slaveslevel >= 10 && _slaveslevel <= 15)
                            efficiency = 3;
                        else if(_slaveslevel > 15)
                            efficiency = 2;
                        if(desired_amount_protozoo > planets[choice -1].getprotozoo()){
                            std::cout<<"There is not so much protozoo my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    while(1){
                        std::cout<<"Tell us the amount of staphillococcus that you would like my lord"<<std::endl;
                        std::cin>>desired_amount_staphillococcus;
                        if(desired_amount_staphillococcus > planets[choice -1].getstaphilloccocus()){
                            std::cout<<"There is not so much staphillococcus my lord"<<std::endl;
                        }
                        else
                            break;

                    }
                    while(1){
                        std::cout<<"Tell us the amount of pseudomona that you desire my lord"<<std::endl;
                        std::cin>>desired_amount_pseudomona;
                        if(desired_amount_pseudomona > planets[choice -1].getpseudomona()){
                            std::cout<<"There is not so much pseudomona my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    sleep(efficiency);
                    planets[choice - 1].setbacteriae(-desired_amount_protozoo, -desired_amount_staphillococcus, -desired_amount_pseudomona);
                    _protozoolevels += desired_amount_protozoo;
                    _staphilococcuslevels += desired_amount_staphillococcus;
                    _pseudomonalevels += desired_amount_pseudomona;
                    std::cout<<"We have added "<<desired_amount_protozoo<<","<<desired_amount_staphillococcus<<" and "<<desired_amount_pseudomona<<std::endl;
                    std::cout<<"of protozoo, staphillococcus and pseudomona my lord!"<<std::endl;
                    break;
                }

            else if(selection == 0)
                break;

            else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }


            }
        }
        else if(planets[choice -1].getplanettype() == 6){
            int selection;
            while(1){
                std::cout<<"\n"
                <<"<<GAS GIANT>>"<<"\n"
                <<"1. Extract WARP drive fuel"<<"\n"
                <<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int desired_amount;
                    if(_slaveslevel >= 0 && _slaveslevel <= 10)
                            efficiency = 4;
                        else if(_slaveslevel >= 10 && _slaveslevel <= 15)
                            efficiency = 3;
                        else if(_slaveslevel > 15)
                            efficiency = 2;
                    while(1){
                        std::cout<<"Please my lord, let us know how much gas you will need"<<std::endl;
                        std::cin>>desired_amount;
                        if(desired_amount > planets[choice -1].getgas()){
                            std::cout<<"We are sorry to tell you my lord that the planet does not contain that much gas"<<std::endl;
                        }
                        else
                            break;
                    }
                    planets[choice - 1].setgas(-desired_amount);
                    efficiency = efficiency_calculation(desired_amount, randRange(1, 2), false);
                    sleep(efficiency);
                    _WARPdrive += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" megatons of antimatter to fill our WARP drive deposits my lord!"<<std::endl;
                    break;
                }
                else if(selection = 0)
                    break;
                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }



            }

        }
    }

}

void Spaceship::interstellar_travel()
{

    int starschoice;
    int solarsystemchoice;
    std::vector<Star> Stars;
    while(1){
        if(_WARPdrive <= 1000){
            std::cout<<"My lord, we have no fuel left, it is time for us to face death like brothers!"<<"\n"
            <<"I must confess it's always been a pleasure for us to serve you"<<std::endl;
            game_over();
            break;
            //The data base should be used here to display data from the user's colonies
            //and the current solar system where our character is
        }
        Stars = stars_interaction();
        std::cin>>starschoice;
        if(_fuelcapacity == 0){
            std::cout<<"My lord, we have no fuel left, it is time for us to face death like brothers!"<<"\n"
            <<"I must confess it's always been a pleasure for us to serve you"<<std::endl;
            game_over();
        }
        if(starschoice == 0)
            break;
        else if(_WARPdrive >= 1000)
        {
            _WARPdrive -= 250;
            planet_interaction();
        }
        std::cout<<"1. Back to solar system"<<"\n"
        <<"2. Back to cabin"<<std::endl;
        std::cin>>solarsystemchoice;
        if(solarsystemchoice == 1){
            to_solar_system();
            break;
        }
        else if(solarsystemchoice ==2)
            break;


    }

}


void Spaceship::purchasepoints(int diamonds){
    if(diamonds == 0){
        std::cout<<"Your archs do not still have diamonds my lord, we will need to invade more planets!"<<"\n"
        <<"Which we will do very gladly..."<<std::endl;
    }
    else if(diamonds > 0){
        _points = diamonds/100;
        _diamondsamount -= diamonds;
        std::cout<<_points<<"\n"
        <<"This is your current amount of points my lord, make us more powerful to serve you!!"<<std::endl;
    }
}




void Spaceship::assign_points(int points, std::string specimen){
    if(points > _points){
        std::cout<<"We are sorry to tell you my lord that we still don't have so many points"<<"\n"
        <<"We will neeed to conquer more regions of the universe"<<std::endl;
    }
    else{
        _points -= points;
        if(specimen == "Robo-slaves"){
            if(points % 2 == 0){
                _slavespoints += points/10;
            }
            else if(points % 2 != 0){
                points = points + 1;
                _slavespoints += points/10;
            }
        }
        else if(specimen == "Scientists"){
            if(points % 2 == 0){
                _scientistspoints += points/10;
            }
            else if(points % 2 != 0){
                points = points + 1;
                _scientistspoints += points/10;
            }

        }
        else if(specimen == "Cyborg soldiers"){
              if(points % 2 == 0){
                _soldierspoints += points/10;
            }
            else if(points % 2 != 0){
                points = points + 1;
                _soldierspoints += points/10;
            }
        }
    }
}


void Spaceship::setlevel(int currentlevel, std::string specimen, int increaseneeded, int levelsleft, int amount_desired, int choice, int factor, bool levelup,  std::vector<int> prices, std::vector<int> levels){
    while(1){

            std::cout<<"\n"
            <<"Type in your amount of points"<<std::endl;
            std::cin>>amount_desired;
            if(amount_desired == 0)
                break;

            else if(amount_desired > _points){
                std::cout<<"You don't have that many points yet, type your points again or press 0 to exit"<<"\n"
                <<"You can purchase points from the main menu"<<std::endl;
            }
            else if(amount_desired == 0)
                break;
            else if(amount_desired <= _points){
                assign_points(amount_desired, specimen);
                if(specimen == "Cyborg soldiers"){
                    for(int i = _soldierslevel; i < prices.size(); i++){
                        if(prices[i] <= _soldierspoints){
                            levelup = true;
                            factor += 1;
                            _soldierslevel += factor;
                        }
                        else{
                            continue;
                        }
                    }
                    if(levelup){
                        std::cout<<"Your cyborg soldiers are stronger by a factor of "<<factor<<" my lord"<<"\n"
                        <<"We feel grateful and will gladly sacrifice our lives for our intergalactic empire!"<<"\n"
                        <<"This is your overall level"<<std::endl;
                        _overalllevel = (_soldierslevel + _scientistslevel + _slaveslevel)/3; //Compute overall level
                        std::cout<<_overalllevel<<std::endl;
                        _soldierspoints = 0;
                        break;
                    }
                    else if(!levelup){
                        std::cout<<"Thanks for making us stronger for you my lord, it is time to go to war!"<<std::endl;
                        break;
                    }
                }
                else if(specimen == "Scientists"){
                    for(int i = _scientistslevel; i < prices.size(); i++){
                        if(prices[i] <= _scientistspoints){
                            levelup = true;
                            factor += 1;
                            _scientistslevel +=factor;
                            break;
                        }
                        else
                            continue;
                    }
                    if(levelup){
                        std::cout<<"Your scientists have clearly outsmarted their previous generation, by a factor of "<<factor<<" my lord"<<"\n"
                        <<"This is your overall level"<<std::endl;
                        _overalllevel = (_soldierslevel + _scientistslevel + _slaveslevel)/3;
                        std::cout<<_overalllevel<<std::endl; //Compute overall
                        _scientistspoints = 0;
                        break;
                    }
                    else if(!levelup){
                        std::cout<<"Your contribution to science will make this a better universe"<<"\n"
                        <<"and enslave half of its population..."<<std::endl;
                        break;
                    }
                }
                 else if(specimen == "Robo-slaves"){
                    for(int i = _slaveslevel; i < prices.size(); i++){
                        if(prices[i] < _slavespoints){
                            levelup = true;
                            factor += 1;
                            _slaveslevel += factor;
                            break;
                        }
                        else
                            continue;
                    }
                    if(levelup){
                        std::cout<<"Your robo-slaves have been powered up by a factor of "<<factor<<" my lord"<<"\n"
                        <<"Not very ethical but.. who said being practical implied being moral?"<<"\n"
                        <<"This is your overall level"<<std::endl;
                        _overalllevel = (_soldierslevel + _scientistslevel + _slaveslevel)/3;
                        std::cout<<_overalllevel<<std::endl; //Compute overall
                        _slavespoints = 0;
                        break;
                    }
                    else if(!levelup){
                        std::cout<<"Your contribution to science will help us make this a better universe!"<<"\n"
                        <<"and enslave more than a half of its population..."<<"\n"
                        <<"I never believed in utopian regimes anyways"<<std::endl;
                        break;
                    }
                }

            }


       }

}


void Spaceship::laboratory(){
    std::string specimen;
    int choice;
    while(1){
    std::cout<<"\n"
    <<"<<LABORATORY>>"<<"\n"
    <<"\n"
    <<"1. Cyborg army"<<"\n"
    <<"2. Scientists"<<"\n"
    <<"3. Robo-slaves"<<"\n"
    <<"4. Exit"<<std::endl;
    std::cin>>choice;
    if(choice == 1){
        specimen = "Cyborg soldiers";
        while(1){
            std::cout<<"1. Power up your cyborg army"<<"\n"
            <<"2. Exit"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                if(choice == 2)
                    break;
                else if(choice == 1){
                    std::cout<<"Current soldiers level: "<<_soldierslevel<<std::endl;
                    int increaseneeded;
                    int levelsleft;
                    int amount_desired;
                    int choice;
                    int factor = 0; //The i value that is used to iteratte through the list plus one, this way we get by how many levels the specimens have improved
                    bool levelup;
                    std::vector<int> prices = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625};
                    std::vector<int> levels = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
                    levelsleft = levels.size() - _soldierslevel;  //this must change for every type
                    std::cout<<"You have "<<levelsleft<<" levels left to become master of the universe"<<"\n"
                    <<"These are your points "<<_points<<std::endl;
                    for(int i = _soldierslevel; i < levels.size(); i++){
                        increaseneeded = std::pow(i, 4);
                        std::cout<<"Level: "<<levels[i]<<"\n"
                        <<"Points needed "<< increaseneeded<<std::endl;
                    }
                    setlevel(_soldierslevel, specimen, increaseneeded, levelsleft, amount_desired, choice, factor, levelup, prices, levels);
                    break;
                }
            }
            else if(choice == 2)
                break;
        }
    }
    else if(choice == 2){
        specimen = "Scientists";
        while(1){
            std::cout<<"\n"
            <<"1. Make your scientists smarter"<<"\n"
            <<"2. Exit"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                if(choice == 2)
                    break;
                else if(choice == 1){
                    std::cout<<"Current scientists level: "<<_scientistslevel<<std::endl;
                    int increaseneeded;
                    int levelsleft;
                    int amount_desired;
                    int choice;
                    int factor = 0;
                    bool levelup;
                    std::vector<int> prices = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625};
                    std::vector<int> levels = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
                    levelsleft = levels.size() - _scientistslevel;  //this must change for every type
                    std::cout<<"You have "<<levelsleft<<" levels left to become master of the universe"<<"\n"
                    <<"These are your points "<<_points<<std::endl;
                    for(int i = _scientistslevel; i < levels.size(); i++){
                        increaseneeded = std::pow(i, 4);
                        std::cout<<"Level: "<<levels[i]<<"\n"
                        <<"Points needed "<< increaseneeded<<std::endl;
                    }
                    setlevel(_scientistslevel, specimen, increaseneeded, levelsleft, amount_desired, choice, factor, levelup, prices, levels);
                    break;
                }
            }
            else if(choice == 2)
                break;
        }

    }
    else if(choice == 3){
        specimen = "Robo slaves";
        while(1){
            std::cout<<"1. Make your slaves almost indefatigable"<<"\n"
            <<"2. Exit"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                if(choice == 2)
                    break;
                else if(choice == 1){
                    std::cout<<"\n"
                    <<"Current slaves level: "<<_slaveslevel<<std::endl;
                    int increaseneeded;
                    int levelsleft;
                    int amount_desired;
                    int choice;
                    int factor = 0; //The i value that is used to iteratte through the list plus one, this way we get by how many levels the specimens have improved
                    bool levelup;
                    std::vector<int> prices = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625};
                    std::vector<int> levels = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
                    levelsleft = levels.size() - _slaveslevel;  //this must change for every type
                    std::cout<<"You have "<<levelsleft<<" levels left to become master of the universe"<<"\n"
                    <<"These are your points "<<_points<<std::endl;
                    for(int i = _slaveslevel; i < levels.size(); i++){
                        increaseneeded = std::pow(i, 4);
                        std::cout<<"Level: "<<levels[i]<<"\n"
                        <<"Points needed "<< increaseneeded<<std::endl;
                    }
                    setlevel(_slaveslevel, specimen, increaseneeded, levelsleft, amount_desired, choice, factor, levelup, prices, levels);
                    break;
                }
            }
            else if(choice == 2)
                break;
        }

    }
   else if(choice == 4)
        break;
  }
}



void Spaceship::read_story(){
//Reads from a text-file the main story of the game

    std::ifstream readstory;
    std::string line;
    readstory.open("readstory.txt");
    if(! readstory.is_open()){
        std::cout<<"Sorry, could not open file"<<std::endl;
    }
    while(std::getline(readstory, line)){
        std::cout<<line<<std::endl;
    }
    readstory.close();
}


std::string Spaceship::show_title(){
return "   ___   ____  ____ ___   ___             ___   _____ ______________   ____      __                           \n"
       "  |__ \\ / __ \\/ __ <  /  /   |  ____     /   | / ___// ____/  _/  _/  / __ \\____/ /_  _______________  __  __ \n"
       "      _/ / / / / / / /  / // | / | /\\   / /| | \\__ \\/ /    / / / /   / / / / __  / / / / ___/ ___/ _ \\/ / / / \n"
       " / __// / / / /_/_/ /  / /  _|/ / / /  / /   | __/ / /____/ /_/ /   / /_/ / /_/ / /_/ (__  |__  )  __/ /_/ /  \n"
       "/____/\\____/\\____/_/  /_/  |_/_/ /_/  /_/  |_/____/\\____/___/___/   \\____/\\__,_/\\__, /____/____/\\___/\\__, /   \n"
       "                                                                               /____/               /____/ ";
}


int Spaceship::cabin(){
    std::cout<<show_title()<<std::endl;
    std::string choice;
    while(1){
        std::cout<<std::endl;
        std::cout<<"<<<CABIN OF THE INTERSTELLAR FALCON IV WELCOME ON BOARD MY MASTER>>>"<<"\n"
        <<"I)nterstellar travel"<<"\n"
        <<"A)ccess laboratory"<<"\n"
        <<"D)eposits and WARP initialiser"<<"\n"
        <<"M)ethallurgy"<<"\n"
        <<"P)urchase points!"<<"\n" //Yeah, we need revenue for our business XDDD
        <<"S)ave game"<<"\n"
        <<"C)olonies"<<"\n"
        <<"R)ead story"<<"\n"
        <<"E)xit"<<std::endl;
        std::cin>>choice;

        if(choice == "I" || choice == "i"){
            interstellar_travel();
        }

        else if(choice == "A" || choice == "a"){
            laboratory();
        }
        else if(choice == "D" || choice == "d"){
            std::string input;
            int desired_amount;
            while(1){
                std::cout<<"\n"
                <<"<<DEPOSITS>>"<<"\n"
                <<"Fuel tank capacity for interplanetary travel: "<<_fuelcapacity<<"\n"
                <<"Antimatter deposit to power WARP drive and planet destroyer: "<<_WARPdrive<<"\n"<<
                "Do you want to charge the antimatter weapon?"<<std::endl;
                std::cin>>input;
                if(input == "Yes" || input == "yes" || input == "YES" || input == "y" || input == "Y"){
                    while(1){
                        std::cout<<"\n"
                        <<"Type in by how much you want to charge it"<<"\n"
                        <<"each shot will consume 3000 units of WARPdrive fuel"<<std::endl;
                        std::cin>>desired_amount;
                        if(desired_amount > _WARPdrive){
                            std::cout<<"Sorry but you don't have enough WARPdrive fuel yet"<<std::endl;
                            std::cout<<std::endl;
                        }
                        _WARPdrive -= desired_amount;
                        _antimatterweapon += desired_amount;
                        std::cout<<"Lord, you just loaded the anti-matter weapon by "<<desired_amount<<" units"<<"\n"
                        <<"Anti-matter weapon: "<<_antimatterweapon<<"\n"
                        <<std::endl;
                        break;
                        }
                }
                else if(input == "no" || input == "No" || input == "NO" || input == "n" || input == "N"){
                    std::cout<<"Wise decision my lord, that amount of WARPdrive fuel will be needed for our interplanetary expeditions!"<<std::endl;
                    break;
                }
                else if(input == "exit" || input == "EXIT" || input == "Exit"){
                    break;
                }
           }
        }
        else if(choice == "M" || choice == "m"){
            metallurgy(1);
        }
        else if(choice == "P" || choice == "p"){
            purchasepoints(_diamondsamount);
        }
        else if(choice == "S" || choice == "s"){
            save_game(); //DATABASE WITH ALL VARIABLES OF THE USER
        }
        else if(choice == "C" || choice == "c"){
            display_colonies(); //DATABASE TO DISPLAY COLONIES
        }
        else if(choice == "R" || choice == "r"){
            read_story();
        }
        else if(choice == "E" || choice == "e"){
            std::cout<<"Lord, the tripulants will get in hibernation mode"<<std::endl;
            std::cout<<"Always willing to serve you my master!"<<std::endl;
            return 0;
            }
    }
}


int main()
{
    srand(unsigned( time(NULL) ));
    Spaceship s;
    s.cabin();
}

