# 🗳️ Apurador de Vereadores — Eleições 2024 🇧🇷

Este é um projeto em C++ que processa o resultado das eleições para **vereadores** com base em dados abertos do TSE (Tribunal Superior Eleitoral).

Ele traduz um projeto em java que pode ser encontrado aqui:
https://github.com/ConradoAntoniazi/eleicao-vereadores-poo.git

---

## ✨ O que este programa faz?

A partir de dois arquivos CSV oficiais do TSE e do código do município a ser analisado, o programa:

- Processa a lista de **candidatos**;
- Analisa a **votação por seção**;
- Cruza os dados com base no código da cidade;
- E exibe um **relatório direto no terminal** com o resultado final da eleição municipal!

Tudo isso respeitando as regras eleitorais vigentes — inclusive os suplentes! 😉

---

## 📆 Onde conseguir os dados?

Você pode baixar os arquivos diretamente do site do TSE:

- **Candidatos**:  
  https://cdn.tse.jus.br/estatistica/sead/odsele/consulta_cand/consulta_cand_2024.zip

- **Votação por seção** (substitua `AC` pela sigla do estado desejado):  
  https://cdn.tse.jus.br/estatistica/sead/odsele/votacao_secao/votacao_secao_2024_AC.zip

Depois de extrair os arquivos `.csv`, você já pode começar a brincadeira!

---

## 🛠️ Requisitos

- **g++ com suporte a C++17**  
  (Você pode checar com `g++ --version`)

---

## 🚀 Como compilar e executar

### Usando o Makefile (recomendado)

Compile tudo com:

```bash
make
```

Depois rode o programa com:

```bash
./vereadores <codigo_municipio> <arquivo_csv_candidatos> <arquivo_csv_votacao> <data_eleicao>
```

#### Exemplo:

```bash
./vereadores 57053 candidatos.csv votacao.csv 06/10/2024
```

### Outros alvos úteis:

- `make run`:  
  Executa diretamente o programa com parâmetros default (ajuste `CDMUN` no Makefile, se quiser).

- `make clean`:  
  Remove os arquivos `.o` e o executável `vereadores`.

---

## 🧠 Observações técnicas

- O código usa **smart pointers (`shared_ptr` e `weak_ptr`)** para gerenciamento de memória entre candidatos e partidos, evitando vazamentos.
- Os dados são convertidos de ISO-8859-1 para UTF-8 para correta exibição de acentos e caracteres especiais.
- A saída é totalmente via terminal — simples, rápido e eficiente.

---

## 🎓 Créditos

Projeto acadêmico para a disciplina de **Programação Orientada a Objetos**, sob orientação do Prof. João Paulo A. Almeida.

---

## 🗂️ Estrutura do repositório

```
📁 src/              # Códigos-fonte .cpp e .hpp
📄 Makefile          # Compilação e execução
📄 README.md         # Você está aqui :)
```

---

Boa análise eleitoral! 😄
