# Ajuda da Comunidade com a Válvula PEEP

Estamos desenvolvendo nossa própria solução, mas também acreditamos que a comunidade pode desenvolver uma solução **mais rapidamente e talvez melhor do que a nossa**.

Dê uma olhada no [Issue #43](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43) para informações mais atualizadas sobre o desenvolvimento da válvula PEEP. Felizmente recebemos ótimas recomendações da comunidade, muitas das contribuições discutidas no Issue #43 podem ser encontradas no fim dessa página.

## Restrições

Ainda não podemos divulgar nossa solução online devido a [possíveis problemas jurídicos](https://github.com/Inspire-Poli-USP/Inspire-OpenLung#exclamation-atualiza%C3%A7%C3%A3o-importante-exclamation) envolvendo tecnologias potencialmente proprietárias, mas esperamos logo poder compartilhá-las depois do aval de especialistas.

## Prazo

Inicialmente essa ajuda da comunidade foi lançada como um desafio, com prazo até dia 15 de Abril. Esse prazo foi dado para podermos já usar essa nova válvula [em experimentos em animais](https://www1.folha.uol.com.br/colunas/monicabergamo/2020/04/ventilador-da-poli-sera-testado-em-animais-e-pessoas-e-pode-ser-lancado-em-uma-semana.shtml?origin=folha#comentarios).

Desenvolvemos uma solução que ainda pode melhorar, então por isso abrimos o problema para que a comunidade pudesse colaborar.

## Descrição

   A válvula que controla a pressão PEEP ([mais info sobre a PEEP aqui](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema#press%C3%B5es)) que estamos usando não aguenta uso prolongado (você pode vê-la [nesse vídeo que fizemos](https://www.youtube.com/watch?v=mwwxAkmB0J0&feature=youtu.be) - é a parte com peças plásticas laranjas). Após cerca de 30min de funcionamento contínuo, começa a ficar imprecisa - ou seja: ela mantém uma PEEP diferente da que indicada pelo marcador. Além disso sua resolução é muito pequena, podendo ser regulada para, por exemplo: 5 cmH2O, 10 cmH20 ou 15 cmH2O, mas não valores entre estes (Como 12 cmH20 ou 7cmH20, por exemplo).

   A regulação da PEEP com mais liberdade pelos fisioterapeutas e médicos é muito importante para determinar a PEEP ideal para cada paciente (chamada de "Titulação de PEEP"). Essa PEEP ideal evita barotraumas e melhora a oxigenação alveolar, o que é crítico para pacientes com COVID-19. Por isso, desenvolver uma solução que melhore a válvula PEEP é crucial para o projeto.

## Problemas a se resolver

-   Imprecisão da válvula PEEP
-   Baixa resolução da válvula PEEP
-   Controle rudimentar (manual)

## Objetivos

  Sem deixar de seguir nossos [princípios e abordagem](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/Principios_e_abordagem.md), precisamos que você desenvolva propostas de válvulas PEEP com as seguintes funcionalidades:

-   Ser acionada eletronicamente;
-   Ser capaz de atuar em um intervalo de pressão de pelo menos 5 cmH2O à 15 cmH2O;
-   Ter uma resolução de controle de no mínimo 1 cmH2O - ou seja, podendo ter valores de 5,6,7,8 ..., 13, 14, 15 cmH2O;
-   Ter precisão nos valores configurados - ou seja, por exemplo: selecionar uma pressão de 7 cmH2O deve manter uma medida de pressão **real** de 7 cmH20;
-   Ter uma velocidade de mudança de valores de pressão de no mínimo 1 cmH2O por segundo;
-   Capaz permitir uma vazão de até 600 mL por segundo;
-   Garantir a performance de controle ao longo do tempo - por exemplo: o valor de pressão PEEP selecionado não pode mudar de valor depois de 30min de uso;
-   Usar materiais baratos e acessíveis - por exemplo: peças automotivas;
-   Não violar propriedade intelectual existente - por exemplo: patentes.

## Recursos Necessários

Para este desafio assumimos que você tem acesso a:

-   Alguma maneira de criar uma pressão de ar, como por exemplo:
    -   Bomba de ar,
    -   Assoprador,
    -   Cilindro de ar comprimido, etc;
-   Alguma maneira de medir pressão, por exemplo:
    -   Sensores eletrônicos de pressão,
    -   Coluna de água num tubo transparente, etc;
-   Eletrônica de prototipagem rápida para testes de controle da sua válvula PEEP, por exemplo:
    -   Arduino (qualquer modelo).

## Entregas

Ajudar nesse desafio significa que você vai entregar completa ou parcialmente:

-   Imagens ou vídeos que mostrem como funciona o seu sistema;
-   Especificações dos materiais que vocẽ usou;
-   Gráficos e tabelas com dados que você mediu;
-   Códigos de controle usados nos testes que você fez.

## Local de Discussão

Coloquem suas propostas, dados de medição, fotos, links para vídeos, desenhos, especificações e quaisquer outras informações relacionadas a este desafio no [Issue #43](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43).

-   Se você não tem uma conta no github, crie e uma e contribua por lá! Essa parte do repositório funciona como um fórum de internet, então não se preocupe por enquanto com "commits", "pull-requests" e outros "palavrões" do github.
-   Você também pode discutir [pelo Telegram](https://t.me/openlungpoliusp), mas não coloque informações lá em detrimento do [Issue #43](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43). O [Issue #43](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43) é o melhor lugar para todos acompanharem de uma maneira rápida e mais organizada o que você está fazendo, além de deixar minimamente registrado neste repositório a sua contribuição.

# Como Resultados serão apresentados

Ajudando nesse desafio, a sua válvula pode ser potencialmente usada [nos testes que faremos essa semana](https://www1.folha.uol.com.br/colunas/monicabergamo/2020/04/ventilador-da-poli-sera-testado-em-animais-e-pessoas-e-pode-ser-lancado-em-uma-semana.shtml).

Reconheceremos publicamente sua contribuição caso a usemos como solução principal, além de ficarmos pessoalmente muito gratos por sua boa vontade em ajudar e gentileza em contribuir.

Caso sua contribuição não acabe sendo usada no final, com certeza ela contribuirá para acelerarmos nosso desenvolvimento. É impossível testarmos todas as possibilidades ao mesmo tempo, mas é importante que a maioria delas sejam testadas por vocês

Além disso, a sua contribuição estimula que este projeto seja cada vez mais aberto, [apesar das restrições](https://github.com/Inspire-Poli-USP/Inspire-OpenLung#exclamation-atualiza%C3%A7%C3%A3o-importante-exclamation).

# :warning: Avisos Importantes :warning:

-   Este "desafio" não representa qualquer compromisso da iniciativa Inspire, como por exemplo, mas não limitando-se a, acatar, orientar ou auxiliar quaisquer propostas sobre o exposto nesta página.
-   A iniciativa Inspire não se responsabiliza por quaisquer danos materiais ou prejuízos financeiros que possam ocorrer a qualquer pessoa que use o disposto nesta página para qualquer finalidade. Também não se responsabiliza por quaisquer acidentes que ocorram durante quaisquer ações de pessoas pautadas direta ou indiretamente pelas informações dispostas nesta página.
-   Se você souber de quaisquer ações que estejam sendo tomadas por pessoas usando as informações dispostas nessa página, que direta ou indiretamente possam colocar em risco a segurança e saúde de qualquer ser humano ou animal, recomendamos fortemente que denuncie a autoridades competentes da sua localidade.

# Resultados

  Primeiramente gostariamos de agradecer a todos que dispuseram a contribuir para o projeto nesse repositório, e comentaram no [Issue #43](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43). Toda contribuição nesse repositório é de extrema ajuda, e nos motiva a manter o repositório movimentado e com as devidas atualizações sobre o projeto! Abaixo estão algumas das contribuições nesse repositório que mais contribuiram para o desenvolvimento da solução atual (Todas elas foram muito boas, principalmente por fomentar a discussão nas Issues).

  Tivemos soluções submetidas pelos seguintes usuários [VitorFrost](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43#issuecomment-614904015), [adalmirabdala](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43#issuecomment-612733690), [felipeosi](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43#issuecomment-614931211), [Imsrv](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43#issuecomment-614984436)e [GustavoMutra](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43#issuecomment-615903073).  Todas ajudaram muito no desenvolvimento, por fomentarem um ambiente de discussão e aprendizato na issue. Por fim [foi desenvolvido nesse repositório](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/43#issuecomment-614721287) uma solução seguindo a ideia do VitorForst. Acreditamos que a solução usada atinja os objetivos mencionados, resolvendo os problemas de imprecisão e baixa resolução da válvula PEEP.
