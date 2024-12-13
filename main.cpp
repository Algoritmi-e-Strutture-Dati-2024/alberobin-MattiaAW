int main() {
    AlberoBinario<int> albero;
    albero.insRadice(54);
    albero.insFiglioSinistro(0, 67);
    albero.insFiglioDestro(0, 43);


    std::cout << "Albero prima della rimozione:\n";
    albero.stampa();

  
    albero.rimuovi(0);

    std::cout << "\nAlbero dopo la rimozione del nodo:\n";
    albero.stampa();

    return 0;
}
