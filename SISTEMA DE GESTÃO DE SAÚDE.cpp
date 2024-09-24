#include <stdio.h>
#include <string.h>

// Definindo as estruturas para armazenar dados dos pacientes e consultas
typedef struct {
    char nome[50];
    int idade;
    char cpf[15];
} Paciente;

typedef struct {
    char nomeMedico[50];
    char especialidade[50];
    char data[10];
    int horario; // Hor�rio em formato de 24 horas
} Consulta;

// Fun��o para verificar se o paciente � maior de 18 anos
int verificarIdade(int idade) {
    if (idade >= 18) {
        return 1;
    } else {
        printf("Aten��o: Voc� precisa ter 18 anos ou mais para acessar o sistema sem autoriza��o dos respons�veis.\n");
        return 0;
    }
}

// Fun��o para agendar uma consulta
void agendarConsulta(Paciente p) {
    Consulta c;
    printf("Digite o nome do m�dico: ");
    scanf("%s", c.nomeMedico);
    printf("Digite a especialidade do m�dico: ");
    scanf("%s", c.especialidade);
    printf("Digite a data da consulta (DD/MM/AAAA): ");
    scanf("%s", c.data);
    printf("Digite o hor�rio da consulta (24h - Ex: 14 para 14:00): ");
    scanf("%d", &c.horario);
    
    // Verificando se o hor�rio � adequado para consultas
    if (c.horario < 8 || c.horario > 17) {
        printf("Hor�rio inv�lido! O hor�rio de consultas � entre 08:00 e 17:00.\n");
    } else {
        printf("Consulta agendada com sucesso!\n");
        printf("M�dico: %s\nEspecialidade: %s\nData: %s\nHor�rio: %d:00\n", c.nomeMedico, c.especialidade, c.data, c.horario);
    }
}

// Fun��o simulando a verifica��o de dados de sa�de de dispositivos vest�veis
void verificarCondicoesSaude() {
    int batimentoCardiaco, glicose;
    printf("Verificando condi��es de sa�de...\n");

    // Simula��o de leitura de dados
    batimentoCardiaco = 75;  // Batimentos por minuto
    glicose = 90;            // N�vel de glicose

    // Estruturas condicionais para determinar o status de sa�de
    if (batimentoCardiaco < 60 || batimentoCardiaco > 100) {
        printf("Aten��o! Seus batimentos card�acos est�o fora da faixa normal: %d BPM\n", batimentoCardiaco);
    } else {
        printf("Seus batimentos card�acos est�o normais: %d BPM\n", batimentoCardiaco);
    }

    if (glicose < 70 || glicose > 140) {
        printf("Aten��o! Seu n�vel de glicose est� fora da faixa normal: %d mg/dL\n", glicose);
    } else {
        printf("Seu n�vel de glicose est� normal: %d mg/dL\n", glicose);
    }
}

int main() {
    Paciente paciente;
    int opcao, idadeValida;

    printf("==== Sistema de Gest�o de Sa�de ====\n");

    // Cadastro de paciente
    printf("Digite seu nome: ");
    scanf("%s", paciente.nome);
    printf("Digite sua idade: ");
    scanf("%d", &paciente.idade);
    printf("Digite seu CPF: ");
    scanf("%s", paciente.cpf);

    // Verifica��o da idade
    idadeValida = verificarIdade(paciente.idade);

    if (!idadeValida) {
        printf("Por favor, pe�a a autoriza��o de um respons�vel para continuar.\n");
        return 0; // Encerrar o programa se a idade for inv�lida
    }

    do {
        // Menu principal do sistema
        printf("\n--- Menu ---\n");
        printf("1. Agendar consulta\n");
        printf("2. Verificar condi��es de sa�de\n");
        printf("3. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                agendarConsulta(paciente);
                break;
            case 2:
                verificarCondicoesSaude();
                break;
            case 3:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
