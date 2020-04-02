# Princípios de Design do Projeto

Este projeto segue uma abordagem com os seguintes pontos fundamentais e suas justificativas:

1. Peças fabricáveis apenas por corte a laser
    - Processos de prototipagem e de produção industrial muito semelhantes
      - Facilidade de passagem do protótipo para o processo industrial
      - Mais simples do que impressão 3D, que precisaria da fabricação de moldes de injeção específicos, por exemplo.
    - Facilidade de uso de diferentes materiais para o mesmo design e processo de fabricação
      - Ex: corte de chapas de acrílico no protótipo mas podendo ser chapas de alumínio no produto industrial
    - Velocidade de fabricação maior que impressão 3D
2. Poucas peças
    - Facilidade de montagem
    - Rapidez de montagem
    - Menor custo
    - Menor complexidade
      - Menor probabilidade de erros de projeto
      - Menor probabilidade de erros de montagem
3. Uso de tubulações, válvulas passivas e compartimentos de Ar já usados em aplicações médicas
    - Funcionalidade já validada
    - Uso regulamentado
    - Familiaridade com os profissionais de saúde
    - Diminuição do escopo de desenvolvimento do projeto
      - Projeto menos complexo
      - Projeto mais ágil
4. Uso de motor de passo
    - Capacidade de controle de movimento preciso
      - Possibilita controle preciso da curva de respiração **apenas** com o pressionamento de compartimento flexível contendo Ar e/ou Oxigênio
5. Poucos componentes móveis
    - Facilidade de montagem
    - Rapidez de montagem
    - Menor custo
    - Menor complexidade
      - Menor probabilidade de erros de projeto
      - Menor probabilidade de erros de montagem
6. Movimento de compressão unidirecional e ortogonal ao compartimento flexível de compressão
    - Permite a flexibilidade de adoção (caso eventualmente necessário) de diferentes compartimentos (Ambu, sanfona etc) usando essencialmente o mesmo design
7. Ausência de válvulas de controle de pressão/vazão da mistura Ar/O2 que vai ao paciente
    - Menor custo
    - Menor complexidade
    - Menor dependência de peças de terceiros
8. Ausência de monitoramento de % de O2
    - Menor custo
    - Ajuste da % de O2 aproveitando o manômetro do cilindro de O2
      - Pré-calibração da mistura de Ar/O2 por ajuste do manômetro é robusta
      - Mistura de Ar e O2 aproveitando o compartimento flexível de compressão (ex: Ambu)
