# CITI-OpenLung

ATENÇÃO: ESTE PROJETO AINDA ESTÁ EM DESENVOLVIMENTO. NAO É UM PRODUTO PRONTO, NAO ESTÁ APTO PARA FABRICAÇÃO. HÁ AINDA MUITO TRABALHO A SER FEITO.

An another [IN PROGRESS] open source, low cost, low resource, quick deployment ventilator design that utilizes a Ambu-bag as a core component.  'War' against COVID-19.

We are expecting (here in Brazil) the peak of covid-19 in 3 weeks (April 10th). The demand for mechanical ventilator is critical, it is the biggest cause of death of the covid-19. We are fighting time to develop an open-source ventilator that can be manufactured on time.

![Image of CITI-OpenLung](https://github.com/emersonmoretto/CITI-OpenLung/blob/master/images/Screen%20Shot%202020-03-21%20at%2004.50.34.png)

## Why another?

We are trying to develop a ventilator that has accessible and available parts here in brazil.

# Status

- March 20: Project started
- March 21: 3D Model in progress 
- March 22: V.2.2: More options for stepper and trapezoidal thread
- March 23: Testes na versao 2.2 com um equipamento que mede volume, pressão e velocidade, obtivemos:
27 ciclos por minuto
250 mL de volume (este valor precisa alcancar 600 mL)
30 cm H2O de pressão

Vamos trocar o motor para NEMA 23 15kg de torque com fuso de avanço maior.


Pending:
- Toda a parte eletronica, PCB, quais sensores utilizar
- Toda a parte de redundancia elétrica, isso tem que funcionar 24x7


## Main requirements:

- Be reliable. It must work continuously without failure (100% duty cycle) for blocks of 14days — 24 hours a day. If necessary, the machine may be replaced after each block of 14 days x 24 hours a day use.

- Provide at least two settings for volume of air/air O2 mix delivered per cycle/breath. These settings to be 450ml +/- 10ml per breath and 350ml +/- 10ml per breath.

- Provide this air/air O2 mix at a peak pressure of 350 mm H2O.

- Have the capability for patient supply pipework to remain pressurised at all times to 150mm H20.

- Have an adjustable rate of between 12 and 20 cycles/breaths per minute.

- Deliver at least 400ml of air/air 02 mix in no more than 1.5 seconds. The ability to change the rate at which air is pushed into the patient is desirable but not essential.


## Bill Of Materials [IN PROGRESS]

Files for laser cut for 5mm thickness:

2x piston V2.2.dxf	
2x side V2.2.dxf
1x ambu support V2.2.dxf	
1x base support V2.2.dxf	
1x motor plate V2.2.dxf	
1x nut plate V2.2.dxf	
1x piston plate V2.2.dxf	

Electronic parts: 

- 1x Nema 23 15kg
- 1x Arduino uno
- 1x Driver de motor de passo
- 20x M3 Screw 16mm
- 4x M3 Screw 12mm 
- Wires, 12v 6A power supply, etc


## To help or to be helped:

emoretto @ usp.br

wpp: +55 11 994840571
