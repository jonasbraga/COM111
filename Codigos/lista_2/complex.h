// --------------------------
// Definição de structs 
// --------------------------

// Definindo o struct do numero complexo
typedef struct complex Complex;

// --------------------------
// protótipos das funções
// --------------------------

// função para criar um novo numero complexo
Complex* complexCriar(float a, float b);

// função para somar 2 números complexos
void complexSomar(Complex* nc1, Complex* nc2, Complex* result);

// função para subtrair 2 números complexos
void complexSubtrair(Complex* nc1, Complex* nc2, Complex* result);

// função para dividir 2 números complexos
void complexDividir(Complex* nc1, Complex* nc2, Complex* result);

// função para multiplicar 2 números complexos
void complexMultiplicar(Complex* nc1, Complex* nc2, Complex* result);

// função para imprimir o numero complexo
void complexImprimir(Complex* nc);

// função para liberar a memória de um numero complexo
void complexLiberar(Complex* nc);