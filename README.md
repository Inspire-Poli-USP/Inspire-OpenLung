# Inspire-OpenLung

<p align="center">
<a href="https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/LICENSE" alt="License CERN Open Hardware V2">
        <img src="https://img.shields.io/badge/license-CERN_Open_Hardware_V2-green" /></a>

<a href="https://t.me/openlungpoliusp" alt="Chat em grupo no Telegram">
        <img src="https://img.shields.io/badge/Telegram_chat_%F0%9F%92%AC-blue" /></a>

<a href="https://groups.google.com/forum/#!forum/inspireopenlung" alt="Lista de email">
        <img src="https://img.shields.io/badge/mail_list_%F0%9F%93%A7-blueviolet" /></a>

<a href="https://inspire-poli-usp.github.io/Inspire-OpenLung/" alt="Docs website">
        <img src="https://img.shields.io/badge/Docs_website-yellow" /></a>
</p>

Seja muito bem vindo ao repositório do projeto de hardware livre OpenLung! Um respirador emergencial brasileiro para enfrentamento da COVID-19!

Um projeto da iniciativa [Inspire Poli-USP](https://www.poli.usp.br/inspire), uma de oito iniciativas da Universidade de São Paulo envolvendo viabilização de respiradores para enfrentamento à pandemia. Para saber mais sobre essa e outras iniciativas [veja esse link](https://prp.usp.br/usp-e-covid-19/).

Considere também apoiar o financiamento de pesquisas na USP para o combate à COVID-19 [através do programa USP Vida](https://www5.usp.br/uspvida/).

![Model of CITI-OpenLung](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/OpenLung_2020-Apr-01_05-59-26AM-000_CustomizedView25005130231_crop.png)

[![Photo of Prototype Version 5](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Version%205.jpg)](https://youtu.be/7Tz8H8FaeOk)

(Clique na imagem acima para ver um vídeo do protótipo em ação)

* * *

## :warning: ATENÇÃO :warning:

-   **Este é um projeto em andamento, não é um produto pronto.**
-   **O projeto em seu atual estado NÃO DEVE SER USADO EM HUMANOS.**
-   **O projeto em seu estado atual NÃO DEVE SER USADO EM ANIMAIS sem aprovação de comitês de ética legítimos.**
-   **Caso futuramente aprovado por autoridades competentes, o projeto NÃO DEVE SER FABRICADO E DISTRIBUÍDO SEM OS CONTROLES DE QUALIDADE necessários para seu uso.**
-   **As entidades e pessoas envolvidas no desenvolvimento desse projeto NÃO SE RESPONSABILIZAM pelo uso de má fé das informações deste projeto ou de projetos derivados deste, que possam por exemplo, mas não limitando-se a, ferir, prejudicar, ludibriar, adoecer, contaminar ou lesar quaisquer pessoas. Caso você julgue ter observado o mau uso deste projeto em quaisquer circunstâncias, nos informe imediatamente pelo contato [inspire@usp.br](mailto:inspire@usp.br) . Sua colaboração é importante para a segurança deste projeto.**
-   **Este projeto usa a licença [CERN-OHL-S 2.0](https://github.com/emersonmoretto/CITI-OpenLung/blob/master/LICENSE).**

* * *

## :exclamation: ATUALIZAÇÃO IMPORTANTE :exclamation:

Devido a questões jurídicas, o entendimento dos coordenadores do projeto é de que o software que realiza o controle do Ambu, bem como os dados experimentais associados aos testes dos algoritmos de controle, permanecerão **privados** até o término dos testes.

Lamentamos essas medidas e estamos discutindo a **possibilidade** do compartilhamento restrito dessas informações com grupos de contribuidores especiais (como centros de pesquisa, universidades, empresas etc) interessados em contribuir com o projeto. Mas isso ainda não está decidido.

Existem [outros repositórios](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Outros-Projetos) **independentes da iniciativa Inspire** que estão desenvolvendo, disponibilizando ou prometem disponibilização de firmwares, como por exemplo o [OdaMV](https://github.com/eduoda/odamv), o [ReesistenciaTeam](https://gitlab.com/reesistencia/reespirator/-/tree/dev/rees_firmware), o [hitecnologia/cov19](https://github.com/hitecnologia/cov19) ou o [BMV OpenLung](https://gitlab.com/open-source-ventilator/ventilator/OpenLung/-/tree/master/) - bem como [essa lista de projetos](https://soptechint.com/ventilators). Contudo não nos responsabilizamos pelo uso destes firmwares com nosso hardware e reforçamos a atenção para os [importantes avisos no início desta página](#warning-atenção-warning).

Caso tenha alguma dúvida, pedido ou reclamação, entre em contato com [inspire@usp.br](mailto:inspire@usp.br).

Vale notar que, desde o dia 14 de Abril, o projeto não recebe atualizações em relação ao respirador. Portanto, o que se encontra nesse repositório é tudo que foi feito até essa data e não incorre em problemas jurídicos para equipe do Inspire. Você pode acompanhar as últimas atualizações através dos [Vídeos Relatórios](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/LICENSE) e das [Aparições na mídia](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Apari%C3%A7%C3%B5es-na-m%C3%ADdia)

* * *

# Índice

| [Nossa Wiki](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki) | [Issues do Projeto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues) | [Pull-Requests](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/pulls) | [Licença de Uso](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/LICENSE) |
| ----------------------------------------------------------------------- | -------------------------------------------------------------------------------- | --------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |

1.  [Porque mais um projeto como esse?](#porque-mais-um-projeto-como-esse)
2.  [Motivação](#motivação)
3.  [Onde queremos chegar](#onde-queremos-chegar)
4.  [Questão Regulatória](#questão-regulatória)
5.  [Como colaborar](#como-colaborar)
6.  [Nossa Abordagem de Trabalho e Princícios de Design](#nossa-abordagem-de-trabalho-e-princípios-de-design)
7.  [Andamento do projeto](#andamento-do-projeto)</br>
    7.1 [Tarefas pendentes](#tarefas-pendentes)
8.  [Principais Especificações Desejadas](#principais-especificações-desejadas)
9.  [Lista de Materiais](#lista-de-materiais)</br>
    9.1 [Partes Mecânicas](#partes-mecânicas)</br>
    9.2 [Partes Eletrônicas](#partes-eletrônicas)</br>
    9.3 [Partes "Médicas"](#partes-médicas)
10. [Contato e Ajuda](#contato-e-ajuda)
11. [Doe para o projeto](#doe-para-o-projeto)
12. [Licença](#licença)


# Por que mais um projeto como esse

Este é mais um projeto de design de ventilador pulmonar de acesso aberto com o intuito de ser barato, de fácil transporte e utilizando poucos materiais, usando principalmente um Ambu como gerador de fluxo de ar.

Iniciamos este projeto porque até então haviam apenas propostas online com conteúdo parcialmente disponível, e apenas levando em consideração o contexto dos países em que tais propostas estavam/estão sendo desenvolvidas. Nosso projeto se baseia em [Princípios](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/Principios_e_abordagem.md) que colocam um peso maior na indisponibilidade de recursos e custo.

Vale notar também que o ventilador pulmonar inspire utiliza em sua maioria produtos que podem ser encontrados com realativa facilidade no mercado Brasileiro.

# Motivação

A expectativa é que teremos no Brasil um pico de casos a serem tratados pelo sistema de saúde pelo final do mês de Abril. Nesse momento a demanda por ventiladores pulmonares mecânicos será crítica, sendo uma das lamentáveis causas de morte pelo novo coronavirus devido a ausência de infraestrutura suficiente para a quantidade de número de pacientes. Estamos lutando contra o tempo para desenvolver um ventilador "open source" que possa ser fabricado antes que isso aconteça.

# Onde queremos chegar

A ideia final é reproduzir um respirador profissional para terapia intensiva. Ou seja:

-   Não é um projeto que se restringe a apenas apertar o Ambú ritmicamente,
-   É um projeto para reproduzir uma curva de variação de pressão definida pelo usuário (médico ou fisioterapeuta),
-   Não queremos fazer um respirador igualmente sofisticado aos comercialmente disponíveis,
-   É um projeto para ter o mínimo necessário para manter pessoas vivas com segurança, [numa situação emergencial](#warning-atenção-warning).

Veja a página ["Entenda o Problema"](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema) para informações mais específicas sobre o escopo técnico deste projeto.

Onde queremos chegar com este braço open source da iniciativa Inspire é desenvolver os módulos centrais do ventilador, que identificamos como sendo:

-   o "apertador de Ambu",
-   e o algoritmo de controle.

Os demais módulos como eletrônica própria (sem usar arduino), interface operador-máquina e _packaging_ do sistema todo **por enquanto** não são open source. O firmware e softwares associados ao algoritmo de controle **serão compartilhados de maneira restrita** com contribuidores especiais, pelas razões explicitadas [aqui](#exclamation-atualização-importante-exclamation).

Contudo, você pode desenvolver esses outros módulos segundo seu próprio contexto local de logística e recursos. Uma produção deslocalizada e flexível é uma possibilidade em aberto para fabricação dos respiradores a tempo. Encorajamos possíveis colaboradores deste projeto a seguir o exemplo de forks desre repositório e desenvolverem suas próprias soluções complementares ao que estamos fazendo.

# Questão regulatória

Uma questão em aberto para todos os projetos open source de ventiladores para suporte no combate à COVID-19 é se esses projetos terão aprovação regulatória para serem usados em pacientes.

A expectativa é que em algum momento esse processo se torne mais facilitado por alguma ação do governo e agências reguladoras.

Para saber mais a respeito das informações que temos a respeito dessa atual situação, dê uma olhada na [página da wiki](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Regulamenta%C3%A7%C3%A3o) sobre este assunto ou na conversa do [Issue #14](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/14).

# Como Colaborar

Veja nosso [guia de como colaborar](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CONTRIBUTING.md). Nele deixamos claro o que é necessário para o projeto e de que maneira precisamos que você nos ajude. Presumimos que você pode colaborar de maneira autônoma, sem depender de nós - mas apoiamos fortemente interagir conosco e outras pessoas desenvolvendo esse mesmo projeto.

Caso nosso guia não seja o suficiente, você pode saber mais sobre quais são os debates do momento da comunidade entrando no [chat em grupo no Telegram](https://t.me/openlungpoliusp) e vendo a [nossa lista de emails](https://groups.google.com/forum/#!forum/inspireopenlung).

Vale dar uma olhada também no nosso [Código de Conduta](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CODE_OF_CONDUCT.md) para colaboração no projeto deste repositório.

# Nossa Abordagem de Trabalho e Princípios de Design

Acreditamos que toda as tentativas de designs possíveis de respiradoras são válidas por aumentarem as possibilidades de sucesso de ALGUM protótipo de respirador funcionar com qualidade ([veja essa lista detalhada](https://soptechint.com/ventilators) de alguns projetos) e chegar até quem precisa. Na nossa tentativa em particular, [definirmos alguns Princípios fundamentais de Design e nossa Abordagem de Trabalho](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/Principios_e_abordagem.md) no desenvolvimento e teste deste protótipo.

Se você se identifica com essa abordagem, considere [colaborar com o projeto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CONTRIBUTING.md).

Se você gostaria de contribuir usando uma abordagem de trabalho ou princípios diferentes destes, o encorajamos fortemente a desenvolver seu próprio repositório com sua nova proposta - colocando também a mão na massa!

# Andamento do Projeto

Estamos documentando as informações do andamento do projeto principalmente na nossa [Wiki](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki).

Essa é uma resumida linha do tempo do projeto:

-   20 de Março: Início do Projeto
-   21 de Março: Modelagem 3D do Design e Fabricação do Protótipo V1
-   22 de Março: Testes do V1. Modelagem e Fabricação do Protótipo V2.2: ampliando posibilidades de posicionamento do motor e fuso trapezoidal.
-   23 de Março: Testes na versao 2.2 com um equipamento que mede volume, pressão e velocidade, obtivemos:
      27 ciclos por minuto
      250 mL de volume (este valor precisa alcancar 600 mL)
      30 cm H2O de pressão
      Conclusão: trocar o motor para NEMA 23 15kg de torque e usar um fuso de avanço maior.
-   24 de Março: Modelagem 3D e testes do Protótipo V3: agora projetado para motor NEMA 23 de 15kg de torque
-   25 de Março: Modelagem 3D e testes do Protótipo V4: Ajustes para diminuir atrito e ser mais resistente a torção
-   26 de Março: Primeira versão, ainda incompleta, do firmware
-   27 de Março: Desenvolvendo o firmware para primeiros testes usando sensor de pressão para controle
-   29 de Março: Implementação do controlador PID
-   30 de Março: Implementação e testes do firmware com controlador PID duplo (Gain Scheduling)
-   31 de Março: Versão 5, com ajustes para atingir uma maior área do ambú
-   1 de Abril a 12 de Abril: Implementações e testes de diferentes algoritmos de controle e testes de capacidade em diferentes cenários reais.
-   13 de Abril a 16 de Abil: [Testes em animais](https://www1.folha.uol.com.br/colunas/monicabergamo/2020/04/ventilador-da-poli-sera-testado-em-animais-e-pessoas-e-pode-ser-lancado-em-uma-semana.shtml)

Vale notar que essa linha do tempo não é atualizada desde 14 de abril. Você pode acompanhar as últimas atualizações através dos [Vídeos Relatórios](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/LICENSE) e das [Aparições na mídia](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Apari%C3%A7%C3%B5es-na-m%C3%ADdia).

## Tarefas Pendentes

-   Testes em Humanos (devidamente regularizado e aprovado por comitês de ética competentes)

Dê também uma olhada nos nossos [Issues](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues) e [Pull-Requests](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/pulls).

# Principais Especificações Desejadas

-   Ser robusto. Deve funcionar continuamente sem falhas (ciclo de trabalho de 100%) por períodos de 14 dias, 24 horas por dia. Se necessário, a máquina pode ser substituída depois de cada período de 14 dias de uso ininterrupto.

-   Prover ao mínimo duas possibilidades de configuração de volume de mistura de ar/O2 entregues por ciclos de respiração. Essas possibilidades devem ser 450ml +/- 10ml por respiração and 350ml +/- 10ml por respiração.

-   Prover essa mistura de ar/Oxigêno a até um pico de 350 mm de H2O.

-   Ter a capacidade de adaptação aos materiais de tubagem, mantendo o paciente pressurizado a todo momento a 150 mm H2O.

-   Ser ajustável para uma taxa de 12 a 20 ciclos/respirações por minuto.

-   Entregar no mínimo 400 mL de mistura de ar/Oxigênio em não mais que 1,5 segundo. A funcionalidade de mudança dessa velocidade em que o ar é empurrado dentro do paciente é desejável, mas não essencial.

# Lista de Materiais

## Partes Mecânicas

-   Acoplador de Garra Drylin E para eixo redondo de 10 mm de diâmetro
-   Fuso Trapezoidal de 10 mm de diâmetro, 15 cm de comprimento e passo de 25 mm
-   Castanha de Latão TR10 e passo de 2,5 mm
-   20x parafusos M3 de 16mm de comprimento
-   20x porcas M3
-   4x parafusos M4 de 16mm de comprimento
-   Chapa de acrílico de 5mm com no máximo 76 cm x 40 cm
    -   Resulta em **apenas 12 peças**:
        -   2x "Suporte de Pistão" (V5)
        -   2x "Pistões" (V5)
        -   2x "Ponta do Pistão" (V5)
        -   1x "Chapa do Motor" (V5)
        -   1x "Chapa da Castanha" (V5)
        -   1x "Chapa do Pistão" (V5)
        -   1x "Suporte do Ambu" V5
        -   2x "Conector Inferior" (V5)

## Partes Eletrônicas

-   1x Nema 23 15kg
-   1x Arduino uno
-   1x Driver DW322E da Leadshine
-   Fonte de 12v 5A
-   4x jumpers macho-macho

## Partes "Médicas"

-   1x Ambu com capacidade de 1600 mL
-   2x Tubo traqueia de 1 m
-   1x Válvula unidirecional de CPAP com acoplamento para válvula PEEP
-   1x Válvula PEEP com ajuste de 5 a 15 cmH2O

_(OBS: as "Partes Médicas" podem variar de nome em cada região; outros produtos médicos de finalidade semelhante podem ser usados)_

# Contato e Ajuda

Se as informações aqui ainda não forem exatamente o que você está procurando, preencha [esse formulário rápido](https://forms.gle/2u1fxgFx3JDqjxeX7) que falaremos com você assim que possível!

# Doe para o projeto

Caso você queira demonstrar seu suporte ao projeto, você tem a opção de doar para a iniciativa Inspire, através do [link](
https://www.vakinha.com.br/vaquinha/inspire-respirador-da-escola-politecnica-da-usp-fase-2 ). Toda doação é bem vinda.

Caso não possa doar, não tem problema. Você também pode demonstrar suporte ao projeto colocando uma ⭐️ nesse repositório. Obrigado!

# Licença

[CERN Open Hardware V2](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/LICENSE)

**Obrigado por visitar nosso repositório e se interessar pelo projeto!**
