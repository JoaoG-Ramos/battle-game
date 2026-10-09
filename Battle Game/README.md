# Battle Game

Um jogo simples de luta em turnos, onde você escolhe uma arma, um nível de dificuldade e luta contra um bot que faz escolhas aleatórias a cada rodada

## Demonstração

![Captura de tela do jogo](assets/image.png)

## Pré-requisitos

- Compilador C, como o GCC.
- Terminal para executar o programa.
- Git, caso queira obter o projeto clonando o repositório.

## Instalação

Abra o terminal e execute:

git clone https://github.com/JoaoG-Ramos/battle-game.git
cd battle-game


Compilar o programa

Na pasta do projeto, execute:

gcc main.c -o battle


Executar

Windows:

battle.exe

Linux/macOS:

./battle

## Como jogar

O jogo acontece em turnos, você escolhe suas ações durante o combate, enquanto o inimigo realiza ações aleatórias.

Armas disponíveis

O jogador pode escolher entre três armas com diferentes atributos:

Arma	Defesa	Ataque
Espada	  3	      9
Escudo	  9	      3
Machado	  5	      7

Cada arma apresenta uma combinação diferente de ataque e defesa, permitindo escolher uma estratégia de combate.

Ações de combate

Atacar: ataca o inimigo, dando o dano determinado pelo ataque de cada arma.
Defender: Você se defende, reduzindo o dano do inimigo pela metade (caso ele ataque na rodada).
Desviar: Você desvia, há uma chance aleatória de não tomar dano de acordo com a dificuldade do jogo.


Níveis de dificuldade

O jogo possui configurações de dificuldade que alteram os atributos do inimigo.

Dificuldade	     Vida do inimigo    Dano do inimigo	   Chance de desvio
Fácil	                50	               10	               50%
Médio	                100	               20	               50%
Difícil	                200	               45	               50%

## Estrutura do projeto

battle-game/

|-- README.md
|-- LICENSE
|-- main.c
|__ assets
     |-- image.png
 


Descrição dos arquivos

main.c: contém o código-fonte principal do jogo.
README.md: apresenta o projeto e explica como instalar, executar e utilizar o programa.
LICENSE: contém os termos da licença escolhida para o projeto.
assets: contém o arquivo image.png
image.png: imagem que demonstra o jogo em funcionamento.

## Licença

Este projeto está distribuído sob a licença MIT.

Consulte o arquivo [LICENSE](LICENSE) para ler o texto completo da licença.