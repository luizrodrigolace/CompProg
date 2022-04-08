/*
 * Primeiro laboratório de Computadores e Programação
 *
 * A ideia do laboratório é mostrar ao aluno outras formas de fazer as operações
 * que ele já está acostumado a fazer, mas de formas diferentes.
 * Criamos esse desafio com o objetivo de fazê-lo pensar em diferentes formas de se
 * atingir o mesmo resultado. Se possível, tentando pensar em qual seria mais
 * eficiente.
 *
 * O aluno deverá usar apenas um subset de operações de C para realizar o que
 * for pedido no enunciado.
 *
 * Todas as operações permitidas serão especificadas em cada questão.
 *
 * Forma de avaliação:
 *      - Quantas operações o aluno utlizou para realizar a tarefa (dentro da quantidade aceitável)
 *      - Explicação do código -- deverá ser o mais claro possível (como qualquer
 *          código), imaginando que qualquer pessoa sem conhecimento prévio da
 *          matéria consiga entender o que foi feito.
 *      - As resoluções com menos operações do que a do monitor terão bonificação.
 *
 * Assinatura:
 *      Aluno: Luiz Rodrigo Lacé Rodrigues
 *      DRE: 118049873
 * 
 *      Aluno: Livia Barbosa Fonseca
 *      DRE: 118039721
 * 
 *      versão do GCC utilizada: 9.3.0
 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>


/* Número é par ou não
 *      Permitido:
 *          Operações: ~ & ^ | << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é par, retorna 0 caso contrário
 *
 *      Exemplo:
 *          ehPar(0) -> 1
 *          ehPar(2) -> 1
 *          ehPar(7) -> 0
 */
int32_t ehPar(int32_t x) {
    return  0x1 ^ (x & 0x1);
}
/** Raciocinio:
 *  Um numero é par ou não dependendo da sua divisão por 2.
 *  Como os numeros são internamente representados como bits
 *  em sequencia como somatorio, que na verdade são potencias
 *  (distintas) de 2.
 
 *  Assim  podemos verificar se um numero é par ou ímpar
 *  pelo seu bit menos signigicativo (mais à direita), visto que
 *  vai representar o resto da divisão desse numero por 2.
 * 
 *  Como o bit menos significativo é representado pela potencia 2**0, vai conter
 *  o valor 0 ou 1, que pode ser pego fazendo um "AND" (com &) com uma máscara 0x1, que vai
 *  zerar todos os bits, restando apenas o bit menos significativo intacto.
 *  
 *  Um numero par tem resto 0 quando dividido por 2, enquanto um ímpar tem resto 1.
 *  a função "ehPar" deseja retornar o contrario disso, isto é, caso um numero seja par
 *  ela deve retornar 1, e quando for impar, retornar 0. Para isso ocorrer, pegamos o bit
 *  obtido da operação acima e fazemos mais uma operação, agora um OU-EXCLUSIVO, novamente com uma
 *  máscara (0x1).
 * 
 */

/*
 * Módulo 8
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 1
 *
 *      Retorna x % 8
 *
 *      Exemplo:
 *          mod8(1) -> 1
 *          mod8(7) -> 7
 *          mod8(10) -> 2
 */
int32_t mod8(int32_t x) {
    return x & 0x7;
}
/** Raciocinio:
 *  Como queremos o resto da divisão do numero x por 8, vamos agora nos precupar com 
 *  os bits que são representados pela potencia de 2 até 2**2, visto que a partir da potencia
 *  2**3 (1000 em binário), já vamos encontrar numero multiplos de 8 (ou seja, resto 0).
 *  Para isso, vamos utilizar uma operação "AND" com a máscara 0x7 (0111 em binário), que vai manter
 *  os 3 primeiros numero da direita para a esquerda, retornando o resto da divisão por 8.
 * 
 * 
 * 

/* Negativo sem -
 *      Permitido:
 *          Operações: ~ & ^ | ! << >> +
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna -x
 *
 *      Exemplo:
 *          negativo(1) -> -1
 *          negativo(42) -> -42
 */
