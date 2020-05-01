# Sistema de Testes

Para testar o funcionamento do nosso sistema com base [no que nos propomos fazer](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Entenda-o-Problema), temos acesso a um sistema padronizado de testes de equipamentos médicos que envolvem ventilação artificial, com o acesso gentilmente cedido pelo prof. Herique Moriya, no Laboratório de Engenharia Biomédica da Poli-USP.

## Nosso sistema

Nosso sistema é o seguinte:

![Esquema do sistema de testes](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Wiki/Wiki_Sistema_de_Testes_IMG6.png)

Cujas especificações são:

-   Pulmão de testes - [Dual Adult PNEU/VIEW System, Model 5600i - Michigan Instruments](https://web.archive.org/web/20200406002510/https://www.michiganinstruments.com/wp-content/uploads/2018/11/5600_manual2.pdf)
    -   Com esse instrumento é possível ajustar finamente a [resistência à passagem de ar das vias aéreas](https://en.wikipedia.org/wiki/Airway_resistance) e a [complacência do pulmão](https://pt.wikipedia.org/wiki/Complac%C3%AAncia_pulmonar).
-   Medidor de Fluxo e Pressão - [Respical Timeter, Model T300 - Allied Healthcare Products](https://web.archive.org/web/20180827132142/http://www.alliedhpi.com/images/z10-00-1000.pdf)
    -   É um equipamento portátil de calibração de respiradores comerciais.
-   Válvula Unidirecional acoplada à Válcula PEEP - [Exemplo](https://web.archive.org/save/https://www.cpaps.com.br/valvula-peep-ajustavel-standard-circuito-cpap)
    -   Vale a pena olhar [este relatório](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Relat%C3%B3rio-9%C2%BA-Dia) antes de usá-la.

Alternativamente, é possível usar um pulmão de testes portátil, como o da seguinte foto:

![Pulmão de testes portátil](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/images/Wiki/Wiki_Sistema_de_Testes_IMG5.jpg)

Especificação:

-   Pulmão de teste portátil - [SmartLung, Adult 600 mL - imtmedical](https://web.archive.org/web/20161111052542/https://biomedequip.com/index.php?route=product/product&product_id=156)

Contudo este pulmão de testes é muito mais limitado que o anterior, não sendo o mais tradicionalmente usado para testes de ventiladores.

Em nosso caso, medimos em redundância a pressão do sistema usando outro equipamento. Fazemos isso para garantir a exatidão das medidas e também por problemas envolvendo a extração de dados pelo software desses equipamentos - dica: antecipe/se prepare para encontrar problemas do tipo.

## Sugestão

  Caso você queira replicar nossos testes ou fazer quaisquer outros por conta própria, sugerimos que procure um local com equipamentos semelhantes a estes, que podem ser encontrados em centros de pesquisa e hospitais. Assim seus dados e validações estarão dentro dos padrões de qualidade mais comuns de teste, podendo ser portanto melhor compartilhados.
