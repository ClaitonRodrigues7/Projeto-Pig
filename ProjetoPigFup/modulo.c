#include "lib.h"


//Variavel Global
int numeroDeJogadores = 0;
jogadores vetor[100];

int cadastroJogador(){

	    jogadores jogador;
	    int dificuldade = 0;

	    printf("Digite seu nome: ");
	    scanf("%s", &jogador.nome);

	    printf("\n************* Bem-vindo(a) %s *************\n", jogador.nome);
	    printf("\n1- Nível fácil 2- Nível difícil: \n");
	    printf("\nCaso digite uma opção inexistente o sistema irá reiniciar.\n");
	    scanf("%d", &dificuldade);



        if(dificuldade == 1 || dificuldade == 2){
	      menuJogo(jogador, dificuldade);

        }else{
          menu();
        }

}

void menu(){
	    system("cls");
	    int opcao = 0;
	    printf("\n***************** Bem-vindo *****************\n\n");
	    printf("1- Cadastrar jogador\n");
	    printf("2- Ver ranking de jogadores\n");
	    printf("3- Encerrar o progama\n");
	    printf ("\nO que deseja fazer? ");
	    scanf("%d", &opcao);

	    switch(opcao){
	        case 1:
	            cadastroJogador();
	            break;
	        case 2:
                mostraJogadores();
	            break;
	        case 3:
	            exit(0);
	            break;
	        default:
	            printf("Opção inválida!");
	    }
}

void menuJogo(jogadores jogador, int dificuldade){

	    int jogador1 = 0, jogador2 = 0;
	    int op = 0;
	    int para = 0;
	    int *ptrPara = &para;

	    int *ptr1 = &jogador1;
	    int *ptr2 = &jogador2;

	    if(dificuldade == 1){
		    while (para != 1){
		        jog1(ptr1, ptrPara, jogador);
		        if(*ptrPara == 1){
		            break;
		        }

		        jog2(ptr2, ptrPara, jogador);
		        if(*ptrPara == 1){
		            break;
		        }
		     }
		     do {
                printf("1- Retornar ao menu 2- Encerrar o progama:");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                     menu();
                     break;
                    case 2:
                        break;
                    default:
                        printf ("Opção inválida. Tente novamente!\n");
                }
            } while (op != 2);



	    } else if(dificuldade == 2){
	        while (para != 1) {
                jog1Dificil(ptr1, ptrPara, jogador);
                    if(*ptrPara == 1){
                        break;
                    }

                jog2Dificil(ptr2, ptrPara, jogador);
                    if(*ptrPara == 1){
                        break;
                    }
            }
            do {
                printf("1- Retornar ao menu 2- Encerrar o progama:");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                     menu();
                     break;
                    case 2:
                        break;
                    default:
                        printf ("Opção inválida. Tente novamente!\n");
                }
            } while (op != 2);

    }
}

int jog1 (int *ptr1,int *ptrPara, jogadores jogador){
	    char nome[] = {"Jogadores.txt"};

	    srand(time(NULL));
	    int dado = 0;
	    int op = 0;
	    int rodada = 0;
	    do {
            printf ("\nÉ a vez de %s jogar\n", jogador.nome);
            printf("1- Rodar o dado 2- Passar a vez 3- Parar de jogar:\n ", jogador.nome);
            scanf("%d", &op);

            switch(op){
                case 1:
                    dado = rand()% 6 + 1;
                    *ptr1 += dado;
                    rodada += dado;
                    if(dado == 1){
                        *ptr1 -= rodada;
                        printf("\n*********************************************************");
                        printf("\n Número 1, pontuação de %s nesta rodada está zerada\n", jogador.nome);
                        printf("*********************************************************\n");
                        op = 2;
                    }
                    printf("\nNúmero: %d\n", dado);
                    printf("Sua pontuação atual: %d\n", *ptr1);

                if(*ptr1 >= 100){
                    printf("\n*********************************************************");
                    printf("\n***********        %s ganhou!           *************\n", jogador.nome);
                    printf("*********************************************************\n");

                remove(nome);

                jogador.pontuacao = *ptr1;
                vetor[numeroDeJogadores] = jogador;
                numeroDeJogadores++;

                jogadores vetoraux[100];


                for (int i = 0; i < numeroDeJogadores - 1; i++) {
                    int indiceMaior = i;
                    for (int j = i + 1; j < numeroDeJogadores; j++) {
                        if (vetor[j].pontuacao > vetor[indiceMaior].pontuacao) {
                            indiceMaior = j;
                        }
                    }
                    if (indiceMaior != i) {
                        vetoraux[1] = vetor[i];
                        vetor[i] = vetor[indiceMaior];
                        vetor[indiceMaior]= vetoraux[1];
                    }
                }

	        FILE *file;
	        file = fopen("Jogadores.txt", "a");//abrir o arquivo e salvar o vetor de jogadores cadastrados

	        for(int i =0; i<numeroDeJogadores ;i++){
	            fprintf(file, "Nome: %s\nPontuação: %d\n\n", vetor[i].nome, vetor[i].pontuacao);
	        }
	        fclose(file);

	        return *ptrPara = 1;

	    }
        break;
                case 3:
                    return *ptrPara = 1;
                break;



	    }
	    } while (op != 2);

}

