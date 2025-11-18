# SIG-HOTEL

**SISTEMA DE GESTÃO PARA HOTÉIS E POUSADAS**
PROJETO DESENVOLVIDO PARA A DISCIPLINA DE PROGRAMAÇÃO (DCT1106)
Um sistema de gestão de hotéis ou pousadas, com opções de clientes, funcionários, serviços e quartos.

## SOBRE O PROJETO
**SIG-HOTEL**(Sistema de Gestao de Hoteis e Pousadas) e uma aplicacao desenvolvida com o objetivo de facilitar e  automatizar os processos de gerenciamento em estabelecimentos de hospedagem em hotei e pousadas.

O sistema oferece algumas funcionalidades essenciais:

- Cadastro e gerenciamento de hospedes
- Controle de reservas e disponibilidade de quartos
- Check-in e check-out automatizados
- Emissao de relatorios hospedes,funcionarios,quartos,financeiros e operacionais
- Gestao de funcionarios e servicos oferecidos

O SIG-HOTEL foi projetado com foco na usabilidade,eficiencia e seguranca, trazendo uma experiencia simples e eficaz tanto para os administradores quanto para os usuarios finais. O modelo do sistema permite facil manutencaom escalabilidade e personalizacao conforme as necessidades especificas de cada estabelecimento.


## DESENVOLVEDORES
NOME: Henderson Emanuel\
EMAIL: hendersonbernardo2018@gmail.com\
GITHUB:https://github.com/HendsMede1r0s\

NOME: Leonardo Relva\
EMAIL: leonardo.relva.111@ufrn.edu.br\
GITHUB: https://github.com/leonardorelva-ufrn 

NOME: Eriky Rayan\
EMAIL: eriky.medeiros.706@ufrn.edu.br\
GITHUB: https://github.com/Eriky-Rayan

NOME: Isaac Vilton Ribeiro\
EMAIL: isaac.ribeiro.018@ufrn.edu.br\
GITHUB: https://github.com/Isaac-Ribeiro

## COMO EXECUTAR

1. Primeiro clone o repositorio:
```bash
git clone https://github.com/HendsMede1r0s/SIG-HOTEL.git

cd SIG-HOTEL
```
2. Compile o codigo:
```bash
gcc -c -Wall *.h
gcc -c -Wall *.c
gcc -o main *.o
```
3. Execute o programa:
```bash
./main

```
## Como usar o make caso possua:
para executar:
```
make

```
para limpar os arquivos caso use no Linux:
```
make clean

```
para executar o programa:
```
make run

```

✅ Andamento do Projeto — SIG-HOTEL
| Módulo / Item                     | Descrição                                                          |  Status |
| --------------------------------- | ------------------------------------------------------------------ |  :----: |
| **Cadastro de hóspedes**          | Registro, edição e consulta de informações dos hóspedes            |    ✅   |
| **Gerenciamento de hóspedes**     | Administração dos dados dos hóspedes ativos e históricos           |    🔍   |
| **Controle de reservas**          | Agendamento e controle de disponibilidade dos quartos              |    🔧   |
| **Disponibilidade de quartos**    | Painel para visualização de quartos disponíveis/ocupados           |    ✅   |
| **Check-in**                      | Registro de entrada do hóspede                                     |    ⚠️   |
| **Check-out**                     | Registro de saída do hóspede                                       |    ⚠️   |
| **Relatórios — Hóspedes**         | Geração de relatórios administrativos de hóspedes                  |    🔧   |
| **Relatórios — Funcionários**     | Geração de relatórios internos de colaboradores                    |    🔧   |
| **Relatórios — Quartos**          | Relatórios operacionais sobre ocupação e disponibilidade           |    🔧   |
| **Relatórios — Operacionais**     | Informações sobre manutenção, serviços e rotinas operacionais      |    🔧   |
| **Gestão de funcionários**        | Registro, edição e gerenciamento dos colaboradores                 |    ✅   |
| **Gestão de serviços oferecidos** | Controle de serviços adicionais (spa, lavanderia, transporte etc.) |    ✅   |

| Emoji | Significado            |
| :---: | ---------------------- |
|   ✅   | Concluído             |
|   ⏳   | Em andamento          |
|   🔧  | Em desenvolvimento     |
|   ❌   | Não iniciado          |
|   ⚠️  | Pendências / Problemas |
|   🔍  | Em análise             |
