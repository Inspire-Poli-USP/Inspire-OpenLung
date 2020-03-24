# CITI-OpenLung

## ATENÇÃO! ANTES DE COMPARTILHAR OU REALIZAR DOWNLOADS, ESTEJA CIENTE DOS SEGUINTES ITENS:

**Este projeto ainda está em desenvolvimento. Não é um produto pronto e ainda não está apto a fabricação em escala. Ainda temos muito trabalho a ser feito, verifique o status do projeto e veja como pode colaborar.**


An another **[IN PROGRESS]** open source, low cost, low resource, quick deployment ventilator design that utilizes a Ambu-bag as a core component.  'War' against COVID-19.

>We are expecting (here in Brazil) the peak of covid-19 in 3 weeks (April 10th). The demand for mechanical ventilator is critical, it is the biggest cause of death of the covid-19. We are fighting time to develop an open-source ventilator that can be manufactured on time.

![Image of CITI-OpenLung](https://github.com/HPparanhos/CITI-OpenLung/blob/master/images/WhatsApp%20Image%202020-03-24%20at%2003.14.08.jpeg)

## Porque mais um projeto?

Criamos outra vertente de projeto, diferente dos que já estão em desenvolvimento, pensando principalmente nas materias primas e itens disponíveis para fabricação dentro so Brasil que são de fácil acesso. Acreditamos que esse conceito **depois de validado** possa ser replicado com o menor tempo de fabricação e com menor custo comparado a outros projetos. 

# Status

- March 20: Inicio do projeto.
- March 21: Modelamento 3D em progresso.
- March 22: V.2.2: Adicionamos 8 opções de montagem e posicionamento dos motores e castaha do fuso.
- March 23: Testes na versao 2.2 com um equipamento que mede volume, pressão e velocidade, obtivemos:
  1. 27 ciclos por minuto
  2. 250 mL de volume (este valor precisa alcancar 600 mL)
  1. 30 cm H2O de pressão
- March 24: Adaptação para NEMA 23 e ajustes para maior rigidez da estrutura.

### Em progresso:

- [x] Iniciar testes de controle de ciclo via potênciometro
- [x] Alteração de desgin para junção da fixação de guia
- [x] Validação do motor NEMA 23
- [x] Validar utilização de fuso de avanço rápido 6,35x25,4 (diâmetro x passo)


### Pendente:
- [ ] Levantamento de sensorização do sistema (qual sensor utilizar?)
- [ ] Escolha do driver de motor de passo com foco em baixo custo e fácil acesso (Dimensionado p/ NEMA23)
- [ ] Programação arduino para controle de ciclo e fluxo via potênciometro
- [ ] Realizar testes intensivos para identificar pontos criticos nas partes de acrilico
- [ ] Criação da case eletrônica
- [ ] Criação da interface (espaço para 2 potênciometros e possível tela para sensor de fluxo)
- [ ] Criação, validação e fabricação de PCB para entrada dos sensores e saida do motor
- [ ] Levantamento de fornecedores e estoques no Brasil dos intens de projeto
- [ ] Projeto elétrico pensando no fácil acesso e amigável (arduino+shield)


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
- 1x Arduino uno
- 1x Driver de motor de passo **(a ser dimensionado)**
- 20x Parafuso M3 16mm
- 4x Parafuso M3 12mm 
- 2x Potênciometro 10K
- Fonte 12V 
- Fiação
- Perfil de acabamento para acrilico 5mm [FOTO](https://http2.mlstatic.com/borracha-u-c-8-metros-acabamento-gabinete-acrilico--D_NQ_NP_21608-MLB20213569630_122014-F.jpg)

# Material para estudo

Não deixe de ler sobre o assunto e entender melhor sobre como funciona um ventilador, quais suas principais funções em relação a ventilação de pacientes com COVID-19 e também alguns editais sobre:

- [Rapidly manufactured ventilator system specification](https://www.gov.uk/government/publications/coronavirus-covid-19-ventilator-supply-specification/rapidly-manufactured-ventilator-system-specification)
- [Frontier Tech 4 COVID Action: emerging market ventilation systems](https://medium.com/frontier-technology-livestreaming/frontier-tech-4-covid-action-emerging-market-ventilation-systems-9c818cb46189)


# Creditos

* Emerson Moretto [@emersonmoretto](https://github.com/emersonmoretto) - SP
* Helbert Paranhos [@HPparanhos](github.com/HPparanhos) - SC

   > É preciso alinhar a espectativa de todos! Estamos trabalhando duro no processo de validação e rápida modificação para um projeto 100% confiável e esperamos ao máximo que isso possa salvar muitas vidas!