int32_t negativo(int32_t x) {
    return ~x + 1;
}
/**
 * Raciocinio:
 * Utilizamos o conceito de Complementa a 2, como visto nas aulas. 
 * Isto é, negando os bits do numero x e somando 1.

/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
    return  (x^y) ^ (x|y);
}
/**
 * Raciocinio:
 * 
 * Utilizamos a Tabela Verdade para a operação AND que é o resultado que queremos chegar:
 *  X |  Y |  X & Y
 *  0 |  0 |    0
 *  0 |  1 |    0 
 *  1 |  0 |    0   
 *  1 |  1 |    1 
 * 
 * 
 * Para chegarmos em um equivalente de AND, vamos precisar utilizar outras operações. 
 * Vamos começar pela operação OU :
 * 
 *  X |  Y | (X | Y)
 *  0 |  0 |    0
 *  0 |  1 |    1 
 *  1 |  0 |    1   
 *  1 |  1 |    1 
 * 
 * A tabela da operação OU possui a primeira e a ultima linha parecidas com a tabela AND, então
 * precisamos dar um jeito de modificar as linhas 2 e 3 da tabela.
 * 
 * A tabela do OU-EXCLUSIVO se dá por:
 * 
 *  X |  Y |  (Y ^ X)
 *  0 |  0 |    0
 *  0 |  1 |    1 
 *  1 |  0 |    1   
 *  1 |  1 |    0 
 * 
 * Onde temos que apenas as linhas do meio são ligadas. Sabendo disso vamos combinar esas duas tabelas.
 * Essa combinação vai ser feita também com outra operação de OU-EXCLUSIVO
 * 
 *   (Y ^ X)   | (X | Y)  | (Y ^ X) ^ (X | Y)
 *      0      |    0     |    0
 *      1      |    1     |    0
 *      1      |    1     |    0
 *      0      |    1     |    1
 * 
 * Que é justamente igual a tabela verdade da operação AND.
 *
 * 


/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> !
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */
int32_t ehIgual(int32_t x, int32_t y) {
    return !(x ^ y);
}
/**
 * Raciocinio:
 * 
 * Vamos utilizar a propriedade do OU-EXCLUSIVO para obter todos os bits desligados
 * caso x e y sejam iguais. Mas como a função quer que o retorno seja 1 para numeros iguais
 * então vamos negar o resultado dessa operação. Caso x e y sejam diferentes, então a operação do
 * OU-EXCLUSIVO vai retornar algo diferente de zero, que quando for negado, nos retorna zero.
 * 
 * 

/* Limpa bit n
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 4
 *      Monitor: 3
 *
 *      Retorna o x com o bit n = 0,
 *      n pode variar entre 0 e 31, do LSB ao MSB
 *
 *      Exemplo:
 *          limpaBitN(3, 0) -> 2
 *          limpaBitN(3, 1) -> 1
 */
int32_t limpaBitN(int32_t x, int8_t n) {
    return x & ~(0x1 << n);
}

/**
 * Queremos zerar o bit  que está a n bits a esquerda do primeiro bit de x, para que isso seja possivel
 * primeiro pegamos a máscara (0x1) e deslocamos n bits para a esquerda. Como queremos que o numero seja zero,
 * então negamos essa operação,assim todos os bits estarão ligados, menos o da posição que queremos modificar.
 * Quando fizermos uma operação AND com esse numero obtido e X, todo numero que for 1
 * vai continuar 1,o que for 0 vai continuar 0, mas o que for 1 e quisermos negar, vai ser tornar 0.

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    return (x >> p) & 0x1 ;
}

/**
 * Raciocinio:
 * 
 * Como queremos pegar o bit na posição p, vamos deslocar o numero x p posições para a direita.
 * Assim o bit menos significativo será aquele que queremos retornar. Vamos garantir que só 
 * esse bit seja retornado fazendo uma operação AND com a máscara 0x1, com isso todos os bits
 * serão desligados, mantendo apenas o estado do bit menos significativo.
 *

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */
int32_t byteEmP(int32_t x, uint8_t p) {
    return (x >> (p<<3)) & 0xFF;
}

