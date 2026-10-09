# Battle Game

Um jogo simples de luta em turnos, onde você escolhe uma arma, um nível de dificuldade e luta contra um bot que faz escolhas aleatórias a cada rodada

## Demonstração

![Captura de tela do jogo](assets/image.png)

## Pré-requisitos

- Compilador C, como o GCC.
- Terminal para executar o programa.
- Git, caso queira obter o projeto clonando o repositório.

## Instalação

1. Abrir a pasta do projeto

Extraia os arquivos entregues e abra o terminal na pasta que contém o arquivo main.c.

Se você estiver no diretório que contém a pasta battle-game-main, execute:

cd "battle-game-main/Battle Game"

Confirme que o arquivo main.c está nessa pasta.

2. Compilar o programa
gcc main.c -o battle

3. Executar o jogo

No Windows:

battle.exe

No Linux ou macOS:

./battle

## Como jogar

O jogo acontece em turnos, você escolhe suas ações durante o combate, enquanto o inimigo realiza ações aleatórias.

Armas disponíveis

O jogador pode escolher entre três armas com diferentes atributos, esses atributos são multiplicados pelo valor base, onde a vida é 10 e o ataque 2, logo quemescolhe a espada dá 18 de dano e tem 30 de vida:

Arma	Defesa	Ataque

Espada	  3	      9
Escudo	  9	      3
Machado	  5	      7

Cada arma apresenta uma combinação diferente de ataque e defesa, permitindo escolher uma estratégia de combate.

Ações de combate

Atacar: ataca o inimigo, dando o dano determinado pelo ataque de cada arma.
Defender: Você se defende, reduzindo o dano do inimigo pela metade (caso ele ataque na rodada).
Desviar: Você desvia, há uma chance de 50% de não tomar dano caso o inimigo ataque.

As mesmas ações e condições valem para o inimigo, ou seja, se ele bloquear e você atacar, ele leva metade do dano, se ele desviar, ele também tem uma chance de desviar que sempre é de 20%


Níveis de dificuldade

O jogo possui configurações de dificuldade que alteram os atributos do inimigo.

Dificuldade	   Vida do inimigo   Dano do inimigo  

Fácil	              50	            10      
Médio	              100	            20	 
Difícil	              200	            45	

## Exemplo de uso

Escolher a arma

Quando o jogo solicitar a escolha da arma, digite:

1 — Espada
2 — Escudo
3 — Machado

Escolher a dificuldade

Quando o jogo solicitar a dificuldade, digite:

1 — Fácil
2 — Médio
3 — Difícil

Exemplo de partida

Digite 1 para escolher a espada.
Digite 1 para escolher a dificuldade fácil.
Durante o combate, selecione a ação de ataque conforme o número apresentado pelo programa.

Resultado possível: se o jogador atacar e o inimigo não conseguir evitar o golpe, o inimigo perderá vida. O dano exato dependerá das regras de cálculo e dos modificadores aplicados naquela rodada.

Como as ações do inimigo e os resultados de desvio podem ser aleatórios, essa sequência não garante o mesmo resultado em todas as partidas.

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