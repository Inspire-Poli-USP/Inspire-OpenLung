# CITI-OpenLung

ATENÇÃO: ESTE PROJETO AINDA ESTÁ EM DESENVOLVIMENTO. NAO É UM PRODUTO PRONTO, INFELIZMENTE AINDA NAO ESTÁ APTO PARA FABRICAÇÃO. ESTAMOS FULL TIME INTEGRAL VOLTADOS PARA ESTE PROJETO.

Este é mais um projeto de design de ventilador pulmonar de acesso aberto com o intuito de ser barato, de fácil transporte e utilizando poucos materiais, usando principalmente um Ambu como gerador de fluxo de ar.

A expectativa é que teremos no Brasil um pico de casos a serem tratados pelo sistema de saúde em cerca de 3 semanas (por volta de 10 de Abril). Nesse momento a demanda por ventiladores pulmonares mecânicos será crítica, sendo uma das lamentáveis causas de morte pelo novo coronavirus devido a ausência de infraestrutura suficiente para a quantidade de número de pacientes. Estamos lutando contra o tempo para desenvolver um ventilador "open source" que possa ser fabricado antes que isso aconteça.

![Image of CITI-OpenLung](https://github.com/emersonmoretto/CITI-OpenLung/blob/master/images/Screen%20Shot%202020-03-21%20at%2004.50.34.png)

# Porque mais um projeto como esse?

Nós estamos tentando desenvolver um ventilador que seja acessível e possa ser disponibilizado em diferentes partes do Brasil.

### Status

- 20 de Março: Início do Projeto
- 21 de Março: Modelagem 3D do Design e Fabricação do Protótipo V1
- 22 de Março: Testes do V1. Modelagem e Fabricação do Protótipo V2.2: ampliando posibilidades de posicionamento do motor e fuso trapezoidal.
- 23 de Março: Testes na versao 2.2 com um equipamento que mede volume, pressão e velocidade, obtivemos:
    27 ciclos por minuto
    250 mL de volume (este valor precisa alcancar 600 mL)
    30 cm H2O de pressão
    Conclusão: trocar o motor para NEMA 23 15kg de torque e usar um fuso de avanço maior.
- 24 de Março: Modelagem 3D do Protótipo V3: agora projetado para motor NEMA 23 de 15kg de torque

### Tarefas Pendentes
- Toda a parte eletronica, PCB, quais sensores utilizar.
- Toda a parte de redundancia elétrica, isso tem que funcionar 24x7.

# Principais Especificações

- Ser robusto. Deve funcionar continuamente sem falhas (ciclo de trabalho de 100%) por períodos de 14 dias, 24 horas por dia. Se necessário, a máquina pode ser substituída depois de cada período de 14 dias de uso ininterrupto.

- Prover ao mínimo duas possibilidades de configuração de volume de mistura de ar/O2 entregues por ciclos de respiração. Essas possibilidades devem ser 450ml +/- 10ml por respiração and 350ml +/- 10ml por respiração.

- Prover essa mistura de ar/Oxigêno a até um pico de 350 mm de H2O.

- Ter a capacidade de adaptação aos materiais de tubagem, mantendo o paciente pressurizado a todo momento a 150 mm H2O. 

- Ser ajustável para uma taxa de 12 a 20 ciclos/respirações por minuto.

- Entregar no mínimo 400 mL de mistura de ar/Oxigênio em não mais que 1,5 segundo. A funcionalidade de mudança dessa velocidade em que o ar é empurrado dentro do paciente é desejável, mas não essencial.

# Lista de Materiais [EM PROGRESSO]

### Arquivos para corte a laser de 5mm de espessura
Apenas 10 peças:
- 2x piston V3.dxf
- 2x side V3.dxf
- 1x ambu support V3.dxf	
- 2x base support V3.dxf	
- 1x motor plate V3.dxf	
- 1x nut plate V3.dxf	
- 1x piston plate V3.dxf	

### Partes Eletrônicas
- 1x Nema 23 15kg
- 1x Arduino uno
- 1x Driver de motor de passo
- 20x M3 Screw 16mm
- 4x M3 Screw 12mm 
- Cabos, Fonte de 12v 6A, etc

# Como Ajudar e ser Ajudado [EM PROGRESSO]
Contato:
- emoretto @ usp.br
- wpp: +55 11 994840571
