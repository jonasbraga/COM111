// --------------------------
// definição de structs 
// --------------------------

// Definindo o struct do numero complexo
typedef struct complex Complex;


// --------------------------
// protótipos das funções
// --------------------------

// função para criar um novo numero complexo
Complex* complexCriar(int a, int b);

// função para somar 2 números complex
Complex* complexSomar(Complex* nc1, Complex* nc2);

// função para subtrair 2 números complexos
Complex* complexSubtrair(Complex* nc1, Complex* nc2);

// função para dividir 2 números complexos
Complex* complexDividir(Complex* nc1, Complex* nc2);

// função para multiplicar 2 números complexos
Complex* complexMultiplicar(Complex* nc1, Complex* nc2);

// função para imprimir o numero complexo
void complexImprimir(Complex* nc);

// função para liberar a memória de um numero complexo
void complexLiberar(Complex* nc);