/**
 * Raciocinio:
 * Para essa função vamos utilizar um raciocinio parecido com a função bitEmP.
 * Dessa vez vamos trabalhar com bytes. Vamos deslocar os bytes desejados da posição p
 * até a posição do byte menos significativo. Entretando, nossa operação de deslocamento
 * é baseada em bits, dessa forma, vamos precisar "deslocar o deslocamento". 
 * 
 * Como um byte equivale a 8 bits e cada deslocamento para a esquerda equivale a multiplicar por 2,
 * temos que deslocar p para a esquerda 3 posições, visto que 2**3 = 8.
 * 
 * Depois finalizamos com uma operação AND com a máscara 0xFF para retornarmos apenas o valor
 * do byte menos significativo e zerar o restante.
 * 

/*
 * Seta byte na posição p do inteiro x como y
 *      Permitido:
 *          Operações: << >> | ~ ! &
 *
 *      Número máximo de operações: 7
 *      Monitor: 5
 *
 *      Retorna x com o valor y no byte da posição p
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          setaByteEmP(0x12345678, 0xFF, 0) -> 0x123456FF
 *          setaByteEmP(0x12345678, 0xFF, 1) -> 0x1234FF78
 *          setaByteEmP(0x12345678, 0xFF, 2) -> 0x12FF5678
 *          setaByteEmP(0x12345678, 0xFF, 3) -> 0xFF345678
 *
 */
int32_t setaByteEmP(int32_t x, int32_t y, uint8_t p) {
    return  (x & ~(0xFF << (p << 3))) | (y << (p<<3)) ;
}
/**
 * Raciocinio:
 * 
 * Primeiramente vamos zerar o byte da posição p de x e depois, copia-lo em y na posição relativa a x.
 * A parte à esquerda da operação OU é analoga a função limpaBitN. 
 * Vamos pegar o byte 0xFF (oito primeiros bits iguais a 1 e o resto igual a 0) e deslocaremos 8*p (p<<3) posições
 * para a esquerda.
 * Negamos então a sequência de bits, o que nos resulta em uma sequência de 1 com o byte na posição p igual a zero.
 * Depois fazemos uma operação AND com essa sequência e o numero x, dessa forma zeramos o byte na posição p no
 * numero x.
 * 
 * Copiamos então o byte y na posição p em x. Isso é, deslocaremos o byte y (p<<3) para a esquerda, deixando o 
 * byte a ser copiado na posição p de y, enquanto os outros bytes em y estão zerados.
 * 
 * Finalmente, fazemos a operação OU entre a sequência obtida e a sequência de y com o
 * byte em p. O resultado será uma sequência com byte p igual ao de y e o resto dos bytes iguais aos de x.
 * 
 * 

/*
 * Minimo
 *      Permitido:
 *          Operações: << >> | ^ < > ~ ! & -
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna o menor numero entre x e y
 *
 *      Exemplo:
 *          minimo(10, 15) -> 10
 *          minimo(-2, -1) -> -2
 *          minimo(-1, 2) -> -1
 *
 */
int32_t minimo(int32_t x, int32_t y) {
    return y - ( ((x > y) - 1) & (y-x) );
}

