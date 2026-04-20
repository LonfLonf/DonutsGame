# 🍩 Donut Survival (Em Desenvolvimento)

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Raylib](https://img.shields.io/badge/Engine-Raylib-red.svg)
![Status](https://img.shields.io/badge/Status-Work_in_Progress-yellow.svg)

## 📖 Sobre o Projeto

O **Donut Survival** é um jogo *Top-Down Shooter 2D* desenvolvido inteiramente em **C** utilizando a biblioteca **Raylib**. Neste jogo, você controla um simpático Donut que precisa sobreviver atirando seus próprios granulados para destruir bombas inimigas.

A principal motivação por trás deste projeto é o **aprendizado prático**. Ele serve como um laboratório pessoal para estudar lógica de programação para jogos, física vetorial e, de forma muito especial, **Pixel Art**.

## 🎨 Pixel Art e Design Visual

Uma das grandes marcas deste projeto é que **100% dos assets visuais foram criados por mim**. A intenção desde o início foi mergulhar no mundo do Game Design criando não apenas o código, mas também a identidade visual do zero. 

Os sprites originais incluem:
- 🍩 **O Donut** (Personagem principal)
- 💣 **A Bomba** (Inimigo)
- 💊 **O Granulado** (Projétil/Tiro)
- ❤️ **O Coração** (Sistema de Vida)

## ⚙️ Mecânicas Atuais (Features)

A base do jogo já conta com sistemas essenciais implementados:

* **Movimentação:** Controle de movimentação fluida através das teclas `W`, `A`, `S`, `D`.
* **Colisão com o Cenário:** Função `IsInsideOfMap` que impede que o Donut saia dos limites da tela.
* **Sistema de Mira e Tiro:** Ao clicar com o botão esquerdo do mouse, o Donut atira um granulado na direção exata do cursor. A trajetória é calculada matematicamente utilizando trigonometria (`atan2`, `sin`, `cos`).
* **Gestão de Entidades:** Estruturas preparadas para gerenciar múltiplos tiros (`MAX_BULLETS`) e inimigos (`MAX_BOMBS`).
* **Sistema de Vida (UI):** Cálculo de vida exibido dinamicamente na tela através de ícones de coração.

## 🏗️ Estrutura do Código

O código foi componentizado para facilitar a expansão futura:

* `main.c`: Contém o Game Loop principal, captura de inputs do jogador e chamadas de renderização.
* `donut.c` / `donut.h`: Responsável pelo gerenciamento do jogador (criação, destruição, vida) e pool de balas (tiros disparados).
* `graphic.c` / `graphic.h`: Funções matemáticas de suporte, como cálculos de delta de vetores e validação de limites de mapa.
* `bomb.h`: Estruturação inicial (`struct`) planejada para o comportamento das bombas inimigas.

## 🚀 Como Compilar e Rodar

Para executar este projeto, você precisará de um compilador **C** (como o GCC) e a biblioteca **Raylib** instalada e configurada no seu ambiente.

Exemplo de compilação via terminal (Linux/MinGW):
```bash
gcc main.c donut.c graphic.c -o donut_game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./donut_game
