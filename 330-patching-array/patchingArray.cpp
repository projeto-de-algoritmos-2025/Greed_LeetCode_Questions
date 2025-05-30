class Solution {
public:
    int minPatches(vector<int>& numeros, int n) {
        long long limite_atual = 1;
        int resultado = 0; // Conta o número de patches
        size_t i = 0;
        while (limite_atual <= n) {
            if (i < numeros.size() && numeros[i] <= limite_atual) {
                limite_atual += numeros[i]; // Estende o alcance
                i++;                 // Move para o próximo número no array
            } else {
                limite_atual += limite_atual; // Dobra o alcance máximo
                resultado++;    // Incrementa o contador de patches
            }
        }
        return resultado;
    }
};