/**
 * Raciocinio:
 * 
 * O que queremos é retornar o menor numero, se x for menor y, retornamos x, caso contrario,
 * se x for mair ou igual a y, retornarmos y.
 * 
 * Primeiramente vamos utilizar condiçoes comparativas, pois elas retornam true ou false. 
 * Vamos de transformar os resultados de true ou false (1 ou 0), em máscaras. Então subtraimos
 * 1 dessa comparação, forçando o resultado, quando verdadeiro ser igual a 0x0 e quando for 
 * falso igual a máscara 0xFFFFFFFF.
 * 
 * Quando obtemos (x>y) verdadeiro, vamos retornar y. Entretanto se for falso, x é quem será retornado.
 * Para isso acontecer, vamos subtrair (y-x) de y apenas quando (x > y) for falso. Do contrario, (y-x) 
 * será anulado.
 * 
 * Para chegamos no caso de (y-x), uma operação AND é feita entre ele e ((x>y) - 1).
 * Para (x>y) verdadeiro, (x>y)-1 será 0x0, resultando em 0;
 * Para (x>y) falso, (x>y)-1 é 0xFFFFFFFF, resultando em (y-x)
 * 
 * Finalmente, subtraimos de y essa operação, retornando o menor numero.
 * 
 * 
/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | & + ~
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */
int32_t negacaoLogica(int32_t x) {
  return ((x | ~x+1) >> 31) + 1;
}

/**
 * Raciocinio
 * 
 * Na função negacaoLogica, queremos retornar verdadeiro quando x for igual a 0 e falso quando
 * x for diferente de zero.
 * 
 * Sabemos da propriedade do Complemento a 2 onde o zero é o único número não negativo que possui
 * ele mesmo como Complemento a 2. Isso é, para um x não negativo, x == -x apenas quando x == 0.
 * 
 * Os numeros negativos têm o bit mais significativo igual a 1, assim como o COmplemento a 2
 * dos numeros positivos. Apenas o número zero possui possui o bit mais significativo em 0 nos dois
 * casos. Logo, ao fazer uma operação OU entre x e o Complemento a 2 de x, o bit mais significativo
 * da sequencia resultante sera igual a 1, para todos os numeros diferentes de zero.
 * 
 * Para manipular esse bit mais significativo, precisamos desloca-lo 31 posições para a direita (>> 31).
 * Como x é um inteiro com sinal, esse deslocamento será aritmético, onde o bit mais signiticativo será repetido
 * na sua devida posição a cada operação.
 * Assim, quand o bit mais significativo for 1, toda a sequencia ficará com bit em 1, entretanto 
 * se for 0, toda a sequencia ficará com bit em zero.
 * 
 * Logo, se o x era diferente de zero, agora a sequencia só terá bits ligados (0xFFFFFFFF ou -1).
 * Se era zero, a sequencia rá manter 0x0. 
 * 
 * Finalmente vamos somar 1 a essa sequencia para retornar 0 quando x for diferente de zero e 1
 * quando x for igual a zero.
 * 
 * 
*/
void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: limpaBitN");
    teste(limpaBitN(1,0), 0);
    teste(limpaBitN(0b1111,1), 0b1101);
    teste(limpaBitN(15,3), 7);
    teste(limpaBitN(-1,31), 2147483647);
    teste(limpaBitN(-1,0), -2);
    teste(limpaBitN(2147483647, 30), 1073741823);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: setaByteEmP");
    teste(setaByteEmP(0x00, 0xFF, 0), 0x000000FF);
    teste(setaByteEmP(0x00, 0xFF, 1), 0x0000FF00);
    teste(setaByteEmP(0x00, 0xFF, 2), 0x00FF0000);
    teste(setaByteEmP(0x00, 0xFF, 3), 0xFF000000);
    teste(setaByteEmP(0x01234567, 0x33, 2), 0x01334567);
    teste(setaByteEmP(0xdeadbeef, 0x00, 0), 0xdeadbe00);
    teste(setaByteEmP(0xdeadbeef, 0x00, 1), 0xdead00ef);
    puts("");

    puts("Teste: minimo");
    teste(minimo(0,1), 0);
    teste(minimo(0,10), 0);
    teste(minimo(1, 128), 1);
    teste(minimo(-1, 0), -1);
    teste(minimo(-1, -2), -2);
    teste(minimo(2147483647, 2147483646), 2147483646);
    teste(minimo(-2147483648, -2147483647), -2147483648);
    teste(minimo(-2147483648, -1), -2147483648);
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");

}
