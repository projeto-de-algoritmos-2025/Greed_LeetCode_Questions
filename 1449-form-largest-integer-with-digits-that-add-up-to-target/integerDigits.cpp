class Solution {
public:
    int maxDigitos(vector<int>& custo, int indice, int somaAtual, vector<vector<int>>& pd, int alvo) {
        if (somaAtual > alvo)
            return INT_MIN; 
        if (indice < 0)
            return somaAtual == alvo ? 0 : INT_MIN; 
        if (pd[indice][somaAtual] != -1)
            return pd[indice][somaAtual]; 
        int incluiu = INT_MIN;
        if (somaAtual + custo[indice] <= alvo) {
            incluiu = 1 + maxDigitos(custo, indice, somaAtual + custo[indice], pd, alvo);
        }
        int excluiu = maxDigitos(custo, indice - 1, somaAtual, pd, alvo);
        return pd[indice][somaAtual] = max(incluiu, excluiu); 
    }
    void reconstruirResultado(vector<int>& custo, int indice, int somaAtual, vector<vector<int>>& pd, int alvo,
            string& numeroFormado) {
        if (somaAtual > alvo)
            return;
        if (indice < 0)
            return; 
        int incluiu = INT_MIN;
        if (somaAtual + custo[indice] <= alvo) {
            incluiu = 1 + maxDigitos(custo, indice, somaAtual + custo[indice], pd, alvo);
        }
        int excluiu = maxDigitos(custo, indice - 1, somaAtual, pd, alvo);
        bool decisaoDeIncluir = false;
        if (incluiu != INT_MIN) {
            if (excluiu == INT_MIN || incluiu >= excluiu) { 
                decisaoDeIncluir = true;
            }
        }
        if (decisaoDeIncluir) {
            numeroFormado += char(indice + 1 + '0'); 
            reconstruirResultado(custo, indice, somaAtual + custo[indice], pd, alvo, numeroFormado);
        } else { 
            reconstruirResultado(custo, indice - 1, somaAtual, pd, alvo, numeroFormado);
        }
    }
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); 
        int maximoDeDigitos = maxDigitos(cost, n - 1, 0, dp, target);
        if (maximoDeDigitos <= 0) 
            return "0"; 
        string numero = "";
        reconstruirResultado(cost, n - 1, 0, dp, target, numero);
        return numero;
    }
};