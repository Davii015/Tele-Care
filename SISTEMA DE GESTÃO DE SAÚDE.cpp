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
    int horario; // Horário em formato de 24 horas
} Consulta;

// Função para verificar se o paciente é maior de 18 anos
int verificarIdade(int idade) {
    if (idade >= 18) {
        return 1;
    } else {
        printf("Atenção: Você precisa ter 18 anos ou mais para acessar o sistema sem autorização dos responsáveis.\n");
        return 0;
    }
}

// Função para agendar uma consulta
void agendarConsulta(Paciente p) {
    Consulta c;
    printf("Digite o nome do médico: ");
    scanf("%s", c.nomeMedico);
    printf("Digite a especialidade do médico: ");
    scanf("%s", c.especialidade);
    printf("Digite a data da consulta (DD/MM/AAAA): ");
    scanf("%s", c.data);
    printf("Digite o horário da consulta (24h - Ex: 14 para 14:00): ");
    scanf("%d", &c.horario);
    
    // Verificando se o horário é adequado para consultas
    if (c.horario < 8 || c.horario > 17) {
        printf("Horário inválido! O horário de consultas é entre 08:00 e 17:00.\n");
    } else {
        printf("Consulta agendada com sucesso!\n");
        printf("Médico: %s\nEspecialidade: %s\nData: %s\nHorário: %d:00\n", c.nomeMedico, c.especialidade, c.data, c.horario);
    }
}

// Função simulando a verificação de dados de saúde de dispositivos vestíveis
void verificarCondicoesSaude() {
    int batimentoCardiaco, glicose;
    printf("Verificando condições de saúde...\n");

    // Simulação de leitura de dados
    batimentoCardiaco = 75;  // Batimentos por minuto
    glicose = 90;            // Nível de glicose

    // Estruturas condicionais para determinar o status de saúde
    if (batimentoCardiaco < 60 || batimentoCardiaco > 100) {
        printf("Atenção! Seus batimentos cardíacos estão fora da faixa normal: %d BPM\n", batimentoCardiaco);
    } else {
        printf("Seus batimentos cardíacos estão normais: %d BPM\n", batimentoCardiaco);
    }

    if (glicose < 70 || glicose > 140) {
        printf("Atenção! Seu nível de glicose está fora da faixa normal: %d mg/dL\n", glicose);
    } else {
        printf("Seu nível de glicose está normal: %d mg/dL\n", glicose);
    }
}

int main() {
    Paciente paciente;
    int opcao, idadeValida;

    printf("==== Sistema de Gestão de Saúde ====\n");

    // Cadastro de paciente
    printf("Digite seu nome: ");
    scanf("%s", paciente.nome);
    printf("Digite sua idade: ");
    scanf("%d", &paciente.idade);
    printf("Digite seu CPF: ");
    scanf("%s", paciente.cpf);

    // Verificação da idade
    idadeValida = verificarIdade(paciente.idade);

    if (!idadeValida) {
        printf("Por favor, peça a autorização de um responsável para continuar.\n");
        return 0; // Encerrar o programa se a idade for inválida
    }

    do {
        // Menu principal do sistema
        printf("\n--- Menu ---\n");
        printf("1. Agendar consulta\n");
        printf("2. Verificar condições de saúde\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
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
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
