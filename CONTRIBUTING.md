# Como Contribuir com o Projeto

Olá! Obrigado por se interessar em contribuir com o projeto!

A contribuição sua e de toda comunidade é nossa arma secreta para desenvolver este projeto a tempo para o combate ao COVID-19.
Organizando direitinho, podemos conseguir fazer juntos muito mais do que jamais seria possível fazer com nossos recursos apenas.

## Índice
1. [Guiando sua ajuda](#guiando-sua-ajuda)
2. [No que precisamos que você ajude aqui](#no-que-precisamos-que-voce-ajude-aqui)
2. [Como contribuir?](#como-contribuir?)


---

# Guiando sua ajuda

Você pode contribuir com este projeto de diversas maneiras.

Caso esteja meio perdido(a), criamos um formulário para ajudar você a ser direcionado rapidamente para as pessoas certas que poderão falar diretamente com você, [clique aqui](https://forms.gle/2u1fxgFx3JDqjxeX7) para acessá-lo.

Preenchendo o formulário conseguimos também nos organizar melhor para falar com todos. :)

# No que precisamos que você ajude aqui

Caso o GitHub não seja exatamente algo estranho para você, existem quatro maneiras de contribuir com esse repositório:

1. **HARDWARE** - baixe os arquivos, monte o protótipo, faça testes e proponha novas melhorias no modelo 3D. Consulte a seção [Como contribuir com o hardware](##como-contribuir-com-o-hardware) para maiores detalhes.
2. **SOFTWARE** - avalie e proponha melhorias nos códigos do firmware e do software de interface com o usuário. Consulte a seção [Como contribuir com o software](##como-contribuir-com-o-software) para mais detalhes.
3. **DADOS** - se você tiver acesso a equipamentos de medição de fluxo e/ou pressão de ar, mas principalmente associados a um [pulmão de testes](https://www.google.com/search?q=pulm%C3%A3o+de+teste) (ou qualquer outro equipamento que simule apropriadamente um pulmão), repita os experimentos que realizamos, melhore-os e faça outros novos experimentos que ainda não foram feitos. Consulte a seção [##como-contribuir-com-dados]
4. **DOCUMENTAÇÃO** - veja quais informações parecem estar faltando, o que poderia estar mais claro ou melhor organizado no repositório. Proponha Issues ou faça Pull-Requests com melhorias e correções.

# Como contribuir?

Temos algumas regrinhas sobre como você deve contribuir com o repositório para tornar a sua contribuição mais eficiente para o avanço do projeto, além de criar mais integração com resto da comunidade.

## Como contribuir com o hardware

- Contribuir com o hardware significa que você vai modificar e fazer Pull-Requests dos arquivos de modelos 3D e 2D do projeto.
- Para começar a contribuir, o melhor caminho é falar sobre suas ideias de melhorias do hardware na nossa lista de emails (inspireopenlung@googlegroups.com) ou [através do grupo de chat no Telegram](https://t.me/openlungpoliusp).
- Nossos modelos foram feitos no software de modelagem 3D Fusion, da Autodesk - que é passível de uso gratuito em algumas condições. Preferimos manter o master branch usando os arquivos de modelos 3D do Fusion para evitar problemas de compatibilidade no compartilhamento dos modelos 3D entre as pessoas da comunidade.
  - Contudo caso você consiga modelar apenas em outros softwares, podemos criar branches especificamente para modelos usando outras ferramentas de modelagem 3D (Solidworks, SketchUp, OpenScad, FreeCad etc) de sua preferência.
    - Nesse caso, o merge com o master dependerá da conversão do modelo 3D para o formato do Fusion.
- Aceitaremos apenas contribuições que se baseiam em nossos [Princípios de Design](https://github.com/OttoHeringer/Inspire-OpenLung/blob/master/DESIGN_PRINCIPLES.md).
    - Dependendo do caso, podemos excepcionalmente criar branches para designs que fujam ligeiramente dos Princípios de Design
- Caso seu Pull-Request envolva uma proposta que julguemos precisar ser validada por fabricação do hardware, ela só será aprovada para merge caso seja construída e acompanhada de Dados documentando as melhorias.

---

- Escrevendo documentação. Nós precisamos muito de uma documentação
  suficientemente detalhada sobre montagem, organização do repositório, etc.
  Toda ajuda neste sentido será de **extrema** importância.
- Contribuindo com código para o
  [firmware](./OpenLung-firmware/OpenLung-firmware.ino) presente neste
  repositório, bem como para
  [https://github.com/eduoda/odamv](https://github.com/eduoda/odamv)
- Contribuindo com documentos, sugestões de materiais de estudo, etc.
- Participando da nossa lista de emails e grupo do telegram.

## Para contribuir com este repositório:

1. Confira que não existe nenhum
   [PR aberto](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/pulls)
   buscando realizar a mesma contribuição.
2. Caso em dúvida sobre a implementação,
   [abra uma issue](https://github.com/Inspire-Poli-USP/Inspire-OpenLung/issues/new/choose)
   para discussão ou envie um email para a lista de emails.
3. Faça um fork do repositório.
4. Crie uma branch a partir da `master`, por exemplo `git branch feature-x`.
5. Faça os commits introduzindo as mudanças necessárias (veja mais sobre
   convenções de mensagens de commit abaixo).
6. Submeta sua branch ao seu fork (`git push <my_fork>`).
7. Abra um Pull Request para fazermos o merge de sua branch `feature-x` na
   master deste repositório.

Depois que seu Pull Request for revisado, pode ser que o merge aconteça
diretamente por um dos mantenedores, ou melhorias sejam requisitadas antes de
incorporá-lo.

Caso seja necessário fazer alterações, use o rebase interativo
(`git rebase -i`) para alterar sua branch
([aqui](https://raphaelfabeni.com/git-alterando-commits-parte-1/) está um
blogpost sobre o assunto). E faça um force push no seu fork (`git push -f
<seu_fork> feature-x`), para automaticamente atualizar o Pull Request. Você
também pode mandar uma mensagem no Pull Request para avisar os mantenedores que
uma nova versão foi enviada.

## Convenções

- Todos os textos e mensagens de commit deste repositório são escritos em
  Português.
- ...

### Convenções sobre mensagens de commit

Lembre-se de separar mudanças não-correlacionadas em commits separados. Isto é,
se seu Pull Request irá conter, por exemplo, uma mudança no README e a adição
de um novo modelo 2D, cada uma destas ações deve estar em um commit separado.
Ou se você está adicionando um paragrafo sobre contribuições no README, e
modificando o paragrafo de Status (para atualizá-lo), isso também corresponde a
dois commits separados.

Também prezamos pelo uso de mensagens bem descritivas sobre a mudança. No último
exemplo do parágrafo anterior, os dois commits poderiam ter como títulos:

- Adicione ao README informações de como contribuir
- Adicione o relatório de status do dia 28 de Março ao README

Não utilize mensagens genéricas como "Atualizando o README".

Quanto a formatação das mensagens de commit, seguimos as convenções descritas
[aqui](https://chris.beams.io/posts/git-commit/). Em resumo:

- A primeira linha é o título. Escreva-a resumindo as mudanças, no imperativo,
  e tente mantê-la em até 50 characteres.
- Use uma linha em branco entre o título e corpo.
- Use o corpo para explicar em mais detalhes o motivo da mudança, justificado em
  72 colunas. Pode ser omitido caso a mudança seja trivial.
- Se o commit resolve uma issue inclua um "`Closes #<issue_id>`" no final.

