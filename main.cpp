#include "std_lib_inc.h"

// Funktion zur Berechnung der Lösungen einer quadratischen Gleichung mit der Mitternachtsformel
vector<double> berechneMitternachtsformel(double a, double b, double c)
{
    // Gleichung wirklich quadratisch? (a darf nicht 0 sein)
    if (a == 0)
    {
        error("Die Gleichung ist keine quadratische Gleichung, da a = 0.");
    }

    // Berechnung der Diskriminante (b^2 - 4ac)
    double diskriminante = b * b - 4 * a * c;

    // Diskriminante negativ? (keine reellen Lösungen)
    if (diskriminante < 0)
    {
        error("Die Gleichung hat keine reellen Loesungen, da die Diskriminante negativ ist.");
    }

    vector<double> loesungen;

    // Fall 1: Diskriminante 0 (doppelte Lösung)
    if (diskriminante == 0)
    {
        loesungen.push_back(-b / (2 * a)); // Lösung wird berechnet und hinzugefügt
    }
        // Fall 2: Diskriminante positiv (zwei unterschiedliche Lösungen)
    else
    {
        loesungen.push_back((-b + sqrt(diskriminante)) / (2 * a)); // Erste Lösung
        loesungen.push_back((-b - sqrt(diskriminante)) / (2 * a)); // Zweite Lösung
    }
    return loesungen;
}

int main()
{
    try
    {
        cout << "Dieses Programm loest quadratische Gleichungen der Form ax^2 + bx + c = 0.\n";
        cout << "Bitte geben Sie die Koeffizienten a, b und c ein:\n";

        double a, b, c;

        // Eingabe der Koeffizienten durch die Benutzerin/den Benutzer
        cout << "a: \n";
        cin >> a;
        cout << "b: \n";
        cin >> b;
        cout << "c: \n";
        cin >> c;

        // Aufruf der Funktion zur Berechnung der Lösungen
        vector<double> loesungen = berechneMitternachtsformel(a, b, c);

        cout << "Die Loesung(en) der Gleichung sind:\n";
        for (double loesung : loesungen)
        {
            cout << loesung << '\n';
        }
    }
        // Behandlung von Fehlern (z. B. wenn Diskriminante negativ ist)
    catch (const runtime_error& e)
    {
        cerr << "Fehler: " << e.what() << '\n';
    }
    return 0;
}
