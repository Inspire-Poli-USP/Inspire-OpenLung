# Como Contribuir com o Projeto

Olá! Obrigado por se interessar em contribuir com o projeto!

A contribuição sua e de toda comunidade é nossa arma secreta para desenvolver este projeto a tempo para o combate ao COVID-19.
Organizando direitinho, podemos conseguir fazer juntos muito mais do que jamais seria possível fazer com nossos recursos apenas.

## Índice
1. [Guiando sua ajuda](#guiando-sua-ajuda)
2. [No que precisamos que você contribua por aqui](#no-que-precisamos-que-você-contribua-por-aqui)
3. [Como fazer as contribuições?](#como-fazer-as-contribuições)
4. [Convenções](#convenções)

---

# Guiando sua ajuda

Você pode contribuir com este projeto de diversas maneiras.

Caso esteja meio perdido(a), criamos um formulário para ajudar você a ser direcionado rapidamente para as pessoas certas que poderão falar diretamente com você, [clique aqui](https://forms.gle/2u1fxgFx3JDqjxeX7) para acessá-lo.

Preenchendo o formulário conseguimos também nos organizar melhor para falar com todos. :)

# No que precisamos que você contribua por aqui

Caso o GitHub não seja exatamente algo estranho para você, existem quatro maneiras de contribuir com esse repositório:

1. **HARDWARE** - baixe os arquivos, monte o protótipo, faça testes e proponha novas melhorias no modelo 3D. Consulte a seção [Como contribuir com o hardware](#como-contribuir-com-o-hardware) para maiores detalhes.
2. **SOFTWARE** - avalie e proponha melhorias nos códigos do firmware e do software de interface com o usuário. Consulte a seção [Como contribuir com o software](#como-contribuir-com-o-software) para mais detalhes.
3. **DADOS** - se você tiver acesso a equipamentos de medição de fluxo e/ou pressão de ar, mas principalmente associados a um [pulmão de testes](https://www.google.com/search?q=pulm%C3%A3o+de+teste) (ou qualquer outro equipamento que simule apropriadamente um pulmão), repita os experimentos que realizamos, melhore-os e faça outros novos experimentos que ainda não foram feitos. Consulte a seção [como contribuir com dados](#como-contribuir-com-dados).
4. **DOCUMENTAÇÃO** - veja quais informações parecem estar faltando, o que poderia estar mais claro ou melhor organizado no repositório. Proponha Issues ou faça Pull-Requests com melhorias e correções. Consulte a seção [Como contribuir com documentação](#como-contribuir-com-documentação).

# Como fazer as contribuições?

Temos algumas regrinhas sobre como você deve contribuir com o repositório para tornar a sua contribuição mais eficiente para o avanço do projeto, além de criar mais integração com resto da comunidade.

Independentemente de que tipo de contribuições você pode dar, valem as regras gerais:

1. Confira que não existe nenhum [Pull-Request aberto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/pulls)
   buscando realizar a mesma contribuição.
2. Caso em dúvida sobre a implementação, [abra um Issue](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/new/choose), mas conferindo antes os [Issues existentes](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues).
3. Para criar Issues e Pull-Requests que ajudem mais eficientemente o projeto, acompanhe o debate mais recente sobre aspectos do projeto no [grupo de chat do Telegram](https://t.me/openlungpoliusp) ou envie um email para a lista de emails (inspireopenlung@googlegroups.com).
3. Faça um [fork do repositório](https://help.github.com/pt/github/getting-started-with-github/fork-a-repo).
4. [Crie uma branch](https://help.github.com/pt/github/collaborating-with-issues-and-pull-requests/creating-and-deleting-branches-within-your-repository) a partir da sua branch master - entenda [aqui](https://blog.da2k.com.br/2015/02/04/git-e-github-do-clone-ao-pull-request/#Criando-a-branch-para-codar-a-feature) porque isso é importante
5. [Faça os commits](https://help.github.com/pt/desktop/contributing-to-projects/committing-and-reviewing-changes-to-your-project) na branch, introduzindo as mudanças necessárias.
6. Abra um [Pull Request](https://help.github.com/pt/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request) para analisarmos o merge de sua branch na master original ou em um novo branch deste repositório.

Depois que seu Pull Request for revisado, pode ser que o merge aconteça diretamente por um dos mantenedores, ou melhorias sejam requisitadas antes de incorporá-lo.

Caso seja necessário fazer alterações no seu Pull-Request, use o rebase interativo(`git rebase -i`) para alterar sua branch ([aqui](https://raphaelfabeni.com/git-alterando-commits-parte-1/) está um blogpost sobre o assunto). E faça um force push no seu fork (`git push -f <seu_fork> feature-x`), para automaticamente atualizar o Pull Request. Você também pode mandar uma mensagem no Pull Request para avisar os mantenedores que uma nova versão foi enviada.

## Como contribuir com o hardware

  - Contribuir com o hardware significa que você vai modificar e fazer Pull-Requests dos arquivos de modelos 3D e 2D do projeto nas pastas ["2D laser cut"](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/tree/master/2D%20laser%20cut) e/ou ["3D model"](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/tree/master/3D%20model).
  - Nossos modelos foram feitos no software de modelagem 3D Fusion, da Autodesk - que é passível de uso gratuito em algumas condições. Preferimos manter o master branch usando os arquivos de modelos 3D do Fusion para evitar problemas de compatibilidade no compartilhamento dos modelos 3D entre as pessoas da comunidade.
    - Contudo caso você consiga modelar apenas em outros softwares, podemos criar branches especificamente para modelos usando outras ferramentas de modelagem 3D (Solidworks, SketchUp, OpenScad, FreeCad etc) de sua preferência.
      - Nesse caso, o merge com o master dependerá da conversão do modelo 3D para o formato do Fusion.
  - Aceitaremos apenas contribuições que se baseiam em nossos [Princípios de Design](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/Principios_e_abordagem.md).
      - Dependendo do caso, podemos excepcionalmente criar branches para designs que fujam ligeiramente dos Princípios de Design
  - Caso seu Pull-Request envolva uma proposta que apesar de seguir os Princípios de Design, julguemos precisar ser validada por fabricação do hardware, ela só será aprovada para merge caso seja construída e acompanhada de Dados documentando as melhorias.

## Como contribuir com o software

  - Contribuir com o software significa que você vai modificar e fazer Pull-Requests dos códigos de firmware do controle de pressão e software de interface com o usuário.
  - Contribua com os softwares que estamos testando com o hardware. Por enquanto eles são:
    - Nosso [firmware](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/OpenLung-firmware/OpenLung-firmware.ino) presente neste repositório.
    - O firmware e interface de usuário [deste repositório](https://github.com/eduoda/odamv) do EduOda.
  - Como esse é um projeto que envolve hardware, precisamos especialmente de contribuições de software cuja funcionalidade **possa ser testada** por você mesmo de alguma maneira - no máximo: construindo o protótipo e [contribuindo com o hardware](#como-contribuir-com-o-hardware); no mínimo: através de simulações computacionais.
      - Podemos testar e estamos testando suas contribuições "na prática", mas o quão mais diferente é a sua contribuição do que já estamos desenvolvendo e testando, mais tempo levaremos tentando "rodar" o seu código no hardware, então encorajamos novamente a focar esforços no que já está sendo feito.

## Como contribuir com dados

  - Contribuir com dados significa que você adicionará arquivos de texto, planilhas, imagens e etc na pasta [Dados Experimentais](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/tree/master/Dados_Experimentais)
  - Contribuir com dados implica em você ter capacidade de ao mesmo tempo poder contribuir com o hardware e o software, tendo ainda acesso a equipamentos para realizar medições, como pressão e vazão, reproduzindo as condições que profissionais de saúde encontrariam numa situação real. Veja, por exemplo, o [Sistema de Testes](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki/Sistema-de-Testes) que usamos.
  - Antes de contribuir, veja os dados e informações que já coletamos e organizamos na [Wiki do projeto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki).
  - Procure nos [Issues](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues) do projeto entradas sugerindo medições e experimentos que ainda não foram feitos.
  - Para ficar mais rapidamente atualizado sobre o que nós e as pessoas da comunidade estão medindo, experimentando, propondo e discutindo, entre no [grupo de chat do Telegram](https://t.me/openlungpoliusp) ou envie um email para a lista de emails (inspireopenlung@googlegroups.com).

## Como contribuir com documentação

  - Contribuir com documentação significa que você alterará arquivos de texto do repositório, adicionará arquivos em diferentes locais do repositório complementando informações (como imagens, pdfs etc) e apontará melhorias necessárias nos [Issues](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues).
  - Nós precisamos muito de uma documentação suficientemente detalhada sobre montagem, organização do repositório, etc. Toda ajuda neste sentido será de **extrema** importância para todos.
  - A [Wiki do projeto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/wiki) é o principal local de organização de informação técnicas do projeto, bem como informações adicionais relevantes.
    - Você pode, por exemplo, sugerir quaisquer materiais externos ou internos (artigos, posts, reports, etc.)
relativos ao projeto, que possam ser úteis para quem quer entender melhor sobre o que está sendo feito. 

# Convenções

## Convenções Gerais

- Todos os textos e mensagens de commit deste repositório são escritos em Português.
- Ado criar novos arquivos, ao invés de usar espaço entre palavras, use underline: _ .
- Ao nomear arquivos, use a primeira letra maiúscula e as restantes minúsculas.
   - Exceções para "arquivos-padrão" do github, como o README, LAYOUT, CODE_OF_CONDUCT, LICENSE etc.
- Todos devem seguir o nosso [Código de Conduta](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/blob/master/CODE_OF_CONDUCT.md).

## Convenções sobre mensagens de commit

Lembre-se de separar mudanças não-correlacionadas em commits separados. Isto é,
se seu Pull Request irá conter, por exemplo, uma mudança no README e a adição
de um novo modelo 2D, cada uma destas ações deve estar em um commit separado.
Ou se você está adicionando um paragrafo sobre contribuições no README, e
modificando o paragrafo de Status (para atualizá-lo), isso também corresponde a
dois commits separados.

Também prezamos pelo uso de mensagens bem descritivas sobre a mudança. No último
exemplo do parágrafo anterior, os dois commits poderiam ter como títulos:

- Adição ao README informações de como contribuir
- Adição do relatório de status do dia 28 de Março ao README

Não utilize mensagens genéricas como "Atualizando o README".

Quanto à formatação das mensagens de commit, seguimos as convenções descritas
[aqui](https://chris.beams.io/posts/git-commit/) (veja a tradução para
Português [aqui](https://translate.google.com/translate?sl=en&tl=pt&u=https%3A%2F%2Fchris.beams.io%2Fposts%2Fgit-commit%2F)).
Em resumo:
- A primeira linha é o título. Escreva-a resumindo as mudanças, no imperativo,
  e tente mantê-la em até 50 characteres.
- Use uma linha em branco entre o título e corpo.
- Use o corpo para explicar em mais detalhes o motivo da mudança, justificado em
  72 colunas. Pode ser omitido caso a mudança seja trivial.
- Se o commit resolve uma issue inclua um "`Closes #<issue_id>`" no final.

