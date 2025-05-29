class Solution {
public:
    int profitableSchemes(int maxMembros, int lucroMinimo, vector<int>& grupo, vector<int>& lucroPorEsquema) {
        int totalEsquemas = grupo.size();
        int MOD = (int)1e9 + 7;

        // pd[esquema_atual][membros_usados][lucro_obtido]: número de formas
        vector<vector<vector<int>>> pd(totalEsquemas + 1, vector<vector<int>>(maxMembros + 1, vector<int>(lucroMinimo + 1, 0)));

        // Caso base: 1 forma para 0 lucro, 0 membros, 0 esquemas (não fazer nada)
        pd[0][0][0] = 1;

        for (int idxEsquema = 1; idxEsquema <= totalEsquemas; idxEsquema++) {
            int membrosDoEsquema = grupo[idxEsquema - 1];
            int lucroDoEsquema = lucroPorEsquema[idxEsquema - 1];

            for (int membrosAtuais = 0; membrosAtuais <= maxMembros; membrosAtuais++) {
                for (int lucroAlcancado = 0; lucroAlcancado <= lucroMinimo; lucroAlcancado++) {
                    // Não incluir o esquema atual
                    pd[idxEsquema][membrosAtuais][lucroAlcancado] = pd[idxEsquema - 1][membrosAtuais][lucroAlcancado];

                    // Incluir o esquema atual (se houver membros suficientes)
                    if (membrosAtuais >= membrosDoEsquema) {
                        // Lucro que precisava ser obtido pelos esquemas anteriores.
                        int lucroAnteriorNecessario = max(0, lucroAlcancado - lucroDoEsquema);
                        
                        pd[idxEsquema][membrosAtuais][lucroAlcancado] = (pd[idxEsquema][membrosAtuais][lucroAlcancado] + pd[idxEsquema - 1][membrosAtuais - membrosDoEsquema][lucroAnteriorNecessario]) % MOD;
                    }
                }
            }
        }
        // Soma as formas que resultam em lucro
        int totalFormasLucrativas = 0;
        for (int membrosUsados = 0; membrosUsados <= maxMembros; membrosUsados++) {
            totalFormasLucrativas = (totalFormasLucrativas + pd[totalEsquemas][membrosUsados][lucroMinimo]) % MOD;
        }
        return totalFormasLucrativas;
    }
};