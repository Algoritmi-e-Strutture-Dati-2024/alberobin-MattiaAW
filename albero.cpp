#include <iostream>

template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool esiste[100]; 
    int dimensione;   

public:
    AlberoBinario() {
        dimensione = 0;
        for (int i = 0; i < 100; ++i) {
            esiste[i] = false;
        }
    }

    bool alberoVuoto() const {
        return dimensione == 0;
    }

    void insRadice(const T& valore) {
        if (dimensione == 0) {
            nodi[0] = valore;
            esiste[0] = true;
            dimensione++;
        }
    }

    T radice() const {
        if (dimensione > 0) {
            return nodi[0];
        } else {
        
            return T(); 
        }
    }

    bool isFoglia(int indice) const {
        if (indice < 100 && esiste[indice]) {
            return !esiste[figlioSinistro(indice)] && !esiste[figlioDestro(indice)];
        }
        return false;
    }

    int figlioSinistro(int indice) const {
        return 2 * indice + 1;
    }

    int figlioDestro(int indice) const {
        return 2 * indice + 2;
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int sinistro = figlioSinistro(indice);
        if (indice < 100 && sinistro < 100 && esiste[indice]) {
            nodi[sinistro] = valore;
            esiste[sinistro] = true;
            dimensione++;
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int destro = figlioDestro(indice);
        if (indice < 100 && destro < 100 && esiste[indice]) {
            nodi[destro] = valore;
            esiste[destro] = true;
            dimensione++;
        }
    }


    void rimuovi(int indice) {
        if (indice < 100 && esiste[indice]) {
            esiste[indice] = false;
            dimensione--;
        }
    }

    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (esiste[i]) {
                std::cout << "Nodo " << i << ": " << nodi[i] << std::endl;
            }
        }
    }
};

