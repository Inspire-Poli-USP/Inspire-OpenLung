# Entenda o Problema

Respiração auxiliada por máquinas é um tópico de estudo da medicina com muitos detalhes. Aqui limitamos enormemente o escopo deste assunto focando em descrever principalmente quais são os os *inputs* (entradas do sistema) para controle de respiração que um respirador precisa ter.

As informações aqui são a nossa descrição baseada em materiais de estudo, além da síntese de diversas explicações que gentilmente nos foram feitas a respeito deste assunto por profissionais da área (médicos, fisioterapeutas e engenheiros de equipamentos de ventilação mecânica).

Não deixe também de coletar feedback com profissionais da saúde especialistas no tema que você tem alcance. Caso colete alguma informação que acha que estamos ignorando, por favor, abra um [Issue](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues) sobre o assunto ou se manifeste no [chat em grupo no Telegram](https://t.me/openlungpoliusp) ou na [nossa lista de emails](https://groups.google.com/forum/#!forum/inspireopenlung).

---
## Índice

  1. [A Curva de Respiração](#a-curva-de-respiração)
    1.1 [Intervalos](#intervalos)
      1.1.1 [Como é na prática](#como-e-na-pratica)
    1.2 [Pressões](#pressões)
  2. [O que o Respirador precisa fazer](#o-que-o-respirador-precisa-fazer)
  3. [Como a abordagem mecânica de vocês faz esse controle?](#como-a-abordagem-mecânica-de-vocês-faz-esse-controle)
  4. [E o volume?](#e-o-volume)
  5. [E se o paciente começar a querer respirar no meio disso tudo?](#e-se-o-paciente-começar-a-querer-respirar-no-meio-disso-tudo)
  6. [Definição do tipo do nosso respirador](#definição-do-tipo-do-nosso-respirador)
  
---

## A Curva de Respiração
A respiração é uma oscilação e pressão e volume do pulmão. Um ventilador precisa reproduzir essa oscilação pelo paciente quando ele tem dificuldade para respirar sozinho, mudando a pressão e volume de ar dentro do pulmão numa frequência específica.

Na medicina existem duas tradições de escolha de variável para se observar durante a respiração auxiliada pelo respirador: a variação de volume inserido no pulmão do paciente ou a variação de pressão no pulmão do paciente. Apesar de haverem supostas vantagens na escolha de uma dessas variáveis, elas são intercambiáveis para fins de monitoramento. No nosso projeto medimos a pressão. Usamos os valores medidos para testar se nossos algoritmos de controle conseguem reproduzir uma curva de respiração com medida de pressão. A tecnologia médica de respiração artificial usa tradicionalmente medidas de milímetros de água (mmH2O) para quantificar a pressão.

### Intervalos

A **curva de respiração** abaixo mostra as diferentes faixas temporais que a compõem:
![Curva de respiração baseada em pressão](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Wiki/Wiki_Entenda_o_Problema_IMG1.jpeg)

A imagem acima mostra claramente 4 inputs de intervalos de tempo:
  * Tempo de Inspiração
  * Tempo de Pausa da Inspiração
  * Tempo de Expiração
  * Tempo de Pausa da Expiração
  
O tempo total desses inputs define a **frequência respiratória** (respirações por minuto). Em muitos casos os tempos individuais de cada uma dessas fases é "padrão", sendo aumentados ou diminuídos de maneira proporcional conforme input do operador do equipamento. Esse input pode ser simples, com o operador apenas definindo o tempo total da respiração através da frequência respiratória, ou mais complicado, com o operador definindo todos os tempos.

#### Como é na prática

Uma maneira muito comum de definir a relação entre esses tempos é uma chamada "proporção" Inspiração/Expiração - em que "Inspiração" é o "Tempo de Inspiração" mais "Tempo de Pausa da Inspiração", e "Expiração" é o "Tempo de Expiração" mais o "Tempo de Pausa da Expiração". Existem por exemplo diferentes recomendações de proporções I/E sugeridas para diferentes tipos de pacientes. Por exemplo: 1:1; 1:2 e etc. 

Exemplo prático: se a recomendação para um paciente é 30 ciclos de respiração por minuto, numa relação I/E de 1:2, qual tempo inspiratório e expiratório o fisioterapeuta deve colocar no painel do respirador? Vejamos: 60 segundos/30 ciclos = 2 segundos por ciclo. Como a proporção é 1:2, a inspiração será 0,66 segundos e a expiração será 1,33 segundos.

A interface com o operador é que determinará o nível de especificidade desses inputs. Como essa interface [foge um pouco do nosso escopo](https://github.com/Inspire-Poli-USP/Inspire-OpenLung#onde-queremos-chegar), apenas estamos deixando possível no nosso algoritmo de controle a modificação todos os valores das variáveis de tempo indicadas no gráfico anterior.

Contudo, a título de informação, entendemos pelos feedbacks com especialistas que em ventiladores mais simples o que se define em geral é o tempo total de inspiração (e a proporção entre "Tempo de Inspiração" e "Tempo de Pausa de Inspiração") e a proporção I/E. Com esses dois valores é possível se obter a frequência de respiração (ciclos por minuto) e o tempo total de expiração. Em equipamentos mais completos existe a opção de definir todos os tempos. Caso queira saber quais são esses tempos que geralmente são usados, indicamos [essa referência](https://accessmedicine.mhmedical.com/content.aspx?bookid=520&sectionid=41692246#57062937).

### Pressões

A curva possui 3 inputs de pressão:

![Pressões da Curva](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Wiki/Wiki_Entenda_o_Problema_IMG2.png)

  * Pressão Máxima de inspiração, a PIP (*Peak Inspiratory Pressure* - Pressão Inspiratória de Pico)
  * Pressão de Platô, a PP (*Plateau Pressure*)
  * Pressão Expiratória Final Positiva, a "PEEP" (*Positive End-Expiratory Pressure*)

## O que o Respirador precisa fazer

  Dados todos os inputs acima, o respirador precisa basicamente reproduzir a curva de respiração que o operador determinar. Além disso, a máquina precisa conseguir gerar valores máximos e mínimos de pressão, conforme definido por [especificações](https://github.com/Inspire-Poli-USP/Inspire-OpenLung#principais-especifica%C3%A7%C3%B5es) de agências governamentais e especialistas da área.
  
## Como a abordagem mecânica de vocês faz esse controle?

  Você talvez já tenha visto que usamos [um motor de passo pressionando um Ambu](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Version%205.jpg). Dependendo da velocidade e aceleração com que o Ambu é apertado pelo motor de passo, ele assopra quantidades diferentes de ar em tempos específicos. Isso faz variar a pressão interna no pulmão também de maneira específica, e [conseguimos gerar variações de pressão bem precisas e estáveis, reproduzindo as curvas de respiração](https://www.youtube.com/watch?v=nd0AW7TLXrk), sem usar válvulas que façam o controle ativo dessa pressão. A única válvula usada é a válvula unidirecional passiva, que impede que o ar seja enviado de volta ao Ambu uma vez empurrado para o pulmão. 
  
  Outros designs usando outros tipos de motores ou sistemas mecânicos "fixos" não são capazes de fazer um controle preciso para reproduzir a curva de respiração com total flexibilidade.
  
## E o volume?

  Não vamos usar medidores de vazão porque são caros ou imprecisos, quando baratos. Como o ambu não se deforma com o tempo e o motor de passo se move de maneira muito precisa, podemos estimar indiretamente **com precisão** o volume sendo expelido pelo Ambu em função do quanto o motor gira. Validamos isso experimentalmente usando um medidor profissional de vazão de gás.
  Assim podemos além de informar gráficos como os anteriores (de pressão ao longo do tempo), mostrar também gráficos de volume ao longo do tempo, contemplando ambas as tradições médicas de monitoramento.
  
## E se o paciente começar a querer respirar no meio disso tudo?

Durante o processo de retirada gradual do paciente sedado do aparelho de respiração (o "desmame"), o paciente pode fazer tentativas de respirar rozinho.

A PEEP acaba variando dentro de um intervalo durante a respiração sem que o paciente respire ativamente. Se o paciente tentar inspirar, mesmo que levemente, o sensor de pressão detectará uma pequena queda abrupta na PEEP. Se essa queda passar de um limiar fora do intervalo esperado de variação da PEEP, o sistema de controle deve iniciar um novo ciclo de respiração.
Por isso existe **mais um "input" de pressão** do programa de controle, a **pressão limiar de gatilho**, ou **trigger pressure**, que pode ser ativado durante o **Tempo de Pausa da Expiração**. Se houver a ativação do "gatilho" devido a uma queda de pressão ANTES de terminar o Tempo de Pausa da Expiração, um novo ciclo de respiração deve começar imediatamente.

### Variáveis "de cada paciente"

Cada paciente é diferente. O sistema de controle da respiração precisa levar essas diferenças em conta. Na medicina essas diferenças são "medidas" com duas variáveis: **resistência** das vias respiratórias e **complacência** do pulmão. Ou seja: o quão fácil é para uma pessoa inspirar e expirar (resistência das vias respiratórias) e o quanto de ar alguém consegue acumular no pulmão com uma determinada diferença de pressão criada (complacência do pulmão) são coisas que variam de pessoa para pessoa.

No [comentário do @alberiolima no issue #42](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/42#issuecomment-612409353), a "força" que um paciente deve fazer para expirar está relacionada com essas duas variáveis de resistẽncia e complacência.

Um dos [algoritmos de controle](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/26) que usamos, por exemplo, estima através de modelos matemáticos a resistência e a complacência do paciente enquanto a respiração ocorre. Essas estimativas são usadas para **adaptar os ciclos de respiração àquele paciente em particular** - o que também responde à dúvida da comunidade no [Issue #45](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/45#issue-599523947).

## Definição do tipo do nosso respirador

  Seguindo as definições formais usadas em medicina, o que descrevemos nesta página é um projeto de respirador...
  * **Gerador de Força Constante** - fluxo variável com as condições de complacência e resistência do sistema respiratório do paciente.
  * de **Ciclagem por Pressão** - um sensor de pressão aciona o controle de insuflação do pulmão conforme a pressão varia.
  * de **Desinsuflação Modulada** - o sistema permite uma desinsuflação passiva até um certo nível, para deixar um pouco de volume nos pulmões, mantendo um determinado nível de PEEP desejado.
  * **Assisto-Controlador de Disparo de Ciclagem E/I** (Expiração/Inspiração) - o sistema pode ou não habilitar um "trigger" de detecção de esforço de respiração do paciente.
