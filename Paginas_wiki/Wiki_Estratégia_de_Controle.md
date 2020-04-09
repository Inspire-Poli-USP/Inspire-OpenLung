[RASCUNHO]

# Estratégia de Controle

Esta é uma página explicativa sobre as estratégias de [controle](https://pt.wikipedia.org/wiki/Engenharia_de_controle_e_automa%C3%A7%C3%A3o) do ventilador. Antes de ler essa página, vale lembrar [como o nosso sistema mecânico funciona](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema#como-a-abordagem-mec%C3%A2nica-de-voc%C3%AAs-faz-esse-controle).

A principal estratégia de controle é criar um sistema controlador [Proporcional Integral Derivativo (o famoso PID)](https://pt.wikipedia.org/wiki/Controlador_proporcional_integral_derivativo)

# Tipos de Controle

## PID

## PI

## Porque se preocupar com o controle é importante

Com base no feedback constante que recebemos de diversos especialistas e profissionais da área durante a primeira semana de projeto, entendemos que é [crítico para a utilidade prática deste ventilador](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema) haver um bom sistema de controle.

Além disso, comparado com outras soluções de ventiladores emergenciais, nossa [abordagem do problema](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/Principios_e_abordagem.md) faz o ventilador ser basicamente um [motor "apertador de ambu" e um sensor de pressão](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema#como-a-abordagem-mec%C3%A2nica-de-voc%C3%AAs-faz-esse-controle), ou seja, controlamos o sistema **diretamente no processo de pressionamento do Ambu**, sem usar válvulas que poderiam facilmente controlar a vazão de maneira rápida e precisa, **mas que encareceriam e tornariam o ventilador emergencial mais complexo**, contrariando nossos [princípios de design](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema).
