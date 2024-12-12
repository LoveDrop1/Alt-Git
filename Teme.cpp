#include <iostream>
#include <string>
#include<vector>

using namespace std;



class angajat {
private:
    float salariu;
    float spo;

public:
    string nume;
    int ore;
    int zile;

    angajat(float sa, float sp, string nu, int o , int z) { 
        salariu = sa;
        spo = sp;
        nume = nu;
        ore = o;
        zile = z;
    };
    
    float net() {
        ore = zile * 8;
        float net = ore * spo;
         return net;
     }

        void afisare() {
        
            cout << "\n Nume - " << nume << endl;
            cout << "\n Incadrare - " << salariu << endl;
            cout << "\n Castig pe ora - " << spo << endl;
            cout << "\n Ore lucrate - " << ore << endl;
            cout << "\n Zile prezente - " << zile << endl;
            cout << "\n Salar net -  " << net() << endl;
        }
};

class meteo {
private:
    float temp;

public:
     meteo (float t) {
        temp = t; }

     float getTemp () const { return temp; }

     void afisare ( const string zi) {
    cout << zi << " au fost " << temp << " grade Celsius " << endl; }
};

 void f1() {

     vector <meteo> saptamana = {
    meteo(4.6) ,
    meteo(6.4) ,
    meteo(1.8) ,
    meteo(7.6) ,
    meteo(3.4) ,
    meteo(7.4) ,
    meteo(5.9) }; 

     vector <string> zi = { "Luni", "Marti", "Miercuri", "Joi", "Vineri", "Sambata", "Duminica" };

      
     float tempMax = saptamana[0].getTemp();
     string ziMax = zi[0];

     for (int i = 0; i < saptamana.size(); ++i) {
         saptamana[i].afisare(zi[i]);

         if (saptamana[i].getTemp() > tempMax) {
         tempMax = saptamana[i].getTemp();
         ziMax = zi[i];
         }
     }
 cout << "\n temperatura maxima a fdost " << ziMax << " si a inregistrat " << tempMax << " grade Celsius" << endl;
}
 

 void f2() { 

     angajat necalificat(5000, 31.25, "Pop Ion", 84, 23);
     necalificat.afisare();
     necalificat.net();
 }

 void f3() {

     struct vreme {

         string ziua;
         float temperatura;
     };

     vreme saptamana[7] = {
     { "Luni", 5.6 },
     { "Marti", 9.4 },
     { "Miercuri", 4.2 },
     { "Joi", 2.5 },
     { "Vineri", 5.3 },
     { "Sambata", 6.7 },
     { "Duminica", 6.9 }
     };

     for (int i = 0; i < 7; i++) {
         cout << saptamana[i].ziua << " au fost : " << saptamana[i].temperatura << " grade Celsius " << endl;
     }

     float tempMax = saptamana[0].temperatura;
     string ziMax = saptamana[0].ziua;

     for (int i = 1; i < 7; i++) {
         if (saptamana[i].temperatura > tempMax) {
             tempMax = saptamana[i].temperatura;
             ziMax = saptamana[i].ziua;
         }
     }
     cout << "\n Maxima a fost : " << ziMax << "  " << tempMax << endl;
 }
 
int main() {

    int q;
    cout << " Introdu exercitiu : \n";
    cout << " 1 pentru meteo :\n";
    cout << " 2 pentru angajat :\n";
    cout << " 3 pentru meteo cu struct :\n";
    cin >> q;

    switch (q) {

    case 1:
        f1();
        break;

    case 2:
        f2();
        break;

   case 3:
        f3();
        break;
        
    default:
            cout << "Alegere invalida !" << endl;
        break;
    
    }

    return 0;
}