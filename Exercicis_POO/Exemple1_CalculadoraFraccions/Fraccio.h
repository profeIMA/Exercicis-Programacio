#ifndef FRACCIO_H
#define FRACCIO_H

class Fraccio {
// Descripció: una fracció amb denominador>0 i simplificada
public:
    // Constructors
    Fraccio();               // Pre: --;   Post: s'ha creat fracció 0/1
    Fraccio(int n, int d);   // Pre: d!=0; Post: s'ha creat fracció en el format (-)n/d i simplificada
    // Consultors
    Fraccio suma(Fraccio f) const;
    // Pre:--; Post: retorna la suma simplificada entre fracció actual i f
    Fraccio resta(Fraccio f) const;
    // Pre:--; Post: retorna la resta simplificada entre fracció actual i f
    Fraccio producte(Fraccio f) const;
    // Pre:--; Post: retorna el producte simplificat entre fracció actual i f
    Fraccio divisio(Fraccio f) const;
    // Pre: f no val zero; Post: retorna la divisió simplificada entre fracció actual i f
    void mostrar() const;
    // Pre:--; Post: mostra la fracció actual en format (-)num/den o (-)num si el denominador és 1

private:
    int a_num; // conté el signe de la fracció
    int a_den; // serà major que zero

    void simplificar();
    // Pre: --; Post: ha simplificat la fracció actual
    static int maxim_comu_divisor(int a, int b);
    // Pre: a,b > 0; Post: retorna M.C.D.(a,b)
    static int minim_comu_multiple(int a, int b);
    // Pre: a,b > 0; Post: retorna M.C.M.(a,b)
};

#endif // FRACCIO_H
