# Inspire-OpenLung
Um projeto da iniciativa [Inspire Poli-USP](https://www.poli.usp.br/inspire).

![Image of CITI-OpenLung](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/OpenLung_2020-Apr-01_05-59-26AM-000_CustomizedView25005130231_crop.png)

## ATENÇÃO
- **Este é um projeto em andamento, não é um produto pronto.**
- **O projeto em seu atual estado NÃO DEVE SER USADO EM HUMANOS.**
- **O projeto em seu estado autal NÃO DEVE SER USADO EM ANIMAIS sem aprovação de comitês de ética legítimos.**
- **Caso futuramente aprovado por autoridades competentes, o projeto NÃO DEVE SER FABRICADO E DISTRIBUÍDO SEM OS CONTROLES DE QUALIDADE necessários para seu uso.**
- **As entidades e pessoas envolvidas no desenvolvimento desse projeto NÃO SE RESPONSABILIZAM pelo uso de má fé das informações deste projeto ou de projetos derivados deste, que possam por exemplo, mas não limitando-se a, ferir, prejudicar, ludibriar, adoecer, contaminar ou lesar quaisquer pessoas. Caso você julgue ter observado o mau uso deste projeto em quaisquer circunstâncias, nos informe imediatamente pelo contato inspirepoliusp@gmail.com. Sua colaboração é importante para a segurança deste projeto.**
- **Este projeto usa a licença [CERN-OHL-S 2.0](https://github.com/emersonmoretto/CITI-OpenLung/blob/master/License.md).**

# Por que mais um projeto como esse?

Este é mais um projeto de design de ventilador pulmonar de acesso aberto com o intuito de ser barato, de fácil transporte e utilizando poucos materiais, usando principalmente um Ambu como gerador de fluxo de ar.

A expectativa é que teremos no Brasil um pico de casos a serem tratados pelo sistema de saúde em cerca de 3 semanas (por volta de 10 de Abril). Nesse momento a demanda por ventiladores pulmonares mecânicos será crítica, sendo uma das lamentáveis causas de morte pelo novo coronavirus devido a ausência de infraestrutura suficiente para a quantidade de número de pacientes. Estamos lutando contra o tempo para desenvolver um ventilador "open source" que possa ser fabricado antes que isso aconteça.

Nossa abordagem é:
- Construir e testar rapidamente
  - *"mais mão-na-massa"*
- Basear decisões de projeto principalmente em dados de testes
  - *"o argumento mais forte é a evidência"*
- Garantir a qualidade do produto final
  - *"feito não é melhor que perfeito... é um equipamento para manter gente viva"*
- Considerar todos os projetos sendo feitos para encurtar trabalho
  - *"o porco do MIT E-VENT ficou vivo?"*
  - *"em que pé que está sistema de controle dos espanhóis do 'ReesistenciaTeam'?"*
  - *"o pessoal da Unicamp já começou a testar o que eles estão fazendo?"*
- Colaborar rapidamente com desenvolvedores/testadores empenhados em ajudar
  - *"o pessoal de Joinvile está cortando e testando nosso modelo mais rápido que a gente (risos)"*

### Status

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
Apenas 12 peças:
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

### Partes Eletrônicas
- 1x Nema 23 15kg
- 1x Arduino uno
- 1x Driver de motor de passo
- 20x M3 Screw 16mm
- 4x M4 Screw 16mm 
- Cabos, Fonte de 12v 5A, etc

# Contato
- Preencher [esse formulário rápido](https://docs.google.com/forms/d/e/1FAIpQLSfJmSH-XnRPcUmkUvS9ZdUzZxjUVUDR-olO96t6SzpphNBRpQ/viewform).
