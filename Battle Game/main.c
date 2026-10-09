#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// vida base = 10, dano base = 2 (multiplicam pelo valor da arma), vida inimigo fácil = 50, médio = 100 e difícil = 200, dano inimigo: fácil = 10, médio = 20, difícil = 45, chance esquiva sua: fácil: 50%, médio: 35%, difícil: 20%, chance esquiva inimigo: fácil: 20%, médio: 35%, difícil: 50%, bonus ataque após defesa = +50%, bonûs esquiva = duas tentativas na próxima;

int vida, dano, dificuldade, arma, vidainimigo, danoinimigo, acaoinimigo, acao, desvio, bonusataque, bonusdesvio;

int main() {

srand(time(NULL));

printf("Battle Game");

printf("\n\nEscolha uma arma:\n\n1: Espada (def = 3, atq = 9)\n2: Escudo (def = 9, atq = 3)\n3: machado (def = 5, atq = 7)\n");
scanf("%d", &arma);

printf("\nDigite o nivel do seu adversário:\n\n1: nivel fácil\n2: nivel médio\n3: nivel difícil\n");
scanf("%d", &dificuldade);

if(arma != 1 && arma != 2 && arma != 3){
printf("Resposta invalida, verifique a arma selecionada");
}

else if(arma == 1){

if(dificuldade != 1 && dificuldade != 2 && dificuldade != 3){
    printf("Resposta invalida, verifique a dificuldade selecionada");
}
else if(dificuldade == 1){
    vida = 30;
    dano = 18;
    vidainimigo = 50;
    danoinimigo = 10;
    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        if(bonusataque == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano+dano/2; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        bonusataque = 0;
        }else{
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        }
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        bonusataque = 1;
        printf("\n+50 porcento de dano no próximo ataque: %d", dano+dano/2);
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        bonusdesvio = 1;
        printf("\nDuas tentativas de desvio na próxima rodada");
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
        if(bonusdesvio==1){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        bonusdesvio = 0;
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
         if(bonusataque == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - (dano + dano/2)/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else{
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        if(bonusataque == 1){
        printf("\nO inimigo não conseguiu desviar!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano + dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
        else{
        printf("\nO inimigo não conseguiu desviar!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        }
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);       
    }
else if(dificuldade == 2){
    vida = 30;
    dano = 18;
    vidainimigo = 100;
    danoinimigo = 20;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
     else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\n+50 porcento de dano no próximo ataque: %d", dano+dano/2);
        bonusataque = 1;
        
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
            printf("\nVocê desviou!");
            printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
            bonusdesvio = 1;
        } 
        
        else if(bonusdesvio == 1){
            
            desvio=rand()%100 + 1;
            
        if(desvio<=50){
            printf("\n\nSegunda tentativa pelo bonûs...");
            printf("\nVocê desviou!");
            printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        }
        else{
            printf("\n\nSegunda tentativa pelo bonûs...");
            printf("\nVocê não conseguiu desviar!");
            vida = vida - danoinimigo;
            printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        }
        bonusdesvio = 0;
        }
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
     }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);
}

else if(dificuldade == 3){
    vida = 30;
    dano = 18;
    vidainimigo = 200;
    danoinimigo = 45;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}

}

else if(arma == 2){

if(dificuldade != 1 && dificuldade != 2 && dificuldade != 3){
    printf("Resposta invalida, verifique a dificuldade selecionada");
}
else if(dificuldade == 1){
    vida = 90;
    dano = 6;
    vidainimigo = 50;
    danoinimigo = 10;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}
else if(dificuldade == 2){
    vida = 90;
    dano = 6;
    vidainimigo = 100;
    danoinimigo = 20;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}
else if(dificuldade == 3){
    vida = 90;
    dano = 6;
    vidainimigo = 200;
    danoinimigo = 45;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}

}

else{

if(dificuldade != 1 && dificuldade != 2 && dificuldade != 3){
    printf("Resposta invalida, verifique a dificuldade selecionada");
}
else if(dificuldade == 1){
    vida = 50;
    dano = 14;
    vidainimigo = 50;
    danoinimigo = 10;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}
else if(dificuldade == 2){
    vida = 50;
    dano = 14;
    vidainimigo = 100;
    danoinimigo = 20;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}
else if(dificuldade == 3){
    vida = 50;
    dano = 14;
    vidainimigo = 200;
    danoinimigo = 45;

    do{
        printf("\n\nDigite sua ação:\n1: Atacar\n2: Defender\n3: Desviar\n");
        scanf("%d", &acao);
        acaoinimigo = rand()%3 + 1;

    if(acaoinimigo == 1&&acao == 1){
        printf("\nO inimigo atacou!");
        printf("\nVocê atacou!");
        vida = vida - danoinimigo;
        vidainimigo = vidainimigo - dano; 
        printf("\nVida = %d\nVida inimigo = %d", vida, vida);
    }
    else if(acaoinimigo == 1&&acao == 2){
        printf("\nO inimigo atacou!");
        printf("\nVocê se defendeu!");
        vida = vida - danoinimigo/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 1&&acao == 3){
        printf("\nO inimigo atacou!");
        desvio=rand()%100 + 1;

        if(desvio<=50){
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nVocê não conseguiu desviar!");
        vida = vida - danoinimigo;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
     else if(acaoinimigo == 2&&acao == 1){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê atacou!");
        vidainimigo = vidainimigo - dano/2;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 2){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 2&&acao == 3){
        printf("\nO inimigo bloqueou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 1){
        desvio=rand()%100 + 1;
        if(desvio<=20){
        printf("\nO inimigo desviou!");
        printf("\nVocê atacou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
        } 
        else{
        printf("\nO inimigo não conseguiu desviar!");
         printf("\nVocê atacou!");
         vidainimigo = vidainimigo - dano;
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);    
        }
    }
    else if(acaoinimigo == 3&&acao == 2){
        printf("\nO inimigo desviou!");
        printf("\nVocê bloqueou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
     else if(acaoinimigo == 3&&acao == 3){
        printf("\nO inimigo desviou!");
        printf("\nVocê desviou!");
        printf("\nVida = %d\nVida inimigo = %d", vida, vidainimigo);
     }
}while(vidainimigo > 0 && vida > 0);

}

}

return 0;
}