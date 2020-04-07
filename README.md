# CITI-OpenLung
 
## ATENÇÃO! ANTES DE COMPARTILHAR OU REALIZAR DOWNLOADS, ESTEJA CIENTE DOS SEGUINTES ITENS:
 
**Este projeto ainda está em desenvolvimento. Não é um produto pronto e ainda não está apto a fabricação em escala. Ainda temos muito trabalho a ser feito, verifique o status do projeto e veja como pode colaborar.**
 
 
An another **[IN PROGRESS]** open source, low cost, low resource, quick deployment ventilator design that utilizes a Ambu-bag as a core component.  'War' against COVID-19.
 
>We are expecting (here in Brazil) the peak of covid-19 in 3 weeks (April 10th). The demand for mechanical ventilator is critical, it is the biggest cause of death of the covid-19. We are fighting time to develop an open-source ventilator that can be manufactured on time.
 
![Image of CITI-OpenLung](https://github.com/HPparanhos/CITI-OpenLung/blob/master/Images/WhatsApp%20Image%202020-04-03%20at%2001.14.49.jpeg)
 
## Porque mais um projeto?
 
Criamos outra vertente de projeto, diferente dos que já estão em desenvolvimento, pensando principalmente nas matérias primas e itens disponíveis para fabricação dentro do Brasil que são de fácil acesso. Acreditamos que esse conceito **depois de validado** possa ser replicado com o menor tempo de fabricação e com menor custo comparado a outros projetos. 
 
# Status
 
- March 20: Início do projeto.
- March 21: Modelamento 3D em progresso.
- March 22: V.2.2: Adicionamos 8 opções de montagem e posicionamento dos motores e castanha do fuso.
- March 23: Testes na versão 2.2 com um equipamento que mede volume, pressão e velocidade, obtivemos:
  1. 27 ciclos por minuto
  2. 250 mL de volume (este valor precisa alcançar 600 mL)
  1. 30 cm H2O de pressão
- March 24: Adaptação para NEMA 23 e ajustes para maior rigidez da estrutura.
- March 25: Testes de fluxo com NEMA 23 e progrmação do CLP.
- March 26: Programação do sistema de telemetria e controle de informações na IHM.
- March 27: Teste intenso do sistema e fadiga do equipamento
- March 28: Instalação do sensor MPX 2010 e teste de pressão
- March 29: Programação do sistema de falhas por pressão e IHM display 128x64
- March 30: Junção dos programas e limpeza do código + ~~Aferição de fluxo e pressão com equipamento de calibração~~
- March 31: Testes de alarme junto ao sistema de sensoriamento
- April 01: Liagaçaõ das válvulas e controle via CLP
- April 02: Adicionar módulo analógico CLP e comunicar via arduino
- April 03: Configuração dos equipamentos de medição para aferir o sistema + Programação CLP entrada analógica
- April 04: Migração do firmware para plataforma ESP32 | Teste e análise de fluxo
- April 05: Implementação NEXTION para leitura do gráfico + ESP32
- April 06: Merge código de telemetria + IHM + CLP | Upload de fotos da montagem/dispositivos

 
### Em progresso:
 
- [x] Iniciar testes de controle de ciclo via potenciômetro
- [x] Alteração de design para junção da fixação de guia
- [x] Validação do motor NEMA 23
- [x] Validar utilização de fuso de avanço rápido 6,35x25,4 (diâmetro x passo)
- [x] Escolha do driver de motor de passo com foco em baixo custo e fácil acesso (Dimensionado p/ NEMA23)
- [x] Programação arduino para controle de ciclo e fluxo via potenciômetro
- [x] Criação da interface (espaço para 2 potenciômetros e possível tela para sensor de fluxo)
- [x] Levantamento de sensorização do sistema (qual sensor utilizar?)
- [x] Realizar testes intensivos para identificar pontos críticos nas partes de acrílico
- [x] Teste com válvulas solenoides para parada de emergência do sistema
- [ ] Criação da case eletrônica
- [x] Programação CLP para leitura analógica
- [ ] Controle PID do motor via CLP
- [x] Adaptação controle de telemetria
- [x] Testes com sensor de pressão industrial
- [ ] Adaptação do código para utilização do ESP32
- [x] Testar MPX5010  (*06 April - Validado*)
- [ ] Desenhar ligação eletrônica (Fritzing)


### Pendente:

- [ ] Armazenar os valores nas variaveis quando retornar as configurações
- [ ] Corrigir bug, que faz imprimir a tela 4 antes da tela 5 quando entra em alarme de pressao pulmonar
- [ ] Imprimir o valor máximo quando rotaciona o encoder no sentido anti-horario na posicao minima
- [ ] Implementar saída analogica para controle de velocidade de avanço
- [ ] Implementar saída analogica para controle de velocidade de recuo
- [ ] Desligar as valvulas de inspiração/expiracao e ligar a valvula de backup quando estiver em pressao pulmonar alta
- [ ] Criação, validação e fabricação de PCB para entrada dos sensores e saída do motor
- [ ] Levantamento de fornecedores e estoques no Brasil dos itens de projeto
 
# Requsitos principais
 
1. Be reliable. It must work continuously without failure (100% duty cycle) for blocks of 14days — 24 hours a day. If necessary, the machine may be replaced after each block of 14 days x 24 hours a day use.
 
2. Provide at least two settings for volume of air/air O2 mix delivered per cycle/breath. These settings to be 450ml +/- 10ml per breath and 350ml +/- 10ml per breath.
 
3. Provide this air/air O2 mix at a peak pressure of 350 mm H2O.
 
4. Have the capability for patient supply pipework to remain pressurised at all times to 150mm H20.
 
5. Have an adjustable rate of between 12 and 20 cycles/breaths per minute.
 
6. Deliver at least 400ml of air/air 02 mix in no more than 1.5 seconds. The ability to change the rate at which air is pushed into the patient is desirable but not essential.
 
 
## Lista de material (BOM) [IN PROGRESS]
 
### Lista de cortes + quantidade:
 
- 2x piston V2.2.dxf  
- 2x side V2.2.dxf
- 1x ambu support V2.2.dxf  
- 1x base support V2.2.dxf  
- 1x motor plate V2.2.dxf 
- 1x nut plate V2.2.dxf 
- 1x piston plate V2.2.dxf  
 
### Eletrônica: 
 
- 1x Nema 23 15kg
- 1x Fuso DST-LS-10X25-R-ES (140mm)
- 1X Castanha DST-JFRM-C-01-DS10X25
- 1x Arduino uno
- 1x Driver de motor de passo **(DM322E)**
- 1x CLP Panasonic FP0R-C16T
- 2X Módulos de entrada/saída (8 canais)
- 1x Módulod analógico CLP (AFP0RA42)
- 20x Parafuso M3 16mm
- 4x Parafuso M3 12mm 
- 2x Potênciometro 1K
- 1x Display 128x64
- 1x Encoder KY040
- 1x Fonte 12V 5A
- 1x Sensor de pressão MPX5010dp
- 1x Tela Nextion 7pol
- Fiação
- Perfil de acabamento para acrilico 5mm [FOTO](https://http2.mlstatic.com/borracha-u-c-8-metros-acabamento-gabinete-acrilico--D_NQ_NP_21608-MLB20213569630_122014-F.jpg)

 ### Itens médicos:

 - 1x Reanimador manual (AMBU)
 - 1x Adaptador para conexão válcula PEEP
 - 3x tubo traqueia
 - 1x Válvula para ambu PEEP (5-20cmH20)
 - 2x Conector "Y" 22mx15F
 - 3x Fluxômetro para oxigênio
 - 1x Filtro HMEF
 - 1x Filtro HEPA


# Material para estudo
 
Não deixe de ler sobre o assunto e entender melhor sobre como funciona um ventilador, quais suas principais funções em relação a ventilação de pacientes com COVID-19 e também alguns editais sobre:
 
- [Rapidly manufactured ventilator system specification](https://www.gov.uk/government/publications/coronavirus-covid-19-ventilator-supply-specification/rapidly-manufactured-ventilator-system-specification)
- [Frontier Tech 4 COVID Action: emerging market ventilation systems](https://medium.com/frontier-technology-livestreaming/frontier-tech-4-covid-action-emerging-market-ventilation-systems-9c818cb46189)
- [Positive Ending Expiratory Pressure Valve](https://grabcad.com/library/positive-ending-expiratory-pressure-valve-1)

![Image of CITI-OpenLung](https://github.com/HPparanhos/CITI-OpenLung/blob/master/Images/92254424_10220896892786622_3459100809759817728_n.jpg)
 
# Creditos
 
* Emerson Moretto [@emersonmoretto](https://github.com/emersonmoretto) - SP
* Helbert Paranhos [@HPparanhos](github.com/HPparanhos) - SC
* Fellipy Kuhne  [@kinife](https://github.com/kinife) - SC
* José Manuel Ramirez [@tere.red](http://tere.red/) - SC
 
   > É preciso alinhar a expectativa de todos! Estamos trabalhando duro no processo de validação e rápida modificação para um projeto 100% confiável e esperamos ao máximo que isso possa salvar muitas vidas!

Colabore para o rápido avanço do projeto em - [VAKINHA](https://www.vakinha.com.br/vaquinha/acelerar-o-desenvolvimento-do-respirador-mecanico-opensource)

# Empresas que apoiam essa causa

- AMS Acrílicos
- Pollux Automation
- Neoyama
- Bold acrílicos
- Unimed Joinville
- OBR Equipamentos industriais
- Igus do Brasil
- JN Ferramentaria
- Docol
- Valgri
- Nidec (Embraco)
- TEX Equipamentos Eletrônicos
- Termica Solutions
- Perini Business Park
- Tere.Red
