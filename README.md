# LP1 - AV1 - Sistema Gerenciador de Linhas de Ônibus

## Detalhes
Autor: Daniel Ferreira Lopes (github: [danielorkae](https://github.com/danielorkae))

Link do repositório: [GitHub](https://github.com/danielorkae/lp1-atv1)

## Descrição

O projeto faz parte da avaliação da 1a unidade da disciplina de Linguagem de Programação 1, do Curso Bacharelado em Tecnologia da Informação, do Instituto Metrópole Digital, da Universidade Federal do Rio Grande do Norte.

O projeto é um modelo semi-abstrato e simplificado de um sistema de gerenciamento de linhas de ônibus, onde é possível editar, excluir e listar linhas de ônibus, listar as linhas de ônibus por bairro, além de receber e listar feedbacks dos usuários.

## Como executar

Para executar o projeto, é necessário ter o C++ e o make instalados na máquina. Após isso, basta executar o comando `make` no terminal, dentro da pasta do projeto, para compilar o programa. 
Em seguida, basta executar o comando `./bin/program` para executar o programa.

## Sobre o desenvolvimento Arquitetura

O projeto foi desenvolvido em C++, utilizando a biblioteca padrão do C++ e utilizado o Makefile para compilar o programa.

### Estrutura da pasta raiz

Separei o projeto em duas pastas principais: `include` e `src`. A pasta `include` contém os cabeçalhos das funções e estruturas utilizadas no projeto, enquanto a pasta `src` contém a implementação das funções e estruturas.

Além destas, temos as pastas `bin` e `build`. A pasta `bin` contém o executável do programa, enquanto a pasta `build` contém os arquivos objeto gerados durante a compilação do programa.

A pasta `data` contém os arquivos de dados utilizados pelo programa, como os arquivos de linhas de ônibus e de feedbacks.

### Padrão MVC
A arquitetura do projeto foi inspirada no padrão MVC (Model-View-Controller), onde temos a separação das responsabilidades do sistema em três camadas: Model, View e Controller. O objetivo é desacoplar a lógica de negócio da interface com o usuário, facilitando a manutenção do código e a reutilização de código.

### Controllers

Os controllers são responsáveis por fazer a interação com o usuário, recebendo a entrada de dados e retornando a informação processada. 

No projeto, os controllers estão centralizados nas pastas `src/controllers` e os cabeçalhos na pasta `include/controllers`.

### Core

O core é responsável por incorporar a lógica de aplicação do sistema, ou seja, encapsula as funções globais compartilhadas por todo sistema.

No projeto, o core está centralizado nas pastas `src/core` e os cabeçalhos na pasta `include/core`.

### Domain

Por ser um projeto pequeno, não foi necessário a criação de modelos como no padrão MVC, visto que as entidades do sistema são anêmicas, ou seja, sem comportamento. Dessa forma, as entidades foram representadas por `structs`, que são utilizadas para estruturar e armazenar os dados das entidades em tempo de execução.

No projeto, as entidades estão centralizadas apenas nos cabeçalhos, na pasta `include/domain`.

### Printers

Por se trata de um projeto que executa no terminal, não foi necessário a criação de Views, como no padrão MVC, visto que a interação com o usuário é feita através do próprio console. Dessa forma, criei arquivos que chamei de `printers`, que são responsáveis por definir modelos de visualização da informação, facilitando o reuso de código, padronização da visualização e facilitando a manutenção do código.

No projeto, os printers estão centralizados nas pastas `src/printers` e os cabeçalhos na pasta `include/printers`.

### Repositories

Os repositories são responsáveis por fazer a interação com a camada de persistência de dados, ou seja, são responsáveis por ler e escrever os dados em arquivos.

No projeto, os repositories estão centralizados nas pastas `src/repositories` e os cabeçalhos na pasta `include/repositories`.
