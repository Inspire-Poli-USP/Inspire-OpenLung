# Inspire-OpenLung

Seja muito bem vindo ao repositório do projeto OpenLung! Um respirador emergencial brasileiro para enfrentamento da COVID-19!

Um projeto da iniciativa [Inspire Poli-USP](https://www.poli.usp.br/inspire).

![Model of CITI-OpenLung](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/OpenLung_2020-Apr-01_05-59-26AM-000_CustomizedView25005130231_crop.png)

![Photo of Prototype Version 5](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Version%205.jpg)

---

## ATENÇÃO
- **Este é um projeto em andamento, não é um produto pronto.**
- **O projeto em seu atual estado NÃO DEVE SER USADO EM HUMANOS.**
- **O projeto em seu estado atual NÃO DEVE SER USADO EM ANIMAIS sem aprovação de comitês de ética legítimos.**
- **Caso futuramente aprovado por autoridades competentes, o projeto NÃO DEVE SER FABRICADO E DISTRIBUÍDO SEM OS CONTROLES DE QUALIDADE necessários para seu uso.**
- **As entidades e pessoas envolvidas no desenvolvimento desse projeto NÃO SE RESPONSABILIZAM pelo uso de má fé das informações deste projeto ou de projetos derivados deste, que possam por exemplo, mas não limitando-se a, ferir, prejudicar, ludibriar, adoecer, contaminar ou lesar quaisquer pessoas. Caso você julgue ter observado o mau uso deste projeto em quaisquer circunstâncias, nos informe imediatamente pelo contato inspire@usp.br . Sua colaboração é importante para a segurança deste projeto.**
- **Este projeto usa a licença [CERN-OHL-S 2.0](https://github.com/emersonmoretto/CITI-OpenLung/blob/master/License.md).**

---

# Índice

  1. [Porque mais um projeto como esse?](#porque-mais-um-projeto-como-esse)
  2. [Motivação](#motivação)
  3. [Onde queremos chegar](#onde-queremos-chegar)
  4. [Como colaborar](#como-colaborar)
  5. [Nossa Abordagem de Trabalho e Princícios de Design](#nossa-abordagem-de-trabalho-e-princípios-de-design)
  6. [Andamento do projeto](#andamento-do-projeto)
    6.1 [Tarefas pendentes](#tarefas-pendentes)
  7. [Principais Especificações](#principais-especificações)
  8. [Lista de Materiais](#lista-de-materiais)
    8.1 [Arquivos para corte a laser](#arquivos-para-corte-a-laser)
    8.2 [Partes Eletrônicas](#partes-eletrônicas)
  9. [Contato e Ajuda](#contato-e-ajuda)

| [Nossa Wiki](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki) | [Issues do Projeto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues) | [Pull-Requests](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/pulls) | [Licença de Uso](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/License.md) |
|-------------------------------------------------------------------------|----------------------------------------------------------------------------------|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|

---

# Porque mais um projeto como esse?

  Este é mais um projeto de design de ventilador pulmonar de acesso aberto com o intuito de ser barato, de fácil transporte e utilizando poucos materiais, usando principalmente um Ambu como gerador de fluxo de ar.

# Motivação
A expectativa é que teremos no Brasil um pico de casos a serem tratados pelo sistema de saúde em cerca de 3 semanas (por volta de 10 de Abril). Nesse momento a demanda por ventiladores pulmonares mecânicos será crítica, sendo uma das lamentáveis causas de morte pelo novo coronavirus devido a ausência de infraestrutura suficiente para a quantidade de número de pacientes. Estamos lutando contra o tempo para desenvolver um ventilador "open source" que possa ser fabricado antes que isso aconteça.

# Onde queremos chegar

A ideia é reproduzir um respirador profissional para terapia intensiva. Ou seja:
  - Não é um projeto que se restringe a apenas apertar o Ambú ritmicamente,
  - É um projeto para reproduzir uma curva de variação de pressão definida pelo usuário (médico ou fisioterapeuta),
  - Não queremos fazer um respirador igualmente sofisticado aos comercialmente disponíveis,
  - É um projeto para ter o mínimo necessário para manter pessoas vivas com segurança, [numa situação emergencial](#ATENÇÃO).

# Como Colaborar

Veja nosso [guia de como colaborar](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CONTRIBUTING.md). Nele deixamos claro o que é necessário para o projeto e de que maneira precisamos que você nos ajude. Presumimos que você pode colaborar de maneira autônoma, sem depender de nós - mas apoiamos fortemente interagir conosco e outras pessoas desenvolvendo esse mesmo projeto.

Caso nosso guia não seja o suficiente, você pode saber mais sobre quais são os debates do momento da comunidade entrando no [chat em grupo no Telegram](https://t.me/openlungpoliusp) e vendo a [nossa lista de emails](https://groups.google.com/forum/#!forum/inspireopenlung).

Vale dar uma olhada também no nosso [Código de Conduta](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CODE_OF_CONDUCT.md) para colaboração no projeto deste repositório.

# Nossa Abordagem de Trabalho e Princípios de Design

Para entender melhor como estamos fazendo esse trabalho, nossa abordagem é:
- Construir e testar rapidamente
  - *"mais mão-na-massa"*
- Basear decisões de projeto principalmente em dados de testes
  - *"o argumento mais forte é a evidência"*
- Garantir a qualidade do produto final
  - *"feito não é melhor que perfeito... é um equipamento para manter gente viva"*
- Considerar todos os projetos sendo feitos para encurtar trabalho
  - *"o porco do MIT E-VENT ficou vivo?"*
  - *"em que pé que está sistema de controle dos espanhóis do 'ReesistenciaTeam'?"*
  - *"o pessoal da UFRJ já começou a testar o que eles estão fazendo?"*
- Colaborar rapidamente com desenvolvedores/testadores empenhados em ajudar
  - *"o pessoal de Joinvile está cortando e testando nosso modelo mais rápido que a gente (risos)"*
Se você se identifica com essa abordagem, considere [colaborar com o projeto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CONTRIBUTING.md).

Também seguimos [Princípios de Design](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/DESIGN_PRINCIPLES.md) muito bem definidos no desenvolvimento e teste deste protótipo, bem como no eventual escalonamento para produção industrial.

Se você gostaria de contribuir usando uma abordagem de trabalho ou princípios diferentes destes, o encorajamos fortemente a desenvolver seu próprio repositório com sua nova proposta - colocando também a mão na massa!

Quanto mais tentativas diferentes houver, aumentamos a chance de sucesso de ter um ventilador que funcione com qualidade para enfrentar o desafio que teremos.

# Andamento do Projeto

Estamos documentando as informações do andamento do projeto principalmente na nossa [Wiki](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki).

Essa é uma resumida linha do tempo do projeto:

- 20 de Março: Início do Projeto
- 21 de Março: Modelagem 3D do Design e Fabricação do Protótipo V1
- 22 de Março: Testes do V1. Modelagem e Fabricação do Protótipo V2.2: ampliando posibilidades de posicionamento do motor e fuso trapezoidal.
- 23 de Março: Testes na versao 2.2 com um equipamento que mede volume, pressão e velocidade, obtivemos:
    27 ciclos por minuto
    250 mL de volume (este valor precisa alcancar 600 mL)
    30 cm H2O de pressão
    Conclusão: trocar o motor para NEMA 23 15kg de torque e usar um fuso de avanço maior.
- 24 de Março: Modelagem 3D e testes do Protótipo V3: agora projetado para motor NEMA 23 de 15kg de torque
- 25 de Março: Modelagem 3D e testes do Protótipo V4: Ajustes para diminuir atrito e ser mais resistente a torção
- 26 de Março: Primeira versão, ainda incompleta, do firmware
- 27 de Março: Desenvolvendo o firmware para primeiros testes usando sensor de pressão para controle
- 29 de Março: Implementação do controlador PID
- 30 de Março: Implementação e testes do firmware com controlador PID duplo (Gain Scheduling)
- 31 de Março: Versão 5, com ajustes para atingir uma maior área do ambú

## Tarefas Pendentes
- Toda a parte eletronica, PCB, quais sensores utilizar.
- Toda a parte de redundancia elétrica, isso tem que funcionar 24x7.

Dê também uma olhada nos nossos [Issues](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues) e [Pull-Requests](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/pulls).

# Principais Especificações

- Ser robusto. Deve funcionar continuamente sem falhas (ciclo de trabalho de 100%) por períodos de 14 dias, 24 horas por dia. Se necessário, a máquina pode ser substituída depois de cada período de 14 dias de uso ininterrupto.

- Prover ao mínimo duas possibilidades de configuração de volume de mistura de ar/O2 entregues por ciclos de respiração. Essas possibilidades devem ser 450ml +/- 10ml por respiração and 350ml +/- 10ml por respiração.

- Prover essa mistura de ar/Oxigêno a até um pico de 350 mm de H2O.

- Ter a capacidade de adaptação aos materiais de tubagem, mantendo o paciente pressurizado a todo momento a 150 mm H2O. 

- Ser ajustável para uma taxa de 12 a 20 ciclos/respirações por minuto.

- Entregar no mínimo 400 mL de mistura de ar/Oxigênio em não mais que 1,5 segundo. A funcionalidade de mudança dessa velocidade em que o ar é empurrado dentro do paciente é desejável, mas não essencial.

# Lista de Materiais

*Essa lista de materiais está desatualizada. Atualizaremos assim que possível.*

## Arquivos para corte a laser
Apenas 12 peças, usando chapas de de 5mm de espessura (estamos usando acrílico, mas pode ser outros materiais):
- 2x piston support V5.dxf	
- 2x piston V5.dxf	
- 2x side V5.dxf	
- 1x plate motor V5.dxf	
- 1x plate nut V5.dxf	
- 1x plate piston V5.dxf	
- 1x ambu support V5.dxf	
- 2x bottom plate V5.dxf	
- cut V5.ai	(arquivo com corte completo)
- cut V5.dxf (arquivo com corte completo)
- cut V5.pdf (arquivo com corte completo)

## Partes Eletrônicas
- 1x Nema 23 15kg
- 1x Arduino uno
- 1x Driver de motor de passo
- 20x M3 Screw 16mm
- 4x M4 Screw 16mm 
- Cabos, Fonte de 12v 5A, etc

# Contato e Ajuda

Se as informações aqui ainda não forem exatamente o que você está procurando, preencha [esse formulário rápido](https://forms.gle/2u1fxgFx3JDqjxeX7) que falaremos com você assim que possível!

**Obrigado por visitar nosso repositório e se interessar pelo projeto!**
