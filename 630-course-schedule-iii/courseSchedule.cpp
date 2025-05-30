class Solution {
public:
    int scheduleCourse(vector<vector<int>>& cursos) { 
        if(cursos.size() <= 0) return 0; 
        // Ordena os cursos pelo menor prazo limite
        sort(cursos.begin(), cursos.end(), [](const vector<int>& curso_a, vector<int>& curso_b) {
            return curso_a[1] < curso_b[1]; 
        });
        priority_queue<int> heap_duracao; // Max-heap para guardar a duração dos cursos 
        int tempo_acumulado = 0;         
        // Itera sobre os cursos
        for(auto curso : cursos) {
            tempo_acumulado += curso[0]; // Adiciona a duração do curso ao tempo acumulado
            heap_duracao.push(curso[0]); // Adiciona a duração do curso ao max-heap
            if(tempo_acumulado > curso[1]) {
                tempo_acumulado -= heap_duracao.top(); // Remove a duração do curso mais longo já adicionado
                heap_duracao.pop();                    // Remove curso mais longo do heap
            }
        }
        return heap_duracao.size();
    }
};