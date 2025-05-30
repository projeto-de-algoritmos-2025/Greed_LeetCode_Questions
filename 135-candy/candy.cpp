class Solution {
public:
    int candy(std::vector<int>& avaliacoes) {
        int tamanho = avaliacoes.size();
        // Inicializa cada criança com 1 doce
        std::vector<int> doces(tamanho, 1);
        // Primeira passagem: da esquerda para a direita
        // Garante que uma criança com avaliação maior que a da sua esquerda receba mais doces
        for (int i = 1; i < tamanho; ++i) {
            if (avaliacoes[i] > avaliacoes[i - 1]) {
                doces[i] = doces[i - 1] + 1;
            }
        }
        // Segunda passagem: da direita para a esquerda
        // Garante que uma criança com avaliação maior que a da sua direita também receba mais doces,
        // e mantém o máximo atribuído pela primeira passagem
        for (int i = tamanho - 2; i >= 0; --i) {
            if (avaliacoes[i] > avaliacoes[i + 1]) {
                doces[i] = std::max(doces[i], doces[i + 1] + 1);
            }
        }
        // Soma o total de doces distribuídos
        int totalDoces = 0;
        for (int doce : doces) {
            totalDoces += doce;
        }
        return totalDoces;
    }
};