int jog2(int *ptr2, int *ptrPara, jogadores jogador){

	    srand(time(NULL));
	    int dado = 0;
	    int op = 0;
	    int rodada = 0;

	    do{

            printf("\n\nJogador 2 está rodando o dado...\n\n");

            op = rand()% 2 + 1;
            dado = rand()% 6 + 1;

            *ptr2 += dado;
            rodada += dado;

             if(dado == 1){
                *ptr2 -= rodada;
                printf("\n**********************************************************");
                printf("\nNúmero 1, pontuação do jogador 2 nesta rodada está zerada\n");
                printf("**********************************************************\n");
                op = 2;
            }

            printf("\nNúmero: %d\n", dado);
            printf("Pontuação atual do jogador 2: %d\n\n", *ptr2);

            if(*ptr2 >= 100){
                printf("\n********************************************");
                printf("\n***********  Jogador 2 ganhou! *************\n");
                printf("********************************************\n");
                return *ptrPara = 1;

            }

	    } while(op != 2);

}
	//Caso escolha o modo Dificil

int jog1Dificil(int *ptr1,int *ptrPara, jogadores jogador){
	    char nome[] = {"Jogadores.txt"};
	    srand(time(NULL));
	    int dado = 0;
	    int dado2 = 0;
	    int op = 0;
	    int rodada = 0;

	    do {
            printf ("\nÉ a vez de %s jogar\n", jogador.nome);
            printf("1- Rodar o dado 2- Passar a vez 3- Parar de jogar:\n ", jogador.nome);
            scanf("%d", &op);

	        switch(op){
                case 1:
                    dado = rand()% 6 + 1;
                    dado2 = rand()% 6 + 1;
                    *ptr1 += (dado+dado2);
                    rodada += (dado+dado2);

                    if(dado == 1 || dado2 == 1){
                        *ptr1 -= rodada;
                        printf("\n***************************************************");
                        printf("\nNúmero 1, pontuação de %s nesta rodada está zerada\n", jogador.nome);
                        printf("***************************************************\n");
                        op = 2;
                    }
                    printf("\nNúmeros: %d e %d\n", dado, dado2);
                    printf("Sua pontuação atual: %d\n", *ptr1);

	               if(*ptr1 >= 100){
                         printf("\n*********************************************************");
                         printf("\n***********        %s ganhou!          *************\n", jogador.nome);
                         printf("*********************************************************\n");

                        remove(nome);


                        jogador.pontuacao = *ptr1;
                        vetor[numeroDeJogadores] = jogador;
                        numeroDeJogadores++;

                        jogadores vetoraux[100];

                        for (int i = 0; i < numeroDeJogadores - 1; i++) {
                            int indiceMaior = i;
                            for (int j = i + 1; j < numeroDeJogadores; j++) {
                                if (vetor[j].pontuacao > vetor[indiceMaior].pontuacao) {
                                    indiceMaior = j;
                                }
                            }
                            if (indiceMaior != i) {
                                vetoraux[1] = vetor[i];
                                vetor[i] = vetor[indiceMaior];
                                vetor[indiceMaior]= vetoraux[1];
                            }
                        }



                    FILE *file;
                    file = fopen("Jogadores.txt", "a");

                    for(int i =0; i<numeroDeJogadores ;i++){
                        fprintf(file, "Nome: %s\n Pontuação: %d\n\n", vetor[i].nome, vetor[i].pontuacao);
                    }
                    fclose(file);

                    return *ptrPara = 1;

	    }
	    break;
	case 3:

	    return *ptrPara = 1;
	    break;
	    }
	    } while (op != 2);

	}

int jog2Dificil(int *ptr2, int *ptrPara, jogadores jogador){
    srand(time(NULL));
    int dado = 0;
    int dado2 = 0;
    int op = 0;
    int rodada = 0;

    do{
        printf("\n\nJogador 2 está rodando os dados...\n\n");

	    op = rand()% 2 + 1;
	    dado = rand()% 6 + 1;
	    dado2 = rand()% 6 + 1;

	    *ptr2 += (dado+dado2);
	    rodada += (dado+dado2);

	     if(dado == 1 || dado2 == 1){
	        *ptr2 -= rodada;
	        printf("\n**********************************************************");
	        printf("\nNumero 1, pontuação do jogador 2 nesta rodada está zerada\n");
	        printf("**********************************************************\n");
	        op = 2;
	    }

	    printf("\nNúmeros: %d e %d\n", dado, dado2);
	    printf("Pontuação atual do jogador 2: %d\n\n", *ptr2);

	    if(*ptr2 >= 100){
	        printf("\n********************************************");
	        printf("\n*********** O jogador 2 ganhou! *************\n");
	        printf("********************************************\n");
	        return *ptrPara = 1;

	    }
    }while(op != 2);

}

void mostraJogadores(){
	    int op = 0;
	    FILE *arq;
	    arq = fopen("Jogadores.txt", "r");

	    char frase[100];

	    printf ("\n------------------- RANKING -----------------\n");

	    while(fgets(frase, 100, arq) != NULL){
	        printf("%s", frase);
	    }
	    fclose(arq);

	    printf ("\n---------------------------------------------\n");


	    do {
            printf("1- Retornar ao menu 2- Encerrar o progama: ");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    menu();
                    break;
                case 2:
                    break;
                default:
                    printf ("Opção inválida. Tente novamente!\n");
                }
        } while (op != 2);
        return;
}
