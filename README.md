<div align="center" >
  <img src="https://game.42sp.org.br/static/assets/achievements/so_longm.png" alt="So_long" width="175" height="175">
  <h1><i>Fase 1</h1></i>

</div>

# :trophy: Score
> A pontuação máxima que um projeto pode atingir na 42sp, considerando apenas a parte mandatório, é de 100 pontos. Caso seja realizado o bônus do projeto, a pontuação pode ser de 101 até 125. O objetivo do mandatório é recriar a função printf da biblioteca padrão do C, e o objetivo do bônus é adicionar algumas funcionalidades extras a função printf, as famigeradas flags.


# :information_source: About
> O projeto do so_long é o primeiro de interface gráfica que fazemos do common core, particularmente é um projeto que eu estava bem animado para fazer, pois já tinha muitas idéias para ele e que queria colocar em prática, já com o intuito de fazer um jogo diferentão do que os cadetes costumam entregar, daí tive a idéia de fazer uma recriação do Super Mario World, mais especificamente a fase de água.

> Para fazer-mos o So_long, como de praxe, usamos a linguagem C e, também, fomos apresentados a uma biblioteca gráfica, a Minilibx. A Minilibx é uma biblioteca gráfica que foi criada pela 42 para facilitar a criação de interfaces gráficas, ela é bem simples e intuitiva, porém, como ela é uma biblioteca gráfica, ela é bem diferente do que estamos acostumados a fazer, então é necessário um tempo para se acostumar com ela. As documentações da própria MiniLibx são bem fracas, porém tem um mini querido que fez uma documentação bem completa e que me ajudou muito, o link está abaixo:

> Em relação ao projeto, o objetivo do jogo é bem simples, você controla um personagem, no qual, para vencer nele, deve coletar todos os colecionáveis e ir até a saída. O bônus te dá mais liberdade no projeto, pois você deve criar um inimigo e, o mais legal de tudo, se quiser, pode criar novas funcionalidades para o seu jogo, deixando-o mais robusto. Isso é MUITO tentador, eu mesmo tive vários planos para tornar o meu jogo mais fiél ao Super Mario World original, mas que devido ao tempo investido para implementar essas funcionalidades, decidi cortar e focar no que era pedido no projeto e, caso sobrasse algum tempo, implementaria algumas funcionalidades extras.

> Pró-tip #1: **Valgrind é o seu melhor amigo, use ele desde o início!**
> Pró-tip #2: **Planeje como o seu game será, eu estava na pira de implementar a gravidade, pulos e funcionalidades do cano em meu jogo, mas que depois cortei isso e foquei no que era pedido no projeto. Foi um pouco frustrante ter que abandonar a ideia, então já começe com ideias realistas e plausíveis de serem feitas no seu tempo!**
> Pró-tip #3: **Pense em todas as verificações possíveis para o seu mapa, sério, uma pessoa que já fez o so_long será completamente capaz de fazer testes de fogo do seu mapa!**


# :test_tube: How to play
> Para jogar o So_long, você precisa certificar-se de ter a Minilibx instalada, caso não tenha, acesse esse repositório e instale-o:

> Após ter a Minilibx instalada, basta clonar o repositório do So_long, entrar na pasta e executar o comando make. Após isso, ele irá compilar a libft e o projeto so_long, gerando o arquivo executável '.o'. A partir disso, você pode executar o programa executável e passar um mapa a sua escola como segundo argumento. O comando para isso será assim:

```bash
./so_long ./maps/[mapa]
```

> **Importante:** há três mapas que são realmente jogáveis, o **map_basic.ber**, **bonus_basic.ber** e o mais legal de todos, **ultimate.ber**. O restante são mapas de verificações de erros, ele pode te dar alguma base para você evitar erros no seu mapa, mas não são jogáveis.  