#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000

  struct User {
      int id;
      char nome[50];
      char email[50];
      char sexo[15];
      char endereco[100];
      double altura;
      int vacina;
};

  void cadastrarUsuario(struct User users[], int *totalUsers);
  void editarUsuario(struct User users[], int totalUsers);
  void excluirUsuario(struct User users[], int *totalUsers);
  void buscarUsuarioPorEmail(struct User users[], int totalUsers);
  void imprimirUsuarios(struct User users[], int totalUsers);

  int main() {
    struct User users[MAX_USERS];
    int totalUsers = 0;
    char opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Editar usuário\n");
        printf("3 - Excluir usuário\n");
        printf("4 - Buscar usuário por e-mail\n");
        printf("5 - Imprimir todos os usuários\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario(users, &totalUsers);
                break;
            case '2':
                editarUsuario(users, totalUsers);
                break;
            case '3':
                excluirUsuario(users, &totalUsers);
                break;
            case '4':
                buscarUsuarioPorEmail(users, totalUsers);
                break;
            case '5':
                imprimirUsuarios(users, totalUsers);
                break;
            case '0':
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}

void cadastrarUsuario(struct User users[], int *totalUsers) {
    if (*totalUsers < MAX_USERS) {
        users[*totalUsers].id = rand();

        printf("Nome completo: ");
        scanf("\n %s", users[*totalUsers].nome);

        printf("Email: ");
        scanf(" %s", users[*totalUsers].email);

        if (strchr(users[*totalUsers].email, '@') == NULL) {
            printf("Email inválido. Tente novamente.\n");
            return;
        }

        printf("Sexo (Feminino/Masculino/Indiferente): ");
        scanf(" %s", users[*totalUsers].sexo);

        if (strcmp(users[*totalUsers].sexo, "Feminino") != 0 &&
            strcmp(users[*totalUsers].sexo, "Masculino") != 0 &&
            strcmp(users[*totalUsers].sexo, "Indiferente") != 0) {
            printf("Sexo inválido. Tente novamente.\n");
            return;
        }

        printf("Endereço: ");
        scanf("\n %s", users[*totalUsers].endereco);

        printf("Altura (entre 1 e 2 metros): ");
        scanf("%lf", &users[*totalUsers].altura);

        if (users[*totalUsers].altura < 1.0 || users[*totalUsers].altura > 2.0) {
            printf("Altura inválida. Tente novamente.\n");
            return;
        }

        printf("Vacina (1 para sim, 0 para não): ");
        scanf("%d", &users[*totalUsers].vacina);

        if (users[*totalUsers].vacina != 0 && users[*totalUsers].vacina != 1) {
            printf("Opção de vacina inválida. Tente novamente.\n");
            return;
        }

        printf("Usuário cadastrado com sucesso!\n");
        (*totalUsers)++;
    } else {
        printf("Limite de usuários atingido. Não é possível cadastrar mais usuários.\n");
    }
}

  void editarUsuario(struct User users[], int totalUsers) {
    if (totalUsers > 0) {
        int id;
        printf("Digite o ID do usuário que deseja editar: ");
        scanf("%d", &id);

        for (int i = 0; i < totalUsers; i++) {
            if (users[i].id == id) {
                printf("Novo nome completo: ");
                scanf("\n %s", users[i].nome);

                printf("Novo email: ");
                scanf(" %s", users[i].email);

                if (strchr(users[i].email, '@') == NULL) {
                    printf("Email inválido. Edição cancelada.\n");
                    return;
                }

                printf("Novo sexo (Feminino/Masculino/Indiferente): ");
                scanf(" %s", users[i].sexo);

                if (strcmp(users[i].sexo, "Feminino") != 0 &&
                    strcmp(users[i].sexo, "Masculino") != 0 &&
                    strcmp(users[i].sexo, "Indiferente") != 0) {
                    printf("Sexo inválido. Edição cancelada.\n");
                    return;
                }

                printf("Novo endereço: ");
                scanf("\n %s", users[i].endereco);

                printf("Nova altura (entre 1 e 2 metros): ");
                scanf("%lf", &users[i].altura);

                if (users[i].altura < 1.0 || users[i].altura > 2.0) {
                    printf("Altura inválida. Edição cancelada.\n");
                    return;
                }

                printf("Nova vacina (1 para sim, 0 para não): ");
                scanf("%d", &users[i].vacina);

                if (users[i].vacina != 0 && users[i].vacina != 1) {
                    printf("Opção de vacina inválida. Edição cancelada.\n");
                    return;
                }

                printf("Usuário editado com sucesso!\n");
                return;
            }
        }

        printf("Usuário com ID %d não encontrado.\n", id);
    } else {
        printf("Não há usuários cadastrados para editar.\n");
    }
}

void excluirUsuario(struct User users[], int *totalUsers) {
    if (*totalUsers > 0) {
        int id;
        printf("Digite o ID do usuário que deseja excluir: ");
        scanf("%d", &id);

        for (int i = 0; i < *totalUsers; i++) {
            if (users[i].id == id) {

                for (int j = i; j < *totalUsers - 1; j++) {
                    users[j] = users[j + 1];
                }
                (*totalUsers)--;
              
                printf("Usuário excluído com sucesso!\n");
                return;
            }
        }

        printf("Usuário com ID %d não encontrado.\n", id);
    } else {
        printf("Não há usuários cadastrados para excluir.\n");
    }
}

  void buscarUsuarioPorEmail(struct User users[], int totalUsers) {
    if (totalUsers > 0) {
        char email[50];
        printf("Digite o email do usuário que deseja buscar: ");
        scanf(" %s", email);

        for (int i = 0; i < totalUsers; i++) {
            if (strcmp(users[i].email, email) == 0) {
                printf("Usuário encontrado:\n");
                printf("ID: %d\n", users[i].id);
                printf("Nome: %s\n", users[i].nome);
                printf("Email: %s\n", users[i].email);
                printf("Sexo: %s\n", users[i].sexo);
                printf("Endereço: %s\n", users[i].endereco);
                printf("Altura: %.2lf\n", users[i].altura);
                printf("Vacina: %d\n", users[i].vacina);
                return;
            }
        }

        printf("Usuário com email %s não encontrado.\n", email);
    } else {
        printf("Não há usuários cadastrados para buscar.\n");
    }
}

  void imprimirUsuarios(struct User users[], int totalUsers) {
    if (totalUsers > 0) {
        printf("Lista de usuários cadastrados:\n");
        for (int i = 0; i < totalUsers; i++) {
            printf("ID: %d\n", users[i].id);
            printf("Nome: %s\n", users[i].nome);
            printf("Email: %s\n", users[i].email);
            printf("Sexo: %s\n", users[i].sexo);
            printf("Endereço: %s\n", users[i].endereco);
            printf("Altura: %.2lf\n", users[i].altura);
            printf("Vacina: %d\n", users[i].vacina);
            printf("\n");
        }
    } else {
        printf("Não há usuários cadastrados para imprimir.\n");
    }